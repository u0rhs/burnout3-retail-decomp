// CGtSphereTree::AddSphere(CGtSphereTreeSphere*,GtMathPs2::CGtV3d,float,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSphereTree.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sibling AddToIntegrateList inline chain one level shorter + header CGtSphere setters).

// CGtSphereTree::AddSphere(CGtSphereTreeSphere*,GtMathPs2::CGtV3d,float,void*) -- hand-finished from the proven sibling
// CGtSphereTree::AddToIntegrateList (GtSphereTree_0035D250.cpp, simfind 0.70).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSphereTree.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// AddSphere = CGtSphere SetPosition/SetRadius (header), field_34 = user data, then the inlined AddToIntegrateList body,
// whose RemoveChild chain is one level shorter here (rc2..rc8: 7 parents, retail s4,s3,s2,s1,s0,s6,s7) [L].

// Inline chain (from AddToIntegrateList) -- CGtSphereTree::RemoveChild / FreeParentSphere / AddToRecomputeList (all in this file,
// GtSphereTree.cpp) inlined 8 levels deep: MWCC's depth-limited expansion of a recursive inline, written out here as a
// chain of static inline helpers with placeholder names [L]; at the cut the real methods are called.

#include "b3/GtMathPs2.h"

struct UnkStruct_0035E750_n;

struct UnkStruct_0035E750_n {
    UnkStruct_0035E750_n * field_0;
    UnkStruct_0035E750_n * field_4;
};

struct CGtSphereTreeSphere {
    GtMathPs2::CGtSphere field_0;
    int field_10;  // [G] parent sphere, held as an integer: an integer null test is what gives retail's leaf layout
    UnkStruct_0035E750_n * field_14;  // [G] list node (next, prev) at +0x14
    UnkStruct_0035E750_n * field_18;
    UnkStruct_0035E750_n * field_1C;  // [G] list node (next, prev) at +0x1C
    UnkStruct_0035E750_n * field_20;
    int field_24;
    unsigned char pad_28[0xC];
    void * field_34;
};

class CGtSphereTree {
public:
    void AddSphere(CGtSphereTreeSphere* p0, GtMathPs2::CGtV3d p1, float p2, void* p3);
    void AddToRecomputeList(CGtSphereTreeSphere*);
    void RemoveChild(CGtSphereTreeSphere*);
    void FreeParentSphere(CGtSphereTreeSphere*);

    unsigned char pad_0[0x8];
    UnkStruct_0035E750_n * field_8;  // [G] list heads (next, prev) at +0x8, +0x10, +0x18
    UnkStruct_0035E750_n * field_C;
    UnkStruct_0035E750_n * field_10;
    UnkStruct_0035E750_n * field_14;
    UnkStruct_0035E750_n * field_18;
    UnkStruct_0035E750_n * field_1C;
    unsigned char pad_20[0x1C];
    int field_3C;
};

// inlined helpers (placeholder names; bodies of CGtSphereTree::FreeParentSphere / AddToRecomputeList /
// RemoveChild, expanded level by level) [G]
static inline void func_0035E750_free(CGtSphereTree * t, CGtSphereTreeSphere * p)
{
    if (p->field_1C != 0) {
        p->field_20->field_0 = p->field_1C;
        p->field_1C->field_4 = p->field_20;
    }
    p->field_14 = t->field_18;
    p->field_18 = (UnkStruct_0035E750_n *)&t->field_18;
    t->field_18->field_4 = (UnkStruct_0035E750_n *)&p->field_14;
    t->field_18 = (UnkStruct_0035E750_n *)&p->field_14;
    t->field_3C++;
}

static inline void func_0035E750_recomp(CGtSphereTree * t, CGtSphereTreeSphere * p)
{
    if (p->field_1C == 0) {
        p->field_1C = t->field_10;
        p->field_20 = (UnkStruct_0035E750_n *)&t->field_10;
        t->field_10->field_4 = (UnkStruct_0035E750_n *)&p->field_1C;
        t->field_10 = (UnkStruct_0035E750_n *)&p->field_1C;
    }
}

static inline void func_0035E750_rc8(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            t->RemoveChild(p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        t->FreeParentSphere(p);
    } else {
        t->AddToRecomputeList(p);
    }
}

static inline void func_0035E750_rc7(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035E750_rc8(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035E750_free(t, p);
    } else {
        func_0035E750_recomp(t, p);
    }
}

static inline void func_0035E750_rc6(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035E750_rc7(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035E750_free(t, p);
    } else {
        func_0035E750_recomp(t, p);
    }
}

static inline void func_0035E750_rc5(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035E750_rc6(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035E750_free(t, p);
    } else {
        func_0035E750_recomp(t, p);
    }
}

static inline void func_0035E750_rc4(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035E750_rc5(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035E750_free(t, p);
    } else {
        func_0035E750_recomp(t, p);
    }
}

static inline void func_0035E750_rc3(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035E750_rc4(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035E750_free(t, p);
    } else {
        func_0035E750_recomp(t, p);
    }
}

static inline void func_0035E750_rc2(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035E750_rc3(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035E750_free(t, p);
    } else {
        func_0035E750_recomp(t, p);
    }
}

// 0x0035E750
void CGtSphereTree::AddSphere(CGtSphereTreeSphere* p0, GtMathPs2::CGtV3d p1, float p2, void* p3)
{
    p0->field_0.SetPosition(p1);
    p0->field_0.SetRadius(p2);
    p0->field_34 = p3;
    p0->field_10 = 0;
    p0->field_24 = 0;
    if (p0->field_10 != 0) {
        func_0035E750_rc2(this, p0);
    }
    p0->field_14 = field_8;
    p0->field_18 = (UnkStruct_0035E750_n *)&field_8;
    field_8->field_4 = (UnkStruct_0035E750_n *)&p0->field_14;
    field_8 = (UnkStruct_0035E750_n *)&p0->field_14;
}
