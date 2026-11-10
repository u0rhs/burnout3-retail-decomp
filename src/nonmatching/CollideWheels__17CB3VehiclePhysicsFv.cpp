// NONMATCHING: CollideWheels__17CB3VehiclePhysicsFv -- retail 395 / ours 383 instructions, 334 in changed runs
// son5: logic complete (wheel ray setup, TransformPoint, per-wheel DoWheelLineCollision, ground triangle scan); remaining: frame 0x250 vs 0x1B0 (extra dead locals/hoisted constants), VU reg choice, loop-counter register (retail s0, ours s3)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

extern float D_004E0698;
extern "C" bool IntersectLineTriangle__14GtIntersectionFRC7CGtLineQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPfPfPf(const void *, const void *, const void *, const void *, float *, float *, float *);

struct UnkStruct_001CDB70_line { CGtV3d field_0; CGtV3d field_10; };
struct UnkStruct_001CDB70_tri { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; CGtV3d field_30; };
struct UnkStruct_001CDB70_mesh {
    int field_0;
    UnkStruct_001CDB70_tri *field_4;
    unsigned short *field_8;
};
struct UnkStruct_001CDB70_cc4 {
    unsigned char pad_0[0x490];
    CGtV3dPlus field_490;
    unsigned char pad_4A0[0xC];
    signed char field_4AC[6];   // [G] count (six wheels: the trucks)
};
struct UnkStruct_001CDB70_wheel {   // [G] 0xC0 stride, base veh+0x820
    CGtV3d field_0;
    CGtV3d field_10;
    CGtV3d field_20;
    CGtV3d field_30;
    CGtV3d field_40;
    float field_50;
    unsigned char pad_54[0x10];
    float field_64;
    unsigned char pad_68[0xC];
    float field_74;
    unsigned char pad_78[0x38];
    unsigned short field_B0;
    unsigned char pad_B2[1];
    unsigned char field_B3;
    unsigned char field_B4;
    unsigned char pad_B5[0xB];
};

class CB3VehiclePhysics {
public:
    void CollideWheels();
    bool DoWheelLineCollision(CGtV3d, CGtV3d, int *, float *);

    unsigned char pad_0[0x200];
    UnkStruct_001CDB70_mesh *field_200;
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0x820 - 0x208];
    UnkStruct_001CDB70_wheel field_820[6];   // six wheels at the 0xC0 stride end at 0xCA0 [C 0x1CDB98 i*0xC0]
    unsigned char pad_CA0[0xCAC - 0xCA0];
    float field_CAC;
    unsigned char pad_CB0[0xCBC - 0xCB0];
    float field_CBC;
    unsigned char pad_CC0[4];
    UnkStruct_001CDB70_cc4 *field_CC4;
    CGtMatrix3x4 *field_CC8[6];   // [G] count (six wheels)
};

// 0x001CDB70
void CB3VehiclePhysics::CollideWheels()
{
    CGtV3d up = field_204->mUp;
    for (int i = 0; i < *(signed char *)((char *)this + 0x1169); i++) {
        field_820[i].field_30 = field_820[i].field_0;
        field_820[i].field_40 = field_820[i].field_10;
    }
    CGtV3d zero;
    asm("vadd.xyz %0, $vf0, $vf0" : "=j"(zero.mData));
    // six wheels (CB3VehiclePhysics +0x1169 is 6 for the six-wheeled traffic: the native port's crash in a race,
    // 2026-11-08); retail's frame has six entries each: lineB sp+0x160, lineA sp+0x1C0, 0x60 apart [C 0x1CDC24 / 0x1CDC88]
    CGtV3d lineB[6];
    CGtV3d lineA[6];
    float lo[6];
    float hi[6];
    int i;
    for (i = 0; i < *(signed char *)((char *)this + 0x1169); i++) {
        lineA[i] = field_CC8[i]->mPos;
        lineB[i] = field_CC8[i]->mPos;
        float k = (i < 2) ? field_CAC : field_CBC;
        float a = field_820[i].field_74;
        float b = field_820[i].field_50;
        float f14 = a + b;
        float f13 = (a - k * 0.75f) - b;
        hi[i] = f14;
        lo[i] = f13;
        lineA[i].SetY(f14);
        lineB[i].SetY(f13);
        if (field_CC4->field_4AC[i] == 2) {
            CGtV3d t = zero;
            t.SetY(b * 0.25f);
            lineB[i] = lineB[i] + t;
        }
    }
    CGtMatrix3x4 *m = field_204;
    for (i = 0; i < *(signed char *)((char *)this + 0x1169); i++) {
        lineA[i] = TransformPoint(*m, lineA[i]);
    }
    m = field_204;
    for (i = 0; i < *(signed char *)((char *)this + 0x1169); i++) {
        lineB[i] = TransformPoint(*m, lineB[i]);
    }
    int n = *(signed char *)((char *)this + 0x1169);
    float h = hi[1] > hi[n - 1] ? hi[1] : hi[n - 1];
    float l = lo[1] < lo[n - 1] ? lo[1] : lo[n - 1];
    float range = -(h - l);
    CGtV3d dir = up * range;
    float fVar4 = D_004E0698;
    int idx;
    float dist;
    for (i = 0; i < *(signed char *)((char *)this + 0x1169); i++) {
        if (field_CC4->field_4AC[i] == 3 || !DoWheelLineCollision(lineA[i], lineB[i], &idx, &dist)) {
            field_820[i].field_B3 = 0;
            field_820[i].field_B4 = 0;
            field_820[i].field_10 = field_820[i].field_0 - field_204->mUp * field_820[i].field_50;
            field_820[i].field_20 = field_204->mUp;
        } else {
            field_820[i].field_B3 = 1;
            CGtV3d c = field_200->field_4[idx].field_30;
            if (((float *)&c)[1] < fVar4) {
                field_820[i].field_20 = field_204->mUp;
            } else {
                field_820[i].field_20 = c;
            }
            unsigned short s = field_200->field_8[idx];
            unsigned char t = s;
            if (t < 0xC || (t >= 0xC && t <= 0x14) || t == 0x26) {
                field_820[i].field_B0 = s;
            }
            float len = (float)dir.GetLength();
            field_820[i].field_10 = lineA[i];
            field_820[i].field_10 += dir * (dist / len); // [C] w = lineA[i].w (= field_204->mPos.w): 0x1CE13C lqc2 vf1, 0x1C0(a1);
            // 0x1CE150 vmulx.xyz vf2; 0x1CE154 vadd.xyz vf1, vf1, vf2; 0x1CE158 sqc2 vf1, 0x830(a0) -- `a + b` took b's w (port lane vu0, culprit #11)
            field_820[i].field_64 = field_820[i].field_50 + (hi[i] - dist);
        }
    }
    *(unsigned short *)((char *)this + 0x1160) = field_820[0].field_B0;
    fVar4 = 1000.0f;
    UnkStruct_001CDB70_line ln;
    ln.field_0 = field_204->mPos;
    CGtV3d e = field_204->mPos;
    e.SetY(field_204->mPos.Y() - 30.0f);
    ln.field_10 = e;
    field_CC4->field_490.SetPlus(9999.0f);
    for (int j = 0; j < field_200->field_0; j++) {
        UnkStruct_001CDB70_tri *tri = &field_200->field_4[j];
        float u, v, tt;
        if (IntersectLineTriangle__14GtIntersectionFRC7CGtLineQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPfPfPf(&ln, tri, &tri->field_10, &tri->field_20, &tt, &v, &u) && tt < fVar4) {
            field_CC4->field_490.SetPlus(tt * 30.0f);
            field_CC4->field_490.SetGtV3d(field_200->field_4[j].field_30);
            *(unsigned short *)((char *)this + 0x1160) = field_200->field_8[j];
            fVar4 = tt;
        }
    }
    *(unsigned char *)((char *)this + 0x1352) = 1;
}
