// Hand-written; the lifter refused it (ghvu19: _ColWorldCallbackLeaf [L DNAT]; local CGtV3d p[3] array keeps retail's three dead vertex stores, 0x60 N140 pad, CGtRandom::Random() x3 with const 2^-32 local, Im3d SetColour (RenderSquare body), N185 operator+(YAxisType,float)/vmulx stand-ins).

// Hand-written (ghvu19, Ghidra draft + retail asm); the lifter refused it.
// [L] DNAT: _ColWorldCallbackLeaf(const CGtPolygonIntersectionResult&, void*) (research/proto/new_names.csv, high),
// B3PhysicsManagerDebug.cpp; the callback CB3PhysicsManagerDebug::DrawCollisionWorld passes when field_A is set.
#include "b3/GtMathPs2.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;
struct CGtTexture;
struct CGtPolygonIntersectionResult {
    unsigned char pad_0[0x20];
    CGtV3d field_20;
    CGtV3d field_30;
    CGtV3d field_40;
    unsigned char pad_50[0x18];
    void * field_68;
};
// [L] N185: stand-ins for GtMathPs2 inlines missing from the header (compiler-chosen VU registers).
static inline YAxisType func_002BDF00_addy(YAxisType a, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return YAxisType(r);
}
// CGtV4d::operator*(float) with the scalar moved by its own statement (as RenderSquare, B3VehicleDeform_00460A50.cpp)
static inline CGtV4d func_002BDF00_mul(const CGtV4d &v, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s)); return CGtV4d(t); }
// CGtV3dPlus::SetGtV3d(CGtV3d) reading its argument through its address (N129: the argument keeps its 16-byte slot)
static inline void func_002BDF00_set(CGtV3dPlus &d, const CGtV3d &v) { u_long128 m = d.mData; asm("vadd.xyz %0, $vf0, %1" : "+j"(m) : "j"(*(const u_long128*)&v.mData)); d.mData = m; }
// [G] N140 pad: retail's frame keeps six dead 16-byte slots below the vertex array (inlined vector/colour code)
struct UnkStruct_002BDF00_pad { int x[24]; UnkStruct_002BDF00_pad() {} ~UnkStruct_002BDF00_pad() {} };
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    unsigned char pad_10[8];
    unsigned int field_18;
    unsigned char pad_1C[4];
    // [L] CB3Im3dVertex::SetColour(GtMathPs2::CGtV4d) (B3O0PCH map, 0x44); [G] body as RenderSquare's (B3VehicleDeform_00460A50.cpp)
    void SetColour(CGtV4d c) {
        CGtV4d s = func_002BDF00_mul(c, 128.0f);
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
extern int _gnNumColWorldPoints;
extern CGtRandom _gRandomColour;
extern void *_gpPolySoupVertices;
extern CGtV4d D_01E86250;
extern CB3Im3dVertex D_01E85A50[];
extern "C" void BeginRendering__6B3Im3dFv();
extern "C" void SetTexture__6B3Im3dFP10CGtTexture(CGtTexture *);
extern "C" void RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(const CB3Im3dVertex *, int);
extern "C" void EndRendering__6B3Im3dFv();

// 0x002BDF00
extern "C" bool func_002BDF00(const CGtPolygonIntersectionResult &r, void *)
{
    float k = 0.0254f;
    if (r.field_68 != _gpPolySoupVertices) {
        _gpPolySoupVertices = r.field_68;
        const float k1 = 2.3283064e-10f;
        D_01E86250.SetX(0.5f * (0.8333333135f * (k1 * (float)_gRandomColour.Random())));
        D_01E86250.SetY(0.5f * (0.8333333135f * (k1 * (float)_gRandomColour.Random())));
        D_01E86250.SetZ(0.5f * (0.8333333135f * (k1 * (float)_gRandomColour.Random())));
    }
    CGtV3d p[3];
    UnkStruct_002BDF00_pad pad;
    p[0] = r.field_20;
    p[0].SetY(func_002BDF00_addy(p[0].Y(), k));
    p[1] = r.field_30;
    p[1].SetY(func_002BDF00_addy(p[1].Y(), k));
    p[2] = r.field_40;
    p[2].SetY(func_002BDF00_addy(p[2].Y(), k));
    int n = _gnNumColWorldPoints;
    CB3Im3dVertex &v0 = D_01E85A50[n];
    CB3Im3dVertex &v1 = D_01E85A50[n + 1];
    CB3Im3dVertex &v2 = D_01E85A50[n + 2];
    v0.field_0.SetGtV3d(p[0]);
    v1.field_0.SetGtV3d(p[1]);
    v2.field_0.SetGtV3d(p[2]);
    v0.SetColour(func_002BDF00_mul(D_01E86250, 1.2f));
    v1.SetColour(func_002BDF00_mul(D_01E86250, 1.0f));
    v2.SetColour(func_002BDF00_mul(D_01E86250, 0.8f));
    _gnNumColWorldPoints = n + 3;
    if (_gnNumColWorldPoints >= 0x3E) {
        BeginRendering__6B3Im3dFv();
        SetTexture__6B3Im3dFP10CGtTexture(0);
        RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(D_01E85A50, _gnNumColWorldPoints);
        EndRendering__6B3Im3dFv();
        _gnNumColWorldPoints = 0;
    }
    return true;
}
