// NONMATCHING: DrawGlobeHalo__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d6RwRGBAf -- retail 1037 / ours 1016 instructions, 1329 in changed runs
// draftAH C-first: 4 halo quads (2 rotated about kUp by angle-270 via CreateRotationMatrix3x4 + TransformPoint, 2 flat), 16 vertices; 1016/1037, calls identical, VU op counts equal except vmove 0/1; left: address arithmetic (lui/ori/addu for +0x19230), frame 0x970 vs 0xF20
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (lane-by-lane trace of all 16 corners and UV pairs); per-kind VU op counts equal (CreateRotationMatrix3x4 header body, 16 TransformPoint, 16 vertex stores); local vsub.z negation stand-in queued as a header gap

// CB3Globe2dObject::DrawGlobeHalo(CGtV3d, RwRGBA, float) -- draftAH (C-first draft; the lifter refused it). 0x3B17F0, 0x1034.
// [C] name: retail symbol table. No Revenge counterpart (B4 has no Globe2dObject). Written from the retail asm (Ghidra as reading aid).
// What it does [L]: the halo texture (D_01EA461C, full 256 x 256 UVs from CB3MenuImageUVs::_CalculateUV) drawn as quads around
// the globe's screen point p, sized by the 2d scale (D_00666270->field_48) and 500 / p.z: past 180 degrees of the caller's angle
// two quads rotated about kUp by (angle - 270) degrees (0 from 270 on), then always two flat quads. Each quad is a 4-vertex
// tristrip with one corner at p; widths 0.8125 * sx, heights D_004E0A94 * sy, signs per quadrant.
// Layouts and the vertex store as the archived sibling _Render__16CB3Globe2dObject (CB3Im3dVertex, CB3Globe2dStaticData).
// Types [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

struct RwRGBA { unsigned char red, green, blue, alpha; };   // [L] RW 3.x layout

// [L] name: E map B3Im3d::RenderTristrip(const CB3Im3dVertex*, int); layout [G] (0x20 stride, uv at +0x10, colour at +0x18)
struct CB3Im3dVertex {
    CGtV4d field_0;             // [G] position, w = 0
    float field_10;             // [G] u
    float field_14;             // [G] v
    RwRGBA field_18;
    unsigned char pad_1C[4];
};
// [L] E map CB3Globe2dStaticData (as _Render's archive): three 33 x 65 point grids, then the vertex buffer
struct CB3Globe2dStaticData {
    CGtV3d field_0[33][65];
    CGtV3d field_8610[33][65];
    CGtV3d field_10C20[33][65];
    CB3Im3dVertex field_19230[66];
};
// [C] class name: the mangled _CalculateUV__15CB3MenuImageUVsFffffffUi; layout [G] (four floats: u0, v0, u1, v1; returned in memory)
class CB3MenuImageUVs {
public:
    static CB3MenuImageUVs _CalculateUV(float, float, float, float, float, float, unsigned int);
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};
class CGtTexture;
namespace B3Im3d {
void SetTexture(CGtTexture *);
void RenderTristrip(const CB3Im3dVertex *, int);
}
struct UnkStruct_003B17F0_cfg { unsigned char pad_0[0x48]; CGtV2d field_48; };   // as DrawInvisiblePolys' UnkStruct_3B2830_cfg
struct UnkStruct_D_00666270 { UnkStruct_003B17F0_cfg *field_0; };
extern UnkStruct_D_00666270 D_00666270;
extern CGtTexture *D_01EA461C;      // [G] halo texture
extern float D_004E06F0;            // [G] degrees -> radians (as Update__11CGtViewport's use)
extern float D_004E0A94;            // [G] halo height factor
extern CGtV3d kUp;

class CB3Globe2dObject {
public:
    static void DrawGlobeHalo(CGtV3d, RwRGBA, float);
    static CB3Globe2dStaticData *gmpStaticGlobeData;
};

// [G] vertex store (as _Render's inl3): w = 0 then xyz = pos in place, colour bytes, then the uv pair
static inline void func_003B17F0_inl1(int i, const CGtV3d &pos, const RwRGBA &c, float u, float v)
{
    CB3Im3dVertex &d = CB3Globe2dObject::gmpStaticGlobeData->field_19230[i];
    d.field_0.SetW(0.0f);
    asm("vadd.xyz %0, $vf0, %1" : "+j"(d.field_0.mData) : "j"(pos.mData));
    d.field_18 = c;
    CB3Im3dVertex &t = CB3Globe2dObject::gmpStaticGlobeData->field_19230[i];
    t.field_10 = u;
    t.field_14 = v;
}

// [G] header gap (queued): retail negates a lane product with `vsub.z D, $vf0, S` (4 sites here); the header's
// ZAxisType::operator-() multiplies by -1.0 (its Create__17CB3TrafficVehicle shape), so this stand-in carries retail's form
static inline ZAxisType func_003B17F0_inl2(ZAxisType a) { u_long128 r; asm("vsub.z %0, $vf0, %1" : "=j"(r) : "j"(a.lVector)); return ZAxisType(r); }
// [G] a quad corner (x, y, 0) built lane by lane in a local (retail's vaddx.x/y/z inserts)
static inline void func_003B17F0_inl3(CGtV3d &q, float x, float y)
{
    q.SetX(x);
    q.SetY(y);
    q.SetZ(0.0f);
}

// 0x003B17F0
void CB3Globe2dObject::DrawGlobeHalo(CGtV3d p, RwRGBA c, float a)
{
    float k = 500.0f / (float)p.Z();  // [C] retail FPU form, not a VU lane op: 0x3B184C div.s (the cast keeps the port's PS2 float model)
    CGtV2d sz = D_00666270.field_0->field_48;
    CGtV2d lSize = sz;
    B3Im3d::SetTexture(D_01EA461C);
    CB3MenuImageUVs uv = CB3MenuImageUVs::_CalculateUV(0.5f, 0.5f, 255.0f, 255.0f, 256.0f, 256.0f, 0);
    int n = 0;
    CGtV3d q, r;
    if (!(a < 180.0f)) {
        float t;
        if (a < 270.0f)
            t = a - 180.0f - 90.0f;
        else
            t = 0.0f;
        CGtMatrix3x4 m = CreateRotationMatrix3x4(kUp, D_004E06F0 * t);
        // rotated quad 1: up and to the left
        float h = p.Z() * (D_004E0A94 * lSize.marValues[1]) * k;
        float w = func_003B17F0_inl2(p.Z() * (0.8125f * lSize.marValues[0])) * k;
        func_003B17F0_inl3(q, 0.0f, h);
        r = TransformPoint(m, q);
        r += p;
        func_003B17F0_inl1(n + 0, r, c, uv.field_8, uv.field_4);
        func_003B17F0_inl3(q, w, h);
        r = TransformPoint(m, q);
        r += p;
        func_003B17F0_inl1(n + 1, r, c, uv.field_0, uv.field_4);
        func_003B17F0_inl3(q, 0.0f, 0.0f);
        r = TransformPoint(m, q);
        r += p;
        func_003B17F0_inl1(n + 2, r, c, uv.field_8, uv.field_C);
        func_003B17F0_inl3(q, w, 0.0f);
        r = TransformPoint(m, q);
        r += p;
        func_003B17F0_inl1(n + 3, r, c, uv.field_0, uv.field_C);
        n += 4;
        B3Im3d::RenderTristrip(gmpStaticGlobeData->field_19230, n);
        n = 0;
        // rotated quad 2: down and to the left
        h = func_003B17F0_inl2(p.Z() * (D_004E0A94 * lSize.marValues[1])) * k;
        w = func_003B17F0_inl2(p.Z() * (0.8125f * lSize.marValues[0])) * k;
        func_003B17F0_inl3(q, 0.0f, 0.0f);
        r = TransformPoint(m, q);
        r += p;
        func_003B17F0_inl1(n + 0, r, c, uv.field_8, uv.field_C);
        func_003B17F0_inl3(q, w, 0.0f);
        r = TransformPoint(m, q);
        r += p;
        func_003B17F0_inl1(n + 1, r, c, uv.field_0, uv.field_C);
        func_003B17F0_inl3(q, 0.0f, h);
        r = TransformPoint(m, q);
        r += p;
        func_003B17F0_inl1(n + 2, r, c, uv.field_8, uv.field_4);
        func_003B17F0_inl3(q, w, h);
        r = TransformPoint(m, q);
        r += p;
        func_003B17F0_inl1(n + 3, r, c, uv.field_0, uv.field_4);
        n += 4;
        B3Im3d::RenderTristrip(gmpStaticGlobeData->field_19230, n);
        n = 0;
    }
    // flat quad 3: up and to the right
    float w3 = p.Z() * (0.8125f * lSize.marValues[0]) * k;
    float h3 = p.Z() * (D_004E0A94 * lSize.marValues[1]) * k;
    func_003B17F0_inl3(q, w3, h3);
    q += p;
    func_003B17F0_inl1(n + 0, q, c, uv.field_0, uv.field_4);
    func_003B17F0_inl3(q, 0.0f, h3);
    q += p;
    func_003B17F0_inl1(n + 1, q, c, uv.field_8, uv.field_4);
    func_003B17F0_inl3(q, w3, 0.0f);
    q += p;
    func_003B17F0_inl1(n + 2, q, c, uv.field_0, uv.field_C);
    func_003B17F0_inl3(q, 0.0f, 0.0f);
    q += p;
    func_003B17F0_inl1(n + 3, q, c, uv.field_8, uv.field_C);
    n += 4;
    B3Im3d::RenderTristrip(gmpStaticGlobeData->field_19230, n);
    n = 0;
    // flat quad 4: down and to the right
    float w4 = p.Z() * (0.8125f * lSize.marValues[0]) * k;
    float h4 = func_003B17F0_inl2(p.Z() * (D_004E0A94 * lSize.marValues[1])) * k;
    func_003B17F0_inl3(q, w4, 0.0f);
    q += p;
    func_003B17F0_inl1(n + 0, q, c, uv.field_0, uv.field_C);
    func_003B17F0_inl3(q, 0.0f, 0.0f);
    q += p;
    func_003B17F0_inl1(n + 1, q, c, uv.field_8, uv.field_C);
    func_003B17F0_inl3(q, w4, h4);
    q += p;
    func_003B17F0_inl1(n + 2, q, c, uv.field_0, uv.field_4);
    func_003B17F0_inl3(q, 0.0f, h4);
    q += p;
    func_003B17F0_inl1(n + 3, q, c, uv.field_8, uv.field_4);
    n += 4;
    B3Im3d::RenderTristrip(gmpStaticGlobeData->field_19230, n);
}
