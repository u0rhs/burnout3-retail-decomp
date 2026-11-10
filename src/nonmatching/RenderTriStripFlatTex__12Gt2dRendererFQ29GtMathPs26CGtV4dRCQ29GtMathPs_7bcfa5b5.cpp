// NONMATCHING: RenderTriStripFlatTex__12Gt2dRendererFQ29GtMathPs26CGtV4dRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2d -- retail 276 / ours 276 instructions, 215 in changed runs
// 215 in changed runs, 276/276: prim/RGBAQ setup block exact; prologue rounding-union scheduling, pair-loop entry (retail if-guard + b test, N24 goto form), 16.0f hoist and loop temp registers still differ
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Gt2dRenderer::RenderTriStripFlatTex(GtMathPs2::CGtV4d,const GtMathPs2::CGtV2d&,int,const GtMathPs2::CGtV2d*,const GtMathPs2::CGtV2d*)
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/.
// Hand-written (ghvu16) from the Ghidra draft and retail; shapes from the proven sibling RenderSpritesTex
// (Gt2dRendererPS2_00219830.cpp: colour scale, vftoi0/ppach/ppacb RGBA, vftoi4 point pairs, pcpyld quads) and the archived
// RenderTriStripFlatUntex (prim/RGBAQ header, copysign-0.5 rounding). Static member types are [G] (instruction widths).
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class Gt2dRenderer {
public:
    static void RenderTriStripFlatTex(const CGtV4d colour, const CGtV2d &pos, int n, const CGtV2d *pts, const CGtV2d *uvs);
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
static inline CGtV4d func_00218D00_inl1(const CGtV4d &c, CGtV4d k)
{
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vmulw.xyzw $vf1, $vf2, $vf1w" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(k.mData), "r"(c.mData));
    return CGtV4d(t);
}

// [L] N185: CGtV4d::operator+(CGtV4d) in place on the by-value left operand (as RenderSpritesTex).
static inline CGtV4d func_00218D00_inl2(CGtV4d a, const CGtV4d &b)
{
    asm("vadd.xyzw %0, %0, %1" : "+j"(a.mData) : "j"(b.mData));
    return CGtV4d(a.mData);
}

// [G] placeholder for the inlined round-to-nearest (x + copysign(0.5, x), truncated, back to float), as the
// archived RenderTriStripFlatUntex.
static inline float func_00218D00_inl3(float v)
{
    volatile union { float f; int u; } h;
    union { float f; int u; } s;
    h.f = 0.5f;
    s.f = v;
    h.u = h.u | (s.u & 0x80000000);
    return (float)(int)(v + h.f);
}

// [G] an 8-byte vector read as two 32-bit halves (retail lwu / dsll32 / or).
static inline unsigned long func_00218D00_inl4(const CGtV2d *p)
{
    const unsigned int *w = (const unsigned int *)p;
    return (unsigned long)w[1] << 32 | w[0];
}

// 0x00218D00
void Gt2dRenderer::RenderTriStripFlatTex(const CGtV4d colour, const CGtV2d &pos, int n, const CGtV2d *pts, const CGtV2d *uvs)
{
    int ox = _gnGSOffX + (int)func_00218D00_inl3(16.0f * pos.marValues[0]);
    int oy = _gnGSOffY + (int)func_00218D00_inl3(16.0f * pos.marValues[1]);
    CGtV4d c = func_00218D00_inl1(colour, kUntexturedColourScale);
    if (511 - (int)(((unsigned int)(_gpu64Current + 1) - (unsigned int)_gau128Buffer) >> 4) < n + 5) {
        _Dispatch();
    }
    u_long128 i0;
    unsigned long h, b;
    asm("vftoi0.xyzw %0, %1" : "=j"(i0) : "j"(c.mData));
    asm("qmfc2.ni %0, %1" "\n\t" "ppach %0, $0, %0" : "=r"(h) : "j"(i0));
    asm("ppacb %0, $0, %1" : "=r"(b) : "r"(h));
    bool fresh;
    if (_guCurrentPrimType != 6 || (b | 0x3F80000000000000UL) != _gu64CurrentRGBAQ) {
        if (((int)_gpu64Current & 0xF) != 0) {
            _gpu64Current = _gpu64Current + 1;
        }
        _guCurrentPrimType = 6;
        unsigned long rgbaq = b | 0x3F80000000000000UL;
        unsigned long *p = _gpu64Current;
        _gu64CurrentRGBAQ = rgbaq;
        *(u_long128 *)p = _gu128SetPrimRGBAQGIFTag;
        p[2] = _gau64PrimRegs[6];
        p[3] = rgbaq;
        ((u_long128 *)p)[2] = _gau128RegListGIFTags[6];
        _gpuNLoops = (unsigned int *)(p + 4);
        _gpu64Current = _gpu64Current + 6;
        fresh = true;
    } else {
        fresh = false;
    }
    if (fresh) {
        *_gpuNLoops += n;
    } else {
        *_gpuNLoops += n + 2;
        unsigned long uv = func_00218D00_inl4(uvs);
        n--;
        unsigned long xy = (unsigned long)_gnZ << 32 | ((long)(ox + (int)(16.0f * pts->marValues[0])) | (long)(oy + (int)(16.0f * pts->marValues[1])) << 16);
        uvs++;
        pts++;
        *(u_long128 *)_gpu64Current = ((u_long128 *)_gpu64Current)[-1];
        u_long128 *q = (u_long128 *)_gpu64Current;
        _gpu64Current = (unsigned long *)(q + 1);
        u_long128 v;
        asm("pcpyld %0, %1, %2" : "=r"(v) : "r"(xy), "r"(uv));
        q[1] = v;
        q[2] = v;
        _gpu64Current = _gpu64Current + 4;
    }
    float py = pos.marValues[1];
    float px = pos.marValues[0];
    CGtV4d o = CGtV4d(px, py, px, py);
    CGtV4d off = func_00218D00_inl2(o, *(const CGtV4d *)&_gGsOffsetXYXY);
    unsigned long *p = _gpu64Current;
    unsigned long z = (unsigned long)_gnZ << 32;
    int i = 0;
    int m2 = n - 2;
    if (0 < m2) {
        unsigned long m = 0xFFFFFFFFUL;
        while (i < m2) {
            unsigned long p0 = func_00218D00_inl4(&pts[0]);
            i += 2;
            unsigned long p1 = func_00218D00_inl4(&pts[1]);
            unsigned long t0 = func_00218D00_inl4(&uvs[0]);
            unsigned long t1 = func_00218D00_inl4(&uvs[1]);
            u_long128 q, v;
            unsigned long x;
            asm("pcpyld %0, %1, %2" : "=r"(q) : "r"(p1), "r"(p0));
            pts += 2;
            uvs += 2;
            asm("qmtc2.ni %1, %0" : "=j"(v) : "r"(q));
            asm("vadd.xyzw %0, %0, %1" : "+j"(v) : "j"(off.mData));
            asm("vftoi4.xyzw %0, %0" : "+j"(v));
            asm("qmfc2.ni %0, %1" "\n\t" "ppach %0, $0, %0" : "=r"(x) : "j"(v));
            unsigned long a = x & m;
            unsigned long bb = x >> 32;
            bb &= m;
            a |= z;
            asm("pcpyld %0, %1, %2" : "=r"(*(u_long128 *)p) : "r"(a), "r"(t0));
            bb |= z;
            asm("pcpyld %0, %1, %2" : "=r"(*(u_long128 *)(p + 2)) : "r"(bb), "r"(t1));
            p += 4;
        }
    }
    while (i < n) {
        unsigned long uv = func_00218D00_inl4(uvs);
        i++;
        unsigned long xy = z | ((long)(ox + (int)(16.0f * pts->marValues[0])) | (long)(oy + (int)(16.0f * pts->marValues[1])) << 16);
        uvs++;
        pts++;
        asm("pcpyld %0, %1, %2" : "=r"(*(u_long128 *)p) : "r"(xy), "r"(uv));
        p += 2;
    }
    _gpu64Current = p;
}
