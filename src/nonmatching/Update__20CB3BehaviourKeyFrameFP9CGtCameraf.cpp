// NONMATCHING: Update__20CB3BehaviourKeyFrameFP9CGtCameraf -- retail 288 / ours 296 instructions, 172 in changed runs
// draftAN fork C C-first: key-frame camera update (sibling of Prepare__20CB3BehaviourKeyFrame's archive, header operator* / SetFromMatrix): type 0 returns, 1 = key frame matrix + car position, 2 = key frame * car matrix, then FOV into the camera +4 and the view transform; other types read the matrix unset (retail, kept); 296/288, calls identical, non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: the switch (beq 2, beq 1, beqz 0 -> return, else fall to GetFOV), GetMatrix's hidden result, the vadd.xyz position add, the 3x4 product with the car rows, the FOV store and SetFromMatrix branches traced

// Update__20CB3BehaviourKeyFrameFP9CGtCameraf -- draftAN fork C (C-first draft). 0x374920, 0x480. [C] name: the mangled
// symbol in retail's tables. Revenge Update__20CB4BehaviourKeyFrameP9CGtCameraf (0x584, B4BehaviourKeyFrame.cpp; stabs
// lpCamera, lrTimeStep, lCameraMatrix, lpBody, leRaceCarIndex, lOutMatrix, the inlined CGtQuatPos::SetFromMatrix) [L].
// The sibling of Prepare__20CB3BehaviourKeyFrameFPv's archive (same keyframe calls and race-car table), with the header's
// CGtMatrix3x4::operator* and CGtQuatPos::SetFromMatrix in place of that archive's stand-ins. What it does [L]: the key
// frame's race car body; by the key frame's behaviour type: 0 = nothing (returns before the FOV), 1 = the key frame matrix
// moved by the car's position, 2 = the key frame matrix in the car's space (key frame * car matrix); then the camera's FOV
// and view transform. [C] retail reads lCameraMatrix unset for any other type (GetFOV and SetFromMatrix still run): kept.
// lrTimeStep is unused (as retail).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CB3CameraKeyFrame {
public:
    int GetRaceCarIndex();
    int GetTypeBehaviour();
    CGtMatrix3x4 GetMatrix();
    float GetFOV();
};
struct UnkStruct_00374920_car { unsigned char pad_0[0x204]; CGtMatrix3x4 *field_204; };
struct UnkStruct_00374920_slot { UnkStruct_00374920_car *field_0; unsigned char pad_4[0x2C]; };
extern UnkStruct_00374920_slot D_0055EFEC[];
class CGtCamera {                        // [L] Revenge layout: +0x10 mViewTransform
public:
    unsigned char pad_0[4];
    float field_4;                       // [G] the FOV slot (GetFOV stored here, as Prepare's archive)
    unsigned char pad_8[8];
    CGtQuatPos field_10;
};
class CB3BehaviourKeyFrame {
public:
    void Update(CGtCamera *lpCamera, float lrTimeStep);
    unsigned char pad_0[8];
    CB3CameraKeyFrame *field_8;
};

// 0x00374920
void CB3BehaviourKeyFrame::Update(CGtCamera *lpCamera, float lrTimeStep)
{
    UnkStruct_00374920_car *lpBody = D_0055EFEC[field_8->GetRaceCarIndex()].field_0;
    CGtMatrix3x4 lCameraMatrix;
    switch (field_8->GetTypeBehaviour()) {
    case 0:
        return;
    case 1:
        lCameraMatrix = field_8->GetMatrix();
        lCameraMatrix.mPos += lpBody->field_204->mPos;
        break;
    case 2:
        lCameraMatrix = field_8->GetMatrix() * *lpBody->field_204;
        break;
    }
    lpCamera->field_4 = field_8->GetFOV();
    lpCamera->field_10.SetFromMatrix(lCameraMatrix);
}
