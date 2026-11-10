// B3ParticleRendererPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 6 function(s) named in research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// Area: src/b3/gamesource/Graphics/ParticleRenderer/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/ParticleRenderer/Ps2/B4ParticleRendererPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ParticleArray.h"
#include "b3/classes/CB3ParticleRenderer.h"
#include "b3/classes/UnkStruct_D_004E29E4.h"

extern UnkStruct_D_004E29E4 D_004E29E4;

// CB3ParticleRenderer::BeginRender(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// 0x00254A50
void CB3ParticleRenderer::BeginRender(bool p0)
{
    CB3ParticleRenderer::mbIsCrash = (unsigned char)this;
    D_004E29E4.field_0 = p0;
    CB3ParticleRenderer::mnNumRenderableArrays = 0;
    CB3ParticleRenderer::mnDMANumQW = 0;
}

// CB3ParticleRenderer::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// 0x00254A70
void CB3ParticleRenderer::Destruct()
{
}

// CB3ParticleRenderer::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// 0x00254A80
void CB3ParticleRenderer::Construct()
{
}

// CB3ParticleArray::BeginUpdate(float) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// 0x00254D40
void CB3ParticleArray::BeginUpdate(float p0)
{
    field_7C = p0;
}

// CB3ParticleArray::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// 0x00254F10
void CB3ParticleArray::Release()
{
}

// CB3ParticleArray::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// 0x00255230
void CB3ParticleArray::Destruct()
{
}
