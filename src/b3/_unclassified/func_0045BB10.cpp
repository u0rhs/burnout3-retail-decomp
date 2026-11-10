// Hand-written; the lifter refused it (a117: page Prepare, sibling shape func_0045BF40 (two 0x14-byte entries, gp-relative &D_004E2658/60)).

enum EB3BackgroundType {};
class CB3PromptBarComponent {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_B { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_gp { int field_0; };
struct UnkStruct_0045BB10 {
    unsigned char pad_0[0x4];
    short field_4;
    short field_6;
    int field_8;
    int field_C;
    void * field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char pad_17[0x1];
    int field_18;
    int field_1C;
    int field_20;
    void * field_24;
    unsigned char field_28;
    unsigned char field_29;
    unsigned char field_2A;
    unsigned char pad_2B[0x1];
    int field_2C;
};
extern UnkStruct_D_16 D_0051BA44;
extern UnkStruct_D_16 D_01E8961C;
extern UnkStruct_D_16 D_01E89518;
extern UnkStruct_D_16 D_01E88A80;
extern UnkStruct_D_16 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_B D_004F507B;
extern UnkStruct_D_B D_004F507C;
extern UnkStruct_D_gp D_004E2658;
extern UnkStruct_D_gp D_004E2660;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);

// 0x0045BB10
extern "C" int func_0045BB10(UnkStruct_0045BB10 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_4 = 0;
    self->field_6 = 2;
    int r1 = func_00271A00(&D_0051BA44, 0x993);
    self->field_8 = r1;
    self->field_10 = &D_004E2658;
    self->field_14 = 2;
    self->field_15 = 4;
    self->field_16 = 0;
    self->field_18 = 0;
    self->field_C = 0;
    int r2 = func_00271A00(&D_0051BA44, 0x994);
    self->field_1C = r2;
    self->field_24 = &D_004E2660;
    self->field_28 = 2;
    self->field_29 = 4;
    self->field_2A = 0;
    self->field_2C = 0;
    self->field_20 = 0;
    func_003BE5A0(&D_01E8961C, (char *)self + 4, (char *)self + 8);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, D_004F507B.field_0);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, D_004F507C.field_0 != 0);
    func_00319C80(&D_01E89518, 0x992, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 0x10A, 15);
    D_01E894FC.Prepare();
    return 1;
}
