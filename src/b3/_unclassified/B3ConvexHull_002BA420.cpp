// CB3ConvexHull::MakeBoatFromBoundingBox(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHull.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (MakeBox sibling shape; header CGtV3d::Set per vertex; entry copies with early addresses (pointer taken before each copy) + scoped opt_propagation off [G]; extern C const void* callee).

// CB3ConvexHull::MakeBoatFromBoundingBox(GtMathPs2::CGtV3d, GtMathPs2::CGtV3d) -- hand-written (ghvu7); sibling of
// MakeBoxFromBoundingBox (B3ConvexHull_002BA9F0.cpp). [C] name: the mangled symbol in retail's tables.
// Field names are placeholders and every type is [G] (instruction widths).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3ConvexHull;
// By-value callee called with pointers to the entry copies (as MakeFromBoundingBox, B3ConvexHull_002BA3A0.cpp).
extern "C" void ScaleAndFillInHullDetails__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(CB3ConvexHull *, const void *, const void *);
class CB3ConvexHull {
public:
    void MakeBoatFromBoundingBox(CGtV3d p0, CGtV3d p1);

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

static inline void func_002BA420_inl1(unsigned char *f, int a, int b, int c) { f[0] = a; f[1] = b; f[2] = c; }

// N182: `#pragma opt_propagation off` ([G] scoped to this function): keeps the early address setup of the copies.
#pragma push
#pragma opt_propagation off
// 0x002BA420
void CB3ConvexHull::MakeBoatFromBoundingBox(CGtV3d p0, CGtV3d p1)
{
    CGtV3d c0;
    CGtV3d c1;
    const void *pa = &c0;
    c0 = p0;
    const void *pb = &c1;
    c1 = p1;
    field_8[0].Set(0.0f, 0.0f, 0.0f);
    field_8[1].Set(1.0f, 0.0f, 0.0f);
    field_8[2].Set(1.0f, 0.5f, 0.0f);
    field_8[3].Set(0.0f, 0.5f, 0.0f);
    field_8[4].Set(0.1f, 1.0f, 0.5f);
    field_8[5].Set(0.9f, 1.0f, 0.5f);
    field_8[6].Set(0.5f, 0.6f, 1.0f);
    field_8[7].Set(0.5f, 0.0f, 0.8f);
    field_18 = 8;
    func_002BA420_inl1(&field_0[0], 0, 2, 1);
    func_002BA420_inl1(&field_0[3], 3, 2, 0);
    func_002BA420_inl1(&field_0[6], 7, 0, 1);
    func_002BA420_inl1(&field_0[9], 2, 3, 5);
    func_002BA420_inl1(&field_0[12], 3, 4, 5);
    func_002BA420_inl1(&field_0[15], 4, 6, 5);
    func_002BA420_inl1(&field_0[18], 5, 1, 2);
    func_002BA420_inl1(&field_0[21], 5, 7, 1);
    func_002BA420_inl1(&field_0[24], 5, 6, 7);
    func_002BA420_inl1(&field_0[27], 4, 3, 0);
    func_002BA420_inl1(&field_0[30], 4, 0, 7);
    func_002BA420_inl1(&field_0[33], 6, 0, 7);
    field_19 = 12;
    ScaleAndFillInHullDetails__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(this, pa, pb);
}
#pragma pop
