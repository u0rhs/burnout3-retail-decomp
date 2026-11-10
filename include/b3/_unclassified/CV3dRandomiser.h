#ifndef B3_CV3DRANDOMISER_H
#define B3_CV3DRANDOMISER_H
// CV3dRandomiser and the per-file random state: the VU0 R-register random vectors of the effects / explosion code.
// gapO (2026-11-01, N288; lead approval for Revenge STABS names). File name and folder [G] (named after the class; no Area
// evidence, so _unclassified). Only the files that use it include it: the two statics below are `static`, so every
// includer gets (and initialises) its own pair, as retail does.
//
// [L] names: Burnout Revenge prototype STABS. research/stabs/revenge_jul14_types.h:33006 `struct CV3dRandomiser { // 0x20
// CGtV3d mVecA; CGtV3d mVecB; Prepare(); CGtV3d RandomInterpolate(); CGtV3d RandomiseXYZ(); }`; locals of that type 0x20
// apart on the stack in Revenge's spawners (SpawnDebrisFromPoint__17CB4EffectsManager -0x1d0/-0x1b0/-0x190, ...). Statics:
// research/burnout3-symbols/.../SLUS_212.42/globals.txt `static CGtV4d gEffectsRandomiserScales; static CGtV4d
// kEffectsRandomiser2E23;` in each of B4EffectsManager.cpp, B4ExplosionManager.cpp, B4PropParticleRenderer.cpp,
// B4DebrisFieldRenderer.cpp.
// [C] B3 retail shape:
//  - one (state, constant) pair per file, each set by that file's static initialiser to the same values: B3EffectsManager
//    D_01D9D190 (.bss) / D_004BBFB0 (sinit 0x4D5D54 / 0x4D5D58), B3ExplosionManager D_01EA4BA0 (.bss) / D_004C9A00
//    (sinit 0x4DA1E8 / 0x4DA1EC); state = (491.156464, 721.334534, 551.727295, 301.123444) (D_004E0C2C.. / D_004E1000..),
//    constant = 0x4B000000 = 8388608.0f = 2^23 in all four lanes. B3 has no prop-particle / debris-field users.
//  - a randomiser is a 0x20 stack object, maximum at +0x00 and (maximum - minimum) at +0x10: func_0039A360 sp+0x7B0/0x7C0
//    and sp+0x790/0x7A0, read by `vaddax.xyz ACC, A, vf0x; vmadd.xyz d, B, t` (0x39A6BC..0x39A70C).
//  - a draw: R (vrnext, [1,2)) times the state, then the 2^23 trick: ACC = (k + t') - k rounds t' to an integer (VU
//    truncates), d = ACC - t' = floor(t') - t', in (-1, 0]; so A + B * d is uniform in [A - B, A] = [minimum, maximum].
//    The state then rotates one lane (vmr32) and is stored back.
//  - two result shapes: three draws, one per lane, `vmadd.xyz` (func_0039A360 x3; func_0025D930 x3) and one draw used for
//    all lanes, `vmaddx.xyz` (func_0025D930 0x25DCD0, 0x25DE60). [L] by the names: RandomiseXYZ = independent per lane,
//    RandomInterpolate = one t along the line A..A-B. Prepare() is declared in Revenge but its body has no B3 evidence: not
//    provided here (the B3 users write mVecA / mVecB directly).
// The VU0 R seed (vrinit from CGtRandom::RandomReal()) has no name anywhere: it stays a local helper in its users.
// Each vrnext is its own volatile statement (hard1): in one statement MWCC drops the .x/.y draws as dead partial writes
// and the R sequence loses two advances.
#include "b3/GtMathPs2.h"

// [C] both CGtV4d per Revenge; values [C] from the B3 static initialisers above. const: [G] -- B3 places the constant in
// .rodata (D_004C9A00, D_004BBFB0) although the sinit writes it; Revenge has both in .bss.
static GtMathPs2::CGtV4d gEffectsRandomiserScales(491.156464f, 721.334534f, 551.727295f, 301.123444f);
static const GtMathPs2::CGtV4d kEffectsRandomiser2E23(8388608.0f, 8388608.0f, 8388608.0f, 8388608.0f);

struct CV3dRandomiser {
    GtMathPs2::CGtV3d mVecA;     // +0x00 [L] Revenge STABS; B3 [C]: the maximum
    GtMathPs2::CGtV3d mVecB;     // +0x10 [L] Revenge STABS; B3 [C]: maximum - minimum
    GtMathPs2::CGtV3d RandomInterpolate();
    GtMathPs2::CGtV3d RandomiseXYZ();
};

#if defined(__MWERKS__)
// [L] one draw in x (`vrnext.x; vmulx.x; vaddax.x; vmsubaw.x; vmsubw.x`), A + B * t.x (`vaddax.xyz; vmaddx.xyz`), as retail
// func_0025D930 (CB3EffectsManager).
inline GtMathPs2::CGtV3d CV3dRandomiser::RandomInterpolate()
{
    u_long128 r, t, d, st, o;
    asm volatile("vrnext.x %0, $R" : "=j"(r));
    st = gEffectsRandomiserScales.mData;
    asm("vmulx.x %0, %1, %2x" : "=j"(t) : "j"(st), "j"(r));
    asm("vaddax.x $ACC, %1, %2x" "\n\t" "vmsubaw.x $ACC, %1, $vf0w" "\n\t" "vmsubw.x %0, %2, $vf0w"
        : "=j"(d) : "j"(kEffectsRandomiser2E23.mData), "j"(t));
    asm("vmr32.xyzw %0, %1" : "=j"(st) : "j"(st));
    gEffectsRandomiserScales.mData = st;
    asm("vaddax.xyz $ACC, %1, $vf0x" "\n\t" "vmaddx.xyz %0, %2, %3x" : "=j"(o) : "j"(mVecA.mData), "j"(mVecB.mData), "j"(d));
    return GtMathPs2::CGtV3d(o);
}
// [L] three draws, one per lane (`vmul.xyz; vadda.xyz; vmsubaw.xyz; vmsubw.xyz`), A + B * t per lane (`vaddax.xyz;
// vmadd.xyz`), as retail func_0039A360 (CB3ExplosionManager) and func_0025D930.
inline GtMathPs2::CGtV3d CV3dRandomiser::RandomiseXYZ()
{
    u_long128 r, t, d, st, o;
    asm volatile("vrnext.x %0, $R" : "=j"(r));
    asm volatile("vrnext.y %0, $R" : "+j"(r));
    asm volatile("vrnext.z %0, $R" : "+j"(r));
    st = gEffectsRandomiserScales.mData;
    asm("vmul.xyz %0, %1, %2" : "=j"(t) : "j"(st), "j"(r));
    asm("vadda.xyz $ACC, %1, %2" "\n\t" "vmsubaw.xyz $ACC, %1, $vf0w" "\n\t" "vmsubw.xyz %0, %2, $vf0w"
        : "=j"(d) : "j"(kEffectsRandomiser2E23.mData), "j"(t));
    asm("vmr32.xyzw %0, %1" : "=j"(st) : "j"(st));
    gEffectsRandomiserScales.mData = st;
    asm("vaddax.xyz $ACC, %1, $vf0x" "\n\t" "vmadd.xyz %0, %2, %3" : "=j"(o) : "j"(mVecA.mData), "j"(mVecB.mData), "j"(d));
    return GtMathPs2::CGtV3d(o);
}
#endif
#endif
