// NONMATCHING: MakeVerticesIntoHull__18CB3ConvexHullMakerFPQ29GtMathPs26CGtV3d -- retail 362 / ours 359 instructions, 192 in changed runs
// ghvu20: logic decoded (12-vertex copy, 20 fixed faces with two convexity tests, per-face plane = normalised cross + distance, edge list); 192 off: frame 0x2F0 vs 0xE0 (retail ~25 dead slots), VU numbering in the two convexity tests (base v10/v5 must be vf2), loop body order (retail normalise block inline, plane copy W read lwc1 0x16C dead), hoisted 1.0s; header CGtV3d types the hull fields int (view struct used)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3ConvexHullMaker::MakeVerticesIntoHull(GtMathPs2::CGtV3d*) -- hand-written (ghvu20, Ghidra draft + retail asm).
// [C] name: the mangled symbol in retail's tables. The hull's layout follows the proven CB3ConvexHull sources
// (B3ConvexHull_002BA420.cpp: faces 3 bytes each at field_0, planes at field_4, vertices at field_8, edges 2 bytes each
// at field_C, counts at 0x18/0x19); the shared header still types those members `int`, so they are read through a
// placeholder view here. Field names are placeholders and every type is [G]. Reading [G]: the 12 points become the
// hull's vertices, 20 fixed faces (two quads split along the diagonal that keeps them convex), then each face's plane
// (normalised cross product, distance = n . first vertex) and its edges (each edge once, from its lower index).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

#include "b3/classes/CB3ConvexHull.h"
#include "b3/classes/CB3ConvexHullMaker.h"

struct UnkStruct_003D8DB0_h {
    unsigned char * field_0;   // [G] face vertex indices, 3 per face
    CGtPlane * field_4;        // [G] face planes
    CGtV3d * field_8;          // [G] vertices
    unsigned char * field_C;   // [G] edge vertex indices, 2 per edge
    unsigned char pad_10[0x4];
    int field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
};

static inline UnkStruct_003D8DB0_h *func_003D8DB0_inl1(CB3ConvexHullMaker *m) { return (UnkStruct_003D8DB0_h *)m->field_4; }
static inline void func_003D8DB0_inl2(unsigned char *f, int a, int b, int c) { f[0] = a; f[1] = b; f[2] = c; }
// [L] N185: a - b on compiler-chosen registers (the header operator- takes its inputs on $vf1/$vf2).
static inline CGtV3d func_003D8DB0_inl3(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185: CrossProduct with a compiler-chosen result register (retail writes it over the first operand's).
static inline CGtV3d func_003D8DB0_inl4(CGtV3d a, CGtV3d b)
{
    u_long128 t, r;
    asm("vopmula.xyz $ACC, %2, %3" "\n\t" "vopmsub.xyz %1, %3, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}
// [L] N185: CrossProduct (header body) with the result moved out `.i` (retail keeps the qmfc2 + qmtc2 round trip, v241).
static inline CGtV3d func_003D8DB0_inl6(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
// [L] N185: normalise in place through 1/sqrt (lst1's in-place tail without the dead 1.0*Q).
static inline void func_003D8DB0_inl5(CGtV3d &d)
{
    XAxisType l = d.GetSquaredLength();
    u_long128 v = d.mData, t;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq");
    asm(".set reorder");
    asm("vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(v));
    d.mData = t;
}

// 0x003D8DB0
void CB3ConvexHullMaker::MakeVerticesIntoHull(CGtV3d *p)
{
    for (int i = 0; i < 12; i++) {
        func_003D8DB0_inl1(this)->field_8[i] = p[i];
    }
    func_003D8DB0_inl1(this)->field_18 = 12;
    func_003D8DB0_inl1(this)->field_19 = (func_003D8DB0_inl1(this)->field_18 - 2) * 2;
    func_003D8DB0_inl1(this)->field_1A = (func_003D8DB0_inl1(this)->field_18 - 2) * 3;
    func_003D8DB0_inl1(this)->field_14 = 0;
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[0], 0, 1, 2);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[3], 8, 10, 9);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[6], 0, 2, 4);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[9], 1, 5, 3);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[12], 0, 4, 8);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[15], 2, 10, 6);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[18], 1, 3, 2);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[21], 4, 2, 6);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[24], 3, 5, 7);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[27], 9, 10, 11);
    CGtV3d *v = func_003D8DB0_inl1(this)->field_8;
    CGtV3d e1 = func_003D8DB0_inl3(v[4], v[10]);
    CGtV3d e2 = func_003D8DB0_inl3(v[8], v[10]);
    CGtV3d c = func_003D8DB0_inl6(e1, e2);
    if (DotProduct(c, func_003D8DB0_inl3(v[6], v[10])) >= 0.0f) {
        func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[30], 4, 6, 8);
        func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[33], 8, 6, 10);
    } else {
        func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[30], 4, 6, 10);
        func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[33], 8, 4, 10);
    }
    v = func_003D8DB0_inl1(this)->field_8;
    if (DotProduct(func_003D8DB0_inl6(func_003D8DB0_inl3(v[11], v[5]), func_003D8DB0_inl3(v[9], v[5])), func_003D8DB0_inl3(v[7], v[5])) >= 0.0f) {
        func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[36], 5, 9, 7);
        func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[39], 7, 9, 11);
    } else {
        func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[36], 5, 9, 11);
        func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[39], 7, 5, 11);
    }
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[42], 0, 8, 1);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[45], 1, 8, 9);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[48], 1, 9, 5);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[51], 2, 3, 10);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[54], 3, 11, 10);
    func_003D8DB0_inl2(&func_003D8DB0_inl1(this)->field_0[57], 3, 7, 11);
    int nEdges = 0;
    int i = 0;
    for (;;) {
        UnkStruct_003D8DB0_h *h = func_003D8DB0_inl1(this);
        if (!(i < h->field_19)) break;
        unsigned char *f = &h->field_0[i * 3];
        CGtV3d *hv = h->field_8;
        int a = f[0];
        CGtV3d n = func_003D8DB0_inl4(func_003D8DB0_inl3(hv[f[2]], hv[a]), func_003D8DB0_inl3(hv[f[1]], hv[a]));
        if (n.GetSquaredLength() >= 2.3283064e-10f) func_003D8DB0_inl5(n);
        h->field_4[i].SetNormal(n);
        func_003D8DB0_inl1(this)->field_4[i].SetDistance(DotProduct(n, func_003D8DB0_inl1(this)->field_8[a]));
        CGtPlane pl = func_003D8DB0_inl1(this)->field_4[i];
        float d = pl.Distance();
        unsigned char *e = &func_003D8DB0_inl1(this)->field_0[i * 3];
        int e0 = e[0];
        int e1 = e[1];
        int e2 = e[2];
        if (e0 < e1) {
            func_003D8DB0_inl1(this)->field_C[nEdges * 2] = e0;
            func_003D8DB0_inl1(this)->field_C[nEdges * 2 + 1] = e1;
            nEdges++;
        }
        if (e1 < e2) {
            func_003D8DB0_inl1(this)->field_C[nEdges * 2] = e1;
            func_003D8DB0_inl1(this)->field_C[nEdges * 2 + 1] = e2;
            nEdges++;
        }
        if (e2 < e0) {
            func_003D8DB0_inl1(this)->field_C[nEdges * 2] = e2;
            func_003D8DB0_inl1(this)->field_C[nEdges * 2 + 1] = e0;
            nEdges++;
        }
        i++;
    }
}
