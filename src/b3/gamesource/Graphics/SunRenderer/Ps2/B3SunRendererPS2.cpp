// B3SunRendererPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3SunRendererPS2.cpp.
// Area: src/b3/gamesource/Graphics/SunRenderer/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/SunRenderer/Ps2/B4SunRendererPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SunRenderer.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

extern UnkStruct_theMemMgr theMemMgr;
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);

// CB3SunRenderer::RenderEnvmap() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SunRendererPS2.cpp.
// 0x0024B360
void CB3SunRenderer::RenderEnvmap()
{
    RenderEnvmapCorona();
    CB3SunRenderer::RenderEnvmapBlob();
}

// CB3SunRenderer::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SunRendererPS2.cpp.
// 0x0024D360
void CB3SunRenderer::Release()
{
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 3, 0);
    CB3SunRenderer::mpCoronaTexture = 0;
}

// CB3SunRenderer::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SunRendererPS2.cpp.
// 0x0024D4A0
void CB3SunRenderer::Destruct()
{
    CB3SunRenderer::mpCoronaTexture = 0;
    CB3SunRenderer::mpEnvmapCoronaTexture = 0;
}

// CB3SunRenderer::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SunRendererPS2.cpp.
// 0x0024D4B0
void CB3SunRenderer::Construct()
{
    CB3SunRenderer::mpCoronaTexture = 0;
    CB3SunRenderer::mpEnvmapCoronaTexture = 0;
}
