// NONMATCHING: DrawInvisiblePolys__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d -- retail 425 / ours 403 instructions, 593 in changed runs
// draftAO (2026-11-01): complete rewrite: the function is static (p by address in a0; the draft read a1 as a member); three untextured colour-0 tristrips: top band (+-sx, sy .. 0.704 sy, z 1), bottom band (-0.717 sy .. -sy; the draft drew a rotated quad), and the rectangle (+-0.8125 sx, +-1.0833 sy) x p.z offset by p (z 0); vertices via CGtV3dPlus SetPlus(0) + SetGtV3d (retail vsubw.w/vaddx.w/vadd.xyz on the loaded quad), colour bytes at +0x18; 403/425, calls identical, VU and mul.s counts equal | Before: fix2 (2026-11-01): vertex type named CB3Im3dVertex from the retail symbol RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi (the placeholder mangled to a missing symbol) | Before: psweep: scoped #pragma inline_depth(3) [G] improves 884 -> 783
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm 0x3B2830..0x3B2ED0: every vertex's lane sources, the static-member a0, the p.z products (vmulx.z) and the three RenderTristrip calls traced

// CB3Globe2dObject::DrawInvisiblePolys(CGtV3d) -- [C] name: retail symbol table. draftAO fork B (2026-11-01): complete rewrite
// from the retail asm (0x3B2830..0x3B2ED0). Three untextured, colour-0 tristrips of four vertices each in the static globe data's
// vertex buffer: a band at the top of the screen-space window (y from the window's half height down to 0.704 of it), a band at
// the bottom (-0.717 .. -1 of it), both at z 1, then a rectangle (+-0.8125 x half width, +-1.0833 x half height) scaled by
// p.z and offset by p. [G] meaning: depth-only polygons that mask the globe's off-screen parts.
// [C] DrawInvisiblePolys is static: the vector arrives by address in a0 (retail 0x3B2834 `lq v1, 0(a0)`); the son-series draft
// declared it as a member (p read from a1) and drew a rotated second quad.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CGtTexture;
struct CB3Im3dVertex {   // [C] name: retail calls RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi; 0x20 bytes [C] stride
    CGtV3dPlus field_0;                        // [G] position xyz + w (retail: SetPlus then SetGtV3d on the loaded quad)
    unsigned char pad_10[8];
    unsigned char field_18[4];                 // [C] colour bytes (sb x4 at +0x18)
    unsigned char pad_1C[4];
};
struct UnkStruct_3B2830_data {
    unsigned char pad_0[0x19230];
    CB3Im3dVertex field_19230[4];              // [C] the four strip vertices (+0x19230, stride 0x20)
};
struct UnkStruct_3B2830_cfg { unsigned char pad_0[0x48]; CGtV2d field_48; };   // [G] +0x48: the window's half size
struct UnkStruct_D_00666270 { UnkStruct_3B2830_cfg *field_0; };
extern UnkStruct_D_00666270 D_00666270;
extern float D_004E0A8C, D_004E0A90, D_004E0A94;   // [C] 0.7041667, -0.7166667, 1.0833334 (gp literals)
namespace B3Im3d {
void SetTexture(CGtTexture *);
void RenderTristrip(const CB3Im3dVertex *, int);
}
class CB3Globe2dObject {
public:
    static void DrawInvisiblePolys(CGtV3d);
    static UnkStruct_3B2830_data *gmpStaticGlobeData;
};

// [G] one strip vertex: w then xyz into the loaded quad (CGtV3dPlus SetPlus / SetGtV3d), then the colour bytes
static inline void func_003B2830_inl1(int i, CGtV3d v, float w, const unsigned char *c)
{
    CB3Im3dVertex *lpVertex = &CB3Globe2dObject::gmpStaticGlobeData->field_19230[i];
    lpVertex->field_0.SetPlus(w);
    lpVertex->field_0.SetGtV3d(v);
    lpVertex->field_18[0] = c[0];
    lpVertex->field_18[1] = c[1];
    lpVertex->field_18[2] = c[2];
    lpVertex->field_18[3] = c[3];
}

// 0x003B2830
void CB3Globe2dObject::DrawInvisiblePolys(CGtV3d p)
{
    unsigned char lColour[4];
    lColour[0] = 0;
    lColour[2] = 0;
    lColour[1] = 0;
    lColour[3] = 0;
    CGtV2d lSize = D_00666270.field_0->field_48;
    B3Im3d::SetTexture(0);
    float lrW = 0.0f;
    float sx = lSize.marValues[0];
    float sy = lSize.marValues[1];
    CGtV3d v;                                  // [C] one stack vector, every lane reset per vertex (w never written)
    // [C] 0x3B28A8..0x3B2A98: top band
    v.SetX(sx); v.SetY(sy); v.SetZ(1.0f);
    func_003B2830_inl1(0, v, lrW, lColour);
    v.SetX(-sx); v.SetY(sy); v.SetZ(1.0f);
    func_003B2830_inl1(1, v, lrW, lColour);
    float lrTopEdge = D_004E0A8C * sy;
    v.SetX(sx); v.SetY(lrTopEdge); v.SetZ(1.0f);
    func_003B2830_inl1(2, v, lrW, lColour);
    v.SetX(-sx); v.SetY(lrTopEdge); v.SetZ(1.0f);
    func_003B2830_inl1(3, v, lrW, lColour);
    B3Im3d::RenderTristrip(gmpStaticGlobeData->field_19230, 4);
    // [C] 0x3B2A9C..0x3B2C68: bottom band
    float lrBottomEdge = D_004E0A90 * sy;
    v.SetX(sx); v.SetY(lrBottomEdge); v.SetZ(1.0f);
    func_003B2830_inl1(0, v, lrW, lColour);
    v.SetX(-sx); v.SetY(lrBottomEdge); v.SetZ(1.0f);
    func_003B2830_inl1(1, v, lrW, lColour);
    v.SetX(sx); v.SetY(-sy); v.SetZ(1.0f);
    func_003B2830_inl1(2, v, lrW, lColour);
    v.SetX(-sx); v.SetY(-sy); v.SetZ(1.0f);
    func_003B2830_inl1(3, v, lrW, lColour);
    B3Im3d::RenderTristrip(gmpStaticGlobeData->field_19230, 4);
    // [C] 0x3B2C6C..0x3B2E94: the rectangle around p, its half size scaled by p.z (ZAxisType x float, vmulx.z)
    float lrLeft = p.Z() * (0.8125f * -lSize.marValues[0]);
    float lrRight = p.Z() * (0.8125f * lSize.marValues[0]);
    float lrTop = p.Z() * (D_004E0A94 * lSize.marValues[1]);
    float lrBottom = p.Z() * (D_004E0A94 * -lSize.marValues[1]);
    v.SetX(lrRight); v.SetY(lrTop); v.SetZ(lrW);
    v += p;
    func_003B2830_inl1(0, v, lrW, lColour);
    v.SetX(lrLeft); v.SetY(lrTop); v.SetZ(lrW);
    v += p;
    func_003B2830_inl1(1, v, lrW, lColour);
    v.SetX(lrRight); v.SetY(lrBottom); v.SetZ(lrW);
    v += p;
    func_003B2830_inl1(2, v, lrW, lColour);
    v.SetX(lrLeft); v.SetY(lrBottom); v.SetZ(lrW);
    v += p;
    func_003B2830_inl1(3, v, lrW, lColour);
    B3Im3d::RenderTristrip(gmpStaticGlobeData->field_19230, 4);
}
