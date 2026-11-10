# Source-shape rulebook (MWCC 3.0.1b119p, -O4): how to write C so the compiler emits retail's instructions

Condensed 2026-10-31 from docs/progress.md (2026-10-30/31 drafter entries), docs/known.md N250-N282 and the existing
rules. Does not repeat docs/matching-patterns.md (rows 1-28: typed returns, `$gp` for <= 8-byte globals, `lbu` for bool,
single `return` at end, `CGtV4d` const by-value param, `extern "C"` mangled names, VU0 `"j"` asm, peephole scoping) or the
workflow in build/vt/hand/BRIEF.md -- read both first. Tags: `[C]` confirmed on the cited site, `[L]` likely, `[G]` guess;
bracket = tag + source entry + site. "(revises X)" = a later entry replaced the earlier rule. A rule that worked on one
site may fail on another: try it, don't assume it.

## 1. Control flow and block layout

- Test order 4,3,5,2 with layout 2,5,3/4 -> `switch` with `case 2`, `case 5`, `case 3: case 4:` in that source order; an if-chain does not reproduce it. [C draft4, CB3VSelectComponent::Update]
- An if/else-if on 0/1 -> `switch` with `case 1` written BEFORE `case 0`. [C draftA, BehaviourTrackSide::Update]
- A type dispatch compared 1,2,3,6,5,4,0 -> one `switch` with `case 3: case 2: case 1:` written first (the `||` chain becomes a range test). [C draftK, UpdateSuspension/PrepareFocus]
- 64-bit `if (id == K) .. else if` chains are switches: retail tests cases in reverse source order, bodies in source order. [C draftW, CB3CarSelectState::Action]
- Mode tests inside an inline -> `switch` with `case 0` before `case 2`; `case 0: default:` fills the `pcpyld` delay slot. [C draftW, func_00310200]
- A 7-way dispatch retail does NOT jump-table -> `if (t==0) return; if (t==1||t==2||t==3) {...; return;}` then a 3-case switch. [C draftB, ResetOnTrack]
- Jump-table case bodies follow the SOURCE order of the cases (JoinGame: 0,1,3,2,4,5). [C draftJ, CB3OnlineJoinGamePage::Update]
- A lobby if-chain tested 1,0,2 with the case-2 body first -> `switch (st) { case 2: ..; case 0: return; case 1: .. }`. [C draftJ, SelectPersonaPage::Update]
- `return` inside a jump-table case moves the body out of line; `break` keeps it. [C draft1, func_0045D0B0-era notes]
- `if (x != y) {...} break;` keeps a case body in place where an early `return` pushes it out. [C draftF, func_00427D00]
- `if (cond) { nested ifs }` instead of `if (!cond) return;` kept the main body in place (1596 -> 870 changed). [C draftV, GetCrashingDrivingControls]
- `if (!f(...)) {A} else {B}` keeps A inline and B out of line; `if (E0 > 0) {big} else {small}` puts big out of line in retail's order. [C draftJ, draftW]
- An FSM if-chain inside `if (counter <= K)`: state bodies must NOT end in `return` (fall to the shared end); timeout branch first. [C draftJ, JoinGame page]
- Outer loops are top-tested in retail: `for (;;) { if (!cond) break; ... }`. [C draftS, UpdateFlyingBits]
- `if (flag || flag2) { value = ...; break; }` placed before the main body puts those blocks out of line in retail's order. [C draftQ, func_0044E400]
- Empty-then form keeps a branch the compiler would if-convert: `b = false; if (a && x) b = true;` -> sltu, but `if (!a || x == 0) {} else b = true;` keeps the branch. [C grind1, func_003F8C30]
- A break/return block can push the code BEFORE it out of line (state-9 block behind `if (field_C) { field_174 = 12; break; }`). [C grind1, func_003F8C30]
- An empty if-body whose tests retail keeps = a call to an EMPTY static inline (also pushes the next block out); a discarded `(void)((w0 || w2) && w1);` keeps a dead test (plain empty if-bodies / empty inline calls get removed there). [C draftB ResetOnTrack; C draftP ApplyDrivingForces]
- Wrap-around: `if (race >= wall) d = race - wall; else d = race + lap - wall;` gives retail's `bc1t` to the wrap case. [C draftL, RaceCarFollow]
- Loops guarded by explicit `if (i < n)` each with its own block-local `CB3MenuPageManager * const m = &D_01E90240;` hoisted into s-registers (function-level const only for the tail). [C draftM, func_0037A920]
- A loop in a tail emitted before another block, or OrthoNormalise rebuild blocks at the function END in retail, are layout-pass effects: 7-8 forms negative; don't grind (see 11). [C draftG, draftC, N272]
- Explicit `goto` entry-jump loops are approved for N24 shapes (memory: n24-goto-approved).

## 2. Comparisons and bools

- `lb` + `sltiu` = signed-char field compared as `(unsigned int)x < 3`. [C draftH, func_002284B0]
- `andi 0xFF; li 1; bne` on a bool = `if (b == true)`; on a bool callee `if (!f())` has no `andi`, `if (f() == 0)` adds `andi 0xFF`. [C draftH; C grind1]
- Retail `bc1f / li 1 / move 0` = `a >= b` (not `!(a < b)`). [C draftY, Draw__16CB3TrafficSystem]
- `if (d0 > d1)` -> `c.le.s + bc1t`; `if (d1 < d0)` -> `c.lt.s`. `K * x < y` gives `c.lt.s + bc1t`. [C draftA TrackSide; C draftP ApplyDrivingForces]
- `(a == b) != 0` inside `||` gives xor/sltiu/bnez; `IsEffectivelyZero(..) == false` gives the materialised bool. [C draftP; C draftN]
- Range membership `if (b==4||b==5) .. else if (b==1||b==2)` -> two sltiu range tests; a 4,5,1,2 `beq` chain needs `!(b!=4 && b!=5 && b!=1 && b!=2)`. [C draftG, ImpactBody]
- sltiu 4 + 0xD mask over cases 4,6,7 = `return t == 4 || t == 6 || t == 7;`. [C draftM, func_0037A920]
- Repeated nested bool predicates = nested bool inlines taking (page, index); `IsNotFlag1() { return !IsFlag1(); }` gives the sltu/xori. [C draftJ, JoinGame]
- IsZero in retail branches straight on the or-ed lanes (`bnez`); any bool local/ternary adds xor/sltiu -> direct-branch body now in header (N274). [C draftC; C N274]

## 3. Float arithmetic

- `a = K; a += t * d;` -> adda.s/madd.s; `K + t * d` -> mul.s + add.s. [C draftF, func_00427D00]
- `r = 1 + K*rand; r *= f; acc += r;` keeps mul.s+add.s where `acc += f*r` fuses to madd. [C draftG, ImpactBody]
- `f = a*b; f += c/d;` keeps mul.s + add.s; passing a product through an inline (`w.inl(0.5f * x)`) gives mul.s+add.s where `+=` fuses. [C draftN; C draftP]
- `e -= 0.05f * d` on a local before clamping gives msub.s. [C draftE, CarViewerGameMode::Update]
- adda.s/msub.s only from `float s = 1.0f; s -= k * (x - c);`; `0.0f +` also gives adda.s; an adda.s from `$zero` needs NO named zero (revises draftC's `z + d + 0.5f*w` named-zero rule). [C draftV; C draftW; C draftN]
- `float o = -30.0f; ... g + o` gives `add.s (g, c)` where a literal gives `(c, g)`. [C draftQ, func_0044E400]
- Runtime `cvt.s.w`: integer literals into float context (`x / 970`, `sq > 10000`, `(float)2020`, 150000/500000/4200/10000/5000/-20000) keep retail's `li; cvt.s.w`. [C draftC; C draftI; C draftP]
- Integer-valued float constants loaded via `$gp` (5000, 2500; D_004E1C88..98 = 60, 110, 90, 2.3, 50) = named `extern float` globals (a literal gives li + cvt.s.w / lui). [C draftH; C draftL]
- `1.0f/sqrtf(x)` gives sqrt+div.s; retail `rsqrt.s` needs the asm stand-in (header InvSqrt, N274; proven GtWideLine_0041D910). [C draftC; C N274]
- Float sign as a pointer pun on the parameter (`*(unsigned*)&v = ... | 0x3F800000`) beat a union and gave retail's dead-zone layout. [C draftB, UpdateFocus]
- `float lOldY = ...mPos.Y();` gives SetY(float)'s vaddx.y. [C draftS, UpdateFlyingBits]
- RaceCarFollow's angle is NOT header AngleBetweenVectors: in-place Normalise of both, `Min(Max(dot,-1),1)` via max.s/min.s, then ACosDeg. [C draftL]
- `volatile` on a stored-and-reloaded float temp (RoundToNearest's lSplitHalf) is a FAKEMATCH: retail's compiler lacks the store forwarding; wait for a patch. [G N275]

## 4. Integers, bit tests, masks

- `D_00648188 & (1UL << (long)i)` with non-small-data globals gives the body-part mask. [C draftU, RenderVehicle]
- `(x & 0xFFFFFF) | 0x3000000` needs explicit masks on a padded int (bitfield syntax gives a 64-bit mask). [C draftJ]
- A u16 key `k = 0; k &= 0xFF00; k |= 0x20;` on its own lines gives retail's andi/ori. [C draftV]
- `(T*)((unsigned)(i << 4) + (unsigned)base)` gives retail's `addu` operand order. [C draftX]
- Arguments read into locals BEFORE a -1 test keep retail's registers. [C draftM]
- A bool parameter is converted at the very top in retail; a local copy gets the position but not the registers. [C draftX]
- Min/Max(int,int) = pminw/pmaxw + self `pextlw` (header, N274); Clamp(int,int,int) = pmaxw->pminw pair (N275); don't hand-write. [C N274, N275]

## 5. Globals and addressing

- A global declared as a <= 8-byte struct or int goes `$gp`-relative; retail's lui/addiu -> declare unsized array or padded struct (D_01EA4690 padded to 16 bytes; D_01EA2F08 must be a struct, a plain int stores via gp). [C draft1; C draftQ; C draftM]
- Per-player/aliased arrays in one object: D_01E900B0 (CB3MenuChoices) is ONE struct; a car array declared as a member of D_00522660 stops MWCC keeping 0x12FCF0 in a saved register. [C draftW; C draftF]
- Retail adds gWorld (0x12AD28) / gGame (0x8021, +0x7080 then +0xD48) member offsets at RUN TIME -> inlined placeholder member accessors (func_0024DAB0_inl7/8/9), prologue included. [C draftE]
- `off = 0x2DA04;` per mode branch + `(char *)&D_004EE040 + off` in the tail reproduces D_0051BA44 = D_004EE040 + 0x2DA04 (form of matched func_0037F640). [C draftT]
- `CB3MenuPageManager *mgr = &D_01E90240;` declared before `bool moved` gives retail's s2/s1; `CB3MenuPageManager * const m` INSIDE a row inline with the colour as `&m->field_0[1]` CSEs `&D_01E90250` into one s-register. [C draftJ; C draftQ]
- A pointer local for a constant address declared right before its use (not at the top) fixed colouring residues. [C stabs3]
- A C-side function-local static emits its own .sbss symbol (Revenge `static RwInt32 lnRotate`); wire-in support for it is open (PresentDrawBuffer, parked). [C stabs1 N257]
- `sscanf` into `int ip[4]` keeps element addresses in s-registers. [C draftJ]
- A static initialiser-filled table (func_004D6B30 fills D_004C3FF0..) and a local array initialiser `{pi/3, pi, 5pi/3}` emitting 12 bytes of `.data` (retail D_0049B510): check the data placement before wiring in. [C draft5; C draftR]
- `field_14`/`field_18` hold separate per-group arrays (indexing `[i + 6]` into one array does not fold the offsets); reloads need block-local `field_14`/`field_18` pointers per loop top. [C draftS]

## 6. Calls and arguments

- Pass-through arguments: functions often take one more argument than the E-map signature (func_003609A0 6th = language index D_004E2918; Impact one more in t0; func_0025EA70 Revenge param order pos, velA, velB, type, float count, lighting, float alpha, u8* accumulator, bool, bool). [C draftJ; G draftE; L stabs2]
- func_0037B400 takes the entry index in a1 and passes it to CacheGameParams(int): callers pass (self, index) though the lifted source declares only self. [C draftM]
- `extern "C"` the mangled name for calls retail makes as `jal` (StartLeadOut, N112); an archive that declares the function under a different symbol than retail compiles to 0 instructions ("ours 0") -- fix the declaration first. [C draftJ; C N280]
- Return types: check v0 at the end of the retail function (func_002294D0 returns the strip vertex count, int; archive had void). [C draftK]
- Parameter order fixes evaluation order: Revenge `ApplyPositionedForce(lPoint, lForce)` (pos first). [C draftN]
- A non-const object parameter fixed a float load position. [C draftX, func_0021FBB0]
- Virtual calls on a global embedded object are devirtualised unless called through a pointer cast. [C draft4]
- `CAR(i)->vt->f(CAR(i))` computes the address twice -> pass it through a small inline; retail keeping `self + 8*idx` in a saved register = an inline taking the index. [C draftF]
- A draw/row inline takes the row INDEX, not a row pointer, and the manager pointer inside it. [C draftQ, draftT]
- A CGtV3d passed by value to an out-of-line call: retail passes the lvalue's address with no copy (3 sites) -> test a CGtV3d without a user copy ctor. [L draftY header queue]

## 7. Registers and locals

- `CGtV3d d(0,0,0)` constructed first reproduces three leading `sw zero`. [C draftA]
- Two CGtV3d members copied `lq,lq,sq,sq` (retail's dead copies) = one 2-element array initialiser. [C grind1; C draftI]
- Revenge STABS locals: uninitialised at the top in STABS order, reused named temporaries, plus ONE loop index shared by loops with different roles (`lnIndex`) reproduce frame and slots (CGtV2d leaf functions, saved-register swaps). [C draftW; C stabs2; C stabs3]
- A class with a vtable copied by the implicit `operator=` skips +0 (vptr) and alignment gaps. [C stabs2]
- Reading kYAxis into a local first makes the header CrossProduct write over `a` (open N256 item). [C draftC]
- CrossProduct result straight into the destination (`"=r"(d.mData)` + qmfc2.i) removes a qmtc2/qmfc2 pair per site. [C draftI]
- `CGtMatrix3x4 m; m = CreateRotationMatrix3x4(...)` gives retail's two copy levels (9 byte loops vs 6); `X = f()` adds its own op=; copy-init from an lvalue is plain lq/sq. [C draftN; C N263]
- Build a rotation matrix before saving `m.mPos` (cut 48). [C draftE]
- A small struct returned by value from an inline schedules right but loses retail's frame slot / address-register byte reads. [C stabs3]
- Archives written before a header round can be stale: re-try them with the current header (GetDesiredDirection 1 -> 0). [C stabs2]

## 8. Stack slots (N281, PROVEN)

- Every memory object gets its own slot (disjoint scopes don't share); slots fill from the bottom of the local area upward in REVERSE creation order (first-created highest); the -O4 layout = the -O0 inline layout minus register-promoted objects. [C N281(a)]
- Creation order by inline LEVEL: all body objects, then all first-level inline objects, then second-level...; `-inline bottomup/deferred/auto` give the same order. [C N281(b)]
- Within a level: named locals first (declaration order, block scopes included), then that body's expression temporaries. [C N281(c)]
- A class-returning call's result temp is created before its argument temps; by-value temporary args are the CALLER's temps ([result, arg x, arg y] per statement); a copy of an lvalue argument is the callee's parameter, first in the callee's level. [C N281(d)]
- Inlines from one body go statement by statement, nested calls in arguments expanded first -- except when the inline call is the root of an expression statement or `return` (outer call's locals first). [C N281(e)]
- A lane inline's by-value argument temps stay in memory (dead slots) only when its expanded body contains an `"=m"` asm; otherwise all are promoted. [C N281(f)]
- Dead lane slots depend on the site: by-value temp 2 slots, lvalue 1, const& 0 (not a setting). [C N254]
- Use it to reposition code between body and inline levels to permute slots (func_0044D6D0 125 -> 93; slot map build/vt/gapM/d6_slotmap.txt). [C draftT; N276 -> N281]

## 9. Inlining

- `-inline level=8` is the build setting (inline depth); no single lower level fits retail (level 4: 24 proven units differ). Use a scoped `#pragma inline_depth(n)` [G, N182 policy] per function; depth that fits differs per function. [C N264; L N262]
- MWCC counts an inline call inside another inline's ARGUMENT as one level deeper (`r * DotProduct(d, r)` cut at depth 5, split statements not). [C draftG]
- Retail's out-of-line CGtV4d `__ct__CGtV4dF1` / `__ct__(const&)` / `__ml__` calls and func_0023E3D0 (XAxisType(u_long128) ctor) are inline-depth effects (scoped depth 6 on UpdateCamera, FlyAround; depth >= 8 gives none). [L N262; C draftG, UpdateCamera]
- `#pragma inline_max_auto_size(17)` (default 15 statements; each inlined asm statement counts one) lets Sync/func_001D4780 recurse like retail. [C N250]
- `#pragma auto_inline on` file-wide keeps same-file methods inlined without out-of-line copies (matching-patterns row 23); file-wide `opt_classresults on` is [G]-only and breaks proven units globally. [G draft3; C N250]
- Named-return elision is `#pragma opt_classresults` where the returning inline is DEFINED (b119p lifts the asm gate); N263 found the missing level was the implicit `operator=` copy, so the header's opt_classresults scopes were stand-ins. [C N250; L N263]
- Scoped `opt_loop_invariants off` [G] keeps colour temps inside 4 loops (UpdateCustomLeadIn); pragmas per N182 policy only. [G draftT]
- Unnamed inlined code: `func_<addr>_inlN` static inline; E-map names of inlined helpers (RotateBoneByAxisAngle, CreateRotationMatrixOnPrincipleAxisWithoutSinCos, GetFlyingObjectIndex ...) are listed in progress.md draftU/draftY. [C]

## 10. VU0 / GtMathPs2 header use

- Applied header APIs (use, don't hand-write stand-ins): CreateRotationMatrix3x4(CGtV3d,float) + lane setters (N259), CGtMatrix3x4::OrthoNormalise + Abs(CGtV3d) (N260), CrossProduct `.set noreorder` body (N256), Invert + op*(YAxisType/ZAxisType) (N266), GtMath::Sign / USplitBits (N267), SetLookAt(at,up) (N268), Min/Max(int,int), InvSqrt, NormaliseFast, AngleBetweenVectors/ACosDeg, GetRight/GetUp(CGtQuat) (N274), IsEffectivelyZero(float / CGtV3d), RoundToNearest, Clamp(int,int,int), ASinRad/ASinDeg (N275). [C]
- Header text alone changes MWCC spill slots (even a COMMENT): `headsafe` the final merged text; adding `#include "b3/GtMathPs2Quat.h"` to a file can change its allocation or make products ambiguous. [C N263; C N274/N275]
- Lane binary operators take by-value parameters (all 42 map names are free functions, none const&). [C N279]
- Normalise/Abs show two retail shapes decided by where the object lives (pointer vs stack local); one header body gives both. [C N261]
- A `vcallms` mnemonic anywhere keeps vector temps on the stack function-wide (= retail) but adds `andi` after every lbu/lhu in its block; `.word` removes the andi but keeps temps in GPRs. [C draftO, IntersectLineNearest]
- `QX_SETA` defined before the includes makes UncompressRotation set w retail's way; use a local CompressRotation copy until the header has it. [C draftV]
- Retail TransformPoint's operand order: the point as the FIRST `"j"` operand matched at 3 sites (header has the row first) -> census before any header change. [C stabs2]
- Where retail's quaternion/matrix op= is a byte-loop copy, ours emits lq/sq: N263 copy-ctor form (applied) fixes some; others (ResetOnTrack, func_002284B0 12 loops) are open. [C draftB; draftH]
- Stand-ins still needed (header gaps queued in build/vt/header_queue.txt): CompressRotation(CGtQuat), Abs(CGtV4d), Clamp(float,float,float), CGtMatrix3x4::operator*=, CGtV2d DotProduct (Revenge lrDotProduct), ASin, operator-(XAxisType,float)/operator+(WAxisType,float), scalar sine/cosine, CGtPolygonSoup16 layout, RotateBone* bodies. [C draftV, draftP, draftK, draftO, draftW, draftY]
- Don't add: CGtV3d::operator+ / operator-(const&) on compiler-chosen registers (proven DIFF); operator+(YAxisType,float) over the scalar register; TransformPoint with the position row as a separate statement. [C N274, N275]
- Stand-ins for N185 (CGtV4d ctor whose dead temp survives), `vrinit/vrnext` VU random and quaternion slerp are missing; see progress.md gapC. [C]

## 11. Known walls (stop; don't grind)

- N255/N282 lane-product stack slots [live, dead, dead] stride 48: no header body on b119p (breaks 30 proven units); needs a compiler patch. ~30 header forms, F4 asm lane read, one-expression chains: negative.
- N272 OrthoNormalise zero-block placement (retail defers X,Y past the caller's tail, Z at 4 sites, order Z,Y,X); N273 sq vs sqc2 lane temps; N271 row-reference body not applied (layout unsolved).
- N277 SinCos constant CSE and lOne's 1.0 = allocation context; N278 no single operator* body (>= 5 retail register shapes); N258 H1/H3 negative.
- UpdateSuspension's loop-1 constants hoisted+spilled (six pragmas negative); ResetOnTrack/func_002284B0 byte-loop copies; func_003F8C30 state-9 block; func_003F7750 `bne` to the epilogue.
- Revenge STABS yield is falling (3/11, 3/13, 0/11); Physics/collision/sound were reworked for Revenge -> hints only. [C stabs3]
- A header round must pass: headsafe (final text) -> verify_all at a pipeline stop -> `python3 -u tools/rescore_archives.py 16` and compare with the previous result.tsv. psweep_all.py credits header gains to the pragma: rescore first. [C N264]

## 12. Tools

- `python3 tools/stabs_lookup.py <mangled> --brief`: Revenge STABS locals, first look per function. `tools/rescore_archives.py [workers]` -> build/vt/rescore/result.tsv (score = changed + 4 x |length diff|).
- `build/vt/draft1/arch.sh`, `hunks.py` (archive compile + hunks); `build/vt/draft2/asm.sh`, `calls.sh` (asm_cur.txt is SHARED: use a private copy); `build/vt/draftA/dh.py`, `m.sh` (mnemonic hunk diff); `build/vt/draft6/peek.py`, `skel.py`, `segs.py`, `ops.py`; `build/vt/draftR/regs.py`; pickers `build/vt/grind1/pick.py`, `build/vt/stabs3/pick.py`.
- Permuter: `build/vt/dperm/run_bg.py` (near-miss archives, score <= 50 first, `--stack-diffs`, STOP_BG); `tools/nonmatch.py` carries TRACK/EQUIV lines over and refuses a non-compiling replacement; `tiny_batch.where` filters stale archives; `tools/nonmatching_coverage.py`, `tools/tag_nonmatching_track.py`.
- `build/vt/hand/ghdraft.sh <name>` for Ghidra drafts; headsafe/verify_all for header gates (never while the pipeline runs).

## Open tensions (found while condensing; each rule held on its own site -- treat as context-dependent)
- adda.s forms: a named zero (draftC) vs none needed (draftN) vs `0.0f +` (draftW) vs `float s = 1.0f; s -= ...` (draftV).
- Pointer locals: repeat the member expression (matching-patterns row 2) vs a block-local pointer for a constant address
  declared right before use (stabs3/draftM/draftQ) vs declared before a `bool` local (draftJ).
- Declaration order: alone fixed nothing in the Revenge passes (N257), yet it decides stack-slot order (N281 c).
- Inline depth: no single level fits retail (N262/N264); the fitting depth is per function.
- In-place Normalise vs `.Normalise()`: N261 -- one body, two shapes, decided by where the object lives.

## Added 2026-10-31 (draftZ, VU-free online/HUD pages) -- [C] on the cited functions
- Destroy-object inline helpers: read the scene pointer and id INSIDE the null test (as arguments they load before it). [C draftZ, func_00457B20]
- Temporaries for an inlined helper passed as arguments (`CGtV2d(70.0f, 70.0f)`) store before the call; declared inside the inline they store after. [C draftZ]
- A prologue-hoisted global address = `T * const p = &D_0066A4C0;` at the top of the function (also fixed the frame). [C draftZ]
- `return` after an if/else inside a switch case keeps retail's own exit block instead of sharing the break block. [C draftZ]
- `if ((x == -5.0f) != 0)` keeps a float-equality then-body inline; plain `==` moves it out of line. [C draftZ]
- A bool inline `return !(a < b);` gives retail's c.lt/bc1f/addiu/daddu. [C draftZ]
- Loop shape could not be steered from source in UpdateSmallMessage__11CB3HUDScoreFf (for/while/goto/for(;;) identical). [C draftZ, negative]

## Added 2026-10-31 (draftAA)
- A pointer global read inside a store-heavy loop: an unsized `extern T *D[]` or a separate 4-byte extern gets its load HOISTED out of the loop; retail's per-use reload (and spilled `lui`s) needs a sized table element (`D_01EA46B0[18]`) or a padded struct field (`D_01EA4674.field_0`). [C draftAA, SetupTableData__18CB3OnlineLobbyPageFv]
- Fresh block-scoped loop variables (`for (int r..) for (int c..)`) for a later nested loop fixed swapped i/j registers where swapping `int i, j;` declaration order did not. [C draftAA, same]
- Index arithmetic `(i-1)*0x50 + 0x370` vs `i*0x50 + 0x320` tells separate member arrays (field_370[6], field_550[6]) apart from one `[15]` array. [C draftAA, same]
- Retail loads a member into a saved register at the top AND re-reads it for a call argument right after: the argument goes through a small accessor inline (`static inline const T *f(const C *s) { return s->field; }`) or a type-punned read; a plain repeated `field` is CSE'd into the saved register. [C draftAA, CalculateNextTargetPosition__11CB3AITargetFv, 115 -> 29]
- A value both masked at assignment (`andi s0,v0,0xFFFF`) and re-masked when passed to a `ushort` parameter = an `int` local holding a ushort result (`int next = lane->IncrementSegmentIndexClamped(..)`; `int lnEnd = n + 8`). [C draftAA, same]
- A long straight-line init soup (constant stores interleaved with gp lit loads, 64-bit hash `sd`s via pcpyld): writing the assignments in RETAIL STORE ORDER reproduced the schedule exactly on the first compile (660 instrs); 64-bit hashes = `unsigned long` fields with `0x...UL` literals; `li; cvt.s.w` stores = integer literals. Tool: build/vt/draftAA/stores.py (symbolic store list) + gen_rv.py. [C draftAA, RegisterVariables__20CB3SoundCrashManagerFv]

## Added 2026-10-31 (draftAB)
- A `return` inside a switch case that retail compiles as a branch to the shared exit block (`b exit; ... exit: b epilogue`), not straight to the epilogue, is a `break` (2 -> 0 changed). [C draftAB, Update__15CB3StopJunctionFbf]
- A lane/param test repeated across a class's methods is one shared bool inline (FindFirstParam's `skip` test reused by Update: `!(inl(0) && inl(1))` gave retail's sltu/xori/andi + saved register on the first compile). [C draftAB, same]
- One spill too few (frame 16 bytes short, a hoisted `lui` kept in a register): look for a value retail loads at the top of a block and holds until its store; reading it into a block-local first (`void *str = self->field_8[i];`) adds the live range back (173 -> 0). [C draftAB, func_00321A50]
- Loop unrolling needs `-opt speed` (CodeWarrior PS2 manual); `#pragma opt_unroll_loops on` does nothing in our build, so retail's per-element stores of a 4-entry stack array are explicit statements. [C draftAB, CSparkBank::Construct]
- Retail reloading `this->field` after stores to a local stack array (non-folded `&lan[i]` pointer temps) means it treats the array as address-taken; an array inside a local struct reached through a pointer reproduces the reload, but no natural form was found. [L draftAB, same; open]
- GIF ST words built from float locals stored to the stack and read back as `lwu`: write `float s, t;` locals, pass `*(unsigned int *)&s`, then `s += 1.0f` in place (the slot is reused). [C draftAB, Copy8BitTextureAsPSMT8H]
- Sign- vs zero-extension in packed GIF words: retail's `dsll32/dsra32` = `(long)(int)expr`, `dsll32/dsrl32` = unsigned; check each half before tuning anything else. [C draftAB, same]

## Added 2026-10-31 (draftAC)
- One dead 16-byte stack slot between two CGtV4d locals and a later temporary (frame 16 short, every sp offset above it off by 16): route ONE branch's copy through a by-value placeholder inline (`static inline void f_inl1(CGtV4d *c, CGtV4d v) { *c = v; }`); its parameter keeps the slot while the copy stays lq/sq. Named locals, CGtV4d(u_long128) copies and return-by-value inlines gave 0 or 2 extra slots. [C draftAC, func_00431860, 62 -> 0]
- a100_rchk flags retail's unlabelled `lui 0x1E9 / addiu 0x240` (&D_01E90240 left raw by splat; the checker only recognises raw `imm(` loads) as "ours-only": same bytes, finish with FINISH_FORCE=1. [C draftAC, func_00431860]
- GIF packet builders (CB3Bloom FirstDownsample): MWCC hoists/CSEs non-volatile `pcpyld` asm like pure expressions (loop-invariant quads land in the preheader); write invariant quads inside the loop or as locals before it according to where retail builds them (before vs after the n > 0 guard). The head-block schedule order was inert to 24 declaration orders and the *p++ form. [C draftAC, FirstDownsample 321 -> 227]
- A retail body with trapping `add/addi/sub` (splat marks them "handwritten instruction"; MWCC never emits them) and explicit `.set noreorder` nops is hand-written assembly: write a CodeWarrior asm function definition (`asm void C::f(args) { .set noreorder / .set noat ... }`, `@L1:` labels, prologue/epilogue written out). A gcc-style `asm volatile` body inside a C function instead gets an extra compiler prologue saving the s-registers it clobbers (+8). Other units with such markers: unit_0021C780, 00221A70, 00364B70, 002FC530. [C draftAC, ProcessB2Distortion__20CB3SoundDSPDataBlockFPsPs, byte-identical]

## draftAD (2026-10-31), from the exact Prepare__16CB3TrafficSystemFv

- A resumable state machine whose tests run 4,3,2,0x18,1 is `switch (state) { case 1: case 0x18: ...; state = 2;
  case 2: ...; case 3: ...; case 4: { body } }` with no default and `return true;` after the switch (retail's shared
  `b <ret>; li v0,1`).
- A run-time gGame member address `*(T*)((char*)&D_004EE040 + off)` must be assigned in BOTH arms of the preceding if,
  and before the call in the arm that has one, to land in the jal delay slot.
- A loop that retail keeps in the same s-register as a later loop reuses that later loop's variable; an inner loop with
  its own block-scoped counter fixed a t0/t1 swap.
- Index a member array directly (`field_4[i].x`), not through a local pointer, to get retail's `base + i*size` CSE
  with the member offset added per use.
- [G] `x = 0.0f + x + 0.25f * p;` as one expression gives retail's `adda.s zero` / `madd.s`; a split `+=` gives an extra
  add.s (DeformDoor).

## draftAE (2026-10-31)

- An integer range test where retail keeps `bltz` on an lbu value: write the bool with early returns
  (`if (v < lo) return false; if (v > hi) return false; return true;`); the `&&` form lets MWCC fold `>= 0`.
  [C Update__17CB3VehiclePhysicsFf]
- `a = b || c || d` assigned as a value gives retail's andi/bool chain (plus the stack copy of a by-value operand);
  `if (!(...)) x = false;` does not. [C same]
- A double andi after an inlined bool call means `if (f() == false)`. [C GetIrradiance__16CB3StreamedTrack]
- A by-value class parameter whose copy sits at the top of the frame: copy it into a local as the first declaration
  (N281 order). [C same]
- `float one = 1.0f; x * one` keeps a retail `mul.s` by 1.0 that a literal folds away. [C func_00330370]
- `x = field + (float)i * k` written as `D * (float)n` gives retail's mul.s operand order without madd.
  [C Update__18CB3BehaviourEffect]
- A struct element copy that skips padding means the struct has no explicit tail pad; let the 16-byte alignment round
  it to the stride. [C func_0023D410]

## draftAF (2026-10-31)

- Copy-initialise a matrix from a product (`CGtMatrix3x4 m = a * b;`) for retail's single set of lb/sb row loops;
  `m; m = a * b;` gives two sets. [C func_001C8290: 409 -> 374]
- A matrix-returning accessor inline around ConvertToMatrix (`CGtMatrix3x4 lResult = q.ConvertToMatrix(); return
  lResult;`, as Revenge's two lResult locals) reproduces retail's out-of-line CGtV4d(u_long128) call and copy levels.
  [C Draw__14CB3CrashPickupFv]
- When a by-value CGtV3d/CGtSphere argument comes from a pointer-derived lvalue and retail passes the originals'
  addresses, declare the callee through its link name with pointer parameters. [C CollideWheelWithWorld: 386 -> 379]

## draftAG (2026-10-31)

- Retail argument lists can be longer than the E-map mangled name says (CollisionResolveCameraWorld takes the camera;
  CB3VehicleDeform::Impact takes a 64-bit id, the impact type and a stack bool). Read the registers actually used and
  define through the link name with retail's real list.
- An `sd` of an argument with no sign extension means a 64-bit `unsigned long` parameter. `long` adds dsll32/dsra32;
  `unsigned long` built from an int adds dsrl32.
- `1.0f * x` folds away. To keep retail's madd.s by 1.0, pass the factor as a float parameter of the inline
  (func_0044A8F0).
- An `||` chain over a small integer range (k==6||...||k==10) folds to sltiu. Retail's separate beq chain is a switch
  with stacked case labels (Impact).
- When retail recomputes a lane offset per lane, reloading the vector each time, pass the source vectors into the
  inline rather than a precomputed lane value (VehicleTrafficResponse).
- Local struct size moves the frame: a 0x48-byte voice-params struct vs 0x50 shifted the frame by 0x10 (PayLoadImpact).

## draftAH (2026-10-31)

- An asm `cfc2.i $0, $vi0` (microprogram wait) as the very last statement before the epilogue is deleted by b119p,
  in every asm form tried. It stays as soon as any store follows. [C BeginInstanceRender; B3TrackRendererRuntimePS2_0026A240]
- Two transposes in one function differ: GetTranspose's full-lane Set(X,X,X) form for the identity; for a loaded
  rotation, copy the rows then set the off-diagonal lanes (Invert's form). [C Prepare__17CB3VehiclePhysics]
- Diagonal-tensor rows built with SetY((float)v.Y()) / SetZ((float)v.Z()) give retail's vaddx.y/vaddx.z through a GPR;
  SetY(YAxisType) gives vaddy.y. [C same]
- `CGtV3d + p` through the header operator+ adds a vmove per use; an in-place `q += p` on the local removes them.
  Quad corners built with CGtV3d(x,y,z) go through stack swc1; lane SetX/Y/Z on a reused local gives vaddx inserts.
  [C DrawGlobeHalo]
- A trailing struct copy whose first member sits at +0x1C after 3 bytes at 0x18..0x1A is a derived class copying its
  4-aligned base (CB3ConvexHullVehicle : CB3ConvexHull, base sizeof 0x1C). [L]
- `bool b = false; if (x != 0xFF) b = true;` gives daddu/beq/daddiu; `b = x != 0xFF` gives sltu/xori.
  [C RenderSpatialTriggers]
- Compare against a literal in each `if (!(d <= 0.0f))`, not a zero-initialised variable, for retail's per-test
  `mtc1 $zero`. [C func_003DC1A0]

## draftAI (2026-10-31)

- Loop conditions written `while (!(a <= b))` / `do {} while (!(x <= y))` make MWCC build a bool (sltu/xori, +5
  instrs). Write `a > b`; the same `!(...)` in an `if` is fine. [C _Render__17C2dObjectBoostBar]
- A plain cvt.s.w on an lbu byte means the byte went through an `int` local; converting an unsigned char directly gives
  the bltz/srl/or/add.s unsigned sequence. [C]
- A byte loaded with lbu and tested or passed on without masking is a `bool` field. [C]
- Explicit empty `case 1: case 2: case 3: break;` labels turn a 3-case compare chain into retail's 6-entry jump table.
  [C _RenderDistort]
- `q = t + t - t*t` fuses into adda/msub; retail's mul/add/sub needs a separate `float tt = t * t;`. [C]
- `arr[i].Set(x, y)` instead of `arr[i] = CGtV2d(x, y)` removes the constructor temporaries. [C _RenderParticles 423 -> 416]
- When a callee reads an argument register the caller never sets, the caller's live value (e.g. a switch value in t3)
  is a real argument: add it to the prototype. Without it the C is WRONG, not just unmatched. [C _RenderNormal ->
  _DispatchMetallic]
- The same pass repeated N times with its own stack slots is an inline called N times; MWCC never unrolls. [L func_002F5060]

## draftAJ (2026-11-01)

- Odd gp-relative constants (0.65000004, 0.75000006, 0.100000024, 9.999998, 13.052631, 0.099999994) are compile-time
  folded sums / differences / reciprocals of other literals (timeline keys, `e - s` of an inline's range): write the
  folded value with the exact bits (check with struct.pack) or the original expression; never round to the "nice" value.
  A gp load of a value whose low half is zero (0.5 at D_004E1E84) is a variable, not a literal (MWCC would `lui` it).
  [C func_003AC170, func_003BC7F0, Update__17CB3GlobeComponentFf]
- Retail duplicating a whole block (CalcSpeed's state-4 random-offset entry, 4 copies) means two separate if-arms in
  the source; merging them with `||` halves the code (lw/sw/random counts drop). [C CalcSpeed__15CB3TrafficParamFibb]
- A dot product computed before a short-circuit `&&` whose first test does not need it: hoist it into a local before
  the `if`; that also restored retail's call order. [C UpdateTrafficWorldCollisionEffects 154 -> hunks ok, calls same]
- Float call arguments can be loaded into f13/f14 at function entry and survive to a much later call: SetZ(z, near,
  far) in DrawPositionMarker takes the view's near/far that retail put straight into f13/f14 in the prologue. Trace
  every f12-f19 of a call back to its last write. [C DrawPositionMarker]
- A mangled-name `bool` parameter compared with slti 2501 / 10001 is an int in retail's real signature (E-map names
  come from another build): define through the link name with retail's list. [C DrawPositionMarker]
- The 4,3,5,2 switch rule held again (func_003BC7F0): `switch { case 2: case 5: case 3: case 4: }` put every call in
  retail's order, where an if-chain had the same call set in another order.
- `(float)byte` from an lbu with a plain cvt.s.w: read the byte into an `int` first (GenerateTarget's occupancy inline:
  1046 -> 910 instrs; the direct unsigned-char conversion adds bltz/srl/or/add.s per use). [C GenerateTarget]
- Reads of values retail never sets on a path are real: keep them as uninitialised locals with a [C] comment
  (func_003AC170's race-path position `p` and crash-path time `e`; Globe UVs for region > 2; DrawPositionMarker's
  colour for an unknown race mode; a CGtV3d off.SetX/Y/Z on a local leaves w as stack garbage). The port must
  reproduce them, not "fix" them.
- A callee that overwrites an argument register before reading it (FEVerticalMove's a1, pcpyld in its prologue) still
  shows retail passing a value: kept in the call for call-by-call identity, marked as unread. [L func_003BC7F0]

## draftAK (2026-11-01)

- MWCC keeps VU0 registers live across calls: a lane source register not written in the block (`vmove $vf10,$vf9`,
  `vaddx.x D,$vf0,$vf9x`) still holds a value from an earlier block. A symbolic decode must track vmove and VU values across
  calls; RegisterVariables__16CB3CameraAttribs' field_110/140 are (0,0,-20)/(0,0,20), not the (10,10,..) a first decode gave.
  With the right values the plain `field_X.Set(x, y, z)` sequence is byte-identical (639/639). [C]
- `320.0f - 0.5f * (s * w)` fuses to adda/msub even through an inline or a separate `hw = 0.5f * (...)`; retail's mul.s +
  sub.s came back with `hw = s * w; hw *= 0.5f;` and `320.0f - hw`. [C func_0019DD00]
- Glyph quads: `cursor + g->field_10 * glyphSize` (CGtV2d product operator, through its returned temporary) keeps retail's
  unfused mul.s/add.s; `cursor + CGtV2d(a.x * b.x, a.y * b.y)` fuses to madd. [C func_00458AE0: float op counts equal]
- A by-value-looking position copied in the PROLOGUE and that copy's address passed on to a callee: the parameter is
  `const CGtV3d&`, copied into a local at entry, and the callee takes `const CGtV3d&` (by value at both ends makes the copy at
  the call site instead). [C func_0027D380]
- An arm placed after the epilogue that ends in `b <shared return block>` is the body of `if (x == 0) { ... }` at the end of
  the function, not `if (x != 0) return; ...`. [C func_0027D380, 2 hunks fewer]
- E-map mangled `fff` parameters can be one CGtV3d passed by address in retail (FindPointNearestTo: box fraction): use the
  proven link-name declaration with retail's list. [C GetHullPoints]
- Retail's out-of-line CGtV4d(u_long128) ctor call inside an inlined CGtQuatPos::ConvertToMatrix came back with a scoped
  `#pragma inline_depth(7)` [G] (6 too; 4/5 none; 8 none). [C Update__16CB3TrafficSystem]
- `% n` compiled as divu: cast the divisor (`% (unsigned int)n`) even where n is tested signed (blez) just before.
  [C FillLaneSection]
- Static locals with guard bytes (lb guard; init block out of line; sb 1) are function-scope `static CGtV2d s(x, y);`; an
  unguarded .sbss float next to them is a file static. [C func_0019DD00]
- A callee that never reads a0 although every caller passes &global (func_0019DD00, the graphics manager): keep the unused
  self parameter for call identity; the body addresses the global itself. [C]
- Unconverted `lbu` byte passed to a bool parameter (no sltu) = the field is `bool`. [C Update__16CB3TrafficSystem]

## hard1 (2026-11-01), the 7 deferred-hard functions

- Calls-same is not enough: compare the bc1t/bc1f (and c.*.s) counts and the non-stack store multiset too
  (build/vt/hard1/stores.py). UpdateRaceCarWorldCollisionEffects compiled calls-same with an inverted spray condition
  (`surf+8 == 0`, retail c.eq.s/bc1t) that only the branch counts showed. [C]
- A retail compare pair whose branches go nowhere (c.le/c.lt then fall-through to the same block) is a range test whose
  result is dead: a float local set in the body keeps it; an empty body is deleted. [C URC]
- A lbu flag used unmasked is a bool field; passing it on unmasked (sd to the stack argument) means the callee's parameter is
  bool too (an int parameter adds andi 0xff). [C URC]
- MWCC emits a switch's stacked case compares last label first: write `case 0xB: case 8: case 5: case 4: case 3:` for retail's
  3,4,5,8,11 beq chain; `default:` before the cases removes a dead duplicate store. [C func_001AE690]
- `CGtV4d v = car->field_B0; v.W()` copies lane by lane (lwc1/swc1 x4); `(float)car->field_B0.W()` gives retail's lq/sq copy. [C]
- If/else of two constant stores: retail's fall-through arm is the `!(a <= b)` one; write that arm first. [C]
- A function inlined twice (StartRaceCarCrashing = the crash body for hud id or given id) with an out-of-line sibling copy
  (func_001AE690): decode the small copy first, then reuse it as the inline. The out-of-line copy called the CGtMatrix3x4 /
  info copy constructors (func_001AF420/AF410/AF3C0); the inlined copies inline them. [C]
- C fabsf is a real call; retail's inline abs.s is GtMath::Abs (but URC's fabsf IS a jal: check each site). [C ApplyLowSpeed]
- CGtV3dPlus view `v.SetGtV3d(v.GtV3d() * k); v.SetPlus(v.Plus() * k)` = retail's split vmulx.xyz + vmulx.w + vmove.w;
  `CGtV4d * k` is one vmulx.xyzw. [C ApplyLowSpeed]
- Retail duplicating a fill loop = the fill inline called in both arms (clamps inside). A flag set with `addiu 1` after
  xor/sltiu is an int (a bool gives daddiu 1). By-value CGtV3d parameters: copy them into locals first (retail lq/sq at entry),
  else MWCC spills the argument pointers (sw a1..t1). [C AddCarToMap]
- operator-(XAxisType, XAxisType) / -(ZAxisType, ZAxisType) are in GtMathPs2Quat.h: include it before writing a stand-in. [C]
- vrnext.x/.y/.z in ONE asm statement on a "=j" operand: MWCC drops the .x/.y lines as dead partial writes (two R advances
  lost = a different random sequence). One `asm volatile` per lane with "+j". [C func_0039A360]
- "VU0 microcode upload" func_00273400 is the Soup16 callback line test (the upload is the inlined UploadVu0Code); its template
  was IntersectLineNearest(Soup16), found through the caller's archive (CGtCollisionKDTree::IntersectLine). Grep callers' archives
  before decoding a "hard" function. [C]

## fix1 (2026-11-01), drafts the port's live checks found wrong (behaviour, not codegen)

Found by running the drafts natively in the live game (the port project port6: Burn3 checker on live captures, host
`capture_replay`). Read retail's branch senses and offsets, not only the instruction counts. [C on the cited functions]
- **`c.lt.s a, b; bc1f L` takes L when !(a < b).** func_002B7DB0's draft updated when `d < dist`; retail 0x2B7E40 updates
  when the end point is NOT inside the plane. A matching-shaped draft compiled 115/112 with the sense inverted. [C]
- **Recompute pad sizes from retail's lui/ori offsets.** SetUpTrackExtents' `pad_12ACFC[0x1AB14]` put field_143810 at
  0x145810 (retail `lui 0x14; ori 0x3830`): it compiled and was scored, and every store landed 0x2000 off. [C]
- **An early `blez count` around a whole block is part of the logic:** SetUpTrackExtents skips the scan and the extent
  init when the world has no segments (0x199788 -> 0x199968); the draft always copied element 0. [C]
- **Declare arrays at their real size, not `[1]` + pad, when the code indexes them.** FillInNoGoData's `field_140[1]` +
  `pad_141[0xFF]` compiles the same on MWCC (152/151 both ways) but is UB past [0] in C++: host GCC -O2 ended the loop
  after one pass. Here the bound is evidenced (index clamped to 0..255). The same applies to `D_xxx.field_0[1]` tables
  where the bound is known. [C]
- **Store order of packed quads: map each `sq` back to its stack slot.** SetupCamera's draft had field_40/field_60's z,w
  pairs swapped (retail: +0x40 from sp+0, +0x60 from sp+0x10). [C 0x21E0A0]
- **A partial-lane VU result keeps the w of the register the compiler wrote into.** When retail fills that register with
  a defined row first (CollidingBody::Update's row products: `qmtc2 m.mAt,$vf1; vmaddz.xyz $vf1,...`), the stored w is a
  real value (here field_10.mAt.w). Write the destination's start value explicitly (`u_long128 t = w; asm("vmaddz.xyz
  %0,..." : "+j"(t) ...)`). A `vadd.xyz $vfN,$vf0,$vf0` Zero() on a register with no defined content stores a stale w
  (port class 7). That cannot come from source, so leave it. [C 0x1ACD40, 0x1ACE7C]
- MWCC refuses `cond ? a.mData : b.mData` on u_long128 ("illegal data size"): use two helpers. [C]
- `extern "C" float sqrtf(float)` is right for MWCC (one sqrt.s), but the port's float->ps2f transform turned it into a
  struct-returning prototype that breaks the Windows x64 ABI (fixed port-side, not in the draft). [C SpawnBouncySpark]

## draftAL (2026-11-01)

- A callee whose mangled name has by-value CGtV3d parameters, called by retail with the caller's own member addresses (no
  copy): declare it through its link name with `const CGtV3d&` (b119p copies by-value arguments at the call site).
  [C UpdateWheelEffects -> AddTrailSegment__14CB3TrailSystem: 636 -> 620 instrs]
- Alignment holes in a struct that retail copies memberwise (CB3ClusterRig: 0x88..0x8F before a CGtV3d, the tail to 0xE0):
  no pad members there; a pad array is copied too (byte loops: 744 -> 613 instrs). [C func_003550F0]
- A tail call into a float-returning callee whose f0 the caller reads: the function returns float. A void draft compiles to
  the same instruction count, so the bug is invisible to the diff; `float r; if (..) r = f(); else r = g(); return r;`
  keeps retail's shared epilogue (a `return f()` in each arm adds an `ld ra`). [C func_00354FD0, read by func_003550F0]
- `li v0, 1` before the epilogue with no reader in the function: it returns a constant (CB3Score::Prepare returns true);
  keep it. [C]
- Small globals that retail addresses with lui/%lo (texture pointers, CGtV2d constants, a checkpoint count): unsized arrays
  or padded structs, one declaration per symbol (merging two neighbours into one struct changes the relocation target).
  [C RoundedPanel _Render, CB3Score::Prepare]
- `CGtV4d c = obj.mColour;` copies through the float view (4 lwc1/swc1); `CGtV4d c(obj.mColour.mData);` is retail's lq/sq.
  [C RoundedPanel _Render 599 -> 593, func_003A3250]
- An `adda.s 0, 0; madd` (0 + r * 90 left unfolded) is an inline's parameter (lerp(0, 90, r)); a literal `0.0f + r * 90.0f`
  is folded by b119p. [C func_003A7F20: float op counts equal]
- A product that retail keeps unfused before an add (mul.s; add.s): build the offset vector, `o *= k;`, then add (the
  draftAK form, here for CGtV2d). [C func_003A3250]
- Not reproducible from source on b119p (all forms compile identically, don't grind): retail's if/else-if arm placement
  (inverted `if (!(x & 2)) {..} else {..}`), its bottom-test entry jump for a variable-bound inline loop (the N24 goto form),
  and a materialised `bool b = c1; b = b && c2; ...` chain (`&&`, `b = b && c`, `if (b) b = c` all thread into branches).
  [C RenderLightCoronas, CollisionIsCameraInVehicle, func_003A3250]
- GS packet builders: one inline `pcpyld` helper Q(lo, hi) per qword plus `(long)int` for every dsll32/dsra32 pair
  reproduced RenderCorona within 2 instructions (540/542). [C]
- The E map names inlines that retail never emits out of line: CB3ScoreCategory::Prepare(EScoreCategoryType, const CB3Score*,
  const float*, int), CB3CameraUtils::CollisionIsCameraInVehicle(CGtV3d, const CGtAxisAlignedBox&, const CGtMatrix3x4&, ...):
  search research/E_B3O0PCH_symbols.csv for a repeated store pattern before inventing a placeholder inline. [C]

## audit1 (2026-11-01), behaviour audit of the archives (tools/behaviour_audit.py)

Bugs the "calls identical" check let through, found by comparing ours vs retail on behaviour (14 archives fixed, 8 more
confirmed in build/vt/audit1/bugs.txt):
- **Class layouts are the most common bug.** A pad or array length off by a few bytes shifts every later field while the
  code still "looks right" and calls the same functions: CB3SoundCrashManager pad 0x84 vs 0x384 (+0x300), StopCrashing
  pad_216 0x60 too long, SetupKeys 0xE0 pad where 0x80 belongs, func_0039B330 field_14[11] for [7], a 1-byte and a 4-byte
  short field (UpdateGameStates, HeadsetControlMessageArrivedCallback). Check every `pad_X[n]`: X + n must equal the next
  field's offset name. [C]
- **Prototype from the mangled name is not the register list.** Member vs static is invisible in CodeWarrior mangling;
  a float parameter declared int leaves f12 unset (func_003A9250); a callback data pointer omitted leaves a3 garbage
  (func_0036ECC0's BuddyInvite); a free(block) helper called without its block (Update__21CB3OnlineNewsMenuPage). The
  callee's own retail code says what it reads: behaviour_audit's live-in arity. [C]
- **A test retail writes "backwards" stays backwards.** GenerateTarget's right-side loop is `k >= field_441 + 4` from
  k = field_441 (never runs) in retail; the draft "fixed" it to `<` and ran 4 passes. Mirror retail, comment it. [C]
- **Calls to a member overload that does not exist** compile and even pass the same registers (func_003A8EB0's
  GetStageGtID(int) vs retail's static (int, int)), but the port would link a missing symbol. [C]
- Literal floats: compare each argument's constant with the retail lui/lwc1 (func_004526F0 passed 30/24 where retail has
  28/22). [C]
- Not visible statically (port only): FillInNoGoData's `[1] + pad` arrays are fine for MWCC but UB for host GCC (fix1). [C]
- Tool lessons (false positives fixed in the tool): splat's `%hi(D_0012ACF8)` on plain offsets (`this + 0x12ACF8`); `%hi` of
  one symbol with `%lo` of a neighbour; stack slots composed lane by lane; `c.le(a,b)` = `!c.lt(b,a)`; xori/sltu boolean
  negations; libgcc reading uninitialised temps (no live-in claims through library code); acosf/asinf/logf are retail's
  func_0011E328/E340/E370 wrappers; tiny leaf callees (`sq a1,0(a0); jr ra`) are inline-vs-call noise.

## draftAM (2026-11-01)

- **A caller's "register allocation" difference can be a missing argument.** func_0030A9D0's archive (65/65, 2 off: "retail puts
  the element pointer into a fresh t0") called GetRadialBlurParams with three arguments; retail passes five (this, params, viewport,
  car, camera manager in t0). Passing the t0 value made it byte-identical. When a callee reads a2/a3/t0..t3 that its mangled name
  does not list, check every caller's archive: the callee's real list fixes both sides. [C func_0030A9D0, GetRadialBlurParams]
- Mangled names from retail's own table can still under-list parameters (GetRadialBlurParams: 3 listed, 4 + this read;
  CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi: the camera in a1 too, and a bool result read by
  CB3BehaviourCluster::Update). Define / declare through the link name with retail's list; Revenge's mangled name often has the
  missing parameter (CB4BoostEffectParams::GetRadialBlurParams lists lpViewport). [C]
- Look for unwired drafts before decoding: _Render__19CHeadingBar2dObject had a complete session-32 draft in
  src/b3/.../B3HeadingComponent_0031B130.cpp (marked DRAFT, not wired, never archived) that the coverage list counts as "no C".
  `grep -rl "NOT WIRED IN" src/b3`. [C]
- One CGtV4d reused for a run of VU data rows (Render__15CB3PopcornArray's lPack, retail's single $vf1): lanes a row does not set
  keep the previous row's value (row 11 z = far clip, row 23 x/w = 0 / 1.0). Write it as one variable with per-lane setters in
  retail's order; separate row temporaries would lose those values. [C]
- VU0 R-register random with a state kept in one register across draws (func_0025D930: lqc2 state once, vmr32 in place after each
  draw, one sqc2 at the end): load the state into a local, rotate it in each draw helper, store it once per group. The x-only draw is
  `vrnext.x; vmulx.x; vaddax.x/vmsubaw.x/vmsubw.x`, the lerp with it `vaddax.xyz ACC,base,vf0x; vmaddx.xyz d,range,rx`. [C]
- Gt2dRenderer strip builders that write through `unsigned long *` re-load and re-store `_gpu64Current` after every word in retail;
  b119p keeps it in a register and stores once (same final buffer and pointer). Not worth shaping; note it. [C RenderTriStripGouraudTex]
- Random draws in one expression (CGtV3d(RR() - 0.5f, 1.5f + RR(), RR() - 0.5f)) are evaluated right to left by MWCC (retail draws
  z, y, x): write them as separate statements in retail's order, or the native port draws them in another order. [C HandleBattleSparks]
- `0 + a + d * t` with constants a, d (adda.s 0,a; madd) is a lerp inline: lerp(1, 0.45, t) folds b - a to retail's exact constant
  (-0.55 = 0xBF0CCCCD, 0.985 - 0.995 = 0xBC23D700); check the folded bits with struct before choosing the endpoints. [C GetRadialBlurParams]
- CGtQuatPos::SetFromMatrix / CGtQuat::ConvertToMatrix / Slerp / Invert from the header reproduced three more inlined sites call-
  and store-identically (Update__19CB3BehaviourCluster 9 hunks, GetRadialBlurParams, Update__23CB3BehaviourInterpolate). [C]

## draftAN (2026-11-01), the last 29 functions without C

- **Revenge STABS + E map identify placeholder functions** (keep the asm label as the symbol): func_0025D430 / func_0025DF30 /
  func_0025D930 = CB3EffectsManager::SpawnPopcornFromPoint / SpawnSparksFromPoint / SpawnSparksAlongLine, func_0039AD90 /
  func_00399EC0 = CB3ExplosionManager::UpdateFire / DoAirRamExplosion, func_001ADA00 = DoTankerExplosion, func_00273070 =
  GtIntersection::IntersectSphere(Soup16): the E-map size, the caller archives' register list and Revenge's parameter list must all
  agree before tagging [L]. Revenge's parameter / static / table-struct names then fit field for field (CFireElementParams,
  CB4AirRamFlashParams = B3's 0x40 / 0x48 tables). [L]
- **Three random shapes besides CV3dRandomiser**, all raw R draws in [1,2) with no state: CScalarRandomiser (mVec x = max - min,
  y = 2 min - max; `vadday.x ACC,vf0,y; vmaddx.x d,mVec,r`) and CV4dRandomiser (mVecA = 2 min - max, mVecB = max - min; four
  vrnext lanes, `vaddax.xyzw; vmadd.xyzw`); the lane setters run y before x. Constant min/max fold at compile time (y 0, x 0.25).
  Header gaps queued. [C 0x25D7B0, 0x39B140]
- **A `vrnext.x $vf0, $R` with no reader is a dropped draw:** keep it as a volatile R advance (it shifts every later random value).
  [C 0x25D8D4]
- A dead `c.le.s` with no branch after it (func_00257860) came back from an if/else setting a float nobody reads (hard1 rule).
- Fused `a + b * t` (`adda.s 0,a; madd.s`) with literal a, b is plain C; routing it through an inline helper unfused it here
  (UpdateFire 2 madd -> 1). Write the expression directly first.
- An inline that returns a CGtMatrix3x4 by value, assigned to a declared-first local (`M m; m = f();`), brings back retail's byte-loop
  copies (RenderAmbientShadow 113 -> 151 of 160); `M m = f();` constructs in place. The unset mPos it copies is real (overwritten after).
- Forks' rules (notes_B / notes_C): vcallms `.word` = 0x4A000038 | (entry / 8) << 6; scoped `#pragma opt_removeemptyloops off` keeps
  an empty ctor loop; `pos + CGtV2d(dx, 0.0f)` keeps retail's unfolded `+ 0`; constants a sinit writes (D_004C4290..) read as 0 in
  the ELF -- decode them from the sinit; `SetY((float)v.Y())` = retail's lw + qmtc2 + vaddx.y; `!(x <= y)` keeps c.le / bc1t with
  NaN semantics; **a proven tiny forwarder can under-declare its callee** (func_001A9D70 passes a1..t0 to func_001AA3F0 but its C
  lists only self): byte-identical, wrong for the port.
- Not game logic: sceVibSetActParam (0x217520) is Sony libvib.a code linked into the game range; left without C.

## fix2 (2026-11-01), behaviour bugs in the non-matching archives (audit1 follow-up) [C on the cited functions]

Read retail for these before trusting a "calls identical" archive; every item was a real draft bug:
- **gp-relative globals: take the symbol from splat's `%gp_rel(D_...)` operand, never compute it.** The son-series drafts
  (func_0025BBC0, HandleRaceCarTrafficCollisionEffects, func_0025AC30, func_0025F0C0, func_002B7F70) named every gp global
  0x7990 high (D_004E9754 for D_004E1DC4): the matching diff cannot see it, the port reads bss. `python3` scan: any D_ symbol
  an archive uses that no retail asm/matched source references is suspect.
- **Copy a callee's prototype from a matched caller when one exists** (func_0022C2F0: `(void *, int, int, int, float x4)` in
  B3Score_00157FA0). The drafts' `(float, int, float, float, void *, ...)` put every rumble argument in the wrong register.
- **Stack arguments count too.** func_0025EA70 takes an 11th argument on the stack (`sd v0, 0(sp)` before the jal); the
  10-parameter callers left it garbage. behaviour_audit does not see outgoing stack slots: check `sd/sw ..,0(sp)` by hand.
- **A callee whose retail reads f14..f17 gets them** (func_00254A90: 6 floats): func_0025E410/EA70 passed 2.
- **MWCC's first virtual is at vtable +8**; vfunc_XX = slot offset. Declaring vfunc_0/vfunc_4.. first shifts every slot by 8
  (Prepare__10CB3RaceCar F8 -> +0x100, func_00333990 0x10 -> 0x18).
- **A vtable pointer in the middle of an object** (`lw t9, 0x1B0(a0); lw t9, 0x20(t9); jalr` with a0 = the object): declare the
  data up to +0x1B0, then the virtuals (MWCC puts the vptr where the first virtual is declared), not a `field_1B0` object
  pointer (UpdateSmallMessage, Prepare__10CB3RaceCar).
- **A virtual call on a global object** must go through a cast pointer (`((T *)&D_x)->vfunc_C()`, as the matched func_0037B770);
  the direct form is devirtualised to a symbol retail does not have (func_0043BC90, AddRaceTime).
- **Placeholder types in a declaration change the link name**: RenderTristrip(const UnkStruct *) vs CB3Im3dVertex, int for an
  enum (GetPresence, GetTrackRegionString), C++ vs extern "C" (ustrncpy), placeholder classes in a member declaration
  (HandleRaceCarTrafficCollisionEffects, RenderAmbientShadow). Use the mangled name's types (a type named in a retail mangled
  symbol is evidence for that name). A header inline declared but defined elsewhere (CGtV4d::SetW(WAxisType) in
  GtMathPs2Quat.h) links a missing out-of-line symbol when its header is not included.
- **Outputs through pointers: follow the mangled parameter order** (GetCrashZoneAndCorner wrote the zone into the corner).
- **A pointer argument the callee writes back** (Update__19CB3SoundTrafficPass normalises *a2 in place, `sq v1, 0(s2)`) is
  part of the behaviour; a local copy loses it.
- **Results copied out of a stack object after a call**: map every `lq off(sp); sq field(s0)` pair (CollideWithWorld copied
  2 of 8 hull-collide results, from the wrong offsets, and passed the stack object as its own params).
- Layout errors found by offsets (pad arithmetic, `[n]` counts, a stray byte, alignment holes): Draw__16CB3TrafficSystem
  (vehicles 0x20 low from alignment after a 0x18-stride table; [0x160] for [0xFE]; params 0x160 high), RenderShadows (0x600),
  HandleRaceCarTraffic (4), hud field_27C0 (0x31C0), Prepare__19CB3BehaviourCluster (0x10), SoundTrafficPass (a stray pad byte),
  SoundCrashManager tables (wrong base symbol, one quad off), func_003A74D0 (offsets written into the colour field).
- Constants: compare each literal's bits with retail's lui (func_00439620 0x3F6F/0x3F2C vs 0x3F6E/0x3F2E, func_003FD1F0 28 vs
  30, UpdateSmallMessage 1/1609.344 = 0x3A22E384 not 0x3A22E380); a compare's zero that retail keeps in f12 for the call
  (func_003A74D0); UV tables in retail's store order (func_003B0160); a float member stored as -1 (0xBF800000) is float.
- Array order of a stack array passed to a callee: `cols` (sp+0x478 = [0]) was swapped in both rumble drafts.
- Random draws: the effects code's vector randoms are CV3dRandomiser (frac(R x state) with state rotation), not raw R values
  (raw `vrnext` is in [1,2)); a raw 4-lane draw lerps v100..v110 including w (func_0025E410).
- Tool (behaviour_audit) false-positive classes made quiet by fix2: CV3dRandomiser statics vs D_01D9D190/D_01EA4BA0; quad
  lanes vs word loads; vcall registers untouched on one side; return values nobody reads (direct callers checked) and int
  functions with f0 garbage; callee-saved registers read before written; libm wrappers (f12 only); int 0 vs 0.0f and byte /
  halfword constants by their low bits; a value that is one input of the other side's merge (weight 2). New check:
  `call-unresolved` (a callee name with no retail address that our object does not define).

## fix3 (2026-11-01), every remaining strong-class audit finding checked against retail [C on the cited functions]

Real bugs (the diff could not see them):
- **Static helpers declared as members.** CB3DirectionalBlur's Downsample / BlurSetRenderstates / BlurIn / BlurOut / CopyToScreen /
  RestoreRenderstates take their first argument in a0 (retail Render 0x426F0C..); Render's archive declared them as members, so every
  argument sat one register late. The twin CB3RadialBlur helpers really are members (a0 = this, 8th argument on the stack): check each
  class, not the family. [C]
- **A link-name declaration one argument short.** OnTakedown declared `GetUnitOriginalID__16CB3StreamedTrackFi(void *)`: the `i` is a
  real argument (the player's signed byte +0x216 in a1, the matched callee reads p0). For a member, the declared list must be the
  mangled list + this. build/vt/fix3/protoscan.py checks every extern "C" link name against the mangled count and against the callee's
  retail live-in registers (pass 2: hidden struct-return pointers, static members and forwarded live-ins are its known FPs). [C]
- **An embedded object called through its container.** UpdateRaceCar called `D_0064D388[idx]->UpdateFlyingBits()`; retail calls it on
  vehicle+0x380 (`addiu a0, v0, 0x380` in the jal delay slot). Read the delay slot of every jal. [C]
- **deg -> rad literal:** `0.0174533f` is 0x3C8EFA39; retail's constant is 0x3C8EFA35 (= 0.017453292f) in three archives
  (BehaviourTrackSide Prepare / Update, CarViewerGameMode Update). behaviour_audit's new `const-near` check pairs floats within 2%
  that only one side uses. [C]
- func_002B7F70 (the hull face query skeleton) drafted completely (542/539, calls identical); notes build/vt/fix3/B/. Its callee
  func_002BEDB0 is matched as `void` but returns the clipped vertex count, and B3ConvexHullCollide.cpp declares func_002B7F70 with
  3 parameters (retail reads 2): header/prototype gaps for the port.

Equivalent forms the audit flagged (now quiet in the tool or listed in tools/behaviour_audit_fp.tsv with the reason):
- retail branchless clamps (vmax/vmini on VU, max.s/min.s on the FPU, `sltu` for `a || b`) vs our compares;
- a global re-read right after this function stored it (retail keeps the register) -- tool forwards stores to absolute globals;
- lwc1 of a global folded to its ELF data on one side, ld/lq kept symbolic on the other -- `romfold`;
- `x` (a base the dataflow lost: indexed, spilled, loop-carried) vs a concrete term -- `wild_eq`, weight 1; a merge of KNOWN values
  vs one of them stays a signal (HandleObjectObject's lo/hi swap turned out path-specialised, verified by hand);
- `D_x[i + k]` with k * size folded into the base (0x1EA4470 vs 0x1EA4648) -- `idx_fold_eq`;
- a test of a merged pointer on one side, of each arm on the other (tail duplication) -- paired in the cond check;
- an unknown store base pools every pointer store at an offset (quad lanes vs sq): only differing literals stay a signal;
- retail's unrolled init vs our loop (func_00459910: 39 store-missing) -- left as is (store-missing stays a weak class).
Noise classes downgraded to weight 1: branch census (except float compare kinds whose totals differ: calibration's
DetectNormalNearMiss is only visible there), return-paths, loop-counter conds unless the loop bound is one the other side never
tests (a 10 -> 13 bound mutation still scores 3), and constant counts (except const-near).
fix3-C (cond pairs, build/vt/fix3/notes_C.txt; 11 of 33 symbols real):
- **Name a field by its offset from retail's lui/addiu, never by the symbol suffix:** func_0044E400 named D_01ECD9F0's fields after
  the splat label each access happened to hit; every field after field_38 sat 0x10 low. Update__17CB3RaceCarPhysicsFf: a car pad
  0x1000 too long (0x27C8 read at 0x37C8); DoCrazySparks pad_216 0xAA for 0xAAA. [C]
- **mph literals are m/s:** GetRacingDrivingControls compares against 8.9408 (20 mph), 13.4112 / -13.4112 (30 mph); the draft had
  2 / 3 / 0.5. Read every compare literal from the gp/lit4 pool. func_003816E0 0.3 / -0.2 (draft 2.0 / 1.0). [C]
- **mwperm rewrites can change behaviour:** func_003BB7A0's `< 16` became `<= 16` (retail sltiu 0x10). Archives whose notes say
  "mwperm:" and touch compares deserve an audit. [C]
- Out-parameters that write two quads (func_003E5CC0's func_003E6C20), stack arguments past t3 (func_003B0870's 9th Prepare argument),
  entry stores (IntersectLineNearest res+0x50 = 1.0), lane choice of a partial zero (x/z, not x/y). [C]
- Tool FP classes it reported (not all modelled yet): merged constants keyed by another branch's constant (incl. movz/movn picks), set
  tests lowered differently (bit masks, (x-1) < 3, jump table vs chain, pminw), `li 1/0; andi 0xFF` bools, sqrt.s not modelled, a
  one-lane VU write-back vs one swc1, identical arms merged changing call counts.

## near1 (2026-11-01), near-miss archives rescored (build/vt/near1/notes.txt)

- **Check for stale archives before working a near-miss:** 193 src/nonmatching archives were of functions already proven
  (TU regrouping moves their glabel into a proven unit, so `tiny_batch.where` returns nothing); deleted. A rescore
  that reports "proven?" / no unit for a name = stale archive.
- **A function-local static is a wire-in shape now** (`static int lnRotate;` = retail .sbss D_004E294C): tools/sdata_retarget.py
  retargets the object's LOCAL .sbss symbol at retail's .sbss dlabel (size checked), as for .sdata initialisers. Write the
  static where Revenge's STABS has one; an `extern int D_...` gives other codegen (PresentDrawBuffer: 14 changed vs 0). [C]
- Residues that no tried source form moves (don't grind; counted in the notes): one independent instruction scheduled 1-5
  slots earlier in ours (46 of 54 moved instructions in the 128 live near-misses point that way); branch delay slots
  filled from the target on one side only; an inlined same-file function's result joined in v1 with a `move v1,v0`
  where retail keeps v0 (SharedNetworkLogin*Prepare x3: real auto-inlined func_003615B0 too). [C on the cited sites]
- C vs C++ compile of the ezNet library archives gives identical code (not the cause of their delay-slot residues). [C]

## draftAO (2026-11-01), the 22 partial archives made complete [C on the cited functions]

- **A "partial" header can be a scoring artefact.** Four archives scored "ours 0 / 4 / 63" only because nonmatch.py diffed retail's
  label against a symbol the object did not define (N104's retail-signature CB3VSelectComponent::Prepare; member placeholders such as
  func_00144E70__11CB3AIDriverFv / ResetCarInSlice) or only the first entry of a multi-entry label (func_004404E0, func_0022E200).
  nonmatch.py now diffs `label=<our one symbol>` and scores alabel units whole (as try.py); behaviour_audit falls back to the
  object's one function. Its audit of a multi-entry label still sees the first entry only: check the others by hand.
- **A psweep `#pragma inline_depth(3)` can leave header inlines out of line** (func_002F2E70: XAxisType's copy ctor, then
  XAxisType::operator-): a call retail lacks and a link name the port does not have. Drop the scoped pragma in a behaviour
  archive when the object references any GtMathPs2 symbol (`call-extra` in behaviour_audit).
- **Scheduled-before-the-branch values:** VSelectComponent::Prepare's c = a + 0*(e - a) is computed before the field_D4 test with
  the zero register (0x321348); the draft fed the conditional half width into it. A madd whose operand register is written only
  later (after a branch) uses the earlier value.
- **sltu = unsigned fields** (func_0022E200's receive ring 0x22E3B4 / 0x22E4DC): positions compared unsigned, the free-space
  difference then compared signed (slt) with the packet size -- declare the fields unsigned and the difference int.
- **Member array vs pointer arithmetic** (DynamisePropBody): `this->field_C3900[k].field_220` gives retail's per-field
  `lui; addu; lw` with one base, a slot pointer folds the offsets; a function-scope `int best;` declared before the first local
  fixed the s1/s2 swap (181/181, 25 changed: only the slot-header schedule left).
- Fork rules (notes_B / C / D): **static member functions take their first argument in a0** (DrawInvisiblePolys read p from a1);
  **swapped roles in a one-of-two branch** (HandleCrashingVehicleVehicleCollision applied the 0x930 mask, tanker test, speed
  test and crash to the other vehicle; retail 0x1ADD54); **operand order of a VU subtract per index** (SetVirtualBoneMatrix
  index 3 is other - m, 0x3E655C); **box layout max first** (CGtCollisionKDTree +0 max, +0x10 min; Revenge CGtAxisAlignedBox);
  traversal stack 64 entries, not 32; HEVYCAR5/6 inverse-inertia diagonal (0.00075, 0.0008, 0.0011) [C 0x1BF830]; the
  viewport's second flags store goes to frame+0x1C again, not +0x2C; SpawnDebris gets velocity, axis, prelight and size y^8.
- Gaps closed: func_002BEDB0 returns func_00272EA0's int (byte-identical `j`); B3ConvexHullCollide's func_002B7F70 takes 2
  arguments (the a2 at the call is a register leftover; disassembly identical); CGt2dFont +0x10 is a float [C 0x381784]
  (headsafe 44 same). Gate: verify_all 3755 SAME, 0 not identical; MATCHES RETAIL.
