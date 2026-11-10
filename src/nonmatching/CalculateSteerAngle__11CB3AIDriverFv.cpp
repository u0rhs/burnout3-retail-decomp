// NONMATCHING: CalculateSteerAngle__11CB3AIDriverFv -- retail 400 / ours 426 instructions, 317 in changed runs
// fix3 (2026-11-01): steer gain factor is 1.0 when the target and current steer have the same sign, D_004E143C only when they differ (retail copysign compare at 0x145388) | Before: son5: logic mapped (target-direction blend, acos-style angle via func_0011E328, sign-based gain D_004E1434/1438, 90-degree clamp, rate limiter vs 9CC); remaining: frame 0x390 vs ours 0x100 (retail keeps ~8 dead V4d stack copies of B0 per gain branch), min/max.s vs compare clamps, VU scheduling | N275 header APIs (gapK)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

extern float D_004E0D6C;
extern float D_004E143C;
extern float D_004E1434;
extern float D_004E1438;
extern float D_004E069C;
extern float D_004E0EAC;
extern float D_004E0EB0;
extern float D_004E0EB4;
extern float D_004E0EB8;
extern float D_01E754F4;
extern "C" int func_001419B0(void *);
extern "C" float func_0011E328(float);

struct UnkStruct_00144E70_car {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    CGtV4d field_C0;
    CGtV4d field_D0;
    unsigned char pad_E0[0x204 - 0xE0];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0x13AC - 0x208];
    float field_13AC;
    unsigned char pad_13B0[0x1524 - 0x13B0];
    int field_1524;
};
struct UnkStruct_00144E70_a {
    CGtV3d field_0;
    unsigned char pad_10[0x10];
    CGtV3d field_20;
    unsigned char pad_30[0x2430 - 0x30];
    UnkStruct_00144E70_car *field_2430;
};

class CB3AIDriver {
public:
    void CalculateSteerAngle();

    unsigned char pad_0[0x1F8];
    int field_1F8;
    unsigned char pad_1FC[0x7A0 - 0x1FC];
    UnkStruct_00144E70_a *field_7A0;
    unsigned char pad_7A4[0xC];
    CGtV3d field_7B0;
    unsigned char pad_7C0[0x9C0 - 0x7C0];
    float field_9C0;
    unsigned char pad_9C4[4];
    float field_9C8;
    float field_9CC;
    unsigned char pad_9D0[4];
    float field_9D4;
};

// 0x00144E70
void CB3AIDriver::CalculateSteerAngle()
{
    field_9D4 = 0.0f;
    if (func_001419B0(field_7A0) != 0) {
        UnkStruct_00144E70_car * const car0 = field_7A0->field_2430;
#define car (field_7A0->field_2430)
        CGtV4d t = car0->field_B0;
        if (D_004E0D6C * ((float *)&t)[3] <= car->field_13AC || (unsigned int)(car->field_1524 - 1) < 2) {
            CGtV3d at = ((CGtMatrix3x4 *)car->field_204)->mAt;
            CGtV3d c;
            if (field_1F8 == 1) {
                c = *(CGtV3d *)&car->field_C0;
            } else {
                c = *(CGtV3d *)&car->field_C0 + at;
            }
            CGtV3d dir;
            if ((float)c.IsEffectivelyZero()) {
                dir = at;
            } else {
                dir = c;
                dir.Normalise();
            }
            float d = (float)DotProduct(field_7B0, dir);
            d = d > -1.0f ? d : -1.0f;
            d = d > 1.0f ? 1.0f : d;
            float ang = func_0011E328(d);
            CGtV3d cr = CrossProduct(dir, field_7A0->field_2430->field_204->mRight);
            if ((float)cr.IsEffectivelyZero()) {
                cr = CrossProduct(dir, at);
            }
            CGtV3d cr2 = CrossProduct(cr, dir);
            cr2.Normalise();
            if ((float)DotProduct(cr2, field_7B0) < 0.0f) {
                ang = -ang;
            }
            float f3 = ang / field_9C8;
            CGtV4d y = car->field_D0;
            float f4 = ((float *)&y)[1];
            // fix3 [C] retail 0x145330..0x145398: g = 1 when f3 and f4 have the same sign bit (two copysign(1, x) compared
            // with c.eq), D_004E143C otherwise (the draft always used D_004E143C)
            union { float f; unsigned int u; } s3, s4;
            s3.f = f3;
            s4.f = f4;
            s3.u = (s3.u & 0x80000000) | 0x3F800000;
            s4.u = (s4.u & 0x80000000) | 0x3F800000;
            float g = (s3.f == s4.f) ? 1.0f : D_004E143C;
            field_9D4 = f4 - f3;
            float k;
            if (f4 <= 0.0f) {
                k = (f3 <= f4) ? D_004E1434 : D_004E1438;
            } else {
                k = (f3 <= f4) ? D_004E1438 : D_004E1434;
            }
            CGtV4d w1 = car->field_B0;
            CGtV4d w2 = car->field_B0;
            field_9C0 = g * (k * (((f3 - f4) * ((float *)&w1)[3]) * ((float *)&w2)[3]));
            if (!(field_9C0 <= 90.0f)) field_9C0 = 90.0f;
            if (field_9C0 < -90.0f) field_9C0 = -90.0f;
            field_9CC = 0.0f;
            return;
        }
    }
#undef car
    float tt = D_01E754F4;
    CGtV3d v = field_7A0->field_20 * tt + *(CGtV3d *)&field_7A0->field_2430->field_C0 * (1.0f - D_01E754F4);
    v.Normalise();
    float dd = (float)DotProduct(field_7B0, v);
    field_9C0 = dd;
    dd = dd > -1.0f ? dd : -1.0f;
    dd = dd > 1.0f ? 1.0f : dd;
    field_9C0 = D_004E069C * func_0011E328(dd);
    if ((float)DotProduct(field_7A0->field_0, field_7B0) < 0.0f) {
        field_9C0 = -field_9C0;
    }
    float delta = field_9C0 - field_9CC;
    if (field_9CC > 0.0f) {
        if (delta > D_004E0EAC) field_9C0 = D_004E0EAC + field_9CC;
        if (delta < D_004E0EB0) field_9C0 = field_9CC - D_004E0EB4;
    } else {
        if (delta > D_004E0EB4) field_9C0 = D_004E0EB4 + field_9CC;
        if (delta < D_004E0EB8) field_9C0 = field_9CC - D_004E0EAC;
    }
    field_9CC = field_9C0;
}
