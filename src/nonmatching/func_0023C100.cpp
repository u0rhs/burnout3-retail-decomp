// NONMATCHING: func_0023C100 -- retail 263 / ours 261 instructions, 24 in changed runs
// near25: row copy as '*(row *)((char *)self + idx * 0x240 + 0x18DC) = *(row *)(... last ...)' gives retail's unfolded addiu 0x18DC / +0x30 bases (28 -> 24). Left (261 vs 263): retail lays the head's shared 'b epi; ld ra' relay, inl1's out-of-line 0xAAAB piece and the callit block between the copy block and setlast; ours puts them at the function end (if/else, goto and || forms of the row block tried)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a143: 259/263 instrs, ~28 in changed runs. Head, row-remove logic, tail all right; left: (1) block layout - retail puts a shared 'b epilogue; ld ra' block (3C8) + inl1 out-of-line pieces + D0F0 call block between the row-copy and the setlast block, ours puts them at function end; (2) row copy loop base: retail addiu a1,v0,0x18DC then a1+0x30 for the short[264] pair loop, ours folds 0x190C
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.


struct UnkStruct_0023C100_s3 { short a; short b; short c; };
struct UnkStruct_0023C100_b3 { unsigned char a; unsigned char b; unsigned char c; };
struct UnkStruct_0023C100_row {
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
    UnkStruct_0023C100_s3 field_14;
    UnkStruct_0023C100_s3 field_1A;
    UnkStruct_0023C100_s3 field_20;
    unsigned short field_26;
    UnkStruct_0023C100_b3 field_28;
    unsigned char field_2B;
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char field_2E;
    unsigned char field_2F;
    short field_30[264];
};
struct UnkStruct_0023C100_w { unsigned char pad[0x18DC]; UnkStruct_0023C100_row r; };
struct UnkStruct_0023C100_p {
    unsigned char pad_0[0x178C];
    int field_178C;
    unsigned char pad_1790[0x158];
    unsigned char field_18E8;
};
struct UnkStruct_0023C100 {
    unsigned char pad_0[0x5C0];
    unsigned char field_5C0;
    unsigned char field_5C1;
    unsigned char pad_5C2[6];
    int field_5C8;
    int field_5CC;
    unsigned char pad_5D0[0x10C];
    UnkStruct_0023C100_p * field_6DC;
    void * field_6E0;
    unsigned char pad_6E4[0x11F8];
    UnkStruct_0023C100_row field_18DC[16];
    int field_3CDC;
    unsigned char pad_3CE0[0x1210];
    int field_4EF0;
    unsigned short field_4EF4;
    unsigned char pad_4EF6[2];
    int field_4EF8;
    unsigned char field_4EFC;
};
struct UnkStruct_D_004E2A14 { unsigned short field_0; };
struct UnkStruct_D_004E1974 { int field_0; };
struct UnkStruct_D_01E654A0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004E2A14 D_004E2A14;
extern UnkStruct_D_004E1974 D_004E1974;
extern UnkStruct_D_01E654A0 D_01E654A0;
extern "C" void func_002303B0(void *, unsigned short);
extern "C" void func_0023F300(void *);
extern "C" void func_0023EDD0(void *, unsigned short);
extern "C" UnkStruct_0023C100_row * func_0023E8A0(void *, unsigned short);
extern "C" void func_0023D0F0(void *, void *);
extern "C" void func_0023C520(void *);

static inline bool func_0023C100_inl1(unsigned short a, unsigned short b)
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

static inline unsigned short func_0023C100_inl2(unsigned short a, unsigned short b)
{
    if (b < 0x5555) {
        if (a > 0xAAAA) {
            return b + (0xFFFF - a);
        }
    }
    return b - a;
}

static inline unsigned short func_0023C100_inl3()
{
    int v = D_004E2A14.field_0;
    if (v == 0xFFFF) v = 0;
    return v;
}

// 0x0023C100
extern "C" void func_0023C100(UnkStruct_0023C100 * self)
{
    func_002303B0(self, func_0023C100_inl3());
    func_0023F300(self);
    if (self->field_5C0 == 0) return;
    if (self->field_5C1 != 0) return;
    if (self->field_6E0 == 0) return;
    int cur = D_01E654A0.field_0;
    if (cur == -1) return;
    int tt = (unsigned short)(func_0023C100_inl3() - cur);
    if (tt == 0xFFFF) tt = 0;
    unsigned short t = tt;
    unsigned short u = t - self->field_5CC - D_004E1974.field_0;
    if (u == 0xFFFF) u = 0;
    func_0023EDD0(self, t);
    UnkStruct_0023C100_row * row = func_0023E8A0(self, u);
    if (row != 0) {
        if (self->field_5C8 == -1) goto callit;
        if (func_0023C100_inl1(row->field_26, self->field_5C8)) goto callit;
      back:
        int idx = row - self->field_18DC;
        int last = self->field_3CDC - 1;
        if (idx == last) goto setlast;
        *(UnkStruct_0023C100_row *)((char *)self + idx * 0x240 + 0x18DC) = *(UnkStruct_0023C100_row *)((char *)self + last * 0x240 + 0x18DC);
        self->field_3CDC = self->field_3CDC - 1;
        goto after;
      callit:
        func_0023D0F0(self, row);
        goto back;
      setlast:
        self->field_3CDC = last;
    }
  after:
    func_0023C520(self);
    unsigned short a1 = self->field_4EF4;
    if (a1 == 0xFFFF) return;
    unsigned short a0 = func_0023C100_inl3();
    unsigned short d = func_0023C100_inl2(a1, a0);
    if (d > 0xB4) {
        if (self->field_4EFC == 0) {
            self->field_4EF8 = 0;
            self->field_4EFC = 1;
            self->field_4EF0 = self->field_6DC->field_178C;
            self->field_6DC->field_178C = 2;
            return;
        }
        self->field_4EF8 = self->field_4EF8 + 1;
        if (self->field_4EF8 > 0x1E) {
            self->field_6DC->field_18E8 = 0;
        }
        if (self->field_4EF8 > 0x3C) {
            self->field_4EF8 = 0;
            return;
        }
    } else {
        if (self->field_4EFC != 0) {
            self->field_4EFC = 0;
            self->field_6DC->field_178C = self->field_4EF0;
            return;
        }
    }
}
