// NONMATCHING: GetRowPos__16CGt2dObjectTableFi -- retail 58 / ours 59 instructions, 26 in changed runs
// near23: loop as *py = e->field_4 + pos.marValues[1] (read via a different expression than the write) gives retail's field+acc add.s order; tail field + pos.X()/Y(). Left: retail keeps &pos.y in a1 (ours t0) and its tail reads pos via sp without CSE-ing &pos.y; ours stores y through py and reloads
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: GetRowPos__16CGt2dObjectTableFi -- retail 58 / ours 59 instructions, 26 in changed runs
// 26 instrs off: logic right; retail keeps sub=self+0x20 in t1, loop pointer &pos.y in a1 set after init stores, tail reads pos via sp direct; ours puts py in t1/sub in t2 and tail via py
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

struct UnkStruct_Gt2dObjectTable_row { float field_0; float field_4; float field_8; };
struct UnkStruct_Gt2dObjectTable_data {
    unsigned char pad_0[8];
    int field_8;
    int field_C;
    UnkStruct_Gt2dObjectTable_row *field_10;
    UnkStruct_Gt2dObjectTable_row *field_14;
};
struct UnkStruct_Gt2dObjectTable_sub {
    unsigned char pad_0[0x10];
    UnkStruct_Gt2dObjectTable_data *field_10;
};
struct UnkStruct_Gt2dObjectTable_self {
    float field_0; float field_4;
    unsigned char pad_8[0x18];
    UnkStruct_Gt2dObjectTable_sub field_20;
};
extern "C" CGtV2d GetRowPos__16CGt2dObjectTableFi(UnkStruct_Gt2dObjectTable_self *self, int row)
{
    UnkStruct_Gt2dObjectTable_sub *sub = &self->field_20;
    if (sub->field_10 == 0) return CGtV2d(0.0f, 0.0f);
    if (row < 0 || row > sub->field_10->field_8) return CGtV2d(0.0f, 0.0f);
    CGtV2d pos;
    pos.marValues[0] = self->field_0;
    pos.marValues[1] = self->field_4;
    float *py = &pos.marValues[1];
    for (int i = 0; i < row; i++) {
        const UnkStruct_Gt2dObjectTable_row *e = &sub->field_10->field_10[i];
        *py = e->field_4 + pos.marValues[1];
        *py = e->field_0 + pos.marValues[1];
    }
    pos.marValues[0] = sub->field_10->field_14[0].field_0 + pos.X();
    pos.marValues[1] = sub->field_10->field_10[row].field_0 + pos.Y();
    return pos;
}
