// NONMATCHING: func_002BEDC0 -- retail 60 / ours 61 instructions, 9 in changed runs
// Frame and structure exact (0x1C0; Y/Z lanes read via ZAxisType-shaped copy-then-lane types; tail 'if (n<3) return 0; return n'). Left 9 instrs: min.Z read goes through a separate pointer (addiu v1,sp,88; lwc1 f13,0(v1)) where retail folds lwc1 f13,88(sp), plus the temp-slot register choices (retail t0/t1/t2 for the Z copies). [L] DNAT: ClipPolyToAABB (new_names.csv, medium).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_002BEDC0 -- hand-written (a69; lifter refused 'else branch shape'). [L] DNAT: ClipPolyToAABB(const CGtAxisAlignedBox&,
// GtMathPs2::CGtV3d*,GtMathPs2::CGtV3d*,int) (research/proto/new_names.csv, 002BEDC0, medium; also config/symbol_addrs_b3names.txt
// "[high]"). Retail's register order differs from that signature (a0 = output polygon, a2 = the box, a3 = input polygon, a1
// unused), so it keeps its placeholder name. Clips a triangle's polygon against the box one axis at a time with
// func_002BEEB0 (= ClipPolyBy2AxisPlanes(CGtV3d*,const float*,int,float,float,int)), ping-ponging through a stack buffer.
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_002BEDC0_box {
    CGtV3d field_0;    // min
    CGtV3d field_10;   // max
};
// [G] the Y lane read, shaped like GtMathPs2::ZAxisType (a copy, then a lane read); the header's YAxisType has no float operator [D]
struct UnkStruct_002BEDC0_y {
    u_long128 lVector;
    UnkStruct_002BEDC0_y() {}
    UnkStruct_002BEDC0_y(const UnkStruct_002BEDC0_y& o) { asm("sq %1, 0(%2)" : "=m"(lVector) : "r"(*(const u_long128*)&o.lVector), "r"(this)); }
    UnkStruct_002BEDC0_y(u_long128 v) { lVector = v; }
    operator float() const { UnkStruct_002BEDC0_y t(*this); return ((const float*)&t.lVector)[1]; }
};
struct UnkStruct_002BEDC0_z {
    u_long128 lVector;
    UnkStruct_002BEDC0_z() {}
    UnkStruct_002BEDC0_z(const UnkStruct_002BEDC0_z& o) { asm("sq %1, 0(%2)" : "=m"(lVector) : "r"(*(const u_long128*)&o.lVector), "r"(this)); }
    UnkStruct_002BEDC0_z(u_long128 v) { lVector = v; }
    operator float() const { UnkStruct_002BEDC0_z t(*this); return ((const float*)&t.lVector)[2]; }
};
// [L] ClipPolyBy2AxisPlanes(out, in, n, axis, hi, lo) (the ABI puts the two floats in f12/f13)
extern "C" int func_002BEEB0(void *out, const void *in, int n, int axis, float hi, float lo);

extern "C" int func_002BEDC0(void *out, int unused, const UnkStruct_002BEDC0_box *box, void *in)
{
    unsigned char tmp[0xF0];
    int n = func_002BEEB0(out, in, 3, 0, box->field_10.X(), box->field_0.X());
    if (n < 3) {
        return 0;
    }
    n = func_002BEEB0(tmp, out, n, 2, UnkStruct_002BEDC0_z(box->field_10.mData), UnkStruct_002BEDC0_z(box->field_0.mData));
    if (n < 3) {
        return 0;
    }
    n = func_002BEEB0(out, tmp, n, 1, UnkStruct_002BEDC0_y(box->field_10.mData), UnkStruct_002BEDC0_y(box->field_0.mData));
    if (n < 3) {
        return 0;
    }
    return n;
}
