// NONMATCHING: FillInNoGoData__17CB3AIAvoidanceMapFPC9CB3AILaneUs16EAIAvoidanceRiskff -- retail 152 / ours 151 instructions, 33 in changed runs
// fix1 (2026-11-01): field_40/140/240 declared as their real 256 entries (the [1] + pad form made host GCC stop the loop after one pass: port6 checker, 0x01010101 fill missing) | Before: ghvu9: logic believed exact (152 vs 151), 33 off. Local [L] N185 stand-ins: Interpolate on hard-coded vf1/vf2 with GPR moves (header's compiler-chosen form folds b into lqc2), (p-field_10).field_30 with vsub on hard-coded vf1. Left: seg/points base registers a2/t0 swapped, first dot's mtc1 delayed, first Interpolate's a move folded/unfolded, f44C load placement.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [C] fix1 (2026-11-01): 24/24 port6 live captures pass the Burn3 checker at tolerance 0; 6 replay identical on the host (capture_replay) -- on those inputs


// CB3AIAvoidanceMap::FillInNoGoData(const CB3AILane*,unsigned short,EAIAvoidanceRisk,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

#include "b3/GtMath.h"

class CB3AILane;
enum EAIAvoidanceRisk {};

class CB3AIAvoidanceMap;
struct CB3AILane;
struct UnkStruct_0013E530_2;
struct UnkStruct_0013E530_3;
struct UnkStruct_0013E530_e0;
struct UnkStruct_0013E530_e1;
struct UnkStruct_D_0064D354;

struct CB3AILane {
    unsigned char pad_0[0x4];
    UnkStruct_0013E530_2 * field_4;
};

struct UnkStruct_0013E530_2 {
    UnkStruct_0013E530_e0 * field_0;
};

struct UnkStruct_0013E530_3 {
    unsigned char pad_0[0x18BC];
    float field_18BC;
};

struct UnkStruct_0013E530_e0 {
    unsigned short field_0;
    unsigned short field_2;
};

struct UnkStruct_D_0064D354 {
    UnkStruct_0013E530_e1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0013E530_e1 {
    GtMathPs2::CGtV3d field_0;
};

class CB3AIAvoidanceMap {
public:
    void FillInNoGoData(const CB3AILane* p0, unsigned short p1, EAIAvoidanceRisk p2, float p3, float p4);

    unsigned char pad_0[0x10];
    GtMathPs2::CGtV3d field_10;
    unsigned char pad_20[0x10];
    GtMathPs2::CGtV3d field_30;
    // fix1: 256 entries each [C] retail 0x13E6A0.. clamps the index range to 0..255 (slti 0x100 / li 0xFF); the old
    // [1] + pad declarations let host GCC end the loop after one pass (an out-of-bounds index is UB there)
    unsigned char field_40[0x100];
    unsigned char field_140[0x100];
    short field_240[0x100];
    unsigned char pad_440[0xC];
    float field_44C;
    unsigned char pad_450[0x4];
    UnkStruct_0013E530_3 * field_454;
};

extern UnkStruct_D_0064D354 D_0064D354;

// [L] N185: stands in for the header's Interpolate(CGtV3d, CGtV3d, float): retail 0x13E590 keeps every operand on the
// hard-coded $vf1/$vf2 with GPR moves (a, t and b moved in, the result moved out .ni), where the header's compiler-chosen
// "+j" a lets b119 fold b's move into an lqc2
static inline GtMathPs2::CGtV3d func_0013E530_inl2(GtMathPs2::CGtV3d a, GtMathPs2::CGtV3d b, float t)
{
    u_long128 r;
    unsigned int ti;
    asm("mfc1 %0, %1" : "=r"(ti) : "f"(t));
    asm("qmtc2 %1, $vf1" "\n\t" "vaddax.xyz $ACC, $vf1, $vf0x" "\n\t" "qmtc2.i %3, $vf2" "\n\t" "vmsubax.xyz $ACC, $vf1, $vf2x" "\n\t"
        "qmtc2.i %2, $vf1" "\n\t" "vmaddx.xyz $vf1, $vf1, $vf2x" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(r) : "r"(a.mData), "r"(b.mData), "r"(ti));
    return GtMathPs2::CGtV3d(r);
}

// [G] the channel of a lane point (5 per metre around field_44C, 128 = centre), as GetSafestChannel's bounds
static inline float func_0013E530_inl1(const CB3AIAvoidanceMap * m, GtMathPs2::CGtV3d p)
{
    // [L] N185: (p - field_10) . field_30 on retail's hard-coded registers (0x13E5B0: `qmtc2.ni p,$vf1; vsub.xyz $vf1,$vf1,$vf4;
    // vmul.xyz $vf2,$vf1,$vf3`, then DotProduct's tail with the 1.0 parked in a GPR)
    u_long128 one, d;
    asm("qmtc2.i %2, $vf1" "\n\t" "vsub.xyz $vf1, $vf1, %3" "\n\t" "vmul.xyz $vf2, $vf1, %4" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t"
        "qmfc2.i %1, $vf1" "\n\t" "vadday.x $ACC, $vf2, $vf2y" "\n\t" "qmtc2.i %1, $vf1" "\n\t" "vmaddz.x $vf1, $vf1, $vf2z" "\n\t"
        "qmfc2.i %0, $vf1"
        : "=r"(d), "=&r"(one) : "r"(p.mData), "j"(m->field_10.mData), "j"(m->field_30.mData));
    return GtMathPs2::XAxisType(d);
}

// 0x0013E530
void CB3AIAvoidanceMap::FillInNoGoData(const CB3AILane* p0, unsigned short p1, EAIAvoidanceRisk p2, float p3, float p4)
{
    UnkStruct_0013E530_e0 * s = &p0->field_4->field_0[p1];
    float t = GtMath::Max(GtMath::Min(field_454->field_18BC, 1.0f), 0.0f);
    float dh = func_0013E530_inl1(this, func_0013E530_inl2(D_0064D354.field_0[s[0].field_0].field_0, D_0064D354.field_0[s[1].field_0].field_0, t));
    float dl = func_0013E530_inl1(this, func_0013E530_inl2(D_0064D354.field_0[s[0].field_2].field_0, D_0064D354.field_0[s[1].field_2].field_0, t));
    int lo;
    int hi = (int)(5.0f * (dh - field_44C)) + 128;
    lo = (int)(5.0f * (dl - field_44C)) + 128;
    if (hi < 0) {
        return;
    }
    if (lo >= 256) {
        return;
    }
    if (lo < 0) {
        lo = 0;
    }
    if (hi >= 256) {
        hi = 255;
    }
    for (int i = lo; i <= hi; i++) {
        if (p3 < 0.03137255f * (float)(int)field_140[i]) {
            field_140[i] = (int)((255.0f * p3) / 8.0f);
            field_40[i] = p2;
        }
        if (p4 < 0.015259255f * (float)field_240[i]) {
            field_240[i] = (int)(((float)32767 * GtMath::Min(GtMath::Max(p4, -500.0f), 500.0f)) / 500.0f);
        }
    }
}
