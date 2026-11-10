// B3Im3DPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3Im3DPS2.cpp, 1 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Graphics/Im3D/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/Im3D/Ps2/B4Im3DPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/B3Im3d.h"

// B3Im3d::SetBackfaceCull(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// 0x00365450
void B3Im3d::SetBackfaceCull(bool p0)
{
    B3Im3d::_gbBFC = (unsigned char)this;
}

// B3Im3d::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// 0x00365880
int B3Im3d::Construct()
{
    B3Im3d::_gbConstructed = 1;
    return 1;
}
