// NONMATCHING: CatmullRom__23CB3BehaviourInterpolateFPQ29GtMathPs26CGtV3dff -- retail 127 / ours 127 instructions, 10 in changed runs
// psweep pragma kept (26 without). grind1: 16 -> 10: field_10/field_20 of the 0x40 element as one CGtV3d field_10[2] array (retail's implicit copy loads both quads then stores both); inl2/inl3 stand-ins by const& (frame 0x180 -> 0x160). Left: frame 0x160 vs 0x120 (t at 0x150 vs 0x110, f 0x90 vs 0xA0), and the unary-minus/damping product registers (retail vsub -> vf2, scalar into vf1: looks hard-coded-register, header lead)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] logic exact (retail itself reads the uninitialised 0x110(sp) local); offsets and 2 VU registers differ


#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_dead_assignments off
using namespace GtMathPs2;

struct UnkStruct_003736D0_k {
    // vptr at +0x0: placeholder virtuals by slot offset [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_003736D0_k *, float);
    float field_4;
    float field_8;
    CGtV3d field_10[2];
    int field_30;
    int field_34;
    int field_38;
    unsigned char field_3C;
};
struct UnkStruct_003736D0_m { unsigned char pad_0[0x240]; UnkStruct_003736D0_k *field_240[1]; };
extern float krSpringCoeff;
extern float krDamping;

// [L] N185: compiler-chosen CGtV3d operator- stand-in
static inline CGtV3d func_003736D0_inl1(CGtV3d a, CGtV3d b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(*(const u_long128 *)&a.mData), "j"(*(const u_long128 *)&b.mData)); return CGtV3d(r); }
// [L] N185: CGtV3d * XAxisType (lane-x scale) stand-in
static inline CGtV3d func_003736D0_inl2(const CGtV3d &a, XAxisType s) { u_long128 r; asm("vmulx.xyz %0, %1, %2x" : "=j"(r) : "j"(*(const u_long128 *)&a.mData), "j"(*(const u_long128 *)&s.lVector)); return CGtV3d(r); }
// [L] N185: compiler-chosen CGtV3d unary operator- stand-in
static inline CGtV3d func_003736D0_inl3(const CGtV3d &a) { u_long128 r; asm("vsub.xyz %0, $vf0, %1" : "=j"(r) : "j"(*(const u_long128 *)&a.mData)); return CGtV3d(r); }

class CB3BehaviourInterpolate {
public:
    void CatmullRom(CGtV3d *pos, float p0, float dt);
    unsigned char pad_0[0x10];
    UnkStruct_003736D0_k field_10;
    UnkStruct_003736D0_k field_50;
    UnkStruct_003736D0_k field_90;
    UnkStruct_003736D0_k field_D0;
    CGtV3d field_110;
    UnkStruct_003736D0_m *field_120;
    unsigned char pad_124[0x14];
    int field_138;
    int field_13C;
    unsigned char pad_140[0x8];
    unsigned char field_148;
    unsigned char field_149;
};

// [L] N185: CGtV3d::operator+=(CGtV3d) with its by-value argument read through its address (N129 slot)
static inline void func_003736D0_inl4(CGtV3d &v, CGtV3d o) { asm("vadd.xyz %0, %0, %1" : "+j"(v.mData) : "j"(*(const u_long128 *)&o.mData)); }
// 0x003736D0
void CB3BehaviourInterpolate::CatmullRom(CGtV3d *pos, float p0, float dt)
{
    if (field_148 != 0) {
        field_90 = field_10;
    } else {
        field_120->field_240[field_138]->vfunc_18(&field_90, dt);
    }
    if (field_149 != 0) {
        field_D0 = field_50;
    } else {
        field_120->field_240[field_13C]->vfunc_18(&field_D0, dt);
    }
    CGtV3d t;
    CGtV3d d = func_003736D0_inl1(t, *pos);
    CGtV3d f(0.0f, 0.0f, 0.0f);
    CGtV3d dk = d * krSpringCoeff;
    func_003736D0_inl4(f, func_003736D0_inl2(dk, d.GetLength()));
    func_003736D0_inl4(f, func_003736D0_inl3(field_110) * krDamping);
    func_003736D0_inl4(field_110, f * dt);
    func_003736D0_inl4(*pos, field_110 * dt);
}



#pragma pop


