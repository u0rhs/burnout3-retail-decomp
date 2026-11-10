// NONMATCHING: Update__18CB3BehaviourOffsetFP9CGtCameraf -- retail 745 / ours 759 instructions, 425 in changed runs
// draftI: 745/759, 425 changed; calls, switch layout (case 1 first), VU op counts identical; residue: tail SetFromMatrix reads m rows into GPRs (retail lqc2/sqc2: N273 lane copy register class), GetSquaredLength 1.0 / addiu scheduling, case-1 VU numbering, frame 0xB40 vs 0x1300
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every case, call, store and VU op accounted for (cases 0-3, 5-7; 4 = no-op), SetFromMatrix into the camera's CGtQuatPos

// Update__18CB3BehaviourOffsetFP9CGtCameraf -- draftI (0x2E2730, 0xBA4) -- CB3BehaviourOffset::Update(CGtCamera*, float)
// Written from the retail asm (no Revenge STABS help: Revenge's Update is 7 instructions). Types/fields [G] (instruction widths).
// Shape [C asm]: copy the target matrix (*field_30) into m, switch on the behaviour type (field_2C; 4 = nothing at all) to place
// the camera in that matrix's space, then write m into the camera's CGtQuatPos (SetFromMatrix).
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_002E2730_attr { CGtV3d field_0; CGtV3d field_10; };            // [L] CB3AttribsOffset (Construct: Prepare__19CB3CameraAttribsCar result)
struct UnkStruct_002E2730_body { unsigned char pad_0[0x1D0]; CGtV3d field_1D0; CGtV3d field_1E0; };
struct UnkStruct_002E2730_row { UnkStruct_002E2730_body * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_002E2730_tab { CGtV3d field_0[3]; };                           // 0x30-byte rows indexed by self->field_8
struct UnkStruct_002E2730_cam { unsigned char pad_0[0x4]; float field_4; unsigned char pad_8[0x8]; CGtQuatPos field_10; };
struct UnkStruct_002E2730 {
    unsigned char pad_0[0x8];
    unsigned char field_8;
    unsigned char pad_9[0x3];
    UnkStruct_002E2730_attr * field_C;
    unsigned char pad_10[0x18];
    int field_28;
    int field_2C;
    const CGtMatrix3x4 * field_30;
};
extern UnkStruct_002E2730_row D_0055EFEC[];
extern unsigned char * D_0064D388[];
extern UnkStruct_002E2730_tab D_004C39E0[];
extern UnkStruct_002E2730_tab D_004C37A0[];
extern CGtV3d kAxisY;

extern "C" float func_0030A970(void *);   // [L] DNAT call tree: CB3BoostEffectParams::GetCameraFOVInterpAmount() const

// [L] N185 stand-ins (as the Update__18CB3BehaviourRotate archive): compiler-chosen CGtV4d scalar setters.
static inline void func_002E2730_sx(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E2730_sy(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E2730_sz(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E2730_sw(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
// [L] N185: CGtQuat::SetFromMatrix (GtMathPs2Quat.h body) with compiler-chosen SetX/Y/Z(float) and the vmulx.w SetW(float).
static inline void func_002E2730_sfm(CGtQuat &q, const CGtMatrix3x4& m)
{
    float trace = m.mRight.X() + m.mUp.Y() + m.mAt.Z();
    if (trace > 0.0f) {
        float s = GtMath::Sqrt(trace + 1.0f);
        q.mRot.SetX(m.mUp.Z() - m.mAt.Y());
        q.mRot.SetY(m.mAt.X() - m.mRight.Z());
        float w = 0.5f * s;
        q.mRot.SetZ(m.mRight.Y() - m.mUp.X());
        q.mRot *= 0.5f / s;
        func_002E2730_sw(q.mRot, w);
    } else {
        int i;
        if (m.mUp.Y() > m.mRight.X()) {
            if (m.mAt.Z() > m.mUp.Y()) i = 2; else i = 1;
        } else {
            if (m.mAt.Z() > m.mRight.X()) i = 2; else i = 0;
        }
        switch (i) {
        case 0: {
            float s = GtMath::Sqrt(m.mRight.X() - (m.mUp.Y() + m.mAt.Z()) + 1.0f);
            func_002E2730_sx(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mUp.Z() - m.mAt.Y()) * s);
            q.mRot.SetY((m.mRight.Y() + m.mUp.X()) * s);
            q.mRot.SetZ((m.mRight.Z() + m.mAt.X()) * s);
            break;
        }
        case 1: {
            float s = GtMath::Sqrt(m.mUp.Y() - (m.mAt.Z() + m.mRight.X()) + 1.0f);
            func_002E2730_sy(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mAt.X() - m.mRight.Z()) * s);
            q.mRot.SetZ((m.mUp.Z() + m.mAt.Y()) * s);
            q.mRot.SetX((m.mUp.X() + m.mRight.Y()) * s);
            break;
        }
        case 2: {
            float s = GtMath::Sqrt(m.mAt.Z() - (m.mRight.X() + m.mUp.Y()) + 1.0f);
            func_002E2730_sz(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mRight.Y() - m.mUp.X()) * s);
            q.mRot.SetX((m.mAt.X() + m.mRight.Z()) * s);
            q.mRot.SetY((m.mAt.Y() + m.mUp.Z()) * s);
            break;
        }
        }
    }
}
static inline void func_002E2730_sfmp(CGtQuatPos &qp, const CGtMatrix3x4& m)
{
    func_002E2730_sfm(qp.mQuat, m);
    qp.mPos = m.mPos;
}

// [L] N185 stand-in for TransformPoint(const CGtMatrix3x4&, CGtV3d) on compiler-chosen registers, one asm per ACC step
// (retail cases 2/5/6/7 keep the rows in $vf5/$vf4/$vf3/$vf2 for the second point; single uses put every row in $vf1).
static inline CGtV3d func_002E2730_tp(const CGtMatrix3x4& m, CGtV3d v)
{
    u_long128 g1 = m.mUp.mData;
    u_long128 g2 = m.mAt.mData;
    u_long128 g3 = m.mPos.mData;
    u_long128 r1, r2, r3, t, w;
    asm("vmulax.xyz $ACC, %0, %1x" : : "j"(m.mRight.mData), "j"(v.mData));
    asm("qmtc2.i %1, %0" : "=j"(r1) : "r"(g1));
    asm("vmadday.xyz $ACC, %0, %1y" : : "j"(r1), "j"(v.mData));
    asm("qmtc2.i %1, %0" : "=j"(r2) : "r"(g2));
    asm("vmaddaz.xyz $ACC, %0, %1z" : : "j"(r2), "j"(v.mData));
    asm("qmtc2.i %1, %0" : "=j"(r3) : "r"(g3));
    asm("vmaddw.xyz %1, %2, $vf0w" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "=j"(w) : "j"(r3));
    return CGtV3d(t);
}
// [L] the E map's GtMathPs2::Matrix3x4SetLookAtPoint(const CGtMatrix3x4&, CGtV3d, CGtV3d) (B3O0PCH 0x311BE0, 0xA8, emitted right
// after this function): look from eye towards target, kAxisY up, mPos = eye. [C asm] the caller computes target before eye (case 2:
// M*field_10 then M*field_0 -> right-to-left argument evaluation), case 3's eye is not transformed, so the transforms are the
// caller's; the matrix parameter's role is not settled [G], so it is left out of this stand-in. Three copy levels as retail
// (lReturnMatrix 0x560.. -> r 0xA30.. -> result 0x1140.. -> m 0x12C0, case 2).
// [G] Matrix3x4SetLookAt(at, up) with the normalise of at inside, on the returned matrix's row (as the Rotate archive's form);
// const& up and the row references give retail's materialised-address stores of mAt/mUp (addiu a0,sp,0x580 / a3,sp,0x570) and
// their reloads for the copy (header body: at by value, normalised by the caller).
static inline CGtMatrix3x4 func_002E2730_la(CGtV3d at, const CGtV3d& up)
{
    CGtMatrix3x4 lReturnMatrix;
    CGtV3d& lA = lReturnMatrix.mAt;
    CGtV3d& lU = lReturnMatrix.mUp;
    lA = at;
    func_002EBED0_inl1(lA);
    lReturnMatrix.mRight = CrossProduct(up, lA);
    func_002EBED0_inl1(lReturnMatrix.mRight);
    lU = CrossProduct(lA, lReturnMatrix.mRight);
    return lReturnMatrix;
}
static inline CGtMatrix3x4 func_002E2730_inl1(CGtV3d eye, CGtV3d target)
{
    CGtMatrix3x4 r = func_002E2730_la(target - eye, kAxisY);
    r.mPos = eye;
    return r;
}

// [G] stand-in: operator+(YAxisType, float) with the scalar and the sum on a hard $vf1 (retail 0x2E27A8..0x2E27D4)
static inline void func_002E2730_inl4(CGtV3d &v, float f)
{
    asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.y $vf1, %0, $vf1x" : : "j"(v.mData), "r"(f));
    asm("vaddy.y %0, $vf0, $vf1y" : "+j"(v.mData));
}
// 0x002E2730
extern "C" void Update__18CB3BehaviourOffsetFP9CGtCameraf(UnkStruct_002E2730 * self, UnkStruct_002E2730_cam * cam, float dt)
{
    if (self->field_2C == 4)
        return;
    CGtMatrix3x4 m = *self->field_30;
    switch (self->field_2C) {
    case 1: {
        CGtV3d off = self->field_C->field_0;
        func_002E2730_inl4(off, 0.25f);
        m.mAt = m.mAt * -1.0f;
        m.mRight = m.mRight * -1.0f;
        m.mPos = TransformPoint(*self->field_30, off);
        break;
    }
    case 0:
        m.mPos = TransformPoint(*self->field_30, self->field_C->field_0);
        cam->field_4 = 90.0f + 25.0f * func_0030A970(D_0064D388[self->field_28] + 0x118C);
        break;
    case 2:
        m = func_002E2730_inl1(func_002E2730_tp(*self->field_30, self->field_C->field_0), func_002E2730_tp(*self->field_30, self->field_C->field_10));
        break;
    case 3:
        m = func_002E2730_inl1(m.mPos + self->field_C->field_0, TransformPoint(*self->field_30, self->field_C->field_10));
        break;
    case 5: {
        UnkStruct_002E2730_body * body = D_0055EFEC[self->field_28].field_0;
        CGtV3d p[2] = { body->field_1D0, body->field_1E0 };   // [G] unused: retail keeps the two dead lq/sq copies (only an array kept them)
        m = func_002E2730_inl1(func_002E2730_tp(*self->field_30, D_004C37A0[self->field_8].field_0[0]), func_002E2730_tp(*self->field_30, D_004C39E0[self->field_8].field_0[0]));
        break;
    }
    case 6: {
        UnkStruct_002E2730_body * body = D_0055EFEC[self->field_28].field_0;
        CGtV3d p[2] = { body->field_1D0, body->field_1E0 };   // [G] unused: retail keeps the two dead lq/sq copies (only an array kept them)
        m = func_002E2730_inl1(func_002E2730_tp(*self->field_30, D_004C37A0[self->field_8].field_0[1]), func_002E2730_tp(*self->field_30, D_004C39E0[self->field_8].field_0[1]));
        break;
    }
    case 7: {
        UnkStruct_002E2730_body * body = D_0055EFEC[self->field_28].field_0;
        CGtV3d p[2] = { body->field_1D0, body->field_1E0 };   // [G] unused: retail keeps the two dead lq/sq copies (only an array kept them)
        m = func_002E2730_inl1(func_002E2730_tp(*self->field_30, D_004C37A0[self->field_8].field_0[2]), func_002E2730_tp(*self->field_30, D_004C39E0[self->field_8].field_0[2]));
        break;
    }
    }
    func_002E2730_sfmp(cam->field_10, m);
}
