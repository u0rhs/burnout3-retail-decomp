# Target folder/file structure and its evidence

Burnout 3 Retail (SLUS-21050) itself contains no literal source-path strings in any build we have
access to (A/B/C/E/F/H — see `docs/known.md` row K19, carried from the earlier research repo). The structure below
is therefore **inferred**, same as it is for the earlier research repo, from two sibling builds that do carry real
paths, plus the one Burnout 3 build with real names (no paths).

## Evidence sources

1. **Burnout 2, Aug 5 2002 prototype (`SLUS_204.97`)** — 186 literal debug source-path strings (K18):
   - game code: `gamesource\{Menu,Race,Hud,Game,Sound,Render,Physics,toolkits}\`
   - shared engine: `GameShared\GameClasses\{FileSystem,MemoryCard,Mpeg}\ps2\`
   - HUD files: `gamesource\Hud\CHud*.cpp`; 2D object: `gamesource\Render\2d\C2dObject.h`
   - Tag: `[C]` for the literal strings; `[L]` for assuming Burnout 3 kept this tree (B11, unproven —
     see `docs/known.md`).
2. **Burnout 3, Jun 8 2004 prototype (`DNAT_200.45`, "E")** — no path strings, but ~9,300 real
   function/class names and the bare filename (no folder) each belongs to, via its link maps. Combined
   with the fact that most original files form one unbroken address range in retail, this gives
   **exact per-file boundaries by name** — a much stronger method than heuristic address splitting.
   Tag: `[C]` for which functions belong to which named file; the file's folder is still inferred.
3. **Burnout Revenge, Jul 14 2005 prototype (`SLUS_212.42`, "R_jul14")** — full GCC stabs debug info:
   2,717 types, 9,416 named functions, **861 literal source paths**. One year after Burnout 3, same
   engine lineage. 3,832 of Burnout 3's own E-map functions match Revenge signatures exactly, and
   `CGt2dScene`/`CGt2dObject` layouts are byte-identical. Tag: `[L]` for Burnout-3-folder hypotheses
   from this source (B14, unproven) — strongest where a class's *layout*, not just its name, matches.

## Decision: which hypothesis to use where

the earlier research repo's own docs/conventions.md already made this call (2026-10-15) for its project; this repo keeps the
same decision rather than re-litigating it without new evidence:

- **Game-specific code** (`CB3*` classes with no Revenge/engine counterpart): Burnout 2's tree,
  `src/b3/gamesource/<Area>/`, Area taken from the B2 counterpart class where one exists.
- **Shared engine code** (`Gt*`-prefixed classes present in both Burnout 3 and Revenge with matching
  layouts): Revenge's tree for that area, `src/b3/GameShared/GameClasses/<Area>/`. Confirmed so far only
  for 2D/graphics (`Graphical/2d/`, per K24/K26/K30/K32).
- **Anything without a checked citation**: `src/b3/_unclassified/<real filename>.cpp`, never placed on
  a guess.

## Current placement

| Path | Status | Evidence |
|---|---|---|
| `src/b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.cpp` | placed | `[L]` B14 + `[C]` K24 (layout matches Revenge, unrelated to B2's `C2dObject`) |
| `src/b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectBox.cpp` | placed | same |
| `src/b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectImage.cpp` | placed, **upgraded to `[C]` 2026-10-20** | `[C]` literal alienbrain path `alienbrainWork\GameShared\GameClasses\Graphical\2d\Gt2dObjectImage.cpp` (`research/R_jul14/symtab.csv`, N35) — exact match to this file's existing placement, confirming the original `[L]` B14 layout-inference call was correct |
| `src/b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.cpp` | placed | `[C]` K32 (byte-identical layout to Revenge's `CGt2dScene`) |
| `src/b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.cpp` | placed | `[L]` K32 notes `CGt2dFont` differs from Revenge by one word, same family |

N167 (2026-10-26): `Gt2dObjectImage.cpp`, `Gt2dScene.cpp` and `Gt2dFont.cpp` above are still the seeded, unlinked
whole-file partials. Their retail ranges are no longer whole-file asm units named after them: the asm is now ordinary
chunks `game/unit_001D5FB0`, `game/unit_001D7560` and `game/unit_001D7A70` (same bytes), so the per-function tools work
them; proven functions get `<File>_<ADDR>` units like every other file. The folder evidence in the rows above is unchanged.
| `src/b3/gamesource/Physics/B3PlayerCarPhysics_*.cpp` | placed 2026-10-20 | `[L]` `CB3PlayerCarPhysics` ↔ B2's `CPlayerCarPhysics`, verified-matched entries in `research/B2_aug05/b2_names_for_match.csv` (e.g. `Init__17CPlayerCarPhysicsFv`) |
| `src/b3/gamesource/Physics/B3VehiclePhysics_*.cpp` | placed 2026-10-20 | `[L]` `CB3VehiclePhysics` ↔ B2's `CVehiclePhysics`, same CSV (e.g. `Update__15CVehiclePhysicsFf`) |
| `src/b3/gamesource/Physics/B3CollidingBody.cpp` | placed + proven 2026-10-20 | `[C]` folder: literal alienbrain path `alienbrainWork\CG4\Game\Code\GameSource\Physics\B4CollidingBody.cpp` (`research/R_jul14/symtab.csv`, N35) — Target #13. Split out of `B3VehiclePhysics.h`, where it had only ever lived as an embedded base-class definition (`CB3VehiclePhysics : CB3CollidingBody`), into its own dedicated file; `B3VehiclePhysics.h` now `#include`s it instead. `[C]` content: `StopImmediately()` matched retail byte-for-byte (N37), including exact VU0 instruction scheduling, via a hand-inlined `asm volatile` block — plain per-field `.Zero()` calls got every value right but not the exact instruction order (N38). |
| `src/b3/gamesource/Physics/B3CollidingBody_001AC450.cpp` | placed + proven 2026-10-20 | `[C]` same class/folder evidence as `B3CollidingBody.cpp` above — Target #15. Separate file (not the same source file as `StopImmediately`) because its two methods' real retail addresses (`0x1AC450`) are not adjacent to `StopImmediately`'s (`0x1AB040`); a single compiled object's `.text` would be placed as one contiguous block by the linker, which would contradict retail's actual layout (unrelated functions sit between them) — same reasoning already established for `B3PlayerCarPhysics_001BD640.cpp`/`B3PlayerCarPhysics_001BDF10.cpp`. `[C]` content: `Destruct()`/`Release()` are both empty bodies, matched on the first compile; required splitting their containing multi-function splat chunk first (N41), the first time this project has done that. |
| `src/b3/gamesource/Physics/B3CollidingBody_001ABDD0.cpp` | placed + proven 2026-10-20 | `[C]` same class/folder evidence as `B3CollidingBody.cpp` above — Target #16. Separate file for the same non-adjacent-address reason as `B3CollidingBody_001AC450.cpp`. `[C]` content: `StopCrashing()` matched retail byte-for-byte (N43), including a second VU0 register-reuse/scheduling idiom in the same family as N37/N38, via a hand-inlined `asm volatile` block; required a second, simpler (two-way) chunk split to pull it out from behind the much larger `CollideWithWorld()`. |
| `src/b3/gamesource/Physics/B3VehiclePhysicsAttribs.cpp` | placed + proven 2026-10-20 | `[L]` folder: Physics/, same domain as sibling classes; no literal alienbrain path found yet. `[L]` lineage: Revenge keeps the same class renamed `CB4DrivableVehiclePhysicsAttribs` (`research/R_jul14/map_symbols.csv`), third CB3→CB4 repetition in this folder alone. `[C]` content: `Destruct`/`Release`/`Construct` (Target #17) matched retail byte-for-byte (N44), including a third, scalar-FPU-pipeline-scheduling instance of the N37/N38/N43 register-reuse idiom family, via a hand-inlined `asm volatile` block; required a third chunk split, the cleanest yet (only one new cut, since the target already started at an existing boundary). |
| `src/b3/gamesource/Physics/B3RaceCarPhysicsAttribs.cpp` | placed + proven 2026-10-20 | `[C]` class relationship: `Destruct()` tail-calls `CB3VehiclePhysicsAttribs::Destruct()` directly, confirming it subclasses `B3VehiclePhysicsAttribs.cpp` above. `[L]` folder: same Physics/ domain, no literal path yet. `[C]` content: `Destruct`/`Release`/`Prepare` (Target #18) matched retail on the first compile, no idioms needed — two are pure tail-calls, the third a simple two-call sequence. Required a fourth chunk split (same three-way shape as N41); also required a symbol alias in `build/undefined_syms_auto.txt` since an unrelated undecompiled chunk called `Release` by its old placeholder name (N46/N47). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3VListComponent.cpp` | placed + proven 2026-10-20 | `[C]` folder: `CB3MenuComponentBase`'s literal alienbrain path (`GameSource\Menu\DebugMenu\Components\B4DebugMenuComponentBase.cpp`), confirmed directly by `Construct()` tail-calling it. First file in this new Area. `[C]` content: `Construct()` (Target #20) matched on the first compile; re-verified still matching after N52's and N53's layout fixes. All three methods now proven. |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.cpp` | placed + proven 2026-10-20 | `[C]` folder: literal alienbrain path (`GameSource\Menu\DebugMenu\Components\B4DebugMenuComponentBase.cpp`, N35) — the actual base class, already referenced from `B3VListComponent.cpp`. `[C]` content: `Release`/`Prepare`/`Construct` (Target #21) matched retail byte-for-byte (N50), revealing `Prepare()` genuinely returns `bool` (not encoded in the mangled name) and requiring a large-enough placeholder for the extern `CB3MenuPageManager` global to avoid a wrong gp-relative addressing choice (N50/N51). Header refined twice since: Target #22 (N52) carved `field_8` out of the former `pad0[0xA]` blanket; Target #24 (N53) carved `field_4` (an intrusive linked-list "next" pointer, used by the peer class `CB3MenuPageManager`) out of the same blanket and added a `friend class CB3MenuPageManager` declaration for it. Both derived/sibling methods were recompiled and re-verified unaffected after each change. |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase_003192F0.cpp` | placed + proven 2026-10-21 | `[C]` file: the E map's `B3MenuComponentBase.cpp` holds SetData x2, SelectNext, SelectPrev in this order. Target #66 (N110). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase_004D7D30.cpp` | placed, **draft, not wired in** | `[C]` file: the E map's `B3MenuComponentBase.cpp` .rodata holds these five objects. Static initializer, 55/57 (N108b). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3VListComponent_0032B200.cpp` | placed + proven 2026-10-20 | `[C]` same class/folder evidence as `B3VListComponent.cpp` above — Target #22. Separate file for the same non-adjacent-address reason as the `B3CollidingBody_*` split files: `Release()` (`0x32B200`) is not adjacent to `Construct()` (`0x32B2B0`) — `Update()` (now also proven, N53) sits between them. `[C]` content: `Release()` matched retail byte-for-byte (N52) after two fixes: a sixth/"target at the start" 2-way chunk split, and a real layout bug caught and fixed before it was ever shipped — `CB3VListComponent`'s own fields had silently shifted by `0xC` bytes once Target #21 gave `CB3MenuComponentBase` real data members, which would have broken `Construct()` on its next recompile had this session not caught it. |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3VListComponent_0032B290.cpp` | placed + proven 2026-10-21 | `[C]` same class/folder evidence as `B3VListComponent.cpp` above — Target #23. Separate file for the same non-adjacent-address reason as `B3VListComponent_0032B200.cpp`. `[C]` content: `Update(float)` matched retail byte-for-byte (N53) — N49's "dead-looking load pattern" turned out to be `if (D_01E90424 == 5) return;`, a debug/state guard copied from sibling `Update()` methods (e.g. `CB3HSelectComponent::Update`) whose real logic for this component type reduces to nothing; CodeWarrior -O4 folds away the comparison/branch itself but leaves both operand loads as dead instructions. Required the N51 placeholder-padding idiom again for the extern `D_01E90424` reference. |
| `src/b3/gamesource/Menu/DebugMenu/B3MenuPageManager.cpp` → `B3MenuPageManager_0030D6B0.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/ area as its sibling components, no literal alienbrain path of its own found yet; referenced as an extern from `B3MenuComponentBase.cpp` since Target #21. `[C]` content: `AddComponent(CB3MenuComponentBase*, int)` (Target #24) matched retail byte-for-byte on the first compile — no idioms needed. Ninth chunk split (3-way, big undecompiled neighbors on both sides). Revealed two real fields: `field_1D4` (an accumulating int, bumped by the `type` argument each call — looks like a layout cursor) and `field_1D8` (the head of an intrusive singly-linked list of `CB3MenuComponentBase*`, linked via the base class's own `field_4`). |
| `src/b3/gamesource/Menu/DebugMenu/B3MenuPageManager_004D7120.cpp` | placed + proven 2026-10-21 | `[C]` file: E's `B3MenuPageManager.cpp` has a 48-byte `__sinit` and one 16-byte constant, as this. `[C]` content: the static initializer, Target #65 (N108). |
| `src/b3/gamesource/Menu/DebugMenu/B3MenuPageManager_0030D3B0.cpp` | placed + proven 2026-10-21 | `[L]` identity: an unnamed function (`func_0030D3B0`) sitting immediately before the other already-proven `CB3MenuPageManager` methods in the compiled layout, with a real caller (`d5/frontend_flow.s`) and a 184-field, constructor-shaped body (zeroes/initializes offsets `0x0`-`0x178`) — not symbol-confirmed, see N55. Tenth chunk split (3-way). `[C]` content: matched retail byte-for-byte (N55) after a naive field-by-field translation got every value/offset right but used a consistently different scratch-register set than retail despite several source-level variations tried; hand-inlined as one large `asm volatile` block (including its own `jr $ra`/delay-slot instruction and `.set noreorder` to control manual delay-slot filling inside two real loops) to pin the exact registers. Revealed the bulk of `CB3MenuPageManager`'s `0x0`-`0x178` field layout, including two 8-element and one 5-element set of parallel per-slot arrays, and a 3-float field (`0x164`-`0x16C`) all initialized to `1.0f`. |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HSelectComponent_0031CD90.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`, same `CB3MenuComponentBase` base and `Construct(1)` tail-call pattern — the horizontal-select counterpart; no literal path of its own found yet. `[C]` content: `Construct()` (Target #26) matched retail on the first compile — a pure tail-call, identical shape to `CB3VListComponent::Construct()`. Simplest chunk split yet (target already last in its chunk, one new cut). `Release()`/`Update()` proven in the next session, see below. |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HSelectComponent_0031CC90.cpp` | placed + proven 2026-10-21 | `[C]` same class/folder evidence as `B3HSelectComponent_0031CD90.cpp` above — Target #27. Separate file for the same non-adjacent-address reason as `B3VListComponent_0032B200.cpp`. `[C]` content: `Release()` matched retail byte-for-byte on the first compile — a single `DestructObject(field_8, field_14)` call, no loop (unlike `CB3VListComponent::Release()`'s array, this component owns exactly one `CGt2dObjectItalicText*`). "Target at the start" 2-way chunk split. |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HSelectComponent_0031CCD0.cpp` | placed + proven 2026-10-21 | `[C]` same class/folder evidence as above — Target #28. No new chunk split needed (already isolated by the Target #27 split in the same session). `[C]` content: `Update(float)` matched retail byte-for-byte (N57) — genuinely real logic (188 bytes), not the empty-body guard idiom seen in `CB3VListComponent::Update()`: `if (D_01E90424==5) { if (field_18 != *field_C) { field_18 = *field_C; <re-render> } }`, re-rendering an italic text label when the live selection index changes. The re-render call's full signature (8 parameters, matched via its mangled name appearing verbatim in the compiled relocation) was recovered from Revenge's full stabs (`research/R_jul14/symtab.csv`) since retail's own name tables only carry a truncated form — see N57. Required the N51 placeholder-padding idiom for the extern `D_01E90424` reference (the other two externs touched, `D_01E903C0`/`D_00665ED0`, already compiled with correct absolute addressing without padding). |
| `src/b3/gamesource/Sound/B3SoundPlayerCar_0028CA50.cpp` | placed 2026-10-20 | `[L]` Revenge has `CB4SoundPlayerCar` (`research/R_jul14/symtab.csv`: `StopFuse__17CB4SoundPlayerCar`) confirming the CB3→CB4 game-class pattern; no direct B2 hit, Area from class domain (sound) |
| `src/b3/gamesource/Race/B3TrackDataStruct_003A20E0.cpp` | placed 2026-10-20 | `[L]` Revenge has `CB4TrackDataStruct` (`research/R_jul14/symtab.csv`: `Fixup__18CB4TrackDataStructUi`) confirming the CB3→CB4 pattern; no direct B2 hit, Area from class domain (track/race) |
| `src/b3/gamesource/Race/B3StreamedTrack.cpp` | placed + proven 2026-10-20, extended 2026-10-20 | `[L]` folder: no literal alienbrain path found yet; Area "Race" on semantic fit, same tier as `B3TrackDataStruct` above. `[L]` lineage: Revenge keeps the same class renamed `CB3StreamedTrack`→`CB4StreamedTrack` (`research/R_jul14/map_symbols.csv`: `CB4StreamedTrack::Construct(void)`). `[C]` content: `Construct()` (Target #14) matched retail instruction-for-instruction on the first compile. `Destruct()` (Target #19, N48) added later, sitting immediately adjacent in retail (only a 4-byte gap) — extended this same file rather than creating a new one, matching retail's own adjacency. |
| `src/b3/GameShared/GameClasses/Mpeg/ps2/GtVideoDecoderPS2_00325B90.cpp` | placed 2026-10-20 | `[L]` `Gt`-prefixed (shared engine, not game-specific); Revenge has `CGtVideoDecoder` (`research/R_jul14/symtab.csv`: `Construct__15CGtVideoDecoder`, `GetImage__15CGtVideoDecoder` etc.); `Mpeg`/`ps2` per K18's literal `GameShared\GameClasses\{...,Mpeg}\ps2\` citation |
| `src/b3/gamesource/Hud/B3Globe2dObject_003B54D0.cpp` | placed 2026-10-20 | `[L]` `CB3Globe2dObject::_Render(const CGt2dObject::CGt2dObjectSpace&, const void*)` subclasses the shared `CGt2dObject` interface (same virtual signature as `Gt2dObjectBox`/`Gt2dObjectImage`'s `_Render`); `CB3HUDSoundManager::FEGlobeSweep/Hilight/Select/Spin()` (`research/E_B3DEBUG_symbols.csv`) ties "Globe" directly to the frontend/HUD sound effects within B3's own retail symbol table — no Revenge counterpart found, but this evidence comes from B3 itself |

| `src/b3/gamesource/Graphics/TrackRenderer/Ps2/B3TrackRendererRuntimePS2.cpp` | placed + proven 2026-10-20, **realigned 2026-10-20** | `[C]` folder: literal alienbrain path `alienbrainWork\CG4\Game\Code\GameSource\Graphics\TrackRenderer\Ps2\B4TrackRendererRuntimePS2.cpp` (`research/R_jul14/symtab.csv`, N35) — supersedes the original "Render" semantic-fit guess (moved from `gamesource/Render/`, no content change). `[L]` lineage: Revenge (`research/R_jul14/map_symbols.csv`) keeps the same class renamed `CB3TrackRenderer`→`CB4TrackRenderer`. `[C]` content: `Destruct()` unchanged by the move — re-verified via `tools/wire_in_all.sh` after the rename, full-binary rom SHA-1 still `6679042a…`, confirming the path change was a pure no-op. |
| `src/b3/gamesource/World/B3AITarget.cpp` | placed + proven 2026-10-20 | `[C]` folder: literal alienbrain path `alienbrainWork\CG4\Game\Code\GameSource\World\B4AITarget.cpp` (`research/R_jul14/symtab.csv`, N35) — the strongest tier of folder evidence used in this repo so far, a real path string, not an inference. `[L]` lineage: B2's `CAITarget` shares 5 exact method names (`LaneIsUndesirable`, `UpdateCurrentSegment`, `ResetCornerStatus`, `GetCurrentFwdFrac`, `LanesAreSideBySide`-family — `research/B2_aug05/b2_names_for_match.csv`) confirming `CB3AITarget`↔`CAITarget`. `[C]` content: `Construct()` matched retail byte-for-byte on the first compile, verified via wire-in-and-relink (N33). First use of the new `World` Area (not in B2's original 8-area list — added on Revenge's literal evidence, see "Area folders defined so far" below). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_003193D0.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`/`CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(3)`); class/method names from the E-build maps (`B3HeadingComponent.cpp`); no literal path of its own. `[C]` content: `Release()`, Target #30 (N60). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_004D7E20.cpp` | placed + proven 2026-10-21 | `[C]` file: both constants are in the E map's `B3HeadingComponent.cpp` .rodata. `[C]` content: the static initializer, Target #63 (N107). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_00319490.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`/`CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(3)`); class/method names from the E-build maps (`B3HeadingComponent.cpp`); no literal path of its own. `[C]` content: `Update(float)` with inlined `SetHeadingString`, Target #34 (N71). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_00319A90.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`/`CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(3)`); class/method names from the E-build maps (`B3HeadingComponent.cpp`); no literal path of its own. `[C]` content: `Prepare(const unsigned short*, EHeadingType)`, Target #31 (N63). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_00319C80.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`/`CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(3)`); class/method names from the E-build maps (`B3HeadingComponent.cpp`); no literal path of its own. `[C]` content: `Prepare(EGlobalStrings, EHeadingType)`, Target #32 (N66). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_00319E80.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`/`CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(3)`); class/method names from the E-build maps (`B3HeadingComponent.cpp`); no literal path of its own. `[C]` content: `Prepare(EHeadingType)`, Target #33 (N67). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_0031A300.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`/`CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(3)`); class/method names from the E-build maps (`B3HeadingComponent.cpp`); no literal path of its own. `[C]` content: `CB3RotatingImage2dObject::_Render`, Target #38 (N84); the DNAT map lists that class in `B3HeadingComponent.cpp`. |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_0031A570.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`/`CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(3)`); class/method names from the E-build maps (`B3HeadingComponent.cpp`); no literal path of its own. `[C]` content: `GtMathPs2::CGtMatrix2x3` `operator=`/copy ctor, emitted out of line in this file (the DNAT map lists both under `B3HeadingComponent.cpp`), Target #37 (N78). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_0031A5D0.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`/`CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(3)`); class/method names from the E-build maps (`B3HeadingComponent.cpp`); no literal path of its own. `[C]` content: retail-only `func_0031A5D0`/`func_0031A840`, Target #35 (N74). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_0031A9C0.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`/`CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(3)`); class/method names from the E-build maps (`B3HeadingComponent.cpp`); no literal path of its own. `[C]` content: retail-only `func_0031A9C0`/`func_0031ABC0`, Target #36 (N75). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_0031B0F0.cpp` | placed + proven 2026-10-21 | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`/`CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(3)`); class/method names from the E-build maps (`B3HeadingComponent.cpp`); no literal path of its own. `[C]` content: `Construct()`, Target #29 (N59). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_0031B130.cpp` | placed, **draft, not wired in** | `[L]` folder: same Menu/DebugMenu/Components/ area as `CB3VListComponent`/`CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(3)`); class/method names from the E-build maps (`B3HeadingComponent.cpp`); no literal path of its own. `[C]` content: `CHeadingBar2dObject::_Render` (N81: 321/321 instructions, frame differs). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031B640.cpp` | placed + proven 2026-10-21 | `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); class/method names from the E-build maps (`B3HelpBarComponent.cpp`); no literal path of its own. `[C]` content: retail-only `func_0031B640`, Target #39 (N93). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031B6A0.cpp` | placed + proven 2026-10-21 | `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); class/method names from the E-build maps (`B3HelpBarComponent.cpp`); no literal path of its own. `[C]` content: `Release()`, Target #40 (N93). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031B770.cpp` | placed + proven 2026-10-21 | `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); class/method names from the E-build maps (`B3HelpBarComponent.cpp`); no literal path of its own. `[C]` content: `SetString`, Target #42 (N96). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031B860.cpp` | placed, **draft, not wired in** | `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); class/method names from the E-build maps (`B3HelpBarComponent.cpp`); no literal path of its own. `[C]` content: `Update(float)` (vtable slot 0), N95. |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031BD60.cpp` | placed, **draft, not wired in** | `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); class/method names from the E-build maps (`B3HelpBarComponent.cpp`); no literal path of its own. `[C]` content: retail-only `func_0031BD60` (N94). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031BF40.cpp` | placed, **draft, not wired in** | `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); class/method names from the E-build maps (`B3HelpBarComponent.cpp`); no literal path of its own. `[C]` content: retail-only `func_0031BF40` (N94). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031C210.cpp` | placed + proven 2026-10-21 | `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); class/method names from the E-build maps (`B3HelpBarComponent.cpp`); no literal path of its own. `[C]` content: `AwardPrepare` and the three `Prepare` overloads, Targets #43-#46 (N96). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031C5D0.cpp` | placed, **draft, not wired in** | `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); class/method names from the E-build maps (`B3HelpBarComponent.cpp`, which also holds `CB3ScrollingText2dObject`); no literal path of its own. `[C]` content: `CB3ScrollingText2dObject::_BuildBatchData` (N101). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031C990.cpp` | placed + proven 2026-10-21 | `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); class/method names from the E-build maps (`B3HelpBarComponent.cpp`, which also holds `CB3ScrollingText2dObject`); no literal path of its own. `[C]` content: `CB3ScrollingText2dObject::_Render`, Target #48 (N100). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031CB20.cpp` | placed + proven 2026-10-21 | `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); class/method names from the E-build maps (`B3HelpBarComponent.cpp`, which also holds `CB3ScrollingText2dObject`); no literal path of its own. `[C]` content: `CB3ScrollingText2dObject::Prepare`, Target #47 (N97). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031C590.cpp` | placed + proven 2026-10-21 | `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); class/method names from the E-build maps (`B3HelpBarComponent.cpp`); no literal path of its own. `[C]` content: `Construct()`, Target #41 (N93). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_004D7E70.cpp` | placed + proven 2026-10-21 | `[C]` same file as the other `B3HelpBarComponent_*` (`kHelpBarRecipSize` is in the E map's `B3HelpBarComponent.cpp` .rodata). `[C]` content: the file's static initializer, Target #49 (N102). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent_0031CDA0.cpp` | placed + proven 2026-10-21 | `[C]` class/file: E-build maps (`B3BackgroundComponent.cpp`, research/E_classified.csv) and retail's tables. `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(6)`); no literal path of its own. `[C]` content: `ReleaseObjects`, `Release`, Target #50 (N102). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent_0031D660.cpp` | placed, **draft, not wired in** | `[C]` as `B3BackgroundComponent_0031CDA0.cpp`. `PrepareBorders`, 175/175, 19 changed (N115). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent_0031D920.cpp` | placed + proven 2026-10-21 | `[C]` class: all three callers pass the `CB3BackgroundComponent` instance; `[L]` file: inside the E map's `B3BackgroundComponent.cpp` range. `[C]` content: retail-only `func_0031D920`, Target #51 (N102). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent_0031E0D0.cpp` | placed + proven 2026-10-21 | `[C]` as `B3BackgroundComponent_0031CDA0.cpp`. `[C]` content: `Construct`, Target #52 (N102). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent_004D7EC0.cpp` | placed + proven 2026-10-21 | `[C]` file: `kBackgroundBorderColourScale` and the `kB3DNASImage*` constants are in the E map's `B3BackgroundComponent.cpp` .rodata. `[C]` content: the static initializer with the file's .rodata and .bss, Target #62 (N106). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_0031E140.cpp` | placed + proven 2026-10-21 | `[C]` class/file: E-build maps (`B3PromptsComponent.cpp`, research/E_classified.csv) and retail's tables. `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(1)`); no literal path of its own. `[C]` content: `SetCurrentPrompts`, Target #53 (N102). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_0031E1A0.cpp` | placed, **draft, not wired in** | `[C]` as `B3PromptsComponent_0031E140.cpp`. `Release`, 83/85 (N103). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_0031FD30.cpp` | placed + proven 2026-10-21 | `[C]` as `B3PromptsComponent_0031E140.cpp`. `[C]` content: `Construct`, Target #54 (N102). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_0031FDB0.cpp` | placed + proven 2026-10-21 | `[C]` class/file: E-build maps (`B3VSelectComponent.cpp`, research/E_classified.csv) and retail's tables. `[L]` folder: as `CB3HSelectComponent` (`Construct()` calls `CB3MenuComponentBase::Construct(4)`); no literal path of its own. `[C]` content: `ForceLead`, `SetItemEnabled`, Target #55 (N102). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_003214B0.cpp` | placed + proven 2026-10-21 | `[C]` as `B3VSelectComponent_0031FDB0.cpp`. `[C]` content: `Construct`, Target #56 (N102). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_0031FE70.cpp` | placed + proven 2026-10-21 | `[C]` as `B3VSelectComponent_0031FDB0.cpp`. `[C]` content: `Release`, Target #57 (N104). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_00320E20.cpp` | placed + proven 2026-10-21 | `[C]` as `B3VSelectComponent_0031FDB0.cpp` (inside its address range; uses its fields). Retail-only `func_00320E20`, Target #67 (N110). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_00320EB0.cpp` | placed + proven 2026-10-21 | `[C]` as `B3VSelectComponent_0031FDB0.cpp`. `func_00320EB0` ([L] PrepareItem), Target #73 (N116). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_00321430.cpp` | placed + proven 2026-10-21 | `[C]` as `B3VSelectComponent_0031FDB0.cpp`. `[C]` content: the two `Prepare` wrappers, Target #58 (N104; symbols mapped onto the E-signature labels). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_004D81A0.cpp` | placed + proven 2026-10-21 | `[L]` file: the E map's `B3VSelectComponent.cpp` .rodata has two constants of these sizes in this order. `[C]` content: the static initializer, Target #64 (N107). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_0031F5E0.cpp` | placed + proven 2026-10-21 | `[C]` file: inside the E map's `B3PromptsComponent.cpp` range. `[C]` content: retail-only `func_0031F5E0`, Target #59 (N104). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_0031F760.cpp` | placed + proven 2026-10-21 | `[C]` as `B3PromptsComponent_0031F5E0.cpp`. `[C]` content: retail-only `func_0031F760`, Target #61 (N106). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_0031F970.cpp` | placed, **draft, not wired in** | `[C]` as `B3PromptsComponent_0031F5E0.cpp`. `func_0031F970`, 100/103 (N105). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_0031FB10.cpp` | placed, **draft, not wired in** | `[C]` as `B3PromptsComponent_0031F5E0.cpp`. `func_0031FB10`, 134/136 (N105). |
| `src/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_004D8100.cpp` | placed + proven 2026-10-21 | `[C]` file: the E map's `B3PromptsComponent.cpp` has an `__sinit` and these kinds of constants. `[C]` content: the static initializer and the file's .rodata block, Target #60 (N104). |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3LoadingScreenPage_00321500.cpp` | placed + proven 2026-10-21 | As `B3LoadingScreenPage_00321680.cpp` (inside its address range; called by its Update with `this`). `func_00321500`, Target #72 (N113). |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3LoadingScreenPage_00321680.cpp` | placed + proven 2026-10-21 | `[C]` class/file: E map `B3LoadingScreenPage.cpp`, retail vtable. `[L]` folder: Revenge's `GameSource\Menu\DebugMenu\Pages\` holds the page base (`B4DebugMenuPageBase.cpp` = our `CB3MenuPageBase`) and the `B4Debug*Page.cpp` pages (N111). `Release`, Target #68. |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3MyBurnoutPage_00322310.cpp` | placed + proven 2026-10-21 | `[C]` class/file: E map `B3MyBurnoutPage.cpp`, retail vtable. `[L]` folder: as above. `Release`, Target #69. |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3MyBurnoutPage_00322610.cpp` | placed + proven 2026-10-21 | As above. `Construct`, Target #70. |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3MenuPageBase_00318530.cpp` | placed + proven 2026-10-21 | `[C]` class/file: E map `B3MenuPageBase.cpp`, retail tables (high). `[L]` folder: N111. `Prepare(bool)`, Target #71 (N112). |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3LoadingScreenPage_00321690.cpp` | placed, **draft, not wired in** | As `B3LoadingScreenPage_00321680.cpp`. `Update`, 57/58 (N112b). |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3MyBurnoutPage_00322320.cpp` | placed, **draft, not wired in** | As `B3MyBurnoutPage_00322310.cpp`. `Update`, 74/73 (N112b). |

## Area folders defined so far (empty until evidence places a file in them)

```
src/b3/gamesource/{Menu,Race,Hud,Game,Sound,Physics,toolkits,World}/
src/b3/gamesource/Graphics/TrackRenderer/Ps2/
src/b3/GameShared/GameClasses/{FileSystem,MemoryCard,Mpeg}/ps2/
src/b3/GameShared/GameClasses/Graphical/2d/   [Ps2/ for the renderer, once something needs it]
```

`World` added 2026-10-20 (N33/N35): not in B2's original 8-area literal list, but confirmed by a real
Revenge alienbrain path string (`GameSource\World\B4AITarget.cpp`), the strongest evidence tier.
`Render` **removed** 2026-10-20: it held only `B3TrackRendererRuntimePS2.cpp`, which has since moved to
its literal-path-confirmed location under `Graphics/TrackRenderer/Ps2/` (see N35 and the row above);
nothing else was ever placed in `Render`, so the Area no longer exists in this tree.

## N35: Revenge's real literal `GameSource` subtree (found 2026-10-20)

`research/R_jul14/symtab.csv` encodes real alienbrain source paths inside mangled static-initializer
symbol names (underscores standing in for path separators). A single grep pass already recovered 40+
of them under `Code\GameSource\`, including areas never guessed from B2 alone: `Camera`, `Camera\
Behaviours`, `Camera\CameraUtils`, `Camera\Crash`, `Camera\States`, `Game`, `Game\Logic`, `Game\Ps2`,
`Graphics`, `Graphics\<Subsystem>\Ps2`, `World`. This is **literal-path-tier** evidence (same tier as
B2's K18, stronger than Revenge's own layout/name-matching tier used for K32/B14) and should be
preferred over semantic-fit guesses wherever a hit exists. **Realignment done 2026-10-20**:
`B3TrackRendererRuntimePS2.cpp` moved from the semantic-fit guess `gamesource/Render/` to its literal
path `gamesource/Graphics/TrackRenderer/Ps2/`; re-verified as a pure no-op via `tools/wire_in_all.sh`
(rom SHA-1 unchanged, `6679042a…`). Checked every other already-placed file's class/filename against
the ~40 paths extracted so far: one more direct hit, `Gt2dObjectImage.cpp` (confirms its existing
placement exactly, upgraded `[L]`→`[C]`, see its row above); no contradictions found for the rest
(`Gt2dObjectBox`, `Gt2dScene`, `Gt2dFont`, the B2-lineage `B3*Physics`/`B3SoundPlayerCar`/
`B3TrackDataStruct`/`B3Globe2dObject` files, `GtVideoDecoderPS2`) — simply no hit yet for them in the
paths pulled out so far, not a confirmation either way (see Next step #1).

## Next step for this doc

1. Extract the *rest* of `research/R_jul14/symtab.csv`'s `alienbrainWork_...GameSource_...` paths
   (N35) into a proper lookup table (`research/R_jul14/gamesource_paths.csv`?) instead of one-off
   greps, then cross-check every already-placed file against it — expect some Area renames.
2. Cross-check every `_unclassified` class against `research/B2_aug05/b2_to_retail.csv` (B2→retail
class-method pairing) and `research/R_jul14/symtab.csv` (Revenge names/layouts) before moving anything
out of `_unclassified/`. Update this table with the citation each time a file moves.
| `src/b3/_unclassified/B3AIAvoidance_00141880.cpp` | placed + proven 2026-10-21 (batch) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3AITarget_00149EB0.cpp` | placed + proven 2026-10-21 (batch) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/B3Burn_0014E390.cpp` | placed + proven 2026-10-21 (batch) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3Burn_0014E5F0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3RaceCar_00151770.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/B3RacePosition_00154750.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RacePosition.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3RacePosition_00154760.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RacePosition.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3RacePosition_00154AB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RacePosition.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3StartPoint_0015E8A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StartPoint.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3StartPoint_0015E8B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StartPoint.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3StartPoint_0015E8D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StartPoint.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3TrafficAxle_0015FAC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficAxle.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3HUDComponent_0019F770.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3HUDComponent.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3HUDComponent_0019F780.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3HUDComponent.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3HUDBoostBar_001A8490.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3HUDBoostBar.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3CrashActionDirector_001B20C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashActionDirector.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3RaceCarPhysics_001C0E70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RaceCarPhysics.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtTimer_001D3A50.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtTimer.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/GtViewport_00211CB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtViewport.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock_002172B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtInputDevicePS2DualShock.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock_002173E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtInputDevicePS2DualShock.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/B3MenuInput_0021A9A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3MenuInput.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtCameraBehaviour_0021AFF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtCameraBehaviour.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtCamera_0021B4D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtCamera.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3VehicleRendererRuntimePS2_00220B30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3VehicleRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtScreenCentre_00221080.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtScreenCentre.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/GtScreenCentre_00221090.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtScreenCentre.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/GtTextureCachePS2_00221570.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtTextureCachePS2.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/GtNetworkPlayerManager_00236780.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtNetworkPlayerManager.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/GtNetworkPlayerManager_00236790.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtNetworkPlayerManager.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/B3ParticleRendererPS2_00254A70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ParticleRendererPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3ParticleRendererPS2_00254A80.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ParticleRendererPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3ParticleRendererPS2_00254D40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ParticleRendererPS2.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3ParticleRendererPS2_00254F10.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ParticleRendererPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3ParticleRendererPS2_00255230.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ParticleRendererPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SparkRendererPS2_00263C00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SparkRendererPS2_00263F70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3SparkRendererPS2_00264030.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BloomPS2_00265C30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3BloomPS2.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/B3AIDebug_00275EA0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AIDebug.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3AIDebug_00275EB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AIDebug.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3AIDebug_00275EC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AIDebug.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3AIDebug_00275ED0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AIDebug.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/B3AIDebug_00275EE0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AIDebug.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SoundTrafficPass_00278800.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficPass.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SoundTrafficVehicle_00278810.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficVehicle.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/B3SoundTrafficVehicle_00279550.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficVehicle.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/B3SoundCrashManager_0027B760.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3SoundHUDManager_002870C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundHUDManager.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3SoundManager_0028ADC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundManager.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/B3SoundTurboModel_0028FAD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTurboModel.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SoundTurboModel_0028FF20.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTurboModel.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3SoundCrashedTraffic_00290440.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundCrashedTraffic.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3PropManager_002B72F0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PropManager.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3PropManager_002B7870.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PropManager.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3EnvironmentManager_002BC450.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3EnvironmentManager.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3TrailSystem_002BD7E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrailSystem.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3TrailSystem_002BD990.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrailSystem.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3PhysicsManagerDebug_002BECE0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PhysicsManagerDebug.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3PhysicsManagerDebug_002BECF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PhysicsManagerDebug.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SoundRaceCarManager_002ED3C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundRaceCarManager.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SoundRaceCarManager_002ED3D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundRaceCarManager.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SoundRaceCarManager_002ED680.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundRaceCarManager.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/B3TrafficDebug_002F0360.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficDebug.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3TrafficDebug_002F0370.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficDebug.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3DebrisRendererPS2_002F4620.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DebrisRendererPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3DebrisRendererPS2_002F4930.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DebrisRendererPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3DebrisRendererPS2_002F4990.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DebrisRendererPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SoundDoppler_002F4B70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundDoppler.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3SoundDoppler_002F4B80.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundDoppler.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3SoundDoppler_002F4B90.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundDoppler.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3SoundDoppler_002F4F80.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundDoppler.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SoundESMManager_002FAF30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundESMManager.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SoundESMManager_002FAF40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundESMManager.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/B3SoundESMStruct_002FB220.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundESMStruct.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3SoundDSPBlock_002FC150.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundDSPBlock.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3BehaviourTrackSide_00300BD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3BehaviourTrackSide.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3CoronaRendererPS2_00307620.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CoronaRendererPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A8D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/B3BoostEffectParams_0030B100.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3BoostEffectParams.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtVideoDecoderPS2_00324F30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtVideoDecoderPS2.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3OnlineJoinGamePage_00327540.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineJoinGamePage.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3OnlineSelectPersonaPage_00340450.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineSelectPersonaPage.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3OnlineSelectLoginPage_00347890.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineSelectLoginPage.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3CrashAnalyser_00353980.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashAnalyser.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3CrashAnalyser_00353A20.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashAnalyser.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3CrashCameraDirector_00354F60.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashCameraDirector.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3DebugMipMaps_0035EF80.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DebugMipMaps.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3DebugMipMaps_0035EF90.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DebugMipMaps.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3PopcornRendererPS2_00366040.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PopcornRendererPS2.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3ScoreBonus_00368330.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3ScoreBonus_003684B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3FlashText2dObject_003720E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3FlashText2dObject.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3CameraEditor_00374520.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3TextureCollectionPS2_00378FF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TextureCollectionPS2.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/GtSoundBank_00383EB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundBank.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/GtSoundBank_00383ED0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundBank.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/GtSoundBank_00383EE0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundBank.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/GtSoundBank_00383EF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundBank.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtSoundBankManager_00384320.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundBankManager.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtSoundListener_00384920.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundListener.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/GtSoundListener_00384970.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundListener.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtSoundListenerManager_00384A50.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundListenerManager.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/GtSoundRealVoice_00385250.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundRealVoice.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtSoundVoiceManager_00389070.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundVoiceManager.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtSoundWave_003895C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundWave.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3CrashRamp_003A1CF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashRamp.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3CrashRamp_003A1D00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashRamp.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3CrashRamp_003A20D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashRamp.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3SoundStaticPassManager_0041D3D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundStaticPassManager.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3SoundCustomSoundTrackPS2_0042B4D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundCustomSoundTrackPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3CameraEditor_00446FD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/func_00130970.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00134260.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00134290.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_001342A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_001342E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00134370.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00134380.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00134390.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_001343A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_001343D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_001343F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00134400.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00134410.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00134420.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00134430.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00134440.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00134450.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00134460.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00134470.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00134480.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00134490.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/B3Game_001344B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3Game.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/B3Game_001344C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3Game.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/func_00134570.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_001345A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_001345B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_001345C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/B3GameMode_001345D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3GameMode.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/B3GameMode_001345E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3GameMode.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/func_001345F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00134DD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00134DE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00135170.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00135B40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_0013B570.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0013B660.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0013C870.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0013C880.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0013C890.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00151A20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/B3HUDComponent_0019F4A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3HUDComponent.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/func_001AA660.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_001AA670.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/B3PlayerCarPhysics_001BD630.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3PlayerCarPhysics.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/B3RaceCarPhysics_001BEA60.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3RaceCarPhysics.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D2F80.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D2F90.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D3820.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/func_001D4E60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_001D4E70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/GtCamera_0021B000.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtCamera.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/GtCamera_0021B4C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtCamera.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/func_0021B760.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0021B820.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0022D2D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0022D320.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0022F960.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0022FBB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_002303B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00230560.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00231B20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00234C30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_002351C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/GtNetworkPlayerManager_002351D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtNetworkPlayerManager.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/func_002351E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_0023AFD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00251490.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_002514A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_002514B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0026C790.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_00271910.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00271A10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00271A50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00272B90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00272BB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/B3SoundManagerPS2_00276980.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3SoundManagerPS2.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/func_00276A10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_0027A8F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00283B20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00285190.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00288F50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00289AF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/B3SoundSkidModel_0028E200.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3SoundSkidModel.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/func_002B6C30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_002B7280.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_002C20C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_002C20D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_002C21B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/GtLogitechHeadset_002C2260.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLogitechHeadset.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/GtLogitechHeadset_002C26C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLogitechHeadset.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/GtLogitechHeadset_002C2830.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLogitechHeadset.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourOffset_002E2720.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourOffset.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourRaceCarFollow_002E3430.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourRaceCarFollow.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourRotate_002E5E20.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourRotate.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourRotate_002E5E30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourRotate.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourFlyAround_002E90B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourFlyAround.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourFlyAround_002E90D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourFlyAround.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourFlyAround_002E90E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourFlyAround.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/func_002F9CF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/B3BehaviourTrackSide_002FD290.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourTrackSide.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourTrackSide_002FD2A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourTrackSide.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourTrackSide_002FD2B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourTrackSide.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourTrackSide_00300BC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourTrackSide.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/func_00300BE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0030A8C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0030E310.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0030E320.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0030E330.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0030ED40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/B3MenuFlowFSM_0030ED50.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3MenuFlowFSM.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/B3ClassSelectPage_003180F0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3ClassSelectPage.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/func_00318520.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/B3OnlineMenuPage_00323730.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OnlineMenuPage.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/func_00324EB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00324EE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/B3OnlineGameCreatePage_00326FB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OnlineGameCreatePage.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourEffect_0032D1E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourEffect.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourEffect_0032D1F0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourEffect.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/func_00330360.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00335FC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_00336780.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337AA0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337AB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337AC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. get template. |
| `src/b3/_unclassified/func_00338E10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033BDF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033C810.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3OnlineSelNetConfigPage_003464A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OnlineSelNetConfigPage.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3OnlineConnectingPage_00346DE0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OnlineConnectingPage.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3ErrorPage_00352030.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3ErrorPage.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3DNASPage_003530E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3DNASPage.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourCluster_00357B70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourCluster.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourCluster_00357B80.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourCluster.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/func_0035F230.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0035F660.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00360360.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/B3CrashCombo_003642B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3CrashCombo_003642F0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3PopcornRendererPS2_00366150.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3PopcornRendererPS2.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/func_003663F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00366560.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/B3ScoreBonus_00369440.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3ScoreBonus_003694B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/func_0036F3D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00371130.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/B3OnlineBuddiesSearchMenuPage_003730A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OnlineBuddiesSearchMenuPage.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourInterpolate_003739A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourInterpolate.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3BehaviourInterpolate_003739B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourInterpolate.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3CameraEditor_003744F0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3CameraEditor_00374500.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. empty template. |
| `src/b3/_unclassified/B3CameraEditor_00374510.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/func_00374900.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00374910.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00375260.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003752E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003752F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00375D80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00375E80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00376330.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003767B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003767C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003778C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00379000.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0037A910.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0037C510.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0037E5F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00381020.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00382FB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00383EC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00383F00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00384EB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_00385EA0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/GtSoundStream_00386350.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundStream.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/func_003872C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/B3OfflineSingleRaceLogic_003897B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OfflineSingleRaceLogic.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/func_003897C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003897D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003897F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00389800.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00389810.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00389820.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003899D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00389A30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00389C20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/B3OfflineSingleRaceLogic_00389C30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OfflineSingleRaceLogic.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/func_00389C40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0038A440.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038A450.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038A460.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038A490.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038A530.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038A540.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038A550.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038A560.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0038AF80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038AF90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038AFA0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038AFB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038AFC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038AFE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038B220.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038B230.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038B240.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0038B260.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0038B370.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0038BB10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038BB20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038BB30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038BB40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038BB50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038BB60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/B3OfflineRoadRageLogic_0038BFD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OfflineRoadRageLogic.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/func_0038BFE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038BFF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038C000.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038C010.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/B3OfflineRoadRageLogic_0038C020.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OfflineRoadRageLogic.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/func_0038C030.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038C040.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038C050.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D490.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D4A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D4B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D4C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D4D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0038D4E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0038D500.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D510.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D520.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D530.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D860.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D900.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D910.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D920.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D930.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038D940.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0038E170.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E180.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E190.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E1A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E1B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0038E1D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E1E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E1F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E200.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E470.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E510.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E520.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E530.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E540.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038E550.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0038EB50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038EB60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038EB70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038EB80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038EB90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038ED40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038ED50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038ED60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038ED70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038ED80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0038ED90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_003904D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_003904E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_00390680.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00390690.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00391F00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00391F90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003923A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003923B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003923C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003923D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003923E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_003923F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_00392410.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_00392420.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00392430.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00392720.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00392940.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00392950.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00392960.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00392970.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_00393350.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00393450.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00393460.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00393480.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003934A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003934B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003934C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_003936F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00393700.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00393920.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00394270.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00395300.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00395560.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00395570.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003959E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00396090.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00398670.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00398840.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0039AD40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0039AD70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0039AD80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0039F080.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003A0FE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003A2820.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003A5C60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_003A7000.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_003B61F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003BA570.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003BA690.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003BA860.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003BA870.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003BA880.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003BA890.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003BA8A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003BAF80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003BB0F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003BE630.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003BE670.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003BE680.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003BE880.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003C0880.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003C2E40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003C3030.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003C3040.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003C30C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003C30D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003C35C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003C45E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003C5300.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003C5ED0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003C6040.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003C96E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003CA6A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003CBB50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003CCC50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003CD5E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003CD5F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003CD600.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003CD810.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003CDB10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003CDB20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003CDB30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003CDB40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003CDB50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003CDB60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003CDB70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003D14F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003D27C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003D2E90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003D30C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003D30D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003D8910.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003E8B70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_003E8C00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003EA7D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_003ED8A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003ED9E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003EDE60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003EF9B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003EFE60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003F03C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003F0EC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003F1160.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003F1FB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003F2330.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_003F2340.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003F38B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003F3AF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003F40D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003F6010.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003F6090.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_003FA5F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_003FBA00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_003FDE00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0041D090.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00422E30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00423F20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00424470.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00424C30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00425320.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00426070.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00427070.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_0042B010.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_0042B4E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B4F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B500.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B510.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0042B520.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B530.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B540.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0042B550.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0042B560.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B570.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B580.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B590.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B5A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B5B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B5C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0042B5D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_0042B5E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_0042BC70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_0042BC80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_00432550.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00433710.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_004343E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00436C80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_004381A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00438830.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00438C40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00438F00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00439CF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0043AEF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0043C350.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0043C460.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0043E310.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0043F450.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0043F670.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_004406D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00440E10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_004413B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00445300.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00445700.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00445CD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00445CE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00445CF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00445D00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_004474E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00447630.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0044A1D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00453C70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00453CE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00453E90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00454BE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00455160.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00456770.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00456D20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00457120.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00458AD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00459760.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0045B910.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0045BDC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0045CA40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00462140.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00462150.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_004621F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_004661B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00469BE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/B3WrongWayWall_0019B750.cpp` | placed + proven 2026-10-22 (batch, hand-written) | `[C]` name: retail tables (high); file `B3WrongWayWall.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3WrongWayWall_0019B760.cpp` | placed + proven 2026-10-22 (batch, hand-written) | `[C]` name: retail tables (high); file `B3WrongWayWall.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3WrongWayWall_0019D4B0.cpp` | placed + proven 2026-10-22 (batch, hand-written) | `[C]` name: retail tables (high); file `B3WrongWayWall.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIAggressionBehaviour_0032F350.cpp` | placed + proven 2026-10-22 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAggressionBehaviour.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0012EF40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3ControllerMappingPS2_0012FFA0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ControllerMappingPS2.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/func_0013B730.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. addr template. |
| `src/b3/_unclassified/B3GameData_0014EBC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3GameData.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_0014EC10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_00150100.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00150110.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3RaceCar_001519E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_00157400.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3SplitTimeCheckpoint_0015E630.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SplitTimeCheckpoint.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3SplitTimeCheckpoint_0015E640.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SplitTimeCheckpoint.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3SplitTimeCheckpoint_0015E710.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SplitTimeCheckpoint.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3StartFinishLine_0015E780.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StartFinishLine.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3StartFinishLine_0015E890.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StartFinishLine.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3StartPoint_0015E8C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StartPoint.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3TrafficLane_00160570.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficLane.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_00162BE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_001631E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3World_0019B6B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3World.cpp` (retail_names.csv). Area not evidenced. this template. |
| `src/b3/_unclassified/func_001A0010.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. this template. |
| `src/b3/_unclassified/B3NetworkMessage_001A8540.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkMessage.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/func_001A8610.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_001A9D60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_001AF410.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. this template. |
| `src/b3/_unclassified/B3PhysicsManager_001B8EF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3PropPhysics_001BE210.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PropPhysics.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D3270.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_001D4010.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_001D4EB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. addr template. |
| `src/b3/_unclassified/GtInputManagerPS2Pad2_00214B60.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtInputManagerPS2Pad2.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/B3VehicleRendererRuntimePS2_00220B40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3VehicleRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_0022EB20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/GtPS2LibNet_0022F000.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtPS2LibNet.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_0023B690.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. addr template. |
| `src/b3/_unclassified/func_0023B8B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0023F4B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_00240A60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0024D4C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. this template. |
| `src/b3/_unclassified/B3TrafficPhysics_00250300.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficPhysics.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/func_00264910.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. this template. |
| `src/b3/_unclassified/B3NetworkCarPhysics_00268950.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkCarPhysics.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3NetworkCarPhysics_00268960.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3NetworkCarPhysics.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3TrackMaterialPS2_0026A160.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrackMaterialPS2.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/func_0026BD20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. this template. |
| `src/b3/_unclassified/B3NetworkRaceReadyMessage_0026BD30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkRaceReadyMessage.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/func_0026BD40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0026BE80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00271A00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00272D50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00276A20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/B3SoundCrashManager_0027BEF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_00283DA0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_00288F60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_0028AEB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3SoundRaceCar_0028D7B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundRaceCar.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3SoundCrashedTraffic_00290430.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundCrashedTraffic.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_002B7070.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_002B7100.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_002BEDB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3BehaviourOffset_002E2700.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourOffset.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3BehaviourRaceCarFollow_002E3410.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourRaceCarFollow.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/func_002E5E10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E6F40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E6F50.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/func_002E90C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/B3TrafficDebug_002F0380.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficDebug.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_002F9920.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_002F99D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/GtLinearMalloc_002F9EA0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtLinearMalloc.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/B3BoostEffectParams_0030B530.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3BoostEffectParams.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/B3MenuFlowFSM_0030ED70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3MenuFlowFSM.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/func_0030ED80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00324EC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_00324ED0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_0032ED30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3StaticTrack_00333110.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StaticTrack.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/B3StaticTrack_00333120.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StaticTrack.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/B3BodyPartPhysics_00333FC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3BodyPartPhysics.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/func_003350E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00336790.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/GtLobbyDirtySock_003367A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/func_003379C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337B00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. addr template. |
| `src/b3/_unclassified/func_00338950.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00338E80.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_00341CF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0034BEA0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00351A80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. this template. |
| `src/b3/_unclassified/B3CrashCameraDirector_00357520.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3CrashCameraDirector.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/B3BehaviourCluster_00358840.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourCluster.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/GtSphereTree_0035C3D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. this template. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_003615E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3CrashCombo_00363B00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/B3ScoreBonus_003684A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3BehaviourInterpolate_003736C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourInterpolate.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3CameraEditor_00374530.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_00375270.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_003754B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_003755D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3PageTextComponent_00379980.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PageTextComponent.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/func_00383C00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. addr template. |
| `src/b3/_unclassified/func_00389EC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00389ED0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038A430.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038A470.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_0038A480.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_0038A5A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038AB30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038B250.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038B590.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038B5A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038C820.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038D7B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038D7C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_0038D9A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038E160.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038E3E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038E460.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_0038E5A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038EB40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038F710.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0038FF60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00391490.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00391DB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00392650.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00392730.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_003929C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00393470.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00393490.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00393930.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_003A0FF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/B3CrashPickup_003A17E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashPickup.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_003B6200.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_003BA670.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. this template. |
| `src/b3/_unclassified/func_003BA680.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. this template. |
| `src/b3/_unclassified/func_003BAF90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_003BB150.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_003BB160.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_003BB170.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_003BB180.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_003BB190.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_003C2390.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. this template. |
| `src/b3/_unclassified/func_003C2E50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3StreamManager_003C3560.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StreamManager.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/B3HUDScoreList_003CB080.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3HUDScoreList.cpp` (retail_names.csv). Area not evidenced. tail template. |
| `src/b3/_unclassified/B3HUDScoreList_003CB400.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3HUDScoreList.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/func_003CBCF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_003CC2C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_003D5CD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_003D8BB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3HUDEscapeDistance_003D8D40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3HUDEscapeDistance.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/func_003E8750.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/B3MemoryManager_003E8BA0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3MemoryManager.cpp` (retail_names.csv). Area not evidenced. setk template. |
| `src/b3/_unclassified/func_003FAA40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/B3SoundStaticPassManager_0041D8D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundStaticPassManager.cpp` (retail_names.csv). Area not evidenced. stores template. |
| `src/b3/_unclassified/func_0041E8A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0041E8B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0041E8C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0041E8D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0041E8E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0041E8F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0041E900.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0041E9E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0041F0B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00421E40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. addr template. |
| `src/b3/_unclassified/func_00431F70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_00433230.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_004343C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_00437050.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_0043CCD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0043DE50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_0043E120.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_004406C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_00441D60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00443830.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_00445CC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_004566D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00461F30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00466E70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00467010.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_00468C90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. this template. |
| `src/b3/_unclassified/func_00469300.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. this template. |
| `src/b3/_unclassified/func_00134580.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3Profile_00136480.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Profile.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3Profile_00136490.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Profile.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3Profile_001364A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Profile.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0013A560.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A5B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A600.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A620.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A630.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A650.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A7D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A7F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A800.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A880.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A890.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013ACF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013AD00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013AD10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3AICar_00143AD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AICar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3AIDriver_001459E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AIDriver.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3GameData_0014EBD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3GameData.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00150240.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00150890.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3RaceCar_001519F0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00155340.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3Score_0015AFC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3StartFinishLine_0015E790.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StartFinishLine.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001631B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficVehicle_00186810.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficVehicle.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficVehicle_001996D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficVehicle.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficVehicle_00199710.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficVehicle.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3AIArbitrator_0019D6A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AIArbitrator.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0019F200.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3HUDScore_001A2260.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3HUDScore.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001A87D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001A87E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001BAD00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3PropPhysics_001BE220.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3PropPhysics.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D3830.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtViewport_00211D50.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtViewport.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtViewport_00211D60.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtViewport.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00213E10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00217060.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0021B4E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002222D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002222E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00222C90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022D2B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022D2E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022D3A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022D3B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022D3F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022D850.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022DA50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022E6B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022F8A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022F8B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtNetworkPlayerManager_002367A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtNetworkPlayerManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00240EC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficPhysics_00251460.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3TrafficPhysics.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3Viewport_00251840.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Viewport.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3BloomPS2_00265C40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3BloomPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3NetworkCarPhysics_00269CF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkCarPhysics.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficLightStruct_00269E80.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficLightStruct.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficValveStruct_00269EC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficValveStruct.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficValveStruct_00269EF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficValveStruct.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0026C8B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00271A60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundTrafficManager_00276C10.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundTrafficVehicle_00278820.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficVehicle.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundESM_00287940.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundESM.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundESM_00288440.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundESM.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundGameModeManager_00289A30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundGameModeManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundGameModeManager_00289B00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundGameModeManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundListener_0028AC50.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundListener.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundManager_0028AE30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundCrashedTraffic_00290AD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundCrashedTraffic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ConvexHull_002B9640.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ConvexHull.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ConvexHull_002B9670.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ConvexHull.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ConvexHull_002B96A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ConvexHull.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtNetworkHeadset_002C0370.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtNetworkHeadset.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtNetworkHeadset_002C0380.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtNetworkHeadset.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_002C1C40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002C2040.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002F03A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3DebrisRendererPS2_002F4600.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DebrisRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3DebrisRendererPS2_002F4630.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DebrisRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ShadowRendererPS2_00303EB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ShadowRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtVideoDecoderPS2_00324F10.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtVideoDecoderPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3OnlineJoinGamePage_00327F00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OnlineJoinGamePage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3MessageBoxComponent_0032D1B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3MessageBoxComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0032ED50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficHullStruct_0032EDD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficHullStruct.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ChatDisplayComponent_00332960.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ChatDisplayComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3BodyPartPhysics_00333140.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BodyPartPhysics.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3BodyPartPhysics_00333FD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3BodyPartPhysics.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00335F40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337860.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_003380D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00338C10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00338DF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0033ACD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0033F3E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0033F400.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TableComponent_00340420.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TableComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3OnlineSelectPersonaPage_003406B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OnlineSelectPersonaPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003494C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00349DF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034D8A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00351A50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00352000.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TableSelectComponent_00352490.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TableSelectComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00353960.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3CrashTrafficGenerationStruct_0035EF20.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashTrafficGenerationStruct.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00360290.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_00361590.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_003615A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3BuddyDisplayComponent_00366400.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3BuddyDisplayComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3BuddyDisplayComponent_00367E40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3BuddyDisplayComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00369080.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00369200.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0036C760.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0036FF00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3BuddyReadMailComponent_00372AF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3BuddyReadMailComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3OnlineBuddiesSearchMenuPage_00373260.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OnlineBuddiesSearchMenuPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3CameraBehaviour_00374290.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CameraBehaviour.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtByteStream_00374440.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtByteStream.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtByteStream_00374450.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtByteStream.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtByteStream_003744B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtByteStream.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0037C810.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0037D1C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0037ED80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundManager_00384F40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundRealVoice_00385240.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundRealVoice.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00385EB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00385FD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00386010.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00386C90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundVirtualVoice_003872D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundVirtualVoice_003872E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundVoiceManager_00388EA0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundVoiceManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundVoiceManager_00388EE0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundVoiceManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003897E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00389A40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00389A50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038A570.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038A5B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038AB10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038AF40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038AFD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038B270.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038B280.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038B2E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038BAE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038C060.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038D480.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038D4F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038D540.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038D6D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038E1C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038E210.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038E350.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038E560.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038ED30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038F6E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038F720.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00391B20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00391B40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00391DC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00391FA0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00392030.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00392400.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00392440.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00392580.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineTurnBasedCrashLogic_00392740.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineTurnBasedCrashLogic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00392980.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00393320.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003933D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00393440.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00393710.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3StageLogic_00395920.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3StageLogic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003959F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00398680.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0039C150.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003A6C80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003B88E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3MenuStringBuffer_003B8900.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3MenuStringBuffer.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3EventFinishedComponent_003B8E80.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3EventFinishedComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003BAFA0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BB0D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BB1A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BE5A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C2940.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C5B40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003D0B60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E0FC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E8DD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E8DE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E96E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E9C90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EA7B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EA7C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EAB70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EB000.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003ED450.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EDAC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EEAF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F0860.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5DC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5DE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5E00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5E20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5E90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5EB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5ED0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5EF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5F10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5F30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5F50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5F70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5F90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5FB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5FD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5FF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3RewardImageComponent_003F6590.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RewardImageComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003F86F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F8870.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003FC040.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0041E910.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0041EAB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00420500.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00420B40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00420FC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00420FD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042E5C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042FCB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00431140.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00434540.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00436B00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00438F10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0043E130.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00445CA0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3CameraEditor_00446F90.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3CameraEditor_00446FA0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3CameraEditor_00446FB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3CameraEditor_00446FC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3CameraEditor_00446FE0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_004474A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00449F90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00458960.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0045A040.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00460180.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00465FB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00465FF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00466030.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00466070.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00466150.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00466180.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004669E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00469400.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00469540.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00469760.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00469770.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004697C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00469950.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00135AF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001507D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3PlayerCar_00150BE0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PlayerCar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3PlayerCar_00150CB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PlayerCar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3RaceCar_00153160.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3Score_0015CAC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0019EB10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001A9D70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock_00216FF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtInputDevicePS2DualShock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00237030.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0023B870.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0023F7F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0023F860.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00240960.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00240DD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00240E90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficPhysics_002502D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficPhysics.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3NetworkCarPhysics_00269CB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3NetworkCarPhysics.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundTrafficPass_00277F40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficPass.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundTrafficPass_00277FB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficPass.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundTrafficPass_00278750.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficPass.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundTrafficVehicle_00279560.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficVehicle.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundTrafficVehicle_0027A550.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficVehicle.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundScrape_00283560.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundScrape.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00284260.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundAICar_0028BAC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundAICar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundAICar_0028BB30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundAICar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_002B7030.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002B70C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtPolygonSoup_002BF7B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtPolygonSoup.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtPolygonSoup_002BF7D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtPolygonSoup.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_002C1C10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002C2070.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundRaceCarManager_002EEFC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundRaceCarManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_002F9970.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundESMManager_002FAE70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundESMManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3BehaviourEffect_0032ED90.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3BehaviourEffect.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0012EF20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A5C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A7E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A820.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013AD30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013AD70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013ADD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013ADF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013AE20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013AE40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013AEB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013B010.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013B050.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013B1B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013B1D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013B520.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013B6A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3AIAvoidance_00141980.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001419B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002366D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0028DFB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002C02D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtNetworkHeadset_002C02E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtNetworkHeadset.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSphereTree_0035EDA0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0038B020.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003952F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00443820.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00199750.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0023AFE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3HardCodedRaceStageList_003EA070.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3HardCodedRaceStageList.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3CrashActionDirector_001AE480.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashActionDirector.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0022D160.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00382BE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003A70B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3HardCodedCrashStageList_003E9520.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3HardCodedCrashStageList.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0014E860.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3GameData_0014E8A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3GameData.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022D180.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00384A30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038F510.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E8B80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042EE00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A7B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0030A970.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0030B110.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3ScoreBonus_00368340.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003CAA20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003D47B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003D4FC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003FB890.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00455B00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001AE630.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3CrashActionDirector_001AE660.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashActionDirector.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0022D3C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtByteStream_003744C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtByteStream.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0042C240.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001B9820.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00240D10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficDebug_002F0330.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficDebug.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00308FE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00309010.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00309040.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00309070.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00341D00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00391DD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F33D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F8C00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003FBBB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002171D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3InputManager_0022D070.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00369210.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00369240.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00385FE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00389A80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038B2B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00392000.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003A6FD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003FBA10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042C270.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00469790.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001BB6B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00228040.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficValve_002662B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficValve.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3CrashCombo_003642C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003E9490.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0041D8E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00439DD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00462160.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00155360.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3Score_00156220.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00255E60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00255EA0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00364270.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineRoadRageRaceLogic_0038ECF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineRoadRageRaceLogic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003CC280.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00458970.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3AIDriver_00145E30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AIDriver.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3Burn_0014DEB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0023B6A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3NetworkHasHeadsetMessage_00341CB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkHasHeadsetMessage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003C28A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003CC4D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004662D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00469410.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001503D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001D3C10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtNetworkPlayerManager_002367B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtNetworkPlayerManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00236BC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3DataLists_002518E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3DataLists_00251E60.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00255C50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0026C9C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundRaceCar_0028DA00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundRaceCar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_002B6FF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002B7080.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002F9930.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038F530.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3StageLogic_00395930.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StageLogic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003BA8B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BC4C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EAFC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042C5C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004405D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00440610.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00440770.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004697D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00199DC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001D3C50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock2_00215620.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtInputDevicePS2DualShock2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSphereTree_0035D210.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003BC500.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BE890.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00464750.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00464790.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00466590.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0019E9E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3DataLists_00252000.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3EnvironmentManager_002BBF50.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3EnvironmentManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_002C1F70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineJoinGamePage_00327550.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineJoinGamePage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00383F10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3MemoryManager_003E8BB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3MemoryManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003EA530.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F4A80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5D10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00465910.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3AIArbitrator_0019DCB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AIArbitrator.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficLight_00266260.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficLight.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3OnlineSelectPersonaPage_00340460.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineSelectPersonaPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TitleScreenComponent_00343FB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TitleScreenComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00360240.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineBuddiesSearchMenuPage_003730B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineBuddiesSearchMenuPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0037C170.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0037C520.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038D950.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038D9B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038E5B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BB100.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3HUDPrimaryMessage_003D8230.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3HUDPrimaryMessage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003EB0A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F2920.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004343F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00439280.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004568B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0045FEF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0045FF40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00466100.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004665D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00466620.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022C2F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022F8C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022F910.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022FC10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00236C00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3DataLists_00251EA0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundAICar_0028BF40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundAICar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033C820.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00384F80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00391FB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3StreamManager_003C3570.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StreamManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003E9690.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004660B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022D920.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3DataLists_002519B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3DataLists_00251EF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0028CD10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSphereTree_0035D1C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003B8120.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F8890.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0045D060.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00464700.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A580.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ScoreBonus_00368E90.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003926C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00421000.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042F870.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3CrashActionDirector_001AE4A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashActionDirector.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00354F70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineRoadRageRaceLogic_0038F3E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineRoadRageRaceLogic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003BA580.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BC5B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003FBA40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003FBAA0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0043C360.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundDSPBlock_002FC160.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundDSPBlock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00369450.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3NetworkReplayMessage_003753F0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkReplayMessage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3NetworkReplayMessage_00375450.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkReplayMessage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00237090.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3CoronaRendererPS2_00307430.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CoronaRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00344F80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3Im3DPS2_00365450.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3PopcornRendererPS2_00365910.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3PopcornRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ScrapeRenderPS2_00376220.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ScrapeRenderPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SunRendererPS2_0024D4A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SunRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SunRendererPS2_0024D4B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SunRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003379B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3Im3DPS2_00365880.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001AB000.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001D3D20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SkyDomeRendererPS2_0021E0F0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SkyDomeRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SkyDomeRendererPS2_0021E3C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SkyDomeRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ReplaySystem_00155000.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ReplaySystem.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3Score_0015A7D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ParticleRendererPS2_00254A50.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ParticleRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00324EF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00360B10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00361050.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00361070.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00361220.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00361240.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00361420.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3ScoreBonus_003684F0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ScoreBonus_00368510.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3GamePS2_001D3FF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3GamePS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003753B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003753D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00361090.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003614A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtVideoDecoderPS2_00325BB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtVideoDecoderPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00420FE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SunRendererPS2_0024D360.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SunRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3DataLists_00251A00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337AD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_003391A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003615B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BB270.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0019EA30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0012FB10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001D3CE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003B5420.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BB1D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3NetworkHasHeadsetMessage_00341C70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkHasHeadsetMessage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundListener_00384930.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundListener.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundListener_003849F0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundListener.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3NetworkGameModeStatusMessage_003CC240.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkGameModeStatusMessage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0013A570.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00237050.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003607C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001D0CB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundAICar_0028B9D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundAICar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E7CD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033C620.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00360950.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00316E30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00360020.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00379990.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OfflineSingleRaceLogic_003899E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OfflineSingleRaceLogic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00396A40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003FDD60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003FDDB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00420B60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00440490.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundRealVoice_00385680.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundRealVoice.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundVirtualVoice_00387A40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E7430.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00386240.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003863C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtMalloc_003BB2A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtMalloc.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_004406E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002B7290.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E7050.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003B84F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_003611C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00442C90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003608F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3NetworkReplayMessage_003754C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkReplayMessage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003929D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C55D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C5630.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00436C20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtViewport_00211D70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtViewport.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtPS2LibNet_0022EC00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtPS2LibNet.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00338E20.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TableSelectComponent_00352430.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TableSelectComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundVoice_00388A90.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundVoice.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003C28E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0043BC30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A310.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00336150.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00393360.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00440650.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0012F6B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3Profile_0013A660.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3Profile.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ReplaySystem_00155210.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ReplaySystem.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A850.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003B6210.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EDE70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3StopJunction_002B6BC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3StopJunction.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundDSPBlock_002FC0E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundDSPBlock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00354CF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundListenerManager_00384B80.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundListenerManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0038E3F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038EAD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficVehicle_00172000.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficVehicle.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0033AC60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0033BD80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038E0F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00390610.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C3050.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C5750.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00446970.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A7D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3RaceCarPhysics_001BFE00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RaceCarPhysics.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundManagerPS2_00276990.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundManagerPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ScoreBonus_00368360.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0037E600.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundListenerManager_00384BF0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundListenerManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003FC260.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00454630.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00130B00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F22B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00442E90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042DEC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00240D40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00332D70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00339E70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0033A6A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0033A730.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3CrashAnalyser_00354ED0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashAnalyser.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0038C360.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038D7D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003ED950.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3ReplayFrame_00154C90.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ReplayFrame.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ReplayPage_003C5FB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ReplayPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundGameModeManager_0028A3C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundGameModeManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003388C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00393600.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock_00217350.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtInputDevicePS2DualShock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0030A8E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E9240.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00466310.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004663A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3ReplaySystem_00154DC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ReplaySystem.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3CoronaRendererPS2_00307630.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CoronaRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003F4160.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0043C3C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0033A600.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3VehicleRendererRuntime_00220FD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3VehicleRendererRuntime.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ErrorPage_00352210.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ErrorPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3CrashCameraDirector_00357550.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3CrashCameraDirector.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00466430.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004664E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundTrafficVehicle_00278E70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficVehicle.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0021B770.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C60B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003ED7E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtPS2LibNet_0022EB40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `GtPS2LibNet.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003F64D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C5690.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00272BC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022E6C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042FDC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OfflineStageLogic_00395490.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3OfflineStageLogic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00352130.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C57C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042FCE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00420A50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042FBC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00157260.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003D8810.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00130A00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3EffectsManager_00262660.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ReplayFrame_00154AC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ReplayFrame.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundPlayerCar_0028C670.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundPlayerCar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3Score_0015C9A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3GameData_0014FF70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3GameData.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3GameData_0014ECB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3GameData.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003F3E60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00371270.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EF7F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013C4B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3GraphicsManagerPS2_00227ED0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3GraphicsManagerPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3MenuComponents_0030B560.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3MenuComponents.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3GameData_0014EDD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3GameData.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00434A40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3NetworkVoIPManagerPS2_0041EAD0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkVoIPManagerPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0039AD50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022D9F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022DA20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficParam_00161B20.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficParam.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficParam_00160E50.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficParam.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundStream_00386360.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundStream.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0026E400.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtBuddies_0035F0A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtBuddies.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3MemoryCardController_004216A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3MemoryCardController.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0022D330.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022D7E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003601C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtBuddies_0035F100.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtBuddies.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3DataLists_00251AE0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0033BAE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3DataLists_00251A30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00445710.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0028AE80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0019E9A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0028AE40.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00235180.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundManager_00384EC0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0043C570.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundManager_00384F00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00371B90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003A5CC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C9A10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004456B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038EDA0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001A85C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003A5C70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3AsyncDataLoader_0013D4D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AsyncDataLoader.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0043EDE0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003A67E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003436C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013C390.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002F9870.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficValve_002685B0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficValve.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00270C90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00335030.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BE5C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3NetworkPlayerStartCountdownMessage_001A8550.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3NetworkPlayerStartCountdownMessage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00236E20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F40E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00458880.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BA5E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022E790.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C2E60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C2F90.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3ChatDisplayComponent_00332570.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ChatDisplayComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0013C400.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00393260.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0023F4C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003AFFD0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00151A30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0023E3C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0023E3D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001D4E80.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E8E60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001D3D30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00386020.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundTrafficManager_00276D00.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundVoiceManager_00389080.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundVoiceManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00442880.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundVoiceManager_00389380.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundVoiceManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001B8B70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0027E540.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. vararg template. |
| `src/b3/_unclassified/func_00447170.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. vararg template. |
| `src/b3/_unclassified/func_00392240.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00421580.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficPhysics_00250310.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficPhysics.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3RaceCar_00150EE0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00395A00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtFSM_00217610.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtFSM.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtFSM_00217650.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtFSM.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtFSM_002176D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtFSM.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3OnlineLobbyPage_003146E0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003974E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtFSM_00217710.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtFSM.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033A210.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00318A30.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineStageLogic_003906A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineStageLogic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0028AEC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EFE70.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003922D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003935A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundRaceCar_0028D7C0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundRaceCar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtInputManagerPS2Pad2_00214940.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtInputManagerPS2Pad2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3RacePosition_00154A30.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3RacePosition.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00372B20.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038BA50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0036C1C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0037C1C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00459640.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004596D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0045A1B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033A250.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_004457C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineSelectLoginPage_003478A0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineSelectLoginPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundListenerManager_00384D40.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundListenerManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003962A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00396340.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineRetrieveConfigsPage_0034A430.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineRetrieveConfigsPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0038A380.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3AsyncDataLoader_0013D410.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3AsyncDataLoader.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003C0890.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003FDE10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00389B50.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003941A0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00438CF0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00312330.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0036C770.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00372FB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003961B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00459550.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EDD60.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineSelectLoginPage_00349840.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineSelectLoginPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0032A930.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003496C0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00317B80.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_002C1D10.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F55E0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284D00.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F020.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00384330.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3ConvexHullMaker_003D8D60.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3ConvexHullMaker.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_002352B0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3PopcornRendererPS2_00365890.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3PopcornRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0039C170.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficValve_00266450.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3TrafficValve.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001A08D0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00287570.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundListenerManager_00384CE0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundListenerManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundListenerManager_00384C70.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundListenerManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001A0790.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtCamera_0021B010.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtCamera.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001A0930.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundBank_00383C10.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundBank.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtCamera_0021B440.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtCamera.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0026ECC0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035EDB0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundESM_00287890.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `B3SoundESM.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_002351F0.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00236940.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSphereTree_0035EE50.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00157180.cpp` | placed + proven 2026-10-22 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtTextureCachePS2_00221490.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtTextureCachePS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3GameData_0014EF60.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (medium); file `B3GameData.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundStreamManager_003869D0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundStreamManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundStreamManager_00386C50.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundStreamManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundStreamManager_00386CB0.cpp` | placed + proven 2026-10-22 (batch) | `[C]` name: retail tables (high); file `GtSoundStreamManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3CrashAnalyser_00354260.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3CrashAnalyser.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundStreamManager_00386A10.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtSoundStreamManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundBankManager_00384400.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtSoundBankManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00386970.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00136380.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00136400.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001362F0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00135A90.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundGameModeManager_00289320.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3SoundGameModeManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00213EB0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3ControllerMappingPS2_0012FFB0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3ControllerMappingPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SkyDomeRendererPS2_0021DBC0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3SkyDomeRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3BehaviourOffset_002E2710.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourOffset.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3BehaviourRaceCarFollow_002E3420.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (medium); file `B3BehaviourRaceCarFollow.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SunRendererPS2_0024B360.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3SunRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ScrapeRenderPS2_00376230.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3ScrapeRenderPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ScrapeRenderPS2_00376260.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3ScrapeRenderPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3EnvironmentManager_002BCE90.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3EnvironmentManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00283F70.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284770.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00283CA0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00283DF0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00283F30.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284AA0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284AE0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284B20.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284C80.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284CC0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284FB0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00285260.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034D8D0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00283DB0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00283EF0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002841B0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284C40.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284E50.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002850B0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00285150.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002854E0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00285520.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00283CE0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00283E30.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284E10.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284E90.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284ED0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284F10.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0041E9A0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0041E9C0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3HardCodedTrackRegionList_003F5AC0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3HardCodedTrackRegionList.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3HardCodedTrackRegionList_003F5AE0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3HardCodedTrackRegionList.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3Globe2dObject_003B54A0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3Globe2dObject.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3HardCodedTrackRegionList_003F5B00.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3HardCodedTrackRegionList.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0026D260.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002F98E0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3Globe2dObject_003B5460.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3Globe2dObject.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0022D1A0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3MemoryManager_003E8760.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (medium); file `B3MemoryManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003350A0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00368D20.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0026CA00.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3DebrisRendererPS2_002F4940.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3DebrisRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0038FF10.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3CrashScore_003CCE90.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3CrashScore.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00325990.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3Globe2dObject_003B5510.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3Globe2dObject.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001D3FA0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022FBC0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00385EC0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042B470.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrailSystem_002BD9A0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TrailSystem.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0026EC50.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3InputManager_0022BA70.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficValve_00267790.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TrafficValve.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3StaticTrack_00332D00.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3StaticTrack.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3PageTextComponent_00379910.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3PageTextComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022BB80.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022BBF0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003C2B80.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003CCBE0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001D28C0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0026ED50.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundRealVoice_00385E20.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtSoundRealVoice.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundVirtualVoice_00388A10.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0026C8C0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3InputManagerPS2_002144B0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManagerPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManagerPS2_00214560.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManagerPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022BC60.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3DNASPage_00353520.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3DNASPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003609A0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineLoginToLobbyPage_0034CD50.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3OnlineLoginToLobbyPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficSystem_00167B90.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TrafficSystem.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0037B400.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EAAE0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EAC90.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EAEA0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EAED0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtByteStream_00374470.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtByteStream.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3Viewport_00251800.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3Viewport.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00440730.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00458940.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficLight_00265C60.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TrafficLight.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundWave_003895D0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtSoundWave.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00150D00.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003ED9F0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00151100.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C6050.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00453C80.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EDA40.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00157360.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3RaceCarPhysics_001BEA70.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3RaceCarPhysics.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0042B660.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003FB710.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0030CE80.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00468D60.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00468D10.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004692B0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00468FF0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042B6A0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00468CA0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00469240.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00468DB0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00468F70.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002409B0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00272D60.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00272DD0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00469050.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004690E0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00339380.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00379140.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0043F570.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F39C0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F0FF0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00396E50.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00322450.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3AICar_00141BC0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3AICar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3Burn_0014E250.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00459770.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3HardCodedCrashStageList_003E8FC0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (medium); file `B3HardCodedCrashStageList.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3HardCodedRaceStageList_003E9A60.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3HardCodedRaceStageList.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3OnlineLobbyPage_003131A0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003C5510.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EDEE0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001A0660.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00313090.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_004597C0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0019EAC0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F57A0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5B30.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0045FF90.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3DataLists_00251870.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003F58D0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5B90.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5C00.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002E32E0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EA4C0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0028E0A0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038E360.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00335DD0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00335DB0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/Gt2dRendererPS2_00217850.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0033C890.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficValve_002667E0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TrafficValve.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0038D680.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038E300.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00392530.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013B6D0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3CoronaRendererPS2_00307500.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3CoronaRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ReplaySystem_001551B0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3ReplaySystem.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D3050.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003CBB60.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00432A50.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00433C20.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00455670.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BE640.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BE850.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003D1050.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003D1000.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013B200.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3InputManager_0022C8C0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022C940.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022C9C0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022CA40.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022CAC0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0022CBE0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022CC60.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3InputManager_0022CCE0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022CD60.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022CDE0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022CE60.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022CEE0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022CF60.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3InputManager_0022CFE0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0022BD50.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3InputManager_0022D0A0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (medium); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0022BE00.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022B8E0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022BEE0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038BE40.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00392330.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3BehaviourRaceCarFollow_002E5D90.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3BehaviourRaceCarFollow.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00386080.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00374840.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00392590.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003A02F0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0043FA90.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038D6E0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0028DFC0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0026C0A0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00352040.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003485B0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00434440.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0019A1D0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00465320.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineSelectLoginPage_00348490.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3OnlineSelectLoginPage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_0035F790.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0028B580.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042E6B0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002BFB00.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OnlineLoginToLobbyState_0034B800.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3OnlineLoginToLobbyState.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003F0CE0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013C8E0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3OfflineStageLogic_003957D0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3OfflineStageLogic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0013C8A0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00231190.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3HardCodedCrashStageList_003E9540.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (medium); file `B3HardCodedCrashStageList.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3HardCodedTrackList_003EAB90.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3HardCodedTrackList.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003D1C50.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003D25E0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00386300.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0026CA50.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00392660.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00230F60.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00436F70.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C4900.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00391630.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00469170.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00468E20.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00468ED0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BA4E0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficDebug_002F02C0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TrafficDebug.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3OnlineStageLogic_00391F10.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3OnlineStageLogic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00392250.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022D890.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284020.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003BAFE0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0044A1E0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00396FE0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00150090.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3PlayerCar_00150820.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (medium); file `B3PlayerCar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3AICar_00142350.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3AICar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundVoiceManager_00388F20.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtSoundVoiceManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00469310.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00469360.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004693B0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002875D0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00287B80.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002C0410.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtViewport_00211DD0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtViewport.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003F67F0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0026EDD0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3StreamManager_003C30E0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3StreamManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3StreamManager_003C31E0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3StreamManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0033C670.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrackMaterialPS2_0026A170.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TrackMaterialPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficLaneStruct_00269F10.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TrafficLaneStruct.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0038D870.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038E480.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundVirtualVoice_00387980.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TriggerStruct_00269D20.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TriggerStruct.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficDataStruct_00269FA0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TrafficDataStruct.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ConvexHull_002BAEF0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3ConvexHull.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0021AAF0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00271920.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001BAAC0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004437F0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00461A30.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0026BE90.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00463800.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3Score_001561C0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3HUDPrimaryMessage_003D8070.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3HUDPrimaryMessage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00466970.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00276870.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00356680.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_004667D0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00467020.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00466750.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002848E0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002768F0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00467580.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3DataLists_00251C10.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00453CF0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3EffectsManager_00262B80.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00336410.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00217690.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EAD20.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EB060.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E9700.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5E40.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficLane_00160590.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TrafficLane.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E70B0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3PhysicsManager_001B85F0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficValve_00267520.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3TrafficValve.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtInputDevicePS2Keyboard_00303FC0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtInputDevicePS2Keyboard.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0026C950.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E9AD0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_003379D0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |

<!-- tu-table:start -->
## Regrouped translation units (generated: tools/layout_tu_table.py)

One source file per retail .cpp, merged from proven per-function units by tools/tu_merge.py (each function's
object is still placed at its own retail address; the merged object is split per function). Membership
evidence is per function; the folder evidence is Revenge's file of the same name, `[L]` (B14 lineage).

| File | Functions | Membership | Folder evidence |
|---|---:|---|---|
| `src/b3/GameShared/GameClasses/Containers/GtArray.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtArray.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Containers/GtArray.cpp |
| `src/b3/GameShared/GameClasses/Containers/GtDictionary.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtDictionary.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Containers/GtDictionary.cpp |
| `src/b3/GameShared/GameClasses/Containers/GtSphereTree.cpp` | 4 | 3 function(s) named in research/retail_names.csv -> GtSphereTree.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Containers/GtSphereTree.cpp |
| `src/b3/GameShared/GameClasses/Core/GtID.cpp` | 5 | 5 function(s) named in research/retail_names.csv -> GtID.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Core/GtID.cpp |
| `src/b3/GameShared/GameClasses/Development/CommsTool/GtCommsToolBase.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtCommsToolBase.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Development/CommsTool/GtCommsToolBase.cpp |
| `src/b3/GameShared/GameClasses/Geometric/Intersection/GtCollisionKDTree.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtCollisionKDTree.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Geometric/Intersection/GtCollisionKDTree.cpp |
| `src/b3/GameShared/GameClasses/Geometric/Primitives/GtPolygonSoup.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> GtPolygonSoup.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Geometric/Primitives/GtPolygonSoup.cpp |
| `src/b3/GameShared/GameClasses/Graphical/2d/Gt2dFrameHierarchy.cpp` | 10 | 0 function(s) named in research/retail_names.csv -> Gt2dFrameHierarchy.cpp, 5 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/2d/Gt2dFrameHierarchy.cpp |
| `src/b3/GameShared/GameClasses/Graphical/2d/Ps2/Gt2dRendererPS2.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> Gt2dRendererPS2.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/2d/Ps2/Gt2dRendererPS2.cpp |
| `src/b3/GameShared/GameClasses/Graphical/Camera/GtCamera.cpp` | 3 | 1 function(s) named in research/retail_names.csv -> GtCamera.cpp, 2 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/Camera/GtCamera.cpp |
| `src/b3/GameShared/GameClasses/Graphical/Camera/GtCameraBehaviour.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtCameraBehaviour.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/Camera/GtCameraBehaviour.cpp |
| `src/b3/GameShared/GameClasses/Graphical/Camera/GtViewport.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> GtViewport.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/Camera/GtViewport.cpp |
| `src/b3/GameShared/GameClasses/Graphical/GtScreenCentre.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> GtScreenCentre.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/GtScreenCentre.cpp |
| `src/b3/GameShared/GameClasses/Graphical/TextureCachePS2/GtTextureCachePS2.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> GtTextureCachePS2.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/TextureCachePS2/GtTextureCachePS2.cpp |
| `src/b3/GameShared/GameClasses/Graphical/VideoDecoder/Ps2/GtVideoDecoderPS2.cpp` | 4 | 3 function(s) named in research/retail_names.csv -> GtVideoDecoderPS2.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/VideoDecoder/Ps2/GtVideoDecoderPS2.cpp |
| `src/b3/GameShared/GameClasses/Memory/GtLinearMalloc.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtLinearMalloc.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Memory/GtLinearMalloc.cpp |
| `src/b3/GameShared/GameClasses/Memory/GtMalloc.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtMalloc.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Memory/GtMalloc.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundBank.cpp` | 7 | 5 function(s) named in research/retail_names.csv -> GtSoundBank.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundBank.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundBankManager.cpp` | 4 | 2 function(s) named in research/retail_names.csv -> GtSoundBankManager.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundBankManager.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundListener.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> GtSoundListener.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundListener.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundListenerManager.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtSoundListenerManager.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundListenerManager.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundManager.cpp` | 7 | 3 function(s) named in research/retail_names.csv -> GtSoundManager.cpp, 4 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundManager.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundRealVoice.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> GtSoundRealVoice.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundRealVoice.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundStream.cpp` | 11 | 3 function(s) named in research/retail_names.csv -> GtSoundStream.cpp, 8 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundStream.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundStreamManager.cpp` | 6 | 4 function(s) named in research/retail_names.csv -> GtSoundStreamManager.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundStreamManager.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundUtils.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtSoundUtils.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundUtils.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundVirtualVoice.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> GtSoundVirtualVoice.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundVirtualVoice.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundVoice.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtSoundVoice.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundVoice.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundVoiceManager.cpp` | 5 | 5 function(s) named in research/retail_names.csv -> GtSoundVoiceManager.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundVoiceManager.cpp |
| `src/b3/GameShared/GameClasses/Sound/GtSoundWave.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> GtSoundWave.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundWave.cpp |
| `src/b3/GameShared/GameClasses/System/FileSystem/GtFileSystem.cpp` | 6 | 6 function(s) named in research/retail_names.csv -> GtFileSystem.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/FileSystem/GtFileSystem.cpp |
| `src/b3/GameShared/GameClasses/System/FileSystem/ps2/GtFileSystemPS2DVD.cpp` | 6 | 3 function(s) named in research/retail_names.csv -> GtFileSystemPS2DVD.cpp, 3 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/FileSystem/ps2/GtFileSystemPS2DVD.cpp |
| `src/b3/GameShared/GameClasses/System/Fsm/GtFSM.cpp` | 6 | 6 function(s) named in research/retail_names.csv -> GtFSM.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Fsm/GtFSM.cpp |
| `src/b3/GameShared/GameClasses/System/GtUnicodeUtils.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtUnicodeUtils.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/GtUnicodeUtils.cpp |
| `src/b3/GameShared/GameClasses/System/Headset/Source/Ps2/GtLogitechHeadset.cpp` | 4 | 1 function(s) named in research/retail_names.csv -> GtLogitechHeadset.cpp, 3 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Headset/Source/Ps2/GtLogitechHeadset.cpp |
| `src/b3/GameShared/GameClasses/System/Input/Ps2/GtInputDevicePS2DualShock.cpp` | 7 | 3 function(s) named in research/retail_names.csv -> GtInputDevicePS2DualShock.cpp, 1 by a medium-confidence name confirmed by a neighbour, 3 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Input/Ps2/GtInputDevicePS2DualShock.cpp |
| `src/b3/GameShared/GameClasses/System/Input/Ps2/GtInputDevicePS2DualShock2.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtInputDevicePS2DualShock2.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Input/Ps2/GtInputDevicePS2DualShock2.cpp |
| `src/b3/GameShared/GameClasses/System/Input/Ps2/GtInputDevicePS2Keyboard.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtInputDevicePS2Keyboard.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Input/Ps2/GtInputDevicePS2Keyboard.cpp |
| `src/b3/GameShared/GameClasses/System/Input/Ps2/GtInputManagerPS2Pad2.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> GtInputManagerPS2Pad2.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Input/Ps2/GtInputManagerPS2Pad2.cpp |
| `src/b3/GameShared/GameClasses/System/MemoryCard/ps2/GTMemoryDevicePS2_MC2.cpp` | 9 | 8 function(s) named in research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/MemoryCard/ps2/GTMemoryDevicePS2_MC2.cpp |
| `src/b3/GameShared/GameClasses/System/Networking/Buddies/GtBuddies.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> GtBuddies.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Networking/Buddies/GtBuddies.cpp |
| `src/b3/GameShared/GameClasses/System/Networking/LobbyService/PlatformIndependent/DirtySock/GtLobbyDirtySock.cpp` | 37 | 16 function(s) named in research/retail_names.csv -> GtLobbyDirtySock.cpp, 13 by a medium-confidence name confirmed by a neighbour, 32 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Networking/LobbyService/PlatformIndependent/DirtySock/GtLobbyDirtySock.cpp |
| `src/b3/GameShared/GameClasses/System/Networking/Packeting/Ps2/GtPS2LibNet.cpp` | 7 | 2 function(s) named in research/retail_names.csv -> GtPS2LibNet.cpp, 1 by a medium-confidence name confirmed by a neighbour, 4 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Networking/Packeting/Ps2/GtPS2LibNet.cpp |
| `src/b3/GameShared/GameClasses/System/Networking/Players/GtNetworkPlayerManager.cpp` | 24 | 5 function(s) named in research/retail_names.csv -> GtNetworkPlayerManager.cpp, 2 by a medium-confidence name confirmed by a neighbour, 17 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Networking/Players/GtNetworkPlayerManager.cpp |
| `src/b3/GameShared/GameClasses/System/Threads/ps2/GtThreadMgrPS2.cpp` | 3 | 4 function(s) named in research/retail_names.csv -> GtThreadMgrPS2.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Threads/ps2/GtThreadMgrPS2.cpp |
| `src/b3/GameShared/GameClasses/System/Timer/GtFramerateManager.cpp` | 3 | 2 function(s) named in research/retail_names.csv -> GtFramerateManager.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Timer/GtFramerateManager.cpp |
| `src/b3/GameShared/GameClasses/System/Timer/GtTimer.cpp` | 6 | 6 function(s) named in research/retail_names.csv -> GtTimer.cpp | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Timer/GtTimer.cpp |
| `src/b3/GameShared/GameClasses/System/Timer/Ps2/GtHiResSystemTimerPS2.cpp` | 5 | 2 function(s) named in research/retail_names.csv -> GtHiResSystemTimerPS2.cpp, 3 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Timer/Ps2/GtHiResSystemTimerPS2.cpp |
| `src/b3/SharedClasses/DataLists/B3DataLists.cpp` | 13 | 13 function(s) named in research/retail_names.csv -> B3DataLists.cpp | [L] Revenge (SLUS_212.42) SharedClasses/DataLists/B4DataLists.cpp |
| `src/b3/SharedClasses/PhysicsData/B3ConvexHull.cpp` | 5 | 5 function(s) named in research/retail_names.csv -> B3ConvexHull.cpp | [L] Revenge (SLUS_212.42) SharedClasses/PhysicsData/B4ConvexHull.cpp |
| `src/b3/SharedClasses/ProgressionData/B3ProgressionDataStruct.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3ProgressionDataStruct.cpp | [L] Revenge (SLUS_212.42) SharedClasses/ProgressionData/B4ProgressionDataStruct.cpp |
| `src/b3/SharedClasses/SoundData/B3SoundESMStruct.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3SoundESMStruct.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) SharedClasses/SoundData/B4SoundESMStruct.cpp |
| `src/b3/SharedClasses/TrafficData/B3CrashTrafficGenerationStruct.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3CrashTrafficGenerationStruct.cpp | [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4CrashTrafficGenerationStruct.cpp |
| `src/b3/SharedClasses/TrafficData/B3TrafficDataStruct.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3TrafficDataStruct.cpp | [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4TrafficDataStruct.cpp |
| `src/b3/SharedClasses/TrafficData/B3TrafficHullStruct.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3TrafficHullStruct.cpp | [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4TrafficHullStruct.cpp |
| `src/b3/SharedClasses/TrafficData/B3TrafficLaneStruct.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3TrafficLaneStruct.cpp | [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4TrafficLaneStruct.cpp |
| `src/b3/SharedClasses/TrafficData/B3TrafficLightStruct.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3TrafficLightStruct.cpp | [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4TrafficLightStruct.cpp |
| `src/b3/SharedClasses/TrafficData/B3TrafficValveStruct.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3TrafficValveStruct.cpp | [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4TrafficValveStruct.cpp |
| `src/b3/SharedClasses/TrafficData/B3TriggerStruct.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3TriggerStruct.cpp | [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4TriggerStruct.cpp |
| `src/b3/_unclassified/B3BuddyDisplayComponent.cpp` | 3 | 2 function(s) named in research/retail_names.csv -> B3BuddyDisplayComponent.cpp, 1 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3BuddyReadMailComponent.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3BuddyReadMailComponent.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3CarViewerGameMode.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3CarViewerGameMode.cpp | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3ChatDisplayComponent.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3ChatDisplayComponent.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3ConvexHullCollide.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3ConvexHullCollide.cpp | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3ConvexHullMaker.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3ConvexHullMaker.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3CrashCameraDirector.cpp` | 5 | 1 function(s) named in research/retail_names.csv -> B3CrashCameraDirector.cpp, 1 by a medium-confidence name confirmed by a neighbour, 3 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3EventFinishedComponent.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3EventFinishedComponent.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3FlashText2dObject.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3FlashText2dObject.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3HardCodedCrashStageList.cpp` | 6 | 0 function(s) named in research/retail_names.csv -> B3HardCodedCrashStageList.cpp, 3 by a medium-confidence name confirmed by a neighbour, 4 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3HardCodedRaceStageList.cpp` | 4 | 2 function(s) named in research/retail_names.csv -> B3HardCodedRaceStageList.cpp, 2 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3HardCodedTrackList.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3HardCodedTrackList.cpp, 1 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3HardCodedTrackRegionList.cpp` | 8 | 3 function(s) named in research/retail_names.csv -> B3HardCodedTrackRegionList.cpp, 5 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3MemoryCardController.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3MemoryCardController.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3MenuFlowFSM.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3MenuFlowFSM.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3MessageBoxComponent.cpp` | 3 | 1 function(s) named in research/retail_names.csv -> B3MessageBoxComponent.cpp, 2 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3NetworkGameModeStatusMessage.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3NetworkGameModeStatusMessage.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3NetworkReplayMessage.cpp` | 4 | 3 function(s) named in research/retail_names.csv -> B3NetworkReplayMessage.cpp, 1 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3NetworkVoIPManagerPS2.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3NetworkVoIPManagerPS2.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3OnlineGameCreateState.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3OnlineGameCreateState.cpp | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3OnlineLoginToLobbyState.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3OnlineLoginToLobbyState.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3RadialBlur2dObject.cpp` | 2 | 0 function(s) named in research/retail_names.csv -> B3RadialBlur2dObject.cpp, 2 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3RewardImageComponent.cpp` | 3 | 1 function(s) named in research/retail_names.csv -> B3RewardImageComponent.cpp, 2 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3SatNavComponent.cpp` | 2 | 0 function(s) named in research/retail_names.csv -> B3SatNavComponent.cpp, 2 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3Score.cpp` | 3 | 1 function(s) named in research/retail_names.csv -> B3Score.cpp, 2 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3ScoreBonus.cpp` | 17 | 5 function(s) named in research/retail_names.csv -> B3ScoreBonus.cpp, 5 by a medium-confidence name confirmed by a neighbour, 7 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3ScrollBarComponent.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3ScrollBarComponent.cpp | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3SoundDSPBlock.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3SoundDSPBlock.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3Strings.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3Strings.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3TableComponent.cpp` | 4 | 2 function(s) named in research/retail_names.csv -> B3TableComponent.cpp, 2 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3TextComponent.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3TextComponent.cpp | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/B3TitleScreenComponent.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3TitleScreenComponent.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock.cpp` | 23 | 7 function(s) named in research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp, 1 by a medium-confidence name confirmed by a neighbour, 17 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/GtNetworkHeadset.cpp` | 5 | 3 function(s) named in research/retail_names.csv -> GtNetworkHeadset.cpp, 2 placed between two of them by address contiguity (N2) | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/_unclassified/GtPerfMon.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> GtPerfMon.cpp | Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md) |
| `src/b3/gamesource/Camera/B3PlayerCameraManager.cpp` | 5 | 2 function(s) named in research/retail_names.csv -> B3PlayerCameraManager.cpp, 2 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Camera/B4PlayerCameraManager.cpp |
| `src/b3/gamesource/Camera/Behaviours/B3BehaviourCluster.cpp` | 3 | 0 function(s) named in research/retail_names.csv -> B3BehaviourCluster.cpp, 3 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Camera/Behaviours/B4BehaviourCluster.cpp |
| `src/b3/gamesource/Camera/Behaviours/B3BehaviourEffect.cpp` | 6 | 1 function(s) named in research/retail_names.csv -> B3BehaviourEffect.cpp, 2 by a medium-confidence name confirmed by a neighbour, 3 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Camera/Behaviours/B4BehaviourEffect.cpp |
| `src/b3/gamesource/Camera/Behaviours/B3BehaviourFlyAround.cpp` | 4 | 0 function(s) named in research/retail_names.csv -> B3BehaviourFlyAround.cpp, 3 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Camera/Behaviours/B4BehaviourFlyAround.cpp |
| `src/b3/gamesource/Camera/Behaviours/B3BehaviourInterpolate.cpp` | 3 | 0 function(s) named in research/retail_names.csv -> B3BehaviourInterpolate.cpp, 3 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Camera/Behaviours/B4BehaviourInterpolate.cpp |
| `src/b3/gamesource/Camera/Behaviours/B3BehaviourOffset.cpp` | 3 | 0 function(s) named in research/retail_names.csv -> B3BehaviourOffset.cpp, 2 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Camera/Behaviours/B4BehaviourOffset.cpp |
| `src/b3/gamesource/Camera/Behaviours/B3BehaviourRaceCarFollow.cpp` | 2 | 0 function(s) named in research/retail_names.csv -> B3BehaviourRaceCarFollow.cpp, 2 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Camera/Behaviours/B4BehaviourRaceCarFollow.cpp |
| `src/b3/gamesource/Camera/Behaviours/B3BehaviourRotate.cpp` | 2 | 0 function(s) named in research/retail_names.csv -> B3BehaviourRotate.cpp, 2 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Camera/Behaviours/B4BehaviourRotate.cpp |
| `src/b3/gamesource/Camera/Behaviours/B3BehaviourTrackSide.cpp` | 5 | 1 function(s) named in research/retail_names.csv -> B3BehaviourTrackSide.cpp, 4 by a medium-confidence name confirmed by a neighbour | [G] domain word `Behaviour` in the name: 26 of Revenge's 28 files with it are in GameSource/Camera/Behaviours/ |
| `src/b3/gamesource/Camera/Behaviours/B3CameraBehaviour.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3CameraBehaviour.cpp | [L] Revenge (SLUS_212.42) GameSource/Camera/Behaviours/B4CameraBehaviour.cpp |
| `src/b3/gamesource/Camera/CameraUtils/B3CameraUtils.cpp` | 1 | 0 function(s) named in research/retail_names.csv -> B3CameraUtils.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Camera/CameraUtils/B4CameraUtils.cpp |
| `src/b3/gamesource/Camera/Crash/B3CrashAnalyser.cpp` | 5 | 3 function(s) named in research/retail_names.csv -> B3CrashAnalyser.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Camera/Crash/B4CrashAnalyser.cpp |
| `src/b3/gamesource/Camera/Movie/B3CameraEditor.cpp` | 11 | 8 function(s) named in research/retail_names.csv -> B3CameraEditor.cpp, 3 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Camera/Movie/B4CameraEditor.cpp |
| `src/b3/gamesource/EASharedLogin/Ps2/B3SFIOCallbacksPS2.cpp` | 12 | 1 function(s) named in research/retail_names.csv -> B3SFIOCallbacksPS2.cpp, 3 by a medium-confidence name confirmed by a neighbour, 8 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/EASharedLogin/Ps2/B4SFIOCallbacksPS2.cpp |
| `src/b3/gamesource/Game/B3AIDebug.cpp` | 5 | 5 function(s) named in research/retail_names.csv -> B3AIDebug.cpp | [L] Revenge (SLUS_212.42) GameSource/Game/B4AIDebug.cpp |
| `src/b3/gamesource/Game/B3AsyncDataLoader.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3AsyncDataLoader.cpp | [L] Revenge (SLUS_212.42) GameSource/Game/B4AsyncDataLoader.cpp |
| `src/b3/gamesource/Game/B3CPUMonitors.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3CPUMonitors.cpp | [L] Revenge (SLUS_212.42) GameSource/Game/B4CPUMonitors.cpp |
| `src/b3/gamesource/Game/B3DebugManager.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3DebugManager.cpp | [L] Revenge (SLUS_212.42) GameSource/Game/B4DebugManager.cpp |
| `src/b3/gamesource/Game/B3FrontEnd.cpp` | 5 | 5 function(s) named in research/retail_names.csv -> B3FrontEnd.cpp | [L] Revenge (SLUS_212.42) GameSource/Game/B4FrontEnd.cpp |
| `src/b3/gamesource/Game/B3Game.cpp` | 31 | 6 function(s) named in research/retail_names.csv -> B3Game.cpp, 2 by a medium-confidence name confirmed by a neighbour, 23 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Game/B4Game.cpp |
| `src/b3/gamesource/Game/B3GameMode.cpp` | 6 | 4 function(s) named in research/retail_names.csv -> B3GameMode.cpp, 2 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Game/B4GameMode.cpp |
| `src/b3/gamesource/Game/B3InputManager.cpp` | 24 | 15 function(s) named in research/retail_names.csv -> B3InputManager.cpp, 1 by a medium-confidence name confirmed by a neighbour, 9 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Game/B4InputManager.cpp |
| `src/b3/gamesource/Game/B3MemoryManager.cpp` | 8 | 3 function(s) named in research/retail_names.csv -> B3MemoryManager.cpp, 3 by a medium-confidence name confirmed by a neighbour, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Game/B4MemoryManager.cpp |
| `src/b3/gamesource/Game/B3MenuInput.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3MenuInput.cpp | [L] Revenge (SLUS_212.42) GameSource/Game/B4MenuInput.cpp |
| `src/b3/gamesource/Game/B3OnePlayerStage.cpp` | 7 | 1 function(s) named in research/retail_names.csv -> B3OnePlayerStage.cpp, 4 by a medium-confidence name confirmed by a neighbour, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Game/B4OnePlayerStage.cpp |
| `src/b3/gamesource/Game/B3OnlineStage.cpp` | 4 | 2 function(s) named in research/retail_names.csv -> B3OnlineStage.cpp, 2 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Game/B4OnlineStage.cpp |
| `src/b3/gamesource/Game/B3Player.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3Player.cpp | [L] Revenge (SLUS_212.42) GameSource/Game/B4Player.cpp |
| `src/b3/gamesource/Game/B3Settings.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3Settings.cpp | [L] Revenge (SLUS_212.42) GameSource/Game/B4Settings.cpp |
| `src/b3/gamesource/Game/B3TrafficDebug.cpp` | 5 | 5 function(s) named in research/retail_names.csv -> B3TrafficDebug.cpp | [L] Revenge (SLUS_212.42) GameSource/Game/B4TrafficDebug.cpp |
| `src/b3/gamesource/Game/Logic/B3OfflineRoadRageLogic.cpp` | 11 | 0 function(s) named in research/retail_names.csv -> B3OfflineRoadRageLogic.cpp, 2 by a medium-confidence name confirmed by a neighbour, 9 placed between two of them by address contiguity (N2) | [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/ |
| `src/b3/gamesource/Game/Logic/B3OfflineSingleRaceLogic.cpp` | 17 | 1 function(s) named in research/retail_names.csv -> B3OfflineSingleRaceLogic.cpp, 2 by a medium-confidence name confirmed by a neighbour, 14 placed between two of them by address contiguity (N2) | [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/ |
| `src/b3/gamesource/Game/Logic/B3OfflineStageLogic.cpp` | 5 | 1 function(s) named in research/retail_names.csv -> B3OfflineStageLogic.cpp, 4 placed between two of them by address contiguity (N2) | [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/ |
| `src/b3/gamesource/Game/Logic/B3OnlineRoadRageRaceLogic.cpp` | 10 | 2 function(s) named in research/retail_names.csv -> B3OnlineRoadRageRaceLogic.cpp, 8 placed between two of them by address contiguity (N2) | [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/ |
| `src/b3/gamesource/Game/Logic/B3OnlineStageLogic.cpp` | 10 | 2 function(s) named in research/retail_names.csv -> B3OnlineStageLogic.cpp, 8 placed between two of them by address contiguity (N2) | [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/ |
| `src/b3/gamesource/Game/Logic/B3OnlineTurnBasedCrashLogic.cpp` | 9 | 1 function(s) named in research/retail_names.csv -> B3OnlineTurnBasedCrashLogic.cpp, 8 placed between two of them by address contiguity (N2) | [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/ |
| `src/b3/gamesource/Game/Logic/B3StageLogic.cpp` | 4 | 0 function(s) named in research/retail_names.csv -> B3StageLogic.cpp, 1 by a medium-confidence name confirmed by a neighbour, 3 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Game/Logic/B4StageLogic.cpp |
| `src/b3/gamesource/Game/Persistence/B3Profile.cpp` | 12 | 1 function(s) named in research/retail_names.csv -> B3Profile.cpp, 2 by a medium-confidence name confirmed by a neighbour, 11 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Game/Persistence/B4Profile.cpp |
| `src/b3/gamesource/Game/Ps2/B3ControllerMappingPS2.cpp` | 3 | 2 function(s) named in research/retail_names.csv -> B3ControllerMappingPS2.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Game/Ps2/B4ControllerMappingPS2.cpp |
| `src/b3/gamesource/Game/Ps2/B3GamePS2.cpp` | 2 | 0 function(s) named in research/retail_names.csv -> B3GamePS2.cpp, 1 by a medium-confidence name confirmed by a neighbour, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Game/Ps2/B4GamePS2.cpp |
| `src/b3/gamesource/Game/Ps2/B3InputManagerPS2.cpp` | 4 | 3 function(s) named in research/retail_names.csv -> B3InputManagerPS2.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Game/Ps2/B4InputManagerPS2.cpp |
| `src/b3/gamesource/Game/Ps2/B3MemoryManagerPS2.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3MemoryManagerPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Game/Ps2/B4MemoryManagerPS2.cpp |
| `src/b3/gamesource/Graphics/B3GraphicsManager.cpp` | 6 | 4 function(s) named in research/retail_names.csv -> B3GraphicsManager.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Graphics/B4GraphicsManager.cpp |
| `src/b3/gamesource/Graphics/B3Viewport.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3Viewport.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/B4Viewport.cpp |
| `src/b3/gamesource/Graphics/B4SkyDomeRenderer/Ps2/B3SkyDomeRendererPS2.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3SkyDomeRendererPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/B4SkyDomeRenderer/Ps2/B4SkyDomeRendererPS2.cpp |
| `src/b3/gamesource/Graphics/Bloom/Ps2/B3BloomPS2.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3BloomPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/Bloom/Ps2/B4BloomPS2.cpp |
| `src/b3/gamesource/Graphics/CoronaRenderer/Ps2/B3CoronaRendererPS2.cpp` | 5 | 5 function(s) named in research/retail_names.csv -> B3CoronaRendererPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/CoronaRenderer/Ps2/B4CoronaRendererPS2.cpp |
| `src/b3/gamesource/Graphics/DebrisRenderer/Ps2/B3DebrisRendererPS2.cpp` | 6 | 6 function(s) named in research/retail_names.csv -> B3DebrisRendererPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/DebrisRenderer/Ps2/B4DebrisRendererPS2.cpp |
| `src/b3/gamesource/Graphics/Debug/B3DebugMipMaps.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3DebugMipMaps.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/Debug/B4DebugMipMaps.cpp |
| `src/b3/gamesource/Graphics/Fog/Ps2/B3FogPS2.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3FogPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/Fog/Ps2/B4FogPS2.cpp |
| `src/b3/gamesource/Graphics/Im3D/Ps2/B3Im3DPS2.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3Im3DPS2.cpp, 1 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Graphics/Im3D/Ps2/B4Im3DPS2.cpp |
| `src/b3/gamesource/Graphics/ParticleRenderer/Ps2/B3ParticleRendererPS2.cpp` | 6 | 6 function(s) named in research/retail_names.csv -> B3ParticleRendererPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/ParticleRenderer/Ps2/B4ParticleRendererPS2.cpp |
| `src/b3/gamesource/Graphics/PopcornRenderer/Ps2/B3PopcornRendererPS2.cpp` | 4 | 2 function(s) named in research/retail_names.csv -> B3PopcornRendererPS2.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Graphics/PopcornRenderer/Ps2/B4PopcornRendererPS2.cpp |
| `src/b3/gamesource/Graphics/Ps2/B3GraphicsManagerPS2.cpp` | 4 | 2 function(s) named in research/retail_names.csv -> B3GraphicsManagerPS2.cpp, 1 by a medium-confidence name confirmed by a neighbour, 3 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Graphics/Ps2/B4GraphicsManagerPS2.cpp |
| `src/b3/gamesource/Graphics/Ps2/B3TextureCollectionPS2.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3TextureCollectionPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/Ps2/B4TextureCollectionPS2.cpp |
| `src/b3/gamesource/Graphics/Scrapes/B3ScrapeSystem.cpp` | 3 | 0 function(s) named in research/retail_names.csv -> B3ScrapeSystem.cpp, 3 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Graphics/Scrapes/B4ScrapeSystem.cpp |
| `src/b3/gamesource/Graphics/Scrapes/Ps2/B3ScrapeRenderPS2.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3ScrapeRenderPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/Scrapes/Ps2/B4ScrapeRenderPS2.cpp |
| `src/b3/gamesource/Graphics/ShadowRenderer/Ps2/B3ShadowRendererPS2.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3ShadowRendererPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/ShadowRenderer/Ps2/B4ShadowRendererPS2.cpp |
| `src/b3/gamesource/Graphics/SparkRenderer/Ps2/B3SparkRendererPS2.cpp` | 6 | 6 function(s) named in research/retail_names.csv -> B3SparkRendererPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/SparkRenderer/Ps2/B4SparkRendererPS2.cpp |
| `src/b3/gamesource/Graphics/SunRenderer/Ps2/B3SunRendererPS2.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> B3SunRendererPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/SunRenderer/Ps2/B4SunRendererPS2.cpp |
| `src/b3/gamesource/Graphics/TrackRenderer/Ps2/B3TrackMaterialPS2.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3TrackMaterialPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/TrackRenderer/Ps2/B4TrackMaterialPS2.cpp |
| `src/b3/gamesource/Graphics/Trails/B3TrailSystem.cpp` | 4 | 3 function(s) named in research/retail_names.csv -> B3TrailSystem.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Graphics/Trails/B4TrailSystem.cpp |
| `src/b3/gamesource/Graphics/VehicleRenderer/B3VehicleRendererRuntime.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3VehicleRendererRuntime.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/VehicleRenderer/B4VehicleRendererRuntime.cpp |
| `src/b3/gamesource/Graphics/VehicleRenderer/Ps2/B3VehicleRendererRuntimePS2.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3VehicleRendererRuntimePS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Graphics/VehicleRenderer/Ps2/B4VehicleRendererRuntimePS2.cpp |
| `src/b3/gamesource/Hud/B3Globe2dObject.cpp` | 4 | 3 function(s) named in research/retail_names.csv -> B3Globe2dObject.cpp, 1 placed between two of them by address contiguity (N2) | same unit as the hand-placed file there (its docs/layout.md row) |
| `src/b3/gamesource/Hud/B3HUDBoostBar.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3HUDBoostBar.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Hud/B4HUDBoostBar.cpp |
| `src/b3/gamesource/Hud/B3HUDComponent.cpp` | 3 | 2 function(s) named in research/retail_names.csv -> B3HUDComponent.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Hud/B4HUDComponent.cpp |
| `src/b3/gamesource/Hud/B3HUDEscapeDistance.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3HUDEscapeDistance.cpp | [G] domain word `HUD` in the name: 37 of Revenge's 38 files with it are in GameSource/Hud/ |
| `src/b3/gamesource/Hud/B3HUDManager.cpp` | 6 | 3 function(s) named in research/retail_names.csv -> B3HUDManager.cpp, 3 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Hud/B4HUDManager.cpp |
| `src/b3/gamesource/Hud/B3HUDPrimaryMessage.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3HUDPrimaryMessage.cpp | [G] domain word `HUD` in the name: 37 of Revenge's 38 files with it are in GameSource/Hud/ |
| `src/b3/gamesource/Hud/B3HUDPrimaryMessageHandler.cpp` | 1 | 0 function(s) named in research/retail_names.csv -> B3HUDPrimaryMessageHandler.cpp, 1 placed between two of them by address contiguity (N2) | [G] domain word `HUD` in the name: 37 of Revenge's 38 files with it are in GameSource/Hud/ |
| `src/b3/gamesource/Hud/B3HUDScore.cpp` | 1 | 0 function(s) named in research/retail_names.csv -> B3HUDScore.cpp, 1 by a medium-confidence name confirmed by a neighbour | [G] domain word `HUD` in the name: 37 of Revenge's 38 files with it are in GameSource/Hud/ |
| `src/b3/gamesource/Hud/B3HUDScoreList.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3HUDScoreList.cpp, 1 by a medium-confidence name confirmed by a neighbour | [G] domain word `HUD` in the name: 37 of Revenge's 38 files with it are in GameSource/Hud/ |
| `src/b3/gamesource/Menu/B3MenuChoices.cpp` | 3 | 1 function(s) named in research/retail_names.csv -> B3MenuChoices.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Menu/B4MenuChoices.cpp |
| `src/b3/gamesource/Menu/B3MenuStringBuffer.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3MenuStringBuffer.cpp, 1 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Menu/B4MenuStringBuffer.cpp |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3DNASPage.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3DNASPage.cpp, 1 by a medium-confidence name confirmed by a neighbour | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3ErrorPage.cpp` | 3 | 1 function(s) named in research/retail_names.csv -> B3ErrorPage.cpp, 1 by a medium-confidence name confirmed by a neighbour, 2 placed between two of them by address contiguity (N2) | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3MyBurnoutPage.cpp` | 1 | 0 function(s) named in research/retail_names.csv -> B3MyBurnoutPage.cpp, 1 placed between two of them by address contiguity (N2) | same unit as the hand-placed file there (its docs/layout.md row) |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3MyBurnoutRewardsHeadlinesPage.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3MyBurnoutRewardsHeadlinesPage.cpp | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineBuddiesMenuPage.cpp` | 2 | 0 function(s) named in research/retail_names.csv -> B3OnlineBuddiesMenuPage.cpp, 2 placed between two of them by address contiguity (N2) | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineBuddiesSearchMenuPage.cpp` | 4 | 1 function(s) named in research/retail_names.csv -> B3OnlineBuddiesSearchMenuPage.cpp, 2 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2) | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineConnectingPage.cpp` | 1 | 0 function(s) named in research/retail_names.csv -> B3OnlineConnectingPage.cpp, 1 by a medium-confidence name confirmed by a neighbour | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineGameCreatePage.cpp` | 1 | 0 function(s) named in research/retail_names.csv -> B3OnlineGameCreatePage.cpp, 1 by a medium-confidence name confirmed by a neighbour | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineJoinGamePage.cpp` | 5 | 3 function(s) named in research/retail_names.csv -> B3OnlineJoinGamePage.cpp, 1 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2) | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineLobbyPage.cpp` | 8 | 8 function(s) named in research/retail_names.csv -> B3OnlineLobbyPage.cpp, 1 placed between two of them by address contiguity (N2) | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineMenuPage.cpp` | 1 | 0 function(s) named in research/retail_names.csv -> B3OnlineMenuPage.cpp, 1 by a medium-confidence name confirmed by a neighbour | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineOpenLobbyPage.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3OnlineOpenLobbyPage.cpp | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineRetrieveConfigsPage.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3OnlineRetrieveConfigsPage.cpp | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineSelNetConfigPage.cpp` | 1 | 0 function(s) named in research/retail_names.csv -> B3OnlineSelNetConfigPage.cpp, 1 by a medium-confidence name confirmed by a neighbour | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineSelectLoginPage.cpp` | 6 | 4 function(s) named in research/retail_names.csv -> B3OnlineSelectLoginPage.cpp, 3 placed between two of them by address contiguity (N2) | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3OnlineSelectPersonaPage.cpp` | 3 | 2 function(s) named in research/retail_names.csv -> B3OnlineSelectPersonaPage.cpp, 1 by a medium-confidence name confirmed by a neighbour | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3PageTextComponent.cpp` | 3 | 2 function(s) named in research/retail_names.csv -> B3PageTextComponent.cpp, 1 placed between two of them by address contiguity (N2) | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Menu/DebugMenu/Pages/B3ReplayPage.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3ReplayPage.cpp | [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/ |
| `src/b3/gamesource/Network/B3NetworkManager.cpp` | 7 | 1 function(s) named in research/retail_names.csv -> B3NetworkManager.cpp, 11 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Network/B4NetworkManager.cpp |
| `src/b3/gamesource/Network/Messages/B3NetworkHasHeadsetMessage.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3NetworkHasHeadsetMessage.cpp | [L] Revenge (SLUS_212.42) GameSource/Network/Messages/B4NetworkHasHeadsetMessage.cpp |
| `src/b3/gamesource/Network/Messages/B3NetworkMessage.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3NetworkMessage.cpp | [L] Revenge (SLUS_212.42) GameSource/Network/Messages/B4NetworkMessage.cpp |
| `src/b3/gamesource/Network/Messages/B3NetworkPlayerStartCountdownMessage.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3NetworkPlayerStartCountdownMessage.cpp | [L] Revenge (SLUS_212.42) GameSource/Network/Messages/B4NetworkPlayerStartCountdownMessage.cpp |
| `src/b3/gamesource/Network/Messages/B3NetworkRaceReadyMessage.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3NetworkRaceReadyMessage.cpp | [L] Revenge (SLUS_212.42) GameSource/Network/Messages/B4NetworkRaceReadyMessage.cpp |
| `src/b3/gamesource/Physics/B3AICarPhysics.cpp` | 3 | 2 function(s) named in research/retail_names.csv -> B3AICarPhysics.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Physics/B4AICarPhysics.cpp |
| `src/b3/gamesource/Physics/B3BodyPartPhysics.cpp` | 3 | 1 function(s) named in research/retail_names.csv -> B3BodyPartPhysics.cpp, 2 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Physics/B4BodyPartPhysics.cpp |
| `src/b3/gamesource/Physics/B3CrashActionDirector.cpp` | 8 | 4 function(s) named in research/retail_names.csv -> B3CrashActionDirector.cpp, 4 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Physics/B4CrashActionDirector.cpp |
| `src/b3/gamesource/Physics/B3NetworkCarPhysics.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3NetworkCarPhysics.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Physics/B4NetworkCarPhysics.cpp |
| `src/b3/gamesource/Physics/B3PhysicsManager.cpp` | 4 | 2 function(s) named in research/retail_names.csv -> B3PhysicsManager.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Physics/B4PhysicsManager.cpp |
| `src/b3/gamesource/Physics/B3PhysicsManagerDebug.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3PhysicsManagerDebug.cpp | [L] Revenge (SLUS_212.42) GameSource/Physics/B4PhysicsManagerDebug.cpp |
| `src/b3/gamesource/Physics/B3PlayerCarPhysics.cpp` | 3 | 0 function(s) named in research/retail_names.csv -> B3PlayerCarPhysics.cpp, 1 by a medium-confidence name confirmed by a neighbour, 2 placed between two of them by address contiguity (N2) | same unit as the hand-placed file there (its docs/layout.md row) |
| `src/b3/gamesource/Physics/B3PropPhysics.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3PropPhysics.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Physics/B4PropPhysics.cpp |
| `src/b3/gamesource/Physics/B3RaceCarPhysics.cpp` | 5 | 3 function(s) named in research/retail_names.csv -> B3RaceCarPhysics.cpp, 1 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Physics/B4RaceCarPhysics.cpp |
| `src/b3/gamesource/Physics/B3TrafficPhysics.cpp` | 4 | 3 function(s) named in research/retail_names.csv -> B3TrafficPhysics.cpp, 1 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Physics/B4TrafficPhysics.cpp |
| `src/b3/gamesource/Physics/B3VehiclePhysics.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3VehiclePhysics.cpp | same unit as the hand-placed file there (its docs/layout.md row) |
| `src/b3/gamesource/Physics/Deformation/B3VehicleDeform.cpp` | 4 | 1 function(s) named in research/retail_names.csv -> B3VehicleDeform.cpp, 3 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Physics/Deformation/B4VehicleDeform.cpp |
| `src/b3/gamesource/Sound/B3SoundManager.cpp` | 4 | 2 function(s) named in research/retail_names.csv -> B3SoundManager.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Sound/B4SoundManager.cpp |
| `src/b3/gamesource/Sound/B3SoundStaticPassManager.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3SoundStaticPassManager.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/B4SoundStaticPassManager.cpp |
| `src/b3/gamesource/Sound/Cars/B3SoundAICar.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> B3SoundAICar.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Cars/B4SoundAICar.cpp |
| `src/b3/gamesource/Sound/Cars/B3SoundPlayerCar.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3SoundPlayerCar.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Cars/B4SoundPlayerCar.cpp |
| `src/b3/gamesource/Sound/Cars/B3SoundRaceCar.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3SoundRaceCar.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Cars/B4SoundRaceCar.cpp |
| `src/b3/gamesource/Sound/Cars/B3SoundRaceCarManager.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> B3SoundRaceCarManager.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Cars/B4SoundRaceCarManager.cpp |
| `src/b3/gamesource/Sound/Cars/B3SoundSkidModel.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3SoundSkidModel.cpp, 1 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Sound/Cars/B4SoundSkidModel.cpp |
| `src/b3/gamesource/Sound/Cars/B3SoundTurboModel.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3SoundTurboModel.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Cars/B4SoundTurboModel.cpp |
| `src/b3/gamesource/Sound/Core/B3SoundGameModeManager.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3SoundGameModeManager.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Core/B4SoundGameModeManager.cpp |
| `src/b3/gamesource/Sound/Core/B3SoundListener.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3SoundListener.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Core/B4SoundListener.cpp |
| `src/b3/gamesource/Sound/Crash/B3SoundCrashManager.cpp` | 5 | 4 function(s) named in research/retail_names.csv -> B3SoundCrashManager.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Sound/Crash/B4SoundCrashManager.cpp |
| `src/b3/gamesource/Sound/Crash/B3SoundScrape.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3SoundScrape.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Crash/B4SoundScrape.cpp |
| `src/b3/gamesource/Sound/Dsp/B3SoundDistPS2.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> B3SoundDistPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Dsp/B4SoundDistPS2.cpp |
| `src/b3/gamesource/Sound/Esm/B3SoundESM.cpp` | 3 | 2 function(s) named in research/retail_names.csv -> B3SoundESM.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Sound/Esm/B4SoundESM.cpp |
| `src/b3/gamesource/Sound/Esm/B3SoundESMManager.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3SoundESMManager.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Esm/B4SoundESMManager.cpp |
| `src/b3/gamesource/Sound/Hud/B3SoundHUDManager.cpp` | 9 | 2 function(s) named in research/retail_names.csv -> B3SoundHUDManager.cpp, 3 by a medium-confidence name confirmed by a neighbour, 4 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/Sound/Hud/B4SoundHUDManager.cpp |
| `src/b3/gamesource/Sound/Ps2/B3SoundManagerPS2.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3SoundManagerPS2.cpp, 1 by a medium-confidence name confirmed by a neighbour | [L] Revenge (SLUS_212.42) GameSource/Sound/Ps2/B4SoundManagerPS2.cpp |
| `src/b3/gamesource/Sound/Radio/Ps2/B3SoundCustomSoundTrackPS2.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3SoundCustomSoundTrackPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Radio/Ps2/B4SoundCustomSoundTrackPS2.cpp |
| `src/b3/gamesource/Sound/Traffic/B3SoundCrashedTraffic.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> B3SoundCrashedTraffic.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Traffic/B4SoundCrashedTraffic.cpp |
| `src/b3/gamesource/Sound/Traffic/B3SoundDoppler.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> B3SoundDoppler.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Traffic/B4SoundDoppler.cpp |
| `src/b3/gamesource/Sound/Traffic/B3SoundTrafficManager.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3SoundTrafficManager.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Traffic/B4SoundTrafficManager.cpp |
| `src/b3/gamesource/Sound/Traffic/B3SoundTrafficPass.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3SoundTrafficPass.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Traffic/B4SoundTrafficPass.cpp |
| `src/b3/gamesource/Sound/Traffic/B3SoundTrafficVehicle.cpp` | 6 | 6 function(s) named in research/retail_names.csv -> B3SoundTrafficVehicle.cpp | [L] Revenge (SLUS_212.42) GameSource/Sound/Traffic/B4SoundTrafficVehicle.cpp |
| `src/b3/gamesource/World/B3AIAggressionBehaviour.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3AIAggressionBehaviour.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4AIAggressionBehaviour.cpp |
| `src/b3/gamesource/World/B3AIArbitrator.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3AIArbitrator.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4AIArbitrator.cpp |
| `src/b3/gamesource/World/B3AIAvoidance.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3AIAvoidance.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4AIAvoidance.cpp |
| `src/b3/gamesource/World/B3AICar.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> B3AICar.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4AICar.cpp |
| `src/b3/gamesource/World/B3AIDriver.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3AIDriver.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4AIDriver.cpp |
| `src/b3/gamesource/World/B3AILane.cpp` | 5 | 5 function(s) named in research/retail_names.csv -> B3AILane.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4AILane.cpp |
| `src/b3/gamesource/World/B3BoostEffectParams.cpp` | 4 | 2 function(s) named in research/retail_names.csv -> B3BoostEffectParams.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4BoostEffectParams.cpp |
| `src/b3/gamesource/World/B3Burn.cpp` | 5 | 5 function(s) named in research/retail_names.csv -> B3Burn.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4Burn.cpp |
| `src/b3/gamesource/World/B3CrashCombo.cpp` | 5 | 1 function(s) named in research/retail_names.csv -> B3CrashCombo.cpp, 3 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4CrashCombo.cpp |
| `src/b3/gamesource/World/B3CrashPickup.cpp` | 3 | 1 function(s) named in research/retail_names.csv -> B3CrashPickup.cpp, 2 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4CrashPickup.cpp |
| `src/b3/gamesource/World/B3CrashRamp.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3CrashRamp.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4CrashRamp.cpp |
| `src/b3/gamesource/World/B3CrashScore.cpp` | 6 | 1 function(s) named in research/retail_names.csv -> B3CrashScore.cpp, 5 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4CrashScore.cpp |
| `src/b3/gamesource/World/B3EffectsManager.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3EffectsManager.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4EffectsManager.cpp |
| `src/b3/gamesource/World/B3EnvironmentManager.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3EnvironmentManager.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4EnvironmentManager.cpp |
| `src/b3/gamesource/World/B3PlayerCar.cpp` | 4 | 2 function(s) named in research/retail_names.csv -> B3PlayerCar.cpp, 1 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4PlayerCar.cpp |
| `src/b3/gamesource/World/B3PropManager.cpp` | 5 | 2 function(s) named in research/retail_names.csv -> B3PropManager.cpp, 3 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4PropManager.cpp |
| `src/b3/gamesource/World/B3RaceCar.cpp` | 10 | 7 function(s) named in research/retail_names.csv -> B3RaceCar.cpp, 3 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4RaceCar.cpp |
| `src/b3/gamesource/World/B3RacePosition.cpp` | 5 | 5 function(s) named in research/retail_names.csv -> B3RacePosition.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4RacePosition.cpp |
| `src/b3/gamesource/World/B3ReplayFrame.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3ReplayFrame.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4ReplayFrame.cpp |
| `src/b3/gamesource/World/B3ReplaySystem.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> B3ReplaySystem.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4ReplaySystem.cpp |
| `src/b3/gamesource/World/B3SplitTimeCheckpoint.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3SplitTimeCheckpoint.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4SplitTimeCheckpoint.cpp |
| `src/b3/gamesource/World/B3StartFinishLine.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3StartFinishLine.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4StartFinishLine.cpp |
| `src/b3/gamesource/World/B3StartPoint.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> B3StartPoint.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4StartPoint.cpp |
| `src/b3/gamesource/World/B3StaticTrack.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> B3StaticTrack.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4StaticTrack.cpp |
| `src/b3/gamesource/World/B3StopJunction.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3StopJunction.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4StopJunction.cpp |
| `src/b3/gamesource/World/B3StreamManager.cpp` | 4 | 4 function(s) named in research/retail_names.csv -> B3StreamManager.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4StreamManager.cpp |
| `src/b3/gamesource/World/B3TrafficAxle.cpp` | 1 | 1 function(s) named in research/retail_names.csv -> B3TrafficAxle.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficAxle.cpp |
| `src/b3/gamesource/World/B3TrafficLane.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3TrafficLane.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficLane.cpp |
| `src/b3/gamesource/World/B3TrafficLight.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3TrafficLight.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficLight.cpp |
| `src/b3/gamesource/World/B3TrafficParam.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3TrafficParam.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficParam.cpp |
| `src/b3/gamesource/World/B3TrafficSystem.cpp` | 2 | 1 function(s) named in research/retail_names.csv -> B3TrafficSystem.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficSystem.cpp |
| `src/b3/gamesource/World/B3TrafficSystemLoadAndRender.cpp` | 4 | 0 function(s) named in research/retail_names.csv -> B3TrafficSystemLoadAndRender.cpp, 4 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficSystemLoadAndRender.cpp |
| `src/b3/gamesource/World/B3TrafficValve.cpp` | 5 | 5 function(s) named in research/retail_names.csv -> B3TrafficValve.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficValve.cpp |
| `src/b3/gamesource/World/B3TrafficVehicle.cpp` | 6 | 4 function(s) named in research/retail_names.csv -> B3TrafficVehicle.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficVehicle.cpp |
| `src/b3/gamesource/World/B3World.cpp` | 5 | 4 function(s) named in research/retail_names.csv -> B3World.cpp, 1 placed between two of them by address contiguity (N2) | [L] Revenge (SLUS_212.42) GameSource/World/B4World.cpp |
| `src/b3/gamesource/World/B3WrongWayWall.cpp` | 3 | 3 function(s) named in research/retail_names.csv -> B3WrongWayWall.cpp | [L] Revenge (SLUS_212.42) GameSource/World/B4WrongWayWall.cpp |
| `src/b3/gamesource/World/Ps2/B3WorldPS2.cpp` | 2 | 2 function(s) named in research/retail_names.csv -> B3WorldPS2.cpp | [L] Revenge (SLUS_212.42) GameSource/World/Ps2/B4WorldPS2.cpp |
<!-- tu-table:end -->
| `src/b3/_unclassified/B3PhysicsManager_001BA280.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3OnlineJoinGamePage_003275A0.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3OnlineJoinGamePage.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_002F7C30.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013C620.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003EFC00.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundCrashedTraffic_00290900.cpp` | placed + proven 2026-10-23 (batch) | `[C]` name: retail tables (high); file `B3SoundCrashedTraffic.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003EFEC0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00344000.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E87A0.cpp` | placed + proven 2026-10-23 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002851A0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002851E0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00285220.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002854A0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundHUDManager_00285BC0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3SoundHUDManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00130980.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F610.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003600D0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00360170.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F4D0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F520.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F570.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F5C0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284FF0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284F50.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00285050.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002850F0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00130B80.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3Profile_0013A760.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (medium); file `B3Profile.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_002841F0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284390.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284B60.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284BD0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00284DA0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002859F0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00336EA0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00284D30.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003362B0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00283E70.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00283FA0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00283D20.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0033A2E0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_003389B0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00338A30.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033A7C0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_00338D60.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033A850.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00284400.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SoundHUDManager_002852A0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (medium); file `B3SoundHUDManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundHUDManager_00285340.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (medium); file `B3SoundHUDManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundHUDManager_002853F0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (medium); file `B3SoundHUDManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033A8F0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00338190.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00283A50.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C2BF0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F3F90.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3FogPS2_00240EF0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3FogPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TableComponent_0033F420.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3TableComponent.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3BehaviourCluster_00358780.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3BehaviourCluster.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3BehaviourCluster_003586B0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3BehaviourCluster.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00283B30.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E8C20.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001419D0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SparkRendererPS2_00263C10.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrailRenderPS2_002F3870.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3TrailRenderPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SparkRendererPS2_00263350.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3AICar_00143A80.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3AICar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3BehaviourInterpolate_00374240.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3BehaviourInterpolate.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3NetworkCarPhysics_00268730.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3NetworkCarPhysics.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3DebrisRendererPS2_002F42C0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3DebrisRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3AIArbitrator_0019DC40.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3AIArbitrator.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3CoronaRendererPS2_00306E00.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3CoronaRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3VehicleRendererRuntimePS2_002204C0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3VehicleRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SparkRendererPS2_002633A0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3AIAvoidance_001418F0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3Im3DPS2_00365510.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001D0A90.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003FE130.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00421E50.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00150E20.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00321780.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00268620.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3AIDriver_00145D10.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3AIDriver.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001D0E00.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0030EB10.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3SplitTimeCheckpoint_0015E5E0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3SplitTimeCheckpoint.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3ConvexHullCollide_002B9470.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3ConvexHullCollide.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00384FD0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00384FF0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0039AD20.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundManager_00384E70.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `GtSoundManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_001309C0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3EffectsManager_00262240.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/GtSoundManager_00385010.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `GtSoundManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3EffectsManager_002623F0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00135B50.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013A6D0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3DataLists_00251F40.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3SoundTrafficManager_00276A30.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3SoundTrafficManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00438840.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003F5800.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3RaceCar_00151C40.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00353C00.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002C20E0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtLogitechHeadset_002C25B0.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `GtLogitechHeadset.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003367B0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033B400.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003392C0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C32E0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0045B1F0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0022FEF0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0043CBD0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00309390.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficPhysics_002513F0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3TrafficPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003938B0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00467EC0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3TrafficSystem_00163DD0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3TrafficSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3DebrisRendererPS2_002F49A0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DebrisRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIAvoidance_00141890.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtInputManagerPS2Pad2_00214A00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputManagerPS2Pad2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0038C9E0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A380.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A4D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDComponent_0019F420.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033C8D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00157000.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0037E270.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0042C160.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00221420.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003C5EE0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F060.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001342F0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtInputManagerPS2Pad2_00214A40.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputManagerPS2Pad2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002172C0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtSoundRealVoice_003855F0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundRealVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003BB210.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00436B10.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00336640.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043F680.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004641C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0041E930.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00336DF0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BA780.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EC0C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FA4A0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00309690.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00228380.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00285A60.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3DataLists_00251920.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HardCodedRaceStageList_003EA090.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HardCodedRaceStageList.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003180A0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00240E20.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F8AA0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BAA60.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003E94C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00467E80.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00435620.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004215A0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00421060.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013A830.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CBBC0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00156E20.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00469AB0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EA1D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundHUDManager_00286C00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundHUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003192A0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00389E00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0021B830.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003734F0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001A0760.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00469960.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0033BB90.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00420D60.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00393740.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00386290.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F0700.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0039D480.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00323C60.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundCrashedTraffic_00290450.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashedTraffic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001D4E90.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FBB50.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003B8840.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FFD80.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042E310.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003B8930.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022D1E0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003906F0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00150280.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A2100.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003365E0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00452630.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EA0E0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundCrashManager_002810E0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00469920.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FDD00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00469810.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003ED8B0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00445850.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashAnalyser_00353990.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashAnalyser.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C5B80.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002F9CA0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00422F40.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038B530.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EAA60.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00199D90.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C2F00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00324E10.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00314720.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0028CB00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0019F350.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundDSPBlock_002FC070.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDSPBlock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineOpenLobbyPage_00396830.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineOpenLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003FBB00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundListenerManager_00384DE0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundListenerManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3DataLists_00251E10.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002840D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashActionDirector_001B2A00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashActionDirector.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtInputManagerPS2Pad2_002149C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputManagerPS2Pad2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00146A70.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkMessage_001A84A0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkMessage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A420.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StageLogic_00395970.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3StageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3DebugMipMaps_0035EF30.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DebugMipMaps.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00436880.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_003612C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundUtils_00386EE0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundUtils.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock_002173F0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputDevicePS2DualShock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtTextureCachePS2_002220E0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtTextureCachePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundPlayerCar_0028CA80.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundPlayerCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3DataLists_00251B90.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TableSelectComponent_003522C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TableSelectComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PopcornRendererPS2_003658E0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PopcornRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_0035FB60.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtTextureCachePS2_00222120.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtTextureCachePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock_00217010.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtInputDevicePS2DualShock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtNetworkHeadset_002C02F0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtNetworkHeadset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_0015A750.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtViewport_00211CC0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtViewport.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PageTextComponent_00379280.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PageTextComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDManager_001A1210.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CoronaRendererPS2_003073A0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CoronaRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtCollisionKDTree_003BE8D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtCollisionKDTree.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundDistPS2_002FD090.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDistPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A050.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundTurboModel_0028FAE0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTurboModel.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BehaviourOffset_002E3350.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourOffset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_0035FA40.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_00360460.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundESM_00287E20.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESM.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDComponent_0019F3D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtArray_002719B0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtArray.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineConnectingPage_00347120.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineConnectingPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HardCodedRaceStageList_003EA390.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HardCodedRaceStageList.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundAICar_0028B8D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundAICar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundGameModeManager_00289A50.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundGameModeManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashActionDirector_001B2760.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashActionDirector.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_00360620.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtByteStream_00374380.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtByteStream.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIControlData_00143F50.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIControlData.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3FlashText2dObject_00372090.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3FlashText2dObject.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_0035FAA0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027B770.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SkyDomeRendererPS2_0021DDD0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SkyDomeRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock_00216F10.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputDevicePS2DualShock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_0035F700.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EffectsManager_002620C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtPS2LibNet_0022E970.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtPS2LibNet.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3GraphicsManager_0019EA70.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3GraphicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_00360670.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtByteStream_003742C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtByteStream.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00339A60.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EffectsManager_002621D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_0035FB00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundESM_00287670.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESM.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034CED0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock_00216F80.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputDevicePS2DualShock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BuddyDisplayComponent_00366570.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3BuddyDisplayComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtNetworkPlayerManager_00236A00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtNetworkPlayerManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0012F460.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038B030.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00393690.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003924E0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038E2B0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00462190.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDManager_001A0370.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003FBBE0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038D630.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtPS2LibNet_0022E830.cpp` | placed + proven 2026-10-24 (batch) | `[C]` name: retail tables (high); file `GtPS2LibNet.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0035FBC0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003A6DE0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003A6E30.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F190.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F1E0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001A4150.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F9E0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F900.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0035F970.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002C1FC0.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00449F10.cpp` | placed + proven 2026-10-24 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003E8E00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00318100.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D0690.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042ECF0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00445730.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00137D50.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00338540.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00390380.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00436570.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00236B30.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F5C70.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00339F00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337F40.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00336730.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00386CF0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0041E9F0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004387C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00455050.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001AF420.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0035F670.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003B8450.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0041D0A0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundDistPS2_002FCFC0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDistPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00310180.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FC210.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Profile_001371B0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Profile.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_003383F0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0022FE10.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FC520.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FC5D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043B4A0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042AFC0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00439D00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00458900.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0030A990.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00364600.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004242C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00150410.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003787D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_003383A0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundDistPS2_002FCF00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDistPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026DA60.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00438DD0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C03D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003902C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0012F610.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C9210.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042E850.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043EE40.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00136E10.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0032EC90.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00384380.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042C020.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001AF3C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043C470.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00338960.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScoreBonus_00369270.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00285B00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BC540.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003366E0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0035FFD0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038F440.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003960A0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FB7C0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDPrimaryMessage_003D80E0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDPrimaryMessage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00228400.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0026CAB0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00335F60.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C70B0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00442470.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundVoiceManager_00388B30.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVoiceManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficParam_00161310.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficParam.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0038BCE0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00390320.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C21F0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042C090.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficSystem_001631F0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3TrafficSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00235D90.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0035FD80.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00430E30.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00442510.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundAICar_0028BA20.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundAICar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3FogPS2_00240FD0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3FogPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001A0560.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038B380.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineConnectingPage_003471E0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineConnectingPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00213F00.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BAB10.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundStream_00385F20.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundStream.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00370F30.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F6EB0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004372B0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtNetworkPlayerManager_002366E0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtNetworkPlayerManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00222260.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BAE10.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLogitechHeadset_002C2840.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtLogitechHeadset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00389700.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022C780.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038C830.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineSelectLoginPage_00349280.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineSelectLoginPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00214380.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BACA0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3ChatDisplayComponent_00332240.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ChatDisplayComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003934D0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00421190.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00438C50.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtNetworkPlayerManager_00235300.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtNetworkPlayerManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026BCA0.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D7100.cpp` | placed + proven 2026-10-24 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock_00216E40.cpp` | placed + proven 2026-10-24 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputDevicePS2DualShock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0022F510.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00420E20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F5A20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtInputManagerPS2Pad2_002147E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputManagerPS2Pad2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0013A3E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C2960.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004413C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00336840.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002847A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FC2E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDManager_001A0800.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003A72E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002F4F10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043FB60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00373100.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00469550.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013A440.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C5310.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042E020.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004423E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00137F20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00338260.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002E70E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002F9D00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundVoiceManager_00388AF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVoiceManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00392040.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PropPhysics_001BE8F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PropPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0013A160.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013A4A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EABD0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042E5D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00469BF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficAxle_0015FA60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficAxle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003359F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00467260.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002FB240.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003E7A50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00389C50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3InputManager_0022BAE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0014D280.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A89A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineOpenConnectionState_00346200.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineOpenConnectionState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003EBEE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00431F90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineNewsState_003694C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineNewsState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundESM_002882D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESM.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003BA6A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00467350.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042C1A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004645F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038A4A0.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038E220.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038EBA0.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00392450.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00270E10.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0043DB70.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00399BA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00430ED0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PageTextComponent_003795C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PageTextComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C6160.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A86C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00237200.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00437B50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0015E720.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FF1D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004652B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00339650.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00351E40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00434FF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundManager_0028AD10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3SoundManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00318340.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundTrafficVehicle_0027A5F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTrafficVehicle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003E9030.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F86B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003904F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045A050.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00237270.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00420BB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004684A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundTurboModel_0028FE70.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTurboModel.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0013AF40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00388FA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004656D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AICar_00143B10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003CC6E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLoginToLobbyState_0034B9D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLoginToLobbyState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00438F30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0012F160.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00456500.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00390550.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Im3DPS2_003655A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0038C070.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042F790.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundRaceCar_0028DD80.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundRaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0013B0E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D46A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00135BE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F66F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3MyBurnoutRewardsHeadlinesPage_003F0B30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MyBurnoutRewardsHeadlinesPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004683A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013A2E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00240B70.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003905B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003E8EA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004458D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLogitechHeadset_002C2600.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLogitechHeadset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00156EF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EB500.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022D400.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FCC10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtInputManagerPS2Pad2_00214870.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputManagerPS2Pad2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00272C90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00240C00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022B9E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDPrimaryMessage_003D8130.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDPrimaryMessage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003E9F90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004538E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Score_0015ADB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00227360.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FC470.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HardCodedCrashStageList_003E9150.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HardCodedCrashStageList.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002B7230.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3MyBurnoutRewardsState_003EC240.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MyBurnoutRewardsState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C22A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundGameModeManager_00289B30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundGameModeManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00285770.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtViewport_00211C30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtViewport.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002C2130.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00135DA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F65D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004546B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SunRendererPS2_0024D390.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SunRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BloomPS2_00264920.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BloomPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0030AAE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FC650.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CameraAttribs_002F8BD0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CameraAttribs.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0030E930.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundSkidModel_0028ED30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundSkidModel.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003CCFB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundRaceCarManager_002EEFE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundRaceCarManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002C0390.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SparkRendererPS2_00263F80.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0024B2A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PopcornRendererPS2_00366050.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PopcornRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScrapeSystem_00375AA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScrapeSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00435AB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043DC30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0033FF10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SplitTimeCheckpoint_0015E650.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SplitTimeCheckpoint.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StartFinishLine_0015E7C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StartFinishLine.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00427080.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StaticTrack_003329A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StaticTrack.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RadialBlurPS2_002FAD90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RadialBlurPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDImpactTime_003D6AB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDImpactTime.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004277C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022DA60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004469E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013A280.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013A1C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013A220.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013A500.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038D550.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002142A0.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00240A70.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3DirectionalBlur_00426030.cpp` | placed + proven 2026-10-25 (batch) | `[C]` name: retail tables (high); file `B3DirectionalBlur.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00427A30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00336B20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00336C20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00336D00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0035FE20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3InputManager_0022CB40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0035FEF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038B160.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001A3AA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0039D530.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EF920.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0012FB50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00302C10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036C370.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00375D90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00467440.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EA580.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundDoppler_002F4DC0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDoppler.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TextComponent_00351A90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TextComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CoronaRendererPS2_00306D90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CoronaRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00155A40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022C050.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDPrimaryMessageHandler_003D5510.cpp` | placed + proven 2026-10-25 (batch) | `[C]` name: retail tables (high); file `B3HUDPrimaryMessageHandler.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003FA510.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00378080.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00399600.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EAF00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EC540.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00446A40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00453DC0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043C760.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C7AB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundWave_00389580.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundWave.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003393C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00372E00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003E9B40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004230D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E7340.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScrollBarComponent_0041EAF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScrollBarComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_00280FC0.cpp` | placed + proven 2026-10-25 (batch) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0022C1B0.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00163E90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_003380E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002348A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3RewardImageComponent_003F6020.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RewardImageComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00457130.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004571F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0012F240.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002B7110.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003B89C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00339BC0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001D3EE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036A510.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00385090.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00392A30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00421F10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00424750.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004566E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00461CD0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3RaceCar_00150F20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0030E340.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036A230.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036A3A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3BuddyDisplayComponent_00367040.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BuddyDisplayComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0038A5D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038DA00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038E600.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038F740.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003B7830.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CD080.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042B700.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00456470.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00466670.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00313650.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00213E20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00338440.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EA2D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00434CF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StreamedTrackData_0015F200.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrackData.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_00351390.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00314850.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00288C20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002F72A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00421380.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043E170.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineConnectingPage_00347440.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineConnectingPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundRaceCar_0028CD60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundRaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIAvoidance_00140850.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00468680.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Score_0015ACC0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ReplaySymbolComponent_003A6840.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ReplaySymbolComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026CBE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtNetworkHeadset_002BF9A0.cpp` | placed + proven 2026-10-25 (batch) | `[C]` name: retail tables (high); file `GtNetworkHeadset.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0042FA60.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0038FF70.cpp` | placed + proven 2026-10-25 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0037B6C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003AB2E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F01B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3RadialBlurPS2_002F9EC0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RadialBlurPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0027D240.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004661C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3BuddyReadMailComponent_003724E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BuddyReadMailComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003D2EA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00284650.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00155280.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00284970.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLogitechHeadset_002C2420.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLogitechHeadset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00430720.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045FFF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004695A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00469650.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OfflineStageLogic_00395580.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OfflineStageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0023B6E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00396670.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F5940.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00435DB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TableComponent_0033FB60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TableComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OfflineStageLogic_003956A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OfflineStageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ConnectionAnimationComponent_003524C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ConnectionAnimationComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0022D760.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002C21C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003792C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00396D30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003971C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00456550.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045A240.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004600B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtPS2LibNet_0022E9D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtPS2LibNet.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0038CA60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002870D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDComponent_0019F6A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0022B850.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0039B250.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045FB10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashCombo_00363A40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuChoices_0030BE20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuChoices.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00355A90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00379380.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3ShadowRendererPS2_003039A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ShadowRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001BE990.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003713A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtNetworkPlayerManager_002367F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtNetworkPlayerManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundPlayerCar_0028C780.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundPlayerCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDTimer_003C2640.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3HUDTimer.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0021C010.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0034AE10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtInputDevicePS2Keyboard_00303F10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputDevicePS2Keyboard.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00436140.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00463410.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundManager_0028ADD0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00378990.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundCrashedTraffic_00290320.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashedTraffic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002842A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003E9E50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundHUDManager_00287240.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundHUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuChoices_0030D1B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuChoices.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003235D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045BDD0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0023BD20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0032CF60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0032D080.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004493F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AILane_001478C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0036F3E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StreamedTrackData_0015F0D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrackData.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003181E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FBC20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundCrashManager_00282930.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0022FC60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002844A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00314CC0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0012F330.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0012F4E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashCombo_00363870.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLoginToLobbyState_0034BC30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLoginToLobbyState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuInput_0021A9B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuInput.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C4C70.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00431050.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00435F50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundRaceCar_0028CE30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundRaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00435CC0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033A460.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0022FF90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00230480.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002515A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038AB40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00436350.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00436460.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0028BF90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045B460.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00461F40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundESMStruct_002FAFB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESMStruct.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MyBurnoutRewardsHeadlinesPage_003F0870.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3MyBurnoutRewardsHeadlinesPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026D970.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00380F10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003B8750.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00338700.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003AFCE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TitleScreenComponent_00343720.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TitleScreenComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002709D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00322620.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00351F00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00377D30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003900E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A5E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StaticTrackPS2_0021D550.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StaticTrackPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00285560.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003B8550.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0044A0F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00367E70.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FDF90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CCEE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3NetworkCarPhysics_00268790.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkCarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00430000.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004418F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00463070.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDCrashCombo_003D7190.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDCrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Burn_0014E3A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00425330.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundDistPS2_002FD0E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDistPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00214050.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CA5D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundStream_00386130.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundStream.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SparkRendererPS2_002637F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0023B500.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00379010.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00379450.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C0D90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashAnalyser_00354760.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashAnalyser.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0019E760.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00270880.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A70D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003B6280.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042FE90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0032B3D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003865A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042BD70.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00434BF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00449FC0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004389B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00230C50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033B1B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003FAA50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C4150.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00464F70.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00391B80.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00439E00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashActionDirector_001AE500.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashActionDirector.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StreamManager_003C3430.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CameraAttribs_002F8AA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CameraAttribs.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00283920.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043E1F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013C170.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C78A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045A850.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3MessageBoxComponent_0032B530.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MessageBoxComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundRaceCar_0028DBB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundRaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003A87F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002514C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033BE00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashCombo_00363930.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDPrimaryMessageHandler_003D55B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDPrimaryMessageHandler.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_00309EB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_00309D20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0031F970.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013A8A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013AA10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013AB80.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00344310.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00422E40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042BEA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundCrashedTraffic_002901D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashedTraffic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C5BF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundRealVoice_003856D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundRealVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C6DF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00314A30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003A8A90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLogitechHeadset_002C2270.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLogitechHeadset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundPlayerCar_0028CB60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundPlayerCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLobbyPage_003139B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003E9CB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficSystemLoadAndRender_003093E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficSystemLoadAndRender.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0012EF80.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A6900.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042C440.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004636E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003137B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_0030A130.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003F38C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AIAvoidance_0013E790.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00434DD0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDEscapeDistance_003D8BC0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3HUDEscapeDistance.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficVehicle_00171A00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficVehicle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundVoiceManager_00389100.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVoiceManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003F03D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3ReplaySystem_00155020.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ReplaySystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock_00217070.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputDevicePS2DualShock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDManager_001A00B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineSelectLoginPage_003476B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineSelectLoginPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineSelectPersonaPage_003404B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineSelectPersonaPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficParam_00160C30.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficParam.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehicleRendererRuntime_00220DB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleRendererRuntime.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ReplaySymbolComponent_003A6A50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ReplaySymbolComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDTakedowns_003A25F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3HUDTakedowns.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ChatDisplayComponent_00332610.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ChatDisplayComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashCombo_00363C90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineSelectLoginPage_00348D10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineSelectLoginPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StaticTrackData_0015E8E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StaticTrackData.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0030CEC0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0032B2C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficLight_00266010.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficLight.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00270AC0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0027EC10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0028B380.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00332E00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036C860.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundRealVoice_00385B10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundRealVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003EB670.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EBA20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FE1F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0041E3C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00316210.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLobbyState_0030F010.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GTMemoryDevicePS2_MC2_003096E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GTMemoryDevicePS2_MC2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSphereTree_0035E030.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSphereTree_0035CA00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSphereTree_0035D250.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00302D20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00315CE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0034B050.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036CB20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036CDE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036D0A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036D360.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036D620.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036F650.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003665B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003778D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0037C570.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00396A90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00397280.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003978C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00397FA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A5D10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A8BF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003AB0A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003AE920.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C1090.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BC610.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C1E00.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00398DE0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C8E20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CCA70.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FC700.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CA6B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D11D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EB0F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EC7E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F2350.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F3400.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0041FAD0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00422960.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042CD60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004328C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00433A70.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00436C90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004376F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004381B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00440A20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00440E20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00456E60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045A9F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045BC50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C1390.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundVirtualVoice_00387A90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundVirtualVoice_003884D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashCombo_00362F60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PauseState_003428D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PauseState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00378240.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003530F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D2AA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043E320.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038CBB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00422070.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundRaceCarManager_002ED690.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundRaceCarManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RaceCarPhysicsAttribs_00252800.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RaceCarPhysicsAttribs.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00271A80.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0015CB10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00424480.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00437370.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficLane_0015FC70.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficLane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineConnectingPage_00346DF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineConnectingPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003E6F50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003E6F90.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0033B710.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StopJunction_002B56B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StopJunction.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtScreenCentre_002210A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtScreenCentre.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003835C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00323A10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineGameCreatePage_00327310.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineGameCreatePage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0045BF40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004471A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0037E440.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficSystem_00166DB0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00442CF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042C2A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PhysicsManager_001B3EA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002BD7F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00422CA0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00465430.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038BB70.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0026F930.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0021ADF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001D4680.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043E000.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045CA50.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StaticTrackPS2_0021D770.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StaticTrackPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033B5B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033B050.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0028B220.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002C12B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337C40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033A9A0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_003610B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033B9D0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Burn_0014DEF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtIntersection_002BF2E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtIntersection.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004699B0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E7150.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineRoadRageRaceLogic_0038EDF0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineRoadRageRaceLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0030D6E0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDTakedowns_003A2510.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3HUDTakedowns.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00228070.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrailRenderPS2_002F3A60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrailRenderPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_0015AB10.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrackRendererRuntimePS2_0026B1C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrackRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dRendererPS2_0021A4F0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00324F40.cpp` | placed + proven 2026-10-25 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3MenuPageManager_0030D5C0.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuPageManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtInputManagerPS2Pad2_00214A80.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputManagerPS2Pad2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundTrafficManager_00276C20.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTrafficManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficParam_00160A60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficParam.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundListener_0028AB60.cpp` | placed + proven 2026-10-25 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundListener.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026DE80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Burn_0014E500.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00234FF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013B580.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AIAggressionBehaviour_0032EE00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAggressionBehaviour.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00313580.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0031FB10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00237120.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002310B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00231850.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00150300.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3GraphicsManager_0019E8C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3GraphicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ControllerMappingPS2_0012F970.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3ControllerMappingPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ControllerMappingPS2_0012FA40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3ControllerMappingPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RadialBlurPS2_002FA3C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RadialBlurPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00240660.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundSkidModel_0028E210.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundSkidModel.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004651E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLinearMalloc_002F9DD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLinearMalloc.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtTextureCachePS2_00221580.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtTextureCachePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AICar_00143E80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3GamePS2_001D45B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3GamePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026F860.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Burn_0014DDE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026E280.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EnvironmentManager_002BC380.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EnvironmentManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_0015AC00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0038EC30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0028B160.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002303C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3DebugManager_001308B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DebugManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SkyDomeRendererPS2_0021E3D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SkyDomeRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00284820.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AIArbitrator_0019D5E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIArbitrator.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ReplayFrame_00154BD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ReplayFrame.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_00156260.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Burn_0014E2D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PlayerCarPhysics_001BDE50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00335E90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00301220.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002C1EC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002350D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00231A20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00231920.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00335DE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026F410.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3InputManager_0022C810.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehiclePhysicsAttribs_00252050.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehiclePhysicsAttribs.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BehaviourFlyAround_002ED310.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourFlyAround.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dRendererPS2_00219CA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D2FA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00217200.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00199E00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtTextureCachePS2_00222030.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtTextureCachePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00147810.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficValve_00266740.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficValve.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_00280860.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ReplayFrame_00154D20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ReplayFrame.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3DebrisRendererPS2_002F4650.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DebrisRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundESMManager_002FAE90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESMManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SparkRendererPS2_00264040.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuPageManager_0030DD70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3MenuPageManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0021AD60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00338AB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00338B40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Burn_0014E1C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00230570.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SparkRendererPS2_002640E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundTrafficManager_002772D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTrafficManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004360B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0028AC80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00312210.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLobbyPage_003122A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PropManager_002B71A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3PropManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026E1A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFSM_002177C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFSM.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDManager_001A0020.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002C1C80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Gt2dObjectText_001D66A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectText.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLobbyPage_003113C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SkyDomeRendererPS2_0021DBD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SkyDomeRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00240C90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002370A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3NetworkManager_0026E380.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00230EE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDManager_001A0240.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrackRendererRuntimePS2_0026A1C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrackRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002516C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022D970.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3GraphicsManagerPS2_002253C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3GraphicsManagerPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ConvexHull_002BA3A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ConvexHull.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027EE40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00145E70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E7250.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0014E600.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundDoppler_002F4EA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDoppler.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3WrongWayWall_0019B6E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3WrongWayWall.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027F040.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027EFD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027EEC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3WrongWayWall_0019D440.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3WrongWayWall.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SkyDomeRendererPS2_0021DB50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SkyDomeRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026DDC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026DD00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D2EE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0021E350.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00136F30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E72D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Burn_0014DFF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StreamedTrack_003012D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrack.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLogitechHeadset_002C2540.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLogitechHeadset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDBoostBar_001A56D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDBoostBar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026E130.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFSM_00217750.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFSM.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D3670.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026F0F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuChoices_0030CE20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuChoices.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AICarPhysics_001D2D10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dFrameHierarchy_001D5D60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFrameHierarchy.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00423DC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Gt2dRendererPS2_00217880.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtPS2LibNet_0022E900.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtPS2LibNet.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033BC20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundESMManager_002FAF50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESMManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00469700.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C9BF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CBD20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003242F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0037C820.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0033C000.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineRetrieveConfigsPage_00349E00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0037FBB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F68E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00422410.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00424C40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003774D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045F630.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00345D00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BBDC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022F220.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0037CF00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0037C250.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00397C90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00341D30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00398850.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00391820.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00199EB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0019B380.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00162BF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0019A2E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00228160.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003963E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00398B80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00378C00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BE040.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00234DB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0033FCF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003E7850.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0033F950.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00398270.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00398470.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00433370.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022F320.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003B8C70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00392750.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001578E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001D3A60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00427560.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003999E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00433560.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00432280.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0039EDB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003907F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0037A360.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004278B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003986C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C2CD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BB2F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0041E260.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0013AEF0.cpp` | placed + proven 2026-10-26 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013B090.cpp` | placed + proven 2026-10-26 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_003916D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00342E10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0014E670.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AILane_00146180.cpp` | placed + proven 2026-10-26 (batch) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3TrafficLane_00160520.cpp` | placed + proven 2026-10-26 (batch) | `[C]` name: retail tables (high); file `B3TrafficLane.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_0039EF40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0039EC90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00433250.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00432160.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00396900.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002E7BA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0026BD50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0021AB40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00386B30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00157060.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BC240.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F0ED0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0033D650.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001D6C40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003E9580.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0041D2D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00376470.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00423E20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00399040.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003786D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00386A60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00375300.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F6420.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0012F720.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0012F850.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0012FC30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3ControllerMappingPS2_0012FE90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ControllerMappingPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00135F30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00136110.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00137C40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AICar_00142200.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00137E00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Profile_001383B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Profile.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Burn_0014E060.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0013B260.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AsyncDataLoader_0013CE20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AsyncDataLoader.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AsyncDataLoader_0013CFA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AsyncDataLoader.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIDriver_001446B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIDriver.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIDriver_00144810.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIDriver.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_0015A9C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PlayerCar_00150640.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3PlayerCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_0015AE40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficLane_001602F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficLane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AITarget_00149B50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RaceCar_00151780.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RacePosition_00154230.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RacePosition.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0019F240.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDManager_001A03A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDManager_001A09A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDScore_001A37A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3HUDScore.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_00157B00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_00157D50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehiclePhysics_001CFC00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehiclePhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00391E00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PhysicsManager_001B89D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PhysicsManager_001B8D20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001D3D70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtInputManagerPS2Pad2_00214B70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputManagerPS2Pad2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D30B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D36E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D3850.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtInputManagerPS2Pad2_00214610.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputManagerPS2Pad2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3GamePS2_001D4020.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3GamePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dRendererPS2_002178E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dRendererPS2_00217A20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dRendererPS2_00217D40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PhysicsManager_001BAA30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026D1E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026CCC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectText_001D6D60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectText.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtID_0021AEF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtID.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtNetworkHeadset_002BFDA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtNetworkHeadset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtNetworkHeadset_002BFCC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtNetworkHeadset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/vibuf_00325E10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `vibuf.c` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/vibuf_003268E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `vibuf.c` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StreamedTrackPS2_0021C590.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrackPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003361C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0033B4B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00336320.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00336950.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00338C70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033A160.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033C740.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectItalicText_0033CF80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectItalicText.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dScene_001D7960.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dScene.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dFont_001D7A70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFont.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dFont_001D80A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFont.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dFont_001D8150.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFont.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dFont_001D8210.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFont.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectImage_001D5FB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectImage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectImage_001D6080.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectImage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dScene_001D7560.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dScene.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dScene_001D7580.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dScene.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dScene_001D78F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dScene.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectImage_001D60B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectImage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectImage_001D6070.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectImage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00139F20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00139790.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001D4EC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Gt2dFrameHierarchy_001D4EE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFrameHierarchy.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dFrameHierarchy_001D4F20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFrameHierarchy.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dFrameHierarchy_001D4F60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFrameHierarchy.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dFrameHierarchy_001D4F80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFrameHierarchy.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dFrameHierarchy_001D5DC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFrameHierarchy.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dFont_001D7B90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFont.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectTable_0033F0E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectTable.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectTable_0033DC20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectTable.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TableComponent_0033F8B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TableComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034CF90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003541D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashAnalyser_003542B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashAnalyser.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSphereTree_0035DF60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_00350900.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_00350830.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00350CF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Gt2dFont_001D7E10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dFont.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtUnicodeUtils_0035EFA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtUnicodeUtils.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_003602A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_00360370.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_00360560.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_003604C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_003606E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_00360800.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineBuddiesMenuPage_0036C250.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineBuddiesMenuPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineBuddiesMenuPage_0036C2E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineBuddiesMenuPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineBuddiesMenuPage_0036C500.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineBuddiesMenuPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineBuddiesMenuPage_0036C590.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineBuddiesMenuPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineBuddiesMenuPage_0036C620.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineBuddiesMenuPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineBuddiesMenuPage_0036C6B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineBuddiesMenuPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_00361510.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_00361340.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_00350D90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_00350E30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_00350ED0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScoreBonus_00368CB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScoreBonus_00368D60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScoreBonus_003683E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScoreBonus_00369120.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundListener_00384650.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundListener.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundListener_00384700.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundListener.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundListener_00384980.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundListener.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundBankManager_00383F60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundBankManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundRealVoice_00385540.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundRealVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundVirtualVoice_003878D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundVirtualVoice_00387300.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundVirtualVoice_00387360.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundUtils_00386F40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundUtils.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundUtils_00386E70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundUtils.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TextureCollectionPS2_00378EA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TextureCollectionPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BehaviourInterpolate_003738D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourInterpolate.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00387240.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundWave_003894D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundWave.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/OnCrashStart__25CB3OfflineSingleRaceLogicFP17CB3RaceCarPhysicsP17CB3CrashStartInfo.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/StartReplay__25CB3OfflineSingleRaceLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BehaviourInterpolate_003741A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourInterpolate.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkReplayMessage_00375520.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkReplayMessage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundBankManager_00384460.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundBankManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OfflineRoadRageLogic_0038C5D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OfflineRoadRageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RadialBlur2dObject_003D30E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RadialBlur2dObject.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDBackground2dObject_003CD820.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDBackground2dObject.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDDPad2dObject_003D6BA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDDPad2dObject.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundManager_00385160.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003767E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00396860.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3FlashText2dObject_00372010.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3FlashText2dObject.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00399E20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CAA40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CCE00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003E9C00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EA7F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EA9D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D0C80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EA940.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EAD60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EADD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Gt2dBezierCurve_0041E1B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dBezierCurve.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dBezierCurve_0041E120.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dBezierCurve.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/ezNetCnf_release_lib_libezctl_00345740.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `ezNetCnf_release.lib libezctl.o` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/ezNetCnf_release_lib_libezctl_00345940.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `ezNetCnf_release.lib libezctl.o` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/ezNetCnf_release_lib_libezctl_003459D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `ezNetCnf_release.lib libezctl.o` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/ezNetCnf_release_lib_libezctl_00345A60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `ezNetCnf_release.lib libezctl.o` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/ezNetCnf_release_lib_libezctl_00345C20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `ezNetCnf_release.lib libezctl.o` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RaceCarPhysics_001BFC70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RaceCarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003E92D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003E93B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C5A80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042E970.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042E9F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042B5F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042DA70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00427720.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3DirectionalBlurPS2_00426920.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DirectionalBlurPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034CEF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0042EA70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042EAF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042EB70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042EBF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042EC70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00436270.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00438910.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043C880.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043C8F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00235960.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00235A80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043FF50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043CC00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043DA70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042BC90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00442900.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002349A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00234C40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3DataLists_00251CB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DataLists.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SkyDomeRendererPS2_0021DE50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SkyDomeRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundHUDManager_002858C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3SoundHUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3GraphicsManagerPS2_00227A20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3GraphicsManagerPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SparkRendererPS2_002636B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficValve_002662E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficValve.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3InputManager_0022C610.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3InputManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficValve_00268490.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficValve.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002365A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0023F1B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundGameModeManager_00288F70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundGameModeManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrackRendererRuntimePS2_0026B7B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrackRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026C7A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundRaceCar_0028D660.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundRaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026F150.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026F2B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00270D00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundSkidModel_0028EBE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundSkidModel.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/vibuf_00326220.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `vibuf.c` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/vibuf_00326770.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `vibuf.c` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundTrafficManager_00276B00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTrafficManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundTrafficVehicle_00278D20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTrafficVehicle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002BD560.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3BehaviourTrackSide_002F5BD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3BehaviourTrackSide.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337870.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StreamedTrack_003029B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrack.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StreamedTrack_00302AE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrack.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337B10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337F90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033A360.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033AD10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033BC80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00335FD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003369F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLogitechHeadset_002C26D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLogitechHeadset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundDSPBlock_002FBCD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDSPBlock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLobbyPage_003120E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectItalicText_0033D770.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectItalicText.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034D1F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectTable_0033DD30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectTable.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectTable_0033DE40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectTable.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034E2A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TableComponent_0033F260.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TableComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashCombo_00363B10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BuddyDisplayComponent_00366440.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3BuddyDisplayComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScoreBonus_00368530.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0038BD30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038BEB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OfflineRoadRageLogic_0038C6B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OfflineRoadRageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0038F570.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00395060.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D0B70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D1090.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D1650.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundRealVoice_00385A00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundRealVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundStream_00386790.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundStream.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OfflineStageLogic_00395310.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OfflineStageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StageLogic_00395800.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0039C1C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A3D30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EC3E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043F460.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F8580.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00442720.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F8700.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00445530.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C47C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C98D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PlayerCameraStatePlayer_00447000.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCameraStatePlayer.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00447370.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00421700.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004251E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00449050.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0044A380.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042F650.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00432410.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0044CB20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00453560.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00454AC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00461D60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00456D30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SkyDomeRendererPS2_0021E100.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SkyDomeRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0045BB10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004641F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00466850.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00466DA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022F660.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00236EA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00235DF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtNetworkPlayerManager_00236C50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtNetworkPlayerManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtPS2LibNet_0022EDE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtPS2LibNet.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0023BE90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0023E3E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0023E6E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0028D830.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0023EB70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00240730.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundESM_00287710.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESM.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026CD90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026CFC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026DF70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_002714C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_00271730.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027A920.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0028AF10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0026BEE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0026C190.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StreamedTrack_00301C80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrack.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001D5CE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Gt2dObjectText_001D65A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectText.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectText_001D63F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectText.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectItalicText_0033CE80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectItalicText.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectItalicText_0033CCD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectItalicText.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_00157FA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AICarPhysics_001D2790.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLinearMalloc_002F9DA0.cpp` | placed + proven 2026-10-26 (batch) | `[C]` name: retail tables (high); file `GtLinearMalloc.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3StopJunction_002B5970.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StopJunction.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtNetworkHeadset_002BF7F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtNetworkHeadset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E7480.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E7D20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00316BE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtNetworkHeadset_002BFE70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtNetworkHeadset.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuChoices_0030C2C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuChoices.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuChoices_0030BFF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuChoices.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00316640.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00321870.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00337D60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00339480.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034D040.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00339C50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00339F50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034D6F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034D910.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033AAB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033C390.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_003509C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_00350B60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_00351410.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ChatDisplayComponent_00331DE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ChatDisplayComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_003515D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineSelectLoginPage_003490C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineSelectLoginPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ChatDisplayComponent_00331FE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ChatDisplayComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/ezNetCnf_release_lib_libezctl_003457B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `ezNetCnf_release.lib libezctl.o` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashAnalyser_00354B20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashAnalyser.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0033AE60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashCombo_00363F10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00338EA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00335450.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3DirectionalBlurPS2_00426B70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DirectionalBlurPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RadialBlurPS2_002FA900.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RadialBlurPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Im3DPS2_00365370.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Im3DPS2_00365230.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScoreBonus_00368EF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00369F80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036A680.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036F170.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineReadMailMenuPage_00372BA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineReadMailMenuPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Update__30CB3OnlineBuddiesSearchMenuPageFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundStream_00386410.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundStream.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PlayerCameraStateInactive_002E80A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCameraStateInactive.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CameraEditor_00374550.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CameraEditor.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundBankManager_003840C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundBankManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundUtils_00386FD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundUtils.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003914A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PromptBarComponent_0038AD80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PromptBarComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0039C2C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00377E30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0037A1B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00371420.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OfflineRoadRageLogic_0038C3F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OfflineRoadRageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00371940.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineStageLogic_00390990.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineStageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00389830.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C49B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00383830.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C58A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CB420.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDTimer_003C26F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3HUDTimer.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003AB640.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CB630.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CB900.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D1AA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C43E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SatNavComponent_003AAE30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SatNavComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashScore_003CD610.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3CrashScore.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MemoryManager_003E7AD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3MemoryManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003E9750.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EDAD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D0D80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F7550.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00430840.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00430C10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F7150.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F7350.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00431D80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D2630.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D23A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004365B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D2160.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004248A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00424A60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00430570.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043C5B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043F850.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043FD60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3DebugManager_00130030.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DebugManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00442580.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnePlayerStage_00134A20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnePlayerStage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0044C960.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Profile_00137FE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Profile.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficLane_0015FFA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficLane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDBoostBar_001A45F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3HUDBoostBar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004547C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficParam_00161590.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficParam.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficSystem_001632C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3TrafficSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficSystem_00165DF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PhysicsManager_001B41D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00281890.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PlayerCarPhysics_001BB250.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3PlayerCarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PlayerCarPhysics_001BAD40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0023B000.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3VehiclePhysicsAttribs_00252100.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehiclePhysicsAttribs.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026C480.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0023EDD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StreamedTrackPS2_0021C120.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrackPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundDistPS2_002FC1E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDistPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0030CA10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PlayerCameraManager_002E7810.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCameraManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026F4C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00301D50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3NetworkManager_00270ED0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00315560.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00314E50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00235F80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002311D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00318A80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00318F50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineGameCreateState_003248F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineGameCreateState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002C09A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034E3D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineGameCreatePage_00326FC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineGameCreatePage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashCombo_00361900.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineJoinGamePage_003277E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineJoinGamePage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_00350F80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineSelectPersonaPage_003418F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineSelectPersonaPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineJoinGamePage_0032AAB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineJoinGamePage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0036E820.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0032CC00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3BuddyReadMailComponent_00372600.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BuddyReadMailComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundVirtualVoice_00388080.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0037F640.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00399130.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0039D5C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0037B770.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0039D900.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038E6F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038DAF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C0950.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C7B60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00389EE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038B5B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C7E80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AILane_00146AC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/CacheGameParams__26CB3OnlineOptimatchMenuPageFi.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehicleDeform_003E2970.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleDeform.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003F4200.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F4600.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0041FE00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004201F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00420510.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00430210.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00433720.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00432560.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00434550.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00423F30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F99F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004239F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004313E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003ECCD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003ED0D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003ED460.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004356A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PhysicsManager_001B82F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PlayerCarPhysics_001BD020.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003F2FE0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PhysicsManager_001B3F90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDManager_001A0AF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtNATDataManager_00231B30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtNATDataManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundTrafficManager_00277360.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTrafficManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00146DB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00456900.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3World_0019A950.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/ResetControllerDeadTime__20CB3ControllerMappingFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GetControllerDeadTime__20CB3ControllerMappingFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/PadIsValid__20CB3ControllerMappingFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/IsTurnBased__25CB3OfflineCrashPartyLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/IsCrashType__25CB3OfflineCrashPartyLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GetOfflineGameModeType__26CB3OfflineSingleCrashLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GetOnlineGameModeType__26CB3OfflineSingleCrashLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/CanAdjustCameras__26CB3OfflineSingleCrashLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/UseTakedownCamera__20CB3OfflineStageLogicFP10CB3RaceCarP10CB3RaceCar.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GetAIMode__13CB3StageLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GetCheckpointMarkerFlags__13CB3StageLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GetScoreModeFlags__13CB3StageLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/SetFirstResultsPageContinuePressed__13CB3StageLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/SetSecondResultsPageContinuePressed__13CB3StageLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GetTotalScore__13CB3StageLogicFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/IncrementTotalScore__13CB3StageLogicFf.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AITarget_0014D410.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Prepare__28CB3CrashPresentationDirectorFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Construct__28CB3CrashPresentationDirectorFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GetNumSplitTimeCheckpoints__11CB3GameDataFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004502A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Score_00156080.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3DebugManager_00130740.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DebugManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00135AA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/_CalcDifficultyIndexQSortCallback__11CB3AIDriverFPCvPCv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AITarget_00149140.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AITarget_00149E80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AITarget_0014A940.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Burn_0014DDB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Burn.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_001553A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3World_0019B6C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3World.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3World_0019B6D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3World.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0019E990.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AICarPhysics_001D2940.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AICarPhysics_001D2950.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0022D2A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00235BA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtPS2LibNet_0022E960.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtPS2LibNet.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/TCPCreate__12CGtPS2LibNetFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtPS2LibNet_0022E6A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtPS2LibNet.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dRendererPS2_00219C90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_00156120.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_001560D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_00156170.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Strings_00271A20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Strings.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Destruct__17CB3SpatialTriggerFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Prepare__17CB3SpatialTriggerFP22CB3PlanarTriggerStruct.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00272E50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3EnvironmentManager_002BC270.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EnvironmentManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TableComponent_0033FB40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3TableComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TipComponent_00342F60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3TipComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_0015AF80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D2F50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtTimer_001D3C90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtTimer.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuInput_0021A950.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuInput.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock_00217310.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputDevicePS2DualShock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EnvironmentManager_002BC140.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EnvironmentManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002E6F10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002E6F20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3BehaviourRotate_002E6F30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Construct__21CB3NetworkCPUMonitorsFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundDistPS2_002FC1C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDistPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BehaviourFlyAround_002EC8C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourFlyAround.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CameraUtils_002F5D30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CameraUtils.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TextComponent_00351B00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3TextComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BuddyReadMailComponent_003725E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3BuddyReadMailComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Update__20CB3PageTextComponentFf.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033C870.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033C880.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_0033C8C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/ezNetCnf_release_lib_libezcnf_00345330.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `ezNetCnf_release.lib libezcnf.o` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_003606D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_0035F490.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_0035FD30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_00360070.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_00360120.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001B86A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtScreenCentre_002213F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtScreenCentre.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0022B830.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/AttachPlugins__10CGtTextureFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrackRendererRuntimePS2_0026B2B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrackRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BehaviourFlyAround_002ED300.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourFlyAround.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BehaviourFlyAround_002ED2F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourFlyAround.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuFlowFSM_0030ED60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3MenuFlowFSM.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/vibuf_00325DC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `vibuf.c` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/vibuf_00326610.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `vibuf.c` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIAggressionBehaviour_00331DA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAggressionBehaviour.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_00270EB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ShadowRendererPS2_00303EC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ShadowRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuPageManager_0030D4B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuPageManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026E350.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundScrape_00283510.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundScrape.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0030B130.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLoginToLobbyPage_0034CD00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLoginToLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/ezNetCnf_release_lib_i18n_00344E10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `ezNetCnf_release.lib i18n.o` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_00361260.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_00361440.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_003614C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034D360.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScoreBonus_00368DF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScoreBonus_00368E40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BehaviourInterpolate_00373940.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourInterpolate.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PageTextComponent_00379230.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PageTextComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PhysicsManagerDebug_002BEA00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManagerDebug.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/ShouldWeEncryptMessageContents__17CB3NetworkManagerFi.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026DD70.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026DE30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3NetworkManager_0026E230.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtLobbyDirtySock_00338C20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundListener_00384550.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundListener.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundListener_00384590.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundListener.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundListener_003845D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundListener.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundListener_00384610.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundListener.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0038AFF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A2830.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D27D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A7010.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A7060.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004480E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003B83F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashPickup_003A17A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashPickup.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/AddCrashMultiplier__13CB3CrashScoreF20ECrashModePickupTypei.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehicleDeform_003E7600.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleDeform.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003EA880.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EA8E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HardCodedTrackList_003EAB10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3HardCodedTrackList.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003EACC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EAE40.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GetRaceVehicleGtID__23CB3HardCodedVehicleListFi.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003FC640.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HardCodedTrackRegionList_003F5D60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3HardCodedTrackRegionList.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00445950.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00460090.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/libSharedLogin_a__21_00465300.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `libSharedLogin.a /21` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00454A60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00462130.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042C100.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TableComponent_00340270.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TableComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtHiResSystemTimerPS2_00375280.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtHiResSystemTimerPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00338BD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineSelectLoginPage_003486B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineSelectLoginPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027F480.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PlayerCameraStateDebug_002E7F00.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCameraStateDebug.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StreamedTrack_00302610.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrack.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00466E80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtLobbyDirtySock_00336F10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `GtLobbyDirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0037ED90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StreamedTrack_00301BC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrack.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TextureCollectionPS2_00378F90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TextureCollectionPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineTurnBasedCrashLogic_00392B30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineTurnBasedCrashLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0045C890.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00393940.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045AE20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineBuddiesMenuPage_0036E0A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineBuddiesMenuPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0045B920.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0034BEB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0037E680.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Profile_00136FA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Profile.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00455170.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficSystem_00164510.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00347940.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A03B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FBDB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FB8B0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00464CD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004670A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00467BC0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00467620.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004678E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F2970.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EE470.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundCrashManager_0027B4C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuPageManager_0030DE10.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3MenuPageManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00322EA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038CF50.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundHUDManager_00286AD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundHUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0042EE20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00454BF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AIAvoidance_0013DA30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003EEB20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F4AD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0021B4F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StreamedTrackPS2_0021CFF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrackPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0012FDA0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/ReleaseExtraLeadIn__18CB3SatNavComponentFv.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0028D1A0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0021B5E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StaticTrackPS2_0021D2E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StaticTrackPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00236310.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00236460.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CC510.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3BehaviourFlyAround_002EC8D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourFlyAround.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001508C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0044CEF0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AIAvoidance_00140980.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashActionDirector_001AE3F0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashActionDirector.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SparkRendererPS2_00263B80.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ParticleRendererPS2_00254C90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ParticleRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001AE360.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CoronaRendererPS2_00307440.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CoronaRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BehaviourFlyAround_002ED2C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourFlyAround.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDManager_001A02C0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027EF30.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027EF60.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001D6970.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0033D380.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001D6AD0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0033D4E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/UpdateWibbleAnimationIn__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00147CB0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00147E90.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundTrafficVehicle_00278F20.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTrafficVehicle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ConvexHullCollide_002B87E0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ConvexHullCollide.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C35D0.cpp` | placed + proven 2026-10-26 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficAxle_0015F940.cpp` | placed + proven 2026-10-26 (batch) | `[C]` name: retail tables (high); file `B3TrafficAxle.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00382CF0.cpp` | placed + proven 2026-10-26 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002319D0.cpp` | placed + proven 2026-10-26 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00231AD0.cpp` | placed + proven 2026-10-26 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/B3MenuPageManager_0030D500.cpp` | placed + proven 2026-10-26 (batch) | `[C]` name: retail tables (high); file `B3MenuPageManager.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3VehicleDeform_00461440.cpp` | placed + proven 2026-10-26 (batch) | `[C]` name: retail tables (high); file `B3VehicleDeform.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3AITarget_0014DC70.cpp` | placed + proven 2026-10-26 (batch) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/B3RaceCarPhysicsAttribs_002540E0.cpp` | placed + proven 2026-10-26 (batch) | `[C]` name: retail tables (high); file `B3RaceCarPhysicsAttribs.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003CC910.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundGameModeManager_00289EE0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundGameModeManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003FC8C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002353D0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundBank_00383C80.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundBank.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00146C20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00438380.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3RoundedPanel2dObject_003A3190.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RoundedPanel2dObject.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00464320.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PhysicsManagerDebug_002BEBB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManagerDebug.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003FCD20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FC060.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3RaceCar_001515E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003F9F70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002C1560.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C1C40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0026EEC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003ADA10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042DF40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundRaceCar_0028DA40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundRaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/RegisterMessageTypes__17CGtNATDataManagerFi.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00469880.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0039F090.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3VehicleRendererRuntime_00220B70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleRendererRuntime.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Game_001344D0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Game.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLobbyState_0030F490.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027AD10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027AB00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PlayerCarPhysics_001BAAF0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3PlayerCarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003FDED0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042F8D0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3BloomPS2_002659C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BloomPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Im3DPS2_00365460.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3WorldPS2_00276300.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3WorldPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0039C570.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00461DF0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Update__15CB3ScrapeSystemFv.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027C370.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Update__24CB3BuddyDisplayComponentFf.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/CreateScoreObject__27CB3HUDPrimaryMessageHandlerFi.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00438FB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AILane_00146F20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CarViewerGameMode_0024FA40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CarViewerGameMode.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004617B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F2620.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PhysicsManager_001B84A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dRendererPS2_00217C40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0036BD90.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3ParticleRendererPS2_00254970.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ParticleRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003827B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00353640.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3BehaviourTrackSide_002F5AC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3BehaviourTrackSide.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004553E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficVehicle_00171E90.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficVehicle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0036B0A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Prepare__13CB3NetworkCarFv.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficSystemLoadAndRender_00309300.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficSystemLoadAndRender.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00452ED0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0023F300.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/vibuf_00326340.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `vibuf.c` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficLane_0015FBA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficLane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AITarget_0014D380.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundBankManager_00383FF0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundBankManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0035F240.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Score_001566F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002E6F60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficLane_0015FAD0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficLane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/vibuf_00326670.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `vibuf.c` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004589B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineBuddiesMenuPage_0036D8F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineBuddiesMenuPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00235770.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3MenuPageManager_0030D560.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuPageManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001549F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3ScrapeRenderPS2_00376290.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScrapeRenderPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00301B00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_00350F70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ScoreBonus_003684D0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SkyDomeRendererPS2_0021DC50.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SkyDomeRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GetChallengeType__25CB3HardCodedRaceStageListFi.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineMenuPage_00323740.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineMenuPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/IntersectFrustum__14GtIntersectionFRC10CGtFrustumRC14CGtExtrudedBox.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/IntersectFrustum__14GtIntersectionFRC10CGtFrustumRC16CGtOrthogonalBox.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026AE30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3ScoreBonus_00367F40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ScoreBonus.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00353F30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtIntersectionPS2_00274C90.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtIntersectionPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineSelNetConfigPage_003464B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineSelNetConfigPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00382FC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003CD920.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002F9690.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3VehicleRendererRuntimePS2_0021FF60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0023D0F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineJoinGameState_0032ADF0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineJoinGameState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundHUDManager_00286C60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3SoundHUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BodyPartPhysics_00334680.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3BodyPartPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EffectsManager_002630F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EffectsManager_002621A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuImages_003717A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3MenuImages.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00450E10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineMenuState_00323E30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineMenuState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002E8BD0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038EEE0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PlayerCameraStateCrashMode_00357600.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PlayerCameraStateCrashMode.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C71B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FF540.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLoginToLobbyState_0034A4E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045C140.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00322700.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FE8F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0041F0C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00155BC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundCrashManager_0027EF90.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00339AA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TableSelectComponent_00352300.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3TableSelectComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ConnectionAnimationComponent_00352990.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ConnectionAnimationComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00351B20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDScore_001A2030.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDScore.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00313450.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00371670.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0030CF90.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtTextureCachePS2_00221650.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtTextureCachePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C9A60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002C02A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00360AC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022F800.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CameraUtils_002F6210.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CameraUtils.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BehaviourCluster_0035BC10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourCluster.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehicleDeform_00460A50.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleDeform.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PlayerCameraStateInGame_002E8250.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (low); file `B3PlayerCameraStateInGame.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003187F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0039F490.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00353FA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00462780.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004272A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00462200.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficParam_00160F10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficParam.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3GraphicsManager_0019EE40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3GraphicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_001598F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00382200.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/IsSegmentLocked__16CB3TrafficSystemFiUs.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineSelectLoginPage_003494F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundCrashManager_0027F0B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SFIOCallbacksPS2_00360B30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3SFIOCallbacksPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0043FFB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EDFD0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00465D00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043EFA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineRankingsState_00369690.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineRankingsState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0019A550.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AIArbitrator_0019D6D0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIArbitrator.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00333740.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Im3DPS2_00364920.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MyBurnoutPage_00322320.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MyBurnoutPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Update__19CB3PromptsComponentFf.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PromptsComponent_0031E1A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PromptsComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3LoadingScreenPage_00321690.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3LoadingScreenPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00353E10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00469CC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StageLogic_00395FC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003E7390.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0041C900.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSphereTree_0035BD80.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSphereTree_0035C3E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00356FB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00437DC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0015A1F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0026D2A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashCameraDirector_00357250.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCameraDirector.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001D0B50.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0031ECD0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00364670.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004474F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3MenuImages_00371870.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuImages.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001573C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00312420.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00312A60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00157380.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficPhysics_002510F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3TrafficPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BloomPS2_00265950.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BloomPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00288480.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3DebrisRendererPS2_002F3B60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DebrisRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficVehicle_001714A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficVehicle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficVehicle_001710E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficVehicle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3DirectionalBlurPS2_00426080.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DirectionalBlurPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3FogPS2_00240F30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3FogPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3GraphicsManagerPS2_00227210.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3GraphicsManagerPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashCombo_00361E60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficParam_00162E80.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3TrafficParam.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00275EF0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrackRendererRuntimePS2_0026BAA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrackRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dRendererPS2_00219D50.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dRendererPS2_00219F20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/UpdateSpinAnimationOut__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00441A00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashCombo_003620B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/UpdateSpinAnimationOut2__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0033E220.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001ABFC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3BackgroundComponent_0031CF30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BackgroundComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00463850.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnScreenKeyboardComponent_0034EEB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnScreenKeyboardComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0031BD60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0031BF40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrackRendererRuntimePS2_0026A240.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrackRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundVoiceManager_00388BD0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVoiceManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001A22A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A6330.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Gt2dObjectTable_0033E4F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectTable.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectTable_0033E6F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectTable.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dObjectTable_0033EA10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectTable.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ConvexHull_002BA9F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ConvexHull.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003A5ED0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3VehicleRendererRuntimePS2_00220270.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehicleRendererRuntimePS2_00220170.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00449150.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficVehicle_00171BA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficVehicle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EnvironmentManager_002BC2B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EnvironmentManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ConvexHullCollide_002B9400.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ConvexHullCollide.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StageLogic_00395E90.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001D1130.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StreamedTrack_003026C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrack.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EnvironmentManager_002BBFA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EnvironmentManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00235590.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00376340.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00371140.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00442F10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/FindChallengeIndex__25CB3HardCodedRaceStageListFUl.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0022DB20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00316E80.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00453EA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundVoiceManager_00388D40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVoiceManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundHUDManager_00286970.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundHUDManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027AF60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AITarget_001495C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C82E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3GraphicsManager_0019EB60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3GraphicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtNATDataManager_002321E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtNATDataManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSphereTree_0035E750.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSphereTree.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EnvironmentManager_002BC190.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EnvironmentManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00463600.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00313230.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C3150.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C3250.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CollidingBody_001ABE70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CollidingBody.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RaceCarPhysics_001BF030.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RaceCarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004506E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3EnvironmentManager_002BC070.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EnvironmentManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficAxle_0015F650.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficAxle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficAxle_0015FA00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficAxle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundSkidModel_0028E120.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundSkidModel.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003BA300.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0039FA70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PromptBarPanel2dObject_003D7EB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PromptBarPanel2dObject.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Panel2dObject_00380970.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Panel2dObject.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003BA8F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003EF9C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDScore_001A1CD0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDScore.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficVehicle_001717D0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficVehicle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003C8A30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00217E70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045B050.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AILane_00148140.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AICarPhysics_001D2C10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MenuInput_0021A5F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MenuInput.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PhysicsManager_001BA950.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003230A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045A3E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundAICar_0028BBC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundAICar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ChatDisplayComponent_003322D0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3ChatDisplayComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0022E110.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AILane_00148D60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehicleDeform_00461150.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleDeform.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00146880.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0039FD90.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A0050.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrackRendererRuntimePS2_0026A610.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrackRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001D0F50.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00397520.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AILane_00147C10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrailSystem_002BD320.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrailSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00235BB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003A6E80.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3EffectsManager_00262520.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00427C30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C1990.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0033DC80.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00442AE0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00369090.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3RaceCar_00150D50.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RaceCar_00151A40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundESMStruct_002FB640.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESMStruct.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003353C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3VehicleDeform_003E4AA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleDeform.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003B8670.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00376880.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AILane_00148C20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Update__25CB3EventFinishedComponentFf.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0043A420.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003F88E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0045CB70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00376F60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00329210.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00137A40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00438520.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00453380.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00465EB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00465B30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003FB0F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AIAggressionBehaviour_0032EEE0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAggressionBehaviour.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GetStylisedTextSize__14CB3ResultsPageFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RewardImageComponent_003F60A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3RewardImageComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0023B380.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003C45F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/OnWorldPrepared__26CB3OfflineSingleCrashLogicFv.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00143860.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashScore_003CD430.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashScore.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundAICar_0028BDD0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundAICar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003CC770.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AILane_00148CA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/StartScrape__14CB3SoundScrapeFiPC12CGtSoundWave.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001D0D00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineBuddiesState_0036A910.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineBuddiesState.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystemPS2DVD_001D3280.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystemPS2DVD.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrailRenderPS2_002F3600.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrailRenderPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OfflineStageLogic_003951A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OfflineStageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtPS2LibNet_0022EC60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtPS2LibNet.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0044A810.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AITarget_0014A480.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00147180.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00311EA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3RaceCarPhysicsAttribs_00252530.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RaceCarPhysicsAttribs.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002F5770.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0023F960.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00160B40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00227B80.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtBuddiesPS2DirtySock_0035FC00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtBuddiesPS2DirtySock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CameraAttribs_002F8870.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CameraAttribs.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundESM_00287F20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESM.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundESMStruct_002FB120.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESMStruct.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ParticleRendererPS2_002556F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ParticleRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002C16A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00220450.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AIDriver_00143FA0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIDriver.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDComponent_0019F4B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIAvoidance_0013D910.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDScore_001A2100.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDScore.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CameraUtils_002F5D40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CameraUtils.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundBank_00383A70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundBank.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/UpdatePause__17CGtSoundRealVoiceFv.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00150460.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundESMStruct_002FB770.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESMStruct.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004655C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/HandleCrashRaceCar__13CB3CrashScoreFP17CB3RaceCarPhysicsi.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PopcornRendererPS2_00366160.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PopcornRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashActionDirector_001AD890.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashActionDirector.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004647D0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundESM_00288770.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESM.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00375840.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AICar_00143CE0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficLight_00265C80.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficLight.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundAICar_0028B720.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundAICar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EffectsManager_00260DB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00465740.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AICar_001419F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtTextureCachePS2_00221850.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtTextureCachePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004516B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Panel2dObject_003808A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Panel2dObject.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003910B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3ParticleRendererPS2_00255240.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ParticleRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RaceCar_00152770.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RacePosition_00154770.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RacePosition.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StopJunction_002B5B70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StopJunction.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundDistPS2_002FCDB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDistPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027F5E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00454120.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AITarget_0014A290.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehicleDeform_00460C20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleDeform.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashCombo_00361F70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3GraphicsManager_0019EBF0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3GraphicsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Gt2dRendererPS2_0021A290.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00389600.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AILane_00146040.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Score_001553F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003F1490.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtInputDevicePS2DualShock2_00214CD0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtInputDevicePS2DualShock2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00255C90.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3HUDBoostBar_001A52D0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDBoostBar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Profile_00139C00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3Profile.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00318560.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0030ED90.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TextComponent_00351C60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TextComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0033F620.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CoronaRendererPS2_00307560.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CoronaRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00421850.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022DEF0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0043A190.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3DebrisRendererPS2_002F4A20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3DebrisRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002F4F90.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003D0710.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PhysicsManagerDebug_002BDDF0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManagerDebug.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundTurboModel_0028FB20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTurboModel.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehicleDeform_003E18E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleDeform.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003BC360.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Gt2dObjectVideoImage_00326E70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectVideoImage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDCrashTimer_003B8170.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDCrashTimer.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00288960.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002BCA20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3NetworkCarPhysics_00269B70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3NetworkCarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00326CF0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficValve_00267640.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficValve.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003CD380.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtSoundStream_003868C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundStream.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AICarPhysics_001D2D70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0038B080.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00431160.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3EffectsManager_00261E00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003A7CB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundGameModeManager_00289770.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundGameModeManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0039C510.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002F34C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3VehicleDeform_003E19C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleDeform.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00146540.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00147F50.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AILane_00147EE0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AILane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RaceCar_00151450.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RaceCar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SparkRendererPS2_002638C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SparkRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AITarget_0014A130.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EnvironmentManager_002BCEC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EnvironmentManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AICar_00141C10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIAvoidance_0013DF60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PhysicsManagerDebug_002BED00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManagerDebug.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/vibuf_00325E90.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `vibuf.c` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3FogPS2_002419C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3FogPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/UpdateMaskCarChangeState__19CB3CarViewComponentFf.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3RacePosition_001540A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3RacePosition.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficParam_001613B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficParam.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehicleDeform_003DA920.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleDeform.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0043A040.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3BloomPS2_00264C30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BloomPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001BEEE0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Initialise__16CGtCameraFrustumFP8RwCamera.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ChatDisplayComponent_003322F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ChatDisplayComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002F2CD0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Im3DPS2_003652E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001A8620.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundTrafficVehicle_00278830.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTrafficVehicle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehicleDeform_003E7110.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehicleDeform.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIAvoidance_0013ED50.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0030B6E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3PhysicsManagerDebug_002BDA00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PhysicsManagerDebug.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundCrashManager_0027F2A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001CBA30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SkyDomeRendererPS2_0021E490.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SkyDomeRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003517F0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002F99E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Gt2dRendererPS2_00219830.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundESM_00287970.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundESM.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0023F5B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0022C340.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Gt2dObjectTable_0033EF20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `Gt2dObjectTable.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EffectsManager_00257C70.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00439110.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3ShadowRendererPS2_00303C10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ShadowRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/Initialise__20CGtCameraFrustumBaseFP8RwCamera.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0027BCE0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0042B030.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3TrafficValve_00267EC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficValve.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00280580.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0039BAB0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0027CC20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0027E900.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/Update__21CB3ScrollBarComponentFf.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0027DDD0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0027E570.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0027C5A0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CoronaRendererPS2_00306E80.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CoronaRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026AF50.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AIAvoidance_0013DD30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0027B1D0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0027CF30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0027FFF0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3VehiclePhysics_001CB780.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehiclePhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ConvexHull_002BA420.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ConvexHull.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00465960.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3AIDriver_00145A10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIDriver.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00311890.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDComponent_0019F790.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3HUDComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00147FC0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00148080.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3ParticleRendererPS2_00254F20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ParticleRendererPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0027E170.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashCombo_003634B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCombo.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIAvoidance_0013EED0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAvoidance.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0027C8E0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002802B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00280900.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundTrafficVehicle_00278B20.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundTrafficVehicle.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003548C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashActionDirector_001B0E10.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashActionDirector.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BodyPartPhysics_003342D0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3BodyPartPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3HUDBoostBar_001A3F40.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3HUDBoostBar.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIAggressionBehaviour_0032F360.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAggressionBehaviour.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIAggressionBehaviour_00331B30.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAggressionBehaviour.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3VehiclePhysics_001CC580.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3VehiclePhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIAggressionBehaviour_0032F550.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIAggressionBehaviour.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0030F620.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0038ABE0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00342410.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/ezNetCnf_release_lib_i18n_00344C80.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `ezNetCnf_release.lib i18n.o` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0026E800.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00315170.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_003BD4B0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002BDF00.cpp` | placed + proven 2026-10-27 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3CrashAnalyser_00354D60.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashAnalyser.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/UpdateTakeDownStats__8CB3ScoreFP17CB3CrashStartInfo.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrackRendererRuntimePS2_0026A710.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrackRendererRuntimePS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficLane_00160400.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficLane.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3ConvexHull_002BA650.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `B3ConvexHull.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtSoundVirtualVoice_003873C0.cpp` | placed + proven 2026-10-27 (batch, hand-written) | `[C]` name: retail tables (high); file `GtSoundVirtualVoice.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PropManager_002B7300.cpp` | placed + proven 2026-10-28 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PropManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_003AB540.cpp` | placed + proven 2026-10-28 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtWideLine_0041D910.cpp` | placed + proven 2026-10-28 (batch, hand-written) | `[C]` name: retail tables (high); file `GtWideLine.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CrashCameraDirector_00356700.cpp` | placed + proven 2026-10-28 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CrashCameraDirector.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3PageTextComponent_00379690.cpp` | placed + proven 2026-10-28 (batch, hand-written) | `[C]` name: retail tables (high); file `B3PageTextComponent.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3GraphicsManagerPS2_002260D0.cpp` | placed + proven 2026-10-28 (batch, hand-written) | `[C]` name: retail tables (high); file `B3GraphicsManagerPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/GameShared/GameClasses/Graphical/2d/Gt2dFrameHierarchy.cpp` (Sync 0x1D53B0, func_001D4780) | proven 2026-10-28 (TU-level, N252) | Same TU as the Gt2dFrameHierarchy family (E-map order); the function name is from the retail tables. |
| `src/b3/_unclassified/B3AICarPhysics_001D1670.cpp` | placed + proven 2026-10-30 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AICarPhysics.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AIArbitrator_0019D4D0.cpp` | placed + proven 2026-10-30 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AIArbitrator.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d.cpp` | placed + proven 2026-10-30 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3AITarget_0014A1C0.cpp` | placed + proven 2026-10-30 (batch, hand-written) | `[C]` name: retail tables (high); file `B3AITarget.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3BehaviourInterpolate_00373F60.cpp` | placed + proven 2026-10-30 (batch, hand-written) | `[C]` name: retail tables (high); file `B3BehaviourInterpolate.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3EffectsManager_0025FCF0.cpp` | placed + proven 2026-10-30 (batch, hand-written) | `[C]` name: retail tables (high); file `B3EffectsManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3GameData_0014E8C0.cpp` | placed + proven 2026-10-31 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3GameData.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0030B9D0.cpp` | placed + proven 2026-10-31 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineJoinGamePage_00327F10.cpp` | placed + proven 2026-10-31 (batch, hand-written) | `[C]` name: retail tables (low); file `B3OnlineJoinGamePage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00343800.cpp` | placed + proven 2026-10-31 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineSelectPersonaPage_003406C0.cpp` | placed + proven 2026-10-31 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3OnlineSelectPersonaPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0037A920.cpp` | placed + proven 2026-10-31 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Score_0015D0A0.cpp` | placed + proven 2026-10-31 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Score.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0037D1F0.cpp` | placed + proven 2026-10-31 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3SoundCrashManager_00282AC0.cpp` | placed + proven 2026-10-31 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundCrashManager.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3StopJunction_002B61E0.cpp` | placed + proven 2026-10-31 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StopJunction.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00321A50.cpp` | placed + proven 2026-10-31 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00431860.cpp` | placed + proven 2026-10-31 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_002FC820.cpp` | placed + proven 2026-10-31 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3Im3DPS2_00364B70.cpp` | placed + proven 2026-10-31 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Im3DPS2_00365040.cpp` | placed + proven 2026-10-31 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3Im3DPS2_00364E10.cpp` | placed + proven 2026-10-31 (batch, hand-written) | `[C]` name: retail tables (high); file `B3Im3DPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3TrafficSystem_00166F50.cpp` | placed + proven 2026-10-31 (batch, hand-written) | `[C]` name: retail tables (high); file `B3TrafficSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3SoundDSPBlock_002FBE20.cpp` | placed + proven 2026-10-31 (batch, hand-written) | `[C]` name: retail tables (high); file `B3SoundDSPBlock.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3CameraAttribs_002F7E70.cpp` | placed + proven 2026-11-01 (batch, hand-written) | `[C]` name: retail tables (high); file `B3CameraAttribs.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0030A9D0.cpp` | placed + proven 2026-11-01 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_0036ECC0.cpp` | placed + proven 2026-11-01 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OnlineLobbyPage_00313B30.cpp` | placed + proven 2026-11-01 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OnlineLobbyPage.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_002FC530.cpp` | placed + proven 2026-11-01 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3GraphicsManagerPS2_002270B0.cpp` | placed + proven 2026-11-01 (batch, hand-written) | `[C]` name: retail tables (high); file `B3GraphicsManagerPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00353A30.cpp` | placed + proven 2026-11-01 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3OfflineRoadRageLogic_0038C120.cpp` | placed + proven 2026-11-01 (batch, hand-written) | `[C]` name: retail tables (high); file `B3OfflineRoadRageLogic.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00130C20.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00130C30.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/func_00131DF0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/func_00133180.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_00134910.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_00134990.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_001353A0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. tail template. |
| `src/b3/_unclassified/func_001353B0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. get template. |
| `src/b3/_unclassified/func_00135410.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. setk template. |
| `src/b3/_unclassified/func_0013C9A0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. empty template. |
| `src/b3/_unclassified/func_0013CBB0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. const template. |
| `src/b3/_unclassified/GtFileSystem_002125E0.cpp` | placed + proven 2026-11-02 (batch) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/GtFileSystem_002126E0.cpp` | placed + proven 2026-11-02 (batch) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. const template. |
| `src/b3/_unclassified/func_002BAEE0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. stores template. |
| `src/b3/_unclassified/GtFileSystem_00212A70.cpp` | placed + proven 2026-11-02 (batch) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_003EA7E0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00134930.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00136E00.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013C990.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_002527F0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013C930.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00131AA0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001D17B0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013C910.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0027A900.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001ABE40.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013B740.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0014DD80.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0014E830.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtFileSystem_00212770.cpp` | placed + proven 2026-11-02 (batch) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00130C40.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00131F60.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00135A60.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001AB010.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013AE70.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001C5040.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001C6EF0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00131CA0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0024FDA0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00131CE0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00131E00.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001AD850.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00134940.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001353C0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013C940.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00131F10.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013CDD0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0014E7E0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0024D4D0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00130D00.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00134660.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013C9B0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00134600.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00131D20.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001349A0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00132560.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001CBCE0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_0013CBC0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_001313C0.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00135420.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/func_00135180.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtFileSystem_00212890.cpp` | placed + proven 2026-11-02 (batch) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00132420.cpp` | placed + proven 2026-11-02 (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. lift template. |
| `src/b3/_unclassified/GtFileSystem_00212CB0.cpp` | placed + proven 2026-11-02 (batch) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_004D5320.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D5990.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D59C0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D5A10.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D5A60.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D5B50.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D6130.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D6CF0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D6E40.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D7150.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D77F0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D8950.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D8D40.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D8E70.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D8EA0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D9410.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D94B0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D9570.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D9580.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D9590.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D95C0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D9770.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DA130.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DA2A0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DAEA0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DAFD0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DB050.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DB300.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DB3E0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DC2B0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DC2F0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DC3A0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DC3E0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DC5D0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DC610.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DC940.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DCB10.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DCB30.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DCBF0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DCC60.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DCF10.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DD390.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DD7B0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/FTell__13CGTFileSystemFPv.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystem_00212590.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystem_00212690.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystem_002126F0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystem_00212730.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystem_002127A0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/ustrSetSeparators.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtUnicode_002138C0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtUnicode.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtUnicode_00213940.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtUnicode.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtUnicode_002139A0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtUnicode.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtUnicode_00213A00.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtUnicode.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtUnicode_00213A30.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtUnicode.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_004D5330.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D5D80.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D5DA0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D6170.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DB070.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DB620.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtCommsToolBase_0021B8C0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtCommsToolBase.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtCommsDatabase_0021B8F0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtCommsDatabase.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtCommsDatabase_0021BF80.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtCommsDatabase.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtHash_0021BFA0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtHash.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtCommsDatabaseGame_00250100.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtCommsDatabaseGame.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtCommsDatabaseGame_00250110.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (medium); file `GtCommsDatabaseGame.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtCommsDatabaseGame_00250120.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtCommsDatabaseGame.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MemoryManagerPS2_002223B0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (medium); file `B3MemoryManagerPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00131E40.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3MemoryManagerPS2_002225C0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MemoryManagerPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/B3MemoryManagerPS2_00222620.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `B3MemoryManagerPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFreeList_002B6C40.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFreeList.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFreeList_002B6CA0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFreeList.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFreeList_002B6D20.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFreeList.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFreeList_002B6E10.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFreeList.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001C0E80.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3VehiclePhysics_001CC520.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001CC4C0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/__ct__12CUnk0028B700Fv.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `None` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0014EC30.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DD7E0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3StreamedTrackPS2_0021D080.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `B3StreamedTrackPS2.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/GtFileSystem_00212A80.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtFileSystem.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_00130C70.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtUnicode_00213BE0.cpp` | placed + proven 2026-11-02 (batch, hand-written) | `[C]` name: retail tables (high); file `GtUnicode.cpp` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_001CBE50.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D8680.cpp` | placed + proven 2026-11-02 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_00131D90.cpp` | placed + proven 2026-11-03 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_001C6F30.cpp` | placed + proven 2026-11-03 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D8A40.cpp` | placed + proven 2026-11-03 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D8980.cpp` | placed + proven 2026-11-03 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DD670.cpp` | placed + proven 2026-11-03 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D8D50.cpp` | placed + proven 2026-11-03 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D8330.cpp` | placed + proven 2026-11-03 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004DC450.cpp` | placed + proven 2026-11-03 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/func_004D9700.cpp` | placed + proven 2026-11-03 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/B3MemoryManagerPS2_002223C0.cpp` | placed + proven 2026-11-04 (batch) | `[C]` name: retail tables (high); file `B3MemoryManagerPS2.cpp` (retail_names.csv). Area not evidenced. lift template. |
| `src/b3/_unclassified/func_00285C00.cpp` | placed + proven 2026-11-05 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/ezNetCnf_release_lib_libezcnf_00345340.cpp` | placed + proven 2026-11-05 (batch, hand-written) | `[C]` name: retail tables (high); file `ezNetCnf_release.lib libezcnf.o` (retail_names.csv). Area not evidenced. |
| `src/b3/_unclassified/func_0022B120.cpp` | placed + proven 2026-11-05 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtID_0021AC70.cpp` | placed + proven 2026-11-06 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
| `src/b3/_unclassified/GtFramerateManager_00376570.cpp` | placed + proven 2026-11-06 (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. |
