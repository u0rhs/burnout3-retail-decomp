// B3Viewport.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3Viewport.cpp.
// Area: src/b3/gamesource/Graphics, [L] Revenge (SLUS_212.42) GameSource/Graphics/B4Viewport.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3Viewport.h"
#include "b3/classes/CGtViewport.h"

extern "C" void Update__11CGtViewportFv(void *);  // CGtViewport::Update()
extern "C" void Construct__11CGtViewportFiii(void *, int, int, int);  // CGtViewport::Construct(int,int,int)

// CB3Viewport::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Viewport.cpp.
// 0x00251800
void CB3Viewport::Update()
{
    Update__11CGtViewportFv(this);
    field_90 = (1.0f / field_48);
}

// CB3Viewport::Construct(int,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Viewport.cpp.
// 0x00251840
void CB3Viewport::Construct(int p0, int p1, int p2)
{
    Construct__11CGtViewportFiii(this, p0, p1, p2);
    field_90 = 1.0f;
}
