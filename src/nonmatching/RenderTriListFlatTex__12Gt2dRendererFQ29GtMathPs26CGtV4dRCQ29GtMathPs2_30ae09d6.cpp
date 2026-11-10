// NONMATCHING: RenderTriListFlatTex__12Gt2dRendererFQ29GtMathPs26CGtV4dRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2d -- retail 248 / ours 236 instructions, 244 in changed runs
// draftAN fork B C-first (helpers from the archived RenderTriStripFlatTex): colour x kUntexturedColourScale.w, dispatch below 3(n+1) free qwords, RGBA by four scalar truncations | Q 1.0, PRIM 2 + RGBAQ header on change, NLOOP += n, do-while over triangles writing (uv, xyz) qwords; 236/248, calls identical; retail re-loads/re-stores _gpu64Current per qword (b119p keeps it in a register)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; the space test, the prim/RGBAQ condition, the header qwords, the rounding of the GS offset and each vertex qword's halves (pcpyld operand order) traced; do-while entry kept

// Gt2dRenderer::RenderTriListFlatTex(GtMathPs2::CGtV4d, const GtMathPs2::CGtV2d&, int, const GtMathPs2::CGtV2d*, const GtMathPs2::CGtV2d*)
// -- draftAN fork B (C-first draft). 0x219150, 0x3E0. [C] name: the mangled symbol in retail's tables. Shapes and helpers from the
// archived sibling RenderTriStripFlatTex (0x218D00). What it does [L]: n flat-coloured textured triangles (3 vertices each, pts/uvs
// in triples): colour x kUntexturedColourScale.w, dispatch when fewer than 3(n+1) qwords are free, PRIM type 2 (triangle list)
// + RGBAQ header when the prim type or RGBAQ changed, NLOOP += n, then one (uv, xyz) qword per vertex at GS offset + round(16 pos).
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class Gt2dRenderer {
public:
    static void RenderTriListFlatTex(const CGtV4d colour, const CGtV2d &pos, int n, const CGtV2d *pts, const CGtV2d *uvs);
    static void _Dispatch();
    static const CGtV4d kUntexturedColourScale;
    static u_long128 *_gau128Buffer;
    static unsigned long *_gpu64Current;
    static unsigned int *_gpuNLoops;
    static int _guCurrentPrimType;
    static unsigned long _gu64CurrentRGBAQ;
    static int _gnZ;
    static int _gnGSOffX;
    static int _gnGSOffY;
    static u_long128 _gGsOffsetXYXY;
    static u_long128 _gu128SetPrimRGBAQGIFTag;
    static unsigned long _gau64PrimRegs[10];
    static u_long128 _gau128RegListGIFTags[10];
};

// [L] N185: stands in for a missing GtMathPs2 inline -- CGtV4d::operator*(WAxisType), as in RenderSpritesTex.
static inline CGtV4d func_00219150_inl1(const CGtV4d &c, CGtV4d k)
{
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vmulw.xyzw $vf1, $vf2, $vf1w" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(k.mData), "r"(c.mData));
    return CGtV4d(t);
}

// [L] N185: CGtV4d::operator+(CGtV4d) in place on the by-value left operand (as RenderSpritesTex).
static inline CGtV4d func_00219150_inl2(CGtV4d a, const CGtV4d &b)
{
    asm("vadd.xyzw %0, %0, %1" : "+j"(a.mData) : "j"(b.mData));
    return CGtV4d(a.mData);
}

// [G] placeholder for the inlined round-to-nearest (x + copysign(0.5, x), truncated, back to float), as the
// archived RenderTriStripFlatUntex.
static inline float func_00219150_inl3(float v)
{
    volatile union { float f; int u; } h;
    union { float f; int u; } s;
    h.f = 0.5f;
    s.f = v;
    h.u = h.u | (s.u & 0x80000000);
    return (float)(int)(v + h.f);
}

// [G] an 8-byte vector read as two 32-bit halves (retail lwu / dsll32 / or).
static inline unsigned long func_00219150_inl4(const CGtV2d *p)
{
    const unsigned int *w = (const unsigned int *)p;
    return (unsigned long)w[1] << 32 | w[0];
}

// [G] one 16-byte GIF data qword: (lo, hi) = (uv, xyz)
static inline void func_00219150_inl5(unsigned long xyz, unsigned long uv)
{
    u_long128 v;
    asm("pcpyld %0, %1, %2" : "=r"(v) : "r"(xyz), "r"(uv));
    *(u_long128 *)Gt2dRenderer::_gpu64Current = v;
    Gt2dRenderer::_gpu64Current = Gt2dRenderer::_gpu64Current + 2;
}

// 0x00219150
void Gt2dRenderer::RenderTriListFlatTex(const CGtV4d colour, const CGtV2d &pos, int n, const CGtV2d *pts, const CGtV2d *uvs)
{
    CGtV4d c = func_00219150_inl1(colour, kUntexturedColourScale);
    if (511 - (int)(((unsigned int)(_gpu64Current + 1) - (unsigned int)_gau128Buffer) >> 4) < (n + 1) * 3) {
        _Dispatch();
    }
    // [C] RGBA by four scalar truncations (cvt.w.s), not the strip builders' vftoi0/ppach/ppacb; Q = 1.0
    unsigned long rgbaq = (long)(int)(float)c.X() | (long)(int)(float)c.Y() << 8 | (long)(int)(float)c.Z() << 16
                        | (long)(int)(float)c.W() << 24 | 0x3F80000000000000UL;
    if (_guCurrentPrimType != 2 || rgbaq != _gu64CurrentRGBAQ) {
        if (((int)_gpu64Current & 0xF) != 0) {
            _gpu64Current = _gpu64Current + 1;
        }
        _guCurrentPrimType = 2;
        unsigned long *p = _gpu64Current;
        _gu64CurrentRGBAQ = rgbaq;
        *(u_long128 *)p = _gu128SetPrimRGBAQGIFTag;
        p[2] = _gau64PrimRegs[2];
        p[3] = rgbaq;
        ((u_long128 *)p)[2] = _gau128RegListGIFTags[2];
        _gpuNLoops = (unsigned int *)(p + 4);
        _gpu64Current = _gpu64Current + 6;
    }
    int ox = _gnGSOffX + (int)func_00219150_inl3(16.0f * pos.marValues[0]);
    int oy = _gnGSOffY + (int)func_00219150_inl3(16.0f * pos.marValues[1]);
    *_gpuNLoops += n;
    unsigned long z = (unsigned long)_gnZ << 32;
    // [C] do-while (bgtz at the bottom, no entry test): n <= 0 still writes one triangle (NLOOP += n only). Kept as retail.
    do {
        n--;
        unsigned long t0 = func_00219150_inl4(&uvs[0]);
        unsigned long t1 = func_00219150_inl4(&uvs[1]);
        func_00219150_inl5(z | ((long)(ox + (int)(16.0f * pts[0].marValues[0])) | (long)(oy + (int)(16.0f * pts[0].marValues[1])) << 16), t0);
        func_00219150_inl5(z | ((long)(ox + (int)(16.0f * pts[1].marValues[0])) | (long)(oy + (int)(16.0f * pts[1].marValues[1])) << 16), t1);
        unsigned long t2 = func_00219150_inl4(&uvs[2]);
        func_00219150_inl5(z | ((long)(ox + (int)(16.0f * pts[2].marValues[0])) | (long)(oy + (int)(16.0f * pts[2].marValues[1])) << 16), t2);
        uvs += 3;
        pts += 3;
    } while (n > 0);
}
