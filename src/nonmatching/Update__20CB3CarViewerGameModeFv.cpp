// NONMATCHING: Update__20CB3CarViewerGameModeFv -- retail 2017 / ours 2004 instructions, 1183 in changed runs
// fix3 (2026-11-01): deg->rad constant 0.0174533f (0x3C8EFA39) -> 0.017453292f = retail's 0x3C8EFA35 [C] retail D_004E0D60 / D_004E0F74 | Before: draftE: written from the asm; calls identical, branch and FPU op counts equal; left: CreateRotationMatrix3x4 constant hoisting in the loops, extra matrix copy level (frame 0x1300 vs 0x23D0), SetFromMatrix SetW form (vmulx.w vs vsubw.w/vaddx.w)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every call (identical sequence), branch, store and VU op accounted for; GetRight/GetUp and Min/Max(int) local stand-ins


// CB3CarViewerGameMode::Update() -- draftE (2026-10-31), written from the retail asm (0x24DAB0, 0x1F84) and draft6's decode.
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3CarViewerGameMode.cpp. No Revenge
// counterpart (tools/stabs_lookup.py). Field names are placeholders and every type is [G] (instruction widths) unless tagged.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

// [L] func_0012FC30 = CB3ControllerMapping::GetPadControl(EGtPS2DualShockDeviceControl, bool) (research/nahelam_check.csv, rejected
// there, so placeholder); records of 300 bytes at gGame+0x7080+0xD48, indexed by the signed byte at gGame+0x8021.
struct UnkStruct_0024DAB0_pad { unsigned char pad_0[0x12C]; };
extern "C" float func_0012FC30(void *, int, int);
struct UnkStruct_0024DAB0_cm {
    unsigned char pad_0[0xD48];
    UnkStruct_0024DAB0_pad field_D48[1];
    float func_0024DAB0_inl8(int i, int c) { return func_0012FC30(&field_D48[i], c, 0); }   // [G] inlined
};
// [L] D_004EE040 = gGame (config comment: conflict) -- placeholder kept.
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x7080];
    UnkStruct_0024DAB0_cm field_7080;
    unsigned char pad_7DD4[0x8021 - 0x7DD4];
    signed char field_8021;
    float func_0024DAB0_inl9(int c) { return field_7080.func_0024DAB0_inl8(field_8021, c); }   // [G] inlined
};
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" float func_0012FC30(void *, int, int);
extern "C" void func_00131F10(void *, void *);   // [L] CB3Game::RequestNewGameMode(CB3GameMode*) (E map comment, config)
struct UnkStruct_D_0051A6A8 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051A6A8 D_0051A6A8;

struct UnkStruct_0024DAB0_60 { unsigned char pad_0[0xA0]; unsigned char field_A0; };
struct UnkStruct_0024DAB0_ep {             // CB3VehicleEssentialParams::field_40
    unsigned char pad_0[0xC];
    signed char field_C;                   // count, loop 2 (hinged parts?) [G]
    signed char field_D;                   // count, loop 1 (wheels?) [G]
    unsigned char pad_E[0x60 - 0xE];
    UnkStruct_0024DAB0_60 *field_60;
    unsigned char pad_64[0xADC - 0x64];
    unsigned char field_ADC[1];            // axis index per loop-2 element
    unsigned char pad_ADD[0xE80 - 0xADD];
    CGtV3d field_E80;
    CGtV3d field_E90;
    unsigned char pad_EA0[0x16C0 - 0xEA0];
    unsigned char *field_16C0;             // 12-byte records
    unsigned char pad_16C4[4];
    signed char field_16C8;                // record count
};
class CB3VehicleDeform { public: unsigned char pad_0[0x10]; };
struct UnkStruct_0024DAB0_vp {             // CB3VehicleParams (ess + 0x80)
    CGtMatrix3x4 field_0[6];
    CGtMatrix3x4 field_180[6];
    CB3VehicleDeform field_300;
    unsigned char pad_310[0x4E8 - 0x310];
    float field_4E8[6];
    unsigned char pad_500[0xF60 - 0x500];
    float field_F60[6];
    unsigned char pad_F78[0x101B - 0xF78];
    unsigned char field_101B;
    unsigned char field_101C[6];
    unsigned char pad_1022[2];
    unsigned char *field_1024;
};
struct UnkStruct_0024DAB0_ess {            // CB3VehicleEssentialParams
    unsigned char pad_0[0x40];
    UnkStruct_0024DAB0_ep *field_40;
    unsigned char pad_44[0x58 - 0x44];
    unsigned char field_58;                // input bits 2..7
    signed char field_59;
    unsigned char pad_5A[0x80 - 0x5A];
    UnkStruct_0024DAB0_vp field_80;
};
// [C] 0x522660 + 0x12AD28 = 0x64D388: D_0064D388 is a member of D_00522660 ([L] gWorld, config comment, medium).
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD28];
    UnkStruct_0024DAB0_ess *field_12AD28[1];
    // [G] inlined accessor (retail adds the 0x12AD28 offset at run time, so not a direct member access)
    UnkStruct_0024DAB0_ess *&func_0024DAB0_inl7(int i) { return field_12AD28[i]; }
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0052267C D_0052267C;    // frame time [G]
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00665EC0 D_00665EC0;
extern void *D_0064F7E0;                   // CB3VehiclePhysics* [G]
extern long long D_0064ED10;               // [G] 8 bytes: retail passes it in t0 with `ld` (bss object 0x14 bytes)
extern const CGtV3d kCarViewerXAxis;
extern const CGtV3d kCarViewerYAxis;

struct UnkStruct_0024DAB0_cam {            // [G] CGtCamera at this+0x1C0
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual int vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(float);
    float field_4;
    float field_8;
};
extern "C" void Update__16CB3VehicleDeformFv(CB3VehicleDeform *);
// [C] retail call shape (0x24F708, 0x24F878): a0..a3 = deform, D_0064F7E0, ess, vp; t0 = D_0064ED10 (ld); t1..t3 = 12, 2, 3;
// stack: two CGtV3d copies by pointer, then 0; f12 = force. The callee (0x3DB450) reads t0, t1, t3 and sp+0/+8. The E-map
// name has one parameter fewer than retail passes, so this is declared extern "C" with what the call site shows [G types].
extern "C" void Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
    CB3VehicleDeform *, void *, UnkStruct_0024DAB0_ess *, UnkStruct_0024DAB0_vp *, long long, int, int, int, CGtV3d, CGtV3d, int, float);
extern "C" void AttachCameraToViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelectionP9CGtCamera(void *, int, void *);

class CB3VehicleEssentialParams;
class CB3VehicleParams;
class CB3CarViewerGameMode {
public:
    void Update();
    void UpdateHinges(CB3VehicleEssentialParams *, CB3VehicleParams *);
    unsigned char pad_0[0x1C0];
    UnkStruct_0024DAB0_cam field_1C0;
    CGtQuat field_1D0;                     // viewer orientation
    CGtV3d field_1E0;                      // viewer position
    unsigned char pad_1F0[0x10];
    float field_200;                       // pitch, degrees [G]
    float field_204;                       // yaw, degrees [G]
    float field_208;                       // steer, degrees [G]
    float field_20C;                       // camera distance [G]
    bool field_210;
    bool field_211;
    bool field_212;
    bool field_213;
    int field_214;
    int field_218;
    int field_21C;
    float field_220;
    int field_224;
    int field_228;
    bool field_22C;
    bool field_22D;
    unsigned char pad_22E[0x240 - 0x22E];
    CGtV3d field_240[12];
    float field_300[6];
};

// [G] inlined pad read. Retail adds +0xD48 after the gGame+0x7080 base and reaches gGame+0x8021 through a register late in
// the function -> written as inlined member functions on the two objects (func_0024DAB0_inl8/inl9).
static inline float func_0024DAB0_inl1(int c)
{
    return D_004EE040.field_7080.func_0024DAB0_inl8(D_004EE040.field_8021, c);
}
// [G] inlined edge trigger: true once per press, latch cleared inside the dead zone
static inline bool func_0024DAB0_inl2(int c, bool *latch)
{
    if (GtMath::Abs(func_0024DAB0_inl1(c)) < 0.3f) {
        if (latch) *latch = false;
        return false;
    }
    if (latch && *latch) return false;
    if (latch) *latch = true;
    return true;
}
// [G] inlined "pressed" test
static inline bool func_0024DAB0_inl3(int c)
{
    return !(GtMath::Abs(func_0024DAB0_inl1(c)) < 0.3f);
}
// [G] inlined dead-zoned axis in [-1, 1]
static inline float func_0024DAB0_inl4(int c)
{
    float v = func_0024DAB0_inl1(c);
    if (GtMath::Abs(v) < 0.3f) return 0.0f;
    return GtMath::Min(GtMath::Max(v, -1.0f), 1.0f);
}

extern "C" void func_00134660(void *);   // gaps1: [C] reads a0 (+0x1B4 / +0x1B8, 0x13466C); retail passes this (0x24DAE8)
// [C name] GtMathPs2::GetRight(CGtQuat) / GetUp(CGtQuat) (B3O0PCH map, 616 bytes each); not in the headers -> local stand-ins.
// [L] bodies: ConvertToMatrix's mRight / mUp row alone (retail 0x24F59C.. / 0x24F750..: only those six lane products).
static inline CGtV3d func_0024DAB0_right(CGtQuat a)
{
    CGtQuat q;
    q = a * 1.4142135f;
    float xy = q.mRot.X() * q.mRot.Y();
    float xz = q.mRot.X() * q.mRot.Z();
    float yy = q.mRot.Y() * q.mRot.Y();
    float zz = q.mRot.Z() * q.mRot.Z();
    float wy = q.mRot.W() * q.mRot.Y();
    float wz = q.mRot.W() * q.mRot.Z();
    CGtV3d r;
    r.SetX(1.0f - yy - zz);
    r.SetY(xy + wz);
    r.SetZ(xz - wy);
    return r;
}
static inline CGtV3d func_0024DAB0_up(CGtQuat a)
{
    CGtQuat q;
    q = a * 1.4142135f;
    float xx = q.mRot.X() * q.mRot.X();
    float xy = q.mRot.X() * q.mRot.Y();
    float yz = q.mRot.Y() * q.mRot.Z();
    float zz = q.mRot.Z() * q.mRot.Z();
    float wx = q.mRot.W() * q.mRot.X();
    float wz = q.mRot.W() * q.mRot.Z();
    CGtV3d r;
    r.SetX(xy - wz);
    r.SetY(1.0f - xx - zz);
    r.SetZ(yz + wx);
    return r;
}
// [C name] GtMath::Min(int,int) / Max(int,int) (B3O0PCH 0x14F5C0 / 0x14F5D0, 0x10 each); not in b3/GtMath.h yet -> local stand-ins [G body]
static inline int func_0024DAB0_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); asm("pextlw %0, $0, %0" : "+r"(r)); return r; }
static inline int func_0024DAB0_max(int a, int b) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); asm("pextlw %0, $0, %0" : "+r"(r)); return r; }

// 0x0024DAB0
void CB3CarViewerGameMode::Update()
{
    func_00134660(this);
    UnkStruct_0024DAB0_ess *ess = D_00522660.func_0024DAB0_inl7(0);
    UnkStruct_0024DAB0_vp *vp = &ess->field_80;
    if (ess->field_40->field_16C0) vp->field_1024 = ess->field_40->field_16C0 + field_218 * 12;
    UnkStruct_0024DAB0_ep *ep = ess->field_40;
    if (field_21C) {
        field_20C = (ep->field_E80.Z() - ep->field_E90.Z()) * 1.6f;
        UnkStruct_0024DAB0_cam *cam = &field_1C0;
        if (cam->vfunc_10()) {
            field_1C0.field_4 = 40.0f;
            field_1C0.field_8 = 0.0f;
            AttachCameraToViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelectionP9CGtCamera(&D_00665EC0, 1, &field_1C0);
        }
        field_21C = 0;
    }
    Update__16CB3VehicleDeformFv(&vp->field_300);
    field_204 += 2.5f * func_0024DAB0_inl4(0x18);
    field_200 += 2.5f * func_0024DAB0_inl4(0x19);
    float d = func_0024DAB0_inl1(0x1B);
    float e = field_20C;
    e -= 0.05f * d;
    field_20C = GtMath::Min(GtMath::Max(e, 0.5f), 200.0f);
    float bv = func_0024DAB0_inl1(0xB);
    field_208 = (bv - func_0024DAB0_inl1(0xD)) * 10.0f;
    if (func_0024DAB0_inl2(0xE, &field_22C)) field_22D = !field_22D;
    if (func_0024DAB0_inl2(5, &field_210)) {
        CGtV3d r = func_0024DAB0_right(field_1D0);
        CGtV3d pos = r * 3.0f;
        CGtV3d dir = r * -1.5f;
        dir.SetY(-0.5f);
        dir.Normalise();
        Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
            &vp->field_300, D_0064F7E0, ess, vp, D_0064ED10, 12, 2, 3, pos, dir, 0, 30000 * field_220);
        field_210 = true;
        if (field_220 == 1.0f) field_220 = 0.333f;
    }
    if (func_0024DAB0_inl2(0xF, &field_211)) {
        CGtV3d u = func_0024DAB0_up(field_1D0);
        CGtV3d pos = u * 2.0f;
        CGtV3d dir = u * -1.0f;
        Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
            &vp->field_300, D_0064F7E0, ess, vp, D_0064ED10, 12, 2, 3, pos, dir, 0, 10000 * field_220);
        field_211 = true;
        if (field_220 == 1.0f) field_220 = 0.333f;
    }
    if (ess->field_40->field_16C0) {
        float v = func_0024DAB0_inl1(0x1A);
        if (v > 0.5f) {
            if (!field_213) {
                field_218 = func_0024DAB0_min(field_218 + 1, ess->field_40->field_16C8 - 1);
                field_213 = true;
            }
        } else if (func_0024DAB0_inl1(0x1A) < -0.5f) {
            if (!field_213) {
                field_218 = func_0024DAB0_max(field_218 - 1, 0);
                field_213 = true;
            }
        } else {
            field_213 = false;
        }
    }
    UpdateHinges((CB3VehicleEssentialParams *)ess, (CB3VehicleParams *)vp);
#define FLAGS D_00522660.func_0024DAB0_inl7(0)->field_58
    bool b;
    b = func_0024DAB0_inl3(0); if (b) FLAGS |= 0x04; else FLAGS &= ~0x04;
    b = func_0024DAB0_inl3(2); if (b) FLAGS |= 0x08; else FLAGS &= ~0x08;
    b = func_0024DAB0_inl3(1); if (b) FLAGS |= 0x10; else FLAGS &= ~0x10;
    b = func_0024DAB0_inl3(10); if (b) FLAGS |= 0x20; else FLAGS &= ~0x20;
    b = func_0024DAB0_inl3(12); if (b) FLAGS |= 0x40; else FLAGS &= ~0x40;
    b = func_0024DAB0_inl3(3); if (b) FLAGS |= 0x80; else FLAGS &= ~0x80;
#undef FLAGS
    int i;
    for (i = 0; i < ess->field_40->field_D; i++) {
        CGtMatrix3x4 &m = vp->field_0[i];
        float a = (i & 1) ? field_208 : -field_208;
        CGtMatrix3x4 rot = CreateRotationMatrix3x4(m.mRight, 0.017453292f * a);
        CGtV3d pos = m.mPos;
        m = m * rot;
        m.mPos = pos;
        vp->field_4E8[i] = 6.0f * field_208;
    }
    CGtMatrix3x4 rx = CreateRotationMatrix3x4(kCarViewerXAxis, 0.017453292f * field_200);
    CGtMatrix3x4 ry = CreateRotationMatrix3x4(kCarViewerYAxis, 0.017453292f * field_204);
    CGtMatrix3x4 r = rx * ry;
    field_1D0.SetFromMatrix(r);
    field_1E0 = r.mAt * -field_20C;
    UnkStruct_0024DAB0_cam *cam = &field_1C0;
    cam->vfunc_18(D_0052267C.field_0);
    for (i = 0; i < ess->field_40->field_C; i++) {
        CGtMatrix3x4 &m = vp->field_180[i];
        CGtMatrix3x4 rot = CreateRotationMatrix3x4(field_240[ep->field_ADC[i]], 0.017453292f * (field_300[i] - vp->field_F60[i]));
        CGtV3d pos = m.mPos;
        m = m * rot;
        m.mPos = pos;
        field_300[i] = vp->field_F60[i];
    }
    if (func_0024DAB0_inl2(8, &field_212) && ess->field_40->field_60) {
        ess->field_59++;
        ess->field_59 = ess->field_59 % ess->field_40->field_60->field_A0;
    }
    if (func_0024DAB0_inl3(9)) {
        if (field_228 != 2) {
            UnkStruct_0024DAB0_ess *p = D_00522660.func_0024DAB0_inl7(0);
            p->field_80.field_101B = 0;
            for (int j = 0; j < 6; j++) p->field_80.field_101C[j] = 0;
        }
        func_00131F10(&D_004EE040, &D_0051A6A8);
    }
}
