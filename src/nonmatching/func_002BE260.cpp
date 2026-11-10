// NONMATCHING: func_002BE260 -- retail 321 / ours 320 instructions, 106 in changed runs
// ghvu18: DNAT _ColWorldCallback(const CGtPolygonIntersectionResult&, void*) (mode filter, material colour switch = jump table in retail, Y<-0.1 / 0x8000 overrides, three Im3d vertices + SetColour as the proven sibling func_002BDF00 _ColWorldCallbackLeaf, flush at 0x3E, centroid + 2*normal DrawLine). Logic complete, 320 vs 321 instrs, frame exact, 106 in changed runs. Left: CGtV4d(f,f,f,f) colour temps sit at the bottom of our frame (retail 0x1A0..0x250, just below the named locals); Y() lane read as addiu v1,sp,K+4 / lwc1 0(v1) (retail lwc1 K+4(sp), same gap as func_00355BD0's ysub); retail reloads the 0.7f lit4 for x and z; SetColour scalar VU numbering (retail 1.2->vf1, 128->vf2, 1.0->vf3); centroid reads p[1]/p[2] through addiu pointers and the normal through lqc2 (VU) where ours uses lq/sq. TU note: CGtPolygonIntersectionResult here adds field_10/field_60 to the sibling's layout -- reconcile on merge.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (ghvu18, Ghidra draft + retail asm + the proven sibling func_002BDF00 = _ColWorldCallbackLeaf).
// [L] DNAT: _ColWorldCallback(const CGtPolygonIntersectionResult&, void*) (research/proto/new_names.csv, medium),
// B3PhysicsManagerDebug.cpp. The second parameter is read as a filter mode (1, 2..3, 3) [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct CGtTexture;
struct UnkStruct_002BE260_mat { unsigned char pad_0[4]; unsigned short field_4; };
struct CGtPolygonIntersectionResult {
    unsigned char pad_0[0x10];
    CGtV3d field_10;
    CGtV3d field_20;
    CGtV3d field_30;
    CGtV3d field_40;
    unsigned char pad_50[0x10];
    UnkStruct_002BE260_mat * field_60;
    unsigned char pad_64[4];
    void * field_68;
};
struct CGtLine { CGtV3d field_0; CGtV3d field_10; };
// [L] N185: stand-ins for GtMathPs2 inlines missing from the header (compiler-chosen VU registers), as func_002BDF00
static inline YAxisType func_002BE260_addy(YAxisType a, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return YAxisType(r);
}
static inline CGtV4d func_002BE260_mul(const CGtV4d &v, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s)); return CGtV4d(t); }
static inline void func_002BE260_set(CGtV3dPlus &d, const CGtV3d &v) { u_long128 m = d.mData; asm("vadd.xyz %0, $vf0, %1" : "+j"(m) : "j"(*(const u_long128*)&v.mData)); d.mData = m; }
// [L] N185: compiler-chosen CGtV3d operator+(CGtV3d) / operator*(float)
static inline CGtV3d func_002BE260_add(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_002BE260_mulv(const CGtV3d &v, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s)); return CGtV3d(t); }
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    unsigned char pad_10[8];
    unsigned int field_18;
    unsigned char pad_1C[4];
    // [L] CB3Im3dVertex::SetColour(GtMathPs2::CGtV4d) (B3O0PCH map, 0x44); [G] body as RenderSquare's (B3VehicleDeform_00460A50.cpp)
    void SetColour(CGtV4d c) {
        CGtV4d s = func_002BE260_mul(c, 128.0f);
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
struct UnkStruct_P { unsigned char pad_0[0x10]; };
extern int _gnNumColWorldPoints;
extern CB3Im3dVertex D_01E85A50[];
extern UnkStruct_P D_004EB1E0;
extern "C" void BeginRendering__6B3Im3dFv();
extern "C" void SetTexture__6B3Im3dFP10CGtTexture(CGtTexture *);
extern "C" void RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(const CB3Im3dVertex *, int);
extern "C" void EndRendering__6B3Im3dFv();
extern "C" void DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(void *, const CGtLine &, CGtV4d);

// [G] placeholder inline: the triangle centroid
static inline CGtV3d func_002BE260_cen(const CGtV3d *v) { return func_002BE260_mulv(func_002BE260_add(func_002BE260_add(v[0], v[1]), v[2]), 0.3333333433f); }
// [G] placeholder inline: a material flag bit test
static inline int func_002BE260_bit(unsigned short f, int m) { return (f & m) != 0; }
// 0x002BE260
extern "C" bool func_002BE260(const CGtPolygonIntersectionResult &r, void *mode_)
{
    int mode = (int)mode_;
    float k = 0.0254f;
    UnkStruct_002BE260_mat * m = r.field_60;
    unsigned short fl = m->field_4;
    int type = fl & 0xFF;
    if (mode == 1) {
        if (type == 0x23 || type == 0x22 || func_002BE260_bit(fl, 0x1000))
            return true;
    } else if ((unsigned)(mode - 2) < 2) {
        if (type == 0x22 || type == 0x23 || type == 0x24 || type == 0x20)
            return true;
    }
    CGtV4d col;
    if (mode == 3) {
        if (func_002BE260_bit(fl, 0x400))
            col = CGtV4d(0.45f, 0.25f, 0.0f, 0.8333333135f);
        else if (func_002BE260_bit(fl, 0x800))
            col = CGtV4d(0.0f, 0.0f, 0.5f, 0.8333333135f);
        else
            col = CGtV4d(0.25f, 0.25f, 0.25f, 0.8333333135f);
    } else {
        switch (type) {
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
            col = CGtV4d(0.25f, 0.25f, 0.25f, 0.8333333135f);
            break;
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
            col = CGtV4d(0.45f, 0.25f, 0.0f, 0.8333333135f);
            break;
        case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
            col = CGtV4d(0.0f, 0.25f, 0.45f, 0.8333333135f);
            break;
        case 32:
            col = CGtV4d(0.0f, 0.5f, 0.0f, 0.8333333135f);
            break;
        case 36:
            col = CGtV4d(0.0f, 0.0f, 0.5f, 0.8333333135f);
            break;
        default:
            col = CGtV4d(0.0f, 0.0f, 0.0f, 0.8333333135f);
            break;
        }
        if (r.field_10.Y() < -0.1f)
            col = CGtV4d(1.0f, 0.0f, 0.0f, 1.0f);
        if (func_002BE260_bit(m->field_4, 0x8000))
            col = CGtV4d(0.7f, 0.0f, 0.7f, 1.0f);
    }
    CGtV3d p[3];
    p[0] = r.field_20;
    p[0].SetY(func_002BE260_addy(p[0].Y(), k));
    p[1] = r.field_30;
    p[1].SetY(func_002BE260_addy(p[1].Y(), k));
    p[2] = r.field_40;
    p[2].SetY(func_002BE260_addy(p[2].Y(), k));
    int n = _gnNumColWorldPoints;
    CB3Im3dVertex &v0 = D_01E85A50[n];
    CB3Im3dVertex &v1 = D_01E85A50[n + 1];
    CB3Im3dVertex &v2 = D_01E85A50[n + 2];
    v0.field_0.SetGtV3d(p[0]);
    v1.field_0.SetGtV3d(p[1]);
    v2.field_0.SetGtV3d(p[2]);
    v0.SetColour(func_002BE260_mul(col, 1.2f));
    v1.SetColour(func_002BE260_mul(col, 1.0f));
    v2.SetColour(func_002BE260_mul(col, 0.8f));
    _gnNumColWorldPoints = n + 3;
    if (_gnNumColWorldPoints >= 0x3E) {
        BeginRendering__6B3Im3dFv();
        SetTexture__6B3Im3dFP10CGtTexture(0);
        RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(D_01E85A50, _gnNumColWorldPoints);
        EndRendering__6B3Im3dFv();
        _gnNumColWorldPoints = 0;
    }
    CGtLine line;
    line.field_0 = func_002BE260_cen(p);
    CGtV3d nrm = r.field_10;
    line.field_10 = func_002BE260_add(line.field_0, func_002BE260_mulv(nrm, 2.0f));
    if (nrm.Y() < -0.1f)
        col = CGtV4d(1.0f, 0.0f, 0.0f, 1.0f);
    else
        col = CGtV4d(0.75f, 0.75f, 0.0f, 0.75f);
    DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(&D_004EB1E0, line, col);
    return true;
}
