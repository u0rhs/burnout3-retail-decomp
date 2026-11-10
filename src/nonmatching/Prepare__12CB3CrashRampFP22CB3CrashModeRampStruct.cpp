// NONMATCHING: Prepare__12CB3CrashRampFP22CB3CrashModeRampStruct -- retail 133 / ours 133 instructions, 90 in changed runs
// ghvu7: logic, block layout (if/else-if chain) and FP registers (decl b,d,c,a) right; 133/133, 90 changed = VU register allocation only (retail adds in place on the v3 load for outputs 0-3, on the product for 4-5; scalar/v3 numbering swapped). Stand-in signatures, operand order, compound += forms, in-place product: no effect or worse
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3CrashRamp::Prepare(CB3CrashModeRampStruct*) -- hand-written (ghvu7) from the Ghidra draft. [C] name: the mangled
// symbol in retail's tables. Field names are placeholders and every type is [G]. The six outputs are the ramp's corner
// points (field_30 +/- field_20*b +/- field_0*a, the last two + field_10*c/d) [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct CB3CrashModeRampStruct {
    CGtV3d field_0;
    CGtV3d field_10;
    CGtV3d field_20;
    CGtV3d field_30;
    int field_40;
};

// [L] N185: CGtV3d::operator+/-(const CGtV3d&) on compiler-chosen registers (stand-ins; the header's hard-code $vf1/$vf2).
static inline CGtV3d func_003A1EB0_inl1(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_003A1EB0_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }

class CB3CrashRamp {
public:
    CGtV3d field_0[6];
    CB3CrashModeRampStruct *field_60;
    bool Prepare(CB3CrashModeRampStruct *);
};

// 0x003A1EB0
bool CB3CrashRamp::Prepare(CB3CrashModeRampStruct *ramp)
{
    float b, d, c, a;
    field_60 = ramp;
    int t = field_60->field_40;
    if (t == 0) {
        d = 1.2f;
        b = 4.0f;
        a = 3.0f;
        c = d;
    } else if (t == 1) {
        b = 6.0f;
        d = 3.0f;
        a = 4.0f;
        c = d;
    } else if (t == 2) {
        b = 7.0f;
        a = 2.55f;
        d = 1.0f;
        c = 3.2f;
    } else if (t == 3) {
        d = 3.2f;
        b = 7.0f;
        a = 2.55f;
        c = 1.0f;
    }
    field_0[0] = func_003A1EB0_inl2(func_003A1EB0_inl1(field_60->field_30, field_60->field_20 * b), field_60->field_0 * a);
    field_0[1] = func_003A1EB0_inl1(func_003A1EB0_inl1(field_60->field_30, field_60->field_20 * b), field_60->field_0 * a);
    field_0[2] = func_003A1EB0_inl2(func_003A1EB0_inl2(field_60->field_30, field_60->field_20 * b), field_60->field_0 * a);
    field_0[3] = func_003A1EB0_inl1(func_003A1EB0_inl2(field_60->field_30, field_60->field_20 * b), field_60->field_0 * a);
    field_0[4] = func_003A1EB0_inl1(func_003A1EB0_inl2(func_003A1EB0_inl1(field_60->field_30, field_60->field_20 * b), field_60->field_0 * a), field_60->field_10 * c);
    field_0[5] = func_003A1EB0_inl1(func_003A1EB0_inl1(func_003A1EB0_inl1(field_60->field_30, field_60->field_20 * b), field_60->field_0 * a), field_60->field_10 * d);
    return true;
}
