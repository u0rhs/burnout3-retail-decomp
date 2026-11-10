// NONMATCHING: func_00427D00 -- retail 1973 / ours 1969 instructions, 2304 in changed runs
// draftF: 1973/1969; calls identical, switch/block layout identical (per-case sizes within 4-16 bytes, case 1 equal), adda/madd and lane-op counts match; residue inside header inlines: CreateRotationMatrix3x4/SinCosFast scheduling and constant registers, Interpolate result folded to sqc2 (retail qmfc2+sq), CGtMatrix3x4 op* hard registers (retail vf1/vf5/vf4 basis), SetFromMatrix lqc2 row reads, matrix copy slots (frame 0x24D0 vs 0x3F80, N254/N255/N263), one extra saved GPR
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every branch, call, store and VU op of the five shots and the tail accounted for (calls and per-case op counts compared)

// func_00427D00 -- hand-written (draftF) from the retail asm and the Ghidra draft. [L] a CB3CarViewComponent method (its only caller,
// func_00427A30, is the car-view Update(float): it calls UpdateLoadState / UpdateMaskCarChangeState, new_names.csv) run while
// field_D4 is set; func_00429BE0 (archived sibling) is the other branch. Placeholder name, types [G].
// Shape [C asm]: a scripted five-shot car-view camera. field_D8 = shot, field_DC = time in the shot. Each shot builds the local
// matrix m (identity first): shots 0/3 a fixed rotation about D_004D1590 with the position lerped between two points, shots 1/2 two
// rotations (about m.mUp, then about the new m.mRight) composed, position lerped, shot 4 an orbit like func_00429BE0 (angle -20/s,
// height from the car box, look-at onto field_60). Then m goes into the camera's CGtQuatPos (field_30), the camera's vfunc_18 runs,
// FOV 45, viewport 1 updated, field_DC += dt.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

struct UnkStruct_00427D00_vt { unsigned char pad_0[0x18]; void (*vfunc_18)(void *, float); };
struct UnkStruct_00427D00 {
    unsigned char pad_0[0xC];
    unsigned char field_C;
    unsigned char pad_D[0x13];
    UnkStruct_00427D00_vt * field_20;     // camera object at +0x20 (vptr first) [G]
    float field_24;                        // FOV [G]
    unsigned char pad_28[0x8];
    CGtQuatPos field_30;
    unsigned char pad_50[0x10];
    CGtV3d field_60;
    float field_70;
    float field_74;
    float field_78;                        // orbit angle, degrees [G]
    float field_7C;
    unsigned char pad_80[0x1E];
    signed char field_9E;                  // vehicle index
    unsigned char pad_9F[0x39];
    int field_D8;                          // shot [G]
    float field_DC;                        // time in shot [G]
    unsigned char pad_E0[0x4];
    float field_E4;
    float field_E8;
    unsigned char field_EC;
};
// the vehicle object: two CGtV3d at +0xE80/+0xE90 (box corners [G]: their Y difference is the height)
struct UnkStruct_00427D00_car { unsigned char pad_0[0xE80]; CGtV3d field_E80; CGtV3d field_E90; };
struct UnkStruct_00427D00_slot { UnkStruct_00427D00_car * field_0; unsigned char pad_4[0x2460 - 4]; };
extern UnkStruct_00427D00_slot D_00652390[];
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004F509C D_004F509C;
extern CGtV3d D_004D1590;
extern CGtV3d D_004D15C0;
extern CGtV3d D_004D15D0;
extern float D_004E25E4;
extern float D_004E25E8;
extern float D_004E25EC;
extern unsigned char D_00665EC0[];
extern "C" void UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(void *, int);

// [L] the map's operator -(ZAxisType, float) (B3O0PCH, 80 bytes; not in the header): as operator -(YAxisType, float) on lane z.
static inline ZAxisType func_00427D00_inl2(ZAxisType a, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vsubx.z %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return ZAxisType(r);
}
// [L] N185 stand-in: CGtQuat::SetFromMatrix (GtMathPs2Quat.h body) with retail's SetW form in the trace > 0 branch
// (`qmtc2.ni; vmulx.w q, $vf0, sx`, the SetW(XAxisType) shape; header gap queued by draftE).
static inline void func_00427D00_sw(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_00427D00_sfm(CGtQuat &q, const CGtMatrix3x4& m)
{
    float trace = m.mRight.X() + m.mUp.Y() + m.mAt.Z();
    if (trace > 0.0f) {
        float s = GtMath::Sqrt(trace + 1.0f);
        q.mRot.SetX(m.mUp.Z() - m.mAt.Y());
        q.mRot.SetY(m.mAt.X() - m.mRight.Z());
        q.mRot.SetZ(m.mRight.Y() - m.mUp.X());
        q.mRot *= 0.5f / s;
        func_00427D00_sw(q.mRot, 0.5f * s);
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
            q.mRot.SetX(0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mUp.Z() - m.mAt.Y()) * s);
            q.mRot.SetY((m.mRight.Y() + m.mUp.X()) * s);
            q.mRot.SetZ((m.mRight.Z() + m.mAt.X()) * s);
            break;
        }
        case 1: {
            float s = GtMath::Sqrt(m.mUp.Y() - (m.mAt.Z() + m.mRight.X()) + 1.0f);
            q.mRot.SetY(0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mAt.X() - m.mRight.Z()) * s);
            q.mRot.SetZ((m.mUp.Z() + m.mAt.Y()) * s);
            q.mRot.SetX((m.mUp.X() + m.mRight.Y()) * s);
            break;
        }
        case 2: {
            float s = GtMath::Sqrt(m.mAt.Z() - (m.mRight.X() + m.mUp.Y()) + 1.0f);
            q.mRot.SetZ(0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mRight.Y() - m.mUp.X()) * s);
            q.mRot.SetX((m.mAt.X() + m.mRight.Z()) * s);
            q.mRot.SetY((m.mAt.Y() + m.mUp.Z()) * s);
            break;
        }
        }
    }
}
// [G] the "start" latch the three timed shots share (retail tests field_EC again inside: an inlined helper)
static inline void func_00427D00_inl1(UnkStruct_00427D00 * self)
{
    if (!self->field_EC) {
        self->field_EC = 1;
        self->field_E4 = 0.0f;
        self->field_E8 = 0.5f;
    }
}

// 0x00427D00
extern "C" void func_00427D00(UnkStruct_00427D00 * self, float dt)
{
    CGtMatrix3x4 m;
    m.SetIdentity();
    switch (self->field_D8) {
    case 0: {
        float t = self->field_DC / 3.0f;
        m = CreateRotationMatrix3x4(D_004D1590, 0.017453292f * D_004E25E4);
        m.mPos = Interpolate(D_004D15C0, D_004D15D0, t);
        if (!self->field_EC && t > 1.0f && self->field_9E != -1) {
            func_00427D00_inl1(self);
            self->field_C = 1;
        }
        if (self->field_EC && !(self->field_E4 < 0.06665f)) {
            self->field_DC = 0.0f;
            self->field_D8 = 1;
        }
        break;
    }
    case 1: {
        float t = self->field_DC / 2.0f;
        UnkStruct_00427D00_car * car = D_00652390[self->field_9E].field_0;
        float y = car->field_E80.Y() - car->field_E90.Y();
        float h = GtMath::Min(1.5f * y, 2.5f);
        float z = car->field_E80.Z() + h;
        float yy = y * 0.3f;
        float ang = D_004E25E8;
        ang += t * (D_004E25EC - D_004E25E8);
        m = CreateRotationMatrix3x4(m.mUp, 0.017453292f * ang);
        m = m * CreateRotationMatrix3x4(m.mRight, -0.08726646f);
        CGtV3d a, b;
        a.SetX(car->field_E80.X());
        a.SetY(yy);
        a.SetZ(z);
        b.SetX(-car->field_E80.X() * 2.0f);
        b.SetY(yy);
        b.SetZ(z - 0.5f);
        m.mPos = Interpolate(a, b, t);
        if (!self->field_EC && self->field_DC + 0.06665f >= 2.0f)
            func_00427D00_inl1(self);
        if (t >= 1.0f) {
            self->field_D8 = 2;
            self->field_DC = 0.0f;
        }
        break;
    }
    case 2: {
        float t = self->field_DC / 2.0f;
        UnkStruct_00427D00_car * car = D_00652390[self->field_9E].field_0;
        float y = car->field_E80.Y() - car->field_E90.Y();
        float h = GtMath::Min(1.5f * y, 2.5f);
        float yy = y * 0.9f;
        float z = func_00427D00_inl2(car->field_E90.Z(), h);
        m = CreateRotationMatrix3x4(m.mUp, 0.2617994f);
        m = m * CreateRotationMatrix3x4(m.mRight, 0.17453292f);
        CGtV3d a, b;
        a.SetX(-car->field_E90.X() * 2.0f);
        a.SetY(yy);
        a.SetZ(z);
        b.SetX(car->field_E90.X());
        b.SetY(yy);
        b.SetZ(z);
        m.mPos = Interpolate(a, b, t);
        if (!self->field_EC && self->field_DC + 0.06665f >= 2.0f)
            func_00427D00_inl1(self);
        if (t >= 1.0f) {
            self->field_D8 = 3;
            self->field_DC = 0.0f;
        }
        break;
    }
    case 3: {
        float t = self->field_DC / 2.0f;
        UnkStruct_00427D00_car * car = D_00652390[self->field_9E].field_0;
        float y = car->field_E80.Y() - car->field_E90.Y();
        float h = GtMath::Min(2.5f * y, 6.5f);
        float x = car->field_E80.X() + h;
        float yy = y * 0.6f;
        m = CreateRotationMatrix3x4(D_004D1590, 4.712389f);
        CGtV3d a, b;
        a.SetX(x);
        a.SetY(yy);
        a.SetZ(car->field_E80.Z() + car->field_E80.X());
        b.SetX(x);
        b.SetY(yy);
        b.SetZ(0.0f);
        m.mPos = Interpolate(a, b, t);
        if (!self->field_EC && self->field_DC + 0.06665f >= 2.0f)
            func_00427D00_inl1(self);
        if (t >= 1.0f) {
            self->field_D8 = 4;
            self->field_DC = 0.0f;
        }
        break;
    }
    case 4: {
        UnkStruct_00427D00_car * car = D_00652390[self->field_9E].field_0;
        self->field_78 += -20.0f * dt;
        if (self->field_78 > 360.0f)
            self->field_78 -= 360.0f;
        float s = sinf(0.017453292f * (self->field_78 + 225.0f));
        float h = (car->field_E80.Y() - car->field_E90.Y()) * (0.75f + 0.4f * s);
        m = CreateRotationMatrix3x4(D_004D1590, 0.017453292f * self->field_78);
        m.mPos = m.mAt * -self->field_74;
        m.mPos.SetY(h);
        CGtV3d at = self->field_60 - m.mPos;
        at.Normalise();
        CGtMatrix3x4 l = Matrix3x4SetLookAt(at, D_004D1590);
        l.mPos = m.mPos;
        m = l;
        break;
    }
    }
    func_00427D00_sfm(self->field_30.mQuat, m);
    self->field_30.mPos = m.mPos;
    self->field_20->vfunc_18(&self->field_20, D_004F509C.field_0);
    self->field_24 = 45.0f;
    UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(D_00665EC0, 1);
    self->field_DC += dt;
}
