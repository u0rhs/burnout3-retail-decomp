// func_003A5D10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dFrame.h"
#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_003A5D10;
struct UnkStruct_003A5D10_e3;

struct UnkStruct_003A5D10_e3 {
    unsigned char pad_0[0x8];
    CGt2dObject *field_8[1];  // [G] element count unknown
};

struct UnkStruct_003A5D10 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x26];
    CGt2dObject *field_30;
    CGt2dObject *field_34[1];  // [G] element count unknown
    unsigned char pad_38[0x14];
    CGt2dObject *field_4C[1];  // [G] element count unknown
    unsigned char pad_50[0x4];
    CGt2dObject *field_54;
    int field_58;
    CGt2dObject *field_5C;
    int field_60;
    unsigned char pad_64[0x4];
    CGt2dObject *field_68[1];  // [G] element count unknown
    unsigned char pad_6C[0xC];
    UnkStruct_003A5D10_e3 field_78[1];  // [G] element count unknown
    unsigned char pad_84[0x4C];
    int field_D0;
    int field_D4;
    int field_D8[1];  // [G] element count unknown
    unsigned char pad_DC[0x10];
    int field_EC[1];  // [G] element count unknown
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x003A5D10
extern "C" void func_003A5D10(UnkStruct_003A5D10 * self)
{
    int i;
    int i1;
    int i2;
    int i3;
    Release__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const sc = &D_01E903E0;
    for (i = 0; (i < self->field_60); i++) {
        CGt2dObject *&p = self->field_34[i];
        DestructObject__10CGt2dSceneFiP11CGt2dObject(sc, self->field_8, p);
        p = 0;
        if (i < self->field_58) {
            CGt2dObject *t0 = self->field_4C[i];
            if (t0 != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(sc, self->field_8, self->field_4C[i]);
                self->field_4C[i] = 0;
            }
        }
        if (i == 0) {
            CGt2dObject *t1 = self->field_54;
            if (t1 != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(sc, self->field_8, t1);
                self->field_54 = 0;
            }
        }
        CGt2dObject *&q = self->field_68[i];
        DestructObject__10CGt2dSceneFiP11CGt2dObject(sc, (self->field_8 + 1), q);
        q = 0;
    }
    for (i1 = 0; (i1 < 6); i1++) {
        for (i2 = 0; (i2 < 3); i2++) {
            CGt2dObject *&t2 = self->field_78[i1].field_8[i2];
            if (t2 != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(sc, (self->field_8 + 1), t2);
                t2 = 0;
            }
        }
    }
    DestructObject__10CGt2dSceneFiP11CGt2dObject(sc, self->field_8, self->field_30);
    self->field_30 = 0;
    CGt2dObject *t3 = self->field_5C;
    if (t3 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(sc, (self->field_8 + 1), t3);
        self->field_5C = 0;
    }
    Destruct__10CGt2dFrameFv((void *)self->field_D0);
    self->field_D0 = 0;
    self->field_D4 = 0;
    for (i3 = 0; (i3 < 5); i3++) {
        self->field_D8[i3] = 0;
        self->field_EC[i3] = 0;
    }
}
