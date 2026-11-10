// Hand-written; the lifter refused it (a249: hand-written from asm (switch as if/else chain, loops, 4-param func_00371670 with ld a2)).

// func_0030CF90 -- [G] hand-written from asm; types are instruction widths.
struct UnkStruct_0030CF90_p {
    unsigned char pad_0[0x8];
    unsigned long field_8[1];
    unsigned char pad_10[0x60];
    int field_70[1];
    unsigned char pad_74[0x2C];
    unsigned long field_A0_dummy;
};
struct UnkStruct_0030CF90_p2 {
    unsigned char pad_0[0x8];
    unsigned long field_8[2];
    unsigned char pad_18[0x58];
    int field_70[2];
    int field_78[2];
    unsigned char pad_80[0x20];
    int field_A0;
    int field_A4;
};
struct UnkStruct_0030CF90_self {
    unsigned char pad_0[4];
    int field_4;
    unsigned char pad_8[4];
    int field_C;
    unsigned char pad_10[0x14];
    int field_24;
    unsigned char pad_28[0x58];
    unsigned long field_80[8];
    int field_C0[8];
};
struct UnkStruct_D_01EA4070 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E32AE0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E32B08 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01EA4070 D_01EA4070;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern "C" int func_00371670(void *, int, unsigned long, int);
extern "C" int func_002366D0(void *, int);

// 0x0030CF90
extern "C" void func_0030CF90(UnkStruct_0030CF90_self *self, UnkStruct_0030CF90_p2 *p)
{
    int t = self->field_4;
    if (t == 4) {
        return;
    }
    if (t == 2 && self->field_C == 4) {
        int i = 0;
        while (i < self->field_24) {
            func_00371670(&D_01EA4070, i, self->field_80[i], self->field_C0[i]);
            i++;
        }
    } else if (t == 3) {
        int i, n;
        bool flag = false;
        n = D_01E32B08.field_0;
        i = 0;
        while (i < n) {
            if (func_002366D0(&D_01E32AE0, i) == 0) {
                flag = true;
                func_00371670(&D_01EA4070, i, self->field_80[0], self->field_C0[0]);
            } else if (flag) {
                func_00371670(&D_01EA4070, i, self->field_80[i], self->field_C0[i]);
            } else {
                func_00371670(&D_01EA4070, i, self->field_80[i + 1], self->field_C0[i + 1]);
            }
            i++;
        }
    } else {
        int i = 0;
        while (i < p->field_A0) {
            func_00371670(&D_01EA4070, i, p->field_8[i], p->field_70[i]);
            i++;
        }
        i = 0;
        while (i < p->field_A4) {
            func_00371670(&D_01EA4070, i + p->field_A0, p->field_8[i + 2], p->field_78[i]);
            i++;
        }
    }
}
