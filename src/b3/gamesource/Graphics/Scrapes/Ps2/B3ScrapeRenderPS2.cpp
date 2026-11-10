// B3ScrapeRenderPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3ScrapeRenderPS2.cpp.
// Area: src/b3/gamesource/Graphics/Scrapes/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/Scrapes/Ps2/B4ScrapeRenderPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/B3Im3d.h"
#include "b3/classes/CB3ScrapeRenderer.h"
#include "b3/classes/CGtTimer.h"

extern "C" void BeginRendering__6B3Im3dFv(void *);  // B3Im3d::BeginRendering()

// CGtTimer::GetFrameCount() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScrapeRenderPS2.cpp.
// 0x00376220
int CGtTimer::GetFrameCount()
{
    return CGtTimer::mguFrames;
}

// CB3ScrapeRenderer::EndRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScrapeRenderPS2.cpp.
// 0x00376230
void CB3ScrapeRenderer::EndRender()
{
    B3Im3d::SetZWrite(1);
    B3Im3d::EndRendering();
}

// CB3ScrapeRenderer::BeginRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScrapeRenderPS2.cpp.
// 0x00376260
void CB3ScrapeRenderer::BeginRender()
{
    BeginRendering__6B3Im3dFv(this);
    B3Im3d::SetZWrite(0);
}
