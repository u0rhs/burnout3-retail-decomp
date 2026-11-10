// CB3ConvexHull::MakeBoxFromBoundingBox(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHull.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written: header Set(X,Y,Z)/SetNormal + [L] N185 lane-negate/SetDistance(Y/Z) stand-ins, face/edge inlines, one 0x4A0 N140 pad for the frame).

// CB3ConvexHull::MakeBoxFromBoundingBox(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d) -- hand-written (v305); the lifter refused it.
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3ConvexHull.cpp.
// Sibling of MakeConeFromBoundingBox (archived) and MakeFromBoundingBox (B3ConvexHull_002BA3A0.cpp).
// Field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3ConvexHull {
public:
    void MakeBoxFromBoundingBox(CGtV3d p0, CGtV3d p1);

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
extern CGtV3d D_004C1BD0;
extern CGtV3d D_004C1BE0;
extern CGtV3d D_004C1BF0;
extern CGtV3d D_004C1C00;
extern CGtV3d D_004C1C10;
extern CGtV3d D_004C1C20;

// [L] N185: stand-ins for the lane negations (B3O0PCH map: XAxisType/YAxisType/ZAxisType::operator-()), retail's
// `vsub.<l> D, $vf0, S` on compiler-chosen registers (the header's bodies hard-code $vf1 or multiply by -1)
static inline XAxisType v305_negx(XAxisType a) { u_long128 r; asm("vsub.x %0, $vf0, %1" : "=j"(r) : "j"(a.lVector)); return XAxisType(r); }
static inline YAxisType v305_negy(YAxisType a) { u_long128 r; asm("vsub.y %0, $vf0, %1" : "=j"(r) : "j"(a.lVector)); return YAxisType(r); }
static inline ZAxisType v305_negz(ZAxisType a) { u_long128 r; asm("vsub.z %0, $vf0, %1" : "=j"(r) : "j"(a.lVector)); return ZAxisType(r); }
// [L] N185: stand-ins for CGtPlane::SetDistance(XAxisType/YAxisType/ZAxisType) (B3O0PCH map): `vmul<l>.w D, $vf0, S<l>`
static inline void v305_sdx(CGtPlane *p, XAxisType a) { asm("vmulx.w %0, $vf0, %1x" : "+j"(p->mData) : "j"(a.lVector)); }
static inline void v305_sdy(CGtPlane *p, YAxisType a) { asm("vmuly.w %0, $vf0, %1y" : "+j"(p->mData) : "j"(a.lVector)); }
static inline void v305_sdz(CGtPlane *p, ZAxisType a) { asm("vmulz.w %0, $vf0, %1z" : "+j"(p->mData) : "j"(a.lVector)); }
static inline void v305_face(unsigned char *f, int a, int b, int c) { f[0] = a; f[1] = b; f[2] = c; }
static inline void v305_edge(unsigned char *e, int a, int b) { e[0] = a; e[1] = b; }

// N140 frame-slot pad: an unused local with an empty ctor/dtor reserves frame space and emits no code
struct UnkStruct_002BA9F0_pad { int x[0x128]; UnkStruct_002BA9F0_pad() {} ~UnkStruct_002BA9F0_pad() {} };

// 0x002BA9F0
void CB3ConvexHull::MakeBoxFromBoundingBox(CGtV3d p0, CGtV3d p1)
{
    // [G] N140: retail's frame is 0x530 (0x4A0 above the saved registers) with no live local: the dead 16-byte slots of
    // the inlined by-value vector/lane temporaries, which b119 drops
    UnkStruct_002BA9F0_pad pad;
    field_14 = 0;
    field_8[0].Set(p0.X(), p1.Y(), p1.Z());
    field_8[1].Set(p1.X(), p1.Y(), p1.Z());
    field_8[2].Set(p1.X(), p1.Y(), p0.Z());
    field_8[3].Set(p0.X(), p1.Y(), p0.Z());
    field_8[7].Set(p0.X(), p0.Y(), p1.Z());
    field_8[6].Set(p1.X(), p0.Y(), p1.Z());
    field_8[5].Set(p1.X(), p0.Y(), p0.Z());
    field_8[4].Set(p0.X(), p0.Y(), p0.Z());
    field_18 = 8;
    field_4[0].SetNormal(D_004C1C20);
    field_4[1].SetNormal(D_004C1C10);
    field_4[2].SetNormal(D_004C1BD0);
    field_4[3].SetNormal(D_004C1BE0);
    field_4[4].SetNormal(D_004C1C00);
    field_4[5].SetNormal(D_004C1BF0);
    field_4[6].SetNormal(D_004C1BD0);
    field_4[7].SetNormal(D_004C1BE0);
    field_4[8].SetNormal(D_004C1C00);
    field_4[9].SetNormal(D_004C1BF0);
    field_4[10].SetNormal(D_004C1C10);
    field_4[11].SetNormal(D_004C1C20);
    v305_sdy(&field_4[0], v305_negy(p0.Y()));
    v305_sdy(&field_4[1], p1.Y());
    v305_sdz(&field_4[2], v305_negz(p0.Z()));
    v305_sdx(&field_4[3], p1.X());
    v305_sdz(&field_4[4], p1.Z());
    v305_sdx(&field_4[5], v305_negx(p0.X()));
    v305_sdz(&field_4[6], v305_negz(p0.Z()));
    v305_sdx(&field_4[7], p1.X());
    v305_sdz(&field_4[8], p1.Z());
    v305_sdx(&field_4[9], v305_negx(p0.X()));
    v305_sdy(&field_4[10], p1.Y());
    v305_sdy(&field_4[11], v305_negy(p0.Y()));
    field_19 = 12;
    v305_face(&field_0[0], 4, 5, 6);
    v305_face(&field_0[3], 0, 1, 2);
    v305_face(&field_0[6], 3, 2, 5);
    v305_face(&field_0[9], 2, 1, 6);
    v305_face(&field_0[12], 1, 0, 7);
    v305_face(&field_0[15], 0, 3, 4);
    v305_face(&field_0[18], 3, 5, 4);
    v305_face(&field_0[21], 2, 6, 5);
    v305_face(&field_0[24], 1, 7, 6);
    v305_face(&field_0[27], 0, 4, 7);
    v305_face(&field_0[30], 0, 2, 3);
    v305_face(&field_0[33], 4, 6, 7);
    v305_edge(&field_C[0], 0, 1);
    v305_edge(&field_C[2], 1, 2);
    v305_edge(&field_C[4], 2, 3);
    v305_edge(&field_C[6], 3, 0);
    v305_edge(&field_C[8], 0, 2);
    v305_edge(&field_C[10], 4, 5);
    v305_edge(&field_C[12], 5, 6);
    v305_edge(&field_C[14], 6, 7);
    v305_edge(&field_C[16], 7, 4);
    v305_edge(&field_C[18], 4, 6);
    v305_edge(&field_C[20], 0, 7);
    v305_edge(&field_C[22], 1, 6);
    v305_edge(&field_C[24], 2, 5);
    v305_edge(&field_C[26], 3, 4);
    v305_edge(&field_C[28], 0, 4);
    v305_edge(&field_C[30], 3, 5);
    v305_edge(&field_C[32], 2, 6);
    v305_edge(&field_C[34], 1, 7);
    field_1A = 18;
}
