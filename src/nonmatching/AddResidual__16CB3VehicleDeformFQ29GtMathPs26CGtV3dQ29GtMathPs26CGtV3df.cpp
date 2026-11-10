// NONMATCHING: AddResidual__16CB3VehicleDeformFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df -- retail 56 / ours 57 instructions, 9 in changed runs
// near22: lane reads as WAxisType puns (pointer-form copy slots like retail), qmtc2.i move of the slot vector into VU, goto found/done + scoped opt_repositioncode off [G]; logic/layout exact. Left 9 (frame-masked 5): frame 0x60 vs 0x50 (b's address-taken slot), a nop where retail fills bc1t's delay slot with the qmtc2, and the minw read goes qmfc2+sq where retail sqc2's from vf1
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV3dPlus;
using GtMathPs2::CGtV4d;
using GtMathPs2::WAxisType;

struct UnkStruct_003DBEA0_e {
    CGtV3d field_0;
    CGtV3dPlus field_10;
    unsigned char field_20;
    unsigned char pad_21[0xF];
};

class CB3VehicleDeform {
public:
    void AddResidual(CGtV3d, CGtV3d, float);
    unsigned char pad_0[0x80];
    UnkStruct_003DBEA0_e field_80[4];
};

#pragma push
#pragma opt_repositioncode off
void CB3VehicleDeform::AddResidual(CGtV3d p1, CGtV3d p2, float f)
{
    CGtV3d q1 = p1;
    CGtV3d q2 = p2;
    CGtV4d b;
    float minw = 3.402823466e+38f;
    int i;
    int bi = 0;
    for (i = 0; i < 4; i++) {
        const WAxisType &cw = *(const WAxisType *)&field_80[i].field_10;
        if (cw <= 0.0f) goto found;
        asm("qmtc2.i %1, %0" : "=j"(b.mData) : "r"(cw.lVector));
        if (!(minw <= *(const WAxisType *)&b)) {
            bi = i;
            minw = *(const WAxisType *)&b;
        }
    }
done:
    field_80[bi].field_0 = q1;
    field_80[bi].field_10.SetGtV3d(q2);
    field_80[bi].field_10.SetPlus(f);
    field_80[bi].field_20 = 3;
    return;
found:
    bi = i;
    goto done;
}
#pragma pop

