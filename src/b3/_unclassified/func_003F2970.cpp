// Hand-written; the lifter refused it (CB3MyBurnoutSettingsAudioPage::Update [L]: ||/&& merged early return, input pad sub-struct at +0xD48, inline option-text refresh, FEVerticalMove arg 1).

// [L] DNAT: CB3MyBurnoutSettingsAudioPage::Update() (research/proto/new_names.csv)
enum EB3MenuFlowFSMEvents {};
struct UnkStruct_2970_o { unsigned char pad_0[0x10]; };
struct UnkStruct_2970_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_2970_b { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_2970_c { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_2970_pad {
    unsigned char pad_0[0x14];
    short field_14;
    unsigned char pad_16[0xA];
    short field_20;
    unsigned char pad_22[0xA];
    short field_2C;
    unsigned char pad_2E[0xA];
    short field_38;
    unsigned char pad_3A[0x16];
    short field_50;
    unsigned char pad_52[0xA];
    short field_5C;
    unsigned char pad_5E[0xCE];
};
struct UnkStruct_2970_im {
    unsigned char pad_0[0xD48];
    UnkStruct_2970_pad field_D48[1];
};
struct UnkStruct_2970 {
    unsigned char pad_0[4];
    unsigned short field_4;
    unsigned char pad_6[2];
    unsigned char pad_8[0x50];
    int field_58[4];
    int field_68;
    unsigned char field_6C;
};
extern UnkStruct_2970_o D_01E7A800, D_01E8961C, D_01EA2970, D_01E90240;
extern UnkStruct_2970_i D_01E90424;
extern UnkStruct_2970_b D_01E65499;
extern UnkStruct_2970_c D_004F5073, D_004F5074, D_004F5075, D_004F5079, D_0051BA94;
extern UnkStruct_2970_im D_004F50C0;
extern signed char D_004F6061[];
extern "C" void func_002844A0(void *);
extern "C" void func_00284650(void *);
extern "C" void func_00283DA0(void *);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" int func_0012FB10(void *, bool);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" void func_003BC4C0(void *, int, int);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, unsigned short);
extern "C" void ApplyEvent__14CB3MenuFlowFSMFUiPv(void *, unsigned int, void *);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
static inline void func_003F2970_inl1(UnkStruct_2970 * self)
{
    int i = self->field_4;
    switch (self->field_58[i]) {
    case 0:
        func_003BC4C0(&D_01E8961C, i, D_004F5074.field_0 / 5);
        break;
    case 1:
        func_003BC4C0(&D_01E8961C, i, D_004F5075.field_0 / 5);
        break;
    case 2:
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, i, D_004F5079.field_0);
        break;
    case 3:
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, i, D_004F5073.field_0);
        break;
    default:
        break;
    }
}
// 0x003F2970
extern "C" void func_003F2970(UnkStruct_2970 * self)
{
    int sel = self->field_58[self->field_4];
    signed char pi = 0;
    if (sel == 0) {
        if (self->field_68 != 3) {
            func_002844A0(&D_01E7A800);
        } else {
            func_00284650(&D_01E7A800);
        }
    } else {
        func_00283DA0(&D_01E7A800);
    }
    if (D_01E90424.field_0 != 5) return;
    if (self->field_68 != 3 && D_01E65499.field_0 == 0) pi = D_0051BA94.field_0;
    UnkStruct_2970_pad * p = &D_004F50C0.field_D48[D_004F6061[pi]];
    if ((p->field_2C != 0 && func_00319360(&self->field_4) != 0) || (p->field_38 != 0 && func_00319330(&self->field_4) != 0)) return;
    if (p->field_14 != 0) {
        switch (sel) {
        case 0:
            if (D_004F5074.field_0 >= 5) {
                D_004F5074.field_0 = D_004F5074.field_0 - 5;
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            }
            break;
        case 1:
            if (D_004F5075.field_0 >= 5) {
                D_004F5075.field_0 = D_004F5075.field_0 - 5;
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            }
            break;
        case 2:
            if (D_004F5079.field_0-- == 0) D_004F5079.field_0 = 1;
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            break;
        case 3:
            if (D_004F5073.field_0-- == 0) D_004F5073.field_0 = 2;
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            break;
        default:
            break;
        }
        func_003F2970_inl1(self);
        ApplyEvent__14CB3MenuFlowFSMFUiPv(&D_01EA2970, 0x4B, 0);
        return;
    }
    if (p->field_20 != 0) {
        switch (self->field_4) {
        case 0:
            D_004F5074.field_0 = D_004F5074.field_0 + 5;
            if (D_004F5074.field_0 > 100) D_004F5074.field_0 = 100;
            else FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            break;
        case 1:
            D_004F5075.field_0 = D_004F5075.field_0 + 5;
            if (D_004F5075.field_0 > 100) D_004F5075.field_0 = 100;
            else FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            break;
        case 2:
            D_004F5079.field_0 = D_004F5079.field_0 + 1;
            if (D_004F5079.field_0 >= 2) D_004F5079.field_0 = 0;
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            break;
        case 3:
            D_004F5073.field_0 = D_004F5073.field_0 + 1;
            if (D_004F5073.field_0 >= 3) D_004F5073.field_0 = 0;
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            break;
        default:
            break;
        }
        func_003F2970_inl1(self);
        ApplyEvent__14CB3MenuFlowFSMFUiPv(&D_01EA2970, 0x4B, 0);
        return;
    }
    if (p->field_50 != 0) {
        self->field_6C = 1;
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        return;
    }
    if (func_0012FB10(p, true) != 0) {
        if (self->field_68 == 3) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        } else {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)6, 1);
        }
        return;
    }
    if (p->field_5C == 0) return;
    self->field_6C = 1;
    ApplyEvent__14CB3MenuFlowFSMFUiPv(&D_01EA2970, 0x4A, 0);
    StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
}
