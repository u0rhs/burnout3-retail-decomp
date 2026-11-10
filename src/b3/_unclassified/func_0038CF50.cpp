// Hand-written; the lifter refused it (N182 pragma match (lead): archive source + scoped optimiser pragma).

// N182: retail compiled this function with `#pragma opt_dead_assignments off` ([G] scoped to this function).
#pragma push
#pragma opt_dead_assignments off

struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_uc { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_float { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_389_car {
    unsigned char pad_0[0x133C];
    int field_133C;
    float field_1340;
    unsigned char pad_1344[0x1485];
    unsigned char field_27C9;
    unsigned char pad_27CA[6];
};
struct UnkStruct_38CF_cb {
    unsigned char pad_0[0x18C0];
    int field_18C0;
    unsigned char pad_18C4[0xD4];
    unsigned char field_1998;
    unsigned char pad_1999[0xAC7];
};
extern UnkStruct_D_int D_0064D3A4;
extern UnkStruct_D_int D_0064D368;
extern UnkStruct_D_uc D_0064D378;
extern "C" void func_00395A40(void *);
extern "C" void SetActive__10CB3RaceCarFb(void *, bool);
struct UnkStruct_389_row {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    unsigned char pad_4[0xBAC];
};
struct UnkStruct_389_score { unsigned char pad_0[0x10C0]; };
struct UnkStruct_389_e4 { unsigned char pad_0[0x27D0]; };
struct CGtTimer {
public:
    void Start();
    void Stop();
    UnkStruct_389_e4 field_0[1];
    unsigned char pad_27D0[0x12AD28 - 0x27D0];
    UnkStruct_389_car * field_12AD28[10];
    UnkStruct_389_car field_12AD50[1];
};
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x28DD0]; unsigned char field_28DD0; unsigned char pad_1[0x23]; };
struct UnkStruct_0D_01EA2970 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_389_st { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_389_sc { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2980 { UnkStruct_389_sc * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct CB3Offline38CF50Logic {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual bool vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual void vfunc_F0();
    virtual void vfunc_F4();
    virtual void vfunc_F8();
    virtual void vfunc_FC();
    virtual void vfunc_100();
    virtual void vfunc_104();
    virtual void vfunc_108();
    virtual void vfunc_10C();
    virtual void vfunc_110();
    virtual void vfunc_114();
    unsigned char pad_4[0x1];
    unsigned char field_5;
    unsigned char pad_6[0x3A];
    int field_40;
    unsigned char pad_44[4];
    float field_48;
};
extern CGtTimer D_00522660;
extern UnkStruct_D_float D_00522680;
extern UnkStruct_Pad16 D_01E7A888;
extern UnkStruct_D_float D_0064E6F0;
extern UnkStruct_D_int D_0064D37C;
extern UnkStruct_D_int D_0064D3A0;
extern UnkStruct_D_int D_0051BA94;
extern UnkStruct_D_int D_0051BA98;
extern UnkStruct_D_uc D_00665E50;
extern UnkStruct_D_uc D_00665E51;
extern UnkStruct_D_uc D_00665E53;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_Pad16 D_004F50C0;
extern UnkStruct_0D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern "C" void Update__20CB3OfflineStageLogicFv(void *);
extern "C" void func_003FA600(void *, int);
extern "C" void func_003960A0(void *);
extern "C" void Update__8CB3ScoreFv(void *);
extern "C" int GetStartButton__15CB3InputManagerFbSc(void *, bool, signed char);
extern "C" UnkStruct_389_st * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x0038CF50
extern "C" void func_0038CF50(CB3Offline38CF50Logic * self)
{
    Update__20CB3OfflineStageLogicFv(self);
    switch (self->field_40) {
    default:
        break;
    case 1:
        func_003FA600(&D_01E7A888, 4);
        self->field_48 = -1.0f;
        if (self->field_5 == 0) {
            if (self->vfunc_C0()) {
                if (!(D_00522680.field_0 <= D_0064E6F0.field_0)) {
                    self->field_40 = 2;
                }
            }
        } else {
            UnkStruct_389_st * r8 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E497BA7576BUL);
            if (D_01EA2974.field_0 != r8) {
                ((UnkStruct_0D_01EA2970 *)&D_01EA2970)->vfunc_18(r8, 0);
                void * t0 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r8;
                UnkStruct_389_sc * t1 = D_01EA2980.field_0;
                if (t1 != 0) {
                    D_01EA2984.field_0 = t1->field_20;
                    if (r8 != 0) {
                        r8->field_8 = t1->field_20;
                    }
                }
                ((UnkStruct_0D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            }
            D_00665E50.field_0 = 1;
            if (D_00665E50.field_0 != 0) {
                D_00522660.Stop();
            } else {
                if (D_00665E51.field_0 == 0) {
                    D_00522660.Start();
                }
            }
            self->field_5 = 0;
            if (self->vfunc_C0()) {
                self->vfunc_24();
                for (int i = 0; i < D_0064D37C.field_0; i++) {
                    UnkStruct_389_car * c = D_00522660.field_12AD28[i];
                    if (c->field_1340 < 0.0f) {
                        c->field_1340 = 4.5f;
                    }
                }
            }
        }
        break;
    case 2: {
        func_003FA600(&D_01E7A888, 5);
        self->field_48 = -1.0f;
        if (!self->vfunc_C0()) {
            for (int i = 0; i < D_0064D37C.field_0; i++) {
                UnkStruct_389_car * c = D_00522660.field_12AD28[i];
                if (c->field_1340 < 0.0f) {
                    c->field_1340 = 4.5f;
                }
            }
        }
        int i;
        bool allDone = true;
        for (i = 0; i < D_0064D3A0.field_0; i++) {
            UnkStruct_389_car * c = (UnkStruct_389_car *)((char *)&D_00522660.field_0[i] + 0x12AD50);
            if (c->field_133C == 3) {
                ((UnkStruct_389_row *)((char *)&D_004EE040 + i * 0xBB0 + 0x28E00))->vfunc_14(18, 0);
                *((unsigned char *)&D_00522660 + (unsigned int)i * 0x27D0 + 0x12D519) = 1;
            } else {
                allDone = false;
            }
        }
        if (allDone) {
            self->field_40 = 3;
            func_003960A0(self);
        } else {
            func_00395A40(self);
            self->vfunc_114();
            if (D_0051BA94.field_0 == -1 && D_00665E53.field_0 == 0) {
            for (signed char j = 0; j < 2; j++) {
                if (*((unsigned char *)&D_004EE040 + j * 0x24 + 0x28DD0) != 0) {
                    if (GetStartButton__15CB3InputManagerFbSc(&D_004F50C0, true, j)) {
                        D_0051BA98.field_0 = j;
                    }
                }
            }
            }
        }
        break;
    }
    case 3:
        break;
    }
    for (int i = 0; i < D_0064D37C.field_0; i++) {
        Update__8CB3ScoreFv((char *)D_00522660.field_12AD28[i] + 0x10C0);
    }
    for (int i = 0; i < D_0064D3A4.field_0; i++) {
        UnkStruct_38CF_cb * cb = (UnkStruct_38CF_cb *)((char *)&D_00522660 + i * 0x2460 + 0x12FCF0);
        if (D_0064D378.field_0 != 0) {
            if (!(cb->field_18C0 < D_0064D368.field_0 - 20)) {
                if (cb->field_1998 != 0) {
                    SetActive__10CB3RaceCarFb(cb, false);
                }
            }
        }
    }
}

#pragma pop
