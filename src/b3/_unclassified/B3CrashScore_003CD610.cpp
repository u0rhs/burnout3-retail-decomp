// CB3CrashScore::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3CrashScore.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a132: CB3CrashScore::Prepare as extern C like GetTotalPickupScore sibling; seed stores 14 before 10).

struct UnkStruct_Prep_car {
    virtual int vfunc_8();
    virtual int vfunc_C();
    virtual int vfunc_10();
    virtual int vfunc_14();
    virtual int vfunc_18();
    virtual int vfunc_1C();
    virtual int vfunc_20();
    virtual int vfunc_24();
    virtual int vfunc_28();
    virtual int vfunc_2C();
    virtual int vfunc_30();
    virtual int vfunc_34();
    virtual int vfunc_38();
    virtual int vfunc_3C();
    virtual int vfunc_40();
    virtual int vfunc_44();
    virtual int vfunc_48();
    virtual int vfunc_4C();
    virtual int vfunc_50();
    virtual int vfunc_54();
    virtual int vfunc_58();
    virtual int vfunc_5C();
    virtual int vfunc_60();
    virtual int vfunc_64();
    virtual int vfunc_68();
    virtual int vfunc_6C();
    virtual int vfunc_70();
    virtual int vfunc_74();
    virtual int vfunc_78();
    virtual int vfunc_7C();
    virtual int vfunc_80();
    virtual int vfunc_84();
    virtual int vfunc_88();
    virtual int vfunc_8C();
    virtual int vfunc_90();
    virtual int vfunc_94();
    virtual int vfunc_98();
    virtual int vfunc_9C();
    virtual int vfunc_A0();
    virtual int vfunc_A4();
    virtual int vfunc_A8();
    virtual int vfunc_AC();
    virtual int vfunc_B0();
};
struct UnkStruct_Prep_b { unsigned char pad_0[0x1B4]; UnkStruct_Prep_car *field_1B4; };
struct UnkStruct_D_0051BA88 { UnkStruct_Prep_b *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Prep_e { int field_0[5]; };
struct UnkStruct_Prep {
    unsigned char pad_0[4];
    int field_4;
    int field_8;
    unsigned char pad_C[4];
    unsigned int field_10;
    unsigned int field_14;
    int field_18[0x42];
    int field_120[0x42];
    float field_228[2][0x42];
    UnkStruct_Prep_e field_438[2];
    int field_460[2];
    int field_468[8];
    float field_488[8];
    unsigned char field_4A8;
    unsigned char field_4A9[2][3];
    unsigned char field_4AF;
    unsigned char field_4B0[0x42];
    unsigned char field_4F2[2];
    unsigned char field_4F4[2];
    unsigned char field_4F6[2];
    unsigned char field_4F8;
    unsigned char field_4F9;
    unsigned char field_4FA;
    unsigned char field_4FB;
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern "C" int Prepare__13CB3CrashScoreFv(UnkStruct_Prep *self)
{
    int i, j, k;
    self->field_14 = 0x02B9D6F8;
    self->field_10 = 0xFD462907;
    for (i = 0; i < 0x42; i++) {
        self->field_18[i] = 0;
        self->field_120[i] = 0;
        self->field_4B0[i] = 0;
    }
    for (j = 0; j < 2; j++) {
        for (k = 0; k < 0x42; k++) {
            self->field_228[j][k] = 0.0f;
        }
        for (k = 0; k < 5; k++) {
            self->field_438[j].field_0[k] = 9;
        }
        for (k = 0; k < 3; k++) {
            self->field_4A9[j][k] = 0;
        }
        for (k = 0; k < 3; k++) {
            self->field_4A9[j][k] = 0;
        }
        self->field_460[j] = 0;
        self->field_4F2[j] = 0;
        self->field_4F4[j] = 0;
        self->field_4F6[j] = 0;
    }
    self->field_4 = 0;
    self->field_4AF = 0;
    self->field_4FB = 0;
    UnkStruct_Prep_car *car = D_0051BA88.field_0->field_1B4;
    if (car != 0) {
        self->field_4F8 = car->vfunc_B0();
        self->field_4F9 = D_0051BA88.field_0->field_1B4->vfunc_A8();
        self->field_4FA = D_0051BA88.field_0->field_1B4->vfunc_A4();
    } else {
        self->field_4F8 = 0;
        self->field_4F9 = 0;
        self->field_4FA = 0;
    }
    for (i = 0; i < 8; i++) {
        self->field_468[i] = 0;
        self->field_488[i] = -1.0f;
    }
    self->field_4A8 = 0;
    self->field_8 = -1;
    return 1;
}
