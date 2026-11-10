// B3TrafficParam.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3TrafficParam.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficParam.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TrafficParam.h"

// CB3TrafficParam::ResetMemberVariables() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// 0x00160E50
void CB3TrafficParam::ResetMemberVariables()
{
    field_46 = 0;
    field_38 = 0;
    field_47 = 255;
    field_41 = 255;
    field_44 = 255;
    field_45 = 255;
    field_4B = (field_4B & 254);
    field_2C = 0;
    field_0 = 0;
    field_4 = 0;
    field_30 = 0;
    field_34 = 0;
    field_20 = 0;
    field_1C = 0;
    field_8 = 5.0f;
    field_C = -5.0f;
    field_4B = (field_4B & 239);
    field_4A = 255;
    field_28 = 0;
    field_10 = -1.0f;
    field_14 = 5.0f;
    field_4D = 0;
    field_18 = 0;
    field_40 = 255;
    field_4B = (field_4B & 247);
    field_24 = 0;
    field_4C = 0;
    field_4B = (field_4B & 251);
    field_48 = 0;
    field_42 = 255;
    field_43 = 255;
    field_3C = 65535;
    field_3E = 65535;
}

// func_00162BE0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00162BE0
extern "C" void func_00162BE0(CB3TrafficParam *self)
{
    self->ResetMemberVariables();
}
