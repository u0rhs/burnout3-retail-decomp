// func_00442E90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E0684.h"

struct UnkStruct_00442E90;

struct UnkStruct_00442E90 {
    unsigned char pad_0[0x204];
    unsigned char field_204;
};

extern UnkStruct_D_004E0684 D_004E0684;
extern "C" void func_00442900(UnkStruct_00442E90 *, float, float);
extern "C" void func_004429F0(UnkStruct_00442E90 *, float, float);
extern "C" void func_00442AE0(UnkStruct_00442E90 *, float, float);

// 0x00442E90
extern "C" void func_00442E90(UnkStruct_00442E90 * self, int p0)
{
    if ((p0 & 255) == 1) {
        func_00442900(self, 0.0f, 1.0f);
        func_004429F0(self, D_004E0684.field_0, 0.0f);
        func_00442AE0(self, 0.0f, 0.0f);
    }
    self->field_204 = p0;
}
