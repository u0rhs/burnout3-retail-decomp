// NONMATCHING: func_001A3B30 -- retail 77 / ours 77 instructions, 24 in changed runs
// ghvu1: 77/77, 24 changed. Logic/calls exact (DNAT CB3HUDSpeedo::Update: W-lane speed * units factor -> PrintInt__10CGtUnicodeFPUsii, header Interpolate(field_60, field_30, 0.75), func_003824D0 with field_60 passed by address). Left: retail moves field_B0 into $vf1 once (qmtc2 in the bc1t delay slot) and reads W in each branch via sqc2 $vf1 -> slot; ours stores the GPR copy (the $vf1 stand-in folds away; .i keeps it but unhoisted, 28); downstream register shuffle in the Interpolate setup.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_001A3B30 -- hand-written (ghvu1, Ghidra-draft trial). Placeholder with C linkage; [L] DNAT: CB3HUDSpeedo::Update(float)
// (research/proto/new_names.csv, medium). Structs are declared with only the fields touched; every type is [G].
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
class CGt2dObject;
struct UnkStruct_D_0066A4C0 {
    unsigned char pad0[0x30];
    CGtV4d field_30;
    unsigned char pad40[0x20];
    CGtV4d field_60;
    unsigned char pad70[0x100];
};
extern UnkStruct_D_0066A4C0 D_0066A4C0;
struct UnkStruct_D_00665ED0_p { unsigned char pad_0[0x10]; float field_10; };
struct UnkStruct_D_00665ED0 { UnkStruct_D_00665ED0_p *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00665ED0 D_00665ED0;
extern __declspec(sdata) unsigned int D_004E2918;
extern __declspec(sdata) float D_004E0960;
extern __declspec(sdata) float D_004E0798;
extern __declspec(sdata) float D_004E08A8;
struct UnkStruct_001A3B30_c { unsigned char pad_0[0xB0]; CGtV4d field_B0; };
struct UnkStruct_001A3B30 {
    unsigned char pad_0[0x20];
    CGt2dObject *field_20;
    unsigned char pad_24[0x8];
    UnkStruct_001A3B30_c *field_2C;
    unsigned short field_30[8];
    CGtV2d field_40;
    float field_48;
};
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);
extern "C" void func_003824D0(CGt2dObject *obj, const CGtV2d &a, const CGtV2d &b, float c, CGtV4d d, CGtV4d e,
                              const unsigned short *text, int f, float g, float h);
// [L] N185: a lane read through \$vf1 (retail moves the vector into \$vf1 once and stores it from there for each W read)
static inline float func_001A3B30_inl1(u_long128 v)
{
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(v));
    return GtMathPs2::WAxisType(t);
}
// 0x001A3B30
extern "C" void func_001A3B30(UnkStruct_001A3B30 *self, float)
{
    UnkStruct_D_0066A4C0 *colours = &D_0066A4C0;
    u_long128 v = self->field_2C->field_B0.mData;
    if (self->field_48 != GtMathPs2::WAxisType(v)) {
        float s;
        if (D_004E2918 > 1) {
            s = D_004E0960 * func_001A3B30_inl1(v);
        } else {
            s = D_004E0798 * func_001A3B30_inl1(v);
        }
        PrintInt__10CGtUnicodeFPUsii(self->field_30, (int)s, 0, 0);
        func_003824D0(self->field_20, self->field_40, CGtV2d(1.0f, D_00665ED0.field_0->field_10), 48.0f, colours->field_60,
                      GtMathPs2::Interpolate(colours->field_60, colours->field_30, 0.75f), self->field_30, 0x71, 1.5f, D_004E08A8);
        self->field_48 = self->field_2C->field_B0.W();
    }
}
