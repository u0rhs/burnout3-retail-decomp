// NONMATCHING: func_0044D400 -- retail 180 / ours 180 instructions, 12 in changed runs
// psweep: scoped #pragma opt_treetransformation off [G] improves 16 -> 12
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// func_0044D400 -- hand-written from scratch (the lifter refused it). Unnamed, so a placeholder with C linkage.
// Layout and types are [G] (instruction widths); the row table and the column-layout inline follow the proven
// siblings func_004502A0 / func_004516B0 (func_00453380's body inlined).

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_treetransformation off
using namespace GtMathPs2;

class CGtTexture;
struct UnkStruct_0044D400_frame { CGtV2d field_0; };
struct UnkStruct_0044D400_obj { unsigned char pad_0[0x10]; CGtV4d field_10; };
struct UnkStruct_0044D400_row {
    UnkStruct_0044D400_obj *field_0;
    void *field_4;
    UnkStruct_0044D400_frame *field_8;
    unsigned char pad_C[0x18];
};
struct UnkStruct_0044D400 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[2];
    UnkStruct_0044D400_row field_C[8];
    unsigned char pad_12C[8];
    int field_134;
    int field_138;
    unsigned char pad_13C[0xC4];
    int field_200;
};
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
extern CGtV4d D_004D3140;
extern CGtV4d D_01E90350;
extern UnkStruct_P16 D_01E903E0;
extern UnkStruct_P16 D_01E7A800;
extern CGtTexture *D_01EA46AC[];
extern CGtV2d D_01EA4790[];
extern CGtV2d D_01EA4798[];

extern "C" void func_00453560(void *);
extern "C" void func_0044E400(void *, int);
extern "C" void func_0044D6D0(void *, int);
extern "C" void func_00453680(void *, int, int, int);
extern "C" void func_002840D0(void *);
extern "C" void *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    void *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);

// [G] func_00453380's body (as func_004516B0_inl1): lay rows from..to out in a column centred on base.
static inline void func_0044D400_inl1(UnkStruct_0044D400 *self, int from, int to, float base, float stride, float x)
{
    if (from != to) {
        float cnt = (float)(to - from - 1);
        float y = 0.0f + base - 0.5f * (cnt * stride);
        int i;
        for (i = from; i < to; i++) {
            self->field_C[i].field_8->field_0 = CGtV2d(x, y);
            y += stride;
        }
    }
}

// [G] inlined helper (name unknown): the image row's Prepare (its CGtV2d temporaries sit below the layout ones).
static inline void func_0044D400_inl2(UnkStruct_0044D400_row *o)
{
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
        o->field_4, CGtV2d(30.0f, 0.0f), CGtV2d(0.0f, 0.5f), CGtV2d(128.0f, 128.0f), D_01E90350,
        D_01EA46AC[0], D_01EA4790[0], D_01EA4798[0], 0);
}

static inline void func_0044D400_inl3(UnkStruct_0044D400_row *o) { func_0044D400_inl2(o); }

// 0x0044D400
extern "C" int func_0044D400(UnkStruct_0044D400 *self, int mode)
{
    int s0;
    int s1;
    func_00453560(self);
    self->field_200 = mode;
    if (mode == 2) {
        self->field_134 = 6;
    } else {
        self->field_134 = 5;
    }
    s0 = self->field_138;
    func_0044E400(self, mode);
    func_0044D400_inl1(self, s0, self->field_138, 200.0f, 40.0f, 640.0f);
    s0 = self->field_138;
    func_0044D6D0(self, mode);
    func_0044D400_inl1(self, s0, self->field_138, 350.0f, 40.0f, -640.0f);
    s0 = self->field_138;
    s1 = *(const int *)&self->field_138;
    func_00453680(self, s0, 5, 2);
    self->field_C[s0].field_0->field_10 = D_004D3140;
    UnkStruct_0044D400_row *row = &self->field_C[s0];
    row->field_4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8, self->field_C[s0].field_8);
    func_0044D400_inl3(row);
    func_002840D0(&D_01E7A800);
    self->field_138++;
    func_0044D400_inl1(self, s1, self->field_138, 340.0f, 0.0f, 640.0f);
    return 1;
}


#pragma pop
