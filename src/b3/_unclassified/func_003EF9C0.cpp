// Hand-written; the lifter refused it (SelectNext test as switch{case 0: break; default: goto act;} (func_003F38C0 shape)).

// near5: the func_00319330 (SelectNext) test as `switch { case 0: break; default: goto act; }` gives retail's beqz/b-act shape (as in the proven func_003F38C0); explicit `goto act` / fall-through to the field_44 test.

// func_003EF9C0 -- CB3MyBurnoutProgressPage::Update() [L] DNAT (research/proto/new_names.csv, medium)
enum EB3MenuFlowFSMEvents {};
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F6061 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E8980A { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E89800 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_003EF9C0_pad {
    unsigned char pad_0[0x2C];
    short field_2C;
    unsigned char pad_2E[0xA];
    short field_38;
    unsigned char pad_3A[0xA];
    short field_44;
    unsigned char pad_46[0x16];
    short field_5C;
    unsigned char pad_5E[300 - 0x5E];
};
struct UnkStruct_D_004F50C0 {
    unsigned char pad_0[0xD48];
    UnkStruct_003EF9C0_pad pads[4];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_003EF9C0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned short field_8;
};
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_P D_01E90240, D_01E8EFB8;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_0043E120(void *);
extern "C" void func_0043E130(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// [L] DNAT: CB3MyBurnoutProgressPage::Update() (research/proto/new_names.csv, medium)
// 0x003EF9C0
extern "C" void func_003EF9C0(UnkStruct_003EF9C0 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    UnkStruct_003EF9C0_pad * pad = &D_004F50C0.pads[D_004F6061.field_0];
    if (pad->field_5C != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, false);
        return;
    }
    if (pad->field_2C != 0 && func_00319360(&self->field_8)) {
        goto act;
    }
    if (pad->field_38 != 0) {
        switch (func_00319330(&self->field_8)) {
        case 0:
            break;
        default:
            goto act;
        }
    }
    if (pad->field_44 != 0 && self->field_8 == 3) {
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
    }
    return;
act:
    self->field_4 = self->field_8;
    switch (self->field_4) {
    case 0:
        func_0043E130(&D_01E8EFB8, 1);
        break;
    case 1:
        func_0043E130(&D_01E8EFB8, 2);
        break;
    case 2:
        func_0043E130(&D_01E8EFB8, 0);
        break;
    case 3:
        func_0043E120(&D_01E8EFB8);
        break;
    }
    if (D_01E8980A.field_0 != 0) {
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    }
    switch (self->field_8) {
    case 0:
    case 1:
    case 2:
        func_0031ECD0(&D_01E89800, 0x101, 3);
        break;
    case 3:
        func_0031ECD0(&D_01E89800, 0x105, 3);
        break;
    }
}
