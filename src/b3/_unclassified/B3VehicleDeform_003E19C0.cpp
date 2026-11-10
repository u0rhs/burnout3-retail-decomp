// CB3VehicleDeform::UpdateFlyingBitsBones(float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3VehicleDeform has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (fresh7: goto-form block order + scoped opt_repositioncode off [G] (asm in the loop's if pushed its body out of line); compiler-chosen vsub stand-in [L] N185 for retail's vf3/vf2 numbering; q = p1*t before each call).

// CB3VehicleDeform::UpdateFlyingBitsBones(float,float) -- hand-written (fresh7).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

struct UnkStruct_D_01E78510 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E78510 D_01E78510;

struct UnkStruct_003E19C0_el { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_003E19C0_40 {
    unsigned char pad_0[0xD];
    signed char field_D;
    unsigned char pad_E[0xB72];
    UnkStruct_003E19C0_el field_B80[1];
};
struct UnkStruct_003E19C0_10 {
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    UnkStruct_003E19C0_40 *field_40;
};
struct UnkStruct_003E19C0_14 {
    unsigned char pad_0[0x4B2];
    signed char field_4B2[1];
    unsigned char pad_4B3[0xAC5];
    float field_F78[6];
    float field_F90[12];
    float field_FC0[1];
};
struct UnkStruct_003E19C0_18 {
    unsigned char pad_0[0xC];
    signed char field_C;
    unsigned char pad_D[0xAB7];
    int field_AC4[1];
};
struct UnkStruct_003E19C0_out { u_long128 q[2]; };

class CB3VehicleDeform {
public:
    void UpdateFlyingBitsBones(float p0, float p1);

    CGtRandom field_0;
    unsigned char pad_8[0x8];
    UnkStruct_003E19C0_10 *field_10;
    UnkStruct_003E19C0_14 *field_14;
    UnkStruct_003E19C0_18 *field_18;
    unsigned char pad_1C[0x15C];
    float field_178;
    unsigned char pad_17C[0x8];
    signed char field_184;
    signed char field_185;
};

extern "C" void DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(void *, int, int, int, int, float);
extern "C" void DeformBonnet__16CB3VehicleDeformFffb(void *, float, float, bool);
extern "C" float DeformDoor__16CB3VehicleDeformF17EVehicleFlyingBitff(void *, int, float, float);
extern "C" void DeformFrontBumper__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(void *, void *, float);
extern "C" void DeformRearBumper__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(void *, void *, float);
extern "C" void DeformBoot__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(void *, void *, float);
extern "C" void DeformSpoiler__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(void *, void *, float);
extern "C" void func_003E6C20(void *self, int, void *out);


// [L] N185: stands in for a CGtV3d subtract on compiler-chosen VU registers (retail `vsub.xyz $vf1, $vf3, $vf1`)
static inline CGtV3d func_003E19C0_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
static inline CGtV3d func_003E19C0_inl2(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData));
    return CGtV3d(r);
}

// N182: `#pragma opt_repositioncode off` ([G] scoped to this function): retail keeps the goto-form block order below
// (the 0/1 and 4/5 bit blocks after the main path, the front-bumper call after its block) and the loop body inline.
#pragma push
#pragma opt_repositioncode off
// 0x003E19C0
void CB3VehicleDeform::UpdateFlyingBitsBones(float p0, float p1)
{
    UnkStruct_003E19C0_out a;
    UnkStruct_003E19C0_out b;
    float t;
    float q;
    int idx;
    UnkStruct_003E19C0_18 *bits;
    func_003E6C20(this, field_184, &a);
    func_003E6C20(this, field_185, &b);
    if ((unsigned int)field_184 <= 1)
        goto front;
    if ((unsigned int)field_185 <= 1) {
        t = 1.0f - field_178;
        q = p1 * t;
        DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(this, 2, field_185, 0, 1, p0 * t);
        if (q > 0.0f)
            DeformFrontBumper__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, &field_10->field_30, q);
        DeformBonnet__16CB3VehicleDeformFffb(this, p0 * (1.0f - field_178), p1 * (1.0f - field_178), true);
    }
bones:
    for (int i = 0; i < field_10->field_40->field_D; i++) {
        float *pf = &field_14->field_F78[i];
        if (*pf < 1.0f) {
            if (func_003E19C0_inl2(((UnkStruct_003E19C0_el *)field_14)[i].field_30, field_10->field_40->field_B80[i].field_30).GetLength() > 0.5f)
                *pf = 1.0f;
        }
    }
    if ((unsigned int)(field_184 - 4) <= 1)
        goto rear;
    if ((unsigned int)(field_185 - 4) <= 1) {
        t = 1.0f - field_178;
        q = p1 * t;
        DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(this, 6, field_185, 4, 5, p0 * t);
        if (q > 0.0f)
            DeformSpoiler__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, &field_10->field_30, q);
        t = 1.0f - field_178;
        q = p1 * t;
        DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(this, 5, field_185, 4, 5, p0 * t);
        if (q > 0.0f)
            DeformBoot__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, &field_10->field_30, q);
        t = 1.0f - field_178;
        DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(this, 3, field_185, 4, 5, p0 * t);
        if (p1 * t > 0.0f)
            DeformRearBumper__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, &field_10->field_30, p0 * t);
    }
doors:
    if (field_184 == 2)
        goto door0;
    if (field_184 != 3)
        return;
    DeformDoor__16CB3VehicleDeformF17EVehicleFlyingBitff(this, 1, p0 * field_178, p1 * field_178);
done:
    return;
front:
    t = field_178;
    q = p1 * t;
    DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(this, 2, field_184, 0, 1, p0 * t);
    if (q > 0.0f)
        goto frontcall;
find:
    bits = field_18;
    for (idx = 0; idx < bits->field_C; idx++) {
        if (bits->field_AC4[idx] == 4)
            goto found;
    }
    idx = -1;
found:
    if ((unsigned int)field_14->field_4B2[idx] < 2) {
        DeformBonnet__16CB3VehicleDeformFffb(this, p0 * field_178, p1 * field_178, true);
        if (2.3283064e-10f * field_0.Random() < 0.1f)
            field_14->field_F90[idx] = 1.0f + field_14->field_FC0[idx];
    }
    goto bones;
frontcall:
    DeformFrontBumper__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, &field_10->field_30, q);
    goto find;
rear:
    t = field_178;
    q = p1 * t;
    DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(this, 6, field_184, 4, 5, p0 * t);
    if (q > 0.0f)
        DeformSpoiler__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, &field_10->field_30, q);
    t = field_178;
    q = p1 * t;
    DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(this, 5, field_184, 4, 5, p0 * t);
    if (q > 0.0f)
        DeformBoot__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, &field_10->field_30, q);
    t = field_178;
    DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(this, 3, field_184, 4, 5, p0 * t);
    if (p1 * t > 0.0f)
        DeformRearBumper__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, &field_10->field_30, p0 * t);
    goto doors;
door0:
    DeformDoor__16CB3VehicleDeformF17EVehicleFlyingBitff(this, 0, p0 * field_178, p1 * field_178);
    goto done;
}
#pragma pop
