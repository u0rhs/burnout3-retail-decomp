// NONMATCHING: DetectAndScoreTailgating__8CB3ScoreFv -- retail 312 / ours 312 instructions, 22 in changed runs
// psweep: scoped #pragma opt_strength_reduction off [G] improves 23 -> 22
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3Score::DetectAndScoreTailgating() -- hand-written (v305); the lifter refused it.
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3Score.cpp.
// Modelled on the proven sibling DetectAndScoreNearMiss (B3Score_001598F0.cpp: the score-category chain, here at +0x598,
// and its level search) and CalculateSlamType's VU stand-ins (src/nonmatching, v296). Field names are placeholders and
// every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_strength_reduction off
using namespace GtMathPs2;

enum EAggressiveHornBlashReason {};
struct CB3ScoreCategory;
class CB3RaceCar;
class CB3Burn {
public:
    void AddBurn(float p0);
};
class CB3ScoreBonus {
public:
    void OnTailgate(CB3RaceCar * p0, CB3ScoreCategory * p1);
    unsigned char pad_0[0x1];
};
class CB3AIAggressionBehaviour {
public:
    void DoAggressiveHornBlast(EAggressiveHornBlashReason p0);
};
class CB3RaceCar {
public:
    unsigned char pad_0[0x20];
    CGtV3d field_20;
    CGtV3d field_30;
    unsigned char pad_40[0x1638];
    unsigned char field_1678;
    unsigned char pad_1679[0x271];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x248];
    CB3AIAggressionBehaviour field_1B60;
};
struct UnkStruct_00158EB0_obj {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
};
struct UnkStruct_00158EB0_rcp {
    UnkStruct_00158EB0_obj * field_0;
    unsigned char pad_4[0x2C];
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x3C98C];
    UnkStruct_00158EB0_rcp field_3C98C[6];
    unsigned char pad_3CAAC[0x12AD1C - 0x3CAAC];
    int field_12AD1C;
    unsigned char pad_12AD20[8];
    CB3RaceCar * field_12AD28[6];
};
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00158EB0_5B0 {
    unsigned char pad_0[0xC];
    float field_C;
};
class CB3Score {
public:
    void DetectAndScoreTailgating();
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0xB8];
    CB3RaceCar * field_C8;
    CB3Burn field_CC;
    unsigned char pad_CD[0x57];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x473];
    float field_598;
    float field_59C;
    float field_5A0;
    float * field_5A4;
    unsigned char field_5A8;
    signed char field_5A9;
    signed char field_5AA;
    signed char field_5AB;
    unsigned char pad_5AC[0x4];
    UnkStruct_00158EB0_5B0 * field_5B0;
    int field_5B4;
    static float gmrTailgateMaxDistance;
    static float gmrTailgateConeAngle;
    static float gmrTailgateInitialTime;
    static float gmrTailgateExtraBurnValue;
};
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0052267C D_0052267C;
extern "C" float func_0011E328(float);   // [L] acosf (LIBM wf_acos.o wrapper next to __ieee754_acosf 0x119C20)

// [L] N185: in-place CGtV3d::NormaliseGetLength on a compiler-chosen register (the header's body works on $vf1)
static inline XAxisType v305_ngl(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r;
    float f;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "qmfc2 %0, $vf1" "\n\t" "mtc1 %0, %1" "\n\t" "sqrt.s %1, %1" "\n\t" "mfc1 %0, %1" "\n\t"
        "qmtc2 %0, $vf1" "\n\t" "qmfc2 %0, $vf1" : "=&r"(r), "=&f"(f));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData));
    asm(".set reorder");
    return XAxisType(r);
}
// [L] N185 (v296): the unnamed retail Normalise family that also computes 1/length (`vmulq.x $vf1,$vf1,$Q`), in place
static inline XAxisType v305_normil(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 one, r;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %0, $vf1" : "=r"(one));
    u_long128 o;
    asm("vwaitq" "\n\t" "vmulq.xyz %1, %1, $Q" "\n\t" "qmtc2.i %2, $vf1" "\n\t" "qmfc2.i %0, %1" : "=r"(o) : "j"(v.mData), "r"(one));
    v.mData = o;
    asm("vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r));
    asm(".set reorder");
    return XAxisType(r);
}
// [L] N185 (v296): GtMathPs2::CosAngleBetweenNormalisedVectors(CGtV3d, CGtV3d) (B3O0PCH map): the dot product clamped to [-1, 1]
static inline float v305_cosang(CGtV3d a, CGtV3d b)
{
    XAxisType d = DotProduct(a, b);
    u_long128 m, r;
    asm("vsubw.x %0, $vf0, $vf0w" : "=j"(m));
    asm("qmtc2 %1, $vf1" "\n\t" "vmax.x $vf1, $vf1, %2" "\n\t" "vminiw.x $vf1, $vf1, $vf0w" "\n\t" "qmfc2 %0, $vf1"
        : "=r"(r) : "r"(d.lVector), "j"(m));
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(r));
    return f;
}
// [G] placeholder: the score category's reset (the same stores as DetectAndScoreNearMiss's chain at +0x418)
static inline void func_00158EB0_inl1(CB3Score * s, int id)
{
    s->field_5A0 = s->field_598;
    s->field_5AA = s->field_5A9;
    s->field_59C = s->field_5B0->field_C;
    s->field_598 = 0.0f;
    s->field_5A8 = 0;
    s->field_5A9 = -1;
    s->field_5B4 = id;
}

// 0x00158EB0
void CB3Score::DetectAndScoreTailgating()
{
    int i;
    float maxd = gmrTailgateMaxDistance;
    int best = -1;
    bool found = false;
    for (i = 0; i < D_00522660.field_12AD1C; i++) {
        CB3RaceCar * car = D_00522660.field_12AD28[i];
        if (car == field_C8) continue;
        if (2.236936331f * (float)*(const WAxisType *)&D_00522660.field_3C98C[i].field_0->field_B0 < 60.0f) continue;  // [C] retail FPU form, not a VU lane op: 0x158F7C mul.s (the cast keeps the port's PS2 float model)
        CGtV3d d = car->field_30;
        d -= field_C8->field_30;
        float len;
        { XAxisType ll = v305_ngl(d); asm("mtc1 %1, %0" : "=f"(len) : "r"(ll.lVector)); }
        if (len <= maxd) {
            if (!(len <= 1.5f)) {
                CGtV3d dir = car->field_20;
                v305_normil(dir);
                v305_normil(d);
                float ang = 57.29578f * func_0011E328(v305_cosang(dir, d));
                if (ang <= gmrTailgateConeAngle) {
                    maxd = len;
                    best = i;
                    found = true;
                }
            }
        }
    }
    if (field_5B4 == best) {
        if (best != -1) {
            float t = field_598;
            float f1 = t + D_0052267C.field_0;
            field_5A0 = t;
            field_598 = f1;
            field_59C = field_5B0->field_C;
            int nn = field_5AB;
            int lv = field_5A9;
            if (lv < nn - 1) {
                int ii = nn;
                int old;
                goto test;
            body:
                if (!(f1 < field_5A4[ii])) {
                    field_5AA = lv;
                    field_5A9 = ii;
                    goto after;
                }
                old = ii;
            test:
                old = ii;
                ii = ii - 1;
                if (old != 0) goto body;
            }
        after:
            if (!(field_598 < gmrTailgateInitialTime)) {
                if (field_5A8 != 0) goto burn;
                field_5A8 = 1;
            }
        }
    } else if (field_C > 0.3f + field_59C) {
        CB3RaceCar * c = 0;
        if (field_5B4 != -1) {
            c = D_00522660.field_12AD28[field_5B4];
            c->field_1678 = 0;
        }
        if (field_5A8 != 0) {
            field_124.OnTailgate(c, (CB3ScoreCategory *)&field_598);
        }
        func_00158EB0_inl1(this, best);
    }
chk:
    if (field_5A8 != 0 && field_5B4 != -1 && D_00522660.field_12AD28[field_5B4]->field_18EA != 0) {
        func_00158EB0_inl1(this, -1);
    }
    return;
burn:
    field_CC.AddBurn(gmrTailgateExtraBurnValue * D_0052267C.field_0);
        if (found) {
            CB3RaceCar * c = D_00522660.field_12AD28[field_5B4];
            if (c->field_1914 != 0) {
                c->field_1678 = 1;
            } else if (field_C8->field_1914 == 1) {
                field_C8->field_1B60.DoAggressiveHornBlast((EAggressiveHornBlashReason)2);
            }
        }
    goto chk;
}

#pragma pop
