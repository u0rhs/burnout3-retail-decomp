// NONMATCHING: func_00423720 -- retail 179 / ours 179 instructions, 39 in changed runs
// fresh4: logic/layout exact; 39 off = register colouring only: retail keeps n (2/1 movz) in s0 for both loops, ours in t9, shifting t9..t5 and moving the byte pointer to s3 (sreg run 2 rounds, decl orders, types inert)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00423720 -- hand-written from scratch (the lifter refused it: movz). Unnamed, so a placeholder with C linkage.
// Layout and types are [G] (instruction widths). Per-player records of D_00522660 (0x27D0 stride at 0x12A980) reached
// through byte-offset views (retail adds the large offsets with lui/ori/addu).

struct UnkStruct_00423720 {
    unsigned char pad_0[4];
    int field_4[3][29];
    unsigned char pad_160[0x14];
    unsigned char field_174;
    unsigned char pad_175[3];
    unsigned char field_178;
};
struct UnkStruct_00423720_pl { unsigned char pad_0[0x12C6FC]; signed char field_12C6FC; };
struct UnkStruct_00423720_b { unsigned char pad_0[0x12ACD2]; unsigned char field_12ACD2; unsigned char pad_12ACD3[3]; unsigned char field_12ACD6; };
struct UnkStruct_00423720_c { unsigned char pad_0[0x12AC18]; int field_12AC18[5]; };
extern unsigned char D_00522660[];

extern "C" void func_00423720(UnkStruct_00423720 *self);

// 0x00423720
void func_00423720(UnkStruct_00423720 *self)
{
    int i;
    int k;
    int n = self->field_178 ? 2 : 1;
    unsigned char start = self->field_174;
    unsigned char mx = 0;
    for (i = 0; i < n; i++) {
        signed char idx = ((UnkStruct_00423720_pl *)(D_00522660 + i * 0x27D0))->field_12C6FC;
        unsigned char v = ((UnkStruct_00423720_b *)(D_00522660 + idx))->field_12ACD2;
        if (mx < v) {
            mx = v;
        }
    }
    unsigned char total = start + mx;
    for (k = 0; k < mx; k++) {
        self->field_4[0][self->field_174] = 3;
        self->field_174++;
    }
    for (k = 0; k < mx; k++) {
        if (self->field_178) {
            self->field_4[0][self->field_174] = 5;
        } else {
            self->field_4[0][self->field_174] = 4;
        }
        self->field_174++;
    }
    for (i = 0; i < n; i++) {
        signed char idx = ((UnkStruct_00423720_pl *)(D_00522660 + i * 0x27D0))->field_12C6FC;
        bool used = false;
        for (k = 0; k < mx; k++) {
            switch (((UnkStruct_00423720_c *)(D_00522660 + idx * 20))->field_12AC18[k]) {
            case 1:
                if (!used && ((UnkStruct_00423720_b *)(D_00522660 + idx))->field_12ACD6 != 0) {
                    self->field_4[i + 1][start + k] = 4;
                    self->field_4[i + 1][total + k] = 4;
                    used = true;
                } else {
                    self->field_4[i + 1][start + k] = 1;
                    self->field_4[i + 1][total + k] = 1;
                }
                break;
            case 2:
                self->field_4[i + 1][start + k] = 2;
                self->field_4[i + 1][total + k] = 2;
                break;
            case 3:
                self->field_4[i + 1][start + k] = 3;
                self->field_4[i + 1][total + k] = 3;
                break;
            case 9:
            default:
                self->field_4[i + 1][start + k] = 0;
                self->field_4[i + 1][total + k] = 0;
                break;
            }
        }
    }
}
