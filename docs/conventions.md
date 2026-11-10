# Conventions

## Evidence tiers

- `[C]` Confirmed — an artefact proves it (address, byte comparison, literal string).
- `[L]` Likely — reasoned from adjacent evidence (e.g. a sibling game's build), not directly proven.
- `[G]` Guess — a placeholder judgment call, must not be load-bearing (never used to name a symbol or
  place a file in a folder; comments only).

## Naming policy

- Never invent symbol names. A name must come from the Jun 8 2004 Burnout 3 prototype's link maps (the
  "E map"), the seeded `research/` name tables, or a specific recorded piece of evidence.
- No evidence yet → placeholder: `func_XXXXXX` (function), `UnkStruct_XXXX` (type), `D_XXXXXXXX` (data),
  `field_XX` (struct member at offset `XX`), `vfunc_XX` (virtual method in vtable slot offset `XX`;
  Approved), `UnkEnum_<addr>` (an enum type, named for the function that needs it)
  and `func_<addr>_inlN` (a `static inline` for inlined code with no evidenced name; both Approved
  2026-10-25, N148). A `vfunc_XX` is never a symbol in the binary: a virtual call only
  loads the slot. It is declared at the vptr's offset; MWCC puts the vptr where the class's first
  virtual is declared and the first slot at +8 (compile probes, N119).
- Member names from Burnout Revenge's stabs (`research/burnout3-symbols/.../SLUS_212.42/types.h`) count as
  `[L]` evidence for shared Gt classes when every offset matches ours (N89); B4-renamed B3 classes need
  their layout checked field by field first. Nahelam's retail function names are hints until
  `tools/check_nahelam_names.py` passes them (N90).
- A guessed *meaning* for something still named by placeholder goes in a comment, tagged `[G]`, never
  promoted to the actual identifier until there's a `[C]` or strong `[L]`.

## Folder placement policy

- A file only moves out of `src/b3/_unclassified/` when its Area has a citation in `docs/layout.md` —
  either a B2 counterpart class (Burnout 2's literal paths) or a Revenge counterpart with a matching
  layout (not just a matching name).
- Every folder assignment gets a row in `docs/layout.md`'s placement table with its tag and citation.

## Matching workflow (once the toolchain is stood up)

1. Build must reproduce the retail ELF's SHA-1 before and after every change — this is the single
   non-negotiable gate.
2. A function is "matched" only when `objdiff` reports 100% for it against the retail binary — not from
   visual inspection of the disassembly.
3. When touching a file carried over from the earlier research repo (see `docs/provenance.md`), re-verify it in
   this repo's own build before relying on its prior verification.
4. Compiler flags live in one place, `tools/mwcc_flags.sh` (`-O4 -str readonly -Cpp_exceptions off
   -inline level=8`, N91); every compile script sources it. After any shared-header change run
   `wsl bash tools/build_c_units.sh`: it rebuilds every unit in `config/proven_units.txt` and runs
   `tools/wire_in_full_check.sh`, which must print `MATCHES RETAIL`.
5. Names: after a change to `research/retail_names.csv`/`retail_data_names.csv`, keep a copy of
   `config/symbol_addrs_b3names.txt`, run `python3 -I tools/gen_symbols.py`, then
   `python3 -I tools/apply_symbol_renames.py <copy>` (renames placeholders in `assembly/` in place; never
   re-run splat over `assembly/`, which holds hand chunk splits), then `tools/fresh_asm_baseline.sh` and
   `tools/build_c_units.sh` (N92).
6. Source-shape rules found so far: `docs/matching-patterns.md` (imported) and the N-rows of
   `docs/known.md` (this repo's).

## Non-matching track

Purpose: C/C++ for every game function, so the later PC port does not wait for the last byte-exact matches. The
matching track keeps priority and authority; a proven match always supersedes the non-matching file.

- **Where:** `src/nonmatching/<symbol>.cpp`, one function per file (existing archive layout). Never linked into the
  matching build, never counted in the README percentages, never cited as matching evidence.
- **Header:** the existing first line stays (`// NONMATCHING: <symbol> -- retail N / ours M instructions ...`). Add:
  - `// TRACK: near | clean | partial` -- `near` = shaped for mwcc, codegen still differs (every archive written
    before 2026-10-30 is `near` unless it has stand-ins); `clean` = written for behaviour and readability, not
    shaped for the compiler; `partial` = stand-ins, scalar placeholders for VU code, or undecoded ranges (not
    equivalent, not usable by the port).
  - `// EQUIV: [L] <basis>` (believed equivalent, e.g. "written from the asm, every branch and store accounted for")
    or `// EQUIV: [C] <artefact>` (a test result), or `// EQUIV: unreviewed` (tagged mechanically by
    `tools/tag_nonmatching_track.py`; nobody has checked it). `[C]` needs a test harness (open item: substitute archives into a
    non-matching ELF and boot it, or a per-function differential test). No `[C]` from inspection.
- **Must still compile with b119p** (`tools/mwcc_flags.sh` flags), so it can go into a test ELF. Host-compiler
  portability comes in the port repo.
- **Same rules as the matching track** for names (placeholders only), `[C]/[L]/[G]` tags, and provenance.
- **Use it for:** never-attempted large functions (283 functions / 780 KB on 2026-10-30, 208 of them >= 1 KB; `python3 -I tools/nonmatching_coverage.py .`) and
  archives that stalled after their passes. Don't spend matching effort turning a `clean` file into `near`; when a
  function is later matched, delete its non-matching file.
- **Behaviour audit (audit1, 2026-11-01): run it on every new or re-archived archive.**
  `python3 -I tools/behaviour_audit.py --only <symbol> --show` compiles the archive (into build/vt/audit1/obj, never
  build/va) and compares ours vs retail on behaviour, not bytes: a symbolic dataflow over both functions gives each call's
  argument sources (constant / parameter / load base+offset / earlier call's result; which registers the callee really
  reads comes from its own retail code), branch predicates with the effects on each side (an inverted condition shows as
  `cond-inverted`), non-stack stores (base, offset, width, value), constants and return values. Quiet = no line with
  weight >= 2 (a function is reported at a total of 4). Findings are suspicions: check each against the asm; offset-only
  differences are usually layout errors (pad sizes, array lengths). Full run (~1 min, 12 jobs):
  `python3 -I tools/behaviour_audit.py` -> build/vt/audit1/report.tsv + summary.txt; calibration: `--matched 5000`
  (proven units, must report nothing) and `--glob 'build/vt/audit1/calib/*.cpp' --tag calib` (known-bad drafts).
  Re-archiving a behaviour fix: build/vt/audit1/refix.py <symbol> <edits.json> <note> (keeps TRACK/EQUIV, rescores).
  Or edit the archive in place and run build/vt/fix2/rearch.py <symbol> <note> [equiv] (fix2). `call-unresolved` (fix2) =
  ours calls a name retail does not have: a prototype whose types or linkage mangle wrong -- always a port link error.
- **Readability for `clean`:** real types from `include/b3/classes` and the GtMathPs2 headers; no raw `asm` blocks
  unless the operation has no C form (then a single named inline helper); field placeholders as usual with guessed
  meanings in comments.

## Session discipline

- Keep `docs/progress.md` current — it's the resume point for the next session.
- Audit `docs/known.md` at session close: promote believed→proven or add a retraction only with an
  artefact; never silently drop a row.
- One session works on this repo's working tree/build folders at a time.
