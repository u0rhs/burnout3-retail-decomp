// B3SatNavComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3SatNavComponent.cpp, 2 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/classes/CB3FlashText2dObject.h"
#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGt2dFrame.h"
#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_004E0824.h"
#include "b3/classes/UnkStruct_D_004E2E94.h"
#include "b3/classes/UnkStruct_D_004E2E9C.h"
#include "b3/classes/UnkStruct_D_004E2EAC.h"
#include "b3/classes/UnkStruct_D_0051A6A8.h"
#include "b3/classes/UnkStruct_D_0051A870.h"
#include "b3/classes/UnkStruct_D_0051A9A0.h"
#include "b3/classes/UnkStruct_D_0051A9A4.h"
#include "b3/classes/UnkStruct_D_01E7A800.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_003AB2E0;
struct UnkStruct_003AB2E0_3;
struct UnkStruct_003AB2E0_4;
struct UnkStruct_003AB2E0_e0;
struct UnkStruct_003AB2E0_e1;
struct UnkStruct_003AE920;
struct UnkStruct_003AE920_1;
struct UnkStruct_003AE920_e2;

struct UnkStruct_003AB2E0_e0 {
    unsigned char pad_0[0x4];
    CB3FlashText2dObject * field_4;
    unsigned char pad_8[0x4];
    UnkStruct_003AB2E0_4 * field_C;
};

struct UnkStruct_003AB2E0_3 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    unsigned char pad_10[0x10];
};

struct UnkStruct_003AB2E0_4 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003AB2E0_e1 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_003AB2E0 {
    UnkStruct_003AB2E0_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0x90];
    UnkStruct_003AB2E0_e0 field_A0[1];  // [G] element count unknown
    unsigned char pad_B0[0x1A0];
    unsigned short field_250;
    unsigned short field_252;
    unsigned char pad_254[0x4B8];
    float field_70C;
    unsigned char pad_710[0x1D5];
    signed char field_8E5;
};

struct UnkStruct_003AE920_1 {
    int field_0;
    unsigned char pad_4[0xC];
    int field_10;
    unsigned char pad_14[0xC];
};

struct UnkStruct_003AE920_e2 {
    CGt2dObject * field_0;
    CGt2dObject * field_4;
};

struct UnkStruct_003AE920 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x26];
    UnkStruct_003AE920_e2 field_30[1];  // [G] element count unknown
    unsigned char pad_38[0x12C];
    CGt2dObject * field_164[1];  // [G] element count unknown
    unsigned char pad_168[0x14];
    CGt2dObject * field_17C[1];  // [G] element count unknown
    unsigned char pad_180[0x8];
    CGt2dObject * field_188;
    CGt2dObject * field_18C[1];  // [G] element count unknown
    unsigned char pad_190[0x2C];
    CGt2dObject * field_1BC;
    CGt2dObject * field_1C0[1];  // [G] element count unknown
    unsigned char pad_1C4[0x2C];
    CGt2dObject * field_1F0[1];  // [G] element count unknown
    unsigned char pad_1F4[0x20];
    CGt2dObject * field_214;
    unsigned char pad_218[0x10];
    CGt2dFrame * field_228;
    CGt2dObject * field_22C;
    unsigned char pad_230[0x1C];
    void * field_24C;
    unsigned char pad_250[0x697];
    unsigned char field_8E7;
};

extern UnkStruct_D_004E2EAC D_004E2EAC;
extern UnkStruct_D_004E0824 D_004E0824;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_004E2E94 D_004E2E94;
extern UnkStruct_D_004E2E9C D_004E2E9C;
extern UnkStruct_D_0051A9A4 D_0051A9A4;
extern UnkStruct_D_0051A9A0 D_0051A9A0;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_0051A870 D_0051A870;
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);  // CB3HUDSoundManager::FEVerticalMove(), passed 1 more argument(s) [G]
extern "C" void func_003B0870(void *, int, float);
extern "C" void func_003AB540(UnkStruct_003AB2E0 *, float);
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(UnkStruct_D_01E903E0 *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(CGt2dFrame *);  // CGt2dFrame::Destruct()
extern "C" void func_003AB0A0(UnkStruct_003AE920 *);
extern "C" void func_003A8A90(UnkStruct_003AE920 *);
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);
extern "C" void func_00130C30(void *, int);
extern "C" void func_00130D50(void *);
extern "C" void func_00324EB0(void *);

// func_003AB2E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003AB2E0
extern "C" void func_003AB2E0(UnkStruct_003AB2E0 * self, float f0)
{
    if (self->field_8E5 != self->field_250) {
        if (self->field_8E5 >= 0) {
            func_003B0870(((char *)&self->field_0[self->field_8E5] + 0xA4), 0, 0.0f);
        }
        self->field_8E5 = self->field_250;
        func_003B0870(((char *)&self->field_0[self->field_8E5] + 0xA4), 1, 0.0f);
        func_003AB540(self, 1.0f);
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    }
    D_004E2EAC.field_0 = 0;
    for (int i = 0; i < self->field_252; i++) {
        UnkStruct_003AB2E0_4 * t1 = self->field_A0[i].field_C;
        if (t1 != 0) {
            UnkStruct_003AB2E0_3 local;
            local.field_0 = 1.0f;
            local.field_4 = 1.0f;
            local.field_8 = 1.0f;
            local.field_C = 0.0f;
            t1->field_10 = *(u_long128 *)&local;
        }
    }
    if (self->field_70C >= 0.0f) {
        float lim = D_004E0824.field_0;
        float t = self->field_70C + f0;
        self->field_70C = t;
        float s;
        if (t < lim) {
            s = 2.5f * t;
        } else {
            s = -1.0f;
        }
        CB3FlashText2dObject * t5 = ((UnkStruct_003AB2E0_e0 *)((char *)&self->field_0[self->field_8E5] + 0xA0))->field_4;
        if (t5 != 0) {
            t5->SetHFlashTimeScale(s);
        }
    }
}

// func_003AE920 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003AE920
extern "C" void func_003AE920(UnkStruct_003AE920 * self)
{
    int i;
    Release__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    short t0 = self->field_8;
    int k9 = t0 + 9;
    int k5 = t0 + 5;
    int k14 = t0 + 14;
    int k6 = t0 + 6;
    int k4 = t0 + 4;
    int k7 = t0 + 7;
    int k8 = t0 + 8;
    int k13 = t0 + 13;
    if (self->field_188 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k6, self->field_188);
        self->field_188 = 0;
    }
    for (i = 0; i < 2; i++) {
        CGt2dObject *& p = self->field_17C[i];
        if (p != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k14, p);
            p = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        CGt2dObject *& p = self->field_164[i];
        if (p != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k4, p);
            p = 0;
        }
    }
    if (self->field_214 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k7, self->field_214);
        self->field_214 = 0;
    }
    if (self->field_228 != 0) {
        Destruct__10CGt2dFrameFv(self->field_228);
        self->field_228 = 0;
    }
    for (i = 0; i < 2; i++) {
        CGt2dObject *& p = self->field_30[i].field_0;
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k7, p);
        p = 0;
        CGt2dObject *& q = self->field_30[i].field_4;
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k7, q);
        q = 0;
    }
    for (i = 0; i < 12; i++) {
        CGt2dObject *& p = self->field_18C[i];
        if (p != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k8, p);
            p = 0;
        }
    }
    if (self->field_1BC != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k13, self->field_1BC);
        self->field_1BC = 0;
    }
    if (self->field_24C != 0) {
        func_003AB0A0(self);
    }
    func_003A8A90(self);
    if (self->field_22C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k5, self->field_22C);
        self->field_22C = 0;
    }
    for (i = 0; i < 12; i++) {
        CGt2dObject *& p = self->field_1C0[i];
        if (p != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k9, p);
            p = 0;
        }
    }
    if (D_004E2E94.field_0 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k8, D_004E2E94.field_0);
        D_004E2E94.field_0 = 0;
    }
    if (D_004E2E9C.field_0 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k8, D_004E2E9C.field_0);
        D_004E2E9C.field_0 = 0;
    }
    for (i = 0; i < 5; i++) {
        CGt2dObject *& p = self->field_1F0[i];
        if (p != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k8, p);
            p = 0;
        }
    }
    if (D_0051A9A4.field_0 != 26) {
        func_00130C70(&D_0051A6A8);
        func_00130D00(&D_0051A6A8);
        func_00130C30(&D_0051A6A8, 26);
    loop:  // [G] goto shape: retail places the wait loop's body after the exit path (as func_003AB0A0)
        if (D_0051A9A0.field_0 != 23) {
            goto body;
        }
    }
    func_00324EB0(&D_0051A870);
    self->field_8E7 = 0;
    return;
body:
    func_00130D50(&D_0051A6A8);
    goto loop;
}
