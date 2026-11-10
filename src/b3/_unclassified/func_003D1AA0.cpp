// Hand-written; the lifter refused it (a133: record table Update; operand order b>a gives slt at; int pun for float compare).

enum UnkEnum_003D17D0 { E0 = 0, E1 = 1, E2 = 2, E3 = 3 };
struct UnkStruct_003D17D0_row {
    unsigned short field_0[9];
    unsigned char field_12;
    unsigned char field_13;
    signed char field_14;
    unsigned char field_15;
    float field_18;
    unsigned short field_1C[9];
    unsigned char field_2E;
    unsigned char field_2F;
};
struct UnkStruct_003D17D0_tbl { UnkStruct_003D17D0_row field_0[5]; };

extern "C" void func_003D2630(void *, unsigned int);

static inline UnkEnum_003D17D0 func_003D1AA0_inl1(int a, int b)
{
    UnkEnum_003D17D0 r;
    if (b > a) r = E3;
    else if (a > b) r = E0;
    else r = E1;
    return r;
}
// 0x003D1AA0
extern "C" void func_003D1AA0(UnkStruct_003D17D0_tbl *self, int p0, unsigned int p1, int p2)
{
    UnkStruct_003D17D0_row *found = 0;
    unsigned int j = 0;
    for (; j < 5; j++) {
        UnkStruct_003D17D0_row *row = &self->field_0[j];
        if (p2 == func_003D1AA0_inl1(*(int *)&row->field_18, p0)) { found = row; break; }
    }
    if (found == 0) return;
    for (unsigned int m = 4; j < m; m--) {
        self->field_0[m] = self->field_0[m - 1];
    }
    if (p2 == func_003D1AA0_inl1(*(int *)&found->field_18, p0)) {
        func_003D2630(found, p1);
        *(int *)&found->field_18 = p0;
    }
}
