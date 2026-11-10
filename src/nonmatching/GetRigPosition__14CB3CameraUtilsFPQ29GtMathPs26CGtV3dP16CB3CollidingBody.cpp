// NONMATCHING: GetRigPosition__14CB3CameraUtilsFPQ29GtMathPs26CGtV3dP16CB3CollidingBody -- retail 119 / ours 119 instructions, 34 in changed runs
// ghvu5: logic + block layout right (GetPositionAtParam's proven lerp inlined twice, closest point on the edge line). Left (34): VU numbering one higher than retail (retail reuses vf3 for the parked 1.0, p0 and d; ours one=vf1, p0=vf1, pos=vf6), lane/seg saved registers swapped (s1/s3; declaration order/assignment order no effect), frame 0xD0 vs 0x110 (lerp copies at 0xA0/0xD0 in retail with dead slots between; N140 pads per sibling).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3CameraUtils::GetRigPosition(GtMathPs2::CGtV3d*, CB3CollidingBody*) -- hand-written (ghvu5, Ghidra draft).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3CameraUtils.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
// [G] the body's position projected onto the line between two interpolated lane edges (closest point).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_002F64E0_e0 { unsigned short field_0[2]; };
struct CB3AILaneStruct { UnkStruct_002F64E0_e0 * field_0; };
struct UnkStruct_002F64E0_l { unsigned char pad_0[4]; CB3AILaneStruct * field_4; };
struct UnkStruct_002F64E0_a { unsigned char pad_0[0x18B4]; UnkStruct_002F64E0_l * field_18B4; unsigned short field_18B8; unsigned char pad_18BA[2]; float field_18BC; };
struct UnkStruct_002F64E0_m { unsigned char pad_0[0x30]; CGtV3d field_30; };
class CB3CollidingBody {
public:
    unsigned char pad_0[0x204];
    UnkStruct_002F64E0_m * field_204;
    unsigned char pad_208[0xD];
    signed char field_215;
    unsigned char pad_216[0x11DE];
    UnkStruct_002F64E0_a * field_13F4;
};
struct UnkStruct_002F64E0_e3 { CGtV3d field_0; };
struct UnkStruct_D_0064D354 { UnkStruct_002F64E0_e3 * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_002F64E0_2 { u_long128 field_0; u_long128 field_10; };
extern UnkStruct_D_0064D354 D_0064D354;
extern unsigned char D_004EE040[];
extern "C" int func_00131E40(void *);
// [L] low: CB3AILane::CalculateForwardDistanceInSegment(GtMathPs2::CGtV3d, unsigned short) (config/symbol_addrs_b3names.txt)
extern "C" float func_00148DF0(UnkStruct_002F64E0_l *lane, const CGtV3d *pos, unsigned short seg);
class CB3CameraUtils { public: static void GetRigPosition(CGtV3d *out, CB3CollidingBody *body); };
// [G] N148 stand-in, as proven GetPositionAtParam__14CB3CameraUtils (B3CameraUtils_002F5D40.cpp): a + (b - a) * t
static inline CGtV3d func_002F64E0_inl1(u_long128 a, u_long128 b, float t)
{
    u_long128 s;
    asm("vsub.xyz %0, %0, %1" : "+j"(b) : "j"(a));
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(t));
    asm("vmulx.xyz %0, %1, %0x" : "+j"(s) : "j"(b));
    asm("vadd.xyz %0, %1, %0" : "+j"(s) : "j"(a));
    return CGtV3d(s);
}
// N140 pad as in GetPositionAtParam's proven source: retail's frame has dead slots around the lerp copies [G]
struct UnkStruct_002F64E0_pad { int x[8]; UnkStruct_002F64E0_pad() {} ~UnkStruct_002F64E0_pad() {} };
// [G] GetPositionAtParam's body (lane struct, segment, t, link type) inlined
static inline CGtV3d func_002F64E0_inl2(CB3AILaneStruct *p0, unsigned short p1, float p2, int p3)
{
    UnkStruct_002F64E0_e3 * t1 = D_0064D354.field_0;
    unsigned short t2 = p0->field_0[p1].field_0[p3];
    unsigned short t3 = p0->field_0[(p1 + 1)].field_0[p3];
    UnkStruct_002F64E0_2 local;
    UnkStruct_002F64E0_pad pad;
    local.field_0 = t1[t2].field_0.mData;
    local.field_10 = t1[t3].field_0.mData;
    return func_002F64E0_inl1(local.field_0, local.field_10, p2);
}
// [L] N185: CGtV3d subtraction on compiler-chosen registers
static inline CGtV3d func_002F64E0_inl3(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
static inline CGtV3d func_002F64E0_inl4(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
// [L] N185: Normalise in place on a compiler-chosen register (retail `vmulq.xyz $vf3,$vf3,$Q`; the header's is on $vf1)
static inline void func_002F64E0_inl5(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData));
    asm(".set reorder");
}
// [L] N185: CGtV3d::operator*(XAxisType) (B3O0PCH map)
static inline CGtV3d func_002F64E0_inl6(const CGtV3d &v, XAxisType s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s.lVector)); return CGtV3d(t); }
// 0x002F64E0
void CB3CameraUtils::GetRigPosition(CGtV3d *out, CB3CollidingBody *body)
{
    UnkStruct_002F64E0_m *m = body->field_204;
    int st;
    if (func_00131E40(D_004EE040) != 0) goto other;
    st = body->field_215;
    if (st == 1) goto go;
    if (st == 2) goto go;
    if (st != 3) goto other;
go:
    {
        UnkStruct_002F64E0_a *a = body->field_13F4;
        unsigned short seg = a->field_18B8;
        UnkStruct_002F64E0_l *lane = a->field_18B4;
        float t;
        if (st == 1) t = a->field_18BC;
        else t = func_00148DF0(lane, &m->field_30, seg);
        CGtV3d p0 = func_002F64E0_inl2(lane->field_4, seg, t, 0);
        CGtV3d p1 = func_002F64E0_inl2(lane->field_4, seg, t, 1);
        CGtV3d d = func_002F64E0_inl3(p1, p0);
        CGtV3d r = func_002F64E0_inl3(m->field_30, p0);
        func_002F64E0_inl5(d);
        *out = func_002F64E0_inl4(p0, func_002F64E0_inl6(d, DotProduct(d, r)));
    }
    goto done;
other:
    *out = m->field_30;
done:
    return;
}


