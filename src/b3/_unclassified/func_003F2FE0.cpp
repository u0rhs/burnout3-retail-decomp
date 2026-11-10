// Hand-written; the lifter refused it (a153: CB3MyBurnoutSettingsControllerPage::Prepare-like option builder; gotos for add-stuff tail, param copy locals fix s-regs, text call result in a temp, n++ after 4 stores).

enum EB3BackgroundType {};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89518 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E88A80 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7A800 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89800 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E8961C { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E894FC { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E65499 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_sb { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_003F2FE0_opt {
    int field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    int field_10;
};
struct UnkStruct_003F2FE0 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned short field_6;
    UnkStruct_003F2FE0_opt field_8[4];
    int field_58[4];
    int field_68;
    unsigned char field_6C;
};
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E894FC D_01E894FC;
extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_sb D_004F5074;
extern UnkStruct_D_sb D_004F5075;
extern UnkStruct_D_sb D_004F5079;
extern UnkStruct_D_sb D_004F5073;
extern int D_004E1EB0;
extern char D_004A55B0[];

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int func_00271A00(void *, int);
extern "C" int func_00131E40(void *);
extern "C" int func_00131CA0(void *);
extern "C" void func_00319C80(void *, int, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" void func_002844A0(void *);
extern "C" void func_00284650(void *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" void func_003BC4C0(void *, int, int);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, unsigned short);

// 0x003F2FE0
extern "C" int func_003F2FE0(UnkStruct_003F2FE0 * self0, int a0_)
{
    int n = 0;
    int i;
    int id;
    int p0 = a0_;
    Prepare__15CB3MenuPageBaseFb(self0, 0);
    self0->field_6C = 0;
    self0->field_68 = 0;
    int t0 = func_00271A00(&D_0051BA44, 0x19C);
    self0->field_8[0].field_D = 7;
    self0->field_8[0].field_0 = t0;
    self0->field_8[0].field_8 = 0;
    self0->field_8[0].field_C = 0x13;
    n = n + 1;
    self0->field_8[0].field_E = 0;
    self0->field_8[0].field_10 = 0;
    self0->field_8[0].field_4 = 0;
    self0->field_58[0] = 0;
    if (func_00131E40(&D_004EE040) == 0) goto addstuff;
join:
    for (i = n; i < 4; i++) {
        self0->field_58[i] = 4;
    }
    self0->field_4 = 0;
    self0->field_6 = n;
    p0 = 0xF;
    switch (self0->field_68) {
    case 0:
        p0 = 0xC;
    case 1:
    case 2:
        id = 0x18A;
        func_00319C80(&D_01E89518, 0x198, 5);
        Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)7);
        func_002844A0(&D_01E7A800);
        break;
    case 3:
        id = 0x10A;
        func_00319C80(&D_01E89518, 0x198, 0xE);
        Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
        func_00284650(&D_01E7A800);
        break;
    }
    func_0031ECD0(&D_01E89800, (unsigned int)id, p0);
    func_003BE5A0(&D_01E8961C, (char *)self0 + 4, (char *)self0 + 8);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    for (i = 0; i < n; i++) {
        switch (self0->field_58[i]) {
        case 0:
            func_003BC4C0(&D_01E8961C, i, D_004F5074.field_0 / 5);
            break;
        case 1:
            func_003BC4C0(&D_01E8961C, i, D_004F5075.field_0 / 5);
            break;
        case 2:
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, i, D_004F5079.field_0);
            break;
        case 3:
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, i, D_004F5073.field_0);
            break;
        default:
            continue;
        }
    }
    return 1;
addstuff:
    if (func_00131CA0(&D_004EE040) != 0) goto join;
    self0->field_68 = 1;
    int t1 = func_00271A00(&D_0051BA44, 0x19B);
    self0->field_8[n].field_D = 7;
    self0->field_8[n].field_0 = t1;
    self0->field_8[n].field_8 = 0;
    self0->field_8[n].field_C = 0x13;
    self0->field_8[n].field_E = 0;
    self0->field_8[n].field_10 = 0;
    self0->field_8[n].field_4 = 0;
    self0->field_58[n] = 1;
    n = n + 1;
    if (D_01E65499.field_0 != 0) goto join;
    self0->field_68 = 2;
    int t2 = func_00271A00(&D_0051BA44, 0xA02);
    self0->field_8[n].field_0 = t2;
    self0->field_8[n].field_8 = (int)&D_004E1EB0;
    self0->field_8[n].field_C = 2;
    self0->field_8[n].field_D = 4;
    self0->field_8[n].field_E = 0;
    self0->field_8[n].field_10 = 0;
    self0->field_8[n].field_4 = 0;
    self0->field_58[n] = 2;
    n = n + 1;
    if (p0 != 0) goto join;
    self0->field_68 = 3;
    int t3 = func_00271A00(&D_0051BA44, 0x8D);
    self0->field_8[n].field_0 = t3;
    self0->field_8[n].field_8 = (int)D_004A55B0;
    self0->field_8[n].field_C = 3;
    self0->field_8[n].field_D = 4;
    self0->field_8[n].field_E = 0;
    self0->field_8[n].field_10 = 0;
    self0->field_8[n].field_4 = 0;
    self0->field_58[n] = 3;
    n = n + 1;
    goto join;
}
