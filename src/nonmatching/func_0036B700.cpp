// NONMATCHING: func_0036B700 -- retail 419 / ours 419 instructions, 30 in changed runs
// a169: logic complete, 419/419 instrs, 30 in changed runs = pure v0/v1 swap at 6 sites: retail 'lw v1,0x120; lui v0,2; ori s0,v0,0xDA04; sll v0,v1,3' vs ours 'lw v0; lui v1; ori s0,v1; sll v0,v0,3' (item count n vs the 0x2DA04 constant temp). Tried: n local, const pun, s as char*, s order. Float arg is plain 516.0f; vfunc_C result unused (void).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// Hand-written (a169): func_0036B700 -- menu item builder for a buddy page (DNAT: CB3OnlineBuddiesState::Action? low-confidence row; see new_names.csv).
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void IsBuddyIgnored__22CGtBuddiesPS2DirtySockFPcPb(void *, char *, bool *);
extern "C" void IsWannaBeMyBuddy__22CGtBuddiesPS2DirtySockFPcPb(void *, char *, bool *);
extern "C" void IsWannaBeHisBuddy__22CGtBuddiesPS2DirtySockFPcPb(void *, char *, bool *);
extern "C" void IsTemporaryBuddy__22CGtBuddiesPS2DirtySockFPcPb(void *, char *, bool *);
extern "C" void IsPermanentBuddy__22CGtBuddiesPS2DirtySockFPcPb(void *, char *, bool *);
extern "C" int GetPresence__22CGtBuddiesPS2DirtySockFPcP16EGtBuddyPresence(void *, char *, int *);
extern "C" int func_0035F970(void *, char *, bool *);
extern "C" int func_0035F900(void *, char *, bool *);
extern "C" int func_0035F1E0(void *, char *, bool *);
extern "C" int func_0035F9E0(void *, char *, bool *);
extern "C" void *HLBListGetBuddyByName(int, char *);
extern "C" int HLBMsgListGetTotalCount(void *);
extern "C" int func_00271A00(void *, int);
extern "C" int func_0039BCD0(void *, void *, void *, int, int, float);
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_Pad16 D_01E89800, D_01E3D390, D_0051BA44, D_004EE040;
struct UnkStruct_D_01E3D4A8 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E3D4A8 D_01E3D4A8;
struct UnkStruct_D_01E89716 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_01E89716 D_01E89716;
struct UnkStruct_D_01E8970C {
    virtual void vfunc_8();
    virtual int vfunc_C();
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_01E8970C D_01E8970C;
struct UnkStruct_a169_ent { int field_0; unsigned char field_4; unsigned char pad_5[3]; };
struct UnkStruct_a169 {
    unsigned char pad_0[0x60];
    short field_60;
    short field_62;
    UnkStruct_a169_ent field_64[14];
    int field_D4[13];
    char field_108[0x18];
    int field_120;
};
static inline void a169_add(UnkStruct_a169 *self, void *tbl, int id, int kind)
{
    int n = self->field_120;
    UnkStruct_a169_ent *e = &self->field_64[n];
    e->field_0 = func_00271A00(tbl, id);
    e->field_4 = 0;
    self->field_D4[self->field_120] = kind;
    self->field_120 = self->field_120 + 1;
}
extern "C" void func_0036B700(UnkStruct_a169 *self, bool p0)
{
    bool ignored, wmy, whb, temp, perm, f4A, f49, f48, f47;
    int pres;
    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x105, 3);
    IsBuddyIgnored__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, self->field_108, &ignored);
    IsWannaBeMyBuddy__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, self->field_108, &wmy);
    IsWannaBeHisBuddy__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, self->field_108, &whb);
    IsTemporaryBuddy__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, self->field_108, &temp);
    IsPermanentBuddy__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, self->field_108, &perm);
    GetPresence__22CGtBuddiesPS2DirtySockFPcP16EGtBuddyPresence(&D_01E3D390, self->field_108, &pres);
    func_0035F970(&D_01E3D390, self->field_108, &f4A);
    func_0035F900(&D_01E3D390, self->field_108, &f49);
    func_0035F1E0(&D_01E3D390, self->field_108, &f48);
    func_0035F9E0(&D_01E3D390, self->field_108, &f47);
    self->field_120 = 0;
    void *b = HLBListGetBuddyByName(D_01E3D4A8.field_0, self->field_108);
    int count = b ? HLBMsgListGetTotalCount(b) : 0;
    int s;
    if (count > 0) a169_add(self, &D_0051BA44, 0xC, 2);
    if (f47) {
        a169_add(self, &D_0051BA44, 0xD, 0xC);
    } else {
        if (wmy) {
            s = 0x2DA04;
            a169_add(self, &D_0051BA44, 0x11, 8);
            a169_add(self, &D_0051BA44, 0x12, 9);
            a169_add(self, &D_0051BA44, 0x13, 0xA);
        } else if (whb) {
            s = 0x2DA04;
            a169_add(self, &D_0051BA44, 0x14, 7);
        } else if (temp) {
            s = 0x2DA04;
            a169_add(self, &D_0051BA44, 0x3D, 0xB);
            a169_add(self, &D_0051BA44, 0xD, 0xC);
        } else if (perm || !p0) {
            s = 0x2DA04;
            a169_add(self, &D_0051BA44, 0xD, 6);
            a169_add(self, &D_0051BA44, 0xB, 1);
        } else {
            s = 0x2DA04;
            a169_add(self, (char *)&D_004EE040 + s, 0x3D, 0xB);
        }
        if (pres == 1 && f48) {
            a169_add(self, (char *)&D_004EE040 + s, 0xA, 0);
        }
        char *t = (char *)&D_004EE040 + s;
        a169_add(self, t, 0x3E, 3);
        if (!ignored) {
            a169_add(self, t, 0xE, 4);
        } else {
            a169_add(self, t, 0xC3F, 5);
        }
    }
    int n = self->field_120;
    self->field_60 = 0;
    self->field_62 = n;
    if (D_01E89716.field_0) ((UnkStruct_D_01E8970C *)&D_01E8970C)->vfunc_C();
    func_0039BCD0(&D_01E8970C, &self->field_60, self->field_64, 1, 0, 516.0f);
}
