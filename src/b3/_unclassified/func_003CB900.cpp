// Hand-written; the lifter refused it (a132: 5-entry option table (stride 0x14) written sequentially).

struct UnkStruct_B900_e {
    int field_0;
    int field_4;
    const void *field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    int field_10;
};
struct UnkStruct_B900 {
    unsigned char pad_0[0x10];
    unsigned short field_10;
    unsigned short field_12;
    UnkStruct_B900_e field_14[5];
    unsigned short field_78;
    unsigned short field_7A;
    unsigned short field_7C;
    unsigned short field_7E;
    unsigned char pad_80[0x14];
    int field_94;
    unsigned char pad_98[8];
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    unsigned char pad_B4[4];
    unsigned char field_B8;
};
struct UnkStruct_D_01E8961C { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_Gen { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_Gen D_0051BA44;
extern int D_004CA470[];
extern int D_004CA478[];
extern int D_004CA488[];
extern int D_004CA490[];
extern "C" int func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void func_003BC360(void *, int, int);

// 0x003CB900
extern "C" void func_003CB900(UnkStruct_B900 *self, int page)
{
    self->field_10 = page;
    self->field_12 = 5;
    self->field_14[0].field_0 = func_00271A00(&D_0051BA44, 0x2CB);
    self->field_14[0].field_8 = D_004CA478;
    self->field_14[0].field_C = 2;
    self->field_14[0].field_D = 4;
    self->field_14[0].field_E = 0;
    self->field_14[0].field_10 = 0;
    self->field_14[0].field_4 = 0;
    self->field_14[2].field_0 = func_00271A00(&D_0051BA44, 0x2D2);
    self->field_14[2].field_8 = &self->field_7C;
    self->field_14[2].field_C = self->field_7E - self->field_7C;
    self->field_14[2].field_D = 5;
    self->field_14[2].field_E = 0;
    self->field_14[2].field_10 = 0;
    self->field_14[2].field_4 = 0;
    self->field_14[3].field_0 = func_00271A00(&D_0051BA44, 0x9BC);
    self->field_14[3].field_8 = D_004CA488;
    self->field_14[3].field_C = 2;
    self->field_14[3].field_D = 4;
    self->field_14[3].field_E = 0;
    self->field_14[3].field_10 = 0;
    self->field_14[3].field_4 = 0;
    self->field_14[4].field_0 = func_00271A00(&D_0051BA44, 0xB3A);
    self->field_14[4].field_8 = D_004CA490;
    self->field_14[4].field_C = 2;
    self->field_14[4].field_D = 4;
    self->field_14[4].field_E = 0;
    self->field_14[4].field_10 = 0;
    self->field_14[4].field_4 = 0;
    if (D_004CA470[self->field_A0] == 1) {
        self->field_14[1].field_0 = func_00271A00(&D_0051BA44, 0x2C4);
        self->field_14[1].field_8 = &self->field_94;
        self->field_14[1].field_C = 3;
        self->field_14[1].field_D = 3;
        self->field_14[1].field_E = 0;
        self->field_14[1].field_10 = 0;
        self->field_14[1].field_4 = 0;
    } else {
        self->field_14[1].field_0 = func_00271A00(&D_0051BA44, 0x2C4);
        self->field_14[1].field_8 = &self->field_78;
        self->field_14[1].field_C = self->field_7A - self->field_78;
        self->field_14[1].field_D = 5;
        self->field_14[1].field_E = 0;
        self->field_14[1].field_10 = 0;
        self->field_14[1].field_4 = 0;
    }
    func_003BE5A0(&D_01E8961C, &self->field_10, &self->field_14);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_A0);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_A8);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, self->field_AC);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, self->field_A4);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 4, self->field_B0);
    func_003BC360(&D_01E8961C, 0, self->field_B8);
}
