// NONMATCHING: func_00455B20 -- retail 269 / ours 269 instructions, 9 in changed runs
// 9 off: only an s0/s2 swap of the CSE'd &field_48[i] / &field_C[i] addresses; pointer locals, block forms, decl orders, sreg (2 rounds) and the 15-pragma sweep don't flip it
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00455B20 -- hand-written (ghvu16) from the Ghidra draft and retail. Unnamed in every table, so the asm label
// with C linkage; `self` is whatever a0 points to. Every type is [G] (instruction widths). Literals: retail .lit4 values
// (1.2*pi, pi/180, 0.05, 0.001). The five rows i = 0..4 are a switch (retail tests 4, 2, 1, 3, 0 = reverse source order).
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_00455B20_o {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
    unsigned char pad_20[0xC];
    float field_2C;
    unsigned char pad_30[0x7];
    unsigned char field_37;
};
struct UnkStruct_00455B20_e { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E903E0_b { unsigned char pad_0[0x2C]; UnkStruct_00455B20_e *field_2C; };
struct UnkStruct_D_01E90240_b { unsigned char pad_0[0x110]; CGtV4d field_110; };
struct UnkStruct_00455B20 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    UnkStruct_00455B20_o *field_C[5];
    unsigned char field_20[5];
    unsigned char pad_25[0x3];
    CGtV2d field_28[2];
    CGtV2d field_38[2];
    float field_48[5];
    float field_5C[5];
    float field_70;
};

extern UnkStruct_D_01E903E0_b D_01E903E0;
extern UnkStruct_D_01E90240_b D_01E90240;
extern const unsigned char D_004D34E8[];
extern const float D_004D34B0[];
extern char D_01E7A800[];
extern "C" void func_00283DB0(void *);
extern "C" void func_00283DF0(void *);
extern "C" void func_00283E30(void *);

// 0x00455B20
extern "C" void func_00455B20(UnkStruct_00455B20 * self)
{
    UnkStruct_D_01E90240_b * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0_b * const scene = &D_01E903E0;
    for (int i = 0; i < 5; i++) {
        if (self->field_C[i] == 0) continue;
        if (self->field_70 < self->field_48[i]) continue;
        unsigned char k = D_004D34E8[i];
        scene->field_2C[self->field_8 + k].field_0 = 0;
        float t = GtMath::Min(GtMath::Max((self->field_70 - self->field_48[i]) / D_004D34B0[i], 0.0f), 1.0f);
        float inv = 1.0f - t;
        CGtV4d c;
        c = self->field_C[i]->field_10;
        c.SetA(1.0f);
        if (i == 3) c.SetA(1.0f - inv);
        self->field_C[i]->field_10 = c;
        switch (i) {
        case 0:
        case 3:
            self->field_C[i]->field_2C = 3.769911528f * inv;
            if (self->field_20[i] == 0) {
                func_00283DB0(D_01E7A800);
                self->field_20[i] = 1;
            }
            break;
        case 1:
        case 2: {
            float s = sinf(0.01745329238f * (360.0f * (self->field_70 - (self->field_48[i] + D_004D34B0[i]))));
            float scale = (1.0f - inv) * (1.0f + 0.05f * s);
            scale += 0.001f;
            int j = i - 1;
            CGtV2d size = self->field_38[j] * scale;
            self->field_C[i]->field_0 = self->field_28[j] - (size - self->field_38[j]) * 0.5f;
            self->field_C[i]->field_8 = size;
            if (self->field_20[i] == 0) {
                func_00283E30(D_01E7A800);
                self->field_20[i] = 1;
            }
            break;
        }
        case 4:
            if (self->field_20[i] == 0) {
                func_00283DF0(D_01E7A800);
                self->field_20[i] = 1;
            }
            self->field_C[i]->field_37 = (int)(0.5f + 255.0f * inv);
            break;
        }
        float d = self->field_5C[i];
        if (d != -1.0f) {
            float e = self->field_48[i] + d;
            if (!(self->field_70 <= e)) {
                float a = 1.0f - GtMath::Min(GtMath::Max((self->field_70 - e) / 0.5f, 0.0f), 1.0f);
                if (a == 0.0f) {
                    scene->field_2C[self->field_8 + k].field_0 = 1;
                } else {
                    CGtV4d c2;
                    c2 = mgr->field_110;
                    c2.SetA(a);
                    self->field_C[i]->field_10 = c2;
                }
            }
        }
    }
}
