// Hand-written; the lifter refused it (a117: page Prepare with two int params (a1,a2 stored at +4/+8)).

// [L] DNAT: CB3StageSelectPage::Prepare(bool) (research/proto/new_names.csv, low); retail takes two ints
struct UnkStruct_0044A380 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char field_C;
};
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_01E89518;
extern UnkStruct_D_16 D_01E89800;
extern UnkStruct_D_16 D_01E894FC;
extern UnkStruct_D_16 D_01E88A80;
extern UnkStruct_D_16 D_01E898E8;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void Prepare__19CB3HeadingComponentFQ219CB3HeadingComponent12EHeadingType(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" void func_0032D080(void *, int, int, int, int);

// 0x0044A380
extern "C" int func_0044A380(UnkStruct_0044A380 * self, int a1, int a2)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_4 = a1;
    self->field_8 = a2;
    self->field_C = 0;
    Prepare__19CB3HeadingComponentFQ219CB3HeadingComponent12EHeadingType(&D_01E89518, 5);
    func_0031ECD0(&D_01E89800, 0x105, 3);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 8);
    func_0032D080(&D_01E898E8, 7, self->field_8, 5, 1);
    return 1;
}
