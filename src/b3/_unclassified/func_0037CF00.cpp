// Hand-written; the lifter refused it (a83: CB3OnlineDupNameMenuPage::Prepare(bool,bool) [L] DNAT; vcall via cast).

// func_0037CF00 -- CB3OnlineDupNameMenuPage::Prepare(bool) [L] DNAT (research/proto/new_names.csv, medium; retail takes a second bool).
enum EB3BackgroundType {};
class CB3PromptBarComponent;
class CB3PromptBarComponent {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C9240 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E3CD44 {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void *vfunc_A8(int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_0037CF00_ent { int field_0; unsigned char field_4; unsigned char pad_5[3]; };
struct UnkStruct_0037CF00 {
    unsigned char pad_0[0x4];
    int field_4[5];
    UnkStruct_0037CF00_ent field_18[5];
    int field_40;
    unsigned char field_44;
    unsigned char pad_45[3];
    short field_48;
    short field_4A;
    int field_4C;
    unsigned char field_50;
    unsigned char field_51;
};
extern UnkStruct_D_Pad16 D_01E90438, D_01E89518, D_01EA3084, D_01E88A80, D_01E89800, D_0051BA44, D_01E8970C, D_01E8D4B0;
extern UnkStruct_D_Pad16 D_004C9220, D_004C9228, D_004C9230, D_004C9238, D_01E899C0;
extern UnkStruct_D_004C9240 D_004C9240;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E3CD44 D_01E3CD44;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" void RegisterKeyboardCallbacks__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" int func_0039BCD0(void *, void *, void *, int, int, float);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" int func_003517F0(void *);

// [L] DNAT: CB3OnlineDupNameMenuPage::Prepare(bool) (research/proto/new_names.csv, medium)
// 0x0037CF00
extern "C" int func_0037CF00(UnkStruct_0037CF00 *self, bool p0, bool p1)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    for (int i = 0; i < 5; i++) {
        self->field_4[i] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    }
    self->field_4C = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    if (p0) {
        func_00319C80(&D_01E89518, 1007, 14);
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&D_01EA3084, self->field_4C, 32);
    } else {
        func_00319C80(&D_01E89518, 1056, 14);
    }
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    for (int i = 0; i < 5; i++) {
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_A8(i), self->field_4[i], 32);
    }
    self->field_48 = 0;
    self->field_4A = 6;
    self->field_18[0].field_0 = self->field_4[0];
    self->field_18[0].field_4 = 0;
    self->field_18[1].field_0 = self->field_4[1];
    self->field_18[1].field_4 = 0;
    self->field_18[2].field_0 = self->field_4[2];
    self->field_18[2].field_4 = 0;
    self->field_18[3].field_0 = self->field_4[3];
    self->field_18[3].field_4 = 0;
    self->field_18[4].field_0 = self->field_4[4];
    self->field_18[4].field_4 = 0;
    self->field_40 = func_00271A00(&D_0051BA44, 1041);
    self->field_44 = 0;
    func_0039BCD0(&D_01E8970C, &self->field_48, self->field_18, 1, 0, 516.0f);
    if (p1) {
        func_00351F00(&D_01E8D4B0, &D_004C9220, &D_004C9228, &D_004C9230, &D_004C9238, &D_004C9240, 1066, 3, 1, 3, 0, 26.0f, D_004C9240.field_0);
    } else {
        func_00351F00(&D_01E8D4B0, &D_004C9220, &D_004C9228, &D_004C9230, &D_004C9238, &D_004C9240, 1040, 3, 1, 3, 0, 26.0f, D_004C9240.field_0);
    }
    self->field_50 = 0;
    self->field_51 = p0;
    func_003517F0(&D_01E899C0);
    RegisterKeyboardCallbacks__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
    return 1;
}
