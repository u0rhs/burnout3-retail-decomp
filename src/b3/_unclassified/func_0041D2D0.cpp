// Hand-written; the lifter refused it (a89: lone byte global padded to 0x10 struct; enum/bool params as int).

// Prepare__26CB3OnlineUploadResultsPageFv -- [L] DNAT: CB3OnlineUploadResultsPage::Prepare() (research/proto/new_names.csv, high)
struct UnkStruct_0041D2D0_blk { unsigned char pad_0[0x10]; };
struct UnkStruct_0041D2D0 {
    unsigned char pad_0[0xCC];
    int field_CC;
};
extern UnkStruct_0041D2D0_blk D_01E88A80;
extern UnkStruct_0041D2D0_blk D_01E894FC;
extern UnkStruct_0041D2D0_blk D_0051BA44;
extern UnkStruct_0041D2D0_blk D_01E89518;
extern UnkStruct_0041D2D0_blk D_01E89788;
extern UnkStruct_0041D2D0_blk D_01E8D4B0;
extern UnkStruct_0041D2D0_blk D_004D10D8;
extern UnkStruct_0041D2D0_blk D_004D10E0;
extern UnkStruct_0041D2D0_blk D_004D10E8;
extern UnkStruct_0041D2D0_blk D_004D10F0;
extern UnkStruct_0041D2D0_blk D_004D10F8;
struct UnkStruct_0041D2D0_b { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_0041D2D0_b D_01EA2F0D;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" int func_00271A00(void *, int);
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, void *, int);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);

// 0x0041D2D0
extern "C" int Prepare__26CB3OnlineUploadResultsPageFv(UnkStruct_0041D2D0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, (void *)(func_00271A00(&D_0051BA44, 0x4F0)), 14);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 0x4F1), 1, 80.0f);
    func_00351F00(&D_01E8D4B0, &D_004D10D8, &D_004D10E0, &D_004D10E8, &D_004D10F0, &D_004D10F8, 0x4F0, 3, 0, 1, 0, 32.0f, 400.0f);
    D_01EA2F0D.field_0 = 0;
    self->field_CC = 0;
    return 1;
}
