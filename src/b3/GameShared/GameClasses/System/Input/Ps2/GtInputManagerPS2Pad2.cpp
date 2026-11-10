// GtInputManagerPS2Pad2.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// Area: src/b3/GameShared/GameClasses/System/Input/Ps2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Input/Ps2/GtInputManagerPS2Pad2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtInputManagerPS2Pad2.h"

// CGtInputManagerPS2Pad2::SetPause(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// 0x00214940
void CGtInputManagerPS2Pad2::SetPause(bool p0)
{
    if ((p0 & 255) == field_20C) return;
    field_20C = p0;
    for (int i = 0; (i < 2); i++) {
        UnkStruct_00214940_2 * t0 = field_200[i];
        if (t0 != 0) {
            t0->vfunc_10(field_20C);
        }
    }
}

// CGtInputManagerPS2Pad2::Prepare() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// 0x00214B60
void CGtInputManagerPS2Pad2::Prepare()
{
    field_264 = -1;
}
