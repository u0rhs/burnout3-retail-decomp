// CB3CrashCameraDirector::GetRigImpact(CB3ClusterRig*,CB3ChildBody*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCameraDirector.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (v273: SetX/Y/Z(float) + Y-subtract stand-ins, offset by ref, N140 pads).

// Hand-written (v273); the lifter refused it (SetX/Y/Z(float) and Y-lane subtract stand-ins, offset passed by reference, N140 pads).
// CB3CrashCameraDirector::GetRigImpact(CB3ClusterRig*, CB3ChildBody*) -- [C] name: the mangled symbol in retail's tables.
// extern "C" definition under the mangled name (the consolidated class header lacks the fields). Types/fields [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_00357250_pad { int x[4]; UnkStruct_00357250_pad() {} ~UnkStruct_00357250_pad() {} };  // [G] N140 frame pad
struct UnkStruct_00357250_e { unsigned char pad_0[4]; unsigned char field_4; unsigned char field_5; unsigned char pad_6[4]; };
struct UnkStruct_00357250_ls { unsigned char pad_0[8]; UnkStruct_00357250_e * field_8; };
struct UnkStruct_00357250_lane { unsigned char pad_0[4]; UnkStruct_00357250_ls * field_4; };
struct UnkStruct_00357250_ai { unsigned char pad_0[0x18B4]; void * field_18B4; unsigned short field_18B8; };
struct UnkStruct_00357250_c40 { unsigned char pad_0[0x13F4]; UnkStruct_00357250_ai * field_13F4; };
struct UnkStruct_00357250_car { unsigned char pad_0[0x40]; UnkStruct_00357250_c40 * field_40; };
struct UnkStruct_00357250_b40 { unsigned char pad_0[0xB0]; CGtV4d field_B0; unsigned char pad_C0[0x144]; CGtMatrix3x4 * field_204; };
struct UnkStruct_00357250_child { unsigned char pad_0[0x40]; UnkStruct_00357250_b40 * field_40; unsigned char pad_44[0x10]; float field_54; };
struct UnkStruct_00357250_f30 { unsigned char pad_0[0x74]; float field_74; };
struct UnkStruct_00357250_f14 { unsigned char pad_0[0x30]; const UnkStruct_00357250_f30 * field_30; };
struct UnkStruct_00357250 {
    unsigned char pad_0[0x8];
    void * field_8;
    unsigned char pad_C[0x8];
    const UnkStruct_00357250_f14 * field_14;
    unsigned char pad_18[0xC];
    int field_24;
    int field_28;
};
extern float D_004E0EF0;

extern "C" UnkStruct_00357250_car * func_00353960(void *);
extern "C" UnkStruct_00357250_lane * WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(void *, unsigned short *, const CGtV3d &);
extern "C" CGtV3d GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(UnkStruct_00357250_ls *, unsigned short, float, int);
// [L] retail passes an 8th argument (t2, a bool) that the mangled name doesn't list (as PrepareOffset's own source reads it)
// The CGtV3d by value is declared as a reference: retail passes &offset with no copy (L265) [G].
extern "C" void PrepareOffset__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyQ29GtMathPs26CGtV3dffi(
    void *, int, int, UnkStruct_00357250_child *, const CGtV3d &, float, float, int, bool);

// [L] N185 stand-ins for CGtV3d::SetX/Y/Z(float) with the scalar on a compiler-chosen register (v241)
static inline void func_00357250_sx(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00357250_sy(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00357250_sz(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
// [L] N185 stand-in for operator-(YAxisType, YAxisType) on the two vectors' y lanes, "=j" result: retail loads the subtrahend
// first (`lqc2 $vf1, p; lqc2 $vf2, pos; vsuby.y $vf1, $vf2, $vf1y`). Called as ysub(subtrahend, minuend).
static inline YAxisType func_00357250_ysub(const CGtV3d &b, const CGtV3d &a) { u_long128 r; asm("vsuby.y %0, %2, %1y" : "=j"(r) : "j"(b.mData), "j"(a.mData)); return YAxisType(r); }

// [G] placeholder inline: the lane segment linked both ways (bytes +4/+5 != 0xFF); its two pads are N140 frame pads [G]
// (retail's dead slots between the W lane read and the Y lane read).
static inline bool func_00357250_inl2(const UnkStruct_00357250_e * e) { UnkStruct_00357250_pad q0, q1; return e->field_4 != 0xFF && e->field_5 != 0xFF; }
// 0x00357250
extern "C" void GetRigImpact__22CB3CrashCameraDirectorFP13CB3ClusterRigP12CB3ChildBody(UnkStruct_00357250 * self, void * rig, UnkStruct_00357250_child * child)
{
    unsigned short seg;
    CGtV3d offset;
    UnkStruct_00357250_pad pa;   // [G] N140 pads (pa, pb, pc): retail frame 0x130
    float dist;
    float w = child->field_40->field_B0.W();
    float t = 1.5f * (child->field_54 * w);
    t = GtMath::Max(t, 8.0f);
    t = GtMath::Min(t, 30.0f);
    switch (self->field_24) {
    case 0:
        func_00357250_sx(offset, 11.0f);
        func_00357250_sy(offset, D_004E0EF0);
        func_00357250_sz(offset, 0.25f * t);
        dist = 60.0f;
        break;
    case 1:
        func_00357250_sx(offset, 7.0f);
        func_00357250_sy(offset, 5.5f);
        func_00357250_sz(offset, -8.0f);
        dist = 45.0f;
        break;
    case 2:
        func_00357250_sx(offset, -11.0f);
        func_00357250_sy(offset, D_004E0EF0);
        func_00357250_sz(offset, t);
        dist = 60.0f;
        break;
    case 3:
        func_00357250_sx(offset, 7.0f);
        func_00357250_sy(offset, 5.5f);
        func_00357250_sz(offset, t);
        dist = 45.0f;
        break;
    }
    self->field_24 = (self->field_24 + 1) % 4;
    CGtV3d pos = child->field_40->field_204->mPos;
    UnkStruct_00357250_ai * ai = func_00353960(self->field_8)->field_40->field_13F4;
    seg = ai->field_18B8;
    UnkStruct_00357250_ls * ls = WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(ai->field_18B4, &seg, pos)->field_4;
    UnkStruct_00357250_e * e = &ls->field_8[seg];
    bool ok = func_00357250_inl2(e);
    if (ok) {
        UnkStruct_00357250_pad pb;
        CGtV3d p = GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(ls, seg, 0.0f, 1);
        UnkStruct_00357250_pad pc;
        if (func_00357250_ysub(p, pos) < -3.0f)
            ok = false;
    }
    PrepareOffset__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyQ29GtMathPs26CGtV3dffi(
        rig, 4, 2, child, offset, dist, self->field_14->field_30->field_74, self->field_28, ok);
}
