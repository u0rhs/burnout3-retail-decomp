// NONMATCHING: func_003CE0A0 -- retail 124 / ours 126 instructions, 83 in changed runs
// ghvu6: 124/126, 83 off. [L] DNAT _DispatchLRGradient. Structure right: 2x2-inverse axis, two Interpolate(c, D_004CA5C0, t) * c0 colours, loop of (p0+p3)*0.5 dot axis clamped -> header-style Interpolate -> RenderTriStripFlatTex. Retail moves c0/c1/c2/D through GPRs (lq + qmtc2.ni, unfolded), D/c0 qmtc2 once (CSE'd), the two colours live in s1/s0 across the loop. Left: D vs c0 VU numbering (vf3/vf4) conflicts with keeping r in s0; 9th arg read early with a dummy lw zero,0x110(sp) (by-value CGtV2d?); FP regs (1.0 in f21, axis.y f20); t mfc1 once in the prologue
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [L] DNAT: CB3StylisedText2dObject::_DispatchLRGradient(CGtV4d, CGtV4d, CGtV4d, const CGtV2d&, ...) (research/proto/new_names.csv, high)
// Retail's label is still func_003CE0A0's placeholder, so C linkage; parameter order from the caller's registers [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class Gt2dRenderer {
public:
    static void RenderTriStripFlatTex(CGtV4d colour, const CGtV2d &pos, int n, const CGtV2d *pts, const CGtV2d *uvs);
};
extern const CGtV4d D_004CA5C0;

// [L] N185: stands in for an Interpolate(CGtV4d, CGtV4d, float) whose end point sits on a compiler-chosen register
// (retail: a moved into $vf2, t into $vf1, `vmaddx.xyzw $vf1, $vf3, $vf1x`, result out through a GPR; the header's
// Interpolate hard-codes b in $vf1)
static inline u_long128 func_003CE0A0_inl1(u_long128 a, u_long128 b, float t)
{
    u_long128 r;
    asm("qmtc2.i %1, $vf2" "\n\t" "vaddax.xyzw $ACC, $vf2, $vf0x" "\n\t" "qmtc2.i %2, $vf1" "\n\t" "vmsubax.xyzw $ACC, $vf2, $vf1x" "\n\t"
        "vmaddx.xyzw $vf1, %3, $vf1x" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r) : "r"(a), "r"(t), "j"(b));
    return r;
}
// [L] N185: stands in for CGtV4d::operator*(CGtV4d) with this through $vf1 and a GPR (retail vmul.xyzw $vf1, $vf1, $vf4)
static inline u_long128 func_003CE0A0_inl2(u_long128 a, u_long128 b)
{
    u_long128 r;
    asm("qmtc2.i %1, $vf1" "\n\t" "vmul.xyzw $vf1, $vf1, %2" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r) : "r"(a), "j"(b));
    return r;
}
// [L] N185: the header's Interpolate(CGtV4d, CGtV4d, float) body on u_long128 operands
static inline u_long128 func_003CE0A0_inl3(u_long128 a, u_long128 b, float t)
{
    u_long128 tv, r;
    asm("vaddax.xyzw $ACC, %1, $vf0x" "\n\t" "qmtc2.ni %2, %0" "\n\t" "vmsubax.xyzw $ACC, %1, %0x" : "=&j"(tv) : "j"(a), "r"(t));
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vmaddx.xyzw $vf1, $vf1, %2x" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r) : "r"(b), "j"(tv));
    asm(".set reorder");
    return r;
}

extern "C" void func_003CE0A0(CGtV4d c0, CGtV4d c1, CGtV4d c2, const CGtV2d &pos, const CGtV2d *pts0, const CGtV2d *uvs0, int n0,
                              const CGtV2d &a, const CGtV2d &b, float t)
{
    int n = n0;
    const CGtV2d *pts = pts0;
    const CGtV2d *uvs = uvs0;
    float inv = 1.0f / (a.marValues[1] * b.marValues[0] - a.marValues[0] * b.marValues[1]);
    CGtV2d axis;
    axis.marValues[0] = -b.marValues[1] * inv;
    float *py = &axis.marValues[1];
    *py = b.marValues[0] * inv;
    u_long128 dv, cv;
    asm("qmtc2.i %1, %0" : "=j"(dv) : "r"(D_004CA5C0.mData));
    asm("qmtc2.i %1, %0" : "=j"(cv) : "r"(c0.mData));
    u_long128 i1 = func_003CE0A0_inl1(c1.mData, dv, t);
    u_long128 l = func_003CE0A0_inl2(i1, cv);
    u_long128 i2 = func_003CE0A0_inl1(c2.mData, dv, t);
    u_long128 r = func_003CE0A0_inl2(i2, cv);
    while (n > 3) {
        CGtV2d mid = (pts[0] + pts[3]) * 0.5f;
        float s = GtMath::Min(GtMath::Max(mid.marValues[0] * axis.marValues[0] + mid.marValues[1] * axis.marValues[1], 0.0f), 1.0f);
        Gt2dRenderer::RenderTriStripFlatTex(CGtV4d(func_003CE0A0_inl3(l, r, s)), pos, 4, pts, uvs);
        pts += 6;
        uvs += 6;
        n -= 6;
    }
}
