// NONMATCHING: func_00461A70 -- retail 152 / ours 152 instructions, 3 in changed runs
// fresh2: 152/152, 3 in changed runs. Scoped opt_repositioncode off [G] + goto-form out-of-line blocks (call, clamp, case-2 reset) in retail order; clamp through a function-scope float *py = &v.marValues[1] (frame 0x50 -> 0x40); SetA split so the qmtc2.ni hoists. Left: cases 1-3 subtract dt from f20 (retail uses the incoming f12 there; f20 only in case 0, which calls). Tried a d0 = dt copy (top / in case 0), -=, opt_lifetimes on/off
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00461A70 -- hand-written from the lifted draft (fresh2).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_00461A70_5 {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
};

struct UnkStruct_D_0051A870 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E88A80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00461A70 {
    unsigned char pad_0[0xC];
    void * field_C[32];
    unsigned char pad_8C[0x10];
    float field_9C;
    float field_A0;
    float field_A4;
    unsigned char pad_A8[0x4];
    int field_AC;
};

extern UnkStruct_D_0051A870 D_0051A870;
extern UnkStruct_D_01E88A80 D_01E88A80;

extern "C" void func_004617B0(UnkStruct_00461A70 *);
extern "C" float func_00324EF0(void *);
extern "C" void func_0031D920(void *, float);

// [G] CGtV4d::SetA's body with the scalar move as its own statement (MWCC hoists it out of the loop, as retail).
static inline void func_00461A70_inl1(CGtV4d & c, float a)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(a));
    asm("vmulx.w %0, $vf0, %1x" : "+j"(c.mData) : "j"(s));
}

// N182: [G] scoped to this function (goto-form out-of-line blocks need it, BRIEF near16)
#pragma push
#pragma opt_repositioncode off
// 0x00461A70
extern "C" void func_00461A70(UnkStruct_00461A70 * self, float dt)
{
    float a;
    float * py;
    switch (self->field_AC) {
    case 0: {
        float k;
        int i;
        CGtV2d * p;
        float t = self->field_A0;
        if (t != -1.0f) {
            self->field_A0 = t - dt;
            if (t - dt < 0.0f) {
                self->field_AC = 1;
                self->field_A0 = 3.0f;
            }
        }
        if (self->field_9C <= 0.0f) {
            goto call;
        }
        self->field_9C = self->field_9C - dt;
        if (self->field_9C <= 0.0f) {
            self->field_9C = 0.0f;
        }
    back0:
        k = self->field_A4;
        for (i = 0; i < 32; i++) {
            p = (CGtV2d *)self->field_C[i];
            if (p != 0) {
                CGtV2d v = *p - CGtV2d(0.0f, k * dt);
                py = &v.marValues[1];
                if (*py < -128.0f) {
                    goto clamp;
                }
            back1:
                *p = v;
            }
        }
        break;
    }
    case 1:
        self->field_A0 = self->field_A0 - dt;
        if (!(self->field_A0 <= 0.0f)) {
            return;
        }
        self->field_AC = 2;
        self->field_A0 = 1.0f;
        func_0031D920(&D_01E88A80, 1.0f + func_00324EF0(&D_0051A870));
        break;
    case 2:
        self->field_A0 = self->field_A0 - dt;
        a = self->field_A0;
        if (a <= 0.0f) {
            goto reset;
        }
    back2:
        for (int i = 0; i < 32; i++) {
            UnkStruct_00461A70_5 * o = (UnkStruct_00461A70_5 *)self->field_C[i];
            if (o != 0) {
                func_00461A70_inl1(o->field_10, a);
            }
        }
        break;
    case 3:
        self->field_A0 = self->field_A0 - dt;
        if (!(self->field_A0 < 0.0f)) {
            return;
        }
        self->field_A0 = 0.0f;
        break;
    }
    return;
call:
    func_004617B0(self);
    goto back0;
clamp:
    *py = -128.0f;
    goto back1;
reset:
    self->field_AC = 3;
    self->field_A0 = 0.1f;
    a = 0.0f;
    goto back2;
}

#pragma pop
