// func_00353E10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (parkfix: tool-bug park fixed (N213)).

// func_00353E10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (split locals (q, neg, callback struct) + N140 pad declared before struct).

// func_00353E10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_00353E10;
struct UnkStruct_00353E10_1;
struct UnkStruct_00353E10_4;
struct UnkStruct_00353E10_5;
struct UnkStruct_00353E10_a1;
struct UnkStruct_00353E10_a2;
struct UnkStruct_D_004EE040;
struct UnkStruct_func_00353FA0;

struct UnkStruct_00353E10_a2 {
    u_long128 field_0;
};

struct UnkStruct_00353E10_1 {
    u_long128 field_0;
    int field_10;
    float field_14;
    unsigned char field_18;
    unsigned char pad_19[0x7];
};

struct UnkStruct_00353E10_a1 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV3d field_10;
};

struct UnkStruct_00353E10_4 {
    unsigned char pad_0[0x204];
    UnkStruct_00353E10_5 * field_204;
};

struct UnkStruct_00353E10_5 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_00353FA0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00353E10 {
    unsigned char pad_0[0x1000];
    UnkStruct_00353E10_4 * field_1000;
    unsigned char pad_1004[0x44];
    unsigned char field_1048;
};

extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_func_00353FA0 func_00353FA0;

extern "C" void ForAllSpheresResult__13CGtSphereTreeFRC10CGtFrustumPFPC19CGtSphereTreeSphere21EGtIntersectionResultRC21CGtIntersectionResultPv_bPv(void *, const void *, const void *, void*);  // CGtSphereTree::ForAllSpheresResult(const CGtFrustum&,bool (*)(const CGtSphereTreeSphere*,EGtIntersectionResult,const CGtIntersectionResult&,void*),void*)
extern "C" int func_00131E40(void *);
extern "C" float func_00353C30(UnkStruct_00353E10 *, void *, void *, void *);

// N140 pad object (file scope, placeholder name): tools/drop_pad_dtor.py removes its out-of-line destructor. parkfix: a
// local `struct G` was mangled __dt__23G$1484func_00353E10_cppFv, which drop_pad_dtor does not match, so the copy (and its
// __dl__FPv reference: undefined in the link) stayed in the object.
struct UnkStruct_00353E10_pad { int x[4]; UnkStruct_00353E10_pad() {} ~UnkStruct_00353E10_pad() {} };

// 0x00353E10
extern "C" float func_00353E10(UnkStruct_00353E10 * self, UnkStruct_00353E10_a1 * p0, const UnkStruct_00353E10_a2 * p1)
{
    u_long128 q;
    GtMathPs2::CGtV3d neg;
    UnkStruct_00353E10_1 local;
    UnkStruct_00353E10_pad pad;
    q = p1->field_0;
    float v1 = 0.0f;
    if (func_00131E40(&D_004EE040) != 0) {
        neg = -p0->field_10;
        v1 = func_00353C30(self, &q, &self->field_1000->field_204->field_30, &neg);
    }
    if (0.0f == v1) {
        local.field_14 = 0.0f;
        local.field_0 = self->field_1000->field_204->field_30;
        local.field_10 = (int)self->field_1000;
        if (func_00131E40(&D_004EE040) == 0 && self->field_1048 != 0) {
            local.field_18 = 1;
        } else {
            local.field_18 = 0;
        }
        ForAllSpheresResult__13CGtSphereTreeFRC10CGtFrustumPFPC19CGtSphereTreeSphere21EGtIntersectionResultRC21CGtIntersectionResultPv_bPv(self, p0, (const void *)&func_00353FA0, (void*)&local);
        v1 = v1 + local.field_14;
    }
    return v1;
}
