// Hand-written; the lifter refused it (a146: [L] DNAT UpdateStreamPVS (low). GetUnit inlines (0x154 hi / 0x17C lo tables); pabsw/pextlw abs; *(const int*)& puns reload field_8/C; bool found/far; D_0064C994 padded 0x10 (lui)).

struct UnkStruct_1D50_cell { signed char field_0; signed char field_1; unsigned char pad_2[0xA7]; };
struct UnkStruct_1D50_hi {
    unsigned char pad_0[4];
    int field_4;
    unsigned char pad_8[0x112];
    UnkStruct_1D50_cell cells[17];
};
struct UnkStruct_1D50_lo {
    unsigned char pad_0[0x50];
    short field_50;
    unsigned char pad_52[0x46];
    unsigned char field_98[4];
};
struct UnkStruct_1D50_self {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x10];
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    unsigned char pad_30[0x14];
    unsigned char field_44;
    unsigned char pad_45[3];
    int field_48;
    unsigned char pad_4C[0x30];
    UnkStruct_1D50_lo *field_7C[17];
    UnkStruct_1D50_lo *field_C0_pad;
    UnkStruct_1D50_lo *field_C4[17];
    UnkStruct_1D50_lo *field_108_pad;
    void *field_10C[17];
    unsigned char pad_150[4];
    UnkStruct_1D50_hi *field_154[10];
    UnkStruct_1D50_lo *field_17C[10];
    unsigned char pad_1A4[0x20];
    UnkStruct_1D50_hi *field_1C4;
    UnkStruct_1D50_hi *field_1C8;
};
struct UnkStruct_1D50_D { short pad_0[0x2A]; short field_54; unsigned char pad_56[0xA]; };
struct UnkStruct_D_0064C994_1D50 { UnkStruct_1D50_D *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064C994_1D50 D_0064C994;
extern "C" void *memset(void *, int, unsigned int);
static inline int func_00301D50_pabsw(int x)
{
    int r;
    asm("pabsw %0,%1" : "=r"(r) : "r"(x));
    return r;
}
static inline long func_00301D50_pextlw0(int x)
{
    long r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(x));
    return r;
}

static inline UnkStruct_1D50_hi *func_00301D50_inl1(UnkStruct_1D50_self *self, int idx)
{
    UnkStruct_1D50_hi *u;
    if (self->field_20 != self->field_28 && idx == self->field_20 % self->field_8) {
        u = 0;
    } else if (idx >= 0 && idx < self->field_8) {
        UnkStruct_1D50_hi *x = self->field_154[idx];
        if (*(int *)((unsigned int)x | 0x20000000) == 2) u = x;
        else u = 0;
    } else {
        u = 0;
    }
    return u;
}
static inline UnkStruct_1D50_lo *func_00301D50_inl2(UnkStruct_1D50_self *self, int idx)
{
    UnkStruct_1D50_lo *u;
    if (self->field_24 != self->field_2C && idx == self->field_24 % self->field_C) {
        u = 0;
    } else if (idx >= 0 && idx < self->field_C) {
        UnkStruct_1D50_lo *x = self->field_17C[idx];
        if (*(int *)((unsigned int)x | 0x20000000) == 2) u = x;
        else u = 0;
    } else {
        u = 0;
    }
    return u;
}
static inline UnkStruct_1D50_hi *func_00301D50_inl1b(UnkStruct_1D50_self *self, int idx)
{
    UnkStruct_1D50_hi *u;
    if (self->field_20 != self->field_28 && idx == self->field_20 % self->field_8) {
        u = 0;
    } else if (idx >= 0 && idx < *(const int *)&self->field_8) {
        UnkStruct_1D50_hi *x = self->field_154[idx];
        if (*(int *)((unsigned int)x | 0x20000000) == 2) u = x;
        else u = 0;
    } else {
        u = 0;
    }
    return u;
}
static inline UnkStruct_1D50_lo *func_00301D50_inl2b(UnkStruct_1D50_self *self, int idx)
{
    UnkStruct_1D50_lo *u;
    if (self->field_24 != self->field_2C && idx == self->field_24 % self->field_C) {
        u = 0;
    } else if (idx >= 0 && idx < *(const int *)&self->field_C) {
        UnkStruct_1D50_lo *x = self->field_17C[idx];
        if (*(int *)((unsigned int)x | 0x20000000) == 2) u = x;
        else u = 0;
    } else {
        u = 0;
    }
    return u;
}
// 0x00301D50
extern "C" void func_00301D50(UnkStruct_1D50_self *self)
{
    if (self->field_44 == 0) return;
    self->field_1C4 = func_00301D50_inl1(self, self->field_0);
    self->field_1C8 = func_00301D50_inl1(self, self->field_48);
    UnkStruct_1D50_hi *p1 = self->field_1C4;
    int W = D_0064C994.field_0->field_54;
    UnkStruct_1D50_hi *p2 = self->field_1C8;
    int a = p1->field_4;
    int b = p2->field_4;
    int s0 = 0;
    if (!(b < a)) {
        if (!(b > a + 4)) s0 = b - a;
    } else {
        if (b < a) {
            b += W;
            if (!(b > a + 4)) s0 = b - a;
        }
    }
    memset(self->field_7C, 0, 0x48);
    memset(self->field_C4, 0, 0x48);
    memset(self->field_10C, 0, 0x48);
    int i = 0;
    do {
        signed char x = self->field_1C4->cells[i].field_0;
        int j;
        bool found = false;
        int t4 = x - s0;
        for (j = 0; j < 17; j++) {
            if (t4 == *((signed char *)self->field_1C8 + j * 0xA9 + 0x11A) && *((signed char *)self->field_1C8 + j * 0xA9 + 0x11B) == 1) {
                found = true;
                break;
            }
        }
        if (found) {
            UnkStruct_1D50_hi *h = 0;
            bool far;
            if (func_00301D50_pextlw0(func_00301D50_pabsw(x)) > 4) {
                far = true;
            } else {
                int idx = self->field_0 + x;
                if (idx < 0) idx += self->field_8;
                h = func_00301D50_inl1b(self, idx % self->field_8);
                far = false;
            }
            int idy = self->field_4 + x;
            if (idy < 0) idy += self->field_C;
            UnkStruct_1D50_lo *l = func_00301D50_inl2b(self, idy % self->field_C);
            if (far) {
                if (l->field_50 > 0) self->field_7C[i] = l;
            } else {
                self->field_7C[i] = (UnkStruct_1D50_lo *)h;
            }
            if (l->field_50 > 0) self->field_C4[i] = l;
            self->field_10C[i] = l->field_98;
        }
        i++;
    } while (i < 17);
}
