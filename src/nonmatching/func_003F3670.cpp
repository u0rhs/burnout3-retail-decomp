// NONMATCHING: func_003F3670 -- retail 141 / ours 140 instructions, 52 in changed runs
// psweep: scoped #pragma opt_optimizecontrolflow off [G] improves 57 -> 56
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_optimizecontrolflow off
// TRACK: near
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_003F3670_ent {
    const unsigned short *field_0;
    int field_4;
    int *field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    int field_10;
};
struct UnkStruct_003F3670 {
    unsigned char pad_0[4];
    short field_4;
    short field_6;
    UnkStruct_003F3670_ent field_8[2];
    int field_30;
    unsigned char field_34;
};
class CB3InputManager { public: int GetLockedPlayersPort(signed char); unsigned char pad_0[0x10]; };
struct UnkStruct_D_gen { unsigned char pad_0[0x10]; };
struct UnkStruct_D_sc { signed char field_0; unsigned char pad_1[0xF]; };
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_sc D_0051BA94;
extern UnkStruct_D_gen D_0051BA44, D_01E88A80, D_01E89800, D_01E894FC, D_01E89518, D_01E8961C;
extern signed char D_004F506C[];
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x702C]; signed char field_702C[2]; };
extern UnkStruct_D_004EE040 D_004EE040;
extern int D_004E1EB8;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" int func_003F3670(UnkStruct_003F3670 *self, bool p0)
{
    Prepare__15CB3MenuPageBaseFb(self, false);
    self->field_34 = 0;
    int s0;
    if (p0) {
        signed char port = D_0051BA94.field_0;
        if (port == -1) port = 0;
        s0 = (signed char)D_004F50C0.GetLockedPlayersPort(port);
        self->field_8[0].field_0 = func_00271A00(&D_0051BA44, s0 + 0xC1);
        self->field_8[0].field_8 = &D_004E1EB8;
        self->field_8[0].field_C = 2;
        self->field_8[0].field_D = 4;
        self->field_8[0].field_E = 0;
        self->field_8[0].field_10 = 0;
        self->field_8[0].field_4 = 0;
        self->field_4 = 0;
        self->field_6 = 1;
    } else {
        for (s0 = 0; s0 < 2; s0++) {
            const unsigned short *str = func_00271A00(&D_0051BA44, s0 + 0xC1);
            self->field_8[s0].field_0 = str;
            self->field_8[s0].field_8 = &D_004E1EB8;
            self->field_8[s0].field_C = 2;
            self->field_8[s0].field_D = 4;
            self->field_8[s0].field_E = 0;
            self->field_8[s0].field_10 = 0;
            self->field_8[s0].field_4 = 0;
        }
        self->field_4 = 0;
        self->field_6 = 2;
    }
    func_003BE5A0(&D_01E8961C, &self->field_4, self->field_8);
    if (p0) {
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, !D_004F506C[s0]);
        func_00319C80(&D_01E89518, 0xC7, 5);
        Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 7);
        func_0031ECD0(&D_01E89800, 0x18A, 0xF);
        self->field_30 = 1;
    } else {
        for (s0 = 0; s0 < 2; s0++) {
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, s0, !D_004EE040.field_702C[s0]);
        }
        func_00319C80(&D_01E89518, 0xC7, 0xE);
        Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
        func_0031ECD0(&D_01E89800, 0x10A, 0xF);
        self->field_30 = 0;
    }
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    return 1;
}

#pragma pop
