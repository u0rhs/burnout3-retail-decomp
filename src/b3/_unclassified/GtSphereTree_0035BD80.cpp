// CGtSphereTree::RecursiveFrustumTestResult(const CGtSphereTreeSphere*,EGtIntersectionResult) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSphereTree.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (recursion auto-inlined 8 deep as static inline chain; 0x30-byte POD CGtIntersectionResult + explicit cut-level ctor calls (no weak copies); POD sphere copy).

// CGtSphereTree::RecursiveFrustumTestResult(const CGtSphereTreeSphere*, EGtIntersectionResult) -- hand-written (L269).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> GtSphereTree.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G] (instruction widths).
// The function recurses into itself; MWCC auto-inlined the recursion 8 levels deep (N151). Written out here as a chain of
// static inline helpers with placeholder names [L] (cf. GtSphereTree_0035CA00.cpp); at the cut the real method is called.
// At the deepest levels retail's inline budget runs out: level 7 calls CGtV3d's ctor out of line (written explicitly),
// level 8 calls CGtIntersectionResult's ctor out of line (its weak copy is retail's 0x35C3D0, right after this function).
// [L] CGtIntersectionResult is 0x30 bytes (two CGtV3d at +0/+0x10 -- the out-of-line member ctor calls -- plus a 16-byte
// tail): each level's frame keeps exactly that size. [L] the sphere is copied bitwise (lq/sq, inline even at level 8), so
// its type here has no user ctor; GtMathPs2.h's CGtSphere (user ctor) makes MWCC call a copy ctor at level 8.

#include "b3/GtMathPs2.h"

class CGtFrustum;
// [L] 0x30 bytes: two CGtV3d at +0/+0x10 (the out-of-line member ctor calls) plus a 16-byte tail. Declared here without
// ctors: the inline (empty) ctors' only trace is the out-of-line calls at the cut levels, written explicitly below [G]
// (an inline ctor would also emit weak out-of-line copies into this object, which the link must not get).
struct CGtIntersectionResult {
    u_long128 field_0;
    u_long128 field_10;
    float field_20;  // [G] type; only its size is evidenced
};
extern "C" void *__ct__Q29GtMathPs26CGtV3dFv(void *);          // [C] retail's jal targets at the cut levels
extern "C" void __ct__21CGtIntersectionResultFv(CGtIntersectionResult *);
struct UnkStruct_0035BD80_sph { u_long128 field_0; };  // [G] GtMathPs2::CGtSphere without a user ctor (see above)
struct UnkStruct_0035BD80_n { UnkStruct_0035BD80_n *field_0; UnkStruct_0035BD80_n *field_4; };
struct CGtSphereTreeSphere {
    UnkStruct_0035BD80_sph field_0;  // [L] the bounding sphere (passed to IntersectSphere)
    unsigned char pad_10[0x14];
    int field_24;                    // [G] child count (0 = leaf)
    UnkStruct_0035BD80_n field_28;   // [G] child list head; children link at +0x14
};
enum EGtIntersectionResult { UnkEnum_0035BD80_0, UnkEnum_0035BD80_1 };
// [C] callee: GtIntersection::IntersectSphere(GtMathPs2::CGtSphere, const CGtFrustum&, CGtIntersectionResult*) (mangled name);
// extern "C" link-name with the placeholder sphere type [G].
extern "C" EGtIntersectionResult IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustumP21CGtIntersectionResult(
    UnkStruct_0035BD80_sph, const CGtFrustum &, CGtIntersectionResult *);
class CGtSphereTree {
public:
    void RecursiveFrustumTestResult(const CGtSphereTreeSphere *, EGtIntersectionResult);
    unsigned char pad_0[0x4C];
    const CGtFrustum *field_4C;  // [L] frustum (set by ForAllSpheresResult)
    unsigned char pad_50[0x4];
    bool (*field_54)(const CGtSphereTreeSphere *, EGtIntersectionResult, const CGtIntersectionResult &, void *);  // [L] callback
    void *field_58;              // [L] callback user data
};

// inlined levels (placeholder names) [L]
static inline void func_0035BD80_rc8(CGtSphereTree *t, const CGtSphereTreeSphere *s, EGtIntersectionResult r)
{
    CGtIntersectionResult res;
    __ct__21CGtIntersectionResultFv(&res);   // [G] inline depth exhausted: ctor out of line
    if (r == 1) {
        UnkStruct_0035BD80_sph sc = s->field_0;
        r = IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustumP21CGtIntersectionResult(sc, *t->field_4C, &res);
        if (r == 0) return;
    }
    if (s->field_24 == 0) {
        t->field_54(s, r, res, t->field_58);
    } else {
        UnkStruct_0035BD80_n *n = s->field_28.field_0;
        while (n != &s->field_28) {
            const CGtSphereTreeSphere *c = (const CGtSphereTreeSphere *)((char *)n - 0x14);
            n = n->field_0;
            t->RecursiveFrustumTestResult(c, r);
        }
    }
}

static inline void func_0035BD80_rc7(CGtSphereTree *t, const CGtSphereTreeSphere *s, EGtIntersectionResult r)
{
    CGtIntersectionResult res;
    __ct__Q29GtMathPs26CGtV3dFv(&res.field_0);   // [G] inline depth exhausted: member ctors out of line
    __ct__Q29GtMathPs26CGtV3dFv(&res.field_10);
    if (r == 1) {
        UnkStruct_0035BD80_sph sc = s->field_0;
        r = IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustumP21CGtIntersectionResult(sc, *t->field_4C, &res);
        if (r == 0) return;
    }
    if (s->field_24 == 0) {
        t->field_54(s, r, res, t->field_58);
    } else {
        UnkStruct_0035BD80_n *n = s->field_28.field_0;
        while (n != &s->field_28) {
            const CGtSphereTreeSphere *c = (const CGtSphereTreeSphere *)((char *)n - 0x14);
            n = n->field_0;
            func_0035BD80_rc8(t, c, r);
        }
    }
}

static inline void func_0035BD80_rc6(CGtSphereTree *t, const CGtSphereTreeSphere *s, EGtIntersectionResult r)
{
    CGtIntersectionResult res;
    if (r == 1) {
        UnkStruct_0035BD80_sph sc = s->field_0;
        r = IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustumP21CGtIntersectionResult(sc, *t->field_4C, &res);
        if (r == 0) return;
    }
    if (s->field_24 == 0) {
        t->field_54(s, r, res, t->field_58);
    } else {
        UnkStruct_0035BD80_n *n = s->field_28.field_0;
        while (n != &s->field_28) {
            const CGtSphereTreeSphere *c = (const CGtSphereTreeSphere *)((char *)n - 0x14);
            n = n->field_0;
            func_0035BD80_rc7(t, c, r);
        }
    }
}

static inline void func_0035BD80_rc5(CGtSphereTree *t, const CGtSphereTreeSphere *s, EGtIntersectionResult r)
{
    CGtIntersectionResult res;
    if (r == 1) {
        UnkStruct_0035BD80_sph sc = s->field_0;
        r = IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustumP21CGtIntersectionResult(sc, *t->field_4C, &res);
        if (r == 0) return;
    }
    if (s->field_24 == 0) {
        t->field_54(s, r, res, t->field_58);
    } else {
        UnkStruct_0035BD80_n *n = s->field_28.field_0;
        while (n != &s->field_28) {
            const CGtSphereTreeSphere *c = (const CGtSphereTreeSphere *)((char *)n - 0x14);
            n = n->field_0;
            func_0035BD80_rc6(t, c, r);
        }
    }
}

static inline void func_0035BD80_rc4(CGtSphereTree *t, const CGtSphereTreeSphere *s, EGtIntersectionResult r)
{
    CGtIntersectionResult res;
    if (r == 1) {
        UnkStruct_0035BD80_sph sc = s->field_0;
        r = IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustumP21CGtIntersectionResult(sc, *t->field_4C, &res);
        if (r == 0) return;
    }
    if (s->field_24 == 0) {
        t->field_54(s, r, res, t->field_58);
    } else {
        UnkStruct_0035BD80_n *n = s->field_28.field_0;
        while (n != &s->field_28) {
            const CGtSphereTreeSphere *c = (const CGtSphereTreeSphere *)((char *)n - 0x14);
            n = n->field_0;
            func_0035BD80_rc5(t, c, r);
        }
    }
}

static inline void func_0035BD80_rc3(CGtSphereTree *t, const CGtSphereTreeSphere *s, EGtIntersectionResult r)
{
    CGtIntersectionResult res;
    if (r == 1) {
        UnkStruct_0035BD80_sph sc = s->field_0;
        r = IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustumP21CGtIntersectionResult(sc, *t->field_4C, &res);
        if (r == 0) return;
    }
    if (s->field_24 == 0) {
        t->field_54(s, r, res, t->field_58);
    } else {
        UnkStruct_0035BD80_n *n = s->field_28.field_0;
        while (n != &s->field_28) {
            const CGtSphereTreeSphere *c = (const CGtSphereTreeSphere *)((char *)n - 0x14);
            n = n->field_0;
            func_0035BD80_rc4(t, c, r);
        }
    }
}

static inline void func_0035BD80_rc2(CGtSphereTree *t, const CGtSphereTreeSphere *s, EGtIntersectionResult r)
{
    CGtIntersectionResult res;
    if (r == 1) {
        UnkStruct_0035BD80_sph sc = s->field_0;
        r = IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustumP21CGtIntersectionResult(sc, *t->field_4C, &res);
        if (r == 0) return;
    }
    if (s->field_24 == 0) {
        t->field_54(s, r, res, t->field_58);
    } else {
        UnkStruct_0035BD80_n *n = s->field_28.field_0;
        while (n != &s->field_28) {
            const CGtSphereTreeSphere *c = (const CGtSphereTreeSphere *)((char *)n - 0x14);
            n = n->field_0;
            func_0035BD80_rc3(t, c, r);
        }
    }
}

static inline void func_0035BD80_rc1(CGtSphereTree *t, const CGtSphereTreeSphere *s, EGtIntersectionResult r)
{
    CGtIntersectionResult res;
    if (r == 1) {
        UnkStruct_0035BD80_sph sc = s->field_0;
        r = IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustumP21CGtIntersectionResult(sc, *t->field_4C, &res);
        if (r == 0) return;
    }
    if (s->field_24 == 0) {
        t->field_54(s, r, res, t->field_58);
    } else {
        UnkStruct_0035BD80_n *n = s->field_28.field_0;
        while (n != &s->field_28) {
            const CGtSphereTreeSphere *c = (const CGtSphereTreeSphere *)((char *)n - 0x14);
            n = n->field_0;
            func_0035BD80_rc2(t, c, r);
        }
    }
}

// 0x0035BD80
void CGtSphereTree::RecursiveFrustumTestResult(const CGtSphereTreeSphere *s, EGtIntersectionResult r)
{
    CGtSphereTree *t = this;
    CGtIntersectionResult res;
    if (r == 1) {
        UnkStruct_0035BD80_sph sc = s->field_0;
        r = IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustumP21CGtIntersectionResult(sc, *t->field_4C, &res);
        if (r == 0) return;
    }
    if (s->field_24 == 0) {
        t->field_54(s, r, res, t->field_58);
    } else {
        UnkStruct_0035BD80_n *n = s->field_28.field_0;
        while (n != &s->field_28) {
            const CGtSphereTreeSphere *c = (const CGtSphereTreeSphere *)((char *)n - 0x14);
            n = n->field_0;
            func_0035BD80_rc1(t, c, r);
        }
    }
}
