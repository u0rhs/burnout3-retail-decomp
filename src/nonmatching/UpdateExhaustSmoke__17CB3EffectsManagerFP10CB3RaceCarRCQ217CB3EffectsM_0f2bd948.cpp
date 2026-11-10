// NONMATCHING: UpdateExhaustSmoke__17CB3EffectsManagerFP10CB3RaceCarRCQ217CB3EffectsManager9CLighting -- retail 117 / ours 119 instructions, 26 in changed runs
// psweep: scoped #pragma opt_propagation off [G] improves 51 -> 34
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3EffectsManager::UpdateExhaustSmoke(CB3RaceCar*, const CB3EffectsManager::CLighting&) -- hand-written (ghvu5, Ghidra draft).
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md). Fields placeholders, types [G].
#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_propagation off
using namespace GtMathPs2;
struct UnkStruct_00260210_e { CGtV3d field_0; CGtV3d field_10; unsigned char pad_20[0x10]; };
struct UnkStruct_00260210_m { unsigned char pad_0[0x1684]; UnkStruct_00260210_e *field_1684; unsigned char pad_1688[0x2C]; unsigned char field_16B4; };
class CB3RaceCar {
public:
    CGtMatrix3x4 field_0;
    UnkStruct_00260210_m *field_40;
    unsigned char pad_44[0x10];
    float field_54;
    unsigned char pad_58[0x1054];
    int field_10AC;
};
// [L] lu8ExhaustAccumulator$36201 (config/symbol_addrs_b3names.txt, medium): a function-local static in .sbss
extern unsigned int D_004E29EC;
class CB3EffectsManager {
public:
    struct CLighting;
    void UpdateExhaustSmoke(CB3RaceCar *car, const CLighting &l);
    unsigned char pad_0[0x1F84C];
    float field_1F84C;
};
extern "C" void func_0025EA70(CB3EffectsManager *self, const CGtV3d *pos, const CGtV3d *vel, const CGtV3d *vel2, int n,
    const CB3EffectsManager::CLighting *l, void *p, int k, unsigned long q, float a, float b);
// N140: unused locals reserving retail's four dead 16-byte frame slots under the loop vectors [G]
struct UnkStruct_00260210_pad { int x[4]; UnkStruct_00260210_pad() {} ~UnkStruct_00260210_pad() {} };
// [L] N185: TransformPoint / a 3-row rotation on compiler-chosen registers (retail rows in $vf4/$vf3/$vf2/$vf1 here; the
// header TransformPoint hard-codes rows 1-3 on $vf1)
static inline CGtV3d func_00260210_inl1(const CGtMatrix3x4 &m, const CGtV3d &v)
{
    u_long128 t;
    u_long128 r;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "vmadday.xyz $ACC, %3, %2y" "\n\t" "vmaddaz.xyz $ACC, %4, %2z" "\n\t" "vmaddw.xyz %0, %5, $vf0w"
        : "=j"(t) : "j"(m.mRight.mData), "j"(v.mData), "j"(m.mUp.mData), "j"(m.mAt.mData), "j"(m.mPos.mData));
    asm("qmfc2.i %0, %1" : "=r"(r) : "j"(t));
    return CGtV3d(r);
}
static inline CGtV3d func_00260210_inl2(const CGtMatrix3x4 &m, const CGtV3d &v)
{
    u_long128 t;
    u_long128 r;
    UnkStruct_00260210_pad p0, p1, p2, p3;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "vmadday.xyz $ACC, %3, %2y" "\n\t" "vmaddz.xyz %0, %4, %2z"
        : "=j"(t) : "j"(m.mRight.mData), "j"(v.mData), "j"(m.mUp.mData), "j"(m.mAt.mData));
    asm("qmfc2.i %0, %1" : "=r"(r) : "j"(t));
    return CGtV3d(r);
}
static inline float func_00260210_inl3(float a, float b, float t) { float d = b - a; return 0.0f + a + d * t; }
// 0x00260210
void CB3EffectsManager::UpdateExhaustSmoke(CB3RaceCar *car, const CLighting &l)
{
    if (car->field_54 < 9.0f && car->field_10AC < 9999) {
        CGtMatrix3x4 m = car->field_0;
        float t = 0.0001000100019f * (float)car->field_10AC;
        UnkStruct_00260210_e *e = car->field_40->field_1684;
        int n = car->field_40->field_16B4;
        int old;
        float sc; float sz; float al;
        sc = func_00260210_inl3(0.15f, 1.25f, t);
        float a = 0.0f + 1.0f - 0.1111111119f * car->field_54;
        sz = field_1F84C * func_00260210_inl3(14.1f, 25.1f, t);
        float u = 1.0f - t;
        u = a * u;
        float b = 1.0f - u;
        b = b * b;
        al = 1.0f - b;
        while (old = n, n = (unsigned char)(n - 1), old != 0) {
            CGtV3d pos = func_00260210_inl1(m, e->field_0);
            CGtV3d vel = func_00260210_inl2(m, e->field_10) * sc;
            func_0025EA70(this, &pos, &vel, &vel, 10, &l, &D_004E29EC, 0, 0, sz, al);
            e++;
        }
    }
}




#pragma pop
