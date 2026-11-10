// NONMATCHING: RenderEnvmapBlob__14CB3SunRendererFv -- retail 212 / ours 214 instructions, 181 in changed runs
// ghvu12: structural draft (4 Im3d vertices SetPlus(0) ctors, sun billboard: cross(dir,up) / cross(r,dir) normalised, centre cam+dir*50, half-size 1.5, rg byte struct + b, GIF packet 8 quads as BeginShadowPlaneRendering); left: frame 0x1F0 vs 0x390 (~26 dead slots), colour byte stores unrolled in retail order, second cross result register, schedule
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [L] N185: compiler-chosen CGtV3d +/- stand-ins
static inline CGtV3d func_0024B3B0_add(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_0024B3B0_sub(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185: CrossProduct(a, b) with its result on a fresh compiler-chosen register (b stays live)
static inline CGtV3d func_0024B3B0_cross(const CGtV3d &a, const CGtV3d &b)
{ u_long128 r, t; asm("vopmula.xyz $ACC, %2, %3" "\n\t" "vopmsub.xyz %1, %3, %2" "\n\t" "qmfc2.ni %0, %1" : "=r"(t), "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
// [L] N185: in-place Normalise on a compiler-chosen register stand-in
static inline void func_0024B3B0_norm(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r = v.mData;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(r));
    asm(".set reorder");
    v.mData = r;
}

class CGtTexture;
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    float field_10;
    float field_14;
    unsigned char field_18[4];
    unsigned char pad_1C[4];
    CB3Im3dVertex() { field_0.SetPlus(0.0f); }   // [L] CB3Im3dVertex::CB3Im3dVertex() (B3O0PCH map); [G] body: w = 0 (RenderSquare)
};
extern "C" {
void BeginRendering__6B3Im3dFv();
void RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi(const CB3Im3dVertex *, int);
void EndRendering__6B3Im3dFv();
void _rwDMAOpenVIFPkt(int, int);
}
struct UnkStruct_0024B3B0_cam { unsigned char pad_0[0x1C0]; u_long128 field_1C0; u_long128 field_1D0; unsigned char pad_1E0[0x50]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x470]; UnkStruct_0024B3B0_cam field_470[1]; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_farFogPlane { u_long128 *field_0; };
struct UnkStruct_0024B3B0_rg { unsigned char r; unsigned char g; };
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_farFogPlane farFogPlane;
extern CGtV3d D_00666320;
extern CGtV3d D_01D9B940;
extern u_long128 D_01D9B950;
extern CGtV4d D_01D9B960;

class CB3SunRenderer {
public:
    static unsigned char mbBehind;
    static void RenderEnvmapBlob();
};

// 0x0024B3B0
void CB3SunRenderer::RenderEnvmapBlob()
{
    CB3Im3dVertex v[4];
    if (mbBehind) return;
    CGtV3d up(0.0f, 1.0f, 0.0f);
    CGtV3d cam = D_00666320;
    CGtV3d dir = D_01D9B940;
    CGtV3d r = CrossProduct(dir, up);
    func_0024B3B0_norm(r);
    CGtV3d u = func_0024B3B0_cross(r, dir);
    func_0024B3B0_norm(u);
    CGtV3d c = func_0024B3B0_add(cam, dir * 50.0f);
    r = r * 1.5f;
    u = u * 1.5f;
    v[0].field_10 = 0.0f; v[0].field_14 = 0.0f;
    v[1].field_10 = 1.0f; v[1].field_14 = 0.0f;
    v[2].field_10 = 0.0f; v[2].field_14 = 1.0f;
    v[3].field_10 = 1.0f; v[3].field_14 = 1.0f;
    CGtV4d col = D_01D9B960;
    UnkStruct_0024B3B0_rg rg;
    rg.r = (int)(float)col.X();
    rg.g = (int)(float)col.Y();
    unsigned char b = (int)(float)col.Z();
    for (int i = 0; i < 4; i++) {
        v[i].field_18[0] = rg.r;
        v[i].field_18[1] = rg.g;
        v[i].field_18[2] = b;
        v[i].field_18[3] = 0xFF;
    }
    v[0].field_0.SetGtV3d(func_0024B3B0_add(func_0024B3B0_sub(c, r), u));
    v[1].field_0.SetGtV3d(func_0024B3B0_add(func_0024B3B0_add(c, r), u));
    v[2].field_0.SetGtV3d(func_0024B3B0_sub(func_0024B3B0_sub(c, r), u));
    v[3].field_0.SetGtV3d(func_0024B3B0_sub(func_0024B3B0_add(c, r), u));
    BeginRendering__6B3Im3dFv();
    const u_long128 *cp = &D_00665EC0.field_470[D_00667050.field_0].field_1C0;
    _rwDMAOpenVIFPkt(0x80000000, 8);
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008007UL), "r"(0xE));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x3380D), "r"(0x47));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x44), "r"(0x42));
    *p++ = cp[0];
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)cp[1] | 0x100000000UL), "r"(0x4E));
    *p++ = D_01D9B950;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x61), "r"(0x14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(5), "r"(8));
    farFogPlane.field_0 = p;
    RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi(v, 4);
    EndRendering__6B3Im3dFv();
}
