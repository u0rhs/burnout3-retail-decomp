// NONMATCHING: func_003F3B00 -- retail 213 / ours 213 instructions, 8 in changed runs
// 213/213, 8 instrs: switch compare regs (retail lhu v0; li a1,1; beq v0,a1 / ours v1,v0); layout exact via goto-dispatch (all button blocks out of line) + switch(case0,case1)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003F3B00 -- CB3MyBurnoutSettingsPlaylistEditPage::Update() [L] DNAT (research/proto/new_names.csv, exact/verified)
#include "b3/classes/UnkStruct_D_004F5070.h"
#include "b3/classes/UnkStruct_D_004F5071.h"
#include "b3/classes/UnkStruct_D_01E90424.h"
enum EB3MenuFlowFSMEvents {};
struct UnkStruct_003F3B00_pad {
    unsigned char pad_0[0x14];
    short field_14;
    unsigned char pad_16[0xA];
    short field_20;
    unsigned char pad_22[0xA];
    short field_2C;
    unsigned char pad_2E[0xA];
    short field_38;
    unsigned char pad_3A[0xA];
    short field_44;
    unsigned char pad_46[0x16];
    short field_5C;
    unsigned char pad_5E[300 - 0x5E];
};
struct UnkStruct_003F3B00_inp {
    unsigned char pad0[0xD48];
    UnkStruct_003F3B00_pad pads[4];
};
struct UnkStruct_003F3B00_o {
    unsigned char pad[0x10];
};
struct UnkStruct_003F3B00_sel {
    unsigned short field_0;
    unsigned short field_2;
};
struct UnkStruct_003F3B00_self {
    unsigned char pad_0[4];
    UnkStruct_003F3B00_sel field_4;
};
struct UnkStruct_003F3B00_p6061 { signed char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_003F3B00_inp D_004F50C0;
extern UnkStruct_003F3B00_p6061 D_004F6061;
extern UnkStruct_D_004F5070 D_004F5070;
extern UnkStruct_D_004F5071 D_004F5071;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_003F3B00_o D_01E8961C;
extern UnkStruct_003F3B00_o D_01EA2970;
extern UnkStruct_003F3B00_o D_01E7A800;
extern UnkStruct_003F3B00_o D_01E90240;
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);
extern "C" void func_003BC500(void *, int, signed char);
extern "C" void ApplyEvent__14CB3MenuFlowFSMFUiPv(void *, unsigned int, void *);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);

// 0x003F3B00
extern "C" void func_003F3B00(UnkStruct_003F3B00_self * self)
{
    if (D_01E90424.field_0 == 5) {
        UnkStruct_003F3B00_pad *pad = &D_004F50C0.pads[D_004F6061.field_0];
        if ((pad->field_2C != 0 && func_00319360(&self->field_4) != 0) || (pad->field_38 != 0 && func_00319330(&self->field_4) != 0)) return;
        if (pad->field_14 != 0) goto l14;
        if (pad->field_20 != 0) goto l20;
        if (pad->field_44 != 0) goto l44;
        if (pad->field_5C != 0) goto l5C;
        return;
        l14:
            switch (self->field_4.field_0) {
            case 0:
                D_004F5070.field_0--;
                if (D_004F5070.field_0 < -9) D_004F5070.field_0++;
                else FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800);
                func_003BC500(&D_01E8961C, 0, D_004F5070.field_0);
                break;
            case 1:
                D_004F5071.field_0--;
                if (D_004F5071.field_0 < -9) D_004F5071.field_0++;
                else FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800);
                func_003BC500(&D_01E8961C, 1, D_004F5071.field_0);
                break;
            }
            ApplyEvent__14CB3MenuFlowFSMFUiPv(&D_01EA2970, 0x4B, 0);
        return;
        l20:
            switch (self->field_4.field_0) {
            case 0:
                D_004F5070.field_0++;
                if (D_004F5070.field_0 > 9) D_004F5070.field_0--;
                else FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800);
                func_003BC500(&D_01E8961C, 0, D_004F5070.field_0);
                break;
            case 1:
                D_004F5071.field_0++;
                if (D_004F5071.field_0 > 9) D_004F5071.field_0--;
                else FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800);
                func_003BC500(&D_01E8961C, 1, D_004F5071.field_0);
                break;
            }
            ApplyEvent__14CB3MenuFlowFSMFUiPv(&D_01EA2970, 0x4B, 0);
        return;
        l44:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)1, false);
        return;
        l5C:
            ApplyEvent__14CB3MenuFlowFSMFUiPv(&D_01EA2970, 0x4A, 0);
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, false);
        return;
    }
}
