// NONMATCHING: GenerateTarget__14CB3AIAvoidanceFv -- retail 914 / ours 910 instructions, 635 in changed runs
// audit1 (2026-11-01): right-side channel loop had the opposite test: retail loops while k >= field_441 + 4 (never, from k = field_441), the draft ran 4 passes setting field_490/field_460 [C] retail 0x1416F0 (behaviour_audit cond-inverted) | Before: draftAJ C-first: span minima, right/left free-region scans (threshold follows rising occupancy, break rules as retail), centres clamped 1..255 / 0..254, side scores and the left/right choice (lane-change modes 4/2), target and look-ahead, speed band; else safest channel with blocked-side look-ahead; direction/distance tail; 910/914, calls identical, hunks 71; left: retail re-reads the occupancy at the scan merge point and field_4A4 per use (ours CSE), frame 0x280 vs 0x200
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra's loop structure dropped reachable blocks; every loop bound, break/continue path, compare sense and store traced from the asm); occupancy through an int (plain cvt.s.w), width converted unsigned as retail


// CB3AIAvoidance::GenerateTarget() -- draftAJ (C-first draft; the lifter refused it). 0x140A30, 0xE48. [C] name: retail's
// tables. Written from the retail asm (Ghidra's draft as a reading aid only: it drops reachable blocks of the scan loops).
// What it does [L]: picks the AI car's avoidance target from its avoidance map (the CB3AIAvoidanceMap at offset 0: 256
// channels of occupancy field_140 (x 8/255), clear distance field_240 (x 500/32767) and type field_40; the car's span is
// channels field_442..field_441, field_440 wide):
//  - occupancy below 4 under the car: grow a free region to the right and to the left of the span (the threshold follows
//    rising occupancy down to 0.2 below the best value), centre the car on each (right centre clamped to 1..255, left to
//    0..254), score both sides (average free space over the width + extra free space beside the span), choose a side
//    (field_4AC 1 = right, 2 = left; forced by the car's lane-change mode 4 / 2 and by full sides), and aim at the chosen
//    centre's lateral offset plus a look-ahead of 2 * clear distance / D_01E75550 (at least 5);
//  - otherwise steer for the map's safest channel with a speed-dependent look-ahead (stronger when blocked beside);
//  - pick the target speed field_488 from the nearest obstacle in the middle half of the span (10 / 20 / 30 m bands) and
//    the middle occupancy;
//  - field_470 = unit direction to the target, field_484 = its distance (in seconds at the car's speed when moving).
// Types and field meanings [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00140A30_mat { unsigned char pad_0[0x20]; CGtV3d field_20; CGtV3d field_30; };   // at, pos rows
struct UnkStruct_00140A30_phys {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;                        // velocity, w = speed
    unsigned char pad_C0[0x144];
    UnkStruct_00140A30_mat *field_204;
};
struct UnkStruct_00140A30_car {             // [G] CB3AICar
    unsigned char pad_0[0x1AC0];
    CGtV3d field_1AC0;                      // forward
    CGtV3d field_1AD0;                      // lateral step per channel
    unsigned char pad_1AE0[0x104];
    int field_1BE4;                         // lane-change mode
    int field_1BE8;
    int field_1BEC;
    unsigned char pad_1BF0[0x840];
    UnkStruct_00140A30_phys *field_2430;
};
struct UnkStruct_00140A30_drv {             // [G] driver parameters
    unsigned char pad_0[0x1D0];
    float field_1D0;                        // default target speed
    unsigned char pad_1D4[0x24];
    int field_1F8;
    int field_1FC;
};
class CB3AIAvoidanceMap {
public:
    int GetSafestChannel();
};
class CB3AIAvoidance {
public:
    void GenerateTarget();

    unsigned char pad_0[0x40];
    signed char field_40[256];              // channel type
    unsigned char field_140[256];           // occupancy (x 8/255)
    short field_240[256];                   // clear distance (x 500/32767)
    unsigned char field_440;                // span width in channels
    unsigned char field_441;                // span right
    unsigned char field_442;                // span left
    unsigned char pad_443[0x1D];
    CGtV3d field_460;                       // target point
    CGtV3d field_470;                       // direction to the target (unit)
    unsigned char pad_480[0x4];
    float field_484;                        // distance (time) to the target
    float field_488;                        // target speed
    float field_48C;
    float field_490;                        // right side free average
    float field_494;                        // left side free average
    float field_498;                        // extra free space right of the span
    float field_49C;                        // extra free space left of the span
    UnkStruct_00140A30_drv *field_4A0;
    UnkStruct_00140A30_car *field_4A4;
    unsigned char pad_4A8[0x4];
    unsigned char field_4AC;                // chosen side (16 = none)
    unsigned char field_4AD;                // left centre channel
    unsigned char field_4AE;                // right centre channel
};
struct UnkStruct_D_01E7553C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E7553C D_01E7553C;     // [G] target speeds per obstacle band
extern UnkStruct_D_01E7553C D_01E75540;
extern UnkStruct_D_01E7553C D_01E75544;
extern UnkStruct_D_01E7553C D_01E75548;
extern UnkStruct_D_01E7553C D_01E7554C;
extern UnkStruct_D_01E7553C D_01E75550;     // [G] look-ahead distance scale

// [G] channel accessors (occupancy 0..8, clear distance in metres)
static inline float func_00140A30_inl1(const CB3AIAvoidance *a, int i) { int o = a->field_140[i]; return 0.03137255f * (float)o; }
static inline float func_00140A30_inl2(const CB3AIAvoidance *a, int i) { return 0.015259255f * (float)a->field_240[i]; }

// [G] the nearest obstacle in the middle half of the span (type-6 channels ignored at speed >= 50)
static inline float func_00140A30_inl3(const CB3AIAvoidance *a)
{
    int lo = a->field_442;
    int hi = a->field_441;
    int q = (hi - lo) / 4;
    float md = 500.0f;
    for (int k = lo + q; k < hi - q; k++) {
        if (a->field_48C < 50.0f || a->field_40[k] != 6) md = GtMath::Min(md, func_00140A30_inl2(a, k));
    }
    return md;
}

// 0x00140A30
void CB3AIAvoidance::GenerateTarget()
{
    UnkStruct_00140A30_car *car = field_4A4;
    int mode = 0;
    if (car->field_1BEC == 0 && (unsigned int)(car->field_1BE8 - 1) < 2) mode = car->field_1BE4;
    field_494 = 0.0f;
    field_490 = 0.0f;
    field_4AC = 16;
    int lo = field_442;
    int hi = field_441;
    float minOcc = func_00140A30_inl1(this, lo);
    float minDist = func_00140A30_inl2(this, lo);
    for (int i = lo + 1; i <= hi; i++) {
        minOcc = GtMath::Min(minOcc, func_00140A30_inl1(this, i));
        minDist = GtMath::Min(minDist, func_00140A30_inl2(this, i));
    }
    int rc, lc;
    if (minOcc < 4.0f) {
        float midAvg;
        // free region to the right of the span
        {
            float thr = minOcc - 0.2f;
            float prev = minOcc;
            if (thr < 0.0f) thr = 0.0f;
            int i = lo;
            while (i < 256) {
                if (hi < i - field_440) {
                    if (func_00140A30_inl1(this, i) < thr) {
                        i--;
                        break;
                    }
                } else {
                    float v = func_00140A30_inl1(this, i);
                    if (v < thr) {
                        if (v < minOcc) break;
                        i++;
                        continue;
                    }
                }
                float v = func_00140A30_inl1(this, i);
                if (!(v < prev)) thr = v - 0.2f;
                prev = v;
                i++;
            }
            int j = i;
            while ((unsigned char)lo < j) {
                if (func_00140A30_inl1(this, j) < thr) {
                    j++;
                    break;
                }
                j--;
            }
            rc = GtMath::Clamp((i + j) / 2, 1, 255);
        }
        // free region to the left of the span
        {
            float thr = minOcc - 0.2f;
            float prev = minOcc;
            if (thr < 0.0f) thr = 0.0f;
            int i = (unsigned char)hi;
            while (i >= 0) {
                if (i + field_440 < lo) {
                    if (func_00140A30_inl1(this, i) < thr) {
                        i++;
                        break;
                    }
                } else {
                    float v = func_00140A30_inl1(this, i);
                    if (v < thr) {
                        if (v < minOcc) break;
                        i--;
                        continue;
                    }
                }
                float v = func_00140A30_inl1(this, i);
                if (!(v < prev)) thr = v - 0.2f;
                prev = v;
                i--;
            }
            int j = i;
            while (j < hi) {
                if (func_00140A30_inl1(this, j) < thr) {
                    j--;
                    break;
                }
                j++;
            }
            lc = GtMath::Clamp((i + j) / 2, 0, 254);
        }
        // side scores
        field_490 = 0.0f;
        for (int k = 0; k < field_440; k++) field_490 += 8.0f - func_00140A30_inl1(this, rc - k);
        field_490 = field_490 / (float)field_440;
        field_498 = 0.0f;
        for (int k = field_442; k <= rc; k++) {
            float v = func_00140A30_inl1(this, k);
            if (v < 2.0f) field_498 += 8.0f - v;
        }
        field_494 = 0.0f;
        for (int k = 0; k < field_440; k++) field_494 += 8.0f - func_00140A30_inl1(this, lc + k);
        field_494 = field_494 / (float)field_440;
        field_49C = 0.0f;
        for (int k = field_441; k >= lc; k--) {
            float v = func_00140A30_inl1(this, k);
            if (v < 2.0f) field_49C += 8.0f - v;
        }
        float rightAvg = field_490;
        float leftAvg = field_494;
        float rightScore = rightAvg + field_498;
        float leftScore = leftAvg + field_49C;
        float sum = 0.0f;
        for (int k = 0; k < field_440; k++) {
            int t = field_40[field_442 + k];
            if (!(t < 2) && t < 5) sum += 8.0f - func_00140A30_inl1(this, field_442 + k);
        }
        midAvg = sum / (8.0f * (float)field_440);
        bool useRight;
        if (leftAvg != 8.0f && (mode == 4 || rightAvg == 8.0f)) {
            useRight = false;
        } else if (field_441 == rc) {
            useRight = false;
        } else if (rightAvg != 8.0f && (mode == 2 || leftAvg == 8.0f)) {
            useRight = true;
        } else if (field_442 == lc) {
            useRight = true;
        } else {
            useRight = rightScore < leftScore;
        }
        if (useRight) {
            field_460 = car->field_1AD0 * (0.2f * (float)(rc - field_441));
            field_4AC = 1;
        } else {
            field_460 = car->field_1AD0 * (0.2f * (float)(lc - field_442));
            field_4AC = 2;
        }
        float ahead = GtMath::Max(5.0f, 2.0f * (minDist / D_01E75550.field_0));
        CGtV3d t = car->field_1AC0 * ahead;
        t += car->field_2430->field_204->field_30;
        field_460 += t;
        float md = func_00140A30_inl3(this);
        if (md < 10.0f) {
            field_488 = D_01E7553C.field_0;
        } else if (md < 20.0f) {
            field_488 = D_01E75540.field_0;
        } else if (md < 30.0f) {
            field_488 = D_01E75544.field_0;
        } else if (midAvg <= 0.9f) {
            field_488 = field_4A0->field_1D0;
        } else if (midAvg <= 0.95f) {
            field_488 = D_01E7554C.field_0;
        } else {
            field_488 = D_01E75548.field_0;
        }
    } else {
        // blocked under the car: head for the safest channel
        int safe = ((CB3AIAvoidanceMap *)this)->GetSafestChannel();
        field_460 = car->field_1AD0 * (0.2f * (float)(safe - 128));
        CGtV3d t;
        UnkStruct_00140A30_drv *drv = field_4A0;
        if (drv->field_1FC == 0 && drv->field_1F8 != 0) {
            t = car->field_1AC0 * (float)car->field_2430->field_B0.W();
            t += field_460;
        } else {
            t = car->field_1AC0 * (4.0f * (float)car->field_2430->field_B0.W());
            t += field_460;
        }
        field_460 = car->field_2430->field_204->field_30 + t;
        for (int k = field_442; k >= field_442 - 4; k--) {
            if (k < 0) continue;
            if (!(func_00140A30_inl1(this, k) < 1.0f)) continue;
            field_494 = 1.0f;
            if (safe < field_442) {
                UnkStruct_00140A30_phys *ph = field_4A4->field_2430;
                field_460 = ph->field_204->field_30 + field_4A4->field_1AC0 * (10.0f * (float)ph->field_B0.W());
            }
        }
        // audit1 [C] retail 0x1416E4..0x1416F0: `slt at, k, f441+4; beqz at, body` -- the body runs while k >= field_441 + 4,
        // so from k = field_441 it never runs (retail's test, kept as is; the mirror of the k >= field_442 - 4 loop above)
        for (int k = field_441; k >= field_441 + 4; k++) {
            if (!(k < 256)) continue;
            if (!(func_00140A30_inl1(this, k) < 1.0f)) continue;
            field_490 = 1.0f;
            if (field_441 < safe) {
                UnkStruct_00140A30_phys *ph = field_4A4->field_2430;
                field_460 = ph->field_204->field_30 + field_4A4->field_1AC0 * (10.0f * (float)ph->field_B0.W());
            }
        }
        rc = safe;
        lc = safe;
        float md = func_00140A30_inl3(this);
        if (md < 10.0f) {
            field_488 = D_01E7553C.field_0;
        } else if (md < 20.0f) {
            field_488 = D_01E75540.field_0;
        } else if (md < 30.0f) {
            field_488 = D_01E75544.field_0;
        } else {
            field_488 = field_4A0->field_1D0;
        }
    }
    // direction and distance to the target
    UnkStruct_00140A30_mat *m = field_4A4->field_2430->field_204;
    field_470 = field_460 - m->field_30;
    ((float *)&field_470)[3] = ((const float *)&m->field_30)[3]; // [C] 0x1412B0 lqc2 vf1, 0x30(v1) (m->field_30); 0x1412B4
    // vsub.xyz vf1, vf2, vf1 keeps its w; 0x1412B8 sqc2 vf1, 0x470(s0) -- `a - b` took field_460's w
    if (field_470.GetSquaredLength() < 2.3283064e-10f) field_470 = field_4A4->field_2430->field_204->field_20;
    if (!((float)field_4A4->field_2430->field_B0.W() <= 1.0f)) {
        field_484 = field_470.GetLength() / (float)field_4A4->field_2430->field_B0.W();
    } else {
        field_484 = field_470.GetLength();
    }
    field_470.Normalise();
    field_4AE = rc;
    field_4AD = lc;
}
