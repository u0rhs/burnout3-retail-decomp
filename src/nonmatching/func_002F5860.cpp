// NONMATCHING: func_002F5860 -- retail 149 / ours 101 instructions, 195 in changed runs
// draftAN fork B C-first: [L] cubic Hermite point for the proven caller func_002F4F90: rows (p0, p1, tangent0, tangent1; w 0) -> G = H x G with the sinit-built basis rows D_004C4290..C0 ((2,-2,1,1), (-3,3,-2,-1), (0,0,1,0), (1,0,0,0)), point = (t^3, t^2, t, 1) . G; 101/149, calls identical (none): retail copies H x G back into G with three 16-byte byte loops (a struct copy) that b119p does as quads
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: the row order (p0 row0, p1 row1, a row2, b row3 by their qmtc2 into the ACC chain), the basis values from func_004D6C10, the (t^3, t^2, t, 1) lanes and the xyz-only result traced; behaviour_audit: only retail's three 16-byte byte-copy loops (G = H x G struct copy; same bytes)

// func_002F5860 -- draftAN fork B (C-first draft). 0x2F5860, 0x254. Unnamed in every table, so a placeholder with C linkage.
// Caller: the proven func_002F4F90 (src/b3/_unclassified/func_002F4F90.cpp, its declaration and argument list: CGtV3d returned
// through the hidden pointer in a0, self in a1 unread, then p0, tangent0 (pre-scaled by the segment length), p1, tangent1, t in f12).
// What it does [L]: a cubic Hermite point. The four inputs become the rows (w = 0) of a geometry matrix G; G = H x G with the basis
// rows D_004C4290 (2,-2,1,1), D_004C42A0 (-3,3,-2,-1), D_004C42B0 (0,0,1,0), D_004C42C0 (1,0,0,0) ([C] set by the sinit
// func_004D6C10); then point = (t^3, t^2, t, 1) . G, i.e. (2p0 - 2p1 + a + b) t^3 + (-3p0 + 3p1 - 2a - b) t^2 + a t + p0.
// [L] a CGtMatrix4x4 product (E map names the class; no header yet): written with a local 4-row struct. [C] the result's w lane is
// never set (a stack value); the copy of H x G into G goes through 16-byte byte-copy loops in retail (a struct copy).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_002F5860_m {               // [L] GtMathPs2::CGtMatrix4x4 (4 rows)
    CGtV4d field_0[4];
};
extern const CGtV4d D_004C4290;             // Hermite basis rows (sinit func_004D6C10); retail lui/%lo each
extern const CGtV4d D_004C42A0;
extern const CGtV4d D_004C42B0;
extern const CGtV4d D_004C42C0;

// [G] stand-in: k.x * m0 + k.y * m1 + k.z * m2 + k.w * m3 (retail's vmulax/vmadday/vmaddaz/vmaddw.xyzw chain)
static inline CGtV4d func_002F5860_inl1(const UnkStruct_002F5860_m &m, const CGtV4d &k)
{
    u_long128 r;
    asm("vmulax.xyzw $ACC, %1, %5x" "\n\t" "vmadday.xyzw $ACC, %2, %5y" "\n\t" "vmaddaz.xyzw $ACC, %3, %5z" "\n\t"
        "vmaddw.xyzw %0, %4, %5w"
        : "=j"(r) : "j"(m.field_0[0].mData), "j"(m.field_0[1].mData), "j"(m.field_0[2].mData), "j"(m.field_0[3].mData), "j"(k.mData));
    return CGtV4d(r);
}
// [G] a CGtV4d row from a point: xyz copied, w = 0
static inline CGtV4d func_002F5860_inl2(const CGtV3d &v)
{
    CGtV4d r;
    r.SetX(v.X());
    r.SetY(v.Y());
    r.SetZ(v.Z());
    r.SetA(0.0f);
    return r;
}

// 0x002F5860
extern "C" CGtV3d func_002F5860(void *self, const CGtV3d &p0, const CGtV3d &a, const CGtV3d &p1, const CGtV3d &b, float t)
{
    UnkStruct_002F5860_m g;
    g.field_0[0] = func_002F5860_inl2(p0);
    g.field_0[2] = func_002F5860_inl2(a);
    g.field_0[1] = func_002F5860_inl2(p1);
    g.field_0[3] = func_002F5860_inl2(b);
    UnkStruct_002F5860_m hg;
    hg.field_0[0] = func_002F5860_inl1(g, D_004C4290);
    hg.field_0[1] = func_002F5860_inl1(g, D_004C42A0);
    hg.field_0[2] = func_002F5860_inl1(g, D_004C42B0);
    hg.field_0[3] = func_002F5860_inl1(g, D_004C42C0);
    g = hg;
    float t2 = t * t;
    float t3 = t * t2;
    CGtV4d T;
    T.SetX(t3);
    T.SetY(t2);
    T.SetZ(t);
    T.SetA(1.0f);
    CGtV4d p = func_002F5860_inl1(g, T);
    CGtV3d r;
    r.SetX(p.X());
    r.SetY(p.Y());
    r.SetZ(p.Z());
    return r;
}
