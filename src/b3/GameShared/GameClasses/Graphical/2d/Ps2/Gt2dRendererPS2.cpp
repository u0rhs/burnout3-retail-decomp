// Gt2dRendererPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> Gt2dRendererPS2.cpp.
// Area: src/b3/GameShared/GameClasses/Graphical/2d/Ps2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/2d/Ps2/Gt2dRendererPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/Gt2dRenderer.h"

// Gt2dRenderer::EnableZTest(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dRendererPS2.cpp.
// 0x00217850
void Gt2dRenderer::EnableZTest(bool p0)
{
    Gt2dRenderer::_gbIsZTestEnabled = p0;
    if (p0) {
        Gt2dRenderer::_gnZ = Gt2dRenderer::_gnUserDefinedZ;
    } else {
        Gt2dRenderer::_gnZ = Gt2dRenderer::_gnNearZ;
    }
}
