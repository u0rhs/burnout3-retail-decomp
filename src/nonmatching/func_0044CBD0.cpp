// NONMATCHING: func_0044CBD0 -- retail 200 / ours 199 instructions, 30 in changed runs
// v277: logic believed right, 199/200, 30 changed. Retail keeps the time accumulator in memory (sp+0x7C, reloaded after calls): only the [G] pun macro *(float*)&acc0 reproduces it; N140 12-byte pad gives the frame; two-statement SetA stand-in (qmtc2 then vmulx.w) gives retail's case-3/4 order. Left: post-loop tail schedule (retail computes the f12 arg first, acc+=0.25 store in the jal delay slot) and the slide-in madd block order (f4/f5, pos.y load before madd)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_D_01E7A800 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E7A800 D_01E7A800;
// Same declarations as B3PromptsComponent_0031F5E0.cpp (N51 padding).
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90424 D_01E90424;
struct UnkStruct_D_01E90420 {
    float value;
    unsigned char pad[0xC];
};
extern UnkStruct_D_01E90420 D_01E90420;
struct UnkStruct_D_01E90350 {
    CGtV4d field_0;
};
extern UnkStruct_D_01E90350 D_01E90350;

extern "C" void func_00284400(void *, float, float);
extern "C" void func_00283FA0(void *);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);  // CB3HUDSoundManager::FEVerticalMove(), passed 1 more argument [G] (as func_003778D0)

struct UnkStruct_0044CBD0_obj {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
};
// [C] rows of 36 bytes from +0xC (func_0044CEF0 reads +0x18/+0x20 of the same rows)
struct UnkStruct_0044CBD0_row {
    unsigned char pad_0[0x8];
    CGtV2d *field_8;
    unsigned char pad_C[0x18];
};
struct UnkStruct_0044CBD0;
extern "C" void func_0044CEF0(UnkStruct_0044CBD0 *self, float f0, float f1);
struct UnkStruct_0044CBD0 {
    unsigned char pad_0[0xC];
    UnkStruct_0044CBD0_row field_C[8];  // [G] element count unknown
    UnkStruct_0044CBD0_obj *field_12C;
    unsigned char pad_130[0x8];
    int field_138;
    float field_13C;
    unsigned char pad_140[0x88];
    signed char field_1C8[0x3C];  // [G] element count unknown
    unsigned char field_204;
};


// 0x0044CBD0
// [G] N140/N186 frame pad: reserves retail's unused slot above the copied position (no code)
// [L] N185: stands in for a missing GtMathPs2 inline -- CGtV4d::SetA's lane write with the qmtc2 as its own
// statement (retail: qmtc2.ni before the vector's lqc2, then vmulx.w; the header's one-statement SetA loads first).
static inline void func_0044CBD0_inl2(CGtV4d &v, float a)
{
    asm("qmtc2.ni %0, $vf2" : : "r"(a));
    asm("vmulx.w %0, $vf0, $vf2x" : "+j"(v.mData));
}
struct UnkStruct_0044CBD0_pad {
    int x[3];
    UnkStruct_0044CBD0_pad() {}
    ~UnkStruct_0044CBD0_pad() {}
};
extern "C" void func_0044CBD0(UnkStruct_0044CBD0 *self, float dt)
{
    switch (D_01E90424.value) {
    case 5:
    case 2: {
        if (self->field_204 != 0)
            return;
        UnkStruct_0044CBD0_pad pad;
        int i;
        float t = self->field_13C;
        float acc0 = 0.0f;
#define acc (*(float *)&acc0)
        bool any = false;
        self->field_13C = t + dt;
        for (i = 0; i < self->field_138; i++) {
            UnkStruct_0044CBD0_row *e = &self->field_C[i];
            CGtV2d pos = *e->field_8;
            if (t - acc <= 0.0f && self->field_13C - acc >= 0.0f)
                func_00284400(&D_01E7A800, 0.75f, 1.25992f);
            if (t - acc <= 0.4f && self->field_13C - acc >= 0.4f)
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            float v = GtMath::Min(GtMath::Max(self->field_13C - acc, 0.0f), 0.4f);
            pos.marValues[0] = 640.0f + 2.5f * v * -640.0f;
            *e->field_8 = pos;
            acc += 0.4f;
            if (self->field_1C8[i] == 0)
                any = true;
        }
        if (any) {
            float d = self->field_13C - acc;
            float a = GtMath::Min(GtMath::Max(d, 0.0f), 0.25f);
            float b = GtMath::Min(GtMath::Max(d - 0.02f, 0.0f), 0.25f);
            float fa = 1.0f - 4.0f * a;
            float fb = 1.0f - 4.0f * b;
            if (fa == 0.0f && fb > 0.0f)
                func_00283FA0(&D_01E7A800);
            acc += 0.25f;
            func_0044CEF0(self, 3.76991153f * fa, 5.0f * GtMath::Min(GtMath::Max(d, 0.0f), 0.2f));
        }
        self->field_204 = self->field_13C > acc;
        break;
    }
    case 3:
    case 4: {
        CGtV4d c;
        c = D_01E90350.field_0;
        func_0044CBD0_inl2(c, D_01E90420.value);
        self->field_12C->field_10 = c;
        break;
    }
    }
}
#undef acc

