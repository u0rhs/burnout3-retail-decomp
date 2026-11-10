// NONMATCHING: RenderTriStripGouraudTex__12Gt2dRendererFRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV4d -- retail 339 / ours 307 instructions, 337 in changed runs
// draftAM C-first: 2D Gouraud textured triangle strip into the Gt2dRenderer GS buffer: pixel offset rounded (x + copysign 0.5), _Dispatch when fewer than (3n+1)/2 + 6 qwords are left, PRIM 7 header (aligned, SetPrim GIFtag, prim reg 7, REGLIST tag 7) unless already in strip mode, else the strip continues with the previous last vertex and the new first vertex repeated; per vertex UV (raw 64-bit), RGBAQ (colour x kUntexturedColourScale.w, (int) lanes, Q 1.0), XYZ2 (offset + 16 x position, _gnZ); 307/339, calls identical; every buffer store at retail's address (retail also writes each intermediate _gpu64Current value: the stores through an unsigned long* reload it, b119p keeps it in a register -- same final state)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; the space test (srl unsigned qword count, signed /2), the prim-7 test, the continuation's nine words (c[0] = c[-3], c[1] = c[-2], c[2] = c[-1], uv, rgbaq, xyz, then the last three repeated), the RGBA packing order and the do-while loop (no entry test) traced
// Retail behaviour kept: the vertex loop is a do-while on lpPositions != lpLastPosition, so a call with no vertex left writes past the end.

// Gt2dRenderer::RenderTriStripGouraudTex(const CGtV2d&, int, const CGtV2d*, const CGtV2d*, const CGtV4d*) -- draftAM (C-first draft).
// 0x2187B0, 0x54C. [C] name: the mangled symbol; parameter / local names from the Revenge STABS of
// Gt2dRenderer::RenderTriStripGouraudTex (Gt2dRendererPS2.cpp: lPixelOffset, lnNumVerts, lpPositions, lpUVs, lpColours, lnOffX,
// lnOffY, lpLastPosition, lScaledColour). Helpers and statics as the RenderTriStripFlatTex archive.
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
using GtMathPs2::WAxisType;

class Gt2dRenderer {
public:
    static void RenderTriStripGouraudTex(const CGtV2d &lPixelOffset, int lnNumVerts, const CGtV2d *lpPositions, const CGtV2d *lpUVs,
                                         const CGtV4d *lpColours);
    static void _Dispatch();
    static const CGtV4d kUntexturedColourScale;
    static u_long128 *_gau128Buffer;
    static unsigned long *_gpu64Current;
    static unsigned int *_gpuNLoops;
    static int _guCurrentPrimType;
    static int _gnZ;
    static int _gnGSOffX;
    static int _gnGSOffY;
    static u_long128 _gu128SetPrimGIFTag;
    static unsigned long _gau64PrimRegs[10];
    static u_long128 _gau128RegListGIFTags[10];
};

// CGtV4d * WAxisType on all four lanes (E map GtMathPs2::CGtV4d::operator *(WAxisType), 0x1646F0; not in the header: queued)
static inline CGtV4d func_002187B0_inl1(const CGtV4d &c, WAxisType k)
{
    u_long128 t;
    asm("vmulw.xyzw %0, %1, %2w" : "=j"(t) : "j"(c.mData), "j"(k.lVector));
    return CGtV4d(t);
}
// round to nearest: x + copysign(0.5, x), truncated (Revenge lSplitValue / lSplitHalf: USplitBits), as RenderTriStripFlatTex
static inline float func_002187B0_inl2(float v)
{
    volatile union { float f; int u; } h;
    union { float f; int u; } s;
    h.f = 0.5f;
    s.f = v;
    h.u = h.u | (s.u & 0x80000000);
    return (float)(int)(v + h.f);
}
// an 8-byte vector as one 64-bit word (x low, y high; Revenge lSplitBits)
static inline unsigned long func_002187B0_inl3(const CGtV2d *p)
{
    const unsigned int *w = (const unsigned int *)p;
    return (unsigned long)w[1] << 32 | w[0];
}
// GS RGBAQ from a scaled colour: (int) each lane, Q = 1.0
static inline unsigned long func_002187B0_inl4(const CGtV4d &c)
{
    return ((long)(int)c.f[3] << 24 | ((long)(int)c.f[2] << 16 | ((long)(int)c.f[0] | (long)(int)c.f[1] << 8))) | 0x3F80000000000000UL;
}

// 0x002187B0
void Gt2dRenderer::RenderTriStripGouraudTex(const CGtV2d &lPixelOffset, int lnNumVerts, const CGtV2d *lpPositions, const CGtV2d *lpUVs,
                                            const CGtV4d *lpColours)
{
    const CGtV2d *lpLastPosition = lpPositions + lnNumVerts;
    int lnOffX = _gnGSOffX + (int)func_002187B0_inl2(16.0f * lPixelOffset.marValues[0]);
    int lnOffY = _gnGSOffY + (int)func_002187B0_inl2(16.0f * lPixelOffset.marValues[1]);
    if (0x1FF - (int)(((unsigned int)(_gpu64Current + 1) - (unsigned int)_gau128Buffer) >> 4) < (3 * lnNumVerts + 1) / 2 + 6)
        _Dispatch();
    bool fresh;
    if (_guCurrentPrimType != 7) {
        if (((int)_gpu64Current & 0xF) != 0)
            _gpu64Current = _gpu64Current + 1;
        _guCurrentPrimType = 7;
        unsigned long *p = _gpu64Current;
        *(u_long128 *)p = _gu128SetPrimGIFTag;
        p[2] = _gau64PrimRegs[7];
        ((u_long128 *)p)[2] = _gau128RegListGIFTags[7];
        _gpuNLoops = (unsigned int *)(p + 4);
        _gpu64Current = _gpu64Current + 6;
        fresh = true;
    } else {
        fresh = false;
    }
    if (fresh) {
        *_gpuNLoops += lnNumVerts;
    } else {
        // continue the strip: repeat the previous last vertex, then the new first vertex twice (two degenerate triangles)
        *_gpuNLoops += lnNumVerts + 2;
        unsigned long uv = func_002187B0_inl3(lpUVs);
        CGtV4d c0 = *lpColours;
        lpUVs++;
        lpColours++;
        float y = 16.0f * lpPositions->marValues[1];
        float x = 16.0f * lpPositions->marValues[0];
        lpPositions++;
        unsigned long *t;
        _gpu64Current[0] = _gpu64Current[-3];
        t = _gpu64Current++;
        t[1] = t[-2];
        t = _gpu64Current++;
        t[1] = t[-2];
        t = _gpu64Current++;
        t[1] = uv;
        unsigned long xy = (long)(lnOffX + (int)x) | (long)(lnOffY + (int)y) << 16;
        CGtV4d c = func_002187B0_inl1(c0, kUntexturedColourScale.W());
        t = _gpu64Current++;
        t[1] = func_002187B0_inl4(c);
        t = _gpu64Current++;
        t[1] = (unsigned long)_gnZ << 32 | xy;
        t = _gpu64Current++;
        t[1] = t[-2];
        t = _gpu64Current++;
        t[1] = t[-2];
        t = _gpu64Current++;
        t[1] = t[-2];
        _gpu64Current++;
    }
    // [C] a do-while: retail tests lpPositions != lpLastPosition only after a vertex (bne at 0x218CA8), so a call with no vertex
    // left (lnNumVerts 0, or 1 on a continued strip) writes past the end; kept
    do {
        unsigned long uv = func_002187B0_inl3(lpUVs);
        float y = 16.0f * lpPositions->marValues[1];
        float x = 16.0f * lpPositions->marValues[0];
        CGtV4d c = func_002187B0_inl1(*lpColours, kUntexturedColourScale.W());
        lpColours++;
        lpUVs++;
        lpPositions++;
        _gpu64Current[0] = uv;
        unsigned long xy = (long)(lnOffX + (int)x) | (long)(lnOffY + (int)y) << 16;
        unsigned long *t = _gpu64Current++;
        t[1] = func_002187B0_inl4(c);
        t = _gpu64Current++;
        t[1] = (unsigned long)_gnZ << 32 | xy;
        _gpu64Current++;
    } while (lpPositions != lpLastPosition);
}
