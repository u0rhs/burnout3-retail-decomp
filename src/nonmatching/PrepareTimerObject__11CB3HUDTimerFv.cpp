// NONMATCHING: PrepareTimerObject__11CB3HUDTimerFv -- retail 166 / ours 166 instructions, 8 in changed runs
// near20: 20 -> 8. t of the float sites moved by its own mfc1 asm statement (v296) inside a second stand-in near20_interpf; first site's 0.75f as a float local declared before the c0 copy (GPR names exact). Left: the result's qmfc2 after vmaddx is scheduled past lui/mtc1/c.lt.s (site 1) and past lq/mfc1 (site 2); retail keeps it right after vmaddx. noreorder around vmaddx+qmfc2 adds nops (v305).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: PrepareTimerObject__11CB3HUDTimerFv -- retail 166 / ours 168 instructions, 20 in changed runs
// v285: logic complete (168/166, frame 0x110 exact, flag block exact). Interpolate via [L] N185 compiler-chosen stand-in (vaddax+qmtc2.ni t+vmsubax in one statement, b moved qmtc2.i, vmaddx+qmfc2.i) -- reproduces retail's VU registers at all 3 sites (a=vf2,t=vf1,b=vf3 / b reused in vf3 / a=vf1,t=vf2,b->vf1); the header N94 body hard-codes t on vf2 and cannot. Element reload = (*(T * const *)&scene->field_2C)[layer]; frame = a-by-ref/b-by-value stand-in params + one N140 pad. Left (2 nops + GPR names): b119p schedules the t mfc1 after vaddax (sub.s; vaddax; mfc1; nop; qmtc2) where retail has sub.s; mfc1; vaddax; qmtc2, and delays the first result's qmfc2 past c.lt.s; GPRs a0/v1/v0 rotate. .set noreorder regions add round trips (worse).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// CB3HUDTimer::PrepareTimerObject(): time left t = clamp(end - now, 0, end); prints "m:ss" into the text,
// blends the colours towards red under 11 s, flags the object (bit 0) when about to run out. [G] meanings.
struct UnkStruct_003C23A0_p { unsigned char pad_0[0xC]; float field_C; unsigned char pad_10[0x2C0]; float field_2D0; };
struct UnkStruct_003C23A0_o { unsigned int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003C23A0_sc { unsigned char pad_0[0x2C]; UnkStruct_003C23A0_o *field_2C; };
struct UnkStruct_003C23A0_e1 { unsigned char pad_0[0x14]; UnkStruct_003C23A0_sc field_14; unsigned char pad_44[0x2C]; };
struct UnkStruct_003C23A0_x { float field_0; };
struct UnkStruct_003C23A0_f { unsigned char pad_0[0x10]; float field_10; };
struct UnkStruct_D_00665ED0 { UnkStruct_003C23A0_f *field_0; unsigned char pad_4[0xFC]; };
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x30];
    CGtV4d field_30;
    unsigned char pad_40[0x10];
    CGtV4d field_50;
    CGtV4d field_60;
};
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern char D_004CA338[];
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);
extern "C" void func_003824D0(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, unsigned short *, int, float, float);
// [L] N185: stands in for GtMathPs2::Interpolate(CGtV4d, CGtV4d, float) on compiler-chosen registers (header N94 body
// hard-codes t on $vf2; retail's first call here has t on $vf1, b on $vf3). Moves of b and the result written .i (fixup -> .ni).
static inline CGtV4d v285_interp(const CGtV4d &a, CGtV4d b, float t)
{
    u_long128 tv, bv, r, rr;
    asm("vaddax.xyzw $ACC, %1, $vf0x" "\n\t" "qmtc2.ni %2, %0" "\n\t" "vmsubax.xyzw $ACC, %1, %0x" : "=&j"(tv) : "j"(a.mData), "r"(t));
    asm("qmtc2.i %1, %0" : "=j"(bv) : "r"(b.mData));
    asm("vmaddx.xyzw %1, %2, %3x" "\n\t" "qmfc2.i %0, %1" : "=r"(rr), "=&j"(r) : "j"(bv), "j"(tv));
    return CGtV4d(rr);
}
// [L] N185 variant for a float-register t: its own mfc1 statement (v296) so it schedules ahead of vaddax.
static inline CGtV4d near20_interpf(const CGtV4d &a, CGtV4d b, float t)
{
    u_long128 tv, bv, r, rr;
    int ti;
    asm("mfc1 %0, %1" : "=r"(ti) : "f"(t));
    asm("vaddax.xyzw $ACC, %1, $vf0x" "\n\t" "qmtc2.ni %2, %0" "\n\t" "vmsubax.xyzw $ACC, %1, %0x" : "=&j"(tv) : "j"(a.mData), "r"(ti));
    asm("qmtc2.i %1, %0" : "=j"(bv) : "r"(b.mData));
    asm("vmaddx.xyzw %1, %2, %3x" "\n\t" "qmfc2.i %0, %1" : "=r"(rr), "=&j"(r) : "j"(bv), "j"(tv));
    return CGtV4d(rr);
}
struct UnkStruct_003C23A0_pad { int x[4]; UnkStruct_003C23A0_pad() {} ~UnkStruct_003C23A0_pad() {} };
class CB3HUDTimer {
public:
    void PrepareTimerObject();
    unsigned char pad_0[0x4];
    UnkStruct_003C23A0_e1 *field_4;
    unsigned char pad_8[0x8];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    int field_20;
    UnkStruct_003C23A0_x *field_24;
    unsigned char pad_28[0x4];
    UnkStruct_003C23A0_p *field_2C;
    float field_30;
    unsigned char field_34;
    unsigned char pad_35;
    unsigned short field_36[8];
};
// 0x003C23A0
void CB3HUDTimer::PrepareTimerObject()
{
    UnkStruct_D_0066A4C0 * const colours = &D_0066A4C0;
    UnkStruct_003C23A0_sc *scene = &field_4[field_1C].field_14;
    int layer = field_10;
    float t = field_2C->field_2D0 - field_2C->field_C;
    if (!(t <= field_2C->field_2D0)) t = field_2C->field_2D0;
    if (t < 0.0f) t = 0.0f;
    field_30 = t;
    CGtV4d c0;
    CGtV4d c1;
    char buf[64];
    UnkStruct_003C23A0_pad pad;  // N140 pad [G]
    snprintf(buf, 63, D_004CA338, (int)(0.016666668f * t), (int)(0.0f + t - 60.0f * (float)(int)(t / 60.0f)));
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, field_36, 8);
    float k = 0.75f;
    c0 = CGtV4d(colours->field_60.mData);
    c1 = v285_interp(colours->field_60, colours->field_30, k);
    if (t < 11.0f) {
        float f = t - (float)(int)t;
        c0 = near20_interpf(c0, colours->field_30, f);
        c1 = near20_interpf(c1, colours->field_50, f);
    }
    func_003824D0((void *)(field_20), CGtV2d(field_24->field_0 - 4.0f, 47.0f), CGtV2d(1.0f, D_00665ED0.field_0->field_10), 56.0f, c0, c1,
                  field_36, 0x61, 1.25f, 3.402823466e+38f);
    if ((field_34 != 0 && t < 2.0f) || field_2C->field_2D0 < 0.0f)
        (*(UnkStruct_003C23A0_o * const *)&scene->field_2C)[layer].field_0 = scene->field_2C->field_0 | 1;
    else
        (*(UnkStruct_003C23A0_o * const *)&scene->field_2C)[layer].field_0 = scene->field_2C->field_0 & ~1;
}


