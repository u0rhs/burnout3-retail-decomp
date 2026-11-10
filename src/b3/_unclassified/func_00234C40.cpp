// Hand-written; the lifter refused it (reset: clear 3 sub-blocks via func_0022DA20 then re-init rows).

struct UnkStruct_0022D9F0_blk {
    unsigned char pad_0[0x10];
};
struct UnkStruct_00234C40_row {
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
struct UnkStruct_00234C40 {
    UnkStruct_00234C40_row field_0[8];
    int field_480;
    int field_484;
    int field_488;
    int field_48C;
    int field_490;
    unsigned char pad_494[0x524 - 0x494];
    int field_524;
    int field_528;
    unsigned char pad_52C[0x53C - 0x52C];
    int field_53C;
    int field_540;
    unsigned char pad_544[0x554 - 0x544];
    int field_554;
    int field_558;
    unsigned char pad_55C[0x56C - 0x55C];
    int field_56C;
    int field_570;
    int field_574;
    int field_578;
    int field_57C;
    float field_580;
    int field_584;
    int field_588;
    int field_58C;
};
extern "C" void func_0022D9F0(void *);
extern "C" void func_0022DA20(void *);

// 0x00234C40
extern "C" void func_00234C40(UnkStruct_00234C40 *self)
{
    self->field_524 = 0;
    self->field_528 = 0;
    self->field_480 = 4;
    self->field_484 = -1;
    self->field_488 = -1;
    self->field_48C = -1;
    self->field_490 = -1;
    self->field_574 = 0;
    self->field_578 = 0;
    self->field_53C = -1;
    self->field_540 = -1;
    self->field_554 = -1;
    self->field_558 = -1;
    self->field_56C = -1;
    self->field_570 = -1;
    self->field_57C = -1;
    self->field_580 = -1.0f;
    self->field_58C = 0;
    for (int i = 0; i < 8; i++) {
        UnkStruct_00234C40_row *r = &self->field_0[i];
        func_0022DA20(&r->field_60);
        func_0022DA20(&r->field_70);
        func_0022DA20(&r->field_80);
    }
    for (int i = 0; i < 8; i++) {
        UnkStruct_00234C40_row *r = &self->field_0[i];
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
}
