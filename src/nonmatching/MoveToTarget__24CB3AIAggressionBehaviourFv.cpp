// NONMATCHING: MoveToTarget__24CB3AIAggressionBehaviourFv -- retail 186 / ours 187 instructions, 54 in changed runs
// near37: LOGIC FIX -- the lane offset scales field_44's field_18D0 (retail lqc2 0x18D0(a2), a2 = field_44), not field_48's; NGL stand-in with the vector compiler-chosen (retail vmulq.xyz vf3,vf3,Q; header NGL hard-codes vf1 + an extra qmfc2) now exact; Sign through a two-union copy. 54 changed. Left: frame 0x130 vs 0xD0 (6 dead 16-byte slots: 0x90-0x100), CrossProduct's qmfc2/qmtc2 round trip and mfc1 placement, a0/a1/a2 numbering of field_44/field_48 loads
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

class CB3Score {
public:
    float GetTotalRaceDistFromAILaneStart();
    bool WasSlammedWithinTime(float);
    unsigned char pad_0[0x10];
};

struct UnkStruct_0032F840_ln {
    unsigned char pad_0[0x2];
    unsigned char field_2;
    unsigned char pad_3[0x7];
};
struct UnkStruct_0032F840_l2 {
    unsigned char pad_0[0x8];
    UnkStruct_0032F840_ln *field_8;
};
struct UnkStruct_0032F840_l1 {
    unsigned char pad_0[0x4];
    UnkStruct_0032F840_l2 *field_4;
};
struct UnkStruct_0032F840_car {
    CGtV3d field_0;
    unsigned char pad_10[0x20];
    CGtV3d field_30;
    unsigned char pad_40[0x1080];
    CB3Score field_10C0;
    unsigned char pad_10D0[0x7E4];
    UnkStruct_0032F840_l1 *field_18B4;
    unsigned short field_18B8;
    unsigned char pad_18BA[0x16];
    CGtV3d field_18D0;
    unsigned char pad_18E0[0xCC];
    signed char field_19AC;
    unsigned char pad_19AD[0x234];
    unsigned char field_1BE1;
    unsigned char pad_1BE2[0x20];
    unsigned char field_1C02;
};
struct UnkStruct_0032F840_rec {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
};
struct UnkStruct_0032F840_ent {
    UnkStruct_0032F840_rec *field_0;
    unsigned char pad_4[0x2C];
};
extern UnkStruct_0032F840_ent D_0055EFEC[];
struct UnkStruct_D_01E755B8 {
    float field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_01E755B8 D_01E755B8;
extern u_long128 kYAxis;
extern "C" int func_001419B0(void *);

class CB3AIAggressionBehaviour {
public:
    int MoveToTarget();
    void StopAttacking(bool, bool);

    unsigned char pad_0[0x10];
    CGtV3d field_10;
    bool field_20;
    unsigned char pad_21[0x13];
    float field_34;
    unsigned char pad_38[0xC];
    UnkStruct_0032F840_car *field_44;
    UnkStruct_0032F840_car *field_48;
};

// [L] GtMath::Sign(float) (B3O0PCH map, 48 bytes): 1.0 with x's sign bit; local stand-in (not in include/b3/GtMath.h)
static inline float func_0032F840_inl1(float x)
{
    union { float f; int i; } u, r;
    u.f = x;
    r.i = (u.i & 0x80000000) | 0x3F800000;
    return r.f;
}

// [L] N185 stand-in: CGtV3d::NormaliseGetLength() with the vector on a compiler-chosen register (retail `vmulq.xyz $vf3,$vf3,$Q`;
// the header's body hard-codes $vf1 and adds a qmfc2 after the length's qmtc2). The length goes through the FPU sqrt.s.
static inline XAxisType func_0032F840_inl2(CGtV3d &v)
{
    XAxisType l;
    l = v.GetSquaredLength();
    u_long128 t;
    float f;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "qmfc2 %1, $vf1" "\n\t" "mtc1 %1, %2" "\n\t" "sqrt.s %2, %2" "\n\t" "mfc1 %1, %2" "\n\t"
        "qmtc2 %1, $vf1" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" "\n\t" ".set reorder" : "+j"(v.mData), "=&r"(l.lVector), "=&f"(f));
    asm(".set reorder");
    return l;
}

static inline CGtV3d func_0032F840_inl3(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 t;
    asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}
static inline void func_0032F840_inl4(CGtV3d &a, CGtV3d b)
{
    asm("vadd.xyz %0, %0, %1" : "+j"(a.mData) : "j"(b.mData));
}


// 0x0032F840
int CB3AIAggressionBehaviour::MoveToTarget()
{
    UnkStruct_0032F840_rec *cr = D_0055EFEC[field_44->field_19AC].field_0;
    UnkStruct_0032F840_rec *tr = D_0055EFEC[field_48->field_19AC].field_0;
    if (2.2369363f * (float)tr->field_B0.W() < D_01E755B8.field_0) {  // [C] retail FPU form, not a VU lane op: 0x22F8B8 mul.s (0x32F8B8), madd.s 0x32F900 / 0x32F92C (the cast keeps the port's PS2 float model)
        StopAttacking(false, true);
        return 0;
    }
    float k = 0.25f;
    float td = field_48->field_10C0.GetTotalRaceDistFromAILaneStart() + k * (float)tr->field_B0.W();  // [C] retail FPU form, not a VU lane op: 0x22F8B8 mul.s (0x32F8B8), madd.s 0x32F900 / 0x32F92C (the cast keeps the port's PS2 float model)
    float cd = field_44->field_10C0.GetTotalRaceDistFromAILaneStart() + k * (float)cr->field_B0.W();  // [C] retail FPU form, not a VU lane op: 0x22F8B8 mul.s (0x32F8B8), madd.s 0x32F900 / 0x32F92C (the cast keeps the port's PS2 float model)
    CGtV3d d = field_44->field_30 - field_48->field_30;
    func_0032F840_inl2(d);
    float diff = td - cd;
    float off;
    if (diff > 0.0f)
        off = 50.0f + diff;
    else
        off = 50.0f - diff;
    CGtV3d side = CrossProduct(kYAxis, field_48->field_18D0) * func_0032F840_inl1(field_34);
    CGtV3d p = func_0032F840_inl3(field_48->field_30, field_44->field_18D0 * off);
    func_0032F840_inl4(p, side * 5.0f);
    field_10 = p;
    bool v;
    if (func_001419B0(field_44) == 0) {
        v = false;
    } else if (field_44->field_10C0.WasSlammedWithinTime(2.0f)) {
        v = false;
    } else if (field_44->field_18B4->field_4->field_8[field_44->field_18B8].field_2 == 0xFF) {
        v = true;
    } else if (field_44->field_1C02 != 0) {
        v = false;
    } else {
        v = true;
    }
    field_20 = v;
    field_44->field_1BE1 = field_20;
    field_34 = DotProduct(d, field_44->field_0);
    return 1;
}
