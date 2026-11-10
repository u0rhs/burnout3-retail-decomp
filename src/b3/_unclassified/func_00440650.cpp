// func_00440650 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004D2228.h"
#include "b3/classes/UnkStruct_D_004D2230.h"
#include "b3/classes/UnkStruct_D_004D2238.h"

struct UnkStruct_00440650;
struct UnkStruct_00440650_1;

struct UnkStruct_00440650_1 {
    unsigned char pad_0[0x20];
};

struct UnkStruct_00440650 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8;
};

extern UnkStruct_D_004D2230 D_004D2230;
extern UnkStruct_D_004D2238 D_004D2238;
extern UnkStruct_D_004D2228 D_004D2228;
extern "C" void snprintf(UnkStruct_00440650_1 *, int, void *, int, void *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(UnkStruct_00440650_1 *, int, int);

// 0x00440650
extern "C" void func_00440650(UnkStruct_00440650 * self, int p0)
{
    UnkStruct_00440650_1 local;  // [G] the frame's one local (size: up to the frame top)
    void * v0;
    if (self->field_8 != 0) {
        v0 = &D_004D2230;
    } else {
        v0 = &D_004D2238;
    }
    snprintf(&local, 32, &D_004D2228, self->field_4, v0);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&local, p0, 32);
}
