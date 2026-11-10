// func_0023B500 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E32B08.h"

struct UnkStruct_0023B500;
struct UnkStruct_0023B500_5;

struct UnkStruct_0023B500_5 {
    unsigned char pad_0[0x4F0];
    int field_4F0;
};

struct UnkStruct_0023B500 {
    unsigned char pad_0[0x4F0];
    int field_4F0;
    unsigned char pad_4F4[0xC];
    int field_500[8];
    int field_520[8];
    int field_540[8];
    int field_560[8];
    unsigned char pad_580[0x6EC];
    unsigned char field_C6C;
};

extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" UnkStruct_0023B500_5 * func_002366D0(void *, int);
extern "C" int func_0022FBB0(UnkStruct_0023B500_5 *);
extern "C" void Prepare__36CB3NetworkAllNATDataFinalisedMessageFPiP15EPlayerNATState(void *, void *, void *);

// 0x0023B500
extern "C" void func_0023B500(UnkStruct_0023B500 * self)
{
    int n;
    UnkStruct_0023B500_5 * r0;
    bool same = 1;
    int i1;
    for (int i = 0; i < 8; i++) {
        self->field_500[i] = -1;
        self->field_520[i] = 4;
    }
    n = D_01E32B08.field_0;
    for (i1 = 0; i1 < n; i1++) {
        r0 = func_002366D0(&D_01E32AE0, i1);
        if (r0 != 0) {
            self->field_500[i1] = func_0022FBB0(r0);
            self->field_520[i1] = r0->field_4F0;
        }
    }
    for (int i2 = 0; i2 < 8; i2++) {
        if (self->field_540[i2] != self->field_500[i2]) {
            same = 0;
            break;
        }
        if (self->field_560[i2] != self->field_520[i2]) {
            same = 0;
            break;
        }
    }
    if (same || (self->field_C6C & 1) == 1 || self->field_4F0 != 2) {
        return;
    }
    Prepare__36CB3NetworkAllNATDataFinalisedMessageFPiP15EPlayerNATState(&self->field_C6C, self->field_500, self->field_520);
    for (int i3 = 0; i3 < 8; i3++) {
        self->field_540[i3] = self->field_500[i3];
        self->field_560[i3] = self->field_520[i3];
    }
}
