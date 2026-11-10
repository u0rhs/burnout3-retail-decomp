// Hand-written; the lifter refused it (a89: Prepare page; nested calls, extern C callees).

// func_00376470 -- [L] DNAT: CB3OnlineTrackRecordsMenuPage::Prepare(int) (research/proto/new_names.csv, medium)
struct UnkStruct_00376470_blk { unsigned char pad_0[0x10]; };
struct UnkStruct_00376470 {
    unsigned char pad_0[4];
    short field_4;
    short field_6;
    int field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char pad_E[2];
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
};
extern UnkStruct_00376470_blk D_0051BA44;
extern UnkStruct_00376470_blk D_01E89518;
extern UnkStruct_00376470_blk D_01E88A80;
extern UnkStruct_00376470_blk D_01E89800;
extern UnkStruct_00376470_blk D_01E894FC;
extern UnkStruct_00376470_blk D_01E89544;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void *FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" int GetTrackString__21CB3HardCodedTrackListFib(void *, bool);
extern "C" int func_00271A00(void *, int);
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, int, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);

// 0x00376470
extern "C" int func_00376470(UnkStruct_00376470 * self, unsigned long p0)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, func_00271A00(&D_0051BA44, GetTrackString__21CB3HardCodedTrackListFib(FindTrack__21CB3HardCodedTrackListFUl(p0), 1)), 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
    func_0031ECD0(&D_01E89800, 0x145, 3);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    self->field_4 = 0;
    self->field_6 = 2;
    self->field_8 = func_00271A00(&D_0051BA44, 0x2A7);
    self->field_C = 0;
    self->field_D = 0;
    self->field_10 = func_00271A00(&D_0051BA44, 0x2A8);
    self->field_14 = 0;
    self->field_15 = 0;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, &self->field_4, &self->field_8, 640.0f);
    return 1;
}
