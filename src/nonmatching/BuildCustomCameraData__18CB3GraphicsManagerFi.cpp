// NONMATCHING: BuildCustomCameraData__18CB3GraphicsManagerFi -- retail 2209 / ours 2176 instructions, 1570 in changed runs
// draft6 first full draft 2176/2209, frame 0xC90 vs 0x21C0; calls identical (10), VU arithmetic and FPU op counts equal (vmove 5 vs 1, mov.s 1 vs 0); left: retail keeps one more copy level of every matrix-valued expression (operator* result through an extra temp, 12 sq per B4 face, 4 per B5 face: opt_classresults work), constants reloaded per SinCosFast (lui 61/51), lane-setter lqc2 of uninitialised locals (91/75). Stand-in: Interpolate(CGtV3d) in the CGtV4d noreorder shape (header body folds b's lq+qmtc2)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra as reading aid), every branch, call and store accounted for; layout and rotation chain decoded per face (B4 3 faces, B5 5 faces)

// draft6: CB3GraphicsManager::BuildCustomCameraData(int) (0x223130), written from the retail asm (Ghidra as reading aid).
// [L] builds the env-map cameras: CB3CameraData slot 0 (this+0x470) from the main RwCamera, then a look-at matrix
// (field_430) from the env-map centre (the car's bounding-box middle in world space, or the origin) towards the main
// camera, and the env-map face cameras 1..N, each by func_00225440 from a rotated copy of that matrix. Two layouts:
// 3 faces (a 45-degree tilted frame stepped 120 degrees about kAtAxis, raised camera height) unless D_0051BA88 points
// at D_0051A6A8, else 5 faces (the matrix itself, then +-90 degrees about D_004B9DC0 and D_004B9DD0).
// Revenge (SLUS_212.42) STABS: CB4GraphicsManager::BuildCustomCameraData(ERaceCarIndex) in B4GraphicsManagerPS2.cpp,
// locals lpCamera / lEnvMapCentre / lpEssential / lpSource / lCamMatrix / lRotationMatrix / lMatrix [L]; the other
// local names here are [G]. Field names are placeholders and every type is [G] (instruction widths).
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

// [G] stand-in: GtMathPs2::Interpolate(CGtV3d, CGtV3d, float) in the CGtV4d body's shape (b and the result unfolded)
static inline CGtV3d func_00223130_inl2(CGtV3d a, CGtV3d b, float t)
{
    u_long128 tv, r;
    asm("vaddax.xyz $ACC, %1, $vf0x" "\n\t" "qmtc2.ni %2, %0" "\n\t" "vmsubax.xyz $ACC, %1, %0x" : "=&j"(tv) : "j"(a.GetRawData()), "r"(t));
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vmaddx.xyz $vf1, $vf1, %2x" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r) : "r"(b.GetRawData()), "j"(tv));
    asm(".set reorder");
    return CGtV3d(r);
}

// [L] RW 3.5 sky2 layouts: RwCamera's RwObject parent (the RwFrame) at +4; RwFrame's modelling RwMatrix at +0x10
// (right, up, at, pos rows of x, y, z, pad).
struct UnkStruct_00223130_row { float field_0, field_4, field_8; unsigned int field_C; };
struct UnkStruct_00223130_frame {
    unsigned char pad_0[0x10];
    UnkStruct_00223130_row field_10[4];
};
struct RwCamera {
    unsigned char pad_0[0x4];
    UnkStruct_00223130_frame * field_4;
};
// [L] Revenge lpSource (CB4VehicleData): two corners at +0xE80/+0xE90
struct UnkStruct_00223130_src {
    unsigned char pad_0[0xE80];
    CGtV3d field_E80;
    CGtV3d field_E90;
};
// [L] Revenge lpEssential (CB4VehicleEssentialParams): world matrix at +0, lpSource at +0x40
struct UnkStruct_00223130_ess {
    CGtMatrix3x4 field_0;
    UnkStruct_00223130_src * field_40;
};
struct UnkStruct_00223130_g { RwCamera * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00223130_p { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00223130_q { unsigned char pad_0[0x10]; };

class CB3CameraData {
public:
    void Construct(RwCamera * cam);
    unsigned char pad_0[0x230];     // [L] size: the face slots' stride
};

class CB3GraphicsManager {
public:
    void BuildCustomCameraData(int idx);

    unsigned char pad_0[0x430];
    CGtMatrix3x4 field_430;         // [G] the env-map look-at matrix
    CB3CameraData field_470[6];     // [L] slot 0 main camera, 1..5 env-map faces (func_00225440's a2)
    unsigned char pad_1190[0x24];
    int field_11B4[5];              // [G] log2 face width
    int field_11C8[5];              // [G] log2 face height
};

extern UnkStruct_00223130_g ourGlobals;
extern UnkStruct_00223130_ess * D_0064D388[];
extern UnkStruct_00223130_p D_0051BA88;
extern UnkStruct_00223130_q D_0051A6A8;
extern float krEnvmapRotateAngle;
extern float krEnvmapShift;
extern CGtV3d kAtAxis;
extern CGtV3d D_004B9DC0;           // [G] axis vectors, filled by a static initialiser (zero in the file)
extern CGtV3d D_004B9DD0;
extern "C" float func_0011E388(float, float);   // [L] libm powf (as B3Profile_00139C00)
// [G] low-confidence table name CB3CameraData::ConstructEnvMap; a0 = the face's CB3CameraData, a1 = the face matrix,
// a2 = face 1..5, a3 = 0 / 1 by layout, t0/t1 = 1 << log2 size, t2 = running offset (returned advanced)
extern "C" int func_00225440(CB3CameraData * cam, const CGtMatrix3x4 & m, int face, int a3, int w, int h, int base);

// [L] Revenge: an inlined RwMatrix -> CGtMatrix3x4 conversion (lpMatrix, four lpV3d / lTypes), each row through a union
static inline CGtMatrix3x4 func_00223130_inl1(const UnkStruct_00223130_frame * f)
{
    CGtMatrix3x4 m;
    m.mRight = CGtV3d(f->field_10[0].field_0, f->field_10[0].field_4, f->field_10[0].field_8);
    m.mUp = CGtV3d(f->field_10[1].field_0, f->field_10[1].field_4, f->field_10[1].field_8);
    m.mAt = CGtV3d(f->field_10[2].field_0, f->field_10[2].field_4, f->field_10[2].field_8);
    m.mPos = CGtV3d(f->field_10[3].field_0, f->field_10[3].field_4, f->field_10[3].field_8);
    return m;
}

// 0x00223130
void CB3GraphicsManager::BuildCustomCameraData(int idx)
{
    RwCamera * lpCamera = ourGlobals.field_0;
    CGtMatrix3x4 lRotationMatrix;
    CGtMatrix3x4 lTempMatrix;
    CGtMatrix3x4 lCamMatrix;
    CGtMatrix3x4 lTemp;
    CGtMatrix3x4 lMatrix;
    CGtV3d lEnvMapCentre;
    lEnvMapCentre.Zero();
    if (idx != -1) {
        UnkStruct_00223130_ess * lpEssential = D_0064D388[idx];
        UnkStruct_00223130_src * lpSource = lpEssential->field_40;
        lEnvMapCentre = TransformPoint(lpEssential->field_0, func_00223130_inl2(lpSource->field_E90, lpSource->field_E80, 0.5f));
    }
    field_470[0].Construct(lpCamera);
    if (idx == -1) {
        return;
    }
    int base = 0;
    if ((void *)D_0051BA88.field_0 != (void *)&D_0051A6A8) {
        lCamMatrix = func_00223130_inl1(lpCamera->field_4);
        field_430.mPos = lEnvMapCentre;
        CGtV3d lPos = lCamMatrix.mPos;
        float dy = lPos.Y() - field_430.mPos.Y();
        float t = 3.0f * dy;
        float c = GtMath::Min(GtMath::Max(t, 0.0f), 3.0f);
        float lrAmountToMoveUp = func_0011E388(c * 0.33333334f, 1.0f) * 3.0f;
        lPos.SetY(lPos.Y() + lrAmountToMoveUp);
        field_430.mAt = lPos - field_430.mPos;
        ((float *)&field_430.mAt)[3] = ((const float *)&field_430.mPos)[3]; // [C] 0x223330 lqc2 vf2, 0x460(s4) (mPos);
        // 0x223348 vsub.xyz vf2, vf4, vf2 keeps mPos's w; 0x22334C sqc2 vf2, 0x450(s4) -- `a - b` took lPos's w
        field_430.mAt.Normalise();
        field_430.mRight = CrossProduct(lCamMatrix.mUp, field_430.mAt);
        field_430.mRight.Normalise();
        field_430.mUp = CrossProduct(field_430.mAt, field_430.mRight);
        field_430.mUp.Normalise();

        float lrShift;
        lRotationMatrix = CreateRotationMatrix3x4(D_004B9DC0, 0.017453292f * krEnvmapRotateAngle);
        lTempMatrix = CreateRotationMatrix3x4(lRotationMatrix.mAt, 0.7853982f);
        lTemp = lRotationMatrix * lTempMatrix;
        lMatrix = lTemp * field_430;
        lrShift = krEnvmapShift;
        lMatrix.mPos += lMatrix.mAt * lrShift;
        base = func_00225440(&field_470[1], lMatrix, 1, 0, 1 << field_11B4[0], 1 << field_11C8[0], base);

        lRotationMatrix = CreateRotationMatrix3x4(kAtAxis, 2.0943952f);
        lTemp = lTemp * lRotationMatrix;
        lMatrix = lTemp * field_430;
        lMatrix.mPos += lMatrix.mAt * lrShift;
        base = func_00225440(&field_470[2], lMatrix, 2, 0, 1 << field_11B4[1], 1 << field_11C8[1], base);

        lRotationMatrix = CreateRotationMatrix3x4(kAtAxis, 2.0943952f);
        lTemp = lTemp * lRotationMatrix;
        lMatrix = lTemp * field_430;
        lMatrix.mPos += lMatrix.mAt * lrShift;
        func_00225440(&field_470[3], lMatrix, 3, 0, 1 << field_11B4[2], 1 << field_11C8[2], base);
    } else {
        UnkStruct_00223130_frame * lpFrame = lpCamera->field_4;
        lCamMatrix.mRight = CGtV3d(lpFrame->field_10[0].field_0, lpFrame->field_10[0].field_4, lpFrame->field_10[0].field_8);
        lCamMatrix.mUp = CGtV3d(lpFrame->field_10[1].field_0, lpFrame->field_10[1].field_4, lpFrame->field_10[1].field_8);
        lCamMatrix.mAt = CGtV3d(lpFrame->field_10[2].field_0, lpFrame->field_10[2].field_4, lpFrame->field_10[2].field_8);
        lCamMatrix.mPos = CGtV3d(lpFrame->field_10[3].field_0, lpFrame->field_10[3].field_4, lpFrame->field_10[3].field_8);
        field_430.mPos = lEnvMapCentre;
        field_430.mAt = lCamMatrix.mPos - field_430.mPos;
        field_430.mAt.Normalise();
        field_430.mRight = CrossProduct(lCamMatrix.mUp, field_430.mAt);
        field_430.mRight.Normalise();
        field_430.mUp = CrossProduct(field_430.mAt, field_430.mRight);
        field_430.mUp.Normalise();
        base = func_00225440(&field_470[1], field_430, 1, 1, 1 << field_11B4[0], 1 << field_11C8[0], base);

        lRotationMatrix = CreateRotationMatrix3x4(D_004B9DC0, 1.5707964f);
        lMatrix = lRotationMatrix * field_430;
        base = func_00225440(&field_470[2], lMatrix, 2, 1, 1 << field_11B4[1], 1 << field_11C8[1], base);

        lRotationMatrix = CreateRotationMatrix3x4(D_004B9DC0, -1.5707964f);
        lMatrix = lRotationMatrix * field_430;
        base = func_00225440(&field_470[3], lMatrix, 3, 1, 1 << field_11B4[2], 1 << field_11C8[2], base);

        lRotationMatrix = CreateRotationMatrix3x4(D_004B9DD0, 1.5707964f);
        lMatrix = lRotationMatrix * field_430;
        base = func_00225440(&field_470[4], lMatrix, 4, 1, 1 << field_11B4[3], 1 << field_11C8[3], base);

        lRotationMatrix = CreateRotationMatrix3x4(D_004B9DD0, -1.5707964f);
        lMatrix = lRotationMatrix * field_430;
        func_00225440(&field_470[5], lMatrix, 5, 1, 1 << field_11B4[4], 1 << field_11C8[4], base);
    }
}
