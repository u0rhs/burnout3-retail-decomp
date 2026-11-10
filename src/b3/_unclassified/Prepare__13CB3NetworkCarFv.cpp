// Hand-written; the lifter refused it (zero/identity CGtV3d members via =j asm (as ResetMemberVariables); byte 1A12 unsigned char, field = field & -8 (separate and + hoisted -8)).

#include "b3/GtMathPs2.h"

class CB3NetworkCar;
extern "C" void Prepare__10CB3RaceCarFv(CB3NetworkCar * self);

class CB3NetworkCar {
public:
    void Prepare();

    unsigned char pad_0[0x19B0];
    GtMathPs2::CGtV3d field_19B0;
    GtMathPs2::CGtV3d field_19C0;
    GtMathPs2::CGtV3d field_19D0;
    GtMathPs2::CGtV3d field_19E0;
    GtMathPs2::CGtV3d field_19F0;
    GtMathPs2::CGtV3d field_1A00;
    unsigned char field_1A10;
    unsigned char field_1A11;
    unsigned char field_1A12;
    unsigned char field_1A13;
    unsigned char field_1A14;
    unsigned char field_1A15;
    unsigned char field_1A16;
    unsigned char pad_1A17;
    int field_1A18;
    unsigned char pad_1A1C[4];
    GtMathPs2::CGtV3d field_1A20;
    unsigned char field_1A30;
    unsigned char pad_1A31[0xF];
    GtMathPs2::CGtV3d field_1A40;
    GtMathPs2::CGtV3d field_1A50;
    GtMathPs2::CGtV3d field_1A60;
    GtMathPs2::CGtV3d field_1A70;
    int field_1A80;
    unsigned char field_1A84;
    unsigned char field_1A85;
    unsigned char pad_1A86[0xA];
    unsigned char field_1A90;
};

#define A211_ZERO(f) { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); f.mData = r; }
#define A211_IDX(f) { u_long128 r = f.mData; asm("vaddw.x %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }
#define A211_IDY(f) { u_long128 r = f.mData; asm("vaddw.y %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }
#define A211_IDZ(f) { u_long128 r = f.mData; asm("vaddw.z %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }

// 0x00150120
void CB3NetworkCar::Prepare()
{
    field_1A13 = 0;
    field_1A84 = 0;
    field_1A85 = 0;
    A211_ZERO(field_19B0)
    A211_ZERO(field_19C0)
    A211_ZERO(field_19D0)
    A211_ZERO(field_19E0)
    A211_IDX(field_19B0)
    A211_IDY(field_19C0)
    A211_IDZ(field_19D0)
    A211_ZERO(field_19F0)
    A211_ZERO(field_1A00)
    field_1A10 &= 0xE0;
    field_1A10 &= 0x1F;
    field_1A11 = 0;
    field_1A12 = field_1A12 & -8;
    field_1A12 &= 0xF7;
    field_1A12 &= 0xEF;
    field_1A14 = 0;
    field_1A15 = 0;
    field_1A16 = 0;
    field_1A18 = 0;
    A211_ZERO(field_1A20)
    field_1A30 = 0;
    A211_ZERO(field_1A40)
    A211_ZERO(field_1A50)
    A211_ZERO(field_1A60)
    A211_ZERO(field_1A70)
    A211_IDX(field_1A40)
    A211_IDY(field_1A50)
    A211_IDZ(field_1A60)
    field_1A80 = 0;
    field_1A90 = 1;
    Prepare__10CB3RaceCarFv(this);
}

