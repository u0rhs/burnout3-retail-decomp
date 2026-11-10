// Hand-written; the lifter refused it (a132: switch case 0,1,2 order; locals declared l4C,l48 then assigned l48 first).

struct UnkStruct_58A0_pp { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_58A0 {
    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[4];
    unsigned long field_30;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    unsigned char field_48;
    unsigned char field_49;
    unsigned char field_4A;
    unsigned char field_4B;
    unsigned char field_4C;
    unsigned char field_4D;
};
struct UnkStruct_58A0_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_58A0_b { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_58A0_c { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_58A0_s { unsigned char pad_0[0x10]; };
enum EB3BackgroundType {};
extern UnkStruct_58A0_i D_01ECDAB4;
extern UnkStruct_58A0_b D_01ECDAC4;
extern UnkStruct_58A0_c D_01ECDACB, D_01ECDACC, D_01ECDACF;
extern UnkStruct_58A0_s D_01E90438, D_01E88A80, D_0051BA44, D_01E89518, D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" int func_00271A00(void *, int);
extern "C" void func_00322620(void *, void *, const int *, const int *);
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, void *, int);
extern "C" void Prepare__19CB3HeadingComponentFQ219CB3HeadingComponent12EHeadingType(void *, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" void func_003C5A80(void *);

// 0x003C58A0
extern "C" void func_003C58A0(UnkStruct_58A0 *self, int id, bool b, UnkStruct_58A0_pp *p)
{
    int type;
    Prepare__15CB3MenuPageBaseFb(self, b);
    self->field_48 = 0;
    self->field_3C = 0;
    self->field_38 = 0;
    self->field_44 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x80);
    self->field_4D = 0;
    self->field_30 = 0xFFFFFFFFUL;
    if (p != 0) {
        if (p->field_0 > 0) {
            self->field_49 = 1;
            self->field_4C = 0;
        } else if (D_01ECDAC4.field_0 != 0) {
            self->field_49 = 1;
            self->field_4C = 1;
        } else {
            self->field_49 = 0;
            self->field_4C = 1;
        }
        self->field_4B = (p->field_0 + 1 == p->field_2);
    } else {
        self->field_49 = 0;
        self->field_4C = 0;
        self->field_4B = 0;
    }
    switch (D_01ECDAB4.field_0) {
    case 0: type = 0; break;
    case 1: type = 1; break;
    case 2: type = 2; break;
    default: type = D_01ECDACF.field_0; break;
    }
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)8);
    if (id < 0xFA5) {
        self->field_28 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x40);
        int l4C, l48;
        l48 = D_01ECDACC.field_0;
        l4C = D_01ECDACB.field_0;
        func_00322620((void *)(self->field_28), (void *)(func_00271A00(&D_0051BA44, id)), &l4C, &l48);
        Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, (void *)(self->field_28), type);
    } else {
        self->field_28 = 0;
        Prepare__19CB3HeadingComponentFQ219CB3HeadingComponent12EHeadingType(&D_01E89518, type);
    }
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    func_003C5A80(self);
}
