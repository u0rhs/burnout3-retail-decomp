// NONMATCHING: func_003E6C20 -- retail 204 / ours 205 instructions, 46 in changed runs
// psweep: scoped #pragma opt_treetransformation off [G] improves 56 -> 50
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_treetransformation off
using namespace GtMathPs2;

// [L] E-map order (B3O0PCH: GetWindscreenPos, GetFront/BackWindscreenZ, then GetClampBox(EVirtualBoneIndex,
// CGtAxisAlignedBox*)) and the a1 index / a2 box-pointer parameters: CB3VehicleDeform::GetClampBox (name not applied).
struct UnkStruct_003E6C20_bones {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70[7];   // [G] count
};
struct UnkStruct_003E6C20_self {
    unsigned char pad_0[0x18];
    UnkStruct_003E6C20_bones * field_18;
    unsigned char pad_1C[0x38 - 0x1C];
    int field_38;
    unsigned char pad_3C[0x50 - 0x3C];
    CGtV3d field_50;
    CGtV3d field_60;
};
struct UnkStruct_003E6C20_box {
    CGtV3d field_0;   // [G] the max corner
    CGtV3d field_10;  // [G] the min corner
};
extern int kaeVirtualToNormalBone[7];
extern const CGtV3d D_004CACF0;
extern const CGtV3d D_004CAD00;
extern const CGtV3d D_004CAD10;
extern const CGtV3d D_004CAD20;
extern const CGtV3d D_004CAD30;
extern const CGtV3d D_004CAD40;
extern const CGtV3d D_004CADA0;
extern "C" CGtV3d GetWindscreenPos__16CB3VehicleDeformFbb(UnkStruct_003E6C20_self *, int, int);

// [L] N185: GtMathPs2::operator-(XAxisType, XAxisType) stand-in (as func_003E7390)
static inline XAxisType func_003E6C20_subxx(XAxisType a, XAxisType b) { u_long128 r; asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
// [L] N185: GtMathPs2::operator+(XAxisType, XAxisType) stand-in (as func_003E7390)
static inline XAxisType func_003E6C20_addxx(XAxisType a, XAxisType b) { u_long128 r; asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
// [L] N185: GtMathPs2::operator-(ZAxisType, ZAxisType) stand-in
static inline ZAxisType func_003E6C20_subzz(ZAxisType a, ZAxisType b) { u_long128 r; asm("vsubz.z %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return ZAxisType(r); }
// [L] N185: GtMathPs2::operator+(YAxisType, float) stand-in
static inline YAxisType func_003E6C20_addyf(YAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return YAxisType(r); }
// [L] N185: CGtV3d::operator*(CGtV3d) (lane-wise) stand-in
static inline CGtV3d func_003E6C20_mul(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vmul.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }

// [G] inlined helper (placeholder name): the virtual bone's position
static inline CGtV3d func_003E6C20_inl1(UnkStruct_003E6C20_self * self, int idx)
{
    CGtV3d r;
    switch (idx) {
    case 2:
        r = self->field_50;
        break;
    case 3:
        r = self->field_60;
        break;
    default:
        r = self->field_18->field_70[kaeVirtualToNormalBone[idx]].mPos;
        break;
    }
    return r;
}

// 0x003E6C20
extern "C" void func_003E6C20(UnkStruct_003E6C20_self * self, int idx, UnkStruct_003E6C20_box * box)
{
    CGtV3d pos = func_003E6C20_inl1(self, idx);
    CGtV3d scale;
    CGtV3d ext;
    CGtV3d p;
    switch (self->field_38) {
    case 0:
        if (idx == 4 || idx == 5) scale = D_004CAD10;
        else if (idx == 2 || idx == 3) scale = D_004CAD20;
        else if (idx == 6) scale = D_004CAD00;
        else scale = D_004CACF0;
        break;
    case 1:
        if (idx == 6) scale = D_004CAD40;
        else scale = D_004CAD30;
        break;
    case 2:
        if (idx == 4 || idx == 5) scale = D_004CAD10;
        else if (idx == 2 || idx == 3) scale = D_004CAD20;
        else if (idx == 6) scale = D_004CAD00;
        else scale = D_004CACF0;
        break;
    default:
        scale = D_004CADA0;
        break;
    }

    ext = func_003E6C20_mul(pos, scale);
    switch (idx) {
    case 0:
    case 1:
        ext.SetZ((float)GetWindscreenPos__16CB3VehicleDeformFbb(self, 1, 1).Z());
        break;
    case 4:
    case 5:
        ext.SetZ((float)GetWindscreenPos__16CB3VehicleDeformFbb(self, 0, 1).Z());
        ext.SetY(func_003E6C20_addyf(pos.Y(), func_003E6C20_subzz(pos.Z(), ext.Z()) * 0.5f));
        break;
    }
    XAxisType nx = func_003E6C20_addxx(pos.X(), func_003E6C20_subxx(pos.X(), ext.X()) * 1.4f);
    p = pos;
    p.SetX(nx);
    if (idx != 6)
        p.SetY(p.Y() + (p.Y() - ext.Y()) * 0.5f);
    box->field_0 = p;
    box->field_10 = ext;
    CGtV3d mn = Min(ext, box->field_0);
    CGtV3d mx = Max(ext, box->field_0);
    box->field_10 = mn;
    box->field_0 = mx;
}

#pragma pop
