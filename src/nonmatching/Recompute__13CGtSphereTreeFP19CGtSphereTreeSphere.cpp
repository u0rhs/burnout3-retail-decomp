// NONMATCHING: Recompute__13CGtSphereTreeFP19CGtSphereTreeSphere -- retail 148 / ours 148 instructions, 36 in changed runs
// 148/148, 36 off: logic/blocks/VU exact (goto form + scoped opt_repositioncode off [G]; child = (unsigned)n + (unsigned)-0x14 keeps retail's register constant; compiler-chosen vsub; W+X / W+float / W-W lane stand-ins). Left: frame 0x110 vs 0x170 (retail: sum 0x160, t 0x150, 6 dead, arg copy 0xE0, 3 dead, W copy 0xA0, R copy 0x90, 2 dead, loop-3 W copy 0x60, centre 0x50 at the bottom) and the a0/a1 swap that follows it
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CGtSphereTree::Recompute(CGtSphereTreeSphere*) -- hand-matched (ghvu8). Layout as the proven GtSphereTree units
// (children listed through their +0x14 node, the parent at +0x10, the recompute-list node at +0x1C, count at +0x24).
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_0035D960_n;
struct UnkStruct_0035D960_n {
    UnkStruct_0035D960_n * field_0;
    UnkStruct_0035D960_n * field_4;
};

struct CGtSphereTreeSphere {
    CGtSphere field_0;
    CGtSphereTreeSphere * field_10;     // [G] parent
    UnkStruct_0035D960_n * field_14;    // [G] sibling list node (next, prev)
    UnkStruct_0035D960_n * field_18;
    UnkStruct_0035D960_n * field_1C;    // [G] recompute list node (next, prev)
    UnkStruct_0035D960_n * field_20;
    int field_24;                       // [G] child count
    UnkStruct_0035D960_n * field_28;    // [G] child list head (next, prev)
    UnkStruct_0035D960_n * field_2C;
    float field_30;
};

class GtIntersection { public: static int IntersectSphere(CGtSphere a, CGtSphere b); };

class CGtSphereTree {
public:
    void Recompute(CGtSphereTreeSphere *s);
    unsigned char pad_0[0x10];
    UnkStruct_0035D960_n * field_10;    // [G] recompute list head
    UnkStruct_0035D960_n * field_14;
    unsigned char pad_18[0x8];
    float field_20;
};

static inline CGtSphereTreeSphere *func_0035D960_inl0(UnkStruct_0035D960_n *n) { return (CGtSphereTreeSphere *)((unsigned int)n + (unsigned int)-0x14); }
// [L] N185: WAxisType + XAxisType (lane w plus lane x)
static inline WAxisType func_0035D960_inl1(const WAxisType &a, const XAxisType &b) {
    u_long128 r = a.lVector;
    asm("vaddx.w %0, %0, %1x" : "+j"(r) : "j"(b.lVector));
    return WAxisType(r);
}
// [L] N185: WAxisType + float
static inline WAxisType func_0035D960_inl2(const WAxisType &a, float f) {
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.w %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return WAxisType(r);
}
// [L] N185: CGtV3d - CGtV3d on compiler-chosen registers (the header's goes through $vf1/$vf2 and GPRs)
static inline CGtV3d func_0035D960_inl4(const CGtV3d &a, const CGtV3d &b) {
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185: WAxisType - WAxisType
static inline WAxisType func_0035D960_inl3(WAxisType a, WAxisType b) {
    u_long128 r;
    asm("vsubw.w %0, %1, %2w" : "=j"(r) : "j"(a.lVector), "j"(b.lVector));
    return WAxisType(r);
}

// N182: scoped `opt_repositioncode off` [G] scoped to this function, with the body in goto form in retail's block order
#pragma push
#pragma opt_repositioncode off
// 0x0035D960
void CGtSphereTree::Recompute(CGtSphereTreeSphere *s)
{
    CGtV3d sum;
    UnkStruct_0035D960_n *n;
    float maxr = 0.0f;
    sum.Set(0.0f, 0.0f, 0.0f);
    for (n = s->field_28; n != (UnkStruct_0035D960_n *)&s->field_28; n = n->field_0) {
        sum += func_0035D960_inl0(n)->field_0.Position();
    }
    CGtV3d centre = sum * (1.0f / (float)s->field_24);
    n = s->field_28;
    goto test2;
body2:
    {
        CGtSphereTreeSphere *c = func_0035D960_inl0(n);
        float r = func_0035D960_inl2(func_0035D960_inl1(c->field_0.Radius(), func_0035D960_inl4(centre, c->field_0.Position()).GetLength()), field_20);
        if (r <= maxr) goto next2;
        maxr = r;
        if (r <= s->field_0.Radius()) goto next2;
        return;
    }
test2:
    if (n != (UnkStruct_0035D960_n *)&s->field_28) goto body2;
    if (s->field_10 != 0) goto parent;
join:
    s->field_0.SetPosition(centre);
    s->field_0.SetRadius(maxr);
    for (n = s->field_28; n != (UnkStruct_0035D960_n *)&s->field_28; n = n->field_0) {
        CGtSphereTreeSphere *c = func_0035D960_inl0(n);
        float d = func_0035D960_inl3(c->field_10->field_0.Radius(), c->field_0.Radius());
        c->field_30 = d * d;
    }
    return;
next2:
    n = n->field_0;
    goto test2;
parent:
    {
        CGtSphere t;
        t.SetPosition(centre);
        t.SetRadius(maxr);
        CGtSphere ps = s->field_10->field_0;
        if (GtIntersection::IntersectSphere(t, ps) != 2) return;
        CGtSphereTreeSphere *p = s->field_10;
        if (p->field_1C != 0) goto join;
        p->field_1C = field_10;
        p->field_20 = (UnkStruct_0035D960_n *)&field_10;
        field_10->field_4 = (UnkStruct_0035D960_n *)&p->field_1C;
        field_10 = (UnkStruct_0035D960_n *)&p->field_1C;
        goto join;
    }
}
#pragma pop
