// func_0038EAD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004EE040.h"
#include "b3/classes/UnkStruct_D_0051BAA8.h"
#include "b3/classes/UnkStruct_D_00665EA0.h"

struct UnkStruct_0038EAD0;

struct UnkStruct_0038EAD0 {
    unsigned char pad_0[0x60];
    int field_60;
    unsigned char pad_64[0x8];
    unsigned char field_6C;
    unsigned char field_6D;
    unsigned char field_6E;
    unsigned char field_6F;
    unsigned char field_70;
    unsigned char pad_71[0x1];
    unsigned char field_72;
};

extern UnkStruct_D_0051BAA8 D_0051BAA8;
extern UnkStruct_D_00665EA0 D_00665EA0;
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" void SetFrontendFrameRate__7CB3GameFb(void *, int);
extern "C" int func_003922D0(UnkStruct_0038EAD0 *);

// 0x0038EAD0
extern "C" void func_0038EAD0(UnkStruct_0038EAD0 * self)
{
    self->field_6C = 0;
    self->field_6D = 0;
    self->field_6E = 0;
    self->field_6F = 0;
    self->field_70 = 0;
    self->field_60 = 1;
    SetFrontendFrameRate__7CB3GameFb(&D_004EE040, 1);
    D_0051BAA8.field_0 = 2;
    D_00665EA0.field_0 = 1;
    self->field_72 = 0;
    func_003922D0(self);
}
