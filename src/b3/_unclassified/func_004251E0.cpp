// Hand-written; the lifter refused it (page Prepare, from func_0037CF00 shape).

enum EB3BackgroundType {};
class CB3PromptBarComponent;
class CB3PromptBarComponent {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_004251E0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
    int field_10;
    short field_14;
    short field_16;
    unsigned char pad_18[0x48];
    int field_60[9];
};
extern UnkStruct_D_Pad16 D_01E90438, D_01E89518, D_01E88A80, D_01E89800, D_01E89544, D_004D14E0, D_004D14F0, D_004D1500, D_004D1520;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, void *, void *, float);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_00424A60(void *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, int, int);
// 0x004251E0
extern "C" int func_004251E0(UnkStruct_004251E0 *self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_14 = self->field_4;
    self->field_16 = 9;
    for (int i = 0; i < 9; i++) {
        self->field_60[i] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 64);
    }
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&D_004D14E0, self->field_60[0], 64);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&D_004D14F0, self->field_60[1], 64);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&D_004D1500, self->field_60[2], 64);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&D_004D1520, self->field_60[3], 64);
    func_00424A60(self);
    self->field_10 = -1;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (char *)self + 0x14, (char *)self + 0x18, 640.0f);
    func_00319C80(&D_01E89518, 227, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    return 1;
}
