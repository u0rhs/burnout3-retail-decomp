// NONMATCHING: DetectNormalNearMiss__8CB3ScoreFP17CB3TrafficVehicle -- retail 504 / ours 412 instructions, 728 in changed runs
// fix1 (2026-11-01): reviewed against retail 0x1586D0..0x158EAC: every compare sense, negation pair, sum order and both minimum stages as retail (only NaN handling of `!(x<y)` written `x>=y` differs); no stand-in or undecoded range left, so TRACK near (412 vs 504 is codegen). The port6 live mismatches (31/1572) were the port's sqrtf ABI bug, not this source. | Before: son9 first archive: logic via CGtV2d xz helpers (ld/sd temps shape like retail, 412 vs 504 instrs). Left: retail's box-centre/pos via VU lane adds (vaddx.x/z with scalar GPR round trips), local CGtV4d copies of rows kept on stack (frame 0x580 vs 0x260), mula/madd+sqrt length helper; the signed 'dot<0 -> negate' float tail not reg-matched
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [C] fix1 (2026-11-01): live shadow race (the port project harness, the port's sqrt.s fix): 1,572 calls, 0 mismatches; 24/24 port6 live captures pass the Burn3 checker at tolerance 0 -- on those inputs

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

extern "C" float sqrtf(float);

static inline CGtV2d func_001586D0_xz(CGtV4d v) { return CGtV2d(v.f[0], v.f[2]); }
static inline float func_001586D0_len(CGtV2d v) { return sqrtf(v.X() * v.X() + v.Y() * v.Y()); }

struct UnkStruct_001586D0_box {
    unsigned char pad_0[0xE80];
    CGtV4d field_E80;
    CGtV4d field_E90;
};

struct UnkStruct_001586D0_xf {
    CGtV4d field_0;
    unsigned char pad_10[0x10];
    CGtV4d field_20;
    CGtV4d field_30;
    UnkStruct_001586D0_box * field_40;
};

class CB3TrafficVehicle {
public:
    unsigned char pad_0[0x70];
    CGtV4d field_70;
    unsigned char pad_80[0x10];
    CGtV4d field_90;
    CGtV4d field_A0;
    UnkStruct_001586D0_box * field_B0;
};

class CB3Score {
public:
    static float gmrMaxNearMissDistance;
    unsigned char pad_0[0xC8];
    UnkStruct_001586D0_xf * field_C8;
    bool DetectNormalNearMiss(CB3TrafficVehicle *);
};

// 0x001586D0
bool CB3Score::DetectNormalNearMiss(CB3TrafficVehicle * v)
{
    UnkStruct_001586D0_xf * a = field_C8;
    CGtV4d d = v->field_A0 - a->field_30;
    if (d.f[1] > 4.0f) return false;
    if (d.f[1] < -4.0f) return false;
    UnkStruct_001586D0_box * ba = a->field_40;
    UnkStruct_001586D0_box * bb = v->field_B0;
    CGtV2d hA = (func_001586D0_xz(ba->field_E80) - func_001586D0_xz(ba->field_E90)) * 0.5f;
    CGtV2d cA = func_001586D0_xz(ba->field_E90) + hA;
    CGtV2d hB = (func_001586D0_xz(bb->field_E80) - func_001586D0_xz(bb->field_E90)) * 0.5f;
    CGtV2d cB = func_001586D0_xz(bb->field_E90) + hB;
    CGtV2d ra = func_001586D0_xz(a->field_0);
    CGtV2d rb = func_001586D0_xz(a->field_20);
    CGtV2d rc = func_001586D0_xz(v->field_70);
    CGtV2d rd = func_001586D0_xz(v->field_90);
    CGtV2d ea = ra * hA.X();
    CGtV2d eb = rb * hA.Y();
    CGtV2d ec = rc * hB.X();
    CGtV2d ee = rd * hB.Y();
    CGtV2d pA = func_001586D0_xz(a->field_30) + ra * cA.X() + rb * cA.Y();
    CGtV2d pB = func_001586D0_xz(v->field_A0) + rc * cB.X() + rd * cB.Y();
    CGtV2d dv = pB - pA;
    float m = gmrMaxNearMissDistance;
    if (m + func_001586D0_len(hA) + func_001586D0_len(hB) < func_001586D0_len(dv)) return false;
    float dx = dv.X();
    float dz = dv.Y();
    float a0 = ea.X(), a1 = ea.Y(), b0 = eb.X(), b1 = eb.Y();
    float c0 = ec.X(), c1 = ec.Y(), e0 = ee.X(), e1 = ee.Y();
    if (dx * a0 + dz * a1 + 0.0f < 0.0f) { a0 = a0 * -1.0f; a1 = a1 * -1.0f; }
    if (dx * b0 + dz * b1 < 0.0f) { b0 = b0 * -1.0f; b1 = b1 * -1.0f; }
    if (dx * c0 + dz * c1 >= 0.0f) { c0 = c0 * -1.0f; c1 = c1 * -1.0f; }
    if (dx * e0 + dz * e1 >= 0.0f) { e0 = e0 * -1.0f; e1 = e1 * -1.0f; }
    dz = dz + ((c1 + e1) - (a1 + b1));
    dx = dx + ((c0 + e0) - (a0 + b0));
    float d2 = dx * dx + dz * dz;
    float t = dx * e0 + dz * e1;
    float best;
    if (t < 0.0f) {
        float u = dx * c0 + dz * c1 + 0.0f;
        best = d2;
        if (u >= 0.0f) {
            u = u / (c0 * c0 + c1 * c1 + 0.0f);
            float px = dx - c0 * u;
            float pz = dz - c1 * u;
            best = px * px + pz * pz + 0.0f;
            if (d2 <= best) best = d2;
        }
    } else {
        t = t / (e0 * e0 + e1 * e1 + 0.0f);
        float px = dx - e0 * t;
        float pz = dz - e1 * t;
        best = px * px + pz * pz + 0.0f;
        if (d2 <= best) best = d2;
    }
    float s = dx * b0 + dz * b1;
    float r;
    if (s >= 0.0f) {
        float u = dx * a0 + dz * a1 + 0.0f;
        r = best;
        if (u < 0.0f) {
            u = u / (a0 * a0 + a1 * a1 + 0.0f);
            float px = dx - a0 * u;
            float pz = dz - a1 * u;
            r = px * px + pz * pz + 0.0f;
            if (best <= r) r = best;
        }
    } else {
        s = s / (b0 * b0 + b1 * b1 + 0.0f);
        float px = dx - b0 * s;
        float pz = dz - b1 * s;
        r = px * px + pz * pz + 0.0f;
        if (best <= r) r = best;
    }
    if (r < gmrMaxNearMissDistance * gmrMaxNearMissDistance) return true;
    return false;
}
