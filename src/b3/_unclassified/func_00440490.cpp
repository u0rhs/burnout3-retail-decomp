// func_00440490 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004D2200.h"

struct UnkStruct_00440490;
struct UnkStruct_00440490_1;

struct UnkStruct_00440490_1 {
    unsigned char pad_0[0x20];
};

struct UnkStruct_00440490 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_004D2200 D_004D2200;
extern "C" void snprintf(UnkStruct_00440490_1 *, int, void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(UnkStruct_00440490_1 *, int, int);

// 0x00440490
extern "C" void func_00440490(UnkStruct_00440490 * self, int p0)
{
    UnkStruct_00440490_1 local;  // [G] the frame's one local (size: up to the frame top)
    snprintf(&local, 32, &D_004D2200, self->field_4);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&local, p0, 32);
}
