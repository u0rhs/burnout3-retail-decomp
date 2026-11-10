// NONMATCHING: IntersectLineNearest__18CGtCollisionKDTreeCFRC7CGtLineP28CGtPolygonIntersectionResult -- retail 494 / ours 509 instructions, 493 in changed runs
// draftAO (2026-11-01): complete: IntersectLine's body (box slab test, retail's dir/org/inv VU temps via CGtV3d APIs, 64-entry stack, unset root fields) with res+0x50 = 1.0 at entry and the leaf IntersectLineNearest results OR-ed (no early out); calls identical, behaviour_audit quiet | Before: fix3 (2026-11-01): res+0x50 (nearest fraction) initialised to 1.0 at entry as retail 0x3BF758 | Before: son8: first archive; same body as IntersectLine (son8 archive) with the leaf calls GtIntersection::IntersectLineNearest(soup / soup16 by +0x2C) OR-ed into the bool result. Same open items: retail's dir/org/invdir VU temps (frame 0x600 vs 0x250, +78 instrs)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm (0x3BF720..0x3BFEDC), every branch, store and call accounted for; behaviour_audit quiet

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

// [C] node pair entry of the tree (retail 0x3BF33C..): 8 bytes. An interior node (field_7 == 0xFF) points with field_4 at a
// pair of children at field_20 + field_4 * 0x10: the left child's split (+0, float) bounds the region below it, the right
// child's split (+8) the region above; the axis (0..2) is the byte at +6 of the pair. A leaf (field_7 != 0xFF) holds its
// polygon-soup index in field_4 (soup = field_24 + field_4 * 0x10).
struct UnkStruct_003BF720_n { float field_0; unsigned short field_4; unsigned char field_6; unsigned char field_7; };
// [C] traversal stack entry (12 bytes, sp+0x2C0..0x5C0: 64 entries): node, entry / exit fraction along the line.
struct UnkStruct_003BF720_e { UnkStruct_003BF720_n *field_0; float field_4; float field_8; };
// [L] CGtLine (start, end) -- the mangled name's CGtLine; the layout from the lq 0x0 / 0x10 reads.
struct UnkStruct_003BF720_l { CGtV3d field_0; CGtV3d field_10; };
// CGtCollisionKDTree: [C] field_0 = box maximum, field_10 = box minimum (the slab test 0x3BEFE0: inside when
// min <= start <= max; entering fraction (min - start) / d for d > 0).
struct UnkStruct_003BF720_t {
    CGtV3d field_0;
    CGtV3d field_10;
    unsigned char *field_20;      // node pairs (16-byte stride)
    unsigned char *field_24;      // polygon soups (16-byte stride)
    unsigned short field_28;      // root leaf's field_7 when field_2A == 0
    unsigned short field_2A;      // non-zero: the root is an interior node
    int field_2C;                 // non-zero: the soups are CGtPolygonSoup16
};

extern float D_004E0DCC;   // [C] fraction epsilon (gp-relative)
extern float D_004E0C14;   // [C] 1/d substitute for an (effectively) zero direction lane (gp-relative)
extern "C" bool IntersectLineNearest__14GtIntersectionFRC7CGtLineRC14CGtPolygonSoupP28CGtPolygonIntersectionResult(const UnkStruct_003BF720_l *, const void *, void *);
extern "C" bool IntersectLineNearest__14GtIntersectionFRC7CGtLineRC16CGtPolygonSoup16P28CGtPolygonIntersectionResult(const UnkStruct_003BF720_l *, const void *, void *);

// One slab of the box test (retail 0x3BEFB8.. x, 0x3BF0EC.. y, 0x3BF21C.. z): parallel lane -> start inside [min, max];
// else clip [tmin, tmax] to the lane's entry / exit fractions. Returns whether the line still overlaps.
static inline bool func_003BF720_inl1(float st, float en, float mx, float mn, float &tmin, float &tmax)
{
    float d = en - st;
    bool ok;
    if (GtMath::IsEffectivelyZero(d)) {
        ok = !(st < mn) && st <= mx;
    } else {
        float inv = 1.0f / d;
        float t0, t1;
        if (inv <= 0.0f) { t0 = inv * (mx - st); t1 = inv * (mn - st); }
        else             { t0 = inv * (mn - st); t1 = inv * (mx - st); }
        ok = false;
        if (tmin <= t1) { ok = true; if (tmax < t0) ok = false; }
        if (ok) {
            tmin = GtMath::Max(tmin, t0);
            tmax = GtMath::Min(tmax, t1);
        }
    }
    return ok;
}

// CGtCollisionKDTree::IntersectLineNearest(const CGtLine &, CGtPolygonIntersectionResult *) const: IntersectLine's walk (same
// box clip, same front-to-back stack) with GtIntersection::IntersectLineNearest on every leaf soup the clipped line passes;
// returns whether any leaf reported a hit (the leaf results OR-ed: retail `or s3, s3, v0`, int as the matched caller
// CB3StreamedTrack 0x301C80 declares it). Every leaf is visited: no early out on the first hit.
extern "C" int IntersectLineNearest__18CGtCollisionKDTreeCFRC7CGtLineP28CGtPolygonIntersectionResult(
    UnkStruct_003BF720_t *self, const UnkStruct_003BF720_l *line, void *res)
{
    *(float *)((char *)res + 0x50) = 1.0f;   // [C] retail 0x3BF758 sw 1.0, 0x50(a2): the nearest-hit fraction starts at the line end
    int found = 0;
    float tmin = 0.0f;
    float tmax = 1.0f;
    bool hit = false;
    if (func_003BF720_inl1(line->field_0.X(), line->field_10.X(), self->field_0.X(), self->field_10.X(), tmin, tmax)
        && func_003BF720_inl1(line->field_0.Y(), line->field_10.Y(), self->field_0.Y(), self->field_10.Y(), tmin, tmax)
        && func_003BF720_inl1(line->field_0.Z(), line->field_10.Z(), self->field_0.Z(), self->field_10.Z(), tmin, tmax))
        hit = true;

    UnkStruct_003BF720_e stack[64];   // [C] sp+0x2C0..0x5C0; retail has no depth check
    CGtV3d inv;    // sp+0x5C0: 1/dir per lane (w never written)
    CGtV3d dir;    // sp+0x5D0
    CGtV3d org;    // sp+0x5E0 (the whole start quad, w included)
    UnkStruct_003BF720_n root;   // sp+0x5F8: field_0 / field_6 never written (never read for the root)
    UnkStruct_003BF720_e *top = &stack[0];
    if (hit) {
        root.field_4 = 0;
        if (self->field_2A == 0) root.field_7 = (unsigned char)self->field_28;
        else root.field_7 = 0xFF;
        dir = line->field_10 - line->field_0;   // vsub.xyz: dir.w is a stale VU lane, never read
        org = line->field_0;
        if (GtMath::IsEffectivelyZero(dir.X())) inv.SetX(D_004E0C14); else inv.SetX(1.0f / (float)dir.X());  // [C] retail FPU form, not a VU lane op: div.s 0x3BF568 / 0x3BF5E4 / 0x3BF65C (the cast keeps the port's PS2 float model)
        if (GtMath::IsEffectivelyZero(dir.Y())) inv.SetY(D_004E0C14); else inv.SetY(1.0f / (float)dir.Y());  // [C] retail FPU form, not a VU lane op: div.s 0x3BF568 / 0x3BF5E4 / 0x3BF65C (the cast keeps the port's PS2 float model)
        if (GtMath::IsEffectivelyZero(dir.Z())) inv.SetZ(D_004E0C14); else inv.SetZ(1.0f / (float)dir.Z());  // [C] retail FPU form, not a VU lane op: div.s 0x3BF568 / 0x3BF5E4 / 0x3BF65C (the cast keeps the port's PS2 float model)
        stack[0].field_0 = &root;
        stack[0].field_4 = tmin - D_004E0DCC;
        stack[0].field_8 = D_004E0DCC + tmax;
        top = &stack[1];
    }
    const float *pdir = (const float *)&dir;
    const float *porg = (const float *)&org;
    const float *pinv = (const float *)&inv;
    while (&stack[0] < top) {
        UnkStruct_003BF720_e *p = top - 1;   // the entry being walked (retail s4); a push walks the new entry above it
        for (;;) {
            UnkStruct_003BF720_n *n = p->field_0;
            if (n->field_7 != 0xFF) break;
            float *pr = (float *)(self->field_20 + n->field_4 * 0x10);
            unsigned int ax = ((unsigned char *)pr)[6];
            float dd = pdir[ax];
            float p1 = 0.0f + porg[ax] + p->field_8 * dd;   // point at the exit fraction
            float p0 = 0.0f + porg[ax] + p->field_4 * dd;   // point at the entry fraction
            if (!(dd <= 0.0f)) {
                if (!(pr[2] <= p1)) {
                    p->field_0 = (UnkStruct_003BF720_n *)pr;              // only the left (lower) child
                } else if (pr[0] < p0) {
                    p->field_0 = (UnkStruct_003BF720_n *)(pr + 2);        // only the right (upper) child
                } else {
                    // both: the near (left) child on top, the far (right) one in this entry
                    UnkStruct_003BF720_e *q = p + 1;
                    q->field_0 = (UnkStruct_003BF720_n *)pr;
                    float iv = pinv[ax];
                    q->field_4 = p->field_4;
                    q->field_8 = p->field_8;
                    if (pr[0] < p1)
                        q->field_8 = q->field_8 + (0.0f + D_004E0DCC + iv * (pr[0] - p1));
                    p->field_0 = (UnkStruct_003BF720_n *)(pr + 2);
                    if (!(pr[2] <= p0))
                        p->field_4 = p->field_4 + (iv * (pr[2] - p0) - D_004E0DCC);
                    p = q;
                }
            } else if (pr[0] < p1) {
                p->field_0 = (UnkStruct_003BF720_n *)(pr + 2);            // only the right child
            } else if (!(pr[2] <= p0)) {
                p->field_0 = (UnkStruct_003BF720_n *)pr;                  // only the left child
            } else {
                // both: the near (right) child on top, the far (left) one in this entry
                UnkStruct_003BF720_e *q = p + 1;
                float iv = pinv[ax];
                q->field_0 = (UnkStruct_003BF720_n *)(pr + 2);
                q->field_4 = p->field_4;
                q->field_8 = p->field_8;
                if (!(pr[2] <= p1))
                    q->field_8 = q->field_8 + (0.0f + D_004E0DCC + iv * (pr[2] - p1));
                p->field_0 = (UnkStruct_003BF720_n *)pr;
                if (pr[0] < p0)
                    p->field_4 = p->field_4 + (iv * (pr[0] - p0) - D_004E0DCC);
                p = q;
            }
        }
        top = p;                             // the leaf's entry is consumed
        UnkStruct_003BF720_n *leaf = p->field_0;
        if (self->field_2C != 0)
            found |= IntersectLineNearest__14GtIntersectionFRC7CGtLineRC16CGtPolygonSoup16P28CGtPolygonIntersectionResult(line, self->field_24 + leaf->field_4 * 0x10, res);
        else
            found |= IntersectLineNearest__14GtIntersectionFRC7CGtLineRC14CGtPolygonSoupP28CGtPolygonIntersectionResult(line, self->field_24 + leaf->field_4 * 0x10, res);
    }
    return found;
}
