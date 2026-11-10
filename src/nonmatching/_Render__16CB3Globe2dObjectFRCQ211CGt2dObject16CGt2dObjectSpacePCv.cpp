// NONMATCHING: _Render__16CB3Globe2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 2383 / ours 2218 instructions, 2585 in changed runs
// draft3 first full draft: 2150/2383, frame 0x6F0 vs 0xB10. Math op counts agree (2 vrsqrt, 20 TransformPoint vmulax, 22 trig ctc2, 23 div.s); call sequence identical. Left: retail has 15 matrix lb/sb copy loops (ours 3), its meridian/polar flushes inline (ours out of line), stack-slot layout. Stand-ins: RGBA pack, CreateRotationMatrix3x4, vertex store, highlight-region loop (local inlines) | N259: CreateRotationMatrix3x4 + lane ops via the header
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra as reading aid), every branch, call, store and loop bound accounted for; highlight cases share one inline with the per-case constants

// draft3: CB3Globe2dObject::_Render(const CGt2dObject::CGt2dObjectSpace&, const void*) (0x3B2EE0, 2383 instructions),
// written from the retail asm (Ghidra 12.1.4 as reading aid). No Revenge counterpart (B4 has no Globe2dObject).
// [L] the front-end globe: a wireframe (meridians, polar caps, parallels) plus a textured surface and an optional
// highlighted region, morphed between a sphere and a flat map by the object's shape value; then the halo.
// [C] names: the mangled symbols in retail's tables (calls), research/E_B3O0PCH_symbols.csv (CB3Globe2dStaticData,
// CB3Im3dVertex, B3Im3d::*, GtMathPs2::Interpolate/TransformPoint). Types and field meanings [G] (instruction widths, use).
// Local stand-ins for inlines the headers lack:
//   inl1 = [G] RGBA pack (col * 128, vftoi0, clamped to (255,255,255,128), ppach/ppacb), as CB3Im3dVertex::SetColour's body
//          in B3VehicleDeform_00460C20.cpp but into an RwRGBA; the clamp constant lives in a stack u_long128 (retail 0x100(sp));
//   inl2 = [L] the E map's GtMathPs2::CreateRotationMatrix3x4(CGtV3d, float) (draft1's decode, same body);
//   inl3 = [G] vertex store: pos.SetW(w) then xyz = p (`vsubw.w; vaddx.w; vadd.xyz v, vf0, p` in place), colour bytes, uv.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;
#pragma opt_classresults on      // [G] file-wide (pragma policy N182): brings retail's matrix copy loops back (lb 1 -> 7) and the changed runs 3376 -> 2653

struct RwRGBA { unsigned char red, green, blue, alpha; };   // [L] RW 3.x layout (DrawGlobeHalo takes one by value)

// [L] name: E map B3Im3d::RenderLinelist(const CB3Im3dVertex*, int); layout [G] (0x20 stride, uv at +0x10, colour at +0x18)
struct CB3Im3dVertex {
    CGtV4d field_0;             // [G] position, w = 0
    float field_10;             // [G] u
    float field_14;             // [G] v
    RwRGBA field_18;
    unsigned char pad_1C[4];
};

// [L] the type of gmpStaticGlobeData: E map CB3Globe2dStaticData (Construct, CalculatePlanePoint/SpherePoint/CylinderPoint).
// Three 33 x 65 point grids (latitude rows x longitude columns, 5.625 degrees apart) and a vertex buffer.
struct CB3Globe2dStaticData {
    CGtV3d field_0[33][65];         // [G] sphere points (the highlight strips read only this grid)
    CGtV3d field_8610[33][65];      // [G] cylinder points (shifted by the latitude offset)
    CGtV3d field_10C20[33][65];     // [G] plane points (shifted by both offsets, scaled by 100)
    CB3Im3dVertex field_19230[66];  // [G] size: at most 66 vertices are written before a flush
};

// [G] the render data block (CB3Globe2dObject + 0x20, as the Set* methods' offsets minus 0x20)
struct UnkStruct_003B2EE0_d {
    float field_0;              // [G] position x (SetPos)
    float field_4;
    float field_8;
    unsigned short field_C;     // [L] latitude, 0..65535 = 0..180 degrees (SetGlobeLocation)
    unsigned short field_E;     // [L] longitude, 0..65535 = 0..360 degrees
    unsigned short field_10;    // [L] SetShape p0 (0xFFFF: halo keeps its alpha); spins the globe by up to 28.125 degrees
    unsigned short field_12;    // [L] SetShape p1: 0 sphere .. 65535 flat
    unsigned char field_14;     // [L] SetGlobeAlpha
    unsigned char field_15;     // [L] SetGlobeReveal: < 0x80 wireframe partly drawn, >= 0x80 surface strips
    unsigned char field_16;     // [L] SetHighlight amount
    signed char field_17;       // [L] SetHighlight region (0, 1, 2; else none)
};

class CGtTexture;
class CB3GraphicsManager { public: void BuildCustomCameraData(int); };
extern CB3GraphicsManager D_00665EC0;
extern int D_00667050;
namespace B3Im3d {
void BeginRendering();
void EndRendering();
void SetAlphaTestThreshold(float);
void SetTexture(CGtTexture *);
void SetZWrite(bool);
void SetLineAntialiasing(bool);
void SetBackfaceCull(bool);
void RenderLinelist(const CB3Im3dVertex *, int);
void RenderTristrip(const CB3Im3dVertex *, int);
}
extern CGtTexture *D_01EA4608;      // [G] globe surface texture
extern CGtTexture *D_01EA460C;      // [G] highlight textures for regions 0, 2, 1
extern CGtTexture *D_01EA4614;
extern CGtTexture *D_01EA4618;
extern CGtV3d kRight;
extern CGtV3d kUp;
extern "C" void _rwDMAOpenVIFPkt(unsigned int, int);
struct UnkStruct_003B2EE0_pkt { u_long128 field_0; u_long128 field_10; };
struct UnkStruct_003B2EE0_fog { UnkStruct_003B2EE0_pkt *field_0; };   // [L] the DMA packet write pointer (as B3SparkRendererPS2.cpp)
extern UnkStruct_003B2EE0_fog farFogPlane;

class CB3Globe2dObject {
public:
    static void _Render(const CGt2dObject::CGt2dObjectSpace &space, const void *data);
    static void DrawInvisiblePolys(CGtV3d);
    static void DrawGlobeHalo(CGtV3d, RwRGBA, float);
    static CB3Globe2dStaticData *gmpStaticGlobeData;
};

static inline RwRGBA func_003B2EE0_inl1(const CGtV4d &c, unsigned long k)
{
    CGtV4d s = c * 128.0f;
    u_long128 i, lim, m, h;
    unsigned int b;
    asm("vftoi0.xyzw %0, %1" : "=j"(i) : "j"(s.mData));
    asm("pextlh %0, $0, %1" : "=r"(lim) : "r"(k));
    asm("pminw %0, %1, %2" : "=r"(m) : "r"(i), "r"(lim));
    asm("ppach %0, $0, %1" : "=r"(h) : "r"(m));
    asm("ppacb %0, $0, %1" : "=r"(b) : "r"(h));
    union { unsigned int u; RwRGBA c; } r;
    r.u = b;
    return r.c;
}

static inline CGtMatrix3x4 func_003B2EE0_inl2_unused(CGtV3d axis, float angle)
{
    axis.Normalise();
    CGtV4d sc = SinCosFast(angle);
    float s = sc.f[0];
    float c = sc.f[1];
    float k = 1.0f - c;
    float x = axis.X(), y = axis.Y(), z = axis.Z();
    CGtMatrix3x4 m;
    m.mRight = CGtV3d(1.0f - (1.0f - x * x) * k, x * y * k + z * s, z * x * k - y * s);
    m.mUp = CGtV3d(x * y * k - z * s, 1.0f - (1.0f - y * y) * k, y * z * k + x * s);
    m.mAt = CGtV3d(z * x * k + y * s, y * z * k - x * s, 1.0f - (1.0f - z * z) * k);
    m.mPos.Zero();
    return m;
}

static inline void func_003B2EE0_inl3(CB3Im3dVertex &v, CGtV3d p, float w, RwRGBA c)
{
    v.field_0.SetW(w);
    asm("vadd.xyz %0, $vf0, %1" : "+j"(v.field_0.mData) : "j"(p.mData));
    v.field_18 = c;
}

// [L] one wireframe/surface point: the cylinder point blended onto the sphere (factor 1), placed by the globe matrix,
// then morphed towards the scrolled plane point by the shape value
static inline CGtV3d func_003B2EE0_inl4(const CB3Globe2dStaticData *g, int r, int c, const CGtMatrix3x4 &m,
                                        const CGtV3d &offUp, const CGtV3d &offRight, float shape)
{
    CGtV3d p = TransformPoint(m, Interpolate(g->field_8610[r][c] + offUp, g->field_0[r][c], 1.0f));
    CGtV3d q = (g->field_10C20[r][c] + offUp + offRight) * 100.0f + m.mPos;
    return Interpolate(p, q, shape);
}

// [G] one highlighted region: a 16-column textured patch of the sphere grid (retail has one inlined copy per case,
// the constants folded; whether Criterion wrote an inline or three loops is unknown)
static inline void func_003B2EE0_inl5(CGtTexture *tex, int base, int row0, int rows, float vs, const CGtMatrix3x4 &m,
                                      RwRGBA col, int &n)
{
    B3Im3d::SetTexture(tex);
    float w = 0.0f;
    for (int c = 0; c < 16; c++) {
        float u0 = (float)(16 - (c + 1)) / 16.0f;
        float u1 = (float)(16 - c) / 16.0f;
        for (int r = 0; r <= rows; r++) {
            float v = (float)(rows - r) / vs;
            CB3Im3dVertex *b = CB3Globe2dObject::gmpStaticGlobeData->field_19230;
            func_003B2EE0_inl3(b[n], TransformPoint(m, CB3Globe2dObject::gmpStaticGlobeData->field_0[row0 + r][base + c + 1]),
                               w, col);
            b[n].field_10 = u0;
            b[n].field_14 = v;
            func_003B2EE0_inl3(b[n + 1], TransformPoint(m, CB3Globe2dObject::gmpStaticGlobeData->field_0[row0 + r][base + c]),
                               w, col);
            b[n + 1].field_10 = u1;
            b[n + 1].field_14 = v;
            n += 2;
        }
        if (n > 0) {
            B3Im3d::RenderTristrip(CB3Globe2dObject::gmpStaticGlobeData->field_19230, n);
            n = 0;
        }
    }
}

// 0x003B2EE0
void CB3Globe2dObject::_Render(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_003B2EE0_d *d = (const UnkStruct_003B2EE0_d *)data;
    float alpha = (float)(unsigned int)d->field_14 / 255.0f;
    CGtV4d haloCol = space.mColour;
    CGtV4d surfCol = haloCol;
    surfCol.SetW(surfCol.W() * alpha);
    if (d->field_10 != 0xFFFF)
        haloCol.SetA(0.0f);
    unsigned long k = 0x00FF00FFUL | (0x008000FFUL << 32);
    float f = 0.75f * alpha + 0.25f;
    RwRGBA surfRgba = func_003B2EE0_inl1(surfCol, k);
    RwRGBA haloRgba = func_003B2EE0_inl1(haloCol, k);
    RwRGBA lineRgba = func_003B2EE0_inl1(CGtV4d(0.8156862855f * f, 0.8980392218f * f, f, 1.0f) * space.mColour, k);
    float shape = (float)(unsigned int)d->field_12 / (float)65535;
    float lat = 180.0f * (float)(unsigned int)d->field_C / (float)65535;
    float oneMinus = 1.0f - shape;
    float lon = 360.0f * (float)(unsigned int)d->field_E / (float)65535;
    lon = 0.0f + lon - 28.125f * ((float)(unsigned int)d->field_10 / (float)65535) * oneMinus;
    if (lon < 0.0f)
        lon += 360.0f;

    Gt2dRenderer::EnableZTest(true);
    Gt2dRenderer::Suspend();
    D_00665EC0.BuildCustomCameraData(-1);
    D_00667050 = 0;

    int cell = (int)(lon / 5.625f);
    float frac = 0.0f + lon - (float)cell * 5.625f;
    CGtMatrix3x4 rx;
    rx = CreateRotationMatrix3x4(kRight, 0.01745329238f * (oneMinus * (lat * -1.0f)));
    CGtMatrix3x4 ry;
    ry = CreateRotationMatrix3x4(kUp, 0.01745329238f * -frac);
    CGtMatrix3x4 m;
    m = ry * rx;
    m.mRight = m.mRight * 100.0f;
    m.mUp = m.mUp * 100.0f;
    m.mAt = m.mAt * 100.0f;
    CGtV3d pos;
    pos.SetX(d->field_0);
    pos.SetY(d->field_4);
    pos.SetZ(d->field_8);
    m.mPos = pos;

    B3Im3d::BeginRendering();
    B3Im3d::SetAlphaTestThreshold(0.0f);
    DrawInvisiblePolys(m.mPos);

    int n = 0;
    float t = lat / 90.0f;
    if (t > 0.875f)
        t = 0.875f;
    else if (t < -0.875f)
        t = -0.875f;
    CGtV3d offUp = kUp * -(t / 0.875f);
    CGtV3d offRight = kRight * (frac / 180.0f);
    B3Im3d::SetTexture(0);
    B3Im3d::SetZWrite(false);
    B3Im3d::SetLineAntialiasing(true);
    lineRgba.alpha = 0x80;
    int parity = cell % 2;
    int limit;
    if (d->field_15 < 0x80)
        limit = 65 - (d->field_15 * 65) / 128;   // [L] first longitude column drawn while revealing
    else
        limit = 0;
    float w = 0.0f;

    // meridians, rows 2..30, every second column
    for (int c = parity; c < 65; c += 2) {
        if (c < limit)
            continue;
        for (int r = 2; r < 30; r++) {
            func_003B2EE0_inl3(gmpStaticGlobeData->field_19230[n],
                               func_003B2EE0_inl4(gmpStaticGlobeData, r, c, m, offUp, offRight, shape), w, lineRgba);
            func_003B2EE0_inl3(gmpStaticGlobeData->field_19230[n + 1],
                               func_003B2EE0_inl4(gmpStaticGlobeData, r + 1, c, m, offUp, offRight, shape), w, lineRgba);
            n += 2;
        }
        if (n > 0) {
            B3Im3d::RenderLinelist(gmpStaticGlobeData->field_19230, n);
            n = 0;
        }
    }
    // the polar ends (rows 0..2 and 30..32), every fourth column
    for (int c = parity; c < 65; c += 4) {
        if (c < limit)
            continue;
        for (int r = 0; r < 2; r++) {
            func_003B2EE0_inl3(gmpStaticGlobeData->field_19230[n],
                               func_003B2EE0_inl4(gmpStaticGlobeData, r, c, m, offUp, offRight, shape), w, lineRgba);
            func_003B2EE0_inl3(gmpStaticGlobeData->field_19230[n + 1],
                               func_003B2EE0_inl4(gmpStaticGlobeData, r + 1, c, m, offUp, offRight, shape), w, lineRgba);
            n += 2;
        }
        for (int r = 30; r < 32; r++) {
            func_003B2EE0_inl3(gmpStaticGlobeData->field_19230[n],
                               func_003B2EE0_inl4(gmpStaticGlobeData, r, c, m, offUp, offRight, shape), w, lineRgba);
            func_003B2EE0_inl3(gmpStaticGlobeData->field_19230[n + 1],
                               func_003B2EE0_inl4(gmpStaticGlobeData, r + 1, c, m, offUp, offRight, shape), w, lineRgba);
            n += 2;
        }
        if (n > 0) {
            B3Im3d::RenderLinelist(gmpStaticGlobeData->field_19230, n);
            n = 0;
        }
    }
    // parallels, every second row
    for (int r = 0; r < 33; r += 2) {
        for (int c = 0; c < 64; c++) {
            if (c < limit)
                continue;
            func_003B2EE0_inl3(gmpStaticGlobeData->field_19230[n],
                               func_003B2EE0_inl4(gmpStaticGlobeData, r, c, m, offUp, offRight, shape), w, lineRgba);
            func_003B2EE0_inl3(gmpStaticGlobeData->field_19230[n + 1],
                               func_003B2EE0_inl4(gmpStaticGlobeData, r, c + 1, m, offUp, offRight, shape), w, lineRgba);
            n += 2;
            if (n >= 64) {
                B3Im3d::RenderLinelist(gmpStaticGlobeData->field_19230, n);
                n = 0;
            }
        }
        if (n > 0) {
            B3Im3d::RenderLinelist(gmpStaticGlobeData->field_19230, n);
            n = 0;
        }
    }

    B3Im3d::SetZWrite(true);
    B3Im3d::SetLineAntialiasing(false);
    B3Im3d::SetTexture(D_01EA4608);
    n = 0;
    if (d->field_15 >= 0x80) {
        B3Im3d::SetBackfaceCull(true);
        int rowLimit;
        if (d->field_15 < 0xFF)
            rowLimit = 33 - ((d->field_15 - 0x80) * 33) / 127;   // [L] first latitude row drawn while revealing
        else
            rowLimit = 0;
        w = 0.0f;
        // the textured surface: one strip per column, u scrolled by the longitude cell
        // [C] retail runs c to 64 and so reads column c + 1 = 65, i.e. the next row's column 0
        for (int c = 0; c < 65; c++) {
            float u0 = (float)(cell + 64 - (c + 1)) / 64.0f;
            float u1 = (float)(cell + 64 - c) / 64.0f;
            for (int r = 0; r < 33; r++) {
                if (r < rowLimit)
                    continue;
                float v = (float)(32 - r) / 32.0f;
                CB3Im3dVertex *b = gmpStaticGlobeData->field_19230;
                func_003B2EE0_inl3(b[n], func_003B2EE0_inl4(gmpStaticGlobeData, r, c + 1, m, offUp, offRight, shape),
                                   w, surfRgba);
                b[n].field_10 = u0;
                b[n].field_14 = v;
                func_003B2EE0_inl3(b[n + 1], func_003B2EE0_inl4(gmpStaticGlobeData, r, c, m, offUp, offRight, shape),
                                   w, surfRgba);
                b[n + 1].field_10 = u1;
                b[n + 1].field_14 = v;
                n += 2;
            }
            if (n > 2) {
                B3Im3d::RenderTristrip(gmpStaticGlobeData->field_19230, n);
                n = 0;
            }
        }
        // the highlighted region: a 16-column textured patch of the sphere grid
        float h = (float)(unsigned int)d->field_16 / 255.0f;
        CGtV4d hc = space.mColour;
        hc.SetW(hc.W() * h);
        surfRgba = func_003B2EE0_inl1(hc, k);
        switch (d->field_17) {
        case 0:
            func_003B2EE0_inl5(D_01EA460C, 24 - (48 - cell), 16, 8, 8.0f, m, surfRgba, n);
            break;
        case 1:
            func_003B2EE0_inl5(D_01EA4618, 24 - (3 - cell), 19, 8, 8.0f, m, surfRgba, n);
            break;
        case 2:
            func_003B2EE0_inl5(D_01EA4614, 24 - (20 - cell), 12, 16, 16.0f, m, surfRgba, n);
            break;
        }
        B3Im3d::SetBackfaceCull(false);
    }

    float haloAngle;
    if (d->field_15 < 0x7F)
        haloAngle = 360.0f * (float)(65 - limit) / 65.0f + frac;
    else
        haloAngle = 360.0f;
    DrawGlobeHalo(m.mPos, haloRgba, haloAngle);
    B3Im3d::EndRendering();

    _rwDMAOpenVIFPkt(0x80000000, 2);
    UnkStruct_003B2EE0_pkt *p = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x1000000000008001), "r"(14));
    p->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x41001), "r"(71));
    p->field_10 = q1;
    farFogPlane.field_0 = p + 1;
    Gt2dRenderer::Resume();
    Gt2dRenderer::EnableZTest(false);
}

