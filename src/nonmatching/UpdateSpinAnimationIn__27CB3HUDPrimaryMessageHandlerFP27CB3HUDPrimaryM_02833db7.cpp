// NONMATCHING: UpdateSpinAnimationIn__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler -- retail 254 / ours 254 instructions, 17 in changed runs
// 17 off: logic/frame/tail exact; left: SinCosFast2 stand-in (header body + v copy for the y/w lanes, [L] N185) puts each I-constant lui/ori after the preceding park qmfc2 where retail hoists it above (4 sites); last-block 1.0 copy coalesced into f21 (retail mov.s f1,f21)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// UpdateSpinAnimationIn -- hand-written (ghvu15; 17 off: the SinCosFast2 constants' lui/ori are scheduled later than retail's, and retail keeps the last 1.0 copy in f1 apart from f21) from the Ghidra draft and the proven Out/Out2 siblings
// (UpdateSpinAnimationOut__27CB3HUDPrimaryMessageHandler..., same struct layout): field_C's object scales its alpha and
// field_2C in, field_10's field_24 grows, the position wobbles by the header SinCosFast2 polynomial while d < 0.7, and the
// score object (CreateScoreObject(field_38), a1 = field_38 in retail) fades in after 0.5. Float literals = retail .lit4
// values. Structs carry only the fields touched; every type is [G] (instruction widths).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_003D4FE0_2 {
    CGtV2d field_0;
    unsigned char pad_8[0x8];
    CGtV4d field_10;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x4];
    float field_2C;
};

struct UnkStruct_003D4FE0 {
    void * field_0;
    int field_4;
    unsigned char pad_8[0x4];
    UnkStruct_003D4FE0_2 * field_C;
    UnkStruct_003D4FE0_2 * field_10;
    UnkStruct_003D4FE0_2 * field_14;
    CGtV2d field_18;
    CGtV2d field_20;
    unsigned char pad_28[0x10];
    int field_38;
    unsigned char pad_3C[0x114];
    float field_150;
};

struct UnkStruct_003D4FE0_pad { int x[4]; UnkStruct_003D4FE0_pad() {} ~UnkStruct_003D4FE0_pad() {} };
struct UnkStruct_003D4FE0_pad8 { int x[2]; UnkStruct_003D4FE0_pad8() {} ~UnkStruct_003D4FE0_pad8() {} };
extern "C" void CreateScoreObject__27CB3HUDPrimaryMessageHandlerFi(UnkStruct_003D4FE0 *, int);

// [L] N185: stands in for GtMathPs2::SinCosFast2 (header body differs at this site)
static inline CGtV4d func_003D4FE0_inl2(float a, float b)
{
    CGtV4d v;
    u_long128 w;
    asm("qmtc2.ni %1, $vf1\n\tvaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(a));
    asm("qmtc2.ni %1, $vf1\n\tvaddx.z %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(b));
    u_long128 v2 = v.mData;
    asm("vaddx.y %0, $vf0, %0x" : "+j"(v2));
    asm("vmulz.w %0, $vf0, %0z" : "+j"(v2));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0x3FC90FDB));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vsubi.xz %0, %1, $I" : "=j"(w) : "j"(v2));
    asm(".set reorder");
    u_long128 x, one, f, y, t, t2, t4, t8, c1, c3, ca, cb, cc, r;
    asm(".set noreorder");
    asm("vabs.xyzw %0, %1" : "=j"(x) : "j"(w));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmaxw.xyzw %0, $vf0, $vf0w" : "=j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xBE22F983));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmulai.xyzw $ACC, %0, $I" : : "j"(x));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x4B400000));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubai.xyzw $ACC, %0, $I\n\tvmaddai.xyzw $ACC, %0, $I" : : "j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0xBE22F983));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubai.xyzw $ACC, %0, $I" : : "j"(x));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x3F000000));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubi.xyzw %0, %1, $I" : "=j"(f) : "j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vabs.xyzw %0, %1" : "=j"(y) : "j"(f));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0x3E800000));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vsubi.xyzw %0, %1, $I" : "=j"(t) : "j"(y));
    asm(".set reorder");
    asm("vmul.xyzw %0, %1, %1" : "=j"(t2) : "j"(t));
    asm("vmul.xyzw %0, %1, %1" : "=j"(t4) : "j"(t2));
    asm("vmul.xyzw %0, %1, %1" : "=j"(t8) : "j"(t4));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xC2992661));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(c1) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmul.xyzw %0, %1, %2" : "=j"(c3) : "j"(c1), "j"(t2));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xC2255DE0));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(ca) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x42A33457));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(cb) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x421ED7B7));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(cc) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmula.xyzw $ACC, %0, %1" : : "j"(ca), "j"(t2));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadda.xyzw $ACC, %0, %1" : : "j"(c3), "j"(t4));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21" : : "r"(0x40C90FDA));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadda.xyzw $ACC, %0, %1" : : "j"(cb), "j"(t4));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmaddai.xyzw $ACC, %0, $I" : : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadd.xyzw %0, %1, %2" : "=j"(r) : "j"(cc), "j"(t8));
    asm(".set reorder");
    return CGtV4d(r);
}

// 0x003D4FE0
extern "C" bool UpdateSpinAnimationIn__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler(UnkStruct_003D4FE0 * self)
{
    UnkStruct_003D4FE0_pad p0, p1, p2;  // N140 [G]: three 16-byte slots retail keeps (frame 0xF0)
    float d = self->field_150;
    float r = 0.0f;
    if (d < 0.25f) r = 15.079646f * (0.25f - d);
    self->field_C->field_2C = r;
    float one = 1.0f;
    float a = one;
    if (d < 0.2f) a = 5.0f * d;
    self->field_C->field_10.SetA(a);
    if (self->field_10 != 0) {
        float s = 1.0f;
        if (d < 1.5f) s = 0.6666667f * d;
        self->field_10->field_24 = s;
    }
    float half = 0.5f;
    CGtV2d pos = self->field_18 - self->field_20 * half;
    UnkStruct_003D4FE0_pad8 p3;  // N140 [G]: the 8-byte slot below pos
    if (d < 0.7f) {
        CGtV4d o = func_003D4FE0_inl2(53.407078f * d, 59.690262f * d) * (14.285714f * (0.7f - d));
        pos += CGtV2d(o.X(), o.Z());
    }
    self->field_C->field_0 = pos;
    if (self->field_38 != 0 && d > half) {
        if (self->field_14 == 0) CreateScoreObject__27CB3HUDPrimaryMessageHandlerFi(self, self->field_38);
        float s;
        if (d < 0.75f) s = 4.0f * (d - half);
        else s = one;
        self->field_14->field_10.SetA(s);
    }
    return !(self->field_150 >= 1.5f);
}
