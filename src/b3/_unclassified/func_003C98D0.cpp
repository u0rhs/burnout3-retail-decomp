// Hand-written; the lifter refused it (a115: i<(n=field_4) keeps n for field_50; element pointer taken after the call).

struct UnkStruct_C98D0_e { int field_0; unsigned char field_4; unsigned char field_5; unsigned char pad_6[2]; };
struct UnkStruct_C98D0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    int field_10[10];
    unsigned char field_38[10];
    unsigned char field_42[10];
    unsigned char field_4C;
    unsigned char pad_4D;
    short field_4E;
    short field_50;
    unsigned char pad_52[2];
    UnkStruct_C98D0_e field_54[1];
};
struct UnkStruct_C98D0_s { unsigned char pad_0[0x10]; };
extern UnkStruct_C98D0_s D_004F50C0;
extern UnkStruct_C98D0_s D_0051BA44;
extern UnkStruct_C98D0_s D_01E89544;
extern UnkStruct_C98D0_s D_01E89518;
extern UnkStruct_C98D0_s D_01E88A80;
extern UnkStruct_C98D0_s D_01E89800;
extern UnkStruct_C98D0_s D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" signed char func_0022D1E0(void *);
extern "C" int func_00271A00(void *, int);
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);
extern "C" void func_00319C80(void *, int, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);

// [L] DNAT: CB3GenericVSelectPage::Prepare() (research/proto/new_names.csv, low)
// 0x003C98D0
extern "C" int func_003C98D0(UnkStruct_C98D0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, false);
    self->field_4C = func_0022D1E0(&D_004F50C0) < 2;
    int n;
    for (int i = 0; i < (n = self->field_4); i++) {
        bool b = ((self->field_4C != 0 && self->field_42[i] != 0) || self->field_38[i] != 0);
        int r = func_00271A00(&D_0051BA44, self->field_10[i]);
        UnkStruct_C98D0_e * e = &self->field_54[i];
        e->field_0 = r;
        e->field_4 = b;
        e->field_5 = 0;
    }
    self->field_4E = self->field_8;
    self->field_50 = n;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, &self->field_4E, &self->field_54[0], 640.0f);
    func_00319C80(&D_01E89518, self->field_C, 0xE);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
    func_0031ECD0(&D_01E89800, 0x105, 3);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    return 1;
}
