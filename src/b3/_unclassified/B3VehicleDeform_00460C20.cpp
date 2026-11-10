// CB3VehicleDeform::RenderClampBoxes() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near31: SetX/Y/Z(axis) stand-ins read through address + N140 pads (72 inline + 1) and a per-iteration const CGtV4d colour local give retail's 0xCF0 frame).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// N140 frame pad [G]: retail keeps 72 dead 16-byte inline-local slots (0xA0-0x520, one per SetX/Y/Z(axis) call
// below; stand-in for the real inline's dead by-value lane copy) and one dead slot between box and p (0x9C0).
struct UnkStruct_00460C20_pad { int x[4]; UnkStruct_00460C20_pad() {} ~UnkStruct_00460C20_pad() {} };
namespace GtMathPs2 {
// [L] N185: stand-ins for GtMathPs2 inlines whose header bodies hard-code a scalar register (retail: compiler-chosen).
// CGtV3dPlus::SetPlus(float) (B3O0PCH map, 72 bytes): the scalar moved by its own statement, as CGtV4d::SetW.
static inline void func_00460C20_inl1(CGtV3dPlus &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddx.w %0, %0, %1x" : "+j"(d.mData) : "j"(s)); }
// CGtV3d::SetX/SetY/SetZ(float) (B3O0PCH map, 48 bytes) with the scalar on a compiler-chosen register (cf. v241_tx)
static inline void func_00460C20_tx(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00460C20_ty(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00460C20_tz(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
// CGtV4d::operator*(float) with the scalar moved by its own statement (hoisted out of the colour loop in retail)
static inline CGtV4d func_00460C20_mul(const CGtV4d &v, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s)); return CGtV4d(t); }
// [L] CGtV3d::SetX/SetY/SetZ(axis) (B3O0PCH map) with the argument read through its address ([G]: the N129 slot,
// as RenderNearMissData's stand-ins)
static inline void func_00460C20_sx(CGtV3d &v, XAxisType a) { UnkStruct_00460C20_pad pad; asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(*(const u_long128 *)&a.lVector)); }
static inline void func_00460C20_sy(CGtV3d &v, YAxisType a) { UnkStruct_00460C20_pad pad; asm("vaddy.y %0, $vf0, %1y" : "+j"(v.mData) : "j"(*(const u_long128 *)&a.lVector)); }
static inline void func_00460C20_sz(CGtV3d &v, ZAxisType a) { UnkStruct_00460C20_pad pad; asm("vaddz.z %0, $vf0, %1z" : "+j"(v.mData) : "j"(*(const u_long128 *)&a.lVector)); }
}
class CGtTexture;
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    unsigned char pad_10[8];
    unsigned int field_18;
    unsigned char pad_1C[4];
    // [L] CB3Im3dVertex::CB3Im3dVertex() / Construct() (B3O0PCH map); [G] body: w = 0
    CB3Im3dVertex() { func_00460C20_inl1(field_0, 0.0f); }
    // [L] CB3Im3dVertex::SetColour(GtMathPs2::CGtV4d) (B3O0PCH map, 0x44); [G] body: col * 128, to int, clamped to (255,255,255,128), packed
    void SetColour(const CGtV4d &c) {
        CGtV4d s = func_00460C20_mul(c, 128.0f);
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
void func_00364670(const void *m, const CB3Im3dVertex *v, int n);
void func_003E6C20(void *self, int i, void *out);
void EndRendering__6B3Im3dFv();
}
class CB3VehicleDeform {
public:
    void RenderClampBoxes();
    unsigned char pad_0[0x10];
    CGtMatrix3x4 *field_10;
};

// [G] the out-parameter of func_003E6C20 (a clamp box's two corners: lqc2 0x0 / 0x10 of the buffer)
struct UnkStruct_00460C20_box {
    CGtV3d field_0;
    CGtV3d field_10;
};

// 0x00460C20
void CB3VehicleDeform::RenderClampBoxes()
{
    CB3Im3dVertex v[24];
    for (int i = 0; i < 24; i++) { const CGtV4d col(0.6f, 1.0f, 0.6f, 1.0f); v[i].SetColour(col); }   // [G] a per-iteration local: retail's colour at 0x520
    for (int b = 0; b < 7; b++) {
        UnkStruct_00460C20_box box;
        UnkStruct_00460C20_pad pad1;   // N140 [G]: retail's dead slot at 0x9C0
        CGtV3d p;
        func_003E6C20(this, b, &box);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_10.Z()); v[0].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_10.Z()); v[1].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_10.Z()); v[2].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_10.Z()); v[3].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_10.Z()); v[4].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_0.Z()); v[5].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_0.Z()); v[6].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_10.Z()); v[7].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_0.Z()); v[8].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_0.Z()); v[9].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_0.Z()); v[10].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_0.Z()); v[11].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_10.Z()); v[12].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_0.Z()); v[13].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_10.Z()); v[14].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_10.Z()); v[15].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_10.Z()); v[16].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_10.Z()); v[17].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_0.Z()); v[18].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_10.Z()); v[19].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_0.Z()); v[20].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_0.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_0.Z()); v[21].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_0.Y()); func_00460C20_sz(p, box.field_0.Z()); v[22].field_0.SetGtV3d(p);
        func_00460C20_sx(p, box.field_10.X()); func_00460C20_sy(p, box.field_10.Y()); func_00460C20_sz(p, box.field_0.Z()); v[23].field_0.SetGtV3d(p);
        BeginRendering__6B3Im3dFv();
        SetTexture__6B3Im3dFP10CGtTexture(0);
        func_00364670(field_10, v, 24);
        EndRendering__6B3Im3dFv();
    }
}
