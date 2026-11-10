// B3PopcornRendererPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3PopcornRendererPS2.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Graphics/PopcornRenderer/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/PopcornRenderer/Ps2/B4PopcornRendererPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3PopcornArray.h"
#include "b3/classes/CB3PopcornRenderer.h"

extern CB3PopcornArray * D_01EA4060[];  // [G] element count unknown

// CB3PopcornRenderer::EndRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PopcornRendererPS2.cpp.
// 0x00365890
void CB3PopcornRenderer::EndRender()
{
    for (int i = 0; (i < CB3PopcornRenderer::mnNumRenderableArrays); i++) {
        D_01EA4060[i]->Render();
    }
}

// CB3PopcornRenderer::BeginRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3PopcornRendererPS2.cpp.
// 0x00365910
void CB3PopcornRenderer::BeginRender()
{
    CB3PopcornRenderer::mnNumRenderableArrays = 0;
}

// CB3PopcornArray::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PopcornRendererPS2.cpp.
// 0x00366040
void CB3PopcornArray::Release()
{
    field_2C = 0;
}

// CB3PopcornArray::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3PopcornRendererPS2.cpp.
// 0x00366150
void CB3PopcornArray::Destruct()
{
}
