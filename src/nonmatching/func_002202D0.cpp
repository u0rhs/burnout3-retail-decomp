// NONMATCHING: func_002202D0 -- retail 93 / ours 95 instructions, 30 in changed runs
// near29: compiles again (local DotProduct dropped for the header's; asm volatile dropped); side-plane asm wrapped in a .set noreorder region (real asm, v298) -> 30 (95 vs 93). Left: frame 0x60 vs 0x50 (one extra slot), end-plane W read lq+qmtc2 vs retail lqc2/sqc2, prologue order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_002202D0 -- retail 93 / ours 96 instructions, 38 in changed runs
// a203: manual-inlined DotProduct + int/mtc1 lane read: frame 0x60 vs retail 0x50 (was 0x90); one dead slot left
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// NONMATCHING: func_002202D0 -- retail 93 / ours 96 instructions, 38 in changed runs
// b119p: natural DotProduct form hoists 1.0 correctly (loop body matches except operand form: retail lqc2 vf3 from plane + sqc2 pad store, we lq+qmtc2). Left: frame 0x90 vs 0x50 (extra sphere/c copies), side-plane inline asm order (qmtc2 radius/lqc2 vf6 scheduling), end-plane W copy; local CGtPlane/CGtSphere removed
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// NONMATCHING: func_002202D0 -- retail 93 / ours 96 instructions, 39 in changed runs
// 39 in changed runs: logic, blocks and the pinned 1.0 hoist match; left: frame 0x70 vs 0x50 (two extra 16-byte slots), b119 reorders the side-plane test's asm (vaddx/vmulx/lqc2 vf6 moved up; scheduling off has no effect), and the plane's W copy reloads with lq+sq where retail stores vf3 (sqc2) from the dot product's lqc2
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
namespace GtMathPs2 {
// CGtSphere / CGtPlane now come from include/b3/GtMathPs2.h (header-API task, N185).
// [G] GtMathPs2::DotProduct(CGtV3d, CGtV3d) (B3O0PCH map): the product and the ACC sum on hard-coded $vf1, the 1.0
// constant as its own "=j" statement defined late (just before the tail; defined first, the VU registers number
// differently: 6 off), then the tail on compiler-chosen registers. b119p hoists the 1.0 into $vf2 as retail (N184).
// The four dead lane reads are a frame pad: retail's frame keeps four more 16-byte slots below the sphere copy
// (inline-local temporaries of the real bodies, N129 mechanism); dead converted locals in an inline reproduce them.
// [C] API: B3O0PCH map (GtMathPs2::operator -(XAxisType,WAxisType), 80 bytes out of line). [G] body.
static inline XAxisType operator-(XAxisType a, WAxisType b)
{
    u_long128 e;
    asm("qmtc2.i %1, $vf1" "\n\t" "vsubw.x $vf1, $vf1, %2w" "\n\t" "qmfc2 %0, $vf1" : "=r"(e) : "r"(a.lVector), "j"(b.lVector));
    return XAxisType(e);
}
}
// [G] a frustum-like global (CGtFrustum's layout, Revenge types.h: two end planes, then the side planes as X/Y/Z/D
// columns), followed by a second set of side-plane columns
struct UnkStruct_D_0067D5A0 {
    CGtPlane maEndPlanes[2];
    u_long128 field_20, field_30, field_40, field_50;
    u_long128 field_60, field_70, field_80, field_90;
};
extern UnkStruct_D_0067D5A0 D_0067D5A0;

// [G] the four side-plane columns at p+K against a sphere: D - (X*cx + Y*cy + Z*cz) + r per lane; returns the or'ed
// lane sign masks (non-zero: outside one of the planes)
static inline unsigned long func_002202D0_inl(const u_long128* p, const CGtV3d* c, float r)
{
    u_long128 v, m;
    unsigned long any;
    asm(".set noreorder");
    asm("qmtc2.ni %1, $vf1" "\n\t" "lqc2 $vf2, 48(%2)" "\n\t" "lqc2 $vf3, 0(%2)" "\n\t" "lqc2 $vf4, 16(%2)" "\n\t"
        "lqc2 $vf5, 32(%2)" "\n\t" "lqc2 $vf6, 0(%3)" "\n\t" "vaddx.yz $vf1, $vf0, $vf1x" "\n\t" "vmulx.w $vf1, $vf0, $vf1x" "\n\t"
        "vaddax.xyzw $ACC, $vf2, $vf0x" "\n\t" "vmsubax.xyzw $ACC, $vf3, $vf6x" "\n\t" "vmsubay.xyzw $ACC, $vf4, $vf6y" "\n\t"
        "vmsubaz.xyzw $ACC, $vf5, $vf6z" "\n\t" "vmaddw.xyzw $vf1, $vf1, $vf0w" "\n\t" "qmfc2.ni %0, $vf1"
        : "=r"(v) : "r"(r), "r"(p), "r"(c));
    asm(".set reorder");
    asm("psraw %0, %1, 31" : "=r"(m) : "r"(v));
    asm("pcpyud %0, %1, $0" "\n\t" "or %0, %1, %0" : "=r"(any) : "r"(m));
    return any;
}

// 0x002202D0
extern "C" int func_002202D0(CGtSphere s)
{
    UnkStruct_D_0067D5A0* f = &D_0067D5A0;
    CGtV3d c = s.Position();
    float rad = s.Radius();
    float nrad = -rad;
    int r = 2;
    if (func_002202D0_inl(&f->field_20, &c, rad) != 0) return 0;

    for (int i = 0; i < 2; i++) {
        u_long128 m, one; int di;
        CGtV3d pp = s.Position();
        CGtV3d nn = f->maEndPlanes[i].Normal();
        asm("vmul.xyz $vf1, %1, %2" "\n\t" "vadday.x $ACC, $vf1, $vf1y" : "=j"(m) : "j"(pp.mData), "j"(nn.mData));
        asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
        asm("vmaddz.x $vf1, %2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(di) : "j"(m), "j"(one));
        float dv; asm("mtc1 %1, %0" : "=f"(dv) : "r"(di));
        float dd = dv - (float)f->maEndPlanes[i].Distance();
        if (!(dd <= rad)) return 0;
        if (!(dd <= nrad)) r = 1;
    }
    if (r != 1) {
        if (func_002202D0_inl(&D_0067D5A0.field_60, &c, nrad) != 0) r = 1;
    }
    return r;
}


