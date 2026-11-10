// NONMATCHING: TestLine__17CB3SpatialTriggerFRC7CGtLine -- retail 84 / ours 84 instructions, 3 in changed runs
// pass2c: 9 -> 3: a234_sub takes const CGtV3d& (retail lqc2 field_0 before field_10; frame back to 0x160 with 2 more N140 pads after pa6), and sqlen_rt's vmaddz + final qmfc2 merged into one statement in a .set noreorder region around that real asm (N188; keeps the eps lui/mtc1 after the mtc1 of the result). Left: rsq's W-lane copy slot sp+0x30 vs retail 0x70 (+ its addiu scheduled before qmfc2): pads in rsq, sqlen, a radius-compare wrapper, DotProduct wrapper, IntersectLine wrapper all land above it
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// NONMATCHING: TestLine__17CB3SpatialTriggerFRC7CGtLine -- retail 84 / ours 84 instructions, 14 in changed runs
// a234: 84/84 instrs, frame 0x160 matches (7 N140 pads), 14 in changed runs. Left: rsq temp slot at 0x30 vs retail 0x70 (4 slots below it; pads inside the inline helper did not move it) and diff at 0x150 vs 0x140; lqc2 vf3 scheduling; eps lui/mtc1 position; addiu v0,sp,rsq position. Stand-ins (header gaps): GPR-parked sqlen with m round-tripped through GPR (qmfc2.ni v1,vf2; qmtc2.ni v1,vf2), sqlen/dot with hard-coded $vf1 tail, W-lane square 'vmulw.w $vf1,S,Sw' -> stack -> lwc1
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
namespace GtMathPs2 {
static inline u_long128 a210_one() { u_long128 o, one; asm("vaddw.x %0, $vf0, $vf0w" : "=j"(o)); asm("qmfc2.i %0, %1" : "=r"(one) : "j"(o)); return one; }
// [L] N185 stand-in: GPR-parked squared length, the product round-tripped through a GPR (retail TestLine 0x272A58)
static inline XAxisType a234_sqlen_rt(CGtV3d aa)
{
    u_long128 a = aa.mData;
    u_long128 one = a210_one();
    u_long128 m, d, t, w;
    asm("vmul.xyz %1, %2, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(m), "=&j"(d) : "j"(a));
    asm("qmtc2.i %2, %0" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(t) : "j"(d), "r"(m));
    asm(".set noreorder");
    asm("qmtc2.i %3, %1" "\n\t" "vmaddz.x %1, %1, %2z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "j"(t), "r"(one));
    asm(".set reorder");
    return XAxisType(d);
}
// [L] N185 stand-in: GPR-parked squared length without the round trip (a210_sqlen)
static inline XAxisType a234_sqlen(const CGtV3d &aa)
{
    u_long128 a = aa.mData;
    u_long128 one = a210_one();
    u_long128 m, d, w;
    asm("vmul.xyz %0, %1, %1" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(a));
    asm("qmtc2.i %1, $vf1" "\n\t" "vmaddz.x $vf1, $vf1, %2z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(d) : "r"(one), "j"(m));
    return XAxisType(d);
}
static inline XAxisType a234_dot(CGtV3d aa, CGtV3d bb)
{
    u_long128 a = aa.mData, b = bb.mData;
    u_long128 one = a210_one();
    u_long128 m, d, w;
    asm("vmul.xyz %0, %1, %2" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(a), "j"(b));
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    return XAxisType(d);
}
static inline CGtV3d a234_sub(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vsub.xyz %0, %2, %1" : "=j"(t) : "j"(b.mData), "j"(a.mData)); return CGtV3d(t); }
static inline float a234_rsq(u_long128 s) { u_long128 t; asm("vmulw.w $vf1, %1, %1w" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "j"(s)); return WAxisType(t); }
}
struct UnkStruct_00272A30_pad { int x[4]; UnkStruct_00272A30_pad() {} ~UnkStruct_00272A30_pad() {} };
struct CGtLine { CGtV3d field_0; CGtV3d field_10; };
struct UnkStruct_00272A30_s { CGtSphere field_0; CGtV3d field_10; };
extern "C" int IntersectLine__14GtIntersectionFRC7CGtLineQ29GtMathPs29CGtSphere(const CGtLine *, const CGtSphere *);
class CB3SpatialTrigger { public:
    UnkStruct_00272A30_s *field_0;
    bool TestLine(const CGtLine &line);
};
// 0x00272A30
bool CB3SpatialTrigger::TestLine(const CGtLine &line)
{
    UnkStruct_00272A30_pad pa7;
    CGtV3d diff;
    UnkStruct_00272A30_pad pa0;
    UnkStruct_00272A30_pad pa1;
    UnkStruct_00272A30_pad pa2;
    UnkStruct_00272A30_pad pa3;
    UnkStruct_00272A30_pad pa4;
    UnkStruct_00272A30_pad pa5;
    UnkStruct_00272A30_pad pa6;
    UnkStruct_00272A30_pad pa8;
    UnkStruct_00272A30_pad pa9;
    if (a234_sqlen_rt(a234_sub(line.field_10, line.field_0)) < 2.3283064e-10f) {
        const CGtSphere &sp = field_0->field_0;
        diff = sp.Position() - line.field_10;
        if (a234_sqlen(diff) <= a234_rsq(sp.mData)) {} else return false;
    } else {
        if (IntersectLine__14GtIntersectionFRC7CGtLineQ29GtMathPs29CGtSphere(&line, &field_0->field_0) == 0) return false;
        diff = field_0->field_0.Position() - line.field_10;
    }
    if (DotProduct(diff, field_0->field_10) < 0.0f) return true;
    return false;
}



