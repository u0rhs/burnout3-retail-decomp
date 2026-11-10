// NONMATCHING: func_003D9360 -- retail 247 / ours 249 instructions, 157 in changed runs
// v301: logic decoded (CB3ConvexHullMaker helper: max-Y scans, top points 8..11 from vertices 12..15, z clamps +/-0.03, SetY, x projected onto base edges); 247/249: frame 0x680 vs 0x990 (retail ~27 dead 16-byte slots per x-projection block -> by-value axis-type temporaries our N185 lane-operator stand-ins don't create), retail loads p8/p0/p1 in that order and does not CSE p8 for the outer X(); lane ops Z-float, Z-Z, X-X, X+float, X+X are missing header APIs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003D9360 -- hand-written (lifter refused). [L] a CB3ConvexHullMaker helper: its only caller is
// CB3ConvexHullMaker::MakeConvexHull (0x3D8D60), which passes `this` and the 12-point CGtV3d buffer GetBasePoints filled.
// Raises the four top points (8..11) from the maker's vertices 12..15, clamps their z just outside the base edge
// (points 0..3, 0.03 margin), sets their y to the highest y among vertices 0..15 and points 0..7 (at least -0.3),
// then moves each one's x onto the base edge line (0-1 or 2-3) at its z.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV3d;
using GtMathPs2::XAxisType;
using GtMathPs2::ZAxisType;

// [G] the maker's vertex records (32 bytes; position first).
struct UnkStruct_003D9360_vtx {
    CGtV3d field_0;
    unsigned char pad_10[0x10];
};
// [L] CB3ConvexHullMaker: field_0 is its vertex array (CB3ConvexHullMaker.h).
struct UnkStruct_003D9360 {
    UnkStruct_003D9360_vtx *field_0;
};

// [L] N185: stand-ins for missing GtMathPs2 lane operators (ZAxisType -/+ float, Z - Z, X - X, X + float, X + X), in the
// header's YAxisType style (scalar moved by its own statement; compiler-chosen registers).
static inline ZAxisType operator-(ZAxisType a, float f) {
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vsubx.z %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return ZAxisType(r);
}
static inline ZAxisType operator+(ZAxisType a, float f) {
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.z %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return ZAxisType(r);
}
static inline ZAxisType operator-(ZAxisType a, ZAxisType b) {
    u_long128 r;
    asm("vsubz.z %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector));
    return ZAxisType(r);
}
static inline XAxisType operator-(XAxisType a, XAxisType b) {
    u_long128 r;
    asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector));
    return XAxisType(r);
}
static inline XAxisType operator+(XAxisType a, float f) {
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return XAxisType(r);
}
static inline XAxisType operator+(XAxisType a, XAxisType b) {
    u_long128 r;
    asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector));
    return XAxisType(r);
}

// 0x003D9360
extern "C" void func_003D9360(UnkStruct_003D9360 *self, CGtV3d *pts)
{
    float m = -0.3f;
    int i;
    for (i = 0; i < 16; i++)
        m = GtMath::Max(m, self->field_0[i].field_0.Y());
    for (i = 0; i < 8; i++)
        m = GtMath::Max(m, pts[i].Y());
    float c = 0.03f;
    pts[8] = self->field_0[12].field_0;
    pts[10] = self->field_0[13].field_0;
    pts[9] = self->field_0[14].field_0;
    pts[11] = self->field_0[15].field_0;
    pts[8].SetZ(GtMath::Min(pts[8].Z(), pts[0].Z() - c));
    pts[10].SetZ(GtMath::Min(pts[10].Z(), pts[2].Z() - c));
    pts[9].SetZ(GtMath::Max(pts[9].Z(), pts[1].Z() + c));
    pts[11].SetZ(GtMath::Max(pts[11].Z(), pts[3].Z() + c));
    pts[8].SetY(m);
    pts[9].SetY(m);
    pts[10].SetY(m);
    pts[11].SetY(m);
    {
        ZAxisType dz1 = pts[8].Z() - pts[0].Z();
        XAxisType dx0 = pts[0].X() - pts[8].X();
        ZAxisType dz2 = pts[1].Z() - pts[0].Z();
        XAxisType dx = pts[1].X() - pts[0].X();
        XAxisType ox = pts[8].X();
        pts[8].SetX(ox + (dx0 + dx * dz1 / dz2));
    }
    {
        ZAxisType dz1 = pts[9].Z() - pts[0].Z();
        XAxisType dx0 = pts[0].X() - pts[9].X();
        ZAxisType dz2 = pts[1].Z() - pts[0].Z();
        XAxisType dx = pts[1].X() - pts[0].X();
        XAxisType ox = pts[9].X();
        pts[9].SetX(ox + (dx0 + dx * dz1 / dz2));
    }
    {
        ZAxisType dz1 = pts[10].Z() - pts[2].Z();
        XAxisType dx0 = pts[2].X() - pts[10].X();
        ZAxisType dz2 = pts[3].Z() - pts[2].Z();
        XAxisType dx = pts[3].X() - pts[2].X();
        XAxisType ox = self->field_0[13].field_0.X();
        pts[10].SetX(ox + (dx0 + dx * dz1 / dz2));
    }
    {
        ZAxisType dz1 = pts[11].Z() - pts[2].Z();
        XAxisType dx0 = pts[2].X() - pts[11].X();
        ZAxisType dz2 = pts[3].Z() - pts[2].Z();
        XAxisType dx = pts[3].X() - pts[2].X();
        XAxisType ox = self->field_0[15].field_0.X();
        pts[11].SetX(ox + (dx0 + dx * dz1 / dz2));
    }
}

