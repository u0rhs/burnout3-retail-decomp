// NONMATCHING: GetMatrix__17CB3CameraKeyFrameFv -- retail 320 / ours 326 instructions, 202 in changed runs
// draftAI: logic complete; retail 320 / ours 326; calls identical (cosf, sinf); header UncompressRotation (QX_SETA, QX_ZB) + CGtQuat::ConvertToMatrix + CGtV3d::Set(float x3); every VU op count identical except the z sign flip (header ZAxisType::operator- = vmulx.z by -1.0, retail vsub.z: queued); left: UncompressRotation's eps test polarity (retail c.le.s/bc1t to the zero branch, header if (r > 0.001f): queued), matrix copy temporaries (addiu +5, lq/sq -1), frame 0x820 vs 0x580
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] the two header bodies were themselves decoded from this function (GtMathPs2Quat.h); position from field_4..C exactly as retail's tail (0x446E94..0x446EEC)

// CB3CameraKeyFrame::GetMatrix() -- draftAI (C-first draft, 0x446A90).
// [C] name: retail symbol table; E map B3O0PCH lists CB3CameraKeyFrame::GetMatrix() (0xB0 bytes at -O0). [L] body: the
// keyframe's packed rotation (field_10) through GtMathPs2::UncompressRotation and CGtQuat::ConvertToMatrix (both header
// bodies were decoded from this function: GtMathPs2Quat.h), the position from field_4..field_C.
// The class is declared here with the fields this body reads (include/b3/classes/CB3CameraKeyFrame.h lacks GetMatrix and
// the fields below +0x14: queued).
// [L] UncompressRotation as retail inlines it here: the SetA(float) w store and the z <= 0 test first (the header's own
// variant switches, GtMathPs2Quat.h)
#define QX_SETA
#define QX_ZB
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CB3CameraKeyFrame {
public:
    CGtMatrix3x4 GetMatrix();
    unsigned char pad_0[0x4];
    float field_4;                 // [C] position x (func_00446A40 builds the CGtV3d from these three)
    float field_8;                 // [C] position y
    float field_C;                 // [C] position z
    unsigned int field_10;         // [C] packed rotation (UncompressRotation's bit layout)
    int field_14;                  // [C] flags (GetTypeBehaviour .. GetIsSetup)
    unsigned char field_18;        // [C] GetRaceCarIndex
    unsigned char field_19;        // [C] GetFOV (x 120 / 255)
};

// 0x00446A90
CGtMatrix3x4 CB3CameraKeyFrame::GetMatrix()
{
    CGtQuat lQuat = UncompressRotation(field_10);
    CGtMatrix3x4 lMatrix;
    lMatrix = lQuat.ConvertToMatrix();
    lMatrix.mPos.Set(field_4, field_8, field_C);
    return lMatrix;
}

