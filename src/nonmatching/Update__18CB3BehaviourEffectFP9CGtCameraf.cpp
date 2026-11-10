// NONMATCHING: Update__18CB3BehaviourEffectFP9CGtCameraf -- retail 1699 / ours 1710 instructions, 1552 in changed runs
// draftAE C-first: 1710/1699, calls identical as a multiset (22 sinf, 11 powf, CGtV4d F1 ctor, DeactivateBehaviour); op counts agree except matrix copies (lq/sq/addiu: retail's extra product copy levels, operator*= gap) and SetFromMatrix SetW (vsubw.w+vaddx.w vs vmulx.w, queued). Left: frame 0x14A0 vs 0x2220 (N255/N282 dead lane slots), the wave inline's powf / second-sinf blocks inline where retail moves them out of line (layout)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (cfgmap) with Revenge STABS as a guide; every branch, call, store and constant accounted for (11 wave sites mapped to their registers, 3 rotations about At/Up/Right, pos, FOV, camera product, SetFromMatrix); header APIs SetIdentity/CreateRotationMatrix3x4/operator*/ConvertToMatrix/SetFromMatrix

// Update__18CB3BehaviourEffectFP9CGtCameraf -- draftAE (0x32D200, 0x1A8C) -- CB3BehaviourEffect::Update(CGtCamera*, float)
// Written from the retail asm (cfgmap) with the Revenge STABS of CB4BehaviourEffect::Update as a guide (B4BehaviourEffect.cpp:
// locals lMatrix / lRotateMatrix / lCameraMatrix, lrAxisX/Y/Z, lrPosX/Y/Z, lrFOV) [L].
// [L] a camera-shake effect: the effect clock field_C advances (by the time step, or by frames * frame time), the effect ends
// (DeactivateBehaviour(15)) once the clock passes field_10 (except type 2), then per effect type a set of damped sine waves
// (tables D_004A4A60.. / D_01EA31E0..: start, duration, amplitude, frequency, second frequency, decay power) gives up to three
// rotations, a position offset and an FOV offset, scaled by field_14; the offset matrix (rotate about the current At, Up,
// Right rows) is applied in front of the camera's own matrix and written back into the camera's CGtQuatPos.
// Types and field meanings [G] (instruction widths, use).
#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;
#pragma inline_depth(8)

class CGtCamera;
class CB3PlayerCameraManager;

struct UnkStruct_0032D200_cam {
    unsigned char pad_0[0x4];
    float field_4;              // [G] field of view, degrees
    unsigned char pad_8[0x8];
    CGtQuatPos field_10;        // [L] the camera's orientation + position (0x10 quat, 0x20 pos)
};

// [G] one damped sine wave: 0 before field_0; amplitude field_8, decaying as (1 - (t - field_0) / field_4) ^ field_14 when
// field_4 > 0; sin(pi * field_C * t), times sin(pi * field_10 * t) when field_10 != 0. 0x20 bytes apart in both tables.
struct UnkStruct_0032D200_wave {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    unsigned char pad_18[0x8];
};
// [C] addresses (retail's %lo relocations; .data values 0x4A4A60..: e.g. {0, 0.5, 7, 6, 17, 1}); the 0x01EA31E0 three are .bss [G]
extern UnkStruct_0032D200_wave D_004A4A60;
extern UnkStruct_0032D200_wave D_004A4A80;
extern UnkStruct_0032D200_wave D_004A4AA0;
extern UnkStruct_0032D200_wave D_004A4AC0;
extern UnkStruct_0032D200_wave D_004A4AE0;
extern UnkStruct_0032D200_wave D_004A4B00;
extern UnkStruct_0032D200_wave D_004A4B20;
extern UnkStruct_0032D200_wave D_004A4B40;
extern UnkStruct_0032D200_wave D_01EA31E0;
extern UnkStruct_0032D200_wave D_01EA3200;
extern UnkStruct_0032D200_wave D_01EA3220;
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };   // [G] frame time
struct UnkStruct_D_0051BAC4 { int field_0; unsigned char pad_4[0xC]; };     // [G] frames elapsed
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_0051BAC4 D_0051BAC4;

extern "C" float sinf(float);
extern "C" float func_0011E388(float, float);   // [L] libm powf (E_dnat_symbols: LIBM.A wf_pow.o powf at 0x11E388)
extern "C" void DeactivateBehaviour__22CB3PlayerCameraManagerFi(CB3PlayerCameraManager *, int);

class CB3BehaviourEffect {
public:
    void Update(CGtCamera * cam, float dt);

    unsigned char pad_0[0x8];
    CB3PlayerCameraManager * field_8;
    float field_C;              // [G] effect clock
    float field_10;             // [G] end time (func_0032EC90 sets it from the type's wave duration; -1 for type 2)
    float field_14;             // [G] intensity
    int field_18;               // [G] effect type 0..3
    int field_1C;               // [G] clock mode: 0 time step, 1 frames * frame time
};

// [G] the damped sine wave (inlined at all 11 sites; the clock re-read from the object at each)
static inline float func_0032D200_inl1(const UnkStruct_0032D200_wave * w, float t)
{
    float r;
    if (t < w->field_0) {
        r = 0.0f;
    } else {
        float a;
        a = w->field_8;
        if (w->field_4 > 0.0f) {
            a = w->field_8 * func_0011E388(1.0f - (t - w->field_0) / w->field_4, w->field_14);
        }
        r = a * sinf(3.1415927f * (w->field_C * t));
        if (w->field_10 != 0.0f) {
            r *= sinf(3.1415927f * (w->field_10 * t));
        }
    }
    return r;
}

void CB3BehaviourEffect::Update(CGtCamera * cam, float dt)
{
    UnkStruct_0032D200_cam * lpCamera = (UnkStruct_0032D200_cam *)cam;
    float lrAxisX = 0.0f;
    float lrAxisY = 0.0f;
    float lrAxisZ = 0.0f;
    float lrPosX = 0.0f;
    float lrPosY = 0.0f;
    float lrPosZ = 0.0f;
    float lrFOV = 0.0f;

    if (field_1C == 0) {
        field_C += dt;
    } else if (field_1C == 1) {
        float s = D_004F509C.field_0;
        s *= (float)D_0051BAC4.field_0;
        field_C += s;
    }
    if (field_18 != 2 && !(field_C < field_10)) {
        DeactivateBehaviour__22CB3PlayerCameraManagerFi(field_8, 15);
        return;
    }

    switch (field_18) {
    case 0:
        lrAxisX = func_0032D200_inl1(&D_004A4A60, field_C);
        lrAxisZ = func_0032D200_inl1(&D_004A4A80, field_C);
        lrPosX = func_0032D200_inl1(&D_01EA31E0, field_C);
        lrPosY = func_0032D200_inl1(&D_01EA3200, field_C);
        lrFOV = func_0032D200_inl1(&D_01EA3220, field_C);
        break;
    case 1:
        lrFOV = func_0032D200_inl1(&D_004A4AA0, field_C);
        break;
    case 2:
        lrAxisX = func_0032D200_inl1(&D_004A4AC0, field_C);
        lrPosX = func_0032D200_inl1(&D_004A4AE0, field_C);
        lrPosZ = func_0032D200_inl1(&D_004A4B00, field_C);
        break;
    case 3:
        lrAxisZ = func_0032D200_inl1(&D_004A4B40, field_C);
        lrPosZ = func_0032D200_inl1(&D_004A4B20, field_C);
        break;
    }

    CGtMatrix3x4 lMatrix;
    lMatrix.SetIdentity();
    float lrScale = field_14;
    lrAxisZ *= lrScale;
    lrAxisX *= lrScale;
    lrAxisY *= lrScale;
    lrPosX *= lrScale;
    lrPosY *= lrScale;
    lrPosZ *= lrScale;
    lrFOV *= lrScale;

    if (lrAxisZ != 0.0f) {
        lMatrix = lMatrix * CreateRotationMatrix3x4(lMatrix.mAt, 0.017453292f * lrAxisZ);
    }
    if (lrAxisY != 0.0f) {
        lMatrix = lMatrix * CreateRotationMatrix3x4(lMatrix.mUp, 0.017453292f * lrAxisY);
    }
    if (lrAxisX != 0.0f) {
        lMatrix = lMatrix * CreateRotationMatrix3x4(lMatrix.mRight, 0.017453292f * lrAxisX);
    }
    lMatrix.mPos.SetX(lrPosX);
    lMatrix.mPos.SetY(lrPosY);
    lMatrix.mPos.SetZ(lrPosZ);

    CGtMatrix3x4 lCameraMatrix;
    lCameraMatrix = lpCamera->field_10.ConvertToMatrix();
    lMatrix = lMatrix * lCameraMatrix;
    lpCamera->field_4 += lrFOV;
    lpCamera->field_10.SetFromMatrix(lMatrix);
}
