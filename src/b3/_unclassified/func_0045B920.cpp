// Hand-written; the lifter refused it (options page input; merged || return for up/down; lr/cf/bk blocks via goto after tests).

struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_B { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_I { int field_0; unsigned char pad_4[0xC]; };
class CB3HUDSoundManager { public: unsigned char pad_0[0x10]; };
struct UnkStruct_0045B920 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
};
extern UnkStruct_D_I D_01E90424;
extern signed char D_004F6061[];
extern UnkStruct_D_16 D_004F50C0, D_01E8961C, D_01E7A800, D_01EA2970, D_01E90240;
extern UnkStruct_D_B D_004F507B;
extern UnkStruct_D_B D_004F507C;
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" void ApplyEvent__14CB3MenuFlowFSMFUiPv(void *, unsigned int, void *);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);

// 0x0045B920
extern "C" void func_0045B920(UnkStruct_0045B920 * self)
{
    if (D_01E90424.field_0 != 5) return;
    char * ctrl = (char *)&D_004F50C0 + D_004F6061[0] * 0x12C + 0xD48;
    if ((*(short *)(ctrl + 0x2C) != 0 && func_00319360(&self->field_4) != 0) || (*(short *)(ctrl + 0x38) != 0 && func_00319330(&self->field_4) != 0)) return;
    if (*(short *)(ctrl + 0x14) != 0 || *(short *)(ctrl + 0x20) != 0) goto lr;
    if (*(short *)(ctrl + 0x44) != 0) goto cf;
    if (*(short *)(ctrl + 0x5C) != 0) goto bk;
    return;
lr:
    switch (self->field_4) {
    case 0:
        if (D_004F507B.field_0 == 1) {
            D_004F507B.field_0 = 0;
        } else {
            D_004F507B.field_0 = 1;
        }
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, self->field_4, D_004F507B.field_0);
        break;
    case 1:
        D_004F507C.field_0 = (D_004F507C.field_0 != 0) ^ 1;
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, self->field_4, D_004F507C.field_0 != 0);
        break;
    }
    FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    ApplyEvent__14CB3MenuFlowFSMFUiPv(&D_01EA2970, 0x4B, 0);
    return;
cf:
    StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 1, false);
    return;
bk:
    ApplyEvent__14CB3MenuFlowFSMFUiPv(&D_01EA2970, 0x4A, 0);
    StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, false);
}
