// NONMATCHING: func_0043AF00 -- retail 360 / ours 359 instructions, 17 in changed runs
// a158: layout+calls exact (359/360); only diff: state reg a2 vs retail a1 / temp a1 vs a2 (idx*300 chain), so retail's StartLeadOut arg is move a1,a2 (shared compare constant 1). Tried decl order/locals/byte-cast/unsigned.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// func_0043AF00 [G] online-page Update (state at +0xC1C)
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F6061 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E898E8 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E89544 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8D450 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8954E { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E898F2 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E8D45A { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E32AE0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E3CD44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89800 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7A800 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004F50C0_Pad {
    unsigned char pad0[0x2C];
    short field_2C;
    unsigned char pad2E[0xA];
    short field_38;
    unsigned char pad3A[0xA];
    short field_44;
    unsigned char pad46[0x16];
    short field_5C;
    unsigned char pad5E[300 - 0x5E];
};
struct UnkStruct_D_004F50C0 {
    unsigned char pad0[0xD48];
    UnkStruct_D_004F50C0_Pad pads[4];
};
struct UnkStruct_0043AF00 {
    unsigned char pad_0[0x4];
    int field_4[16];
    unsigned char pad_44[0xBBC];
    int field_C00;
    unsigned short field_C04;
    unsigned char pad_C06[0x16];
    signed char field_C1C;
};
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" void *memset(void *, int, unsigned);
extern "C" int atoi(const char *);
extern "C" int func_003365E0(void *, int, char *, int);
extern "C" void func_0043A990(void *);
extern "C" int func_0043A190(void *);
extern "C" void func_0043A040(void *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0032B2C0(void *, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned);
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);

static inline void CloseAll()
{
    if (D_01E898F2.field_0 != 0) ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    if (D_01E8954E.field_0 != 0) ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    if (D_01E8D45A.field_0 != 0) ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
}

// 0x0043AF00
extern "C" void func_0043AF00(UnkStruct_0043AF00 *self)
{
    if (D_01E90424.field_0 != 5) return;
    UnkStruct_D_004F50C0_Pad *pad = &D_004F50C0.pads[D_004F6061.field_0];
    switch (self->field_C1C) {
    case 0: {
        int st = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
        switch (st) {
        case 2: {
            memset(self->field_4, 0, 0x40);
            int *p = self->field_4;
            for (unsigned i = 0; i < 16; i++, p++) {
                char buf[0x20];
                if (func_003365E0(&D_01E3CD44, i, buf, 0x20) == 1) {
                    self->field_C1C = 3;
                    CloseAll();
                    func_0032D080(&D_01E898E8, 2, 0x9E7, 0, 0);
                    return;
                }
                *p = atoi(buf);
            }
            self->field_C1C = 1;
            if (D_01E898F2.field_0 != 0) ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            if (self->field_4[2] < 0 || self->field_4[2] >= 0x44) self->field_4[2] = 0;
            if (self->field_4[7] < 0 || self->field_4[7] >= 0x44) self->field_4[7] = 0;
            if (self->field_4[5] < 0 || self->field_4[5] >= 0x25) self->field_4[5] = 0;
            func_0043A990(self);
            break;
        }
        case 0:
            break;
        case 1:
            self->field_C1C = 3;
            CloseAll();
            func_0032D080(&D_01E898E8, 2, 0x9E7, 0, 0);
            break;
        }
        break;
    }
    case 3:
        if (func_0032B2C0(&D_01E898E8, 0) == 0) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, false);
        }
        break;
    case 1:
        if (pad->field_44 != 0) {
            if (self->field_C04 != 0) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 1, 0);
            } else {
                if (D_01E8954E.field_0 != 0) ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x101, 3);
                func_0043A190(self);
            }
        } else if (pad->field_5C != 0) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, false);
        } else if (pad->field_2C != 0 && func_00319360(&self->field_C04)) {
        } else if (pad->field_38 != 0 && func_00319330(&self->field_C04)) {
            return;
        }
        break;
    case 2:
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            if (D_01E8954E.field_0 != 0) ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x105, 3);
            Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, &self->field_C04, (char *)self + 0xC08, 640.0f);
            func_0043A990(self);
            return;
        } else if (GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            if (self->field_C00 > 0) {
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
                self->field_C00 = self->field_C00 - 1;
                func_0043A040(self);
            }
            return;
        } else if (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            if (self->field_C00 < 0xE) {
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
                self->field_C00 = self->field_C00 + 1;
                func_0043A040(self);
            }
            return;
        }
        break;
    }
}
