// Hand-written; the lifter refused it (Prepare call chain, void* externs).

// Hand-written (a108). [L] DNAT: CB3MyBurnoutRewardsTrophiesPage::Prepare() (research/proto/new_names.csv, low) -- hint only.
struct UnkStruct_00438910 {
    unsigned char pad_0[0x14];
    float field_14;
};
struct UnkStruct_Gd { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004F50A0_a { float field_0; unsigned char pad_4[0xC]; };

extern UnkStruct_Gd D_004F50C0;
extern UnkStruct_Gd D_01E89518;
extern UnkStruct_Gd D_01E8D550;
extern UnkStruct_Gd D_01E88A80;
extern UnkStruct_Gd D_01E89788;
extern UnkStruct_Gd D_01E894FC;
extern UnkStruct_Gd D_01E7A888;
extern UnkStruct_D_004F50A0_a D_004F50A0;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void ResetDeadInputTime__15CB3InputManagerFSc(void *, signed char);
extern "C" void Prepare__19CB3HeadingComponentFQ219CB3HeadingComponent12EHeadingType(void *, int);
extern "C" int func_00343A50(void *);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" void Prepare__19CB3HelpBarComponentFv(void *);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" void func_003FA600(void *, int);

// 0x00438910
extern "C" int func_00438910(UnkStruct_00438910 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, true);
    ResetDeadInputTime__15CB3InputManagerFSc(&D_004F50C0, -1);
    Prepare__19CB3HeadingComponentFQ219CB3HeadingComponent12EHeadingType(&D_01E89518, 5);
    func_00343A50(&D_01E8D550);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 1);
    Prepare__19CB3HelpBarComponentFv(&D_01E89788);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    func_003FA600(&D_01E7A888, 0);
    self->field_14 = D_004F50A0.field_0;
    return 1;
}
