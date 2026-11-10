// Hand-written; the lifter refused it (CB3OfflineSingleCrashLogic::Update: modelled on func_00389EE0 (CGtTimer array members, byte-offset 0x12C63A to defeat CSE); n cached for score loop; s1 flag assigned before the 0x52 test; second loop var k declared after bool all).

// Hand-written (a170): CB3OfflineSingleCrashLogic::Update draft (partial)
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_uc { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_float { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_389_car {
    unsigned char pad_0[0x133C];
    int field_133C;
    float field_1340;
    unsigned char pad_1344[0x18EA - 0x1344];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x27C9 - 0x18EB];
    unsigned char field_27C9;
    unsigned char pad_27CA[6];
};
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
struct CB3OfflineSingleCrashLogic {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x3C];
    int field_40;
    float field_44;
    float field_48;
    unsigned char pad_4C[0x50 - 0x4C];
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
    unsigned char field_53;
    unsigned char field_54;
};
extern CGtTimer D_00522660;
extern UnkStruct_D_float D_00522680;
extern UnkStruct_Pad16 D_01E7A888;
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


extern UnkStruct_D_uc D_00665F2B, D_0051BAA4, D_0051BAD5, D_00665EA0, D_00665EA1;
extern UnkStruct_D_int D_0066A544, D_0064EAF8;

extern UnkStruct_Pad16 D_005179F0, D_00516E40, D_01E78E50, D_01E95854, D_00665EC0, D_0064CE40, D_01E75640, D_0066A3D0, D_01E959D0, D_01D9D200;
extern UnkStruct_D_int D_01D9D208;
extern float D_004E1058;
struct UnkStruct_D_00648704 { unsigned char pad_0[0x3AC]; int field_3AC; };
struct UnkStruct_D_00648704p { UnkStruct_D_00648704 * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00648704p D_00648704;
struct UnkStruct_vt14 { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(int, int); unsigned char pad_4[0xC]; };
extern "C" int HasIntroFinished__22CB3PlayerCameraManagerFv();
extern "C" int func_003F86F0(void *);
extern "C" void func_00445710(void *);
extern "C" void func_00276A20(void *);
extern "C" int func_00131CA0(void *);
extern "C" void func_0019E760(void *);
extern "C" void func_00255EA0(void *);
extern "C" int func_00255C50(void *);
extern "C" void SetSlowMo__8CGtTimerFi(void *, int);
extern "C" void SetMasterPitchScalar__15CB3SoundManagerFf(void *, float);
extern "C" int Prepare__13CB3HUDManagerFv(void *);
extern "C" int func_004242C0(void *);
extern "C" void func_002E6F60();
extern "C" void func_003CC770(void *);

// 0x00393940
extern "C" void func_00393940(CB3OfflineSingleCrashLogic * self)
{
    Update__20CB3OfflineStageLogicFv(self);
    int n = D_0064D37C.field_0;
    switch (self->field_40) {
    default:
        break;
    case 1:
        if (self->field_50 == 0) {
            func_003FA600(&D_01E7A888, 4);
            if (self->field_53 == 0) {
                UnkStruct_389_st * r8 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E532FEFE99EUL);
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
                self->field_53 = 1;
                self->field_54 = 0;
            }
            if (HasIntroFinished__22CB3PlayerCameraManagerFv()) {
                if (func_003F86F0(&D_01E7A888)) {
                    if (self->field_54 == 0) {
                        func_00445710(&D_01E95854);
                        self->field_54 = 1;
                    }
                }
            }
        } else {
            func_003FA600(&D_01E7A888, 6);
            if (D_0051BAA4.field_0 != 0) {
                ((UnkStruct_vt14 *)&D_00516E40)->vfunc_14(15, 0);
                ((UnkStruct_vt14 *)&D_005179F0)->vfunc_14(15, 0);
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
                self->field_40 = 2;
                self->field_50 = 0;
                func_00276A20(&D_01E78E50);
                if (func_00131CA0(&D_004EE040)) func_0019E760(&D_00665EC0);
                D_00665E50.field_0 = 1;
                if (D_00665E50.field_0 != 0) {
                    D_00522660.Stop();
                } else {
                    if (D_00665E51.field_0 == 0) {
                        D_00522660.Start();
                    }
                }
            }
        }
        break;
    case 2:
        func_003FA600(&D_01E7A888, 6);
        if (D_00665F2B.field_0 == 0) {
            D_00665F2B.field_0 = 1;
        }
        break;
    case 3: {
        func_003FA600(&D_01E7A888, 6);
        int i;
        for (i = 0; i < n; i++) {
            UnkStruct_389_car * c = D_00522660.field_12AD28[i];
            if (c->field_1340 < 0.0f) {
                c->field_1340 = 3.0f;
            }
        }
        if (self->field_52 != 0) {
            float f1 = D_00522680.field_0 - self->field_44;
            if (f1 > D_004E1058) {
                SetSlowMo__8CGtTimerFi(&D_00522660, 1);
                SetMasterPitchScalar__15CB3SoundManagerFf(&D_01E75640, 1.0f);
                self->field_44 = -1.0f;
                self->field_52 = 0;
            } else if (f1 > 0.0f) {
                SetSlowMo__8CGtTimerFi(&D_00522660, 6);
                SetMasterPitchScalar__15CB3SoundManagerFf(&D_01E75640, 0.75f);
            }
        }
        int k;
        bool all = true;
        for (k = 0; k < D_0064D3A0.field_0; k++) {
            UnkStruct_389_car * c = &D_00522660.field_12AD50[k];
            if (c->field_18EA == 0 && c->field_133C == 3) {
                ((UnkStruct_389_row *)((char *)&D_004EE040 + k * 0xBB0 + 0x28E00))->vfunc_14(18, 0);
                c->field_27C9 = 1;
            }
            if (c->field_133C != 3) all = false;
        }
        if (all) {
            bool s1 = true;
            if (D_00665E53.field_0 == 0) {
                if (D_01D9D208.field_0 == 0) {
                    func_00255EA0(&D_01D9D200);
                    s1 = false;
                } else {
                    if (func_00255C50(&D_01D9D200) == 0) s1 = false;
                }
            }
            if (s1) {
                s1 = false;
                if (self->field_52 != 0) {
                    SetSlowMo__8CGtTimerFi(&D_00522660, 1);
                    SetMasterPitchScalar__15CB3SoundManagerFf(&D_01E75640, 1.0f);
                    self->field_44 = -1.0f;
                    self->field_52 = 0;
                }
                if (D_00665E53.field_0 == 0) {
                    int j;
                    for (j = 0; j < D_0064D3A0.field_0; j++) {
                        if (*((unsigned char *)&D_00522660 + (unsigned int)j * 0x27D0 + 0x12C63A) != 0) s1 = true;
                    }
                }
                if (s1) {
                    if (D_0064EAF8.field_0 < D_00648704.field_0->field_3AC - 2) {
                        self->field_51 = 1;
                        func_003960A0(self);
                        break;
                    }
                    D_0066A544.field_0 = 0;
                    Prepare__13CB3HUDManagerFv(&D_0066A3D0);
                    self->field_40 = 4;
                    func_004242C0(&D_01E959D0);
                    func_002E6F60();
                    func_003CC770(&D_0064CE40);
                    SetSlowMo__8CGtTimerFi(&D_00522660, 1);
                    SetMasterPitchScalar__15CB3SoundManagerFf(&D_01E75640, 1.0f);
                    self->field_44 = -1.0f;
                    self->field_52 = 0;
                    D_0051BAD5.field_0 = 1;
                    if (D_00665E53.field_0 == 0) {
                        D_00665EA0.field_0 = 1;
                        D_00665EA1.field_0 = 1;
                    }
                } else {
                    self->field_48 = D_00522680.field_0;
                    self->field_40 = 5;
                }
                break;
            }
        }
        if (D_0051BA94.field_0 == -1 && D_00665E53.field_0 == 0) {
            for (signed char j = 0; j < 2; j++) {
                if (*((unsigned char *)&D_004EE040 + j * 0x24 + 0x28DD0) != 0) {
                    if (GetStartButton__15CB3InputManagerFbSc(&D_004F50C0, true, j)) {
                        D_0051BA98.field_0 = j;
                    }
                }
            }
        }
        break;
    }
    case 4:
        break;
    case 5:
        if (D_00522680.field_0 - self->field_48 > 3.0f) {
            self->field_51 = 1;
            if (D_00665E53.field_0 == 0) func_003960A0(self);
            self->field_40 = 6;
        }
        break;
    }
    for (int i = 0; i < n; i++) {
        Update__8CB3ScoreFv((char *)D_00522660.field_12AD28[i] + 0x10C0);
    }
}
