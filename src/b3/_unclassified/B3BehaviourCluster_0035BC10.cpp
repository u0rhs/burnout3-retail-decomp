// CB3ClusterRig::PrepareOffset(EB3RigType,EB3FocusType,CB3ChildBody*,GtMathPs2::CGtV3d,float,float,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourCluster.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (SetIdentity stand-ins, point-first TransformPoint, Y+Y =j add, chosen-reg SetY(YAxisType), N140 pads, extra bool arg).

// CB3ClusterRig::PrepareOffset(EB3RigType,EB3FocusType,CB3ChildBody*,GtMathPs2::CGtV3d,float,float,int) -- hand-matched (v241).
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md).
// extern "C" definition under the mangled name: retail also reads an 8th argument (t2, stored as a byte at +0xD0) that the
// mangled name doesn't list [L]. Field names are placeholders; types [G] from instruction widths.
// Body: store the parameters, CB3CameraUtils::GetRigMatrix into +0x0, SetIdentity on the matrix at +0x40 (CGtMatrix3x4::
// SetIdentity, B3O0PCH map, inlined: V241_* stand-ins), its position = TransformPoint(+0x0, offset), then the position's y
// = target.y + offset.y with the target from func_002F5DC0 (car at D_00522660 + 0x128290 + i*0x1050) or func_002F6040.
// [L] N185 stand-ins: TransformPoint with the point listed first (retail loads it before row 0), YAxisType + YAxisType
// (`vaddy.y`, "=j" result) and CGtV3d::SetY(YAxisType) on compiler-chosen registers (header: hard-coded $vf1/$vf2).
// The three UnkStruct_0035BC10_pad in the SetY inline and one before `v` are N140 frame pads [G] (retail frame 0xA0).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EB3RigType {};
enum EB3FocusType {};
class CB3ChildBody;
struct UnkStruct_0035BC10_3 {
    unsigned char pad_0[0x13F4];
    void * field_13F4;
};
struct UnkStruct_0035BC10_2 {
    unsigned char pad_0[0x40];
    UnkStruct_0035BC10_3 * field_40;
};
struct UnkStruct_0035BC10_self {
    CGtMatrix3x4 field_0;
    CGtMatrix3x4 field_40;
    unsigned char pad_80[0x4];
    UnkStruct_0035BC10_2 * field_84;
    unsigned char pad_88[0x18];
    CGtV3d field_A0;
    unsigned char pad_B0[0x8];
    float field_B8;
    unsigned char pad_BC[0x8];
    int field_C4;
    EB3FocusType field_C8;
    EB3RigType field_CC;
    unsigned char field_D0;
};
struct UnkStruct_0035BC10_e0 {
    unsigned char pad_0[0x1050];
};
struct UnkStruct_D_00522660 {
    UnkStruct_0035BC10_e0 field_0[1];  // [G] element count unknown
};
extern UnkStruct_D_00522660 D_00522660;

extern "C" void GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody(CGtMatrix3x4 * m, void * body);
extern "C" void PrepareFocus__13CB3ClusterRigFf(UnkStruct_0035BC10_self * self, float f);
extern "C" UnkStruct_0035BC10_2 * func_00353960(void * p);
extern "C" CGtV3d func_002F5DC0(void * p, const void * pos);
extern "C" CGtV3d func_002F6040(const void * pos, int i);

#define V241_ZERO(f) { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); f.mData = r; }
#define V241_IDX(f) { u_long128 r = f.mData; asm("vaddw.x %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }
#define V241_IDY(f) { u_long128 r = f.mData; asm("vaddw.y %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }
#define V241_IDZ(f) { u_long128 r = f.mData; asm("vaddw.z %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }
struct UnkStruct_0035BC10_pad { int x[4]; UnkStruct_0035BC10_pad() {} ~UnkStruct_0035BC10_pad() {} };  // [G] N140 frame pad
// [L] N185: TransformPoint with the point listed first (retail loads it before row 0; the header lists row 0 first)
static inline CGtV3d v241_xform(const CGtMatrix3x4& m, CGtV3d v) {
    u_long128 t;
    asm("vmulax.xyz $ACC, %2, %1x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %1y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddaz.xyz $ACC, $vf1, %1z" "\n\t" "qmtc2.i %5, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(v.mData), "j"(m.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData), "r"(m.mPos.mData));
    return CGtV3d(t);
}
// [L] N185 stand-ins: operator+(YAxisType, YAxisType) (as the header's operator-) and SetY(YAxisType) on compiler-chosen registers
static inline YAxisType v241_yadd(YAxisType a, YAxisType b) { u_long128 r; asm("vaddy.y %0, %1, %2y" : "=j"(r) : "j"(b.lVector), "j"(a.lVector)); return YAxisType(r); }
static inline void v241_sety(CGtV3d &v, YAxisType a) { UnkStruct_0035BC10_pad p1, p2, p3; asm("vaddy.y %0, $vf0, %1y" : "+j"(v.mData) : "j"(a.lVector)); }

// 0x0035BC10
extern "C" void PrepareOffset__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyQ29GtMathPs26CGtV3dffi(
    UnkStruct_0035BC10_self * self, EB3RigType rig, EB3FocusType focus, CB3ChildBody * body, CGtV3d offset, float f0, float f1, int idx, bool b)
{
    self->field_CC = rig;
    self->field_84 = (UnkStruct_0035BC10_2 *)body;
    self->field_A0 = offset;
    self->field_B8 = f0;
    self->field_C8 = focus;
    self->field_C4 = idx;
    self->field_D0 = b;
    GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody(&self->field_0, self->field_84->field_40);
    self->field_40.SetIdentity();
    self->field_40.mPos = v241_xform(self->field_0, self->field_A0);
    UnkStruct_0035BC10_pad p;
    CGtV3d v;
    if (self->field_D0) {
        UnkStruct_0035BC10_2 * car = func_00353960((char *)&D_00522660.field_0[self->field_C4] + 0x128290);
        v = func_002F5DC0(car->field_40->field_13F4, &self->field_40.mPos);
    } else {
        v = func_002F6040(&self->field_40.mPos, self->field_C4);
    }
    v241_sety(self->field_40.mPos, v241_yadd(self->field_A0.Y(), v.Y()));
    PrepareFocus__13CB3ClusterRigFf(self, f1);
}

