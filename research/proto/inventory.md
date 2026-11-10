# Build inventory: every other Burnout build on disk, what it holds, what is mined (2026-10-25)

Scope: `..\<local archive>\Releases\{Demo,Prototype,Retail}` (the `..\<local archive>\Burnout 2` folder is empty now; the B2
discs live under `Releases\Prototype`). Read-only. Sources for "mined": `research/` here, `docs/provenance.md`,
the earlier research repo's `docs/progress.md` "Builds" table, `docs/symbol-report.md`, `docs/burnout2-builds.md`,
`docs/retail-names.md`. New probes this session: `build/vt/proto/scanexe.py` (string classes), `elfpaths.py`
(source paths), `mips-linux-gnu-readelf` (sections/symbols). Extracted only what was probed, to
`build/vt/proto/x/` (retail Xbox `default.xbe`/`update.xbe`, Dominator `SLES_546.27`, Burnout 1 `SLES_504.45`/`.MAP`,
Heaven's Drive `SLPM_650.88`). IDs A-J are the earlier research repo's.

Value scale (for this repo: matching retail PS2 game code, names, folders): **high** = directly yields names,
bodies or folders for retail functions; **medium** = cross-check or partial; **low** = context only.

## Burnout 3 (PS2)

| ID | Build | Executable (format) | Symbols / maps / debug | Strings of note | Mined so far | Unmined | Value |
|---|---|---|---|---|---|---|---|
| A | Apr 28 2004 demo, PAL (`Demo\...Apr 28`) | `SLED_525.97` 2.70 MB, MW ELF, one PT_LOAD | none (empty `.symtab`) | RW 3.6 `$Id`, ValueDB `.cfg` names; no asserts/paths [C] | hash compare vs B (65% identical), E-name projection (withdrawn, §13) | nothing with names | low |
| B | May 29 2004 demo, NTSC | `SLUS_291.13` 2.71 MB | none | as A | `research/names_B_may29.csv` (E map block-aligned: 2,577, mostly library) | game-code pairing B -> retail not done (no names to gain) | low |
| I | Jun 21 2004 demo (`SLPM_602.46`, VER 1.01) | 2.70 MB | none | as A | 64% identical to B; `E_transfer_I.csv` | -- | low |
| **E** | **Jun 8 2004 prototype** "Pre-Alpha 1 6-07-2004" | `DNAT_200.45` 3.37 MB (dated 2004-06-09 13:20) | **4 link maps** on disc: `DNAT_200.MAP` (text, 2004-06-04; a slightly earlier link: region-dependent shift), `B3INTERN.MAP` (06-03), `B3DEBUG.MAP` (06-09 10:44), `B3O0PCH.MAP` (06-09 12:56; -O0 PCH build); `B3DEBUG.AST`/`B3INTERN.AST` (3.4k/3.6k assert expressions). ELFs of the other three maps are not on the disc | `NETGUI\` DNAS GUI (separate) | names placed on the ELF (7,425, `name_audit_DNAT_200.45.csv`); E -> retail Ghidra transfer (`retail_names.csv`); data names (`retail_data_names.csv`); AST member names (wiki); 20 GtMathPs2 bodies (`docs/gtmathps2_api.md`); vtable pairing (the earlier research repo namecheck) | **this session:** +519 map names placed on the ELF (`build/vt/proto/placed_extra.csv`); code-similarity + vtable alignment to retail (`research/proto/dnat_align.csv`): 1,302 retail placeholders paired (424 high / 532 medium / 346 low), 1,067 of them with no name in `retail_names.csv` (`new_names.csv`). Still open: 371 map functions not placeable; -O0 map sizes as inline-size evidence (`gtmathps2_api.md` uses them) | **high** (done here) |
| F | Jul 20 2004 11.11 "Alpha 1 07-18-2004" | `SLUS_210.50` 3.87 MB | none | -- | E->F->retail chain (`xfer_E_F*`, `F_names_for_match*`, 7,021 matches) | -- | medium (hop only) |
| G | Jul 20 2004 11.14 PAL "Review 20.07.2004" | `SLES_525.84` 3.87 MB | none | -- | = F code | -- | low |
| D | Burnout 3 demo on the NFSU2 (USA) disc `/B3/` | `B3_NTSC.ELF` 4.00 MB | none | new data formats (`KFS`, `PVEH`) | hash compare only ("D was not tested yet" as a hop) | E->D->retail hop; D is the build closest to retail after F | low |
| C | **Retail** `SLUS_210.50` | 4.07 MB | none | -- | target | -- | target |

## Burnout 3 (Xbox)

| ID | Build | Executable | Symbols / debug | Strings of note | Mined | Unmined | Value |
|---|---|---|---|---|---|---|---|
| H | Jun 22 2004 Xbox preview (`.bin/.cue`) | `default.xbe` 4.24 MB (MSVC, x86) | none; **no MSVC RTTI** (`.?AV` count 0), no assert text, no `__FILE__` [C, `scanexe.py`] | only path `d:\projects\CG1Code\GameProjects\VisualStudio.NET\Burnout3\XboxExternal\Burnout3_External.exe`; RW 3.6 `$Id`s | header parse, string sweep (the earlier research repo §11) | x86 code: Criterion's helpers may be out of line where MWCC inlines them (semantics only, no names) | low |
| -- | **Retail Xbox (USA)** `Burnout 3 - Takedown XBOX (USA).xiso.iso` (not in the earlier research repo's table) | `default.xbe` 4.31 MB (+ `update.xbe` 2.3 MB = MS dashboard updater, + 58 MB `dashupdate.xbe`) | none; no RTTI (the 4 `.?AV` hits are in `update.xbe`, MS STL), no asserts [C] | `C:\work\B3\CG1Code\GameProjects\VisualStudio.NET\Burnout3\XboxExternal\Burnout3_External.exe` [C] -- the project root is `CG1Code\GameProjects\...` (Revenge: `CG4\Game\Code\GameSource`) | nothing before this session | as H | low |
| J | 2005 Xbox Live online demo | `Burnout3.xbe` 4.27 MB | none; no RTTI, no asserts [C] | `d:\XboxLiveDemoCode\GameProjects\VisualStudio.NET\Burnout3\XboxExternal\Burnout3_External.exe` | build path (parked) | -- | low |

The task brief expected MSVC RTTI names (`.?AV...@@`) in the Xbox demo: there are none in any of the three Burnout 3
Xbox executables (all built without RTTI). [C]

## Burnout Revenge / Dominator (later engine, GCC)

| ID | Build | Executable | Symbols / debug | Mined | Unmined | Value |
|---|---|---|---|---|---|---|
| R_jul14 | Revenge Jul 14 2005 PS2 (`SLUS_212.42`) | 108 MB ELF (GCC/SN) | `.symtab` 21,887, `.mdebug` stabs (99 MB), `B4EXTERN.MAP` | names/signatures, `types.h` (wiki), `functions.csv` folders (used by `tools/tu_merge.py`), 113 `_GLOBAL_$I$` alienbrain paths | `.mdebug` holds 728 `.cpp` paths (`build/vt/proto/x/revenge_paths.txt`, this session): they cover 318 of E's 606 game source files (B3X -> B4X, `research/proto/source_paths.csv`), but the wiki's `source_files.txt`/`functions.csv` (847 basenames, already read by `tools/tu_merge.py`) cover 310 of those; **new: 8 files** (`B3NormalGameModes`, `B3ParticleRenderer`, `B3PopcornRenderer`, `B3SparkRenderer`, `B3SunRenderer`, `GtOrientedBox`, `GtPerfMon`, `GtVu0CodeManager`). Line tables not used | high, but already mined |
| R_aug04 / R_aug09 | Revenge Aug 2005 PAL | 4.2 MB | stripped | -- | -- | low |
| R_feb06 | Revenge X360 Feb 7 2006 "Beta 5" | `default.xex`, `B4Extern.pe` | **`B4Extern.pdb` 12.4 MB** + `.pmf` | not decoded | PDB types/function names of the 2006 engine (MSVC); overlaps R_jul14 | low-medium |
| -- | **Burnout Dominator Jan 31 2007 PS2 prototype** (not in any earlier table; `docs/progress.md` l.1380 lists it as "to survey") | `SLES_546.27` **35.7 MB** (GCC) | **`.symtab` 10,033 functions (1,271 `CB4*`/`CGt*`), `.mdebug` stabs 31 MB, `.stab` for the `.dsm` VU files**; tree `d:/dev/Psp/BurnoutReckless/Main/Ps2/Code/GameSource/...` and `GameShared/GameClasses/...` (Unity build) | nothing | 1,128 source paths: folders agree with Revenge's for **212/212** E files they share, and add **0** E files Revenge lacks [C]. Types/symbols are 2007-era (B4 renames) | low-medium (confirmation of Revenge's folders; third typed build) |

## Burnout 1 / Burnout 2 (context)

| Build | Executable | Symbols / debug | Mined | Unmined | Value |
|---|---|---|---|---|---|
| B1 Sep 12 2001 "Preview Code" (+ Developer Note.pdf) | `SLES_504.45` 30.8 MB, **MW 2.4.1.01** + `SLES_504.MAP` | **`.symtab` 3,615 functions, DWARF 1 `.debug` 27 MB + `.line`** [C] | nothing | B1-era classes (`CAICar`, `CFrontEnd`, `CGhostCar`; almost no `CGt*`): lineage only; same compiler family with line tables (codegen studies already served by B2 Aug 5) | low |
| B1 Jan 3 2002 "Heaven's Drive" (JP PS2) | `SLPM_650.88` 2.2 MB | stripped [C] | -- | -- | low |
| B1 Mar 6 2002 `BOER51` (GameCube, CleanRip) | GC disc | not probed (7-Zip can't open GCM) | -- | -- | low |
| B1 Mar 7 2002 Xbox Review PAL / Mar 21 2002 `XBBOER12` | Xbox ISOs | not probed | -- | -- | low |
| B1 Oct 5 2001 demo / BurnoutDemo | PS2 `.bin` | not probed | -- | -- | low |
| B2 Jul 27 / Jul 29 / **Aug 5 2002** | `SLUS_204.97` 19-20 MB | `.symtab` 11-12.6k, DWARF 1, relocations; Aug 5 + `SLUS_204.MAP` | Aug 5: symtab, 932 DWARF types (`research/B2_aug05/`), B2->retail binary match (516/519 agree; game code doesn't transfer) | Jul 27/29: only type deltas | medium (done) |
| B2 Aug 6 demo, Aug 31 US/PAL | 2.2-2.5 MB | stripped | inventoried | -- | low |
| B2 Xbox port Mar 28 2003 | `b2_dxbox.xbe` (Debug) etc. | no PDB; 454 source paths, 1,879 assert-like strings | inventoried | B2-era asserts | low |

## What this session added (summary)
- E: +519 map names placed on `DNAT_200.45` (neighbour shift + start/end checks); code-similarity + vtable-slot
  alignment to retail; class counts and new-name candidates in `research/proto/`.
- Revenge `.mdebug` source paths (728 `.cpp`) extracted from the ELF in place: literal folders for 318 E source files, 8 of them not already in the wiki's Revenge lists.
- Retail Xbox, Dominator, Burnout 1 probed for the first time: no RTTI/asserts on Xbox; Dominator and B1 Sep 2001 carry
  full debug info, of low incremental value for Burnout 3's game code.
- **Highest remaining unmined value:** none of the other builds has names for retail game code that E lacks. The
  remaining levers are on E itself (the 371 unplaced map functions; B3O0PCH's -O0 sizes as inline-body evidence) and
  on Revenge's `.mdebug` (line tables could order functions inside files; types are already in the wiki's `types.h`).
- Re-extraction (the probed binaries were deleted from `build/vt/proto/x/` after probing, to keep ~75 MB of executables
  out of the auto-pushed tree): `7z e <iso> SLES_546.27` (Dominator), `7z e <iso> SLES_504.45 SLES_504.MAP` (B1 Sep 2001),
  `python -I tools/xdvdfs.py <xiso> <out> --only .XBE` (retail Xbox).
