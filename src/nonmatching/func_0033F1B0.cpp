// NONMATCHING: func_0033F1B0 -- retail 42 / ours 42 instructions, 6 in changed runs
// near10: 42/42 (was 43/42), frame 0x40 right: the locals are two header CGtV4d(float x4) colours (a = 1,1,1,1 at sp+0x10, b = 1,1,1,0.5 at sp+0). Left: retail loads a (lq a3) then b in the beqz delay slot, ours b then a; g/pointer locals, assignment forms, u_long128 copies, const tried (declaring b first swaps the slots)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_0033F1B0 -- retail 42 / ours 43 instructions, 6 in changed runs
// logic complete; 43 vs 42 instrs: address-of field_10 for the lq makes 'addiu a3,sp,16' + store via a3 and lq order swapped (retail lq a3,0x10(sp) before gp load, lq a2 in beqz delay slot). Tried union/array pun/float fields
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_0033F1B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_0033F1B0;
struct UnkStruct_0033F1B0_0;
struct UnkStruct_0033F1B0_3;
struct UnkStruct_0033F1B0_4;
struct UnkStruct_D_004E2DB0;

struct UnkStruct_0033F1B0_0 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    unsigned char pad_20[0x20];
};

struct UnkStruct_D_004E2DB0 {
    int field_0;
};

struct UnkStruct_0033F1B0_3 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_0033F1B0_4 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_0033F1B0 {
    unsigned char pad_0[0x34];
    UnkStruct_0033F1B0_3 * field_34;
    UnkStruct_0033F1B0_4 * field_38;
};

extern UnkStruct_D_004E2DB0 D_004E2DB0;

// 0x0033F1B0
extern "C" void func_0033F1B0(UnkStruct_0033F1B0 * self, int p0)
{
    CGtV4d a(1.0f, 1.0f, 1.0f, 1.0f);
    CGtV4d b(1.0f, 1.0f, 1.0f, 0.5f);
    if (D_004E2DB0.field_0 != 0) {
        switch (p0) {
        case 0:
            self->field_34->field_10 = a.mData;
            self->field_38->field_10 = a.mData;
            break;
        case 1:
            self->field_34->field_10 = a.mData;
            self->field_38->field_10 = b.mData;
            break;
        case 2:
            self->field_34->field_10 = b.mData;
            self->field_38->field_10 = a.mData;
            break;
        default:
            break;
        }
    }
}

