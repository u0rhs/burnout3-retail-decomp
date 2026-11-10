// func_00442AE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E261C.h"
#include "b3/classes/UnkStruct_D_004E2620.h"
#include "b3/classes/UnkStruct_D_004E2624.h"
#include "b3/classes/UnkStruct_D_004E2628.h"
#include "b3/classes/UnkStruct_D_004E262C.h"

struct UnkStruct_00442AE0;

struct UnkStruct_00442AE0 {
    unsigned char pad_0[0xE8];
    int field_E8;
    unsigned char pad_EC[0x4];
    int field_F0;
    unsigned char pad_F4[0x40];
    int field_134;
    unsigned char pad_138[0x4];
    int field_13C;
    int field_140;
    unsigned char pad_144[0x34];
    int field_178;
    unsigned char pad_17C[0x30];
    int field_1AC;
    unsigned char pad_1B0[0x4];
    int field_1B4;
    int field_1B8;
    int field_1BC;
    unsigned char pad_1C0[0x4];
    int field_1C4;
    unsigned char pad_1C8[0x3C];
    unsigned char field_204;
};

extern __declspec(sdata) const UnkStruct_D_004E262C D_004E262C;
extern __declspec(sdata) const UnkStruct_D_004E2624 D_004E2624;
extern __declspec(sdata) const UnkStruct_D_004E2628 D_004E2628;
extern __declspec(sdata) const UnkStruct_D_004E261C D_004E261C;
extern __declspec(sdata) const UnkStruct_D_004E2620 D_004E2620;
extern "C" void lgDevStopForceEffect(int);
extern "C" float fabsf(float);
extern "C" void lgDevUpdateForceEffect(int, void *);
extern "C" void lgDevStartForceEffect(int);

// 0x00442AE0
extern "C" void func_00442AE0(UnkStruct_00442AE0 * self, float f0, float f1)
{
    if (self->field_204 == 0 && !(0.0f == f0)) {
        if (fabsf(f1) > 0.05f) {
            lgDevStopForceEffect(self->field_E8);
            lgDevStopForceEffect(self->field_F0);
            float g1 = D_004E2620.field_0;
            float g0 = D_004E261C.field_0;
            self->field_134 = 200;
            self->field_13C = (int)(g0 + g1 * f0);
            if (f1 < 0.0f) {
                self->field_140 = 90;
            } else {
                self->field_140 = 270;
            }
            lgDevUpdateForceEffect(self->field_E8, ((char *)self + 0x130));
            lgDevStartForceEffect(self->field_E8);
        } else {
            lgDevStopForceEffect(self->field_E8);
            lgDevStopForceEffect(self->field_F0);
            self->field_1AC = (unsigned int)D_004E262C.field_0;
            float g2 = D_004E2624.field_0;
            self->field_1B4 = (int)(g2 + D_004E2628.field_0 * f0);
            self->field_1B8 = 90;
            self->field_1BC = 100;
            self->field_1C4 = self->field_178;
            lgDevUpdateForceEffect(self->field_F0, ((char *)self + 0x1A8));
            lgDevStartForceEffect(self->field_F0);
        }
    } else {
        lgDevStopForceEffect(self->field_E8);
        lgDevStopForceEffect(self->field_F0);
    }
}
