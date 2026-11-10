// NONMATCHING: GetPivotPos__16CB3VehicleDeformF17EVirtualBoneIndex -- retail 124 / ours 121 instructions, 27 in changed runs
// ghvu12: logic + frame 0xE0 exact (projection in a [G] inline, by-value N129 stand-ins); left: retail loads p2 twice (vsub/q-= share vf3, the vadd gets its own lqc2 vf6) and reloads mPos for the -= through an early address register while the float lane read shares the VU load; ours CSEs them; VU numbering at the top follows
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EVirtualBoneIndex { EVirtualBoneIndex_0 };   // placeholder enumerators [G]
struct UnkStruct_003E0590_e { CGtV3d field_0; CGtV3d field_10; unsigned char pad_20[0x20]; };
struct UnkStruct_003E0590_p { unsigned char pad_0[0x90]; UnkStruct_003E0590_e field_90[8]; };
struct UnkStruct_003E0590_q { unsigned char pad_0[0x700]; CGtMatrix3x4 field_700[7]; };
class CB3VehicleDeform {
public:
    CGtV3d GetWindscreenPos(bool, bool);
    CGtV3d GetPivotPos(EVirtualBoneIndex);
    unsigned char pad_0[0x14];
    UnkStruct_003E0590_q *field_14;
    UnkStruct_003E0590_p *field_18;
};

// [L] N185: compiler-chosen CGtV3d operator- stand-in
static inline CGtV3d func_003E0590_inl1(CGtV3d a, CGtV3d b)
{ u_long128 r; asm("vsub.xyz %0, %1, %2" : "=&j"(r) : "j"(*(const u_long128 *)&a.mData), "j"(*(const u_long128 *)&b.mData)); return CGtV3d(r); }
// [L] N185: compiler-chosen CGtV3d operator+ stand-in
static inline CGtV3d func_003E0590_inl2(CGtV3d a, CGtV3d b)
{ u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(*(const u_long128 *)&a.mData), "j"(*(const u_long128 *)&b.mData)); return CGtV3d(r); }
// [L] N185: CGtV3d * XAxisType (lane-x scale) stand-in
static inline CGtV3d func_003E0590_inl3(CGtV3d a, XAxisType s)
{ u_long128 r; asm("vmulx.xyz %0, %1, %2x" : "=j"(r) : "j"(*(const u_long128 *)&a.mData), "j"(*(const u_long128 *)&s.lVector)); return CGtV3d(r); }
// [L] N185: operator-(XAxisType, XAxisType) stand-in
static inline XAxisType func_003E0590_inl4(XAxisType a, XAxisType b)
{ u_long128 r; asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
// [L] N185: in-place Normalise on compiler-chosen registers stand-in
static inline void func_003E0590_inl5(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r = v.mData;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(r));
    asm(".set reorder");
    v.mData = r;
}

// [G] the projection onto the bone line as an inline (frame: its slots sit below the call temporary)
static inline CGtV3d func_003E0590_inl6(CB3VehicleDeform *self, int i1, int i2)
{
    CGtV3d d = func_003E0590_inl1(self->field_18->field_90[i1].field_10, self->field_18->field_90[i2].field_10);
    d.SetX(0.0f);
    func_003E0590_inl5(d);
    CGtV3d q = self->field_18->field_90[3].field_10;
    q -= self->field_18->field_90[i2].field_10;
    CGtV3d p = func_003E0590_inl2(self->field_18->field_90[i2].field_10, func_003E0590_inl3(d, DotProduct(q, d)));
    return p;
}
// [G] the scaled offset as an inline
static inline float func_003E0590_inl7(XAxisType l, float a) { return l * a; }
// 0x003E0590
CGtV3d CB3VehicleDeform::GetPivotPos(EVirtualBoneIndex bone)
{
    int i2, i1;
    bool b;
    switch (bone) {
    case 0: i2 = 4; i1 = 1; b = true; break;
    case 4: i2 = 1; i1 = 4; b = false; break;
    case 1: i2 = 5; b = true; i1 = 2; break;
    case 5: i1 = 5; i2 = 2; b = false; break;
    }
    CGtV3d p = func_003E0590_inl6(this, i1, i2);
    const CGtV3d &mp = field_14->field_700[3].mPos;
    float a = func_003E0590_inl4(p.X(), field_14->field_700[3].mPos.X());
    float x = func_003E0590_inl7(field_14->field_700[3].mRight.GetLength(), a) + (float)field_14->field_700[3].mPos.X();
    p.SetX(x);
    p -= mp;
    p += GetWindscreenPos(b, false) * 0.5f;
    return p;
}





