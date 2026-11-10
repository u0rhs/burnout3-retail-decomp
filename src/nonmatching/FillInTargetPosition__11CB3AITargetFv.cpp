// NONMATCHING: FillInTargetPosition__11CB3AITargetFv -- retail 271 / ours 271 instructions, 31 in changed runs
// psweep: scoped #pragma opt_propagation off [G] improves 35 -> 31
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: FillInTargetPosition__11CB3AITargetFv -- retail 271 / ours 271 instructions, 2 in changed runs
// pass3b: plain if/else forms (== / != arm order, break inside arm, default case added) all leave the one dead epilogue 'ld ra' (272/271); 'return' inside the avg arm gives the archived fall-through shape. Retail moved (not copied) the ld ra into the relay stub's delay slot.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// v299: 271/271, 2 changed: retail's out-of-line GetAvgForwardsVector arm ends 'b <break stub>' and its epilogue has no ld ra; ours falls into the epilogue. The plain if/else form (build/vt/hand/FillInTargetPosition__11CB3AITargetFv_v299fx1.cpp) is 272/271 with 1 changed: only a dead epilogue ld ra that retail deletes after the delay-slot fill (pragma sweep: none helps). Key fixes: point indices read straight through t->field_1D4->field_4->field_0[seg] (no element pointer), vector work one inline level below the GetLeftFrac copy temp, N140 pad per inlined copy, [L] N185 stand-ins (compiler-chosen vsub, in-place Normalise ending qmfc2 in its region, hard-coded operator*(float) with the scalar qmtc2.ni first).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_propagation off
using namespace GtMathPs2;

struct UnkStruct_0014C5E0_s { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_0014C5E0_r { unsigned char pad_0[0x204]; UnkStruct_0014C5E0_s *field_204; };
struct UnkStruct_0014C5E0_o { unsigned char pad_0[0x2430]; UnkStruct_0014C5E0_r *field_2430; };
struct UnkStruct_0014C5E0_p { unsigned short field_0[2]; };
struct CB3AILaneStruct { UnkStruct_0014C5E0_p *field_0; };
class CB3AILane { public: unsigned char pad_0[4]; CB3AILaneStruct *field_4; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x2C]; CB3AILane field_2C[1]; };
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0064D354 { CGtV3d *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D354 D_0064D354;
extern "C" {
float GetLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3df(CB3AILane *, unsigned short, CGtV3d, float);
float GetWidth__9CB3AILaneCFUs(CB3AILane *, unsigned short);
void GetAvgForwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(CB3AILane *, unsigned short, CGtV3d *);
}
class CB3AITarget {
public:
    void FillInTargetPosition();
    unsigned char pad_0[4];
    UnkStruct_0014C5E0_o *field_4;
    unsigned char pad_8[0x1CC];
    CB3AILane *field_1D4;
    unsigned short field_1D8;
    unsigned char pad_1DA[0x1E];
    int field_1F8;
    int field_1FC;
    CGtV3d field_200;
    unsigned short field_210;
    unsigned char pad_212[2];
    unsigned short field_214;
    unsigned short field_216;
    unsigned short field_218;
    unsigned char pad_21A[6];
    CGtV3d field_220;
    CGtV3d field_230;
    CGtV3d field_240;
    CGtV3d field_250;
    unsigned char pad_260;
    unsigned char field_261;
    unsigned char field_262;
    unsigned char pad_263[3];
    unsigned short field_266;
    unsigned short field_268;
    unsigned char pad_26A[6];
    int field_270;
};
// [L] N185: stands in for an in-place Normalise on a compiler-chosen register (retail `vmulq.xyz $vf4,$vf4,$Q`)
static inline void func_0014C5E0_inl2(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    u_long128 o;
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2 %0, %1" : "=r"(o), "+j"(v.mData));
    asm(".set reorder");
    v.mData = o;
}
// [L] N185: stands in for the hard-coded CGtV3d::operator*(float) body (v288)
static inline CGtV3d func_0014C5E0_inl3(CGtV3d v, float s)
{
    u_long128 t;
    asm("qmtc2.ni %0, $vf2" : : "r"(s));
    asm("qmtc2 %1, $vf1" "\n\t" "vmulx.xyz $vf1, $vf1, $vf2x" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(v.mData));
    return CGtV3d(t);
}
// [L] N185: compiler-chosen vsub (retail `vsub.xyz $vf4, $vf1, $vf3`)
static inline CGtV3d func_0014C5E0_inl4(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}
// [G] N140 pad: an unused 16-byte frame slot retail keeps in each inlined copy
struct UnkStruct_0014C5E0_pad { int x[4]; UnkStruct_0014C5E0_pad() {} ~UnkStruct_0014C5E0_pad() {} };
static inline void func_0014C5E0_inl6(CB3AITarget *t, unsigned short seg, float s)
{
    UnkStruct_0014C5E0_pad pad;
    CGtV3d *pts = D_0064D354.field_0;
    CGtV3d a = pts[t->field_1D4->field_4->field_0[seg].field_0[0]];
    CGtV3d b = pts[t->field_1D4->field_4->field_0[seg].field_0[1]];
UnkStruct_0014C5E0_pad pq;
    CGtV3d d;
    d = func_0014C5E0_inl4(b, a);
    func_0014C5E0_inl2(d);
    CGtV3d r = func_0014C5E0_inl3(d, s);
    r += a;
    t->field_200 = r;
}
static inline void func_0014C5E0_inl1(CB3AITarget *t)
{
    unsigned short seg = t->field_210;
    t->field_261 = 0xFF;
    t->field_266 = 0xFFFF;
    t->field_270 = 16;
    float f = GtMath::Min(GtMath::Max(GetLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3df(t->field_1D4, t->field_1D8, t->field_4->field_2430->field_204->field_30, 0.0f), 0.4f), 0.6f);
    func_0014C5E0_inl6(t, seg, f * GetWidth__9CB3AILaneCFUs(t->field_1D4, seg));
}
// 0x0014C5E0
void CB3AITarget::FillInTargetPosition()
{
    if (field_1FC == 0) {
        switch (field_1F8) {
        case 0:
            field_200 = field_220;
            field_210 = field_214;
            break;
        case 1:
            field_200 = field_230;
            field_210 = field_216;
            break;
        case 2:
            field_200 = field_240;
            field_210 = field_218;
            if (field_262 != 0xFF) goto avg;
            field_250.Zero();
            break;
        }
    } else {
        switch (field_1F8) {
        case 0:
            field_210 = field_214;
            func_0014C5E0_inl1(this);
            break;
        case 1:
            field_210 = field_216;
            func_0014C5E0_inl1(this);
            break;
        case 2:
            field_210 = field_218;
            func_0014C5E0_inl1(this);
            break;
        }
    }
    return;
avg:
    GetAvgForwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(&D_00522660.field_2C[field_262], field_268, &field_250);
    field_250.Normalise();
}

#pragma pop
