// NONMATCHING: CalculateCarPositionInMap__17CB3AIAvoidanceMapFb -- retail 245 / ours 247 instructions, 25 in changed runs
// psweep: scoped #pragma opt_lifetimes off [G] improves 44 -> 33
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3AIAvoidanceMap::CalculateCarPositionInMap(bool) -- hand-written (v296); the lifter refused it.
// [C] name: the mangled symbol in retail's tables. The bool parameter is unused (a1 never read).
// Field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_lifetimes off
using namespace GtMathPs2;

enum EAISegmentLinkType {};
struct UnkStruct_0013D530_e {
    unsigned char pad_0[4];
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct UnkStruct_0013D530_p {
    unsigned short field_0;
    unsigned short field_2;
};
struct CB3AILaneStruct {
    UnkStruct_0013D530_p *field_0;
    unsigned char pad_4[4];
    UnkStruct_0013D530_e *field_8;
};
class CB3AILane {
public:
    CB3AILane *FindSideLane(unsigned short *, EAISegmentLinkType);
    unsigned char pad_0[4];
    CB3AILaneStruct *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0064D354 {
    CGtV3d *field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_0064D354 D_0064D354;
extern CGtV3d kYAxis;
struct UnkStruct_0013D530_m { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_0013D530_c { unsigned char pad_0[0x204]; UnkStruct_0013D530_m *field_204; };
struct UnkStruct_0013D530_o {
    unsigned char pad_0[0x18B4];
    CB3AILane *field_18B4;
    unsigned short field_18B8;
    unsigned char pad_18BA[2];
    float field_18BC;
    unsigned char pad_18C0[0x10];
    CGtV3d field_18D0;
    unsigned char pad_18E0[0xB50];
    UnkStruct_0013D530_c *field_2430;
};
// [L] N185: stands in for a missing GtMathPs2 inline (XAxisType unary minus: `vsub.x $vf1, $vf0, $vf1`)
static inline XAxisType v296_neg(XAxisType a)
{
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "vsub.x $vf1, $vf0, $vf1" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(a.lVector));
    return XAxisType(t);
}
// [L] N185: CrossProduct with the result's qmfc2 kept (.i)
static inline CGtV3d v296_cross(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
// [L] N185: stands in for GtMathPs2::Interpolate(CGtV3d, CGtV3d, float): operands by reference (retail evaluates a first),
// t moved to a GPR in its own statement (scheduled early, as retail), .i moves (fixup restores .ni), no volatile
static inline CGtV3d v296_interpM(const CGtV3d &a, const CGtV3d &b, float t)
{
    u_long128 r, x = a.mData;
    int ti;
    asm("mfc1 %0, %1" : "=r"(ti) : "f"(t));
    asm("vaddax.xyz $ACC, %1, $vf0x" "\n\t" "qmtc2.i %3, $vf2" "\n\t" "vmsubax.xyz $ACC, %1, $vf2x" "\n\t"
        "qmtc2.i %2, %1" "\n\t" "vmaddx.xyz %1, %1, $vf2x" "\n\t" "qmfc2.i %0, %1"
        : "=r"(r), "+j"(x) : "r"(b.mData), "r"(ti));
    return CGtV3d(r);
}
// [L] N185: stands in for a compiler-chosen CGtV3d::operator- (result on o's register, as retail)
static inline CGtV3d v296_s1(CGtV3d a, CGtV3d b)
{
    u_long128 r;
    asm("vsub.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData));
    return CGtV3d(r);
}
// N140 frame-slot pad: an unused local with an empty ctor/dtor reserves one 16-byte slot and emits no code
struct UnkStruct_0013D530_pad { int x[4]; UnkStruct_0013D530_pad() {} ~UnkStruct_0013D530_pad() {} };
class CB3AIAvoidanceMap {
public:
    void CalculateCarPositionInMap(bool);
    CGtV3d field_0;
    CGtV3d field_10;
    CGtV3d field_20;
    CGtV3d field_30;
    unsigned char pad_40[0x404];
    float field_444;
    float field_448;
    float field_44C;
    unsigned char pad_450[4];
    UnkStruct_0013D530_o *field_454;
};

// 0x0013D530
void CB3AIAvoidanceMap::CalculateCarPositionInMap(bool)
{
    // [G] N140: ten unused 16-byte slots (retail frame 0x130)
    UnkStruct_0013D530_pad pad0;
    UnkStruct_0013D530_pad pad1;
    UnkStruct_0013D530_pad pad2;
    UnkStruct_0013D530_pad pad3;
    UnkStruct_0013D530_pad pad4;
    UnkStruct_0013D530_pad pad5;
    UnkStruct_0013D530_pad pad6;
    UnkStruct_0013D530_pad pad7;
    UnkStruct_0013D530_pad pad8;
    UnkStruct_0013D530_pad pad9;
    unsigned short seg = field_454->field_18B8;
    unsigned short s2;
    unsigned char link;
    if (field_454->field_18B4->field_4->field_8[seg].field_4[0] == 0xFF) {
        link = field_454->field_18B4->field_4->field_8[seg].field_4[1];
        s2 = field_454->field_18B4->field_4->field_8[seg].field_6[1];
    } else {
        link = 0xFF;
    }
    CB3AILane *l;
    if (link == 0xFF) {
        l = field_454->field_18B4->FindSideLane(&seg, (EAISegmentLinkType)0);
    } else {
        l = D_00522660.field_2C[link].FindSideLane(&s2, (EAISegmentLinkType)0);
        seg = s2;
    }
    unsigned short a0 = l->field_4->field_0[seg].field_0;
    unsigned short a1 = l->field_4->field_0[seg + 1].field_0;
    seg = field_454->field_18B8;
    if (field_454->field_18B4->field_4->field_8[seg].field_4[1] == 0xFF) {
        link = field_454->field_18B4->field_4->field_8[seg].field_4[0];
        s2 = field_454->field_18B4->field_4->field_8[seg].field_6[0];
    } else {
        link = 0xFF;
    }
    if (link == 0xFF) {
        l = field_454->field_18B4->FindSideLane(&seg, (EAISegmentLinkType)1);
    } else {
        l = D_00522660.field_2C[link].FindSideLane(&s2, (EAISegmentLinkType)1);
        seg = s2;
    }
    unsigned short b0 = l->field_4->field_0[seg].field_2;
    unsigned short b1 = l->field_4->field_0[seg + 1].field_2;
    float t = field_454->field_18BC;
    if (a0 == b0) {
        t = 1.0f;
    } else if (a1 == b1) {
        t = 0.0f;
    }
    field_0 = v296_interpM(D_0064D354.field_0[a0], D_0064D354.field_0[a1], t);
    CGtV3d r = v296_interpM(D_0064D354.field_0[b0], D_0064D354.field_0[b1], t);
    field_10 = r;
    field_30 = v296_s1(field_0, r);
    field_30.SetY(0.0f);
    if (field_30.GetSquaredLength() < 2.3283064e-10f) {
        field_30 = -v296_cross(kYAxis, field_454->field_18D0);
    }
    field_444 = field_30.NormaliseGetLength();
    field_20 = field_454->field_2430->field_204->field_30;
    const CGtV3d &dir = field_30;
    field_44C = DotProduct(v296_s1(field_20, field_10), dir);
    field_448 = v296_neg(DotProduct(v296_s1(field_20, field_0), dir));
}


#pragma pop
