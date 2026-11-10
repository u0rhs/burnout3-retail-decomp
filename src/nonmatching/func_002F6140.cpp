// NONMATCHING: func_002F6140 -- retail 51 / ours 51 instructions, 12 in changed runs
// psweep: scoped #pragma opt_arithtransformation off [G] improves 13 -> 12
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_arithtransformation off
using namespace GtMathPs2;
struct UnkStruct_002F6140_t { unsigned char pad_0[4]; unsigned short field_4; };
struct UnkStruct_002F6140_a0 {
    CGtV3d field_0;
    CGtV3d field_10;
    unsigned char pad_20[0x40];
    UnkStruct_002F6140_t * field_60;
};
struct UnkStruct_002F6140_a1 { float field_0; float field_4; };
struct YT185 {
    u_long128 lVector;
    YT185() {}
    YT185(const YT185& o) { asm("sq %1, 0(%2)" : "=m"(lVector) : "r"(*(const u_long128*)&o.lVector), "r"(this)); }
    YT185(u_long128 v) { lVector = v; }
    operator float() const { YT185 t(*this); return ((const float*)&t.lVector)[1]; }
};
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
struct UnkStruct_002F6140_pad { int x[4]; UnkStruct_002F6140_pad() {} ~UnkStruct_002F6140_pad() {} };
extern "C" bool func_002F6140(UnkStruct_002F6140_a0 * a0, UnkStruct_002F6140_a1 * a1)
{
    UnkStruct_002F6140_pad pad;
    UnkStruct_002F6140_pad pad2;
    unsigned short t = a0->field_60->field_4;
    switch (t & 255) {
    case 32:
    case 36:
    case 35:
    case 34:
        goto yes;
    }
    if ((t & 0x800) ? true : false)
        goto yes;
    CGtV3d d = a0->field_0;
    asm("qmtc2.ni %1, $vf2\n\tvsubx.y %0, %0, $vf2x" : "+j"(d.mData) : "r"(a1->field_0));
    YAxisType dyv = d.Y();
    YAxisType *pd = &dyv;
    float qy = a0->field_10.Y();
    float dy = ((float *)pd)[1];
    if (!(qy <= 0.5f) && fabsf(dy) < fabsf(a1->field_4)) {
        a1->field_4 = dy;
        return false;
    }
    return true;
yes:
    return true;
}

#pragma pop
