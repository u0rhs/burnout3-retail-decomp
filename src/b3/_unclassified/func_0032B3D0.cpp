// func_0032B3D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

#include "b3/classes/UnkStruct_D_004C561C.h"
#include "b3/classes/UnkStruct_D_004C5628.h"
#include "b3/classes/UnkStruct_D_004C5634.h"
#include "b3/classes/UnkStruct_D_004C5640.h"
#include "b3/classes/UnkStruct_D_004C5648.h"
#include "b3/classes/UnkStruct_D_004C565C.h"
#include "b3/classes/UnkStruct_D_01E90240.h"

struct UnkStruct_0032B3D0;
struct UnkStruct_0032B3D0_3;

struct UnkStruct_0032B3D0_3 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
};

struct UnkStruct_0032B3D0 {
    unsigned char pad_0[0x50];
    float field_50;
    unsigned char pad_54[0x30];
    int field_84;
    unsigned char pad_88[0xC];
    signed char field_94;
    unsigned char field_95;
};

extern UnkStruct_D_004C565C D_004C565C;
extern UnkStruct_D_004C561C D_004C561C;
extern UnkStruct_D_004C5628 D_004C5628;
extern UnkStruct_D_004C5648 D_004C5648;
extern UnkStruct_D_004C5634 D_004C5634;
extern UnkStruct_D_004C5640 D_004C5640;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void func_002F9690(void *, void *, void *, void *, void *, void *, int, int, float);

// 0x0032B3D0
extern "C" void func_0032B3D0(UnkStruct_0032B3D0 * self, int p0)
{
    UnkStruct_D_01E90240 * mgr = &D_01E90240;
    float w = 0.0f;
    if (self->field_84 == 0) {
        return;
    }
    if (self->field_94 == 8) {
        w = D_004C565C.field_0;
    } else if (self->field_94 != 0 && self->field_94 != 1) {
        w = 30.0f;
    }
    if (self->field_95 != 0) {
        GtMathPs2::CGtV2d pos;
        GtMathPs2::CGtV2d scale;
        float t = D_004C5634.field_0;
        scale.Set(0.5f, 0.5f);
        pos.Set(D_004C5640.field_0, t + ((self->field_50 - 0.5f * w) - t) / 2.0f);
        func_002F9690((void *)(self->field_84), &pos, &scale, mgr, (void *)(p0), (char *)self + 0x68, 3, 0, D_004C5648.field_0);
    } else {
        GtMathPs2::CGtV2d pos;
        GtMathPs2::CGtV2d scale;
        float t = D_004C561C.field_0;
        scale.Set(0.5f, 0.5f);
        pos.Set(D_004C5628.field_0, t + ((self->field_50 - 0.5f * w) - t) / 2.0f);
        func_002F9690((void *)(self->field_84), &pos, &scale, mgr, (void *)(p0), (char *)self + 0x68, 3, 0, D_004C5648.field_0);
    }
}
