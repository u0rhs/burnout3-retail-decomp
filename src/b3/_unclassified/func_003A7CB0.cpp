// func_003A7CB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (pass2e: float one assigned 1.0f in each arm (after sinf in the m==2 arm) so the fmod divisor is not CSE'd into f20).

// fresh2: 152 vs 153, 7 in changed runs. CGtV4d(x,y,z,w) colour + N140 0x30 pad (frame exact), inverted last if (call temps' slots), track id computed before the call, field_290 = 0 in both arms, field_264 read early, separate D_01EA4630/D_01EA4634 externs, colour before arg in the else arm. Left: the m==2 fmod's 1.0 divisor shares f20 with the later 1.0f (retail: f3 before sinf, f20 = mtc1 a0 after). Tried literal/named/inline-param divisor

// func_003A7CB0 -- hand-written from the lifted draft (fresh2).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to. Callee signatures from their proven sources.

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

class CGt2dObject;
struct CGtBezierCurveRenderData;

struct UnkStruct_003A7CB0_e {
    void * field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_003A7CB0_r {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
};

struct UnkStruct_003A7CB0_o {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
};

struct UnkStruct_003A7CB0 {
    unsigned char pad_0[0xB0];
    UnkStruct_003A7CB0_e field_B0[1];  // [G] element count unknown
    unsigned char pad_C0[0x16C];
    UnkStruct_003A7CB0_o * field_22C;
    unsigned char pad_230[0x24];
    int field_254;
    unsigned char pad_258[0xC];
    int field_264;
    unsigned char pad_268[0x24];
    float field_28C;
    unsigned char field_290;
    unsigned char pad_291[0x3];
    int field_294;
    int field_298;
    float field_29C;
    float field_2A0;
    unsigned char pad_2A4[0x5C];
    void * field_300;
    unsigned char pad_304[0x5E0];
    signed char field_8E4;
    unsigned char pad_8E5;
    unsigned char field_8E6;
};

struct UnkStruct_D_01E88D40 {
    unsigned short field_0;
    unsigned char pad_2[0xE];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA4630 {
    const void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E88D40 D_01E88D40;
extern UnkStruct_D_01EA4630 D_01EA4630;
extern UnkStruct_D_01EA4630 D_01EA4634;

extern "C" unsigned long GetCrashStageGtID__26CB3HardCodedCrashStageListFi(int);
extern "C" unsigned long GetStageGtID__25CB3HardCodedRaceStageListFii(int, int);
extern "C" unsigned long GetStageTrackID__25CB3HardCodedRaceStageListFUl(unsigned long);
extern "C" UnkStruct_003A7CB0_r * func_003E8E00(unsigned long);
extern "C" float func_003EA880(unsigned long);
extern "C" void func_003EA4C0(int, int, int *, int *);
extern "C" void func_0041E260(UnkStruct_003A7CB0_o *, const CGtV2d &, const CGtV2d &, const CGtV4d,
                              CGtBezierCurveRenderData *, float, const void *);

// [G] N140 pad: retail's frame keeps three unused 16-byte slots below the colour (by-value copies elided).
struct UnkStruct_003A7CB0_pad {
    int x[12];
    UnkStruct_003A7CB0_pad() {}
    ~UnkStruct_003A7CB0_pad() {}
};

static inline float func_003A7CB0_inl1(float a, float b)
{
    return a - b * (float)(int)(a / b);
}

// 0x003A7CB0
extern "C" void func_003A7CB0(UnkStruct_003A7CB0 * self, float dt)
{
    float one;
    const void * arg;
    CGtV4d colour;
    UnkStruct_003A7CB0_pad pad;
    signed char m = self->field_8E4;
    if (m == 2) {
        float t = func_003A7CB0_inl1(self->field_28C + dt, 1.0f);
        self->field_28C = t;
        float s = sinf(0.017453292f * (360.0f * t));
        one = 1.0f;
        colour = CGtV4d(one, one, one, 0.75f + 0.25f * s);
        arg = D_01EA4634.field_0;
    } else if (m == 3) {
        one = 1.0f;
        arg = D_01EA4630.field_0;
        colour = CGtV4d(one, one, one, one);
    } else {
        one = 1.0f;
        colour = CGtV4d(one, one, one, dt);
        arg = D_01EA4634.field_0;
    }
    self->field_22C->field_10 = colour;
    int n = self->field_264;
    if (self->field_290 == 0) {
        return;
    }
    if (self->field_8E6 != 0 && self->field_8E4 == 3) {
        UnkStruct_003A7CB0_r * r = func_003E8E00(GetCrashStageGtID__26CB3HardCodedCrashStageListFi((int)(self->field_B0[D_01E88D40.field_0].field_0)));
        self->field_294 = r->field_C;
        self->field_298 = r->field_10;
        self->field_2A0 = one;
    } else {
        func_003EA4C0(self->field_254, n, &self->field_294, &self->field_298);
        self->field_2A0 = one;
    }
    self->field_29C = 10.0f;
    if (self->field_8E6 != 0 || self->field_8E4 != 3) {
        func_0041E260(self->field_22C, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), colour, (CGtBezierCurveRenderData *)&self->field_294, -0.2f, arg);
        self->field_290 = 0;
    } else {
        unsigned long track = GetStageTrackID__25CB3HardCodedRaceStageListFUl(GetStageGtID__25CB3HardCodedRaceStageListFii((int)(self->field_300), 0));
        func_0041E260(self->field_22C, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), colour, (CGtBezierCurveRenderData *)&self->field_294, 0.2f * func_003EA880(track), arg);
        self->field_290 = 0;
    }
}
