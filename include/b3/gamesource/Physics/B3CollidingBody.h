// CB3CollidingBody: split out of B3VehiclePhysics.h into its own file 2026-10-20 (N35/N36 realignment).
// [C] folder: alienbrain literal path GameSource\Physics\B4CollidingBody.cpp
// (research/R_jul14/symtab.csv) -- same CB3->CB4 naming pattern already proven (N31/N33).
// Field layout below is the union of two independently-sourced bits of evidence:
//  - `_p[0x204]`/`mpMatrix`/`mbCrashing`: carried over as-is from the embedded definition that used
//    to live in B3VehiclePhysics.h ([assert, class L], retail offsets via research/retail_fieldmap.csv).
//  - fields 0xB0..0x140: derived this session from StopImmediately()'s own disassembly (N37).
#ifndef B3_B3COLLIDINGBODY_H
#define B3_B3COLLIDINGBODY_H

#include "b3/GtMathPs2.h"

struct CB3CollidingBody
{
    char _p[0xB0];
    GtMathPs2::CGtV4d field_B0;    // [L] StopImmediately zeros all 4 lanes (vsub.xyzw) -- accumulator?
    GtMathPs2::CGtV4d field_C0;    // [L] StopImmediately copies mpMatrix's mAt vector (+0x20) here, not zeroed
    GtMathPs2::CGtV3d field_D0;    // [L] StopImmediately zeros (vadd.xyz)
    GtMathPs2::CGtV3d field_E0;    // [L] StopImmediately zeros
    GtMathPs2::CGtV3d field_F0;    // [L] StopImmediately zeros
    GtMathPs2::CGtV3d field_100;   // [L] StopImmediately zeros
    GtMathPs2::CGtV3d field_110;   // [L] StopImmediately zeros
    GtMathPs2::CGtV3d field_120;   // [L] StopImmediately zeros
    GtMathPs2::CGtV3d field_130;   // [L] StopImmediately zeros
    char pad140[0x150 - 0x140];
    GtMathPs2::CGtV3d field_150;   // [L] StopCrashing zeros (vadd.xyz), not covered by its memset
    GtMathPs2::CGtV3d field_160;   // [L] StopCrashing zeros explicitly, also inside its memset range
    GtMathPs2::CGtV3d field_170;   // [L] StopCrashing zeros explicitly, also inside its memset range
    char pad180[0x190 - 0x180];    // [L] inside StopCrashing's memset(this+0x160, 0, 0x60) range, no field needed by name
    short field_190;                // [L] StopCrashing zeros
    char pad192[2];
    int field_194;                  // [L] StopCrashing zeros
    int field_198;                  // [L] StopCrashing zeros
    char pad19C[0x204 - 0x19C];
    GtMathPs2::CGtMatrix3x4 *mpMatrix;  // [assert, class L] "mpMatrix->IsOrthogonal()"
    char pad208[0x20E - 0x208];
    unsigned char field_20E;         // [L] StopCrashing zeros
    char pad20F[0x210 - 0x20F];
    bool mbCrashing;  // [assert, class L] "!mbCrashing"
    char pad211[0x218 - 0x211];
    signed char field_218;           // [L] StopCrashing sets -1 (invalidated handle, same N32 idiom)

    void StopImmediately();   // 0x001AB040 [C]: decompiled and objdiff-verified
    void Destruct();          // 0x001AC450 [C]: decompiled and objdiff-verified (empty body, N41)
    void Release();           // 0x001AC460 [C]: decompiled and objdiff-verified (empty body, N41)
    void StopCrashing();      // 0x001ABDD0 [C]: decompiled and objdiff-verified (Target #16, N43)
};

#endif
