// CB3VehicleDeform::GetVirtualBones(GtMathPs2::CGtV3d,signed char*,signed char*,float*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (FPU sqrt round-trip asm moved into its own static inline (creation order puts length in v1, dir in a0 as retail)).

// v278: 11 off, length equal. Fixed: nlen3's scale as a '+j' vmulq statement inside the region (no explicit qmfc2 of the normalised vector: retail's dir GPR move is compiler-made). Left: length in a0 / dir in v1 (retail: length v1, dir a0), and the dir qmtc2 to vf2 scheduled right after vmulq (retail: after the lqc2 of p and the 1.0 park). '+r' on the sqrt round trip or splitting it adds hazard nops. Header gap: retail's NormaliseGetLength-like inline uses FPU sqrt.s (mtc1/sqrt.s/mfc1 then qmtc2/qmfc2 through vf1) while Q computes

// CB3VehicleDeform::GetVirtualBones(GtMathPs2::CGtV3d, signed char*, signed char*, float*) -- [C] name: retail symbol table.
// Finds the two virtual bones nearest to pos (squared distance; bone 6 skipped), then the position of pos along the
// line between them (0..1). Types and fields are placeholders [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003E7390_self;
extern "C" CGtMatrix3x4 func_003E7390(UnkStruct_003E7390_self * self, int idx);   // [G] GetVirtualBoneMatrix (E order)

class CB3VehicleDeform {
public:
    void GetVirtualBones(CGtV3d pos, signed char * a, signed char * b, float * t);
};

static inline u_long128 func_003E7110_inl2(const XAxisType &l) { u_long128 a; float f;
    asm("qmtc2.i %2, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "qmfc2.i %0, $vf1" "\n\t" "mtc1 %0, %1" "\n\t"
        "sqrt.s %1, %1" "\n\t" "mfc1 %0, %1" "\n\t" "qmtc2.i %0, $vf1" "\n\t" "qmfc2.i %0, $vf1" : "=&r"(a), "=&f"(f) : "r"(l.lVector)); return a; }
// [L] N185: CGtV3d::NormaliseGetLength()-style stand-in (B3O0PCH map, 196 bytes; header's body returns 1/length): the
// squared length through a GPR, vrsqrt into Q, the length by sqrt.s on the FPU (one asm, in its own inline: pass2f) while
// Q computes, then the scale; the region as func_00353FA0's GetLength tail.
static inline XAxisType v272_nlen3(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 a;
    asm(".set noreorder");
    a = func_003E7110_inl2(l);
    asm("vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData));
    asm(".set reorder");
    return XAxisType(a);
}
// [L] N185: CGtV3d::operator-(const CGtV3d&) on compiler-chosen registers (N198's second vsub form) stand-in
static inline CGtV3d v272_sub(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
// [G] N140 frame pad (16 bytes, user ctor/dtor): retail keeps one more 16-byte slot below the caller's temporaries
struct UnkStruct_003E7110_pad { int x[4]; UnkStruct_003E7110_pad() {} ~UnkStruct_003E7110_pad() {} };
static inline CGtV3d v272_subp(const CGtV3d &a, const CGtV3d &b) { UnkStruct_003E7110_pad pad; return v272_sub(a, b); }

// 0x003E7110
void CB3VehicleDeform::GetVirtualBones(CGtV3d pos, signed char * a, signed char * b, float * t)
{
    CGtV3d p = pos;
    CGtV3d p1;
    int best[2];
    int *pb = &best[1];
    best[0] = 7;
    *pb = 7;
    float d1;
    float d0 = 3.402823466e+38f;
    d1 = d0;
    for (int i = 0; i < 7; i++) {
        if (i != 6) {
            float d = v272_sub(func_003E7390((UnkStruct_003E7390_self *)this, i).mPos, p).GetSquaredLength();
            if (d < d0) {
                *pb = best[0];
                d1 = d0;
                d0 = d;
                best[0] = i;
            } else if (d < d1) {
                d1 = d;
                *pb = i;
            }
        }
    }
    *a = best[0];
    *b = best[1];
    p1 = func_003E7390((UnkStruct_003E7390_self *)this, *a).mPos;
    const CGtV3d *pp2 = &func_003E7390((UnkStruct_003E7390_self *)this, *b).mPos;
    CGtV3d dir = v272_subp(p1, *pp2);
    float len = v272_nlen3(dir);
    float t1 = DotProduct(v272_sub(p, p1), dir);
    float t2 = DotProduct(v272_sub(p, *pp2), dir);
    if (t1 < 0.0f && t2 > 0.0f)
        *t = t2 / len;
    else if (t1 > 0.0f)
        *t = 1.0f;
    else
        *t = 0.0f;
}
