// NONMATCHING: IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC17CGtAxisAlignedBox -- retail 66 / ours 66 instructions, 50 in changed runs
// ghvu1: 66/66 instrs, 50 in changed runs: logic right (Arvo sphere-AABB, any/all sign masks via psraw/pcpyud), but VU register allocation/scheduling differs (retail keeps c/d1/d0/z/acc/two FLT_MAX on vf6-vf12, scratch on vf1-vf5; in-place vmulx/vmini/vadd) and frame 0x400 (many dead inline slots) vs 0x50. [L] N185 stand-ins for vmini/vmax/vabs/vmul/lane-sum.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// GtIntersection::IntersectSphere(CGtSphere, const CGtAxisAlignedBox&) -- hand-written (ghvu1, Ghidra-draft trial).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct CGtAxisAlignedBox { CGtV3d field_0; CGtV3d field_10; };   // [G] layout: min at 0, max at 0x10
// [L] N185: stand-ins for missing GtMathPs2 inlines (element-wise vmini/vmax/vabs/vmul, lane-scaled mul, lane sum,
// sign masks), one asm per retail instruction, compiler-chosen registers.
static inline u_long128 func_00274DC0_sub(u_long128 a, u_long128 b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b)); return r; }
static inline u_long128 func_00274DC0_zero() { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); return r; }
static inline u_long128 func_00274DC0_mini(u_long128 a, u_long128 b) { u_long128 r; asm("vmini.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b)); return r; }
static inline u_long128 func_00274DC0_max(u_long128 a, u_long128 b) { u_long128 r; asm("vmax.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b)); return r; }
static inline u_long128 func_00274DC0_abs(u_long128 a) { u_long128 r; asm("vabs.xyz %0, %1" : "=j"(r) : "j"(a)); return r; }
static inline u_long128 func_00274DC0_mul(u_long128 a, u_long128 b) { u_long128 r; asm("vmul.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b)); return r; }
static inline u_long128 func_00274DC0_add(u_long128 a, u_long128 b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b)); return r; }
static inline u_long128 func_00274DC0_scale(u_long128 a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyz %0, %1, %2x" : "=j"(r) : "j"(a), "j"(s)); return r; }
static inline float func_00274DC0_hsum(u_long128 a) { u_long128 t; float f; asm("vaddy.x %0, %1, %1y" : "=j"(t) : "j"(a)); asm("vaddz.x %0, %0, %1z" : "+j"(t) : "j"(a)); asm("qmfc2.i %0, %1" : "=r"(f) : "j"(t)); return f; }
static inline void func_00274DC0_scalei(u_long128 &a, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyz %0, %0, %1x" : "+j"(a) : "j"(s)); }
static inline void func_00274DC0_minii(u_long128 &a, u_long128 b) { asm("vmini.xyz %0, %0, %1" : "+j"(a) : "j"(b)); }
static inline void func_00274DC0_addi(u_long128 &a, u_long128 b) { asm("vadd.xyz %0, %0, %1" : "+j"(a) : "j"(b)); }
static inline void func_00274DC0_mulr(u_long128 &a, u_long128 b) { asm("vmul.xyz %0, %1, %0" : "+j"(a) : "j"(b)); }
// 0x00274DC0
class GtIntersection { public: static int IntersectSphere(CGtSphere s, const CGtAxisAlignedBox &b); };
int GtIntersection::IntersectSphere(CGtSphere s, const CGtAxisAlignedBox &b)
{
    u_long128 c = s.mData;
    u_long128 d1 = func_00274DC0_sub(c, b.field_10.mData);
    u_long128 z = func_00274DC0_zero();
    u_long128 d0 = func_00274DC0_sub(c, b.field_0.mData);
    u_long128 a1 = func_00274DC0_abs(func_00274DC0_mini(d1, z));
    u_long128 a0 = func_00274DC0_max(d0, z);
    CGtV3d ones(1.0f, 1.0f, 1.0f);
    func_00274DC0_scalei(a1, 3.402823466e+38f);
    func_00274DC0_scalei(a0, 3.402823466e+38f);
    func_00274DC0_minii(a1, ones.mData);
    func_00274DC0_minii(a0, ones.mData);
    u_long128 acc = func_00274DC0_zero();
    u_long128 p1 = func_00274DC0_mul(func_00274DC0_mul(d1, d1), a1);
    func_00274DC0_mulr(a0, func_00274DC0_mul(d0, d0));
    func_00274DC0_addi(acc, p1);
    func_00274DC0_addi(acc, a0);
    float dist = func_00274DC0_hsum(acc);
    u_long128 rr; asm("vmulw.w %0, %1, %1w" : "=j"(rr) : "j"(c));
    float r2 = WAxisType(rr);
    if (!(dist < r2)) return 0;
    u_long128 v, w, z2;
    asm("vsubw.xyz %0, %1, %2w" : "=j"(v) : "j"(d1), "j"(c));
    asm("vaddw.w %0, $vf0, $vf0w" : "+j"(v));
    unsigned long vv; asm("qmfc2.i %0, %1" : "=r"(vv) : "j"(v));
    asm("vaddw.xyz %0, %1, %2w" : "=j"(w) : "j"(d0), "j"(c));
    u_long128 sv; asm("psraw %0, %1, 31" : "=r"(sv) : "r"(vv));
    asm("vsub.xyzw %0, $vf0, $vf0" : "=j"(z2));
    unsigned long any; asm("pcpyud %0, %1, $0\n\tor %0, %1, %0" : "=r"(any) : "r"(sv));
    asm("vsubw.w %0, %1, $vf0w" : "+j"(w) : "j"(z2));
    u_long128 ww; asm("qmfc2.i %0, %1" : "=r"(ww) : "j"(w));
    u_long128 sw; asm("psraw %0, %1, 31" : "=r"(sw) : "r"(ww));
    unsigned long all; asm("pcpyud %0, %1, $0\n\tand %0, %1, %0" : "=r"(all) : "r"(sw));
    if (all == 0 || any != 0) return 1;
    return 2;
}
