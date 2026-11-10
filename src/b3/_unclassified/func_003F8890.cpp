// func_003F8890 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E1EDC.h"
#include "b3/classes/UnkStruct_D_004E1EE0.h"

struct UnkStruct_003F8890;

struct UnkStruct_003F8890 {
    float field_0;
    unsigned char pad_4[0x19C];
    float field_1A0;
    unsigned char pad_1A4[0x4];
    float field_1A8;
};

extern UnkStruct_D_004E1EDC D_004E1EDC;
extern UnkStruct_D_004E1EE0 D_004E1EE0;
extern "C" void func_0042B4E0(void *);

// 0x003F8890
extern "C" float func_003F8890(UnkStruct_003F8890 * self, float f0)
{
    self->field_0 = f0;
    func_0042B4E0(((char *)self + 0x8));
    self->field_1A0 = (f0 * D_004E1EDC.field_0);
    float t0 = D_004E1EE0.field_0;
    self->field_1A8 = (f0 * t0);
    return (f0 * t0);
}
