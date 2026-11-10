// Hand-written; the lifter refused it (a88: MyBurnoutRewardsPage::Update, goto act/lead layout, switch for the Down test ([G] gotos)).

// Hand-written (a88: CB3MyBurnoutRewardsPage::Update(), sibling shape func_003F38C0).
// [L] DNAT: CB3MyBurnoutRewardsPage::Update() (research/proto/new_names.csv, medium)
enum EB3MenuFlowFSMEvents {};
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; };
struct UnkStruct_003F0ED0_in {
    unsigned char pad_0[0x2C];
    short field_2C;
    unsigned char pad_2E[0xA];
    short field_38;
    unsigned char pad_3A[0xA];
    short field_44;
    unsigned char pad_46[0x16];
    short field_5C;
};
struct UnkStruct_003F0ED0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x4];
    unsigned short field_C;
};
struct UnkStruct_D_004F50C0 { unsigned char pad_0[0x12C]; };
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E90240 D_01E90240;
struct UnkStruct_D_004F6061 { signed char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_004F50C0 D_004F50C0[];
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);
extern "C" void func_003F0CE0(UnkStruct_003F0ED0 *, int);

// 0x003F0ED0
extern "C" void func_003F0ED0(UnkStruct_003F0ED0 * self)
{
    if (D_01E90424.field_0 != 5) return;
    UnkStruct_003F0ED0_in * in = (UnkStruct_003F0ED0_in *)((char *)&D_004F50C0[D_004F6061.field_0] + 0xD48);
    if (in->field_5C != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    if (in->field_2C != 0 && func_00319360((char *)self + 0xC) != 0) goto act;
    if (in->field_38 != 0) {
        switch (func_00319330((char *)self + 0xC)) {
        case 0:
            break;
        default:
            goto act;
        }
    }
    if (in->field_44 != 0) goto lead;
    return;
act:
    self->field_4 = self->field_C;
    func_003F0CE0(self, self->field_4);
    return;
lead:
    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
}
