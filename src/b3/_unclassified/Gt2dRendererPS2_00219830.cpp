// Gt2dRenderer::RenderSpritesTex(GtMathPs2::CGtV4d,const GtMathPs2::CGtV2d&,int,const GtMathPs2::CGtV2d*,const GtMathPs2::CGtV2d*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu6: Ghidra draft + SetBlendMode packet shape; vmulw/vadd.xyzw stand-ins with by-value params for the frame, pts/uvs param copies for s0/s1, split and/or statements for the quad order).

// Gt2dRenderer::RenderSpritesTex(GtMathPs2::CGtV4d,const GtMathPs2::CGtV2d&,int,const GtMathPs2::CGtV2d*,const GtMathPs2::CGtV2d*)
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/.
// Hand-written (ghvu6) from the Ghidra draft; packet shapes from the proven SetBlendMode (func_00217E70) and the
// archived sibling RenderSpritesUntex. Static member types are [G] (instruction widths); _gGsOffsetXYXY is read as one
// 128-bit vector (lqc2).
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class Gt2dRenderer {
public:
    static void RenderSpritesTex(const CGtV4d colour, const CGtV2d &pos, int n, const CGtV2d *pts, const CGtV2d *uvs);
    static void _Dispatch();
    static const CGtV4d kUntexturedColourScale;
    static u_long128 *_gau128Buffer;
    static unsigned long *_gpu64Current;
    static unsigned int *_gpuNLoops;
    static int _guCurrentPrimType;
    static unsigned long _gu64CurrentRGBAQ;
    static int _gnZ;
    static u_long128 _gGsOffsetXYXY;
    static u_long128 _gu128SetPrimRGBAQGIFTag;
    static unsigned long _gau64PrimRegs[10];
    static u_long128 _gau128RegListGIFTags[10];
};

// [L] N185: stands in for a missing GtMathPs2 inline -- CGtV4d::operator*(WAxisType) (B3O0PCH map API), colour
// times the scale's w lane, hard-coded $vf1/$vf2 as the CGtV3d binary operators (retail vmulw.xyzw $vf1, $vf2, $vf1w).
// The by-value scale parameter gives retail's frame slot [G].
static inline CGtV4d func_00219830_inl1(const CGtV4d &c, CGtV4d k)
{
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vmulw.xyzw $vf1, $vf2, $vf1w" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(k.mData), "r"(c.mData));
    return CGtV4d(t);
}

// [L] N185: stands in for a missing GtMathPs2 inline -- CGtV4d::operator+(CGtV4d) (B3O0PCH map API), in place on the
// by-value left operand (retail vadd.xyzw $vf2, $vf2, $vf1; the by-value copy gives retail's frame slot [G]).
static inline CGtV4d func_00219830_inl2(CGtV4d a, const CGtV4d &b)
{
    asm("vadd.xyzw %0, %0, %1" : "+j"(a.mData) : "j"(b.mData));
    return CGtV4d(a.mData);
}
// 0x00219830
// [G] `const` on the by-value colour (not in the mangled name; N206: retail loads it before the register saves).
// [G] the two pointer parameters copied into locals (N215-style lever: retail keeps pts in s0, uvs in s1).
void Gt2dRenderer::RenderSpritesTex(const CGtV4d colour, const CGtV2d &pos, int n, const CGtV2d *pts0, const CGtV2d *uvs0)
{
    const CGtV2d *uvs = uvs0;
    const CGtV2d *pts = pts0;
    CGtV4d c = func_00219830_inl1(colour, kUntexturedColourScale);
    if (511 - (int)(((unsigned int)(_gpu64Current + 1) - (unsigned int)_gau128Buffer) >> 4) < n * 2 + 3) {
        _Dispatch();
    }
    // [L] N185: colour to RGBA bytes (vftoi0 / ppach / ppacb, as the SetColour stand-ins in B3VehicleDeform_00460C20)
    u_long128 i;
    unsigned long h, b;
    asm("vftoi0.xyzw %0, %1" : "=j"(i) : "j"(c.mData));
    asm("qmfc2.ni %0, %1" "\n\t" "ppach %0, $0, %0" : "=r"(h) : "j"(i));
    asm("ppacb %0, $0, %1" : "=r"(b) : "r"(h));
    if (_guCurrentPrimType != 0 || (b | 0x3F80000000000000UL) != _gu64CurrentRGBAQ) {
        if (((int)_gpu64Current & 0xF) != 0) {
            _gpu64Current = _gpu64Current + 1;
        }
        unsigned long *p = _gpu64Current;
        _guCurrentPrimType = 0;
        unsigned long rgbaq = b | 0x3F80000000000000UL;
        _gu64CurrentRGBAQ = rgbaq;
        *(u_long128 *)p = _gu128SetPrimRGBAQGIFTag;
        p[2] = _gau64PrimRegs[0];
        p[3] = rgbaq;
        ((u_long128 *)p)[2] = _gau128RegListGIFTags[0];
        _gpuNLoops = (unsigned int *)(p + 4);
        _gpu64Current = _gpu64Current + 6;
    }
    float py = pos.marValues[1];
    float px = pos.marValues[0];
    CGtV4d o = CGtV4d(px, py, px, py);
    *_gpuNLoops += n;
    CGtV4d off = func_00219830_inl2(o, *(const CGtV4d *)&_gGsOffsetXYXY);
    unsigned long z = (unsigned long)_gnZ << 32;
    unsigned long m = 0xFFFFFFFFUL;
    unsigned long *p = _gpu64Current;
    // [L] N185: per sprite, two points + offset -> vftoi4 -> ppach, packed with UV into two GIF quads (pcpyld, N218)
    do {
        unsigned long p0 = *(const unsigned long *)&pts[0];
        n--;
        unsigned long p1 = *(const unsigned long *)&pts[1];
        unsigned long t0 = *(const unsigned long *)&uvs[0];
        unsigned long t1 = *(const unsigned long *)&uvs[1];
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
        bb |= z;
        asm("pcpyld %0, %1, %2" : "=r"(*(u_long128 *)p) : "r"(a), "r"(t0));
        asm("pcpyld %0, %1, %2" : "=r"(*(u_long128 *)(p + 2)) : "r"(bb), "r"(t1));
        p += 4;
    } while (n > 0);
    _gpu64Current = p;
}
