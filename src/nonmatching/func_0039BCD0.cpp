// NONMATCHING: func_0039BCD0 -- retail 285 / ours 288 instructions, 180 in changed runs
// a152: logic complete (288 vs 285 instrs, 180 changed): switch(mode 0-3) sets field_44/48/4C + f20 + field_58, two arrow images (z=0.0f shared register: z+field_40+z*(32*(n-1))-32 / one*...+32, uv base D_01EA4790+0xD0/0xE0, colour quad stack copy), final fit via func_00372400; remaining: s-register assignment (retail s2=scene,s0=lh 8,s1=frame), constant lui/sw interleave in the switch (shared v1 for 0x44/0x48), float zero/one register sharing across the three adda/madd chains
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// func_0039BCD0 -- [L] DNAT: CB3ScrollVSelectComponent::Prepare (research/proto/new_names.csv, low); hand-written from retail (lifter refused)
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
class CGt2dFrame;
class CGtTexture;

struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; CGt2dFrame * field_14; };
struct UnkStruct_D_01E90240 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
};
struct UnkStruct_039BCD0_d { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_039BCD0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    UnkStruct_039BCD0_d * field_C;
    int field_10;
    CGt2dObject * field_14[7];
    CGt2dObject * field_30;
    CGt2dObject * field_34;
    CGt2dObject * field_38;
    int field_3C;
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
    float field_50;
    float field_54;
    signed char field_58;
    signed char field_59;
    unsigned char field_5A;
};
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_P D_01E90350, D_01EA4790;
extern UnkStruct_F D_004C9A28;
extern CGtTexture * D_01EA46B0[];
extern "C" CGt2dObject * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void func_0039BAB0(void *, int);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, const void *, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);
extern "C" void func_00372400(CGt2dObject *, const CGtV2d &, const CGtV2d &, const void *, float, float, float);

// 0x0039BCD0
extern "C" int func_0039BCD0(UnkStruct_039BCD0 * self, UnkStruct_039BCD0_d * data, void *p2_, int mode, unsigned char flag, float fv)
{
    int p2 = (int)p2_;
    float f20;
    Prepare__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int s0 = self->field_8;
    CGt2dFrame * s1 = scene->field_14;
    int fp = s0 + 1;
    self->field_50 = fv;
    switch (mode) {
    case 0:
        self->field_48 = 112.0f;
        self->field_44 = 64.0f;
        self->field_4C = 0.0f;
        f20 = 240.0f;
        self->field_58 = 7;
        break;
    case 1:
        self->field_48 = 320.0f;
        self->field_44 = 320.0f;
        self->field_4C = 0.5f;
        f20 = 288.0f;
        self->field_58 = 5;
        break;
    case 2:
        self->field_48 = 320.0f;
        self->field_44 = 320.0f;
        self->field_4C = 0.5f;
        f20 = 304.0f;
        self->field_58 = 3;
        break;
    case 3:
        self->field_48 = 320.0f;
        self->field_44 = 320.0f;
        self->field_4C = 0.5f;
        f20 = 336.0f;
        self->field_58 = 3;
        break;
    }
    self->field_C = data;
    self->field_10 = p2;
    self->field_5A = flag;
    self->field_59 = self->field_58 / 2;
    self->field_3C = -1;
    self->field_40 = 0.0f + f20 - 32.0f * (float)self->field_59;
    self->field_54 = -1.0f;
    for (int i = 0; i < self->field_58; i++) {
        self->field_14[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, fp, s1);
        func_0039BAB0(self, i);
    }
    self->field_30 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, s0, s1);
    self->field_34 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, s0, s1);
    {
        u_long128 col = D_01E90240.field_0;
        if (self->field_C->field_0 == 0) {
            col = D_01E90240.field_20;
        }
        float z = 0.0f;
        float y = z + self->field_40 + z * (32.0f * (float)(self->field_58 - 1)) - 32.0f;
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_30, CGtV2d(self->field_48, y), CGtV2d(0.5f, 0.5f), CGtV2d(17.0f, 9.0f), &col, D_01EA46B0[0], *(const CGtV2d *)((char *)&D_01EA4790 + 0xD0), *(const CGtV2d *)((char *)&D_01EA4790 + 0xD8), 0);
    }
    {
        u_long128 col = D_01E90240.field_0;
        float z = 0.0f;
        float one = 1.0f;
        float y = z + self->field_40 + one * (32.0f * (float)(self->field_58 - 1)) + 32.0f;
        if (self->field_C->field_0 == self->field_C->field_2 - 1) {
            col = D_01E90240.field_20;
        }
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_34, CGtV2d(self->field_48, y), CGtV2d(0.5f, 0.5f), CGtV2d(17.0f, 9.0f), &col, D_01EA46B0[0], *(const CGtV2d *)((char *)&D_01EA4790 + 0xE0), *(const CGtV2d *)((char *)&D_01EA4790 + 0xE8), 0);
    }
    self->field_38 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, s0, s1);
    {
        float sx = self->field_14[self->field_59]->mObjectSpace.mTopLeftPos.marValues[0];
        sx = self->field_14[self->field_59]->mObjectSpace.mSize.marValues[0];
        float w = sx + D_004C9A28.field_0;
        float z = 0.0f;
        float f14 = z + 640.0f + z * (w - 640.0f);
        float t = f14 - w;
        CGtV2d pos(-0.5f * t, z + self->field_40 + 32.0f * (float)self->field_59);
        CGtV2d anchor(0.0f, 0.5f);
        func_00372400(self->field_38, pos, anchor, &D_01E90350, 640.0f + t, z + self->field_44 - self->field_4C * sx, f14);
    }
    return 1;
}
