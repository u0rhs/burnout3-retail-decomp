# Port libraries: RenderWare 3.6, Sony SDK and the other linked libraries (draft, 2026-10-30)

Planning doc for the later PC port (separate repo; charter note in `docs/conventions.md`). Its job **now** is narrow: make
sure the types and headers we write today don't block a port that swaps the PS2 libraries out. Every claim is tagged;
nothing here changes the matching rules.

## 1. What game code calls (inventory)

Artefact: `research/port/game_library_calls.tsv` (address, library, name, direct call sites), generated from
`orig/SLUS_210.50` by scanning every `jal` outside the library ranges for targets inside them (`python3 -I tools/port_lib_calls.py .
research/port/game_library_calls.tsv`; re-run when library boundaries change). [C] for direct calls. It **misses** calls through function
pointers, RW macros already expanded into game code (e.g. frame/matrix accessors), and plugin data read by offset.

414 of the 3,451 library functions are called directly from game code:

| Library (asm dir) | Functions called | Call sites | Port replacement | Prior art |
|---|---|---|---|---|
| `runtime/libc`, `libm`, `libgcc`, `mwrt`, `crt0` | 53 | 1,762 | host C runtime; wrappers only where PS2 libc differs (`scePrintf`-style) [L] | -- |
| `ea/dirtysock` (EA DirtySDK: lobby, buddies, TagField) | 115 | 489 | own online layer (EA's servers are gone) [C: Burn3 had to write its own] | Burn3 `server/matchmaking.py`, `src/net` |
| `sce/libkernl` (threads, semaphores, SIF RPC to the IOP) | 47 | 219 | host threads / sync; the IOP-side work (audio, CD, pad) moves into host code [L] | Burn3 `ee_kernel.cpp` |
| `rw/renderware` (RW Graphics 3.6, sky2 driver) | 50 | 182 | librw-style reimplementation + our own back end for the `RpSky*` / `_rwDMA*` parts (see 2) [L] | librw; Burn3 renderer |
| `rwa/*` (RenderWare Audio: objects, voices, wave dicts, streams, SPU2) | 51 | 111 | own audio layer behind the same call surface; RWS stream + PS-ADPCM decode [L] | Burn3 `src/audio` (`rws_stream`, `ps_adpcm`, `spu2_*`) |
| `sce/libinsck`, `libnet`, `netcnfif` | 24 | 58 | host sockets | Burn3 `src/net` |
| `lg/*` (Logitech USB: headset codec, devices, keyboard) | 32 | 61 | host audio capture / keyboard, or drop [G] | -- |
| `sce/libpad2` | 7 | 29 | host input (SDL-style) | Burn3 `platform/input_bindings` |
| `sce/libmc2` | 14 | 18 | save files | Burn3 `src/save` |
| `sce/libcdvd` | 5 | 11 | file I/O over the extracted disc | Burn3 `content/disc_path_resolver` |
| `sce/libmpeg` (+ IPU) | 6 | 10 | host video decode (FFmpeg-class) | Burn3 movie playback |
| `sce/libdma`, `libgraph`, `libdbc`, `libscf`, `libmrpc` | 10 | 43 | absorbed by the render / platform back ends | -- |

The top RW entry is `_rwDMAOpenVIFPkt` with **73 call sites**. Game code builds its own VIF/GS packets inside RW's
DMA stream, which is the real render-port boundary (section 2), not the RW API.

## 2. RenderWare: what a librw-style layer covers and what it doesn't

librw (github.com/aap/librw, the open RW 3.x reimplementation behind re3/reVC) [L, from its README/source,
re-check before relying on it]: the public RW object model (`RwEngine`, `RwCamera`, `RwFrame`, `RwRaster`,
`RwTexture`, `RpClump`/`RpAtomic`/`RpGeometry`, plugin registration, binary stream chunks), several back ends
(D3D, GL, null), and reading PS2 native geometry/textures for conversion. Its structs are **its own**, not
binary-compatible with RW 3.6.

| Game-side use | librw-style layer? | Notes |
|---|---|---|
| `RwEngine*`, `RwCamera*` (create, clip planes, view window, begin/end update, show raster), `RwFrame*`, `RwMatrix*`, `RwRaster*` | yes [L] | compiles against librw only if game code uses named fields, not RW 3.6 offsets |
| `RpSky*` (texture cache, render state, mode, deep Z, TS clipper) | no | sky2-driver specific; map to our renderer's state / texture management |
| `_rwDMA*` (`OpenVIFPkt` x73, `PreAlloc`, `AddImageUpload`, `ForceBufferSwap`, yield callback) | no | the game writes VIF/GIF packets itself; re-implement at the game render-class level |
| 22 game-owned VU1 microprograms (`vu/game_*` textbin) + 5 RW ones | no | port = host / GPU reimplementation of each program; Burn3 has decoded which programs run and their DMA chains |
| RW Audio | no open reimplementation known [G] | separate audio layer (row above) |

## 3. Header and type rules that help the port now (no codegen change intended)

These apply to new code and header rounds on **both** tracks. Each must be checked to leave every proven unit
identical (`verify_all` + `MATCHES RETAIL`); if one changes codegen it loses to matching.

1. **One shared prototype header per library** (`include/rw/`, `include/rwa/`, `include/sce/`, later
   `include/dirtysock/`), with the libraries' own names and signatures (RW 3.5/3.1 SDK prototypes, tagged [L] for
   3.6; Sony's names from the 3.0.3 SDK headers referenced by path, never copied). Units stop redeclaring library
   functions locally. Today they do; that is a header-consolidation job, declarations only.
2. **Read RW structs through named fields**, using typed layouts taken from the RW 3.5 headers [L], not raw
   `*(int*)((char*)p + 0x34)` puns. A port can only compile against librw's own structs if the game names the field.
   Where a field's 3.6 offset differs from 3.5, the struct records it with a [C]/[L] comment.
3. **VU0 math stays behind the GtMathPs2 headers.** The port swaps `GtMathPs2*.h` for a host-SIMD implementation of
   the same inline API (`docs/gtmathps2_api.md`). 241 of 3,733 matched `.cpp` files still carry their own `asm`
   blocks (top ops: `pcpyld` 244, `qmtc2` ~110, `pextlw`, `pminw`/`pmaxw`, `vsub`/`vadd`, `vrsqrt`). Where matching
   allows, those become named inline helpers in a shared header; where it doesn't, the port's non-matching version
   replaces the function.
4. **One 128-bit type.** 268 files use `u_long128` / `mode(TI)` locally; it should come from one shared typedef
   header so the port can redefine it.
5. **Hardware and scratchpad addresses** (58 files reference `0x1000xxxx` / `0x1200xxxx` registers or `0x70000000`
   scratchpad) go through named constants in one header, so the port can find and replace every direct hardware
   touch.

## 4. Open items

- Re-run the inventory to also count calls through function pointers and RW macro expansions (needs the RW 3.5
  macro list and a pattern scan of game asm).
- Pick the order for rules 1, 2, 4 and 5 as header-consolidation rounds (they ride on `tools/hdr_consolidate.py`).
- Decide the port repo's language baseline and renderer API when that phase starts. Burn3 (Vulkan via paraLLEl-GS)
  is the reference for what the PS2 render path needs, not necessarily the design to copy.
