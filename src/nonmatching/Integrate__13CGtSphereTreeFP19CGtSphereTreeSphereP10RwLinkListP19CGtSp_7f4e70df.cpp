// NONMATCHING: Integrate__13CGtSphereTreeFP19CGtSphereTreeSphereP10RwLinkListP19CGtSphereTreeSpherei -- retail 233 / ours 233 instructions, 29 in changed runs
// v292: logic complete, 29 changed: prologue load order (retail loads field_34 before field_20[0], int->float via f3), call a0/a1 addiu order, frame 0x1D0 vs 0x240 (retail dead-slot gaps t|3|pc|2|sphR|2|bestR|10|AC|2|AC)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CGtSphereTree::Integrate(CGtSphereTreeSphere*, RwLinkList*, CGtSphereTreeSphere*, int) -- hand-written (v292).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> GtSphereTree.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

struct RwLLLink { RwLLLink *next; RwLLLink *prev; };   // [L] RW 3.5 rwcore.h layout
struct RwLinkList { RwLLLink link; };

struct CGtSphereTreeSphere {
    GtMathPs2::CGtSphere field_0;    // [L] bounding sphere
    CGtSphereTreeSphere *field_10;   // [L] parent
    RwLLLink field_14;               // [L] sibling link (GetFromSiblingListLink subtracts 0x14)
    RwLLLink field_1C;               // [L] recompute-list link
    int field_24;                    // [L] child count
    RwLinkList field_28;             // [L] child list
    float field_30;
};

namespace GtIntersection {
int IntersectSphere(GtMathPs2::CGtSphere, GtMathPs2::CGtSphere);
}

class CGtSphereTree {
public:
    void Integrate(CGtSphereTreeSphere *, RwLinkList *, CGtSphereTreeSphere *, int);
    RwLinkList field_0;
    RwLinkList field_8;
    RwLinkList field_10;   // [L] recompute list
    RwLinkList field_18;   // [L] free parent spheres
    float field_20[5];     // [L] [0] set by Init's float; [1..4] per-level parent sizes
    int field_34;
    int field_38;
    int field_3C;
};

// [L] N185: stands in for a missing GtMathPs2 inline (compiler-chosen vsub.xyz)
static inline GtMathPs2::CGtV3d func_0035DBB0_inl1(const GtMathPs2::CGtV3d &a, const GtMathPs2::CGtV3d &b)
{
    u_long128 t;
    asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return GtMathPs2::CGtV3d(t);
}
// [L] N185: stands in for a missing GtMathPs2 inline (WAxisType - WAxisType, vsubw.w)
static inline GtMathPs2::WAxisType func_0035DBB0_inl2(GtMathPs2::WAxisType a, GtMathPs2::WAxisType b)
{
    u_long128 t;
    asm("vsubw.w %0, %1, %2w" : "=j"(t) : "j"(*(const u_long128*)&a.lVector), "j"(*(const u_long128*)&b.lVector));
    return GtMathPs2::WAxisType(t);
}

// [L] inlined child add (placeholder name; RW rwLinkListAddLLLink order)
static inline void func_0035DBB0_inl3(CGtSphereTreeSphere *p, CGtSphereTreeSphere *c)
{
    p->field_24++;
    c->field_10 = p;
    c->field_14.next = p->field_28.link.next;
    c->field_14.prev = &p->field_28.link;
    p->field_28.link.next->prev = &c->field_14;
    p->field_28.link.next = &c->field_14;
    float d = func_0035DBB0_inl2(c->field_10->field_0.Radius(), c->field_0.Radius());
    c->field_30 = d * d;
}
// [L] CGtSphereTree::AddToRecomputeList body (0x35D210), inlined
static inline void func_0035DBB0_inl4(CGtSphereTree *t, CGtSphereTreeSphere *p)
{
    if (p->field_1C.next == 0) {
        p->field_1C.next = t->field_10.link.next;
        p->field_1C.prev = &t->field_10.link;
        t->field_10.link.next->prev = &p->field_1C;
        t->field_10.link.next = &p->field_1C;
    }
}

// [L] inlined free-parent allocation (placeholder name)
static inline CGtSphereTreeSphere *func_0035DBB0_inl5(CGtSphereTree *t, GtMathPs2::CGtV3d pos, float r)
{
    RwLLLink *f = t->field_18.link.next;
    CGtSphereTreeSphere *s = (CGtSphereTreeSphere *)((char *)f - 0x14);
    f->prev->next = f->next;
    f->next->prev = f->prev;
    s->field_0.SetPosition(pos);
    s->field_0.SetRadius(r);
    s->field_1C.prev = 0;
    s->field_1C.next = 0;
    t->field_3C--;
    return s;
}

// 0x0035DBB0
void CGtSphereTree::Integrate(CGtSphereTreeSphere *p0, RwLinkList *list, CGtSphereTreeSphere *sphere, int level)
{
    CGtSphereTreeSphere *best = 0;
    bool grew = false;
    float rad = sphere->field_0.Radius();
    float r = rad + (field_20[0] + 0.001f * (float)(field_34 - level));
    float bestDist = field_20[level];
    RwLLLink *l = list->link.next;
    while (l != &list->link) {
        CGtSphereTreeSphere *s = (CGtSphereTreeSphere *)((char *)l - 0x14);
        l = l->next;
        float len = func_0035DBB0_inl1(s->field_0.Position(), sphere->field_0.Position()).GetLength();
        float d = len + r;
        if (d < bestDist) {
            if (p0 != 0) {
                GtMathPs2::CGtSphere t;
                t.SetPosition(s->field_0.Position());
                t.SetRadius(d);
                GtMathPs2::CGtSphere pc = s->field_10->field_0;
                if (GtIntersection::IntersectSphere(t, pc) != 2) continue;
            }
            best = s;
            bestDist = d;
        }
    }
    if (best != 0) {
        float br = best->field_0.Radius();
        if (bestDist > br) {
            best->field_0.SetRadius(bestDist);
            grew = true;
        }
    } else {
        best = func_0035DBB0_inl5(this, sphere->field_0.Position(), r);
        if (p0 != 0) {
            func_0035DBB0_inl3(p0, best);
            if (p0->field_24 > 1) func_0035DBB0_inl4(this, p0);
        } else {
            best->field_14.next = list->link.next;
            best->field_14.prev = &list->link;
            list->link.next->prev = &best->field_14;
            list->link.next = &best->field_14;
        }
    }
    if (level == field_34) {
        func_0035DBB0_inl3(best, sphere);
        if (grew && best->field_24 > 1) func_0035DBB0_inl4(this, best);
    } else {
        Integrate(best, &best->field_28, sphere, level + 1);
    }
}


