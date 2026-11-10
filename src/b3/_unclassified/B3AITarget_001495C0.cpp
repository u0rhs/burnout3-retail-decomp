// CB3AITargetSpline::CalculateSplineVectors() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (v312: else-if chain in guard, GetLeftFrac by address + N140 pad, .i CrossProduct in noreorder region).

// CB3AITargetSpline::CalculateSplineVectors() -- hand-written (v312; lifter draft reshaped).
// [C] name: retail symbol table; file: research/retail_names.csv -> B3AITarget.cpp. Field names are placeholders, types [G].
// Shape: else-if chain on field_1BE8 (1, 2) nested in the 1BEC/1BE3 guard; GetLeftFrac called through its link name with
// the CGtV3d passed by address (retail passes &field, no copy) plus an N140 pad for the two dead copy slots.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct CB3AILaneStruct;
class CB3AILane {
public:
    float GetSignedForwardDistBetweenParams(float, float);
    unsigned char pad_0[4];
    CB3AILaneStruct *field_4;
};
extern "C" float GetLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3df(const CB3AILane *, unsigned short, const void *, float);

struct UnkStruct_001495C0_2 {
    unsigned char pad_0[0x1BC4];
    CB3AILane *field_1BC4;
    unsigned short field_1BC8;
    unsigned char pad_1BCA[0x2];
    float field_1BCC;
    unsigned char pad_1BD0[0x13];
    unsigned char field_1BE3;
    unsigned char pad_1BE4[0x4];
    int field_1BE8;
    int field_1BEC;
    unsigned char pad_1BF0[0x14];
    unsigned short field_1C04;
    unsigned short field_1C06;
    unsigned short field_1C08;
    unsigned char pad_1C0A[0x6];
    CGtV3d field_1C10;
    CGtV3d field_1C20;
};

struct UnkStruct_kYAxis { CGtV3d field_0; };
extern UnkStruct_kYAxis kYAxis;

class CB3AITargetSpline {
public:
    void CalculateSplineVectors();
    bool GetSplineIndices(const CB3AILaneStruct *, unsigned short, int *) const;
    void CalculateSpline(int *, CB3AILane *, float *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *);

    unsigned char pad_0[0xC0];
    CGtV3d field_C0;
    CGtV3d field_D0;
    CGtV3d field_E0;
    CGtV3d field_F0;
    u_long128 field_100;
    u_long128 field_110;
    u_long128 field_120;
    CGtV3d field_130;
    CGtV3d field_140;
    unsigned char field_150;
    unsigned char field_151;
    unsigned char pad_152[0x2];
    UnkStruct_001495C0_2 *field_154;
};

// [L] N185: CrossProduct with the result move written .i (N190: vopmsub results keep qmfc2 + sq). The real asm sits in a
// `.set noreorder` region (N188): without it b119 puts the following Normalise's square on $vf1 and copies it to $vf2.
static inline CGtV3d func_001495C0_inl2(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm(".set noreorder");
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    asm(".set reorder");
    return CGtV3d(t);
}
struct UnkStruct_001495C0_pad { int x[8]; UnkStruct_001495C0_pad() {} ~UnkStruct_001495C0_pad() {} };
// [G] retail converts the unsigned short params through the unsigned-int path (bltz / srl|and / add.s)
static inline float func_001495C0_inl1(unsigned int u) { return (float)u; }

// 0x001495C0
void CB3AITargetSpline::CalculateSplineVectors()
{
    float w[6];
    int idx[6];
    UnkStruct_001495C0_pad pad;  // [G] N140: retail's two dead 16-byte slots (by-value CGtV3d copies passed to GetLeftFrac, elided)
    if (!GetSplineIndices(field_154->field_1BC4->field_4, field_154->field_1BC8, idx)) {
        return;
    }
    for (int i = 0; i < 6; i++) {
        w[i] = field_154->field_1BCC;
    }
    field_150 = 0;
    CalculateSpline(idx, field_154->field_1BC4, w, &field_E0, 0, &field_C0, (CGtV3d *)&field_100);
    field_E0.Normalise();
    field_C0.Normalise();
    field_F0 = func_001495C0_inl2(kYAxis.field_0, field_E0);
    field_F0.Normalise();
    field_D0 = func_001495C0_inl2(kYAxis.field_0, field_C0);
    field_D0.Normalise();
    UnkStruct_001495C0_2 *t0 = field_154;
    if (t0->field_1BEC == 0 && t0->field_1BE3 != 0) {
      if (t0->field_1BE8 == 1) {
            float lf;
            float d;
            d = t0->field_1BC4->GetSignedForwardDistBetweenParams(func_001495C0_inl1(t0->field_1C06), func_001495C0_inl1(t0->field_1C04));
            lf = GetLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3df(field_154->field_1BC4, field_154->field_1C04, &field_154->field_1C10, 0.0f);
            for (int i = 0; i < 6; i++) {
                float r = field_154->field_1BC4->GetSignedForwardDistBetweenParams((float)idx[i], func_001495C0_inl1(field_154->field_1C04)) / d;
                w[i] = r * field_154->field_1BCC + (1.0f - r) * lf;
            }
            field_150 = 1;
            CalculateSpline(idx, field_154->field_1BC4, w, 0, 0, &field_130, &field_140);
            field_130.Normalise();
            field_151 = 1;
    } else if (t0->field_1BE8 == 2) {
            float lf;
            float d;
            d = t0->field_1BC4->GetSignedForwardDistBetweenParams(func_001495C0_inl1(t0->field_1C08), func_001495C0_inl1(t0->field_1C06));
            lf = GetLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3df(field_154->field_1BC4, field_154->field_1C06, &field_154->field_1C20, 0.0f);
            for (int i = 0; i < 6; i++) {
                float r = field_154->field_1BC4->GetSignedForwardDistBetweenParams((float)idx[i], func_001495C0_inl1(field_154->field_1C06)) / d;
                w[i] = r * field_154->field_1BCC + (1.0f - r) * lf;
            }
            field_150 = 1;
            CalculateSpline(idx, field_154->field_1BC4, w, 0, 0, &field_130, &field_140);
            field_130.Normalise();
            field_151 = 1;
    } else {
        field_151 = 0;
    }
    } else {
        field_151 = 0;
    }
    if (field_151 == 0) {
        field_120 = field_100;
        field_110 = field_C0.mData;
    }
}
