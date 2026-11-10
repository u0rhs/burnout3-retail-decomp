// NONMATCHING: PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib -- retail 247 / ours 244 instructions, 192 in changed runs
// happly1: hdr14 reroute (N232 header + GtMathPs2Trig.h) 221 -> 192
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib -- retail 247 / ours 244 instructions, 209 in changed runs
// v295: logic believed complete (cloned from proven PrepareOffset; 10th arg per v273), 247 vs 244 instrs, frame 0x170 exact with 8 N140 pads, 209 in changed runs (mostly schedule/registers: tail from the transforms on is exact up to stack offsets). Inlined GtMathPs2::SinCosFast(float) -> CosFast4 via v289's stand-ins (vmaddai as .word: b119's assembler rejects the mnemonic). Left: slot order (retail: call temps 0x130-0x150 above 8 dead slots at 0x40-0xB0; ours pads high, temps low -- try pads inside the SinCos/CosFast inlines), parameter-store/matrix-copy schedule at entry, CosFast4 constant/GPR scheduling (as func_002BB420's archive), row-0 register of the 2nd TransformPoint.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3ClusterRig::PrepareRotate(EB3RigType,EB3FocusType,CB3ChildBody*,float,float,GtMathPs2::CGtV3d,float,float,float,
// const CGtMatrix3x4&,const CGtMatrix3x4&,float,int,bool) -- hand-matched (v295); the lifter refused it.
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md).
// extern "C" definition under the mangled name: retail also reads a 10th argument (sp+8 at the caller, v273) that the
// mangled name doesn't list [L]. Field names are placeholders; types [G] from instruction widths.
// Shape cloned from the proven sibling PrepareOffset (B3BehaviourCluster_0035BC10.cpp): store the parameters, copy the
// rig matrix into +0x0, SetIdentity on +0x40, its position from a rotated offset, then the y fix-up from func_002F5DC0 /
// func_002F6040. [L] the inlined GtMathPs2::SinCosFast(float) (B3O0PCH map, 588 bytes) and CosFast4(CGtV4d) (520 bytes):
// no header API, so file-local stand-ins (v289's func_002BB420 ones). b119's inline assembler rejects vmaddai in every
// operand form, so it is written as .word 0x4BE00A3F / 0x4BE01A3F (v289) [G].

#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

enum EB3RigType {};
enum EB3FocusType {};
class CB3ChildBody;
struct UnkStruct_0035B830_3 {
    unsigned char pad_0[0x13F4];
    void * field_13F4;
};
struct UnkStruct_0035B830_2 {
    unsigned char pad_0[0x40];
    UnkStruct_0035B830_3 * field_40;
};
struct UnkStruct_0035B830_self {
    CGtMatrix3x4 field_0;
    CGtMatrix3x4 field_40;
    unsigned char pad_80[0x4];
    CB3ChildBody * field_84;
    unsigned char pad_88[0x8];
    CGtSphere field_90;
    CGtV3d field_A0;
    float field_B0;
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    int field_C4;
    EB3FocusType field_C8;
    EB3RigType field_CC;
    unsigned char field_D0;
};
struct UnkStruct_0035B830_e0 {
    unsigned char pad_0[0x1050];
};
struct UnkStruct_D_00522660 {
    UnkStruct_0035B830_e0 field_0[1];  // [G] element count unknown
};
extern UnkStruct_D_00522660 D_00522660;

extern "C" void PrepareFocus__13CB3ClusterRigFf(UnkStruct_0035B830_self * self, float f);
extern "C" UnkStruct_0035B830_2 * func_00353960(void * p);
extern "C" CGtV3d func_002F5DC0(void * p, const void * pos);
extern "C" CGtV3d func_002F6040(const void * pos, int i);

// [L] stand-in for GtMathPs2::CosFast4(CGtV4d) (B3O0PCH map, 520 bytes; v289's func_002BB420_inl2)
static inline CGtV3d func_0035B830_inl3(CGtV4d a, WAxisType w) { u_long128 r; asm("vmulw.xyz %0, %1, %2w" : "=j"(r) : "j"(a.mData), "j"(w.lVector)); return CGtV3d(r); }
static inline void func_0035B830_inl4(CGtV3d &v, YAxisType a) { asm("vaddy.z %0, $vf0, %1y" : "+j"(v.mData) : "j"(a.lVector)); }
static inline YAxisType func_0035B830_inl5(YAxisType a, YAxisType b) { u_long128 r; asm("vaddy.y %0, %1, %2y" : "=j"(r) : "j"(b.lVector), "j"(a.lVector)); return YAxisType(r); }
static inline void func_0035B830_inl6(CGtV3d &v, YAxisType a) { asm("vaddy.y %0, $vf0, %1y" : "+j"(v.mData) : "j"(a.lVector)); }
// [L] N185: TransformPoint with the point listed first (retail loads it before row 0), as PrepareOffset's v241_xform
static inline CGtV3d func_0035B830_inl7(const CGtMatrix3x4& m, CGtV3d v) {
    u_long128 t;
    asm("vmulax.xyz $ACC, %2, %1x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %1y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddaz.xyz $ACC, $vf1, %1z" "\n\t" "qmtc2.i %5, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(v.mData), "j"(m.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData), "r"(m.mPos.mData));
    return CGtV3d(t);
}
struct UnkStruct_0035B830_pad { int x[4]; UnkStruct_0035B830_pad() {} ~UnkStruct_0035B830_pad() {} };  // [G] N140 frame pad

// 0x0035B830
extern "C" void PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
    UnkStruct_0035B830_self * self, EB3RigType rig, EB3FocusType focus, CB3ChildBody * body, float f0, float f1, CGtV3d pos,
    float radius, float f2, float f3, const CGtMatrix3x4 & rigm, const CGtMatrix3x4 & m2, float focusf, int idx, bool b, unsigned char skip)
{
    UnkStruct_0035B830_pad p1, p2, p3, p4, p5, p6, p7, p8;
    self->field_CC = rig;
    self->field_84 = body;
    self->field_B0 = f0;
    self->field_B8 = f2;
    self->field_B4 = f1;
    self->field_BC = f3;
    self->field_C0 = f0 + 180.0f;
    self->field_0 = rigm;
    self->field_C8 = focus;
    self->field_C4 = idx;
    self->field_D0 = b;
    self->field_90.SetPosition(pos);
    self->field_90.SetRadius(radius);
    self->field_40.SetIdentity();
    CGtV4d sc = SinCosFast(0.01745329238f * self->field_B0);
    CGtV3d r = func_0035B830_inl3(sc, self->field_90.Radius());
    CGtV3d p;
    p.SetX(r.X());
    p.SetY(self->field_B4);
    func_0035B830_inl4(p, r.Y());
    CGtMatrix3x4 m = self->field_0;
    m.mPos = self->field_90.Position();
    self->field_40.mPos = func_0035B830_inl7(m, p);
    self->field_A0 = func_0035B830_inl7(m2, self->field_40.mPos);
    if (!skip) {
        CGtV3d v;
        if (self->field_D0) {
            UnkStruct_0035B830_2 * car = func_00353960((char *)&D_00522660.field_0[self->field_C4] + 0x128290);
            v = func_002F5DC0(car->field_40->field_13F4, &self->field_40.mPos);
        } else {
            v = func_002F6040(&self->field_40.mPos, self->field_C4);
        }
        func_0035B830_inl6(self->field_40.mPos, func_0035B830_inl5(self->field_A0.Y(), v.Y()));
    }
    PrepareFocus__13CB3ClusterRigFf(self, focusf);
}

