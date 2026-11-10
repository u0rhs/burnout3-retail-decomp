// NONMATCHING: RenderTriStripFlatUntex__12Gt2dRendererFQ29GtMathPs26CGtV4dRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2d -- retail 233 / ours 232 instructions, 185 in changed runs
// 185 off (232/233): logic/layout per retail; s-register rotation (retail n s4, pts s3, end s2, ox s1, oy s0) + RGBAQ/rounding scheduling as in RenderSpritesUntex's archive
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Gt2dRenderer::RenderTriStripFlatUntex(GtMathPs2::CGtV4d,const GtMathPs2::CGtV2d&,int,const GtMathPs2::CGtV2d*)
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/.
// Hand-written (fresh5): lifter refused. Packet shapes from the proven SetClipRegion / SetBlendMode (func_00217E70);
// the copysign-0.5 rounding union from B3Profile_00139C00.cpp (pass2a: volatile half keeps retail's sw/lw).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class Gt2dRenderer {
public:
    static void RenderTriStripFlatUntex(CGtV4d colour, const CGtV2d &pos, int n, const CGtV2d *pts);
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
    static u_long128 _gu128SetPrimRGBAQGIFTag;
    static unsigned long _gau64PrimRegs[10];
    static u_long128 _gau128RegListGIFTags[10];
};

// [G] placeholder for the inlined round-to-nearest (x + copysign(0.5, x), truncated, back to float).
static inline float func_00218400_inl1(float v)
{
    volatile union { float f; int u; } h;
    union { float f; int u; } s;
    h.f = 0.5f;
    s.f = v;
    h.u = h.u | (s.u & 0x80000000);
    return (float)(int)(v + h.f);
}

// 0x00218400
void Gt2dRenderer::RenderTriStripFlatUntex(CGtV4d colour, const CGtV2d &pos, int n, const CGtV2d *pts)
{
    const CGtV2d *end = pts + n;
    int ox = _gnGSOffX + (int)func_00218400_inl1(16.0f * pos.marValues[0]);
    int oy = _gnGSOffY + (int)func_00218400_inl1(16.0f * pos.marValues[1]);
    CGtV4d c = colour * kUntexturedColourScale;
    if (511 - (int)(((unsigned int)(_gpu64Current + 1) - (unsigned int)_gau128Buffer) >> 4) < (n + 1) / 2 + 4) {
        _Dispatch();
    }
    unsigned long rgbaq = 0x3F80000000000000UL | ((long)(int)(float)c.W() << 24 | ((long)(int)(float)c.Z() << 16 | ((long)(int)(float)c.Y() << 8 | (long)(int)(float)c.X())));
    bool fresh = false;
    if (_guCurrentPrimType != 8 || rgbaq != _gu64CurrentRGBAQ) {
        if (((int)_gpu64Current & 0xF) != 0) {
            _gpu64Current = _gpu64Current + 1;
        }
        _guCurrentPrimType = 8;
        unsigned long *p = _gpu64Current;
        _gu64CurrentRGBAQ = rgbaq;
        *(u_long128 *)p = _gu128SetPrimRGBAQGIFTag;
        fresh = true;
        p[2] = _gau64PrimRegs[8];
        p[3] = rgbaq;
        ((u_long128 *)p)[2] = _gau128RegListGIFTags[8];
        _gpuNLoops = (unsigned int *)(p + 4);
        _gpu64Current = _gpu64Current + 6;
    }
    if (fresh) {
        *_gpuNLoops += n;
    } else {
        *_gpuNLoops += n + 2;
        unsigned long v = (unsigned long)_gnZ << 32 | ((long)(ox + (int)(16.0f * pts->marValues[0])) | (long)(oy + (int)(16.0f * pts->marValues[1])) << 16);
        pts++;
        *_gpu64Current = _gpu64Current[-1];
        *++_gpu64Current = v;
        unsigned long *q = _gpu64Current++;
        q[1] = q[0];
        _gpu64Current++;
    }
    unsigned long z = (unsigned long)_gnZ << 32;
    do {
        *_gpu64Current = z | ((long)(ox + (int)(16.0f * pts->marValues[0])) | (long)(oy + (int)(16.0f * pts->marValues[1])) << 16);
        pts++;
        _gpu64Current++;
    } while (pts != end);
}
