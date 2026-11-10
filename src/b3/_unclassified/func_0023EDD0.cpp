// Hand-written; the lifter refused it (a143: row-ring insert; goto fin shared 87E0 tail, goto copy/skip, row.field_0&1 test, inl1 u16 helper).

struct UnkStruct_0023EDD0_s3 { short a; short b; short c; };
struct UnkStruct_0023EDD0_b3 { unsigned char a; unsigned char b; unsigned char c; };
struct UnkStruct_0023EDD0_row {
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
    UnkStruct_0023EDD0_s3 field_14;
    UnkStruct_0023EDD0_s3 field_1A;
    UnkStruct_0023EDD0_s3 field_20;
    unsigned short field_26;
    UnkStruct_0023EDD0_b3 field_28;
    unsigned char field_2B;
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char field_2E;
    unsigned char field_2F;
    short field_30[264];
};
struct UnkStruct_0023EDD0_w { unsigned char pad[0x18DC]; UnkStruct_0023EDD0_row r; };
struct UnkStruct_0023EDD0_o { unsigned char pad_0[0x210]; unsigned char field_210; };
struct UnkStruct_0023EDD0 {
    unsigned char pad_0[0x5C8];
    int field_5C8;
    int field_5CC;
    unsigned char pad_5D0[0x10C];
    void * field_6DC;
    UnkStruct_0023EDD0_o * field_6E0;
    unsigned char pad_6E4[0x240];
    UnkStruct_0023EDD0_row field_924;
    unsigned char pad_B64[0xD78];
    int pad_18DC_[0x240 * 16 / 4];
    int field_3CDC;
    unsigned char pad_3CE0[0x120C];
    float field_4EEC;
    unsigned char pad_4EF0[4];
    unsigned short field_4EF4;
};
struct UnkStruct_D_004E2A14 { unsigned short field_0; };
struct UnkStruct_D_004E1974 { int field_0; };
struct UnkStruct_D_004F50A0 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004E2A14 D_004E2A14;
extern UnkStruct_D_004E1974 D_004E1974;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern "C" void func_0023F1B0(void *, unsigned short, unsigned short);
extern "C" void func_001A87E0(void *);
extern "C" bool func_001A87D0(void *);
extern "C" void func_0023E3E0(void *, unsigned short, void *);

static inline bool func_0023EDD0_inl1(unsigned short a, unsigned short b)
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

// 0x0023EDD0
extern "C" void func_0023EDD0(UnkStruct_0023EDD0 * self, unsigned short ts)
{
    int x = ts - self->field_5CC - D_004E1974.field_0;
    unsigned short s0 = x;
    if (s0 == 0xFFFF) s0 = 0;
    if ((self->field_924.field_0 & 1) != 1) return;
    unsigned short g = D_004E2A14.field_0;
    if (g == 0xFFFF) g = 0;
    self->field_4EF4 = g;
    self->field_4EEC = D_004F50A0.field_0;
    func_0023F1B0(self, self->field_924.field_26, ts);
    if (self->field_5C8 != -1) {
        if (!func_0023EDD0_inl1(self->field_924.field_26, self->field_5C8)) {
          fin:
            func_001A87E0(&self->field_924);
            return;
        }
    }
    if (!func_0023EDD0_inl1(s0, self->field_924.field_26)) {
        if (self->field_6E0->field_210 != 0) {
            if (func_001A87D0(&self->field_924)) {
                if (self->field_5C8 == -1) goto copy;
                if (!func_0023EDD0_inl1(self->field_924.field_26, self->field_5C8)) goto skip;
              copy:
                ((UnkStruct_0023EDD0_w *)((char *)self + self->field_3CDC * 0x240))->r = self->field_924;
                self->field_3CDC = self->field_3CDC + 1;
                if (self->field_3CDC >= 0x10) self->field_3CDC = 0;
              skip:;
            }
        }
    }
    if (self->field_6E0->field_210 != 0) {
        if (func_001A87D0(&self->field_924)) goto fin;
    }
    func_0023E3E0(self, ts, &self->field_924);
    goto fin;
}
