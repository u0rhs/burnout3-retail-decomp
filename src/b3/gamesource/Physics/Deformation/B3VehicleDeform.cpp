// B3VehicleDeform.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3VehicleDeform.cpp, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Physics/Deformation, [L] Revenge (SLUS_212.42) GameSource/Physics/Deformation/B4VehicleDeform.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3VehicleDeform.h"

struct UnkStruct_003E0FC0;

struct UnkStruct_003E0FC0 {
    unsigned char pad_0[0x1014];
    unsigned char field_1014;
    unsigned char field_1015;
};

// func_003E0FC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E0FC0
extern "C" void func_003E0FC0(UnkStruct_003E0FC0 * self)
{
    self->field_1014 = 2;
    self->field_1015 = (self->field_1015 | 1);
}

// func_003E6F50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E6F50
extern "C" float func_003E6F50(CB3VehicleDeform * self, bool p0)
{
    return self->GetWindscreenPos(false, p0).Z();
}

// func_003E6F90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E6F90
extern "C" float func_003E6F90(CB3VehicleDeform * self, bool p0)
{
    return self->GetWindscreenPos(true, p0).Z();
}

// CB3VehicleDeform::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// 0x00461440
void CB3VehicleDeform::Construct()
{
    field_44 = 0;
    field_14 = 0;
    field_18 = 0;
    for (int i = 0; (i < 4); i++) {
        field_90[i].field_0.SetW(0.0f);
    }
    field_4 = 0x2B9D6F8;
    field_0 = 0xFD462907;
}
