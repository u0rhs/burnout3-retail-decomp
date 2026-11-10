// NONMATCHING: ClipEdgesByPlane__20CB3ConvexHullCollideFPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dUiQ29GtMathPs28CGtPlane -- retail 86 / ours 86 instructions, 18 in changed runs
// prag1: LOGIC FIX -- the interp asm had "+j"(a.mData), clobbering a before out[k++] = a (retail reloads the original a); now hard-coded $vf1/$vf2 with a, b, t as GPR inputs (lq+qmtc2 folds to retail's lqc2 vf1). Added if (n == 0) return k; (retail's extra beqz a2). Scoped arith off kept (26 vs 30 without). 30 -> 18, 86/86. Left: a/b slots 0x50/0x40 vs 0x40/0x30, in0/in1 bc1t/bc1f sense, mfc1 t after vaddax (+nop), qmfc2+sq folded to sqc2 (.i needs a config/vu0_keep_i.txt entry -- lead)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// a192: hoists (vf4,vf3 1.0s + vf5 plane normal) and VU regs match; 30 off: andi on in0/in1 where retail has raw int compare (nop;b;move pairs), retail entry beqz a2 + sltu zero<a2 both, a/b stack slots 0x40/0x30 vs ours 0x50/0x40 (+interp reads a from stack, ours forwards to vf)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
// [G] N182: scoped opt_arithtransformation off (psweep_all.py; N236: pragmas are per-function)
#pragma push
#pragma opt_arithtransformation off
using namespace GtMathPs2;
// [L] N185: stands in for GtMathPs2::DotProduct with retail's hard-coded $vf1
static inline XAxisType func_002B78A0_inl0(CGtV3d a, CGtV3d b)
{
    u_long128 d, m, one, bv;
    asm("qmtc2.ni %1, %0" : "=j"(bv) : "r"(b.mData));
    asm("qmtc2.ni %2, $vf1" "\n\t" "vmul.xyz $vf1, %1, $vf1" "\n\t" "vadday.x $ACC, $vf1, $vf1y" : "=j"(m) : "j"(bv), "r"(a.mData));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm("vmaddz.x $vf1, %2, $vf1z" "\n\t" "qmfc2.ni %0, $vf1" : "=r"(d) : "j"(m), "j"(one));
    return XAxisType(d);
}
class CB3ConvexHullCollide { public:
static int ClipEdgesByPlane(CGtV3d *out, CGtV3d *in, unsigned n, CGtPlane pl);
};
// 0x002B78A0
int CB3ConvexHullCollide::ClipEdgesByPlane(CGtV3d *out, CGtV3d *in, unsigned n, CGtPlane pl)
{
    int k = 0;
    if (n == 0) return k;
    float dist = pl.Distance();
    for (unsigned i = 0; i < n; ) {
        CGtV3d a = in[i];
        CGtV3d b = in[i + 1];
        float d0 = func_002B78A0_inl0(a, pl.Normal());
        float d1 = func_002B78A0_inl0(b, pl.Normal());
        int in0 = d0 <= dist ? 1 : 0;
        int in1 = d1 <= dist ? 1 : 0;
        if (in0 != in1) {
            float t = (dist - d0) / (d1 - d0);
            u_long128 r;
            asm("qmtc2.ni %1, $vf1" "\n\t" "vaddax.xyz $ACC, $vf1, $vf0x" "\n\t" "qmtc2.ni %3, $vf2" "\n\t" "vmsubax.xyz $ACC, $vf1, $vf2x" "\n\t"
                "qmtc2.ni %2, $vf1" "\n\t" "vmaddx.xyz $vf1, $vf1, $vf2x" "\n\t" "qmfc2.ni %0, $vf1"
                : "=r"(r) : "r"(a.mData), "r"(b.mData), "r"(t));
            out[k++] = CGtV3d(r);
        }
        if (in0 == 1) out[k++] = a;
        if (in1 == 1) out[k++] = b;
        i += 2;
    }
    return k;
}

#pragma pop
