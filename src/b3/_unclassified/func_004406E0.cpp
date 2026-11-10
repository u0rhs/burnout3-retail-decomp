// func_004406E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004D2240.h"

struct UnkStruct_004406E0;
struct UnkStruct_004406E0_0;

struct UnkStruct_004406E0_0 {
    unsigned char pad_0[0x20];
};

struct UnkStruct_004406E0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
};

extern UnkStruct_D_004D2240 D_004D2240;
extern "C" void snprintf(UnkStruct_004406E0_0 *, int, void *, int, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(UnkStruct_004406E0_0 *, int, int);

// 0x004406E0
extern "C" void func_004406E0(UnkStruct_004406E0 * self, int p0)
{
    UnkStruct_004406E0_0 local;  // [G] the frame's one local (size: up to the frame top)
    snprintf(&local, 32, &D_004D2240, self->field_4, self->field_8);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&local, p0, 32);
}
