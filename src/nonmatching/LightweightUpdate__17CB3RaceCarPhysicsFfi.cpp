// NONMATCHING: LightweightUpdate__17CB3RaceCarPhysicsFfi -- retail 234 / ours 234 instructions, 9 in changed runs
// near2: 9 off (was 15), frame now exact (0x120): the loop's W read as *(const WAxisType *)&field_B0 (one slot, v297), the end read stays field_B0.W(). Left: (1) dPos/d100 -- retail stores the vsub results into the inline result slots (0x80/0x70, bottom) and leaves the named slots (F0/E0) dead; ours uses the named ones; (2) the loop W copy sits at 0xD0 in retail (ours 0xA0, below 3 dead) + its v0/v1 swap. Tried: init/assign/ref forms, u_long128 / by-value / const returns, =m store, declaration orders.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// CB3RaceCarPhysics::LightweightUpdate(float,int). Field names placeholders, types [G] (instruction widths).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3RaceCar {
public:
    void UpdateAggressiveReaction();
    unsigned char pad_0[0x178C];
    int field_178C;
};
struct UnkStruct_001C44E0_e0 {
    unsigned char pad_0[0x40];
    float field_40;
    float field_44;
    unsigned char pad_48[0x78];
};
struct UnkStruct_001C44E0_8 {
    unsigned char pad_0[0xC];
    signed char field_C;
};
struct UnkStruct_001C44E0_7 {
    unsigned char pad_0[0x40];
    UnkStruct_001C44E0_8 * field_40;
    unsigned char pad_44[0x10];
    float field_54;
};
struct UnkStruct_001C44E0_10 {
    unsigned char pad_0[0x4B2];
    signed char field_4B2[1];  // [G] element count unknown
    unsigned char pad_4B3[0xB75];
    int field_1028;
    int field_102C;
    unsigned char field_1030;
    unsigned char field_1031;
    unsigned char field_1032;
    unsigned char field_1033;
};
extern "C" void CollideWheels__17CB3VehiclePhysicsFv(void *);
extern "C" int DoDrivingWorldCollision__17CB3RaceCarPhysicsFv(void *);
extern "C" void UpdateSuspension__17CB3VehiclePhysicsFf(void *, float);
extern "C" void Update__16CB3CollidingBodyFf(void *, float);
extern "C" void UpdateHingedPart__17CB3VehiclePhysicsFif(void *, int, float);
extern "C" void UpdateWheelStates__17CB3RaceCarPhysicsFv(void *);
extern "C" void func_001C8290(void *, int);

class CB3RaceCarPhysics {
public:
    void LightweightUpdate(float p0, int p1);
    void CacheWorldTriangles(int);
    void ApplyDrivingForces(float);
    // vptr at +0x0: placeholder virtuals by slot offset [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    unsigned char pad_4[0xAC];
    CGtV4d field_B0;
    unsigned char pad_C0[0x30];
    CGtV3d field_F0;
    CGtV3d field_100;
    unsigned char pad_110[0x102];
    unsigned char field_212;
    unsigned char field_213;
    unsigned char pad_214[0x62C];
    UnkStruct_001C44E0_e0 field_840[1];  // [G] element count unknown
    unsigned char pad_900[0x3C0];
    UnkStruct_001C44E0_7 * field_CC0;
    UnkStruct_001C44E0_10 * field_CC4;
    unsigned char pad_CC8[0x4A0];
    unsigned char field_1168;
    signed char field_1169;
    unsigned char pad_116A[0x28A];
    CB3RaceCar * field_13F4;
    unsigned char pad_13F8[0x8];
    float field_1400;
    unsigned char pad_1404[0x40];
    unsigned char field_1444;
    unsigned char pad_1445[0x1];
    unsigned char field_1446;
    unsigned char pad_1447[0x55];
    float field_149C;
    unsigned char pad_14A0[0x28];
    int field_14C8;
    unsigned char pad_14CC[0x58];
    int field_1524;
    unsigned char pad_1528[0x4];
    float field_152C;
};

// [L] N185: stands in for CGtV3d::operator- on compiler-chosen VU registers (retail vsub.xyz vf3,vf4,vf3 / vf1,vf2,vf1)
static inline CGtV3d func_001C44E0_inl1(const CGtV3d &a, const CGtV3d &b)
{
    CGtV3d r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r.mData) : "j"(a.mData), "j"(b.mData));
    return r;
}


// [L] N185: stands in for CGtV4d::Zero() on a compiler-chosen VU register (retail vsub.xyzw $vf1,$vf0,$vf0; sqc2)
static inline void func_001C44E0_inl2(CGtV4d &v) { asm("vsub.xyzw %0, $vf0, $vf0" : "=j"(v.mData)); }

// 0x001C44E0
void CB3RaceCarPhysics::LightweightUpdate(float p0, int p1)
{
    int n = p1;
    CacheWorldTriangles(p1);
    vfunc_2C();
    CollideWheels__17CB3VehiclePhysicsFv(this);
    int i = 0;
    goto test0;
body0:
    field_840[i].field_40 = field_840[i].field_44;
    i++;
test0:
    if (i < field_1169) goto body0;
    CGtV3d oldPos = field_F0;
    CGtV3d old100 = field_100;
    ApplyDrivingForces(p0);
    CGtV3d dPos;
    CGtV3d d100;
    dPos = func_001C44E0_inl1(field_F0, oldPos);
    d100 = func_001C44E0_inl1(field_100, old100);
    bool twice = p1 >= 2;
    while (n > 0) {
        if (n < p1) {
            field_F0 = dPos;
            field_100 = d100;
        }
        field_212 = 0;
        field_213 = 0;
        if (DoDrivingWorldCollision__17CB3RaceCarPhysicsFv(this) == 0) {
            if (field_1524 == 3) field_1524 = 0;
        } else {
            field_1524 = 3;
            field_212 = 1;
        }
        if (n < p1) CollideWheels__17CB3VehiclePhysicsFv(this);
        if (twice) UpdateSuspension__17CB3VehiclePhysicsFf(this, 2.0f * p0);
        else UpdateSuspension__17CB3VehiclePhysicsFf(this, p0);
        if ((*(const WAxisType *)&field_B0 < 0.5f && field_1400 <= 0.1f) || field_13F4->field_178C == 0 || field_13F4->field_178C == 2) {
            func_001C44E0_inl2(field_B0);
            field_F0.SetX(0.0f);
            field_F0.SetZ(0.0f);
        }
        if (twice) Update__16CB3CollidingBodyFf(this, 2.0f * p0);
        else Update__16CB3CollidingBodyFf(this, p0);
        n--;
        if (twice) {
            n--;
            if (n == 1) twice = false;
        }
    }
    if (!(field_152C < -0.0001f)) {
        field_152C = 0.0f + field_152C - p0 * (float)p1;
    }
    for (int j = 0; j < field_CC0->field_40->field_C; j++) {
        if (field_CC4->field_4B2[j] == 2) {
            func_001C8290(this, j);
            UpdateHingedPart__17CB3VehiclePhysicsFif(this, j, p0);
        }
    }
    field_13F4->UpdateAggressiveReaction();
    field_CC0->field_54 = field_B0.W();
    field_CC4->field_1028 = field_14C8;
    field_CC4->field_102C = (int)(9.549296379f * field_149C);
    field_CC4->field_1030 = field_1168;
    field_CC4->field_1032 = (unsigned int)(field_1524 - 1) < 2;
    field_CC4->field_1031 = field_1444;
    field_CC4->field_1033 = field_1446;
    UpdateWheelStates__17CB3RaceCarPhysicsFv(this);
}
