// NONMATCHING: CalculateHighShelfCoefficients__20CB3SoundDSPDataBlockFfff -- retail 104 / ours 106 instructions, 113 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a124: 106/104 instrs, ~113 changed. RBJ high-shelf biquad coefficients, expression grouping believed right (A=func_0011E388(10,gain/40); w=D_004E0740*f/48000(int cvt); sinf/cosf; beta=sqrtf((0+1+A*A)/(0+S-(A-1)^2)) (sqrt.s, the 'c1 0x10044' is sqrt.s f1,f1); b0=A*(t2+t1), b1=-2A*(Am1+Ap1*cos), b2=A*
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
class CB3SoundDSPDataBlock {
public:
    void CalculateHighShelfCoefficients(float p0, float p1, float p2);

    unsigned char pad_0[0x4C];
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
};

extern "C" float func_0011E388(float, float);
extern "C" float sqrtf(float);

void CB3SoundDSPDataBlock::CalculateHighShelfCoefficients(float p0, float p1, float p2)
{
    float A = func_0011E388(10.0f, p1 / 40.0f);
    float w = 6.2831855f * p0 / (float)48000;
    float sn = sinf(w);
    float cs = cosf(w);
    float z = 0.0f;
    float one = 1.0f;
    float Ap1 = one + A;
    float Am1 = A - one;
    float q = z + one + A * A;
    float r = z + p2 - Am1 * Am1;
    float beta = sqrtf(q / r);
    float t0 = Am1 * cs;
    float t1 = beta * sn;
    float t2 = Ap1 + t0;
    float t3 = Ap1 * cs;
    float b0 = A * (t2 + t1);
    float b2 = A * (t2 - t1);
    float t4 = Ap1 - t0;
    float b1 = -2.0f * A * (Am1 + t3);
    float a0 = t4 + t1;
    float c1 = 2.0f * (Am1 - t3);
    float a2 = t4 - t1;
    float k = 65536.0f;
    field_4C = (int)(k * (b0 / a0));
    field_50 = (int)(k * (b1 / a0));
    field_54 = (int)(k * (b2 / a0));
    field_58 = (int)(k * (a0 / a0));
    field_5C = (int)(k * (c1 / a0));
    field_60 = (int)(k * (a2 / a0));
}
