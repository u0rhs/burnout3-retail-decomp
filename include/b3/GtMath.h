// GtMath: Criterion's scalar maths helpers.
// [C] names: GtMath::Max(float,float) (12 bytes), GtMath::Min(float,float) (12 bytes) and
//     GtMath::Max(float,float,float) in research/E_B3O0PCH_symbols.csv (0x14A8F0, 0x14A900, 0x26AE40).
// [G] this file's name (after the namespace, as include/b3/GtMathPs2.h is named after GtMathPs2): no file
//     evidence for where the inlines are declared.
#ifndef B3_GTMATH_H
#define B3_GTMATH_H

namespace GtMath {

// [C] a single R5900 max.s / min.s (the 12-byte out-of-line copies: the instruction, jr ra, nop). Inlined, a
// computed argument is bound to a float local first: probe build/vt/mx/fog7.cpp matches
// CB3Fog::CalculateClipPlanes (0x240EF0) 13/13, fog8.cpp (the product passed directly) differs in 4.
inline float Max(float a, float b) { float r; asm("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
inline float Min(float a, float b) { float r; asm("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
// [C] name: GtMath::Abs(float) in research/E_B3O0PCH_symbols.csv (0x12EF10, 12 bytes). [L] body: one abs.s, as the proven
// file-local fabsf helpers (N170/N176); MWCC b119 has no fabs intrinsic. hdrrd (2026-10-27); was the lifter's ABS_HELPER.
inline float Abs(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

// ---- gapH (2026-10-31): GtMath::Sign(float) ----
// [C] API: B3O0PCH map (GtMath::Sign(float) 0x155390, 72 bytes; its only new helper GtMath::USplitBits::USplitBits(float) 0x1553E0,
// 40 bytes, emitted right after it). [L] USplitBits = Revenge STABS `union USplitBits { RwReal mrReal; RwUInt32 mxBits; }` (B3 adds
// the float constructor); Revenge's inlined Sign copies name the parameter lrReal and the local `USplitBits lSplitBits` on the
// stack. [C] retail census (build/vt/gapH/census_sign.py): 27 copies in 17 functions, 24 through a stack word (swc1; lw; and
// 0x80000000; or 0x3F800000; sw; lwc1). [L] body: the sign bit of x on 1.0.
union USplitBits {
    float mrReal;
    unsigned int mxBits;
    USplitBits(float lrReal) { mrReal = lrReal; }
};
inline float Sign(float lrReal)
{
    USplitBits lSplitBits(lrReal);
    lSplitBits.mxBits = (lSplitBits.mxBits & 0x80000000) | 0x3F800000;
    return lSplitBits.mrReal;
}

// ---- gapJ (2026-10-31): GtMath::Min(int,int) / Max(int,int) ----
// [C] API: B3O0PCH map (GtMath::Min(int,int) 0x14F5C0, GtMath::Max(int,int) 0x14F5D0, 16 bytes each). [L] body: one MMI pminw / pmaxw
// then pextlw r, $0, r (retail census build/vt/gapJ/census_mm.py: 61 of the 98 pminw/pmaxw sites are followed by a self pextlw;
// `max(min())` pairs carry one pextlw, so [L] those are another API, e.g. GtMath::Clamp(int,int,int) (map, 36 bytes)). -O0 16 = map
// [C] (without the pextlw 12). As the proven units' local stand-ins (B3Profile_00139C00 a137_min/max + a137_zx, B3HUDScore_001A1CD0).
inline int Min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); asm("pextlw %0, $0, %0" : "+r"(r)); return r; }
inline int Max(int a, int b) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); asm("pextlw %0, $0, %0" : "+r"(r)); return r; }

// ---- gapJ (2026-10-31): GtMath::InvSqrt(float) ----
// [C] API: B3O0PCH map (GtMath::InvSqrt(float) 0x1B64F0, 64 bytes). [L] body: retail's inlined copy is one rsqrt.s with 1.0
// (CB3CollidingBody::Update 0x1AD1D4; as proven GtWideLine_0041D910). [C] `1.0f / sqrtf(x)` gives sqrt.s + div.s under b119p, also with
// `#pragma rsqrt on` / `#pragma fastmath on` (build/vt/gapJ/t/p3.cpp). -O0 36 vs map 64: open.
inline float InvSqrt(float x) { float r, one = 1.0f; asm("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(one), "f"(x)); return r; }

// ---- gapK (2026-10-31): GtMath::IsEffectivelyZero(float) ----
// [C] API: B3O0PCH map (GtMath::IsEffectivelyZero(float) 0x140630, 40 bytes). [C] retail census (build/vt/gapK/census1.py, census6.py):
// 46 sites in 26 functions test the float's bits `(bits & 0x7F800000) < 0x37800001` (exponent at most 2^-16's), the bits taken by mfc1
// from an FPR (15), by lw from a float already in memory (9, e.g. CB3BehaviourTrackSide::Update 0x2FDE34) or by qmfc2 from a lane (5).
// [L] body: the proven units' mfc1 stand-in (B3SoundTurboModel_0028FB20, func_00288480, B3AIAvoidance_0013DD30 route through it
// identically, gapK prov); `*(unsigned int *)&x` instead goes through a stack word (swc1/lw) under b119p. `<=` with the threshold as
// written there ([C]: `< 0x37800001` puts the threshold in a different register). -O0 32 vs map 40: open.
inline bool IsEffectivelyZero(float lrValue) { unsigned int lxBits; asm("mfc1 %0, %1" : "=r"(lxBits) : "f"(lrValue)); return (lxBits & 0x7F800000) <= 0x37800000; }

// ---- gapK (2026-10-31): GtMath::RoundToNearest(float) ----
// [C] API: B3O0PCH map (GtMath::RoundToNearest(float) 0x220290, 124 bytes, in Gt2dRendererPS2.cpp). [L] locals: Revenge STABS
// `USplitBits lSplitValue; USplitBits lSplitHalf;` (CB4BehaviourRaceCarFollow::Update, CB4CrashScore). [C] retail census
// (build/vt/gapK/census3.py): 8 copies (CB3Profile::Evaluate 0x139E44, six Gt2dRenderer primitives, RaceCarFollow Update 0x2E3528):
// 0.5's bits stored (sw) and reloaded (lw), the sign bit of x or-ed in, then (float)(int)(x + half); lSplitHalf sits above lSplitValue
// in the frame -> declared first [L]. -O0 124 = map [C] (with or without the volatile).
// FAKEMATCH [G]: `volatile` on lSplitHalf. b87/b103/b119 forward the constant store (lui + dsll32/dsra32, no sw/lw); the R3.0
// 3.0-011126 compiler keeps retail's sw/lw without it (build/vt/gapK/t/rn2.cpp) -> retail's compiler lacks that forwarding [L].
// Proven B3Profile_00139C00 (its volatile-union stand-in) routes through it identically (gapK prov).
inline float RoundToNearest(float lrValue)
{
    volatile USplitBits lSplitHalf(0.5f);
    USplitBits lSplitValue(lrValue);
    lSplitHalf.mxBits |= lSplitValue.mxBits & 0x80000000;
    return (float)(int)(lrValue + lSplitHalf.mrReal);
}

// ---- gapK (2026-10-31): GtMath::Clamp(int,int,int) ----
// [C] API: B3O0PCH map (GtMath::Clamp(int,int,int) 0x134A80, 36 bytes). [C] retail census (build/vt/gapK/census4.py): 23 pmaxw ->
// pminw pairs in 20 functions, 22 with ONE pextlw after the pminw (Min(Max()) would give two). [L] body: Max's pmaxw, Min's pminw, one
// pextlw; the proven units' zx(min(max())) stand-ins route through it identically (B3Profile_00139C00, B3DebugManager_00130030,
// B3AITarget_00149B50, func_0013B260, B3AILane_00145E70, Gt2dRendererPS2_00217880, B3AIDriver_00144810; gapK prov).
// -O0 20 vs map 36: open (the float Clamp is 32 vs Min(float)'s 12: both carry 4 more instructions than their asm).
inline int Clamp(int lnValue, int lnMin, int lnMax) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(lnValue), "r"(lnMin)); asm("pminw %0, %1, %2" : "=r"(r) : "r"(r), "r"(lnMax)); asm("pextlw %0, $0, %0" : "+r"(r)); return r; }

}  // namespace GtMath

#endif
