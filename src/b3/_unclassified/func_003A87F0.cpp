// func_003A87F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (i declared before layer; const scene local; CGt2dObject* fields/globals + element-pointer loop; CGtV2d temp copied to *field_24C; field_254 reread via address pun [G]).

// lifter variant 0
// func_003A87F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

class CGt2dObject;

struct UnkStruct_003A87F0;
struct UnkStruct_003A87F0_5;
struct UnkStruct_003A87F0_6;
struct UnkStruct_003A87F0_e0;
struct UnkStruct_D_004E2E94;
struct UnkStruct_D_004E2E98;
struct UnkStruct_D_004E2E9C;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01E7A800;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003A87F0_e0 {
    unsigned char pad_0[0x3C];
    int field_3C[1];  // [G] element count unknown
    unsigned char pad_40[0x30];
};

struct UnkStruct_003A87F0_5 {
    float field_0;
    int field_4;
};

struct UnkStruct_003A87F0_6 {
    float field_0;
    int field_4;
};

struct UnkStruct_D_004E2E94 {
    CGt2dObject * field_0;
};

struct UnkStruct_D_004E2E98 {
    unsigned char field_0;
};

struct UnkStruct_D_004E2E9C {
    CGt2dObject * field_0;
};

struct UnkStruct_D_01E7A800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003A87F0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x1E6];
    CGt2dObject * field_1F0[5];
    unsigned char pad_204[0x48];
    CGtV2d * field_24C;
    unsigned char pad_250[0x4];
    int field_254;
    unsigned char pad_258[0x4C];
    int field_2A4[1];  // [G] element count unknown
    unsigned char pad_2A8[0x298];
    UnkStruct_003A87F0_e0 field_540[1];  // [G] element count unknown
    unsigned char pad_5B0[0x154];
    float field_704;
    unsigned char pad_708[0x1DC];
    unsigned char field_8E4;
    unsigned char pad_8E5[0x2];
    unsigned char field_8E7;
};

extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_004E2E94 D_004E2E94;
extern UnkStruct_D_004E2E98 D_004E2E98;
extern UnkStruct_D_004E2E9C D_004E2E9C;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void func_003AE120(UnkStruct_003A87F0 *);
extern "C" void func_003A8A90(UnkStruct_003A87F0 *);
extern "C" int func_003F5D10(int);
extern "C" int func_003EA530(int);
extern "C" int func_003E9750(int, int, void *);
extern "C" int func_003E8EA0(int, int, void *);
extern "C" void func_002850B0(void *);

// 0x003A87F0
extern "C" void func_003A87F0(UnkStruct_003A87F0 * self)
{
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int i;
    int layer = self->field_8 + 8;
    func_003AE120(self);
    func_003A8A90(self);
    int t1 = D_0051BF9C.field_0;
    int n = func_003F5D10(self->field_254);
    int lim = func_003EA530(self->field_254);
    for (i = 0; i < n; i++) {
        int t2 = self->field_254;
        int t3 = self->field_540[t2].field_3C[i];
        if (t3 < lim) {
            // [G] read through an address pun: retail reloads field_254 for this call (the else arm reuses t2);
            // a plain member read is CSE'd with t2. The real source's expression is unknown.
            self->field_2A4[i] = func_003E9750(*(int *)&self->field_254, t3, (void *)(t1));
        } else {
            self->field_2A4[i] = func_003E8EA0(t2, t3, (void *)(t1));
        }
    }
    self->field_8E7 = 0;
    self->field_8E4 = 6;
    self->field_704 = 2.1000001f;
    if (self->field_24C != 0) {
        CGtV2d v(400.0f, 0.0f);  // GtMathPs2 temporary: retail keeps its stack stores
        *self->field_24C = v;
    }
    func_002850B0(&D_01E7A800);
    D_004E2E98.field_0 = 0;
    if (D_004E2E94.field_0 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer, D_004E2E94.field_0);
        D_004E2E94.field_0 = 0;
    }
    if (D_004E2E9C.field_0 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer, D_004E2E9C.field_0);
        D_004E2E9C.field_0 = 0;
    }
    for (int i1 = 0; i1 < 5; i1++) {
        CGt2dObject ** pp = &self->field_1F0[i1];
        if (*pp != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer, *pp);
            *pp = 0;
        }
    }
}
