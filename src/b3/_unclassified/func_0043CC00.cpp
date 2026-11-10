// Hand-written; the lifter refused it (2x5 slot loop).

// Hand-written (a108).
struct UnkStruct_D_01E903E0_a { unsigned char pad_0[0x10]; };
struct UnkStruct_0043CC00 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x66];
    void *field_70;
    void *field_74[2];
    int field_7C[2][5];
};
extern UnkStruct_D_01E903E0_a D_01E903E0;
extern "C" int func_00458960(void *);
extern "C" void func_00458970(void *, void *, int);
// 0x0043CC00
extern "C" void func_0043CC00(UnkStruct_0043CC00 * self)
{
    int i = 0;
    int j;
    UnkStruct_D_01E903E0_a *g = &D_01E903E0;
    int h = self->field_8;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++) {
            int *p = &self->field_7C[i][j];
            if (func_00458960(p) != 0) {
                func_00458970(p, g, h);
            }
        }
    }
}
