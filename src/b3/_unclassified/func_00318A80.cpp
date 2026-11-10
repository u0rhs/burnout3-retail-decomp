// Hand-written; the lifter refused it (table page update; *(int*)&field_18 test (lw vs lb), separate int bi, early 'if (s2 < 0) return;' keeps the tail 'b' separate).

// Hand-written (a147).
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_gen { unsigned char pad_0[0x10]; };
struct UnkStruct_00318A80 {
    unsigned char pad_0[8];
    long field_8;
    long field_10;
    signed char field_18;
    unsigned char pad_19[3];
    int field_1C_dummy;
    int field_20;
    int field_24;
    int field_28;
    unsigned char pad_2C[4];
    int field_30;
    unsigned char field_34;
};
extern UnkStruct_D_int D_01E90424;
extern UnkStruct_D_gen D_004F50C0;
extern UnkStruct_D_gen D_01E8EC30;
extern UnkStruct_D_gen D_01E90240;
extern UnkStruct_D_gen D_01E7A800;
extern UnkStruct_D_gen D_01E8EB40;
extern "C" int AreLockedPlayersConnected__15CB3InputManagerFv(void *);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuLeft__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuRight__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBuddies__15CB3InputManagerFSc(void *, signed char);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" int func_0042BC70(void *);
extern "C" int func_0042B6A0(void *, int);
extern "C" int func_0042BC80(void *);
extern "C" long func_0042B700(void *, int);
extern "C" int func_0042DF40(long, int);
extern "C" int func_0042B5F0(void *, int);
extern "C" int func_0042C240(void *);
extern "C" void func_0042C020(void *);
extern "C" int func_0042C270(void *);
extern "C" void func_0042C090(void *);
extern "C" int func_0042C160(void *);
extern "C" void func_0042BD70(void *);
extern "C" int func_0042C1A0(void *);
extern "C" void func_0042BEA0(void *);
extern "C" int func_0042C100(void *);
extern "C" void func_0042BC90(void *);
extern "C" void func_0042AFC0(void *, int);
extern "C" void func_00283D20(void *);
extern "C" void func_0042B010(void *, long, int);
extern "C" void func_00318560(UnkStruct_00318A80 *);

// 0x00318A80
extern "C" void func_00318A80(UnkStruct_00318A80 * self)
{
    long s0 = 0;
    int s2;
    if (D_01E90424.field_0 != 5) return;
    if (AreLockedPlayersConnected__15CB3InputManagerFv(&D_004F50C0) == 0) return;
    if (*(int *)&self->field_18 != 0) s0 = -1;
    if (self->field_34 != 0) {
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, (signed char)s0) != 0) {
            if (func_0042B6A0(&D_01E8EC30, func_0042BC70(&D_01E8EC30)) != 0) {
                self->field_20 = func_0042BC80(&D_01E8EC30);
                self->field_24 = func_0042DF40(func_0042B700(&D_01E8EC30, func_0042BC70(&D_01E8EC30)), 0);
            }
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, false);
            return;
        }
    }
    if (self->field_30 <= 0) return;
    func_00318560(self);
    if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, self->field_18) != 0) {
        self->field_8 = func_0042B700(&D_01E8EC30, func_0042BC70(&D_01E8EC30));
        self->field_28 = func_0042B5F0(&D_01E8EC30, func_0042BC70(&D_01E8EC30));
        if (self->field_8 != 0) {
            if (self->field_10 == 0) {
                if (func_0042B6A0(&D_01E8EC30, func_0042BC70(&D_01E8EC30)) == 0) goto nconfirm;
            }
            if (func_0042B6A0(&D_01E8EC30, func_0042BC70(&D_01E8EC30)) != 0) {
                self->field_20 = func_0042BC80(&D_01E8EC30);
                self->field_24 = func_0042DF40(func_0042B700(&D_01E8EC30, func_0042BC70(&D_01E8EC30)), 0);
            }
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0, 0);
            return;
        }
    }
  nconfirm:
    s2 = -1;
    if (GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, self->field_18) != 0 && func_0042C240(&D_01E8EC30) != 0) {
        func_0042C020(&D_01E8EC30);
        s2 = func_0042BC70(&D_01E8EC30);
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    }
    if (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, self->field_18) != 0 && func_0042C270(&D_01E8EC30) != 0) {
        func_0042C090(&D_01E8EC30);
        s2 = func_0042BC70(&D_01E8EC30);
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    }
    if (GetMenuLeft__15CB3InputManagerFSc(&D_004F50C0, self->field_18) != 0 && func_0042C160(&D_01E8EC30) != 0) {
        func_0042BD70(&D_01E8EC30);
        s2 = func_0042BC70(&D_01E8EC30);
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    }
    if (GetMenuRight__15CB3InputManagerFSc(&D_004F50C0, self->field_18) != 0 && func_0042C1A0(&D_01E8EC30) != 0) {
        func_0042BEA0(&D_01E8EC30);
        s2 = func_0042BC70(&D_01E8EC30);
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    }
    if (GetMenuBuddies__15CB3InputManagerFSc(&D_004F50C0, self->field_18) != 0) {
        if (func_0042C100(&D_01E8EC30) != 0) {
            int bi = func_0042BC70(&D_01E8EC30);
            func_0042BC90(&D_01E8EC30);
            func_0042AFC0(&D_01E8EB40, func_0042B5F0(&D_01E8EC30, bi));
            func_00283D20(&D_01E7A800);
        }
    }
    if (s2 < 0) return;
    s0 = func_0042B700(&D_01E8EC30, s2);
    if (s0 != 0) {
        if (func_0042B6A0(&D_01E8EC30, s2) != 0) {
            func_0042B010(&D_01E8EB40, s0, func_0042B5F0(&D_01E8EC30, s2));
        } else {
            func_0042B010(&D_01E8EB40, 0, 0);
        }
    } else {
        func_0042B010(&D_01E8EB40, 0, 0);
    }
}
