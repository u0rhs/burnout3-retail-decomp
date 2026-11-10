// NONMATCHING: func_0023E8A0 -- retail 178 / ours 172 instructions, 103 in changed runs
// a120: structure right (find row by id, swap-remove rows older by u16 wrap compare, refind); 6 instrs short, regs shifted (found/i vs a3/t0, hoisted bool 1 in a2 not reproduced), row 0x240 copy skips 2-byte gap at +0xE (aligned(4) attr on field_10 gives member copy)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_0023E8A0_s3 { short a; short b; short c; };
struct UnkStruct_0023E8A0_b3 { unsigned char a; unsigned char b; unsigned char c; };
struct UnkStruct_0023E8A0_row {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    signed char field_3;
    int field_4;
    int field_8;
    unsigned short field_C;
    unsigned char field_10 __attribute__((aligned(4)));
    unsigned char field_11;
    unsigned char field_12;
    unsigned char field_13;
    UnkStruct_0023E8A0_s3 field_14;
    UnkStruct_0023E8A0_s3 field_1A;
    UnkStruct_0023E8A0_s3 field_20;
    unsigned short field_26;
    UnkStruct_0023E8A0_b3 field_28;
    unsigned char field_2B;
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char field_2E;
    unsigned char field_2F;
    short field_30[264];
};
struct UnkStruct_0023E8A0 {
    unsigned char pad_0[0x18DC];
    UnkStruct_0023E8A0_row field_18DC[16];
    int field_3CDC;
};

static inline bool func_0023E8A0_inl1(unsigned short a, unsigned short b)
{
    if (a < 0x5555) {
        if (b > 0xAAAA) {
            return true;
        }
    }
    if (b < 0x5555) {
        if (a > 0xAAAA) {
            return false;
        }
    }
    if (b < a) {
        return true;
    }
    return false;
}

// 0x0023E8A0
extern "C" UnkStruct_0023E8A0_row * func_0023E8A0(UnkStruct_0023E8A0 * self, int p0)
{
    int i;
    unsigned short id = p0;
    UnkStruct_0023E8A0_row * found = 0;
    for (i = 0; i < self->field_3CDC; i++) {
        if (id == self->field_18DC[i].field_26) {
            found = &self->field_18DC[i];
            break;
        }
    }
    if (found == 0) return 0;
    unsigned short t0 = found->field_26;
    for (int k = 0; k < self->field_3CDC; k++) {
        if (func_0023E8A0_inl1(t0, self->field_18DC[k].field_26)) {
            int last = self->field_3CDC - 1;
            int idx = &self->field_18DC[k] - self->field_18DC;
            if (idx != last) {
                self->field_18DC[idx] = self->field_18DC[last];
            }
            self->field_3CDC--;
            k--;
        }
    }
    for (int j = 0; j < self->field_3CDC; j++) {
        if (t0 == self->field_18DC[j].field_26) {
            return &self->field_18DC[j];
        }
    }
    return 0;
}
