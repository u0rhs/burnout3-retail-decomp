// NONMATCHING: WorldSafeBodyTranslations__17CB3PhysicsManagerFP16CB3CollidingPairPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3d -- retail 215 / ours 219 instructions, 75 in changed runs
// psweep: scoped #pragma inline_depth(5) [G] improves 158 -> 91
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3PhysicsManager.cpp.
#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(5)
using namespace GtMathPs2;

struct UnkStruct_001B3B40_3 {
    unsigned char pad_0[0xC0];
    CGtV3d field_C0;
    unsigned char pad_D0[0xA0];
    CGtV3d field_170;
    unsigned char pad_180[0x92];
    unsigned char field_212;
};
struct UnkStruct_001B3B40_1 {
    unsigned char pad_0[0xC];
    UnkStruct_001B3B40_3 * field_C;
};
class CB3CollidingPair {
public:
    unsigned char pad_0[0x24];
    UnkStruct_001B3B40_1 * field_24;
    UnkStruct_001B3B40_1 * field_28;
};
class CB3PhysicsManager {
public:
    void WorldSafeBodyTranslations(CB3CollidingPair* p0, CGtV3d* p1, CGtV3d* p2);
};
// [L] N185 stand-in: CGtV3d::operator*(float)'s earlier hard-coded body (GtMathPs2.h comment: `qmtc2 %1,$vf1;
// qmtc2.ni %2,$vf2; vmulx.xyz $vf1,$vf1,$vf2x`) -- retail reloads the vector (lqc2 into $vf1) for this product.
static inline CGtV3d func_001B3B40_inl4(const CGtV3d& v, float s)
{
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2.ni %2, $vf2" "\n\t" "vmulx.xyz $vf1, $vf1, $vf2x" "\n\t" "qmfc2 %0, $vf1"
        : "=r"(t) : "r"(v.mData), "r"(s));
    return CGtV3d(t);
}

static inline bool func_001B3B40_inl2(CGtV3d v) { bool r = true; if (!(v.GetSquaredLength() < 2.3283064e-10f)) r = false; return r; }
static inline void func_001B3B40_inl1(CGtV3d* p,  UnkStruct_001B3B40_3* b)
{
    u_long128 v = p->mData;
    if (!func_001B3B40_inl2(CGtV3d(v))) {
        float d = DotProduct(CGtV3d(v), b->field_170);
        if (d < -0.1f) {
            float len = CGtV3d(v).GetLength();
            CGtV3d dir;
            CGtV3d t = CGtV3d(v); t -= func_001B3B40_inl4(b->field_170, d);
            if (!func_001B3B40_inl2(t)) { dir = t; dir.Normalise(); }
            else dir = -b->field_C0;
            *p = dir * len;
        }
    }
}
void CB3PhysicsManager::WorldSafeBodyTranslations(CB3CollidingPair* p0, CGtV3d* p1, CGtV3d* p2)
{
    UnkStruct_001B3B40_3 * b0 = p0->field_24->field_C;
    UnkStruct_001B3B40_3 * b1 = p0->field_28->field_C;
    if (b0->field_212 != 0) func_001B3B40_inl1(p1, b0);
    if (b1->field_212 != 0) func_001B3B40_inl1(p2, b1);
}

#pragma pop
