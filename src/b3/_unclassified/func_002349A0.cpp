// Hand-written; the lifter refused it (reset: 8 rows stride 0x90, 3 sub-blocks via func_0022D9F0, returns 1).

struct UnkStruct_002349A0_vt {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
};
struct UnkStruct_0022D9F0_blk {
    unsigned char pad_0[0x10];
};
struct UnkStruct_002349A0_row {
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
    float field_2C;
    int field_30;
    unsigned char field_34;
    unsigned char pad_35[0x1F];
    float field_54;
    unsigned char field_58;
    unsigned char field_59;
    unsigned char field_5A;
    unsigned char field_5B;
    unsigned char field_5C;
    unsigned char field_5D;
    unsigned char field_5E;
    unsigned char pad_5F;
    UnkStruct_0022D9F0_blk field_60;
    UnkStruct_0022D9F0_blk field_70;
    UnkStruct_0022D9F0_blk field_80;
};
struct UnkStruct_002349A0 {
    UnkStruct_002349A0_row field_0[8];
    unsigned char pad_480[0x524 - 0x480];
    UnkStruct_002349A0_vt *field_524;
    int field_528;
    unsigned char pad_52C[0x580 - 0x52C];
    float field_580;
    int field_584;
    int field_588;
    int field_58C;
};
extern "C" void func_0022D9F0(void *);

// 0x002349A0
extern "C" int func_002349A0(UnkStruct_002349A0 *self)
{
    if (self->field_524 != 0) {
        self->field_524->vfunc_24();
    }
    self->field_524 = 0;
    self->field_528 = 0;
    self->field_580 = -1.0f;
    self->field_58C = 0;
    for (int i = 0; i < 8; i++) {
        UnkStruct_002349A0_row *r = &self->field_0[i];
        r->field_0 = 4;
        r->field_4 = -1;
        r->field_8 = -1;
        r->field_C = -1;
        r->field_10 = -1;
        r->field_14 = -1;
        r->field_18 = -1;
        r->field_1C = 0;
        r->field_20 = 0;
        r->field_24 = -1;
        r->field_28 = -1;
        r->field_2C = -1.0f;
        r->field_30 = 0;
        r->field_34 = 0;
        r->field_54 = -1.0f;
        r->field_58 = 0;
        r->field_59 = 0;
        r->field_5A = 0;
        r->field_5B = 0;
        r->field_5C = 0;
        r->field_5D = 0;
        r->field_5E = 0;
        func_0022D9F0(&r->field_60);
        func_0022D9F0(&r->field_70);
        func_0022D9F0(&r->field_80);
    }
    self->field_584 = 0;
    self->field_588 = 2;
    return 1;
}
