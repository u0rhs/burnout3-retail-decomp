// NONMATCHING: Prepare__9CGtCameraFv -- retail 239 / ours 247 instructions, 130 in changed runs
// draftAN fork C C-first: CGtCamera::Prepare (Revenge stabs/types.h layout [L]): each behaviour's virtual Prepare(initial variables) while all so far succeeded (&& chain, retail stops calling after a false), failure clears the prepared flag and returns false, else view transform = SetFromMatrix(identity) (header SetIdentity + CGtQuatPos::SetFromMatrix, its four trace branches), flag set, true; 247/239, calls identical, non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: the v1/s2 && chain, vtable slot 0x10 with (lpBehaviour, lpInitialVariables), the trace / largest-diagonal branch senses of the inlined SetFromMatrix, the bool result and flag stores traced

// Prepare__9CGtCameraFv -- draftAN fork C (C-first draft). 0x21B080, 0x3BC. [C] name: the mangled symbol in retail's tables.
// Revenge Prepare__9CGtCamera (0x474, GameShared/GameClasses/Graphical/Camera/GtCamera.cpp; stabs: bool, locals lnIndex,
// lbAreBehavioursPrepared, lTempMatrix, the inlined CGtQuatPos/CGtQuat::SetFromMatrix) [L]; layout from Revenge types.h [L]
// (CGtCamera: mViewTransform 0x10, mpBehaviourDefs 0x34, mnNumberOfBehaviours 0x38, mbIsPrepared 0x3C; CGtCameraBehaviourDef
// {lpBehaviour, lpInitialVariables}; CGtCameraBehaviour's virtual Prepare(void*) = vtable slot 0x10) -- member names kept as
// placeholders here with Revenge's in comments. What it does: every behaviour's Prepare(initial variables) while all so far
// succeeded (retail stops calling after the first false); on failure clears the prepared flag and returns false; else sets the
// view transform from an identity matrix (header SetIdentity + CGtQuatPos::SetFromMatrix), sets the flag, returns true.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CGtCameraBehaviour {               // [L] Revenge: vptr only
public:
    virtual void Construct();
    virtual void Destruct();
    virtual bool Prepare(void *lpInitialVariables);   // [C] retail jalr through vtable +0x10 with (behaviour, initial variables)
};
struct CGtCameraBehaviourDef {
    CGtCameraBehaviour *field_0;         // [L] Revenge lpBehaviour
    void *field_4;                       // [L] Revenge lpInitialVariables
};
class CGtCamera {
public:
    bool Prepare();
    float field_0;                       // [L] Revenge mrFOV
    float field_4;                       // [L] Revenge mrDOF
    unsigned char pad_8[0x8];
    CGtQuatPos field_10;                 // [L] Revenge mViewTransform
    void *field_30;                      // [L] Revenge mpViewport
    CGtCameraBehaviourDef *field_34;     // [L] Revenge mpBehaviourDefs
    int field_38;                        // [L] Revenge mnNumberOfBehaviours
    bool field_3C;                       // [L] Revenge mbIsPrepared
};

// 0x0021B080
bool CGtCamera::Prepare()
{
    bool lbAreBehavioursPrepared = true;
    for (int lnIndex = 0; lnIndex < field_38; lnIndex++)
        lbAreBehavioursPrepared = lbAreBehavioursPrepared && field_34[lnIndex].field_0->Prepare(field_34[lnIndex].field_4);
    if (lbAreBehavioursPrepared) {
        CGtMatrix3x4 lTempMatrix;
        lTempMatrix.SetIdentity();
        field_10.SetFromMatrix(lTempMatrix);
        field_3C = true;
        return true;
    }
    field_3C = false;
    return false;
}
