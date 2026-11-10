// B3ShadowRendererPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3ShadowRendererPS2.cpp.
// Area: src/b3/gamesource/Graphics/ShadowRenderer/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/ShadowRenderer/Ps2/B4ShadowRendererPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ShadowRenderer.h"
#include "b3/classes/UnkStruct__gpCache.h"

extern UnkStruct__gpCache _gpCache;

// CB3ShadowRenderer::EndShadowRendering() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ShadowRendererPS2.cpp.
// 0x00303EB0
void CB3ShadowRenderer::EndShadowRendering()
{
    _gpCache.field_0 = 0;
}
