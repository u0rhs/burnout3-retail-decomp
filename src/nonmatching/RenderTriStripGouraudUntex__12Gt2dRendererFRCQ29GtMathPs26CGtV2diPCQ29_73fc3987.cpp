// NONMATCHING: RenderTriStripGouraudUntex__12Gt2dRendererFRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV4d -- retail 271 / ours 268 instructions, 193 in changed runs
// reshaped 2026-11-05 with the map's _NumQWFree / _SetPrimType / _DuplicateQW inlines and a non-volatile RoundToNearest stand-in (315 -> 193); left: frame 0x1B0 vs 0x190 (dead-slot layout), continuation and loop scheduling, RGBA lane-copy order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm 0x217FC0..0x2183F8: the space test, the prim-9 header (no dword at +0x18), the continuation (nloops + n + 2, q[0] = q[-1], cursor store before the two vertex qwords, net +0x30), the RGBA/XYZ2 packing and the do-while loop (no entry test) traced; behaviour_audit clean

// Gt2dRenderer::RenderTriStripGouraudUntex(const CGtV2d&, int, const CGtV2d*, const CGtV4d*) -- 0x217FC0, 0x43C.
// [C] name: the mangled symbol; parameter/local names as the RenderTriStripGouraudTex archive (Revenge STABS of the Tex
// sibling) [L]. draftAM C-first draft, reshaped 2026-11-05 (boot2 request) with the file's own inlines from the B3O0PCH map
// [C names]: Gt2dRenderer::_NumQWFree() (0x21F3F0), _SetPrimType(int) (0x21F280, 0x164), _DuplicateQW(int) (0x220DE0, 0xB0),
// _AddQW (0x21F1F0, 0x6C; mangled `_AddQW__12Gt2dRendererF1`, parameter type [G] u_long128), GtMath::RoundToNearest. Their
// bodies are [L] (from this function's asm); _SetPrimType's bool result = retail's t0 flag (1 after a new header, 0 if the
// type was already 9) [L]. 315 -> 193 changed; frame 0x1B0 vs retail 0x190 (dead-slot layout, N281/N282).
//
// Behaviour (all [C] from the retail asm 0x217FC0..0x2183F8):
// - offset = _gnGSOff + RoundToNearest(16 * lPixelOffset) per axis (before the space test; no memory side effect).
// - _Dispatch() when fewer than n + 5 qwords are free. (_Dispatch sets the prim type to 11, so the continuation below
//   never runs right after a dispatch: q[-1] is always this buffer's previous qword.)
// - prim type != 9: pad cur to 16 bytes, write GIF tag _gu128SetPrimGIFTag and PRIM _gau64PrimRegs[9] (dword +0x18 is NOT
//   written), the reg-list tag _gau128RegListGIFTags[9] at +0x20; _gpuNLoops -> +0x20; cur += 0x30; then *_gpuNLoops += n.
// - prim type == 9 (continue the strip): *_gpuNLoops += n + 2; copy the previous qword to cur (lq -0x10 / sq 0);
//   store cur + 0x10 to _gpu64Current; build vertex 0 and write it to cur + 0x10 and cur + 0x20; cur += 0x20 (net +0x30).
//   Vertex 0 (position and colour) is consumed here; the loop starts at vertex 1.
// - vertex qword: low dword RGBAQ = (int) of each lane of colour * kUntexturedColourScale (VU0 vmul.xyzw, truncating
//   cvt.w.s per lane, each sign-extended and OR-ed in at bits 0/8/16/24, no masking), Q = 1.0f in bits 32..63; high dword
//   XYZ2 = (offX + (int)(16 * x)) | (offY + (int)(16 * y)) << 16 | _gnZ << 32 (x, y terms sign-extended before the OR).
// - the loop is a do-while on lpPositions != lpLastPosition (bne at 0x2183AC): with no vertex left (n == 0, or n == 1 on a
//   continued strip) it runs on past the end. Kept as retail.

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class Gt2dRenderer {
public:
    static void RenderTriStripGouraudUntex(const CGtV2d &lPixelOffset, int lnNumVerts, const CGtV2d *lpPositions, const CGtV4d *lpColours);
    static void _Dispatch();
    static int _NumQWFree();
    static bool _SetPrimType(int t);
    static void _DuplicateQW(int i);
    static void _AddQW(u_long128 q);
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

// [C] name/signature: B3O0PCH map. [L] body: free qwords left in the 512-qword buffer (the cursor counts one dword ahead).
inline int Gt2dRenderer::_NumQWFree() { return 511 - (int)(((unsigned int)(_gpu64Current + 1) - (unsigned int)_gau128Buffer) >> 4); }

// [C] name/signature: B3O0PCH map. [L] body: the PRIM header packet, written only on a change; [L] true if it was written.
inline bool Gt2dRenderer::_SetPrimType(int t)
{
    if (_guCurrentPrimType != t) {
        if (((int)_gpu64Current & 0xF) != 0) {
            _gpu64Current = _gpu64Current + 1;
        }
        _guCurrentPrimType = t;
        unsigned long *p = _gpu64Current;
        *(u_long128 *)p = _gu128SetPrimGIFTag;
        p[2] = _gau64PrimRegs[t];
        ((u_long128 *)p)[2] = _gau128RegListGIFTags[t];
        _gpuNLoops = (unsigned int *)(p + 4);
        _gpu64Current = _gpu64Current + 6;
        return true;
    }
    return false;
}

// [C] name/signature: B3O0PCH map. [L] body: repeat the qword i back at the cursor, advance one qword.
inline void Gt2dRenderer::_DuplicateQW(int i)
{
    u_long128 *q = (u_long128 *)_gpu64Current;
    q[0] = q[-i];
    _gpu64Current = _gpu64Current + 2;
}

// [C] name: B3O0PCH map. [L] body: one qword at the cursor, advance. Defined for the port; this shape writes the loop's
// store inline (the asm below: same store, same advance).
inline void Gt2dRenderer::_AddQW(u_long128 q)
{
    *(u_long128 *)_gpu64Current = q;
    _gpu64Current = _gpu64Current + 2;
}

// FAKEMATCH [G] stand-in for GtMath::RoundToNearest (behaviour identical), as RenderSpritesUntex's archive: a plain 0.5
// store with volatile reads keeps retail's sw/lw without pinning both copies' stores in program order (N283).
static inline float func_00217FC0_inl2(float lrValue)
{
    GtMath::USplitBits lSplitHalf(0.5f);
    GtMath::USplitBits lSplitValue(lrValue);
    lSplitHalf.mxBits = *(volatile unsigned int *)&lSplitHalf.mxBits | (lSplitValue.mxBits & 0x80000000);
    return (float)(int)(lrValue + *(volatile float *)&lSplitHalf.mrReal);
}

// [L] one 128-bit qword from two dwords (pcpyld: hi, lo)
static inline u_long128 func_00217FC0_q(unsigned long hi, unsigned long lo)
{
    u_long128 r;
    asm("pcpyld %0, %1, %2" : "=r"(r) : "r"(hi), "r"(lo));
    return r;
}

// 0x00217FC0
void Gt2dRenderer::RenderTriStripGouraudUntex(const CGtV2d &lPixelOffset, int lnNumVerts, const CGtV2d *lpPositions, const CGtV4d *lpColours)
{
    const CGtV2d *lpLastPosition = lpPositions + lnNumVerts;
    int lnOffX = _gnGSOffX + (int)func_00217FC0_inl2(16.0f * lPixelOffset.marValues[0]);
    int lnOffY = _gnGSOffY + (int)func_00217FC0_inl2(16.0f * lPixelOffset.marValues[1]);
    if (_NumQWFree() < lnNumVerts + 5)
        _Dispatch();
    if (_SetPrimType(9)) {
        *_gpuNLoops += lnNumVerts;
    } else {
        // continue the strip: repeat the previous last vertex, then the new first vertex twice (two degenerate triangles)
        *_gpuNLoops += lnNumVerts + 2;
        const CGtV4d *lpC = lpColours++;
        float y = 16.0f * lpPositions->marValues[1];
        float x = 16.0f * lpPositions->marValues[0];
        lpPositions++;
        _DuplicateQW(1);
        CGtV4d c = *lpC * kUntexturedColourScale;
        unsigned long xy = (unsigned long)_gnZ << 32 | ((long)(lnOffX + (int)x) | (long)(lnOffY + (int)y) << 16);
        u_long128 v = func_00217FC0_q(xy, 0x3F80000000000000UL | ((long)(int)(float)c.W() << 24 | ((long)(int)(float)c.Z() << 16 | ((long)(int)(float)c.Y() << 8 | (long)(int)(float)c.X()))));
        u_long128 *q = (u_long128 *)_gpu64Current;
        q[0] = v;
        q[1] = v;
        _gpu64Current = _gpu64Current + 4;
    }
    do {
        float y = 16.0f * lpPositions->marValues[1];
        float x = 16.0f * lpPositions->marValues[0];
        CGtV4d c = *lpColours * kUntexturedColourScale;
        lpColours++;
        lpPositions++;
        unsigned long xy = (unsigned long)_gnZ << 32 | ((long)(lnOffX + (int)x) | (long)(lnOffY + (int)y) << 16);
        asm("pcpyld %0, %1, %2" : "=r"(*(u_long128 *)_gpu64Current) : "r"(xy), "r"(0x3F80000000000000UL | ((long)(int)(float)c.W() << 24 | ((long)(int)(float)c.Z() << 16 | ((long)(int)(float)c.Y() << 8 | (long)(int)(float)c.X())))));
        _gpu64Current = _gpu64Current + 2;
    } while (lpPositions != lpLastPosition);
}
