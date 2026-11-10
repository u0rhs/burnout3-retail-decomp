// func_003359F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E06C0.h"
#include "b3/classes/UnkStruct_D_0064D384.h"

struct UnkStruct_003359F0;
struct UnkStruct_003359F0_2;
struct UnkStruct_003359F0_3;

struct UnkStruct_003359F0_2 {
    short field_0;
    unsigned char pad_2[0x2];
    int field_4;
};

struct UnkStruct_003359F0_3 {
    unsigned char pad_0[0xC];
    float field_C;
};

struct UnkStruct_003359F0 {
    unsigned char pad_0[0x30];
    UnkStruct_003359F0_2 * field_30;
    int field_34;
    int field_38;
    float field_3C;
    unsigned char pad_40[0x11];
    unsigned char field_51;
};

extern UnkStruct_D_0064D384 D_0064D384;
extern UnkStruct_D_004E06C0 D_004E06C0;
extern "C" void func_003356A0(UnkStruct_003359F0 *);

// 0x003359F0
extern "C" void func_003359F0(UnkStruct_003359F0 * self, float f0)
{
    bool v3 = false;
    if (self->field_38 != D_0064D384.field_0) {
        v3 = true;
    }
    if (self->field_51 != 0) {
        if (self->field_34 != self->field_30->field_4) {
            v3 = true;
        }
    } else {
        if (self->field_34 != self->field_30->field_0) {
            v3 = true;
        }
    }
    UnkStruct_003359F0_3 * t0 = (UnkStruct_003359F0_3 *)self->field_30;
    if (v3) {
        if (!(t0->field_C <= 0.0f)) {
            self->field_3C = D_004E06C0.field_0;
        }
    } else {
        float t1 = self->field_3C;
        if (!(t1 <= 0.0f)) {
            self->field_3C = (t1 - f0);
            if ((t1 - f0) < 0.0f) {
                self->field_3C = 0.0f;
            }
        }
    }
    func_003356A0(self);
}
