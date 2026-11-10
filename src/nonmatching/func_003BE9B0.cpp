// NONMATCHING: func_003BE9B0 -- retail 362 / ours 360 instructions, 223 in changed runs
// draftAM C-first: [L] CGtCollisionKDTree::IntersectSphere(CGtSphere, cb, void*) const (E map, no symbol form in retail): the inlined sphere-box test (squared distance to the box < r^2), the root overlap test against centre +- r, a 64-entry traversal stack of (node, plane mask) with the root mask from centre +- 0.577/r, children kept by their bounds on the split axis, a masked-out subtree taking its whole leaf range, each leaf soup tested with func_00274ED0 (CGtPolygonSoup) or func_00273070 (field_2C != 0); 360/362, calls identical, non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every compare (field_10 <= hi, !(field_0 < lo), the six root-mask bits, child 1 min <= hi, child 0 max < lo, child 1 min < lo2, child 0 max <= hi2), the push order (child 1 replaces the entry, child 0 pushed with the entry's original mask), the u16 leaf loop and the first/last-leaf descent traced; behaviour_audit: the root-mask ternaries' arm placement (c.le+bc1t vs bc1f, same values) and t0/t2 "arguments" the 4-argument callees never take
// Retail oddities kept: k = 0.577 / r (not x r); the node loop clears plane bits 1 << axis / 2 << axis while the root mask uses
// 1 << 2 axis / 2 << 2 axis, so the "all planes passed" shortcut fires on different subtrees than a consistent mask would.

// func_003BE9B0 -- draftAM (C-first draft). 0x3BE9B0, 0x5A8. Placeholder with C linkage: retail's table has no symbol form for it;
// [L] identity from config/symbol_addrs_b3names.txt ("no symbol form @ 0x003BE9B0: CGtCollisionKDTree::IntersectSphere(...) const
// [high]") and its caller CB3StreamedTrack::IntersectSphereWithUnit (func_00301B00, a proven unit, passes the tree, the sphere by
// value, the callback and its data). Node layout as the IntersectLine__18CGtCollisionKDTree archive. Header gaps queued:
// operator*(WAxisType, WAxisType) and CGtV3d::operator+(WAxisType) (both in the E map).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

struct CGtPolygonIntersectionResult;
typedef bool (*UnkFunc_003BE9B0_cb)(const CGtPolygonIntersectionResult &, void *);
struct UnkStruct_003BE9B0_n {               // [L] a KD-tree node, 8 bytes (as IntersectLine__18CGtCollisionKDTree's archive)
    float field_0;                          // [G] the child's bound on its parent's split axis (child 0: max, child 1: min)
    unsigned short field_4;                 // internal: children pair index; leaf: soup index
    unsigned char field_6;                  // [G] split axis (read on child 0 of a pair)
    unsigned char field_7;                  // 0xFF: internal node
};
struct UnkStruct_003BE9B0_e { UnkStruct_003BE9B0_n * field_0; unsigned int field_4; };   // traversal entry: node, planes-to-test mask
struct UnkStruct_003BE9B0_s { unsigned char pad_0[0x10]; };   // [L] a polygon soup (CGtPolygonSoup / CGtPolygonSoup16), 0x10 bytes
struct UnkStruct_003BE9B0_t {               // [L] CGtCollisionKDTree
    CGtV3d field_0;                         // [G] bounding box max
    CGtV3d field_10;                        // [G] bounding box min
    UnkStruct_003BE9B0_n * field_20;        // nodes
    UnkStruct_003BE9B0_s * field_24;        // leaf soups
    unsigned short field_28;                // [G] the root's leaf tag when the tree has no internal node
    unsigned short field_2A;                // [G] internal node count (0: the root is a leaf)
    int field_2C;                           // [G] soup kind (!= 0: CGtPolygonSoup16)
};
extern const CGtV3d D_004CA310;             // (0, 0, 0)
// [L] GtIntersection::IntersectSphere(CGtSphere, const CGtPolygonSoup&, cb, void*) (E map, no symbol form) and its Soup16 sibling
extern "C" int func_00274ED0(const CGtSphere s, const UnkStruct_003BE9B0_s & soup, UnkFunc_003BE9B0_cb cb, void * data);
extern "C" int func_00273070(const CGtSphere s, const UnkStruct_003BE9B0_s & soup, UnkFunc_003BE9B0_cb cb, void * data);

// W * W in the w lane (E map GtMathPs2::operator*(WAxisType, WAxisType), not in the header yet)
static inline WAxisType func_003BE9B0_inl1(WAxisType a, WAxisType b)
{
    u_long128 r;
    asm("vmulw.w %0, %1, %2w" : "=j"(r) : "j"(a.lVector), "j"(b.lVector));
    return WAxisType(r);
}
// v + w broadcast (E map CGtV3d::operator+(WAxisType), not in the header yet)
static inline CGtV3d func_003BE9B0_inl2(const CGtV3d & v, WAxisType w)
{
    u_long128 r;
    asm("vaddw.xyz %0, %1, %2w" : "=j"(r) : "j"(v.mData), "j"(w.lVector));
    return CGtV3d(r);
}
// v -/+ a scalar on all three lanes (`qmtc2; vsubx.xyz / vaddx.xyz`; no map entry found)
static inline CGtV3d func_003BE9B0_inl3(const CGtV3d & v, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vsubx.xyz %0, %1, %2x" : "=j"(r) : "j"(v.mData), "j"(s));
    return CGtV3d(r);
}
static inline CGtV3d func_003BE9B0_inl4(const CGtV3d & v, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.xyz %0, %1, %2x" : "=j"(r) : "j"(v.mData), "j"(s));
    return CGtV3d(r);
}
static inline float func_003BE9B0_inl5(const CGtV3d & v, int axis) { return ((const float *)&v.mData)[axis]; }

// 0x003BE9B0
extern "C" void func_003BE9B0(const UnkStruct_003BE9B0_t * self, const CGtSphere s, UnkFunc_003BE9B0_cb cb, void * data)
{
    CGtSphere ls = s;
    // [L] the inlined CGtCollisionKDTree::SphereBBoxTest(CGtSphere): squared distance from the centre to the box < r^2
    CGtV3d half = (self->field_0 - self->field_10) * 0.5f;
    CGtV3d centre = self->field_10 + half;
    CGtV3d d = Max(Abs(ls.Position() - centre) - half, D_004CA310);
    float lrDistSq = (float)d.GetSquaredLength();
    if (!(lrDistSq < (float)func_003BE9B0_inl1(ls.Radius(), ls.Radius())))
        return;
    float r = (float)ls.Radius();
    CGtV3d lo = ls.Position() - ls.Radius();
    CGtV3d hi = func_003BE9B0_inl2(ls.Position(), ls.Radius());
    // [C] 0.577 / r, not 0.577 x r (an inner box of the sphere would be r / sqrt 3): retail's own constant use, kept
    float k = 0.577f * (1.0f / r);
    CGtV3d lo2 = func_003BE9B0_inl3(ls.Position(), k);
    CGtV3d hi2 = func_003BE9B0_inl4(ls.Position(), k);
    UnkStruct_003BE9B0_e stack[64];
    UnkStruct_003BE9B0_n root;              // field_0 and field_6 never set (an internal root reads only field_4 / field_7)
    UnkStruct_003BE9B0_e * p = stack;
    if ((float)self->field_10.X() <= (float)hi.X() && (float)self->field_10.Y() <= (float)hi.Y() &&
        (float)self->field_10.Z() <= (float)hi.Z() && !((float)self->field_0.X() < (float)lo.X()) &&
        !((float)self->field_0.Y() < (float)lo.Y()) && !((float)self->field_0.Z() < (float)lo.Z())) {
        root.field_4 = 0;
        if (self->field_2A != 0)
            root.field_7 = 0xFF;
        else
            root.field_7 = (unsigned char)self->field_28;
        stack[0].field_0 = &root;
        unsigned int mz = (float)self->field_0.Z() <= (float)hi2.Z() ? 0 : 0x20;
        unsigned int my = (float)self->field_0.Y() <= (float)hi2.Y() ? 0 : 8;
        unsigned int mx = (float)self->field_0.X() <= (float)hi2.X() ? 0 : 2;
        unsigned int nz = (float)self->field_10.Z() < (float)lo2.Z() ? 0x10 : 0;
        unsigned int nx = (float)self->field_10.X() < (float)lo2.X() ? 1 : 0;
        unsigned int ny = (float)self->field_10.Y() < (float)lo2.Y() ? 4 : 0;
        stack[0].field_4 = mz | (my | (mx | (nz | (nx | ny))));
        p = &stack[1];
    }
    while (p > stack) {
        p--;
        UnkStruct_003BE9B0_n * nodes = self->field_20;
        unsigned short start;
        unsigned short count;
        for (;;) {
            UnkStruct_003BE9B0_n * n = p->field_0;
            unsigned int mask = p->field_4;
            if (n->field_7 != 0xFF) {
                start = n->field_4;
                count = 1;
                break;
            }
            if (mask == 0) {
                // every plane already passed: take all the subtree's leaves (first leaf .. last leaf)
                UnkStruct_003BE9B0_n * all = self->field_20;
                UnkStruct_003BE9B0_n * first = &all[n->field_4 * 2];
                UnkStruct_003BE9B0_n * last = first;
                while (first->field_7 == 0xFF)
                    first = &all[first->field_4 * 2];
                last = last + 1;
                while (last->field_7 == 0xFF)
                    last = &all[last->field_4 * 2] + 1;
                start = first->field_4;
                count = (unsigned short)(last->field_4 + 1 - first->field_4);
                break;
            }
            UnkStruct_003BE9B0_n * c = &nodes[n->field_4 * 2];
            int axis = c->field_6;
            float lrMin1 = c[1].field_0;
            if (!(lrMin1 <= func_003BE9B0_inl5(hi, axis))) {
                p->field_0 = c;
                continue;
            }
            p->field_0 = c + 1;
            if (c->field_0 < func_003BE9B0_inl5(lo, axis))
                continue;
            // [C] the plane bits cleared here are 1 << axis / 2 << axis, while the root mask uses 1 << 2 axis / 2 << 2 axis
            // (x 1/2, y 4/8, z 0x10/0x20): retail's own mismatch, kept
            if (!(lrMin1 < func_003BE9B0_inl5(lo2, axis)))
                p->field_4 &= ~(1 << axis);
            p++;
            p->field_0 = c;
            p->field_4 = mask;
            if (c->field_0 <= func_003BE9B0_inl5(hi2, axis))
                p->field_4 &= ~(2 << axis);
        }
        for (unsigned short i = 0; i < count; i++) {
            unsigned short idx = start + i;
            if (self->field_2C != 0)
                func_00273070(ls, self->field_24[idx], cb, data);
            else
                func_00274ED0(ls, self->field_24[idx], cb, data);
        }
    }
}
