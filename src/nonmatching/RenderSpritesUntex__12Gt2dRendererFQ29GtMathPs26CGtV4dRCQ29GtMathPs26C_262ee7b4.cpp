// NONMATCHING: RenderSpritesUntex__12Gt2dRendererFQ29GtMathPs26CGtV4dRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2d -- retail 191 / ours 191 instructions, 42 in changed runs
// reshaped 2026-11-05 with the map's _NumQWFree / _SetPrimTypeAndRGBAQ inlines and a non-volatile RoundToNearest stand-in (56 -> 42); left: RGBA lane-copy order (retail copies W, Z, Y first), the second rounding's half/sign scheduling
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm 0x219530..0x21982C: space test, header test and packet (tag, PRIM[1], RGBAQ, reg-list tag, NLOOP pointer), RGBAQ packing (truncating, sign-extended, unmasked), rounded offset, do-while sprite loop (one sq per sprite, pts[0] low) traced; behaviour_audit clean

// Gt2dRenderer::RenderSpritesUntex(GtMathPs2::CGtV4d,const GtMathPs2::CGtV2d&,int,const GtMathPs2::CGtV2d*)
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ when matched.
// fresh5 hand draft, reshaped 2026-11-05 (boot2 request) with the file's own inlines from the B3O0PCH map [C names]:
// Gt2dRenderer::_NumQWFree() (0x21F3F0, 0x28) and Gt2dRenderer::_SetPrimTypeAndRGBAQ(int,unsigned long) (0x21FDB0, 0x190,
// emitted after RenderSpritesTex, its first user); GtMath::RoundToNearest (0x220290, emitted right after this function).
// Their bodies are [L]: written from this function's asm (_NumQWFree gave retail's cur/buf registers: 56 -> 52 changed).
//
// Behaviour (all [C] from the retail asm 0x219530..0x21982C):
// - colour lane-wise times kUntexturedColourScale (one VU0 vmul.xyzw; the product is only spilled to the stack, whole).
// - _Dispatch() when fewer than n + 3 qwords are free (511 - ((cur + 8 - buf) >> 4), unsigned shift).
// - RGBAQ = (int) of each scaled lane (cvt.w.s = truncation), each sign-extended to 64 bits and OR-ed in at bits 0/8/16/24,
//   Q = 1.0f (0x3F800000) in bits 32..63. No masking: a lane >= 256 or < 0 bleeds into the next byte / into Q.
// - unless prim type is already 1 with that RGBAQ: pad cur to 16 bytes, write GIF tag _gu128SetPrimRGBAQGIFTag, PRIM
//   _gau64PrimRegs[1], RGBAQ, the reg-list tag _gau128RegListGIFTags[1]; _gpuNLoops -> that tag; cur += 0x30.
// - offset = _gnGSOff + RoundToNearest(16 * pos) per axis; *_gpuNLoops += n.
// - per sprite (do-while: n <= 0 still writes one sprite): XYZ2 words (ox + (int)(16 * x)) | (oy + (int)(16 * y)) << 16 |
//   _gnZ << 32 for pts[0] (low dword) and pts[1] (high dword), one sq; cur += 0x10; pts += 2. The x and y terms are
//   sign-extended before the OR (a negative x clobbers the y and z fields).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class Gt2dRenderer {
public:
    static void RenderSpritesUntex(CGtV4d colour, const CGtV2d &pos, int n, const CGtV2d *pts);
    static void _Dispatch();
    static int _NumQWFree();
    static void _SetPrimTypeAndRGBAQ(int t, unsigned long rgbaq);
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

// [C] name/signature: B3O0PCH map. [L] body: free qwords left in the 512-qword buffer (the cursor counts one dword ahead).
inline int Gt2dRenderer::_NumQWFree() { return 511 - (int)(((unsigned int)(_gpu64Current + 1) - (unsigned int)_gau128Buffer) >> 4); }

// [C] name/signature: B3O0PCH map. [L] body: the PRIM + RGBAQ header packet, written only on a change.
inline void Gt2dRenderer::_SetPrimTypeAndRGBAQ(int t, unsigned long rgbaq)
{
    if (_guCurrentPrimType != t || rgbaq != _gu64CurrentRGBAQ) {
        if (((int)_gpu64Current & 0xF) != 0) {
            _gpu64Current = _gpu64Current + 1;
        }
        _guCurrentPrimType = t;
        unsigned long *p = _gpu64Current;
        _gu64CurrentRGBAQ = rgbaq;
        *(u_long128 *)p = _gu128SetPrimRGBAQGIFTag;
        p[2] = _gau64PrimRegs[t];
        p[3] = rgbaq;
        ((u_long128 *)p)[2] = _gau128RegListGIFTags[t];
        _gpuNLoops = (unsigned int *)(p + 4);
        _gpu64Current = _gpu64Current + 6;
    }
}

// FAKEMATCH [G] stand-in for GtMath::RoundToNearest (behaviour identical: x + copysign(0.5, x), truncated, back to float).
// The header's `volatile lSplitHalf` pins both copies' 0.5 stores in program order; retail (an older compiler without the
// 0.5 forwarding, N283) stores both halves first. A plain store with volatile READS keeps retail's sw/lw and lets the
// second store hoist: 52 -> 42 changed. For the port, GtMath::RoundToNearest is the same function.
static inline float func_00219530_inl1(float lrValue)
{
    GtMath::USplitBits lSplitHalf(0.5f);
    GtMath::USplitBits lSplitValue(lrValue);
    lSplitHalf.mxBits = *(volatile unsigned int *)&lSplitHalf.mxBits | (lSplitValue.mxBits & 0x80000000);
    return (float)(int)(lrValue + *(volatile float *)&lSplitHalf.mrReal);
}

// 0x00219530
void Gt2dRenderer::RenderSpritesUntex(CGtV4d colour, const CGtV2d &pos, int n, const CGtV2d *pts)
{
    CGtV4d c = colour * kUntexturedColourScale;
    if (_NumQWFree() < n + 3) {
        _Dispatch();
    }
    // [L] retail's OR tree is W | (Z | (X | Y)); this order (W | (Z | (Y | X))) schedules closer (42 vs 47). Same value.
    unsigned long rgbaq = 0x3F80000000000000UL | ((long)(int)(float)c.W() << 24 | ((long)(int)(float)c.Z() << 16 | ((long)(int)(float)c.Y() << 8 | (long)(int)(float)c.X())));
    _SetPrimTypeAndRGBAQ(1, rgbaq);
    int ox = _gnGSOffX + (int)func_00219530_inl1(16.0f * pos.marValues[0]);
    int oy = _gnGSOffY + (int)func_00219530_inl1(16.0f * pos.marValues[1]);
    *_gpuNLoops += n;
    unsigned long z = (unsigned long)_gnZ << 32;
    do {
        unsigned long a = z | ((long)(ox + (int)(16.0f * pts[0].marValues[0])) | (long)(oy + (int)(16.0f * pts[0].marValues[1])) << 16);
        unsigned long b = z | ((long)(ox + (int)(16.0f * pts[1].marValues[0])) | (long)(oy + (int)(16.0f * pts[1].marValues[1])) << 16);
        n--;
        pts += 2;
        asm("pcpyld %0, %1, %2" : "=r"(*(u_long128 *)_gpu64Current) : "r"(b), "r"(a));
        _gpu64Current = _gpu64Current + 2;
    } while (n > 0);
}
