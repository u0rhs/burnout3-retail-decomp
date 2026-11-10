// Hand-written; the lifter refused it (MainMenu-family page Prepare; flag s7=0 between stores keeps fp/s7 separate; *(const int*)&field_1C reload in stub; else-if order A,Y,X).

// Hand-written (a147).
struct UnkStruct_D_gen { unsigned char pad_0[0x10]; };
struct UnkStruct_00318F50 {
    unsigned char pad_0[8];
    long field_8;
    unsigned long field_10;
    unsigned char pad_18[4];
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    unsigned int field_2C;
    int field_30;
    unsigned char field_34;
    unsigned char field_35;
};
extern UnkStruct_D_gen D_01E88A80;
extern UnkStruct_D_gen D_01E894FC;
extern UnkStruct_D_gen D_01E89788;
extern UnkStruct_D_gen D_01E8EC30;
extern UnkStruct_D_gen D_01E8EB40;
extern UnkStruct_D_gen D_01E8EE98;
extern UnkStruct_D_gen D_01E89800;
extern UnkStruct_D_gen D_01E7A888;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void func_003187F0(void *, int, unsigned long);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" void Prepare__19CB3HelpBarComponentFv(void *);
extern "C" int GetClassFromID__14CB3VehicleListFUl(unsigned long);
extern "C" int func_0042DF40(unsigned long, int);
extern "C" void func_0042CFA0(void *, int, int, int, int, int, int, int);
extern "C" int func_0042B030(void *, int, int);
extern "C" bool func_00435100(void *, int);
extern "C" int GetEntryCount__20CB3CarouselComponentFv(void *);
extern "C" int func_0042BC70(void *);
extern "C" long func_0042B700(void *, int);
extern "C" int func_0042B5F0(void *, int);
extern "C" void func_0042B010(void *, long, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_003F8C00(void *, int);

// 0x00318F50
extern "C" bool func_00318F50(UnkStruct_00318F50 * self, int p0, unsigned long p1, int p2, int p3, bool p4, unsigned long p5, int p6)
{
    int s7;
    Prepare__15CB3MenuPageBaseFb(self, false);
    self->field_1C = p0;
    self->field_10 = p1;
    s7 = 0;
    self->field_34 = p4;
    self->field_35 = 1;
    func_003187F0(self, p0, p1);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 11);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    Prepare__19CB3HelpBarComponentFv(&D_01E89788);
    if (self->field_10 != 0) {
        self->field_1C = GetClassFromID__14CB3VehicleListFUl(self->field_10);
        self->field_20 = self->field_1C;
        self->field_24 = func_0042DF40(self->field_10, 0);
        func_0042CFA0(&D_01E8EC30, self->field_1C, self->field_24, self->field_20, self->field_24, p2, p3, p6);
        func_0042B030(&D_01E8EB40, 0, 0);
    } else if (self->field_1C != 9) {
        s7 = 3;
        if (self->field_20 != self->field_1C) {
            self->field_20 = *(const int *)&self->field_1C;
            self->field_24 = 0;
        }
        func_0042CFA0(&D_01E8EC30, self->field_1C, -1, self->field_20, self->field_24, p2, p3, p6);
        func_0042B030(&D_01E8EB40, 0, 1);
    } else {
        s7 = 15;
        if (p5 != 0) {
            self->field_20 = GetClassFromID__14CB3VehicleListFUl(p5);
            self->field_24 = func_0042DF40(p5, 0);
        }
        func_0042CFA0(&D_01E8EC30, 9, -1, self->field_20, self->field_24, p2, p3, p6);
        func_0042B030(&D_01E8EB40, 0, 1);
    }
    func_00435100(&D_01E8EE98, self->field_10 != 0);
    self->field_30 = GetEntryCount__20CB3CarouselComponentFv(&D_01E8EC30);
    long s1;
    int s0;
    s0 = func_0042BC70(&D_01E8EC30);
    s1 = func_0042B700(&D_01E8EC30, s0);
    if (s1 != 0) {
        func_0042B010(&D_01E8EB40, s1, func_0042B5F0(&D_01E8EC30, s0));
    } else {
        func_0042B010(&D_01E8EB40, 0, 0);
    }
    self->field_8 = 0;
    self->field_28 = 0;
    if (self->field_34 != 0) self->field_2C = 0x4000001;
    else self->field_2C = 0x4000000;
    if (self->field_10 != 0) self->field_2C |= 0x10;
    else self->field_2C |= 4;
    if (p0 == 9 || p1 == 0) self->field_2C |= 0x100;
    func_0031ECD0(&D_01E89800, self->field_2C, s7);
    func_003F8C00(&D_01E7A888, 4);
    return true;
}
