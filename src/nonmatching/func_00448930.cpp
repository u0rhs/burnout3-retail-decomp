// NONMATCHING: func_00448930 -- retail 158 / ours 148 instructions, 131 in changed runs
// returns CGtV2d by value (hidden a0); switch(field_90) cases 0/5/6/default and the CGtV4d(0,0,0,0) colour temp are right. Open: retail keeps 0.0f in f4 for every zero store (swc1, not sw zero) and computes 16+40 at runtime (no fold), list height (0+(16+40))+30k then (0+a)+2k via adda/madd; constants as locals/inline params/inline getters all fold
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00448930 -- hand-finished. Returns a CGtV2d by value (hidden result pointer in a0).
// Every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

struct UnkStruct_00448930_5;

struct UnkStruct_D_004D30A8 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00448930_a1 {
    unsigned char pad_0[0x70];
    unsigned char field_70[0x1C];
    UnkStruct_00448930_5 * field_8C;
    signed char field_90;
    unsigned char pad_91[0x63];
    float field_F4;
};

struct UnkStruct_D_004D30E0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D30C0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00448930_5 {
    unsigned char pad_0[0xC];
    float field_C;
};

extern UnkStruct_D_004D30A8 D_004D30A8;
extern UnkStruct_D_004D30E0 D_004D30E0;
extern UnkStruct_D_004D30C0 D_004D30C0;

extern "C" void func_002F9690(UnkStruct_00448930_5 *, void *, void *, void *, void *, void *, int, int, float);

// [G] inlined helper (name unknown): height of an n-row list
static inline float func_00448930_list(int n)
{
    float k = (float)(n - 1);
    float a = 0.0f + (16.0f + 40.0f) + 30.0f * k;
    return 0.0f + a + 2.0f * k;
}

extern "C" GtMathPs2::CGtV2d func_00448930(UnkStruct_00448930_a1 * p0, int p1, int p2)
{
    GtMathPs2::CGtV2d r;
    float h;
    r.marValues[0] = D_004D30A8.field_0;
    switch (p0->field_90) {
    case 0: {
        GtMathPs2::CGtV2d pos;
        GtMathPs2::CGtV2d scale;
        scale.Set(0.5f, 0.5f);
        GtMathPs2::CGtV4d col(0.0f, 0.0f, 0.0f, 0.0f);
        pos.Set(0.0f, 0.0f);
        func_002F9690(p0->field_8C, &pos, &scale, &col, (void *)(p1), p0->field_70, 3, 0, D_004D30C0.field_0);
        h = p0->field_F4 = p0->field_8C->field_C + 32.0f;
        break;
    }
    case 5:
        p0->field_F4 = 16.0f;
        h = func_00448930_list(p2);
        break;
    case 6: {
        float l = func_00448930_list(p2);
        h = (p0->field_F4 = (0.0f + 32.0f) + (float)(D_004D30E0.field_0 * 5)) + l;
        break;
    }
    default: {
        float l = func_00448930_list(p2);
        GtMathPs2::CGtV2d pos;
        GtMathPs2::CGtV2d scale;
        scale.Set(0.5f, 0.5f);
        GtMathPs2::CGtV4d col(0.0f, 0.0f, 0.0f, 0.0f);
        pos.Set(0.0f, 0.0f);
        func_002F9690(p0->field_8C, &pos, &scale, &col, (void *)(p1), p0->field_70, 3, 0, D_004D30C0.field_0);
        h = (p0->field_F4 = p0->field_8C->field_C + 32.0f) + l;
        break;
    }
    }
    r.marValues[1] = 1.0f + h;
    return r;
}

