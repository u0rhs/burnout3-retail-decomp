// Hand-written; the lifter refused it (stabs1: Revenge loop shape (i from lnStartUnit, lpUnit, result locals) + noreorder plane test).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_251740_seg {
    unsigned char pad_0[0x60];
    u_long128 field_60;
    u_long128 field_70;
    u_long128 field_80;
};
class CB3StreamedTrack {
public:
    int TestPosition(CGtV3d p);
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x34];
    unsigned char field_44;
    unsigned char pad_45[7];
    int field_4C;
    unsigned char pad_50[0x12C];
    UnkStruct_251740_seg *field_17C[1];
};
// stabs1 (2026-10-30): loop shape and locals from Revenge's TestPosition__16CB4StreamedTrackGQ29GtMathPs26CGtV3d
// (research/stabs, [L]): i, lnStartUnit, lpUnit, lu128Result, lu128ShiftedResult, luResult64 (names Revenge's, [L]);
// i runs from lnStartUnit to lnStartUnit + 9. The `.set noreorder` region around the plane test [G] keeps retail's
// three lq ahead of the first qmtc2.
// 0x00251740
int CB3StreamedTrack::TestPosition(CGtV3d p)
{
    CGtV3d pc = p;
    int i;
    if (field_44 == 0) return -1;
    int lnStartUnit = field_4C - 4;
    if (lnStartUnit < 0) lnStartUnit += field_C;
    for (i = lnStartUnit; i < lnStartUnit + 9; i++) {
        UnkStruct_251740_seg *lpUnit = field_17C[i % field_C];
        u_long128 lu128Result;
        asm(".set noreorder");
        asm("qmtc2.i %1, $vf1\n\tvmulax.xyzw $ACC, $vf1, %4x\n\tqmtc2.i %2, $vf1\n\tvmaddaz.xyzw $ACC, $vf1, %4z\n\tqmtc2.i %3, $vf1\n\tvmsubw.xyzw $vf1, $vf1, $vf0w\n\tqmfc2.ni %0, $vf1"
            : "=r"(lu128Result) : "r"(lpUnit->field_60), "r"(lpUnit->field_70), "r"(lpUnit->field_80), "j"(*(u_long128 *)&pc));
        asm(".set reorder");
        u_long128 lu128ShiftedResult;
        asm("psraw %0, %1, 31" : "=r"(lu128ShiftedResult) : "r"(lu128Result));
        unsigned long luResult64;
        asm("pcpyud %0, %1, $0\n\tor %0, %1, %0" : "=r"(luResult64) : "r"(lu128ShiftedResult));
        if (luResult64 == 0) return i % field_C;
    }
    return -1;
}
