// NONMATCHING: CalcSeparationAcrossTrack__8CB3AICarFP10CB3RaceCar -- retail 56 / ours 56 instructions, 3 in changed runs
// pass2a: 5 -> 3. DotProduct result to float through a local mtc1 (no operator-float slot) gives retail's 0x40 frame; left: dir at sp+0x10 vs retail sp+0 (GetSquaredLength operator-float temp sits below dir; removing it via local mtc1 shrinks the frame but changes the schedule)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: CalcSeparationAcrossTrack__8CB3AICarFP10CB3RaceCar -- retail 56 / ours 56 instructions, 5 in changed runs
// near30: 22 -> 5 by cloning the matched CalcSeparationAlongTrack (safe-normalise static inline with by-value fwd, GtMath::Abs); every instruction identical, frame only: ours 0x50 with dir at sp+0x10, retail 0x40 with dir at sp+0 (one dead slot too many below dir)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// NONMATCHING: CalcSeparationAlongTrack__8CB3AICarFP10CB3RaceCar -- retail 57 / ours 57 instructions, 5 in changed runs
// near20: 21 -> 5, every instruction identical, frame only (ours 0x60, retail 0x50; dir at 0x30 vs retail 0x10). Header SetY/GetSquaredLength/DotProduct + 3 local [L] N185 stand-ins (compiler-chosen vsub with the result on o's register, XAxisType unary minus, Normalise in place on a compiler-chosen VF). fwd declared before d puts d at retail's 0x40. Slot sources found: fwd.SetY (member call takes fwd's address) and the condition's GetSquaredLength operator-float temp each add one 16-byte slot; retail has one temp below dir and two slots between d and dir.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
class CB3RaceCar { public: unsigned char pad_0[0x30]; CGtV3d field_30; };
class CB3AICar {
public:
    float CalcSeparationAcrossTrack(CB3RaceCar *p0);
    CGtV3d field_0;
    unsigned char pad_10[0x20];
    CGtV3d field_30;
};
// [L] N185 stand-ins (no header API yet): compiler-chosen vsub with the result on the other operand's register (v296),
// XAxisType unary minus (Revenge stabs list it; B3 header lacks it), Normalise with the vector on a compiler-chosen register.
static inline CGtV3d near20_sub(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData));
    return CGtV3d(r);
}
static inline XAxisType near20_neg(XAxisType a)
{
    u_long128 t;
    asm("qmtc2.i %1, $vf1" "\n\t" "vsub.x $vf1, $vf0, $vf1" "\n\t" "qmfc2.i %0, $vf1" : "=r"(t) : "r"(a.lVector));
    return XAxisType(t);
}
static inline void near20_norm(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 t;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(v.mData));
    asm(".set reorder");
    v.mData = t;
}
static inline float a210_abs(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline CGtV3d func_00141AE0_inl1(CGtV3d fwd, const CGtV3d &alt)
{
    CGtV3d dir;
    if (!(fwd.GetSquaredLength() < 2.3283064e-10f)) {
        near20_norm(fwd);
        dir = fwd;
    } else {
        dir = alt;
    }
    return dir;
}
float CB3AICar::CalcSeparationAcrossTrack(CB3RaceCar *p0)
{
    CGtV3d fwd = field_0;
    CGtV3d d = near20_sub(field_30, p0->field_30);
    d.SetY(0.0f);
    fwd.SetY(0.0f);
    XAxisType x = DotProduct(d, func_00141AE0_inl1(fwd, field_0));
    float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector));
    return GtMath::Abs(f);
}

