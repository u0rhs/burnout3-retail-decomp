// Hand-written; the lifter refused it (int return of func_00465320's result (dead r==0 guard) + scoped opt_propagation off [G], do-while pair copy).

// [L] D_004B12B0 is the 26-byte string "Copyright Electronic Arts" (Ghidra string at 0x4B12B0), copied to the stack
// as 13 byte pairs.
// [G] r: retail keeps the dead `r == 0` guard (v0 = 0, then the result of func_00465320 is returned in v0).
struct UnkStruct_00465960_src {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
};
struct UnkStruct_00465960_g {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    unsigned char pad_48[0x8C];
    int field_D4;
    unsigned char pad_D8[4];
    int field_DC;
    unsigned char pad_E0[0x10];
    int field_F0;
    unsigned char pad_F4[0x14];
    int field_108;
    unsigned char pad_10C[0x30];
    int field_13C;
    int field_140;
    int field_144;
    unsigned char pad_148[4];
    int field_14C;
};
struct UnkStruct_D_004E2FC4_d { UnkStruct_00465960_g *field_0; };
struct UnkStruct_D_004E2FC0_d { unsigned char field_0; };
struct UnkStruct_004B12B0_e { signed char a; signed char b; };
struct UnkStruct_004B12B0 { UnkStruct_004B12B0_e e[13]; };
struct UnkStruct_00465960_arg {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
};
struct UnkStruct_00465960_self {
    UnkStruct_00465960_src *field_0;
    int field_4;
};
extern UnkStruct_D_004E2FC4_d D_004E2FC4;
extern UnkStruct_D_004E2FC0_d D_004E2FC0;
extern UnkStruct_004B12B0 D_004B12B0;
extern "C" void * memset(void *, int, unsigned int);
extern "C" void * func_00360AE0(int, int, int);
extern "C" void * func_00469540();
extern "C" int func_004649F0(void *);
extern "C" int func_00465320(int);

// N182: opt_propagation off [G] scoped to this function (keeps the r == 0 guard as retail).
#pragma push
#pragma opt_propagation off

// 0x00465960
extern "C" int func_00465960(const UnkStruct_00465960_self * self)
{
    UnkStruct_004B12B0 tbl;
    UnkStruct_00465960_arg arg;
    D_004E2FC0.field_0 = 1;
    D_004E2FC4.field_0 = (UnkStruct_00465960_g *)func_00360AE0(self->field_4, 0x150, 4);
    memset(D_004E2FC4.field_0, 0, 0x150);
    D_004E2FC4.field_0->field_144 = self->field_4;
    *(UnkStruct_00465960_src *)D_004E2FC4.field_0 = *self->field_0;
    D_004E2FC4.field_0->field_D4 = 4;
    D_004E2FC4.field_0->field_108 = 4;
    D_004E2FC4.field_0->field_DC = 10;
    D_004E2FC4.field_0->field_F0 = 5;
    D_004E2FC4.field_0->field_14C = 0;
    D_004E2FC4.field_0->field_13C = 0;
    D_004E2FC4.field_0->field_140 = -1;
    int r = 0;
    { const UnkStruct_004B12B0_e *q = D_004B12B0.e; UnkStruct_004B12B0_e *d = tbl.e; int i = 13; do { i--; d->a = q->a; d->b = q->b; d++; q++; } while (i > 0); }
    if (r == 0) {
        arg.field_0 = 2;
        arg.field_8 = (int)D_004E2FC4.field_0;
        arg.field_C = (int)&tbl;
        arg.field_10 = 0x1A;
        arg.field_4 = (int)&D_004E2FC4.field_0->field_13C;
        arg.field_14 = (int)func_00469540();
        arg.field_18 = D_004E2FC4.field_0->field_144;
        r = func_00465320(func_004649F0(&arg));
    }
    return r;
}


#pragma pop
