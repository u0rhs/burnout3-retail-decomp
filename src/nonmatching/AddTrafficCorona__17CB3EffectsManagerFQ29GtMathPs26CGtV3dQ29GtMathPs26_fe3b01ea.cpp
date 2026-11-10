// NONMATCHING: AddTrafficCorona__17CB3EffectsManagerFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df -- retail 44 / ours 41 instructions, 10 in changed runs
// stabs2: header CGtV3d::operator*(float) for c4*d (stand-in kept for v*64); 17 -> 10, length 42 -> 41. Left: dot vmul dest reg + lqc2 order (header), 400.0f via mtc1/swc1 (ours sw), the v*64 result round-trips GPR->VU before sqc2
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed
// retune1 (N239): s->w = 400.0f stored before the c3 copy; 33 -> 17 -- REVERTED 2026-11-07: that order changed behaviour (the c3 qword copy then overwrote w); retail's order restored

// NONMATCHING: AddTrafficCorona__17CB3EffectsManagerFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df -- retail 44 / ours 42 instructions, 21 in changed runs
// near22: header DotProduct(p2,p1) reproduces the parked dot block (only load order of p1/p2 differs); hard-coded operator*(float) stand-in. Left: retail stores 400.0f via mtc1/swc1 (ours lui/sw) and moves the second product back into VU (qmtc2+sqc2) where ours sq's the GPR; p3/p4 lq hoisted vs head order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// [L] N185 stand-ins (near22): DotProduct with the sum parked on hard-coded $vf1/$vf2 (retail 0x256FD0: m and the 1.0 go
// through GPRs into the vadday/vmaddz block); CGtV3d::operator*(float) in its older hard-coded body (header note: "Was").
static inline XAxisType func_00256FD0_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 o, m, mg, one, d;
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(o));
    asm("vmul.xyz %0, %1, %2" : "=j"(m) : "j"(b.mData), "j"(a.mData));
    asm("qmfc2.i %0, %1" : "=r"(mg) : "j"(m));
    asm("qmfc2.i %0, %1" : "=r"(one) : "j"(o));
    asm("qmtc2.i %1, $vf2" "\n\t" "vadday.x $ACC, $vf2, $vf2y" "\n\t" "qmtc2.i %2, $vf1" "\n\t" "vmaddz.x $vf1, $vf1, $vf2z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(d) : "r"(mg), "r"(one));
    return XAxisType(d);
}
static inline CGtV3d func_00256FD0_inl2(const CGtV3d &v, float s)
{
    u_long128 r;
    asm("qmtc2.i %1, $vf1" "\n\t" "qmtc2.i %2, $vf2" "\n\t" "vmulx.xyz $vf1, $vf1, $vf2x" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r) : "r"(v.mData), "r"(s));
    return CGtV3d(r);
}
struct UnkStruct_00256FD0_slot { float x, y, z, w; float vx, vy, vz, vw; };
class CB3EffectsManager {
public:
    void AddTrafficCorona(CGtV3d p1, CGtV3d p2, CGtV3d p3, CGtV3d p4, float f);
    unsigned char pad_0[0x2C];
    UnkStruct_00256FD0_slot *field_2C;
    UnkStruct_00256FD0_slot *field_30;
};
// 0x00256FD0
void CB3EffectsManager::AddTrafficCorona(CGtV3d p1, CGtV3d p2, CGtV3d p3, CGtV3d p4, float f)
{
    CGtV3d c3 = p3;
    CGtV3d c4 = p4;
    float d = DotProduct(p2, p1);
    if (d > 0.0f) {
        CGtV3d v = c4 * d;
        UnkStruct_00256FD0_slot *s = field_2C;
        if (s != field_30) {
            CGtV3d w = v * 64.0f;
            *(CGtV3d *)&s->x = c3;
            s->w = 400.0f; // [C] retail stores c3 first (0x257058 sq a3, 0(a2)), then 400.0 at +0xC (0x25705C swc1 f0): retune1's order let the qword copy overwrite w (port lane vu0, culprit #14)
            *(CGtV3d *)&s->vx = w;
            s->vw = f;
            field_2C = field_2C + 1;
        }
    }
}
