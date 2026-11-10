// func_003BD4B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (mgr/scene const-pointer locals declared after x (before a = t0 + 2): retail's prologue schedule and s1/s2; y without the explicit 0.0f (MWCC's own adda zero) (pass3a)).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
class CGt2dFrame;
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; GtMathPs2::CGtV4d field_10; };
struct UnkStruct_D_01E89810 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_01E8980A { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E89800 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01EA4724 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_vv { unsigned char pad_0[0x10]; };
struct UnkStruct_003BD4B0_e { unsigned char pad_0[0xD]; unsigned char field_D; unsigned char field_E; unsigned char pad_F[0x5]; };
struct UnkStruct_003BD4B0_o { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_003BD4B0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x6];
    UnkStruct_003BD4B0_e * field_10;
    unsigned char pad_14[0x24];
    UnkStruct_003BD4B0_o * field_38[1];
    unsigned char pad_3C[0x68];
    void * field_A4;
    void * field_A8;
    unsigned char pad_AC[0x2C];
    CGt2dFrame * field_D8;
    unsigned char pad_DC[0x8];
    float field_E4;
    int field_E8;
    float field_EC;
};
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E89810 D_01E89810;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01EA4724 D_01EA4724;
extern UnkStruct_D_vv D_01EA48C0;
extern UnkStruct_D_vv D_01EA48C8;
extern UnkStruct_D_vv D_01EA48D0;
extern UnkStruct_D_vv D_01EA48D8;
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, GtMathPs2::CGtV4d, void *, const void *, const void *, unsigned int);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

#pragma push
#pragma opt_repositioncode off
// 0x003BD4B0
extern "C" void func_003BD4B0(UnkStruct_003BD4B0 * self, int idx, float f12)
{
    int t0 = self->field_8;
    float y = self->field_E4 + 32.0f * (float)idx;
    float x = f12;
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int a = t0 + 2;
    if ((unsigned)(self->field_10[idx].field_D - 2) <= 6 && self->field_10[idx].field_E == 0) {
        if (self->field_A4 == 0) goto mk1;
b1:
        if (self->field_A8 == 0) goto mk2;
b2:
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_A4, CGtV2d(x - 5.0f, y), CGtV2d(1.0f, 0.5f), CGtV2d(12.0f, 21.0f), mgr->field_10, D_01EA4724.field_0, &D_01EA48C0, &D_01EA48C8, 0);
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_A8, CGtV2d(5.0f + (x + self->field_38[idx]->field_8), y), CGtV2d(0.0f, 0.5f), CGtV2d(12.0f, 21.0f), mgr->field_10, D_01EA4724.field_0, &D_01EA48D0, &D_01EA48D8, 0);
        if (D_01E8980A.field_0 != 0) {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 0x100, 0xF);
        } else {
            func_0031ECD0(&D_01E89800, 0x100, 0xF);
        }
        self->field_E8 = 0;
        self->field_EC = 1.0f;
        goto rt;
    }
    if (self->field_A4 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_A4);
        self->field_A4 = 0;
    }
    if (self->field_A8 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_A8);
        self->field_A8 = 0;
    }
    if (D_01E8980A.field_0 == 0) goto end;
    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 0x100, 3);

rt:
    return;
mk1:
    self->field_A4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, a, self->field_D8);
    goto b1;
mk2:
    self->field_A8 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, a, self->field_D8);
    goto b2;
end:
    ;
}
#pragma pop
