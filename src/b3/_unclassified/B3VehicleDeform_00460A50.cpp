// CB3VehicleDeform::RenderSquare(float,float,float,float,float,float,GtMathPs2::CGtV4d*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (v242: Im3d square; SetPlus/SetX/Y/Z/operator*(float) stand-ins with the scalar on its own statement, SetColour inline (ppacb into a 32-bit asm output); the 1 'changed' is diff_vs_retail spelling vftoi0 with lane masks, words identical (v242_bytes.py)).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
namespace GtMathPs2 {
// [L] N185: stand-ins for GtMathPs2 inlines whose header bodies hard-code a scalar register (retail: compiler-chosen).
// CGtV3dPlus::SetPlus(float) (B3O0PCH map, 72 bytes): the scalar moved by its own statement, as CGtV4d::SetW.
static inline void func_00460A50_inl1(CGtV3dPlus &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddx.w %0, %0, %1x" : "+j"(d.mData) : "j"(s)); }
// CGtV3d::SetX/SetY/SetZ(float) (B3O0PCH map, 48 bytes) with the scalar on a compiler-chosen register (cf. v241_tx)
static inline void func_00460A50_tx(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00460A50_ty(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00460A50_tz(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
// CGtV4d::operator*(float) with the scalar moved by its own statement (hoisted out of the colour loop in retail)
static inline CGtV4d func_00460A50_mul(const CGtV4d &v, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s)); return CGtV4d(t); }
}
class CGtTexture;
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    unsigned char pad_10[8];
    unsigned int field_18;
    unsigned char pad_1C[4];
    // [L] CB3Im3dVertex::CB3Im3dVertex() / Construct() (B3O0PCH map); [G] body: w = 0
    CB3Im3dVertex() { func_00460A50_inl1(field_0, 0.0f); }
    // [L] CB3Im3dVertex::SetColour(GtMathPs2::CGtV4d) (B3O0PCH map, 0x44); [G] body: col * 128, to int, clamped to (255,255,255,128), packed
    void SetColour(CGtV4d c) {
        CGtV4d s = func_00460A50_mul(c, 128.0f);
        u_long128 i, lim, m, h;
        unsigned int b;
        asm("vftoi0.xyzw %0, %1" : "=j"(i) : "j"(s.mData));
        unsigned long k = 0x00FF00FFUL | (0x008000FFUL << 32);
        asm("pextlh %0, $0, %1" : "=r"(lim) : "r"(k));
        asm("pminw %0, %1, %2" : "=r"(m) : "r"(i), "r"(lim));
        asm("ppach %0, $0, %1" : "=r"(h) : "r"(m));
        asm("ppacb %0, $0, %1" : "=r"(b) : "r"(h));
        field_18 = b;
    }
};
extern "C" {
void BeginRendering__6B3Im3dFv();
void SetTexture__6B3Im3dFP10CGtTexture(CGtTexture *);
void RenderTristrip__6B3Im3dFRCQ29GtMathPs212CGtMatrix3x4PC13CB3Im3dVertexi(const CGtMatrix3x4 &, const CB3Im3dVertex *, int);
void EndRendering__6B3Im3dFv();
}
class CB3VehicleDeform {
public:
    void RenderSquare(float x0, float y0, float z0, float x1, float y1, float z1, CGtV4d *col);
    unsigned char pad_0[0x10];
    CGtMatrix3x4 *field_10;
};

// 0x00460A50
void CB3VehicleDeform::RenderSquare(float x0, float y0, float z0, float x1, float y1, float z1, CGtV4d *col)
{
    CB3Im3dVertex v[4];
    CGtV3d p;
    for (int i = 0; i < 4; i++) v[i].SetColour(*col);
    func_00460A50_tx(p, x0); func_00460A50_ty(p, y1); func_00460A50_tz(p, z0); v[0].field_0.SetGtV3d(p);
    func_00460A50_tx(p, x0); func_00460A50_ty(p, y0); func_00460A50_tz(p, z0); v[1].field_0.SetGtV3d(p);
    func_00460A50_tx(p, x1); func_00460A50_ty(p, y1); func_00460A50_tz(p, z1); v[2].field_0.SetGtV3d(p);
    func_00460A50_tx(p, x1); func_00460A50_ty(p, y0); func_00460A50_tz(p, z1); v[3].field_0.SetGtV3d(p);
    BeginRendering__6B3Im3dFv();
    SetTexture__6B3Im3dFP10CGtTexture(0);
    RenderTristrip__6B3Im3dFRCQ29GtMathPs212CGtMatrix3x4PC13CB3Im3dVertexi(*field_10, v, 4);
    EndRendering__6B3Im3dFv();
}
