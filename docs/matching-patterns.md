> Imported 2026-10-21 from `the earlier research repo/docs/matching-patterns.md` (commit b30e033, the maintainer's own
> work; docs/provenance.md). Rows 1-28 were found there; paths such as `matching/vu0/`, `build_retail.py`, "E", "retail"
> refer to that project. Patterns found in this repo are in docs/known.md (N-rows); add new rows here only
> when they are proven by this repo's harness.

# Matching patterns (CodeWarrior PS2, -O4 -Cpp_exceptions off; E: 3.0.1b103, retail: 3.0.1b119)

Source-shape rules found while matching build E. Each entry: symptom in the diff → fix → where it was proven.

| # | Symptom | Fix | Proven on |
|---|---|---|---|
| 1 | Extra `nop` between a load and `jr ra` in a getter | Return a **typed** pointer (`CB3RaceCar*`), not `void*` | `CB3ScoreBonus::GetDuellingCar` (E 0x312800) |
| 2 | `addu` operands swapped / a local pointer held in a register | **Repeat the full member expression** (`mpData->maState[i]`) instead of caching `&...` in a local | `FlapBodyPart` (0x191ab0), via permuter |
| 3 | Unsigned range check `(u32)x < 2` compiled through `$at` | Write it as `x == 0 \|\| x == 1` (compiler folds to `sltiu $at`) | `FlapBodyPart`, `DetachAll` |
| 4 | Member base held in a temp register (`addiu a0, s0, off` then `sw (a0)`) | Use **real struct members**, not `*(T*)((char*)this+off)` casts | `PlayerCarPhysics::Prepare`, `FireAirRam` |
| 5 | Globals addressed via `$gp` instead of `lui/addiu` | Give extern objects their **real size** (> 8 bytes); small-data only for ≤8-byte objects | `ReleasePayload`, `DetachBodyPart` |
| 6 | Byte flag loaded with `lb` instead of `lbu` | Field is `bool`/`unsigned char` | `PlayerCarPhysics::Update` |
| 7 | Virtual call offset off by 4 | Count virtuals: CW vtable has an **8-byte header**; slot n is at `8 + 4n` | `PlayerCarPhysics::Update` (slot 6 = +0x20) |
| 8 | Function returns via shared epilogue (`b → move v0,s0`) | **Single `return` at the end**: `if (ok) {...} return ok;` | `CB3VehiclePhysics::Prepare()` |
| 9 | 16-byte vector copied as 4×`lwc1/swc1` instead of `lq/sq` | `CGtV3d` = `union { float f[4]; u_long128 q; }` (`u_long128 = unsigned int __attribute__((mode(TI)))`) | `FireAirRamUpwards` |
| 10 | Several call sites merged into one `jal` with direction chosen per branch | Choose a **pointer in each branch**, then make one call; re-read the member in each branch | `FireAirRam` |
| 11 | Stack frame 0x10 too small; vector built then `lq/sq`-copied to a second slot | **Assign from a temporary** (`CGtV3d v; v = CGtV3d(...)`) instead of direct construction | `DoCrashBreaker` (frame matched) |
| 12 | Float written via int literal at runtime (`li 9999; mtc1; cvt.s.w`) | Assign an **int literal to a float** (`mrX = 9999;`), not `9999.0f` | `StopCrashing`, `CB3VehiclePhysics::Prepare` |
| 13 | Memset sequence | Plain `memset(&member, 0, sizeof(member))`; CW emits each call with the size in the delay slot | `CB3VehiclePhysics::Prepare` |

| 14 | Matches on E but a call fails on retail | Calls were masked on E: **always confirm on retail with name-resolved relocations**. Base classes found this way: `CB3PlayerCarPhysics : CB3AICarPhysics` | build_retail.py, 2026-10-14 |
| 15 | VU0 code (`vadd/vmul/...` with compiler-chosen `vf` regs) | GCC-style inline asm with `"j"` operands, one statement per vector op; zero = `vadd.xyz %0,$vf0,$vf0` | ClearAccumulatedValues, SetAIOutOfRange, CGtV4d::operator* |
| 16 | Whole function is `j target; nop` (tail call), ours builds a frame + `jal` | Compile with **`-Cpp_exceptions off`** (now the default) | `CB3VehiclePhysics::Destruct/Release`, tail2 4/4, phys1 +2 (compilers.md) |
| 17 | VU0 values bounced through GPRs (`qmfc2 a1,vf2; qmfc2 v1,vf1; qmtc2 a1,vf2 …`) around an ACC-only op | GPR (`"r"`) operands with **explicit `qmfc2/qmtc2` in the asm text**, the ACC block `volatile`, and **`#pragma peephole off` scoped by push/pop** around that definition only | `CGtV3d::GetSquaredLength` (E 0x29f230), see "VU0 GPR spill pattern" below |
| 18 | Retail: delay slot left as `nop` after a branch where our build fills it | Compile retail with **3.0.1b119** (build_retail default) | retail `FlapBodyPart`, `ReleasePayload`, `DetachAll` (compilers.md) |
| 19 | Retail `FireAirRam`: member pointer loaded once before the branches, target reloads it per branch and has one call | Choose `CGtV3d* d = &mpMatrix->mRight/mAt/mUp` per branch, then **one** call with `*d` (row 10 again, under b119) | retail 0x1cc520 |
| 20 | Unit calls fall back to "derived" symbols | Usually a **source error**: wrong base class or parameter type. The derived list showed `CB3VehiclePhysics : CB3CollidingBody` (not the invented `CB3BaseVehiclePhysics`) and `GetFlyingObjectIndex(CB3VehicleData*, …)` | build report |
| 21 | Small vector result copied through an 8-byte stack slot (`swc1` x2, `ld`/`sd`), mul and sub not fused into `msub` | `CGtV2d` operators build a **local and return it** (`CGtV2d r; r.f[0] = ...; return r;`), not `return CGtV2d(x, y)` (which fuses to `msub` and drops the copies) | retail `CGt2dObject::SetPos` 0x1D5E00 (100%) |
| 22 | 128-bit by-value parameter (`CGtV4d`): its `lq` scheduled first / a copy made at the call, or not | Declare the parameter **`const CGtV4d`** (same mangled name) and give `CGtV4d` **no** copy constructor; a copy constructor fixes the callee's order but forces a copy at every by-value call (`_Render` passes `space.colour` uncopied) | retail `CGt2dObject::Prepare` 0x1D5E70, `CGt2dObjectBox::Prepare` (100%) |
| 23 | Same-file methods inlined into a caller **and** kept out of line | `#pragma auto_inline on` at the top of the file (the `inline` keyword drops the out-of-line copies) | retail `Gt2dObjectImage.cpp`: `SetTexture`/`SetUVs` inlined into `Prepare` (92.5%) |
| 24 | A field stored from a register nothing set (`sw a2` standalone; `lw v0,0x40(sp)` when inlined: the **next argument slot**) | Open: an uninitialised local lands in v0/a0, not the next argument slot (`int`/`register`/order variants 96–98%). Candidate for the permuter | retail `CGt2dObjectImage::SetTexture` 0x1D6070 (98.33%), `Prepare` 0x1D60B0 (92.53%) |
| 25 | A vector copied to the stack before a scalar multiply (`swc1` of the source vector, then mul) | The scalar multiply is a **free operator taking the vector by value**: `operator*(const CGtV2d v, float)` (not a member) | retail `CGt2dFont::RenderString` 0x1D7B90 |
| 26 | Same-file layer/array element reloaded per field store | Hold the element in a **local reference** (`UnkStruct& layer = field_2c[i];`) | retail `CGt2dScene::Prepare`, `Construct` (100%) |
| 27 | Two registers swapped between related temporaries | Change the **order the temporaries are computed** (pointer before size) | retail `CGt2dScene::Construct` (100%) |
| 28 | Indirect call (`jalr`) where retail has `jal`, calling a function under a different signature | Declare the target `extern "C"` under its exact mangled symbol with the real parameter list (not a cast function pointer) | `CGtFreeListPool::Construct` via upstream's `GtLListPoolCreateInMemory` |

## VU0 GPR spill pattern: `CGtV3d::GetSquaredLength` (2026-10-14)
Target (12 instr.): `lqc2 vf2,0(a1); vaddw.x vf1,vf0,vf0w; vmul.xyz vf2,vf2,vf2; qmfc2 a1,vf2; qmfc2 v1,vf1; qmtc2 a1,vf2; vadday.x ACC,vf2,vf2y; qmtc2 v1,vf1; vmaddz.x vf1,vf1,vf2z; qmfc2 v1,vf1; jr ra; sq v1,0(a0)`.
All with `-O4 -Cpp_exceptions off`, harness vs E. Test files `matching/vu0/v7.cpp` … `v13.cpp`.

| Variant | Form | Result |
|---|---|---|
| v7 A–H | C-side: assignment vs init, `u_long128` by-value helpers, `register` locals, `.q` member copies, local copy of `*this`, result declared first, vadday+vmaddz in one `"j"` block | all **identical 7-instr. output** (no spills): the optimizer keeps everything in vf regs |
| v8 I–M | `"r"` operands + explicit `qmtc2/qmfc2` in the text, non-volatile, one or several blocks | explicit moves **removed** by the compiler (it parses the asm and propagates copies), back to 7 instr. |
| v8 N | as J, ACC block `volatile` | 12 instr., right shape; vf1/vf2 roles and the first ops in a different order |
| v9 P/Q (one first), P2/Q2 (sq first) | `"=j"` producers, volatile `"r"` consumers (separate or combined) | P2/Q2: instr. 4–10 match; producer part differs (sq moved out before `one` is computed) |
| v9 R/S | everything `"j"`, consumers or all statements volatile | 7 instr. (volatile alone does not force spills) |
| v10 U1–U3 | both producers in **one** `"=j"` asm statement | producer order/regs still differ |
| v10 U4/U5 | producer block with fixed regs + `"r"` outputs (`lqc2 $vf2,0(%2) … qmfc2 %0,$vf2; qmfc2 %1,$vf1`), volatile consumer | **11/12**: last store is `sqc2 vf1,0(a0)` instead of `qmfc2 v1; sq v1` (peephole folds the move) |
| v11 W1–W6 | final-store variants (temp, separate qmfc2, `"=j"` output, pointer store, one big block) | all 11/12 except W2/W3 (worse) |
| `-pragma "peephole off"` (global) | v10 U4/U5, v11 W1/W4/W5/W6 | **MATCH**. But global peephole off breaks other matches (t1 6→4, phys1 8→6, flap_final 1→0, v2 3→0), so it is not global |
| `-pragma "schedule off"` (global) | same sets | no match (instr. 10–12 differ) |
| v12 | `#pragma push` / `peephole off` / `pop` around the inline definition only, global flags default | **MATCH** [C] |
| v13 | same, via `include/GtMathPs2.h` | MATCH only when the definition comes **after** `CGtV4d::operator*` (an inline asm function defined after the pop changed register allocation; cause open) [C] |

Other findings:
- MW's GCC-asm parser rejects an operand reference directly followed by `\n` inside one literal (`"... %1\n\tqmfc2 ..."` → "illegal operand"). Split the literals: `"... %1" "\n\t" "qmfc2 ..."`. [C]
- Inline-asm `"r"` operands can't be used in VU instructions directly ("illegal operand"); move them with explicit `qmtc2`. [C]
- Reading: the original header probably wrote these VU0 helpers as hand-scheduled asm with explicit GPR moves under a scoped `peephole off`. Whether other GtMathPs2 functions share the same scope is open (CGtV4d::operator* and the v2 functions need peephole **on**). [L]

## Open patterns (not solved yet)
- ~~Tail calls~~: solved, row 16.
- **VU0 vector math** in general: `GtMathPs2` header in progress (rows 15 and 17 cover two styles).
- **Branch-target block order** at the end of functions (`DetachBodyPart`): permuter stopped.
- **Address-of-local via register** (`addiu v1, sp, 0x20; sq a0, 0(v1)`): retail `StartCrashing` (0x1cbc70) is still open under b119. Tried: out-param accessor (copy or `.q`), by-value `.q` accessor (frame size then right), a `CGtV3d` copy constructor, early return, `== false`. The branch layout (target `bnez` skips the body) also differs. Variants in `matching/retail_flags/vpv.cpp`.
- **Block order at the end** of retail `DetachBodyPart` (0x1cbd80): 2 instructions (else block falls through into the epilogue in the target); variants DB1–DB5 tried.
- **Unfilled delay slots** in retail `B3DataLists.cpp` (`IsTrackPointToPoint`): per-file `schedule off`? Untested.

## Permuter log
| Function | Base score | Best | Status |
|---|---:|---:|---|
| FlapBodyPart | n/a | **0** | matched (48 iterations) |
| PlayerCarPhysics::Prepare | n/a | 90 | stopped (15 min limit) |
| DetachBodyPart | 235 | none found | stopped (25 min) |
| StartCrashing | 1525 | 710 | stopped |
| DoCrashBreaker | 1575 | 1160 | stopped |
