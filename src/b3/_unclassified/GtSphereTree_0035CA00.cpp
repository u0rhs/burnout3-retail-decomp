// CGtSphereTree::RemoveChild(CGtSphereTreeSphere*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSphereTree.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (RemoveChild/FreeParentSphere/AddToRecomputeList inlined 8 deep as static inline chain; parent field_10 typed int (int null test gives retail's leaf block layout)).

// CGtSphereTree::RemoveChild -- CGtSphereTree::RemoveChild / FreeParentSphere / AddToRecomputeList (all in this file,
// GtSphereTree.cpp) inlined 8 levels deep: MWCC's depth-limited expansion of a recursive inline, written out here as a
// chain of static inline helpers with placeholder names [L]; at the cut the real methods are called.

struct UnkStruct_0035CA00_n;

struct UnkStruct_0035CA00_n {
    UnkStruct_0035CA00_n * field_0;
    UnkStruct_0035CA00_n * field_4;
};

struct CGtSphereTreeSphere {
    unsigned char pad_0[0x10];
    int field_10;  // [G] parent sphere, held as an integer: an integer null test is what gives retail's leaf layout
    UnkStruct_0035CA00_n * field_14;  // [G] list node (next, prev) at +0x14
    UnkStruct_0035CA00_n * field_18;
    UnkStruct_0035CA00_n * field_1C;  // [G] list node (next, prev) at +0x1C
    UnkStruct_0035CA00_n * field_20;
    int field_24;
};

class CGtSphereTree {
public:
    void AddToRecomputeList(CGtSphereTreeSphere*);
    void RemoveChild(CGtSphereTreeSphere*);
    void FreeParentSphere(CGtSphereTreeSphere*);

    unsigned char pad_0[0x8];
    UnkStruct_0035CA00_n * field_8;  // [G] list heads (next, prev) at +0x8, +0x10, +0x18
    UnkStruct_0035CA00_n * field_C;
    UnkStruct_0035CA00_n * field_10;
    UnkStruct_0035CA00_n * field_14;
    UnkStruct_0035CA00_n * field_18;
    UnkStruct_0035CA00_n * field_1C;
    unsigned char pad_20[0x1C];
    int field_3C;
};

// inlined helpers (placeholder names; bodies of CGtSphereTree::FreeParentSphere / AddToRecomputeList /
// RemoveChild, expanded level by level) [G]
static inline void func_0035CA00_free(CGtSphereTree * t, CGtSphereTreeSphere * p)
{
    if (p->field_1C != 0) {
        p->field_20->field_0 = p->field_1C;
        p->field_1C->field_4 = p->field_20;
    }
    p->field_14 = t->field_18;
    p->field_18 = (UnkStruct_0035CA00_n *)&t->field_18;
    t->field_18->field_4 = (UnkStruct_0035CA00_n *)&p->field_14;
    t->field_18 = (UnkStruct_0035CA00_n *)&p->field_14;
    t->field_3C++;
}

static inline void func_0035CA00_recomp(CGtSphereTree * t, CGtSphereTreeSphere * p)
{
    if (p->field_1C == 0) {
        p->field_1C = t->field_10;
        p->field_20 = (UnkStruct_0035CA00_n *)&t->field_10;
        t->field_10->field_4 = (UnkStruct_0035CA00_n *)&p->field_1C;
        t->field_10 = (UnkStruct_0035CA00_n *)&p->field_1C;
    }
}

static inline void func_0035CA00_rc9(CGtSphereTree * t, CGtSphereTreeSphere * s)
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

static inline void func_0035CA00_rc8(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035CA00_rc9(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035CA00_free(t, p);
    } else {
        func_0035CA00_recomp(t, p);
    }
}

static inline void func_0035CA00_rc7(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035CA00_rc8(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035CA00_free(t, p);
    } else {
        func_0035CA00_recomp(t, p);
    }
}

static inline void func_0035CA00_rc6(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035CA00_rc7(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035CA00_free(t, p);
    } else {
        func_0035CA00_recomp(t, p);
    }
}

static inline void func_0035CA00_rc5(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035CA00_rc6(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035CA00_free(t, p);
    } else {
        func_0035CA00_recomp(t, p);
    }
}

static inline void func_0035CA00_rc4(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035CA00_rc5(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035CA00_free(t, p);
    } else {
        func_0035CA00_recomp(t, p);
    }
}

static inline void func_0035CA00_rc3(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035CA00_rc4(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035CA00_free(t, p);
    } else {
        func_0035CA00_recomp(t, p);
    }
}

static inline void func_0035CA00_rc2(CGtSphereTree * t, CGtSphereTreeSphere * s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035CA00_rc3(t, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035CA00_free(t, p);
    } else {
        func_0035CA00_recomp(t, p);
    }
}

// 0x0035CA00
void CGtSphereTree::RemoveChild(CGtSphereTreeSphere* s)
{
    CGtSphereTreeSphere * p = (CGtSphereTreeSphere *)s->field_10;
    s->field_18->field_0 = s->field_14;
    s->field_14->field_4 = s->field_18;
    p->field_24--;
    s->field_10 = 0;
    if (p->field_24 == 0) {
        if (p->field_10 != 0) {
            func_0035CA00_rc2(this, p);
        } else {
            p->field_18->field_0 = p->field_14;
            p->field_14->field_4 = p->field_18;
        }
        func_0035CA00_free(this, p);
    } else {
        func_0035CA00_recomp(this, p);
    }
}
