// B3SkyDomeRendererPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// Area: src/b3/gamesource/Graphics/B4SkyDomeRenderer/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/B4SkyDomeRenderer/Ps2/B4SkyDomeRendererPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SkyDomeRenderer.h"
#include "b3/classes/UnkStruct_skyFrame_1.h"

extern UnkStruct_skyFrame_1 skyFrame_1;

// CB3SkyDomeRenderer::RestoreRenderTarget() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// 0x0021DBC0
void CB3SkyDomeRenderer::RestoreRenderTarget()
{
    skyFrame_1.field_0 = CB3SkyDomeRenderer::mu64OldFrame_1;
}

// CB3SkyDomeRenderer::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// 0x0021E0F0
void CB3SkyDomeRenderer::Release()
{
    CB3SkyDomeRenderer::mbTexturesUploaded = 0;
    CB3SkyDomeRenderer::mePrepareState = 24;
}

// CB3SkyDomeRenderer::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// 0x0021E3C0
void CB3SkyDomeRenderer::Destruct()
{
    CB3SkyDomeRenderer::mbTexturesUploaded = 0;
    CB3SkyDomeRenderer::mePrepareState = 25;
}
