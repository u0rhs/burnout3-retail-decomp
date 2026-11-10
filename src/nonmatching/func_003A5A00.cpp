// NONMATCHING: func_003A5A00 -- retail 151 / ours 151 instructions, 16 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a131: 16 instrs off, all in the entry block scheduling (lw 0x64 / 30.0 lui hoist, lq reg); everything else exact (frame via 2 N140 pads, g const ptr)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

struct UnkStruct_D_01E90240_x {
    unsigned char pad_0[0x10];
    u_long128 field_10;
    unsigned char pad_20[0x10];
    u_long128 field_30;
};
struct UnkStruct_003A5A00_e { unsigned char pad_0[0x10]; u_long128 field_10; };
struct UnkStruct_003A5A00 {
    unsigned char pad_0[0x30];
    void * field_30;
    void * field_34[11];
    int field_60;
    int field_64;
    UnkStruct_003A5A00_e * field_68[1];
    unsigned char pad_6C[0x9C];
    int field_108;
};
struct UnkStruct_003A5A00_pad { unsigned char field_0[0x10]; UnkStruct_003A5A00_pad() {} ~UnkStruct_003A5A00_pad() {} };
struct UnkStruct_D_float { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_v2 { CGtV2d field_0; unsigned char pad_8[0x8]; };
extern UnkStruct_D_01E90240_x D_01E90240;
extern UnkStruct_D_float D_004C9E08;
extern UnkStruct_D_float D_004C9DE8;
extern UnkStruct_D_v2 D_004C9E18;
extern "C" void func_0045B460(void *, const CGtV2d &, const CGtV2d &, int, float);
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, int);
extern "C" void func_003A5040(void *, int);
extern "C" void func_003A3EA0(void *, int);

// 0x003A5A00
extern "C" void func_003A5A00(UnkStruct_003A5A00 * self, int idx)
{
    UnkStruct_D_01E90240_x * const g = &D_01E90240;
    if (idx < 0) {
        idx = 0;
    } else if (idx >= self->field_60) {
        idx = self->field_60 - 1;
    }
    CGtV2d ext;
    CGtV2d sizeA;
    CGtV2d posA;
    CGtV2d sizeB;
    CGtV2d posB;
    CGtV2d size2;
    CGtV2d pos2;
    UnkStruct_003A5A00_pad pb;
    UnkStruct_003A5A00_pad pc;
    float f21;
    float f20;
    f20 = D_004C9E08.field_0;
    self->field_68[self->field_64]->field_10 = g->field_30;
    f21 = D_004C9E08.field_0 - 30.0f;
    for (int i = 0; i < self->field_60; i++) {
        if (i == idx) {
            posA.Set(0.0f, 0.0f);
            sizeA.Set(30.0f, 0.0f + 120.0f + 50.0f * (float)i);
            func_0045B460(self->field_34[i], sizeA, posA, 0, f21);
        } else {
            posB.Set(0.0f, 0.0f);
            sizeB.Set(30.0f, 0.0f + 120.0f + 50.0f * (float)i);
            func_0045B460(self->field_34[i], sizeB, posB, 1, D_004C9DE8.field_0);
        }
    }
    if (self->field_108 != 0) {
        ext.Set(D_004C9E18.field_0.marValues[0], 32.0f * (float)self->field_60 + 18.0f * (float)(self->field_60 - 1) - 1.9f);
    } else {
        ext = D_004C9E18.field_0;
    }
    pos2.Set(0.0f, 0.0f);
    size2.Set(f20, 120.95f);
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(self->field_30, size2, pos2, ext, 0x36, 1);
    self->field_64 = idx;
    self->field_68[self->field_64]->field_10 = g->field_10;
    func_003A5040(self, self->field_64);
    func_003A3EA0(self, idx);
}
