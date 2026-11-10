// Hand-written; the lifter refused it (SetIdentity stand-in zeroing rows through a nested Zero inline (VU numbering: 1.0 lanes first)).

// func_0023F5B0 -- hand-matched (ghvu8). Placeholder name, C linkage (asm label); `self` is a0.
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_0023F5B0_r {
    CGtMatrix3x4 field_0;
    CGtMatrix3x4 field_40;
    CGtV3d field_80;
    CGtV3d field_90;
    CGtV3d field_A0;
    unsigned char field_B0;
    unsigned char field_B1;
    unsigned char pad_B2[0xE];
};

struct UnkStruct_0023F5B0_s {
    unsigned char pad_0[0x240];
};

struct UnkStruct_0023F5B0 {
    unsigned char pad_0[0x4F4];
    unsigned char field_4F4;
    unsigned char pad_4F5[0xCF];
    int field_5C4;
    int field_5C8;
    int field_5CC;
    int field_5D0;
    int field_5D4[0x40];
    unsigned short field_6D4;
    short field_6D6;
    int field_6D8;
    unsigned char pad_6DC[0x8];
    unsigned char field_6E4[0x240];
    unsigned char field_924[0x2D0];
    unsigned char field_BF4[0x14];
    unsigned char field_C08[0x14];
    unsigned char field_C1C[0x14];
    unsigned char field_C30[0x3C];
    unsigned char field_C6C[0x9C4];
    unsigned char field_1630[0x2AC];
    UnkStruct_0023F5B0_s field_18DC[0x10];
    int field_3CDC;
    UnkStruct_0023F5B0_r field_3CE0[0x18];
    int field_4EE0;
    int field_4EE4;
    unsigned char field_4EE8;
    unsigned char field_4EE9;
    unsigned char pad_4EEA[0x2];
    int field_4EEC;
    int field_4EF0;
    unsigned short field_4EF4;
    unsigned char pad_4EF6[0x2];
    int field_4EF8;
    unsigned char field_4EFC;
    unsigned char field_4EFD[6];
    unsigned char field_4F03[6];
    unsigned char field_4F09;
    unsigned char field_4F0A;
    unsigned char field_4F0B;
    unsigned char field_4F0C;
    unsigned char pad_4F0D[0x3];
    int field_4F10;
    int field_4F14;
};

extern "C" void func_0022D9F0(void *);
extern "C" void func_001AA1A0(void *);
extern "C" void func_002B7100(void *);
extern "C" void func_002B7070(void *);

// [L] N185: stands in for the header's CGtV3d::Zero() (which hard-codes $vf1)
static inline void func_0023F5B0_inl1(CGtV3d &v) { u_long128 t; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(t)); v.mData = t; }

// [L] N185: CGtMatrix3x4::SetIdentity with the row zeroing through the Zero() inline (one level deeper than the
// 1.0 lanes): retail's VU numbering (1.0 lanes first, then the rows) [G] inline nesting.
static inline void func_0023F5B0_inl2(CGtMatrix3x4 &m) {
    func_0023F5B0_inl1(m.mRight);
    func_0023F5B0_inl1(m.mUp);
    func_0023F5B0_inl1(m.mAt);
    func_0023F5B0_inl1(m.mPos);
    { u_long128 r = m.mRight.mData; asm("vaddw.x %0, $vf0, $vf0w" : "+j"(r)); m.mRight.mData = r; }
    { u_long128 r = m.mUp.mData; asm("vaddw.y %0, $vf0, $vf0w" : "+j"(r)); m.mUp.mData = r; }
    { u_long128 r = m.mAt.mData; asm("vaddw.z %0, $vf0, $vf0w" : "+j"(r)); m.mAt.mData = r; }
}

// 0x0023F5B0
extern "C" void func_0023F5B0(UnkStruct_0023F5B0 * self)
{
    int i;
    self->field_4F4 = 0;
    self->field_5C4 = 0;
    self->field_5C8 = -1;
    self->field_5CC = 0;
    self->field_5D0 = 0;
    for (i = 0; i < 0x40; i++) {
        self->field_5D4[i] = 0;
    }
    self->field_6D4 = 0xFFFF;
    self->field_6D6 = -1;
    self->field_6D8 = -1;
    func_0022D9F0(self->field_6E4);
    func_001AA1A0(self->field_924);
    func_0022D9F0(self->field_BF4);
    func_002B7100(self->field_C08);
    func_0022D9F0(self->field_C1C);
    func_002B7070(self->field_C30);
    func_0022D9F0(self->field_C6C);
    func_0022D9F0(self->field_1630);
    for (i = 0; i < 0x10; i++) {
        func_001AA1A0(&self->field_18DC[i]);
    }
    self->field_3CDC = 0;
    for (i = 0; i < 0x18; i++) {
        func_0023F5B0_inl2(self->field_3CE0[i].field_0);
        func_0023F5B0_inl2(self->field_3CE0[i].field_40);
        func_0023F5B0_inl1(self->field_3CE0[i].field_80);
        func_0023F5B0_inl1(self->field_3CE0[i].field_90);
        func_0023F5B0_inl1(self->field_3CE0[i].field_A0);
        self->field_3CE0[i].field_B0 = 0xFF;
        self->field_3CE0[i].field_B1 = 0;
    }
    self->field_4EE0 = 0;
    self->field_4EE4 = 0;
    self->field_4EE8 = 0;
    self->field_4EE9 = 0;
    self->field_4EEC = 0;
    self->field_4EF0 = 0;
    self->field_4EF4 = 0xFFFF;
    self->field_4EFC = 1;
    self->field_4EF8 = 0;
    self->field_4F10 = 0;
    self->field_4F14 = 0;
    for (i = 0; i < 6; i++) {
        self->field_4EFD[i] = 0;
        self->field_4F03[i] = 0;
    }
    if (self->field_4F10 > 0) {
        self->field_4F10--;
    } else {
        self->field_4F0A = 0;
        self->field_4F0B = 0;
        self->field_4F09 = 0;
        self->field_4F0C = 0xFF;
    }
}
