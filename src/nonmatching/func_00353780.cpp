// NONMATCHING: func_00353780 -- retail 119 / ours 119 instructions, 46 in changed runs
// repair1: header DotProduct/GetLength/operator*(float)/Y()-Y() + GtMath::Max/Min (retail max.s/min.s) + compiler-chosen vsub/Normalise stand-ins (func_00353780_inl1/2); left: VU numbering (ours v on vf4/d on vf6/Dot one vf5, retail vf5/vf1/vf7) and the YAxisType temp slot at sp+0 (retail 0x30, 3 dead slots below it)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
// [G] b - a with compiler-chosen VU registers (retail `vsub.xyz $vf1,$vf4,$vf5` / `vsub.xyz $vf5,$vf6,$vf5`); the header's
// binary operator- hard-codes $vf1/$vf2 inputs
static inline CGtV3d func_00353780_inl1(const CGtV3d& b, const CGtV3d& a)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(b.mData), "j"(a.mData));
    return CGtV3d(r);
}
// [G] CGtV3d::Normalise inlined with the vector kept on its own VU register (retail `vmulq.xyz $vf5,$vf5,$Q`)
static inline void func_00353780_inl2(CGtV3d& v)
{
    XAxisType l = v.GetSquaredLength();
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData));
    asm(".set reorder");
}
struct UnkStruct_00353780_s { CGtV3d field_0; unsigned char pad_10[0x10]; float field_20; unsigned char pad_24[0xC]; };   // [G] 0x30 stride
struct UnkStruct_00353780_b { UnkStruct_00353780_s field_0[0x32]; int field_960_[1]; int field_964; };
struct UnkStruct_00353780_p { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_00353780_v { unsigned char pad_0[0x204]; UnkStruct_00353780_p* field_204; };
struct UnkStruct_00353780_e {                       // [G] 0x70 stride from +0x2E0
    unsigned char pad_0[0x40];
    UnkStruct_00353780_v* field_40;
    unsigned char pad_44[0x14];
    float field_58;
    float field_5C;
    unsigned char pad_60[9];
    unsigned char field_69;
    unsigned char pad_6A[6];
};
struct UnkStruct_00353780_a {
    unsigned char pad_0[0x2E0];
    UnkStruct_00353780_e field_2E0[8];             // [G] count
    unsigned char pad_660[0x9D0];
    int field_1030;
};
struct UnkStruct_00353780_pad { int x[4]; UnkStruct_00353780_pad() {} ~UnkStruct_00353780_pad() {} };  // [G] N140 frame pad
// 0x00353780
extern "C" void func_00353780(UnkStruct_00353780_a* self, float* pMin, float* pMax, UnkStruct_00353780_s* segs)
{
    float minPos = 3.402823466e+38f;
    float maxPos = 0.0f;
    for (int i = 0; i < self->field_1030; i++) {
        UnkStruct_00353780_e* e = &self->field_2E0[i];
        if (e->field_69 != 0) continue;
        float accum = 0.0f;
        float bestDist = 3.402823466e+38f;
        float bestPos = 3.402823466e+38f;
        CGtV3d p = e->field_40->field_204->field_30;
        int n = ((int*)((char*)segs + 0x964))[0] - 1;
        for (int j = 0; j < n; j++) {
            UnkStruct_00353780_s* s = &segs[j];
            UnkStruct_00353780_pad q0, q1, q2, q3;
            CGtV3d d = func_00353780_inl1(p, s[0].field_0);
            CGtV3d v = func_00353780_inl1(s[1].field_0, s[0].field_0);
            func_00353780_inl2(v);
            float t = DotProduct(v, d);
            float c = GtMath::Min(GtMath::Max(t, 0.0f), s->field_20);
            CGtV3d q = v * c;
            float dist = func_00353780_inl1(d, q).GetLength();
            float dy = q.Y() - d.Y();
            if (!(dy <= 10.0f)) dist += 10.0f;
            if (!(dist < bestDist)) {} else { bestPos = accum + c; bestDist = dist; }
            accum += s->field_20;
        }
        e->field_58 = bestPos;
        e->field_5C = bestDist;
        if (bestPos < minPos) minPos = bestPos;
        if (bestPos > maxPos) maxPos = bestPos;
    }
    *pMin = minPos;
    *pMax = maxPos;
}
