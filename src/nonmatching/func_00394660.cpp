// NONMATCHING: func_00394660 -- retail 132 / ours 132 instructions, 4 in changed runs
// near2: 4 off (was 13). Control flow fixed: one if (field_38 != t || (field_CC != 0 && field_D4 != field_34->field_7C)) {update} (gives retail's out-of-line beq ret / b update+4 with the lwc1 copied into the slot), tail 'if (CC != 0) func_00394280(self);' then return; zero: label after. k_t declared before p (t in a1), a.field_4/a.field_0 stores before pos.Set. Left: lui a1,0x3E80 (t) and lui 0x4210 scheduled early -- same residual as func_00394280 (retail places t's lui after the by-value pointer addiu). Tried: k_t at 9 positions, split decl/assign, x/y locals, store orders, opt_repositioncode/optimizecontrolflow/rebuildconditionals/treetransformation off.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// NONMATCHING: func_00394660 -- retail 132 / ours 132 instructions, 24 in changed runs
// v256: logic + layout right (DNAT-adjacent CB3HUDLapTimer time update: m:s.cc snprintf, ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi, Interpolate colour, func_003824D0 text render, goto-form out-of-line 'unchanged' and zero blocks). 24 off: GPR choice (p in a0 vs v1, Interpolate's 0.25 in a1 hoisted early), store/argument scheduling around the Interpolate, and the same-block's beq ret + b update (ours folds to bne update). Interpolate needs .i moves here (v256_interp stand-in; header CGtV4d Interpolate's .ni moves fold to lqc2/sqc2)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_00394660 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_00394660;
struct UnkStruct_00394660_1;
struct UnkStruct_00394660_2;
struct UnkStruct_00394660_3;
struct UnkStruct_D_004C98C0;
struct UnkStruct_D_0066A4C0;

struct UnkStruct_00394660_1 {
    unsigned char pad_0[0x7C];
    int field_7C;
    unsigned char pad_80[0x248];
    float field_2C8;
};

struct UnkStruct_00394660_2 {
    unsigned char pad_0[0x20];
    GtMathPs2::CGtV4d field_20;
    int field_30;
    float field_34;
    float field_38;
    float field_3C;
};

struct UnkStruct_00394660_3 {
    float field_0;
    float field_4;
    float field_8;
};

struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x30];
    GtMathPs2::CGtV4d field_30;
    unsigned char pad_40[0x20];
    GtMathPs2::CGtV4d field_60;
};

struct UnkStruct_D_004C98C0 { char field_0[0x10]; };

struct UnkStruct_00394660 {
    unsigned char pad_0[0x20];
    int field_20;
    UnkStruct_00394660_3 * field_24;
    unsigned char pad_28[0xC];
    UnkStruct_00394660_1 * field_34;
    float field_38;
    unsigned char pad_3C[0x4];
    char field_40[0x8C];
    unsigned char field_CC;
    unsigned char pad_CD[0x7];
    int field_D4;
};

extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_004C98C0 D_004C98C0;

extern "C" float func_00155280(float);
extern "C" int snprintf(char *, int, const char *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const char *, void *, int);
extern "C" void func_003824D0(void *, const void *, const void *, const void *, const void *, void *, int, float, float, float);
extern "C" void func_00394280(UnkStruct_00394660 *);

struct UnkStruct_00394660_p { int field_0; float field_4; };
// [L] N185: Interpolate(CGtV4d, CGtV4d, float) stand-in: the header body with `.i` moves for b and the vmaddx result
// (retail keeps lq + qmtc2 and qmfc2 + sq unfolded here, N190)


// 0x00394660
extern "C" void func_00394660(UnkStruct_00394660 * self)
{
    int m, s, c;
    float t = func_00155280(self->field_34->field_2C8);
    if (t < 5.0f) {
        if (t < self->field_38) t = self->field_38;
    }
    if (self->field_38 != t || (self->field_CC != 0 && self->field_D4 != self->field_34->field_7C)) {
    UnkStruct_D_0066A4C0 * const g = &D_0066A4C0;
    self->field_38 = t;
    if (3.4028235e+38f == t) goto zero;
    m = (int)(0.016666668f * t);
    {
        float r = t - 60.0f * (float)(int)(t / 60.0f);
        s = (int)r;
        c = (int)(100.0f * (r - (float)s)) % 100;
    }
fmt:
    GtMathPs2::CGtV2d pos;
    UnkStruct_00394660_p a;
    GtMathPs2::CGtV4d col;
    char buf[0x20];
    snprintf(buf, 31, D_004C98C0.field_0, m, s, c);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_40, 32);
    float k_t = 0.25f;
    UnkStruct_00394660_3 * p = self->field_24;
    float py = p->field_4;
    float px = p->field_0;
    float pz = p->field_8;
    a.field_4 = 0.5f;
    a.field_0 = 0;
    pos.Set((px + pz) - 112.0f, (36.0f + py) - 22.0f);
    col = GtMathPs2::Interpolate(g->field_60, g->field_30, k_t);
    func_003824D0((void *)(self->field_20), &pos, &a, &col, &g->field_30, self->field_40, 97, 30.0f, 1.25f, 3.4028235e+38f);
    if (self->field_CC != 0) func_00394280(self);
    }
    return;
zero:
    m = 0; s = 0; c = 0;
    goto fmt;
}
