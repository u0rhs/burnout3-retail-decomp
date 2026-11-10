// NONMATCHING: IntersectLineSegment__14CB3TrafficAxleFv -- retail 143 / ours 143 instructions, 73 in changed runs
// retune1 (N239): pad 0x140->0x150 gives exact frame 0x1E0; 87 -> 73
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: IntersectLineSegment__14CB3TrafficAxleFv -- retail 143 / ours 143 instructions, 74 in changed runs
// 74 off; logic believed right (two IntersectLineTriangle tries, n = (p2-p0)+(p3-p1) x (p0-p1)+(p2-p3) NormaliseGetLength, Set(0,1,0) if length 0, sphere y += up.y*(radius + 10-20t), up = n), frame exact with a 0x100 N140 pad. Left: vertex-pointer s-register order / index load order, VU numbering of the 4 vsubs and 2 vadds (retail vf6/vf2/vf3/vf1), FP constant registers. Stand-ins: compiler-chosen vadd/vsub, WAxisType+float, YAxisType*WAxisType, NormaliseGetLength scaling the vector's own register
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3TrafficAxle::IntersectLineSegment -- hand-matched (ghvu8).
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

// [G] the probe segment passed to IntersectLineTriangle (a CGtLine: two points)
struct UnkStruct_0015F410_line {
    CGtV3d field_0;
    CGtV3d field_10;
};

// [G] N140: one 0x140-byte pad standing in for retail's twenty dead 16-byte frame slots (inline temporaries)
struct UnkStruct_0015F410_pad { int x[68]; UnkStruct_0015F410_pad() {} ~UnkStruct_0015F410_pad() {} };

class CB3TrafficAxle {
public:
    bool IntersectLineSegment(); // returns the hit in v0 [C 0x15F4BC / 0x15F5F8 andi v0, v0, 0xFF; 0 at .L0015F62C; read by AdjustAxleHeight 0x15F7D8 bnez v0]
    CGtSphere field_0;
    CGtV3d field_10;
    unsigned short field_20[4];
    CGtV3d *field_28;
};

// [G] by-pointer link-name call: retail passes the vertices' own addresses (no by-value copies)
extern "C" bool IntersectLineTriangle__14GtIntersectionFRC7CGtLineQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPfPfPf(
    const UnkStruct_0015F410_line *, const CGtV3d *, const CGtV3d *, const CGtV3d *, float *, float *, float *);

// [L] N185: CGtV3d + CGtV3d on compiler-chosen registers (the header's hard-codes $vf1/$vf2)
static inline CGtV3d IntersectLineSegment_inl1(const CGtV3d &a, CGtV3d b) {
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185: WAxisType + float
static inline WAxisType IntersectLineSegment_inl2(WAxisType a, float f) {
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.w %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return WAxisType(r);
}
// [L] N185: YAxisType * WAxisType
static inline YAxisType IntersectLineSegment_inl3(YAxisType a, WAxisType b) {
    u_long128 r;
    asm("vmulw.y %0, %1, %2w" : "=j"(r) : "j"(a.lVector), "j"(b.lVector));
    return YAxisType(r);
}
// [L] N185: CGtV3d::NormaliseGetLength with the scale on the vector's own (compiler-chosen) register
static inline XAxisType IntersectLineSegment_inl4(CGtV3d &v) {
    XAxisType l = v.GetSquaredLength();
    u_long128 t, r;
    float f;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "qmfc2 %1, $vf1" "\n\t" "mtc1 %1, %2" "\n\t" "sqrt.s %2, %2" "\n\t" "mfc1 %1, %2" "\n\t"
        "qmtc2 %1, $vf1" "\n\t" "qmfc2 %1, $vf1" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %3, %3, $Q" "\n\t"
        "qmfc2 %0, %3" "\n\t" ".set reorder" : "=r"(t), "=&r"(r), "=&f"(f) : "j"(v.mData));
    asm(".set reorder");
    v.mData = t;
    return XAxisType(r);
}

// [L] N185: CGtV3d - CGtV3d on compiler-chosen registers (the header's goes through $vf1/$vf2 and GPRs)
static inline CGtV3d IntersectLineSegment_inl5(const CGtV3d &a, const CGtV3d &b) {
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}

// 0x0015F410
bool CB3TrafficAxle::IntersectLineSegment()
{
    float t;
    float u;
    float v;
    UnkStruct_0015F410_line line;
    CGtV3d n;
    UnkStruct_0015F410_pad pad;
    CGtV3d *p1;
    CGtV3d *p0;
    CGtV3d *p3;
    CGtV3d *p2;
    p2 = &field_28[field_20[2]];
    p3 = &field_28[field_20[3]];
    p0 = &field_28[field_20[0]];
    p1 = &field_28[field_20[1]];
    line.field_0 = IntersectLineSegment_inl1(field_0.Position(), field_10 * 10.0f);
    line.field_10 = IntersectLineSegment_inl1(field_0.Position(), field_10 * -10.0f);
    bool hit = IntersectLineTriangle__14GtIntersectionFRC7CGtLineQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPfPfPf(&line, p0, p1, p2, &t, &u, &v);
    if (!hit) {
        hit = IntersectLineTriangle__14GtIntersectionFRC7CGtLineQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPfPfPf(&line, p2, p1, p3, &t, &u, &v);
    }
    if (hit) {
        float s = 10.0f + 2.0f * (-10.0f * t);
        n = CrossProduct(IntersectLineSegment_inl1(IntersectLineSegment_inl5(*p2, *p0), IntersectLineSegment_inl5(*p3, *p1)),
                         IntersectLineSegment_inl1(IntersectLineSegment_inl5(*p0, *p1), IntersectLineSegment_inl5(*p2, *p3)));
        float len = IntersectLineSegment_inl4(n);
        if (len == 0.0f) {
            n.Set(0.0f, 1.0f, 0.0f);
        }
        CGtV3d p = field_0.Position();
        p.SetY(p.Y() + IntersectLineSegment_inl3(field_10.Y(), IntersectLineSegment_inl2(field_0.Radius(), s)));
        field_0.SetPosition(p);
        field_10 = n;
    }
    return hit;
}
