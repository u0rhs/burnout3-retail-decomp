// NONMATCHING: func_0038F830 -- retail 439 / ours 439 instructions, 165 in changed runs
// a170 CB3OnlineRoadRageRaceLogic::Update [L]: 439/439 instrs, everything outside case 7 exact (case 6 scoring/finish loops, bool flags, byte-offset car list); only the 46-field D_0064EA70 -> D_01EA07D4 record copy differs in load/store scheduling (165 changed) -- same known blocker as func_0038A6C0 / func_00390D70.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a170): CB3OnlineRoadRageRaceLogic::Update (state machine; sibling of func_0038A6C0 / CB3OnlineSingleRaceLogic::Update)
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00 { unsigned char pad_0[0x10]; };
struct UnkStruct_Arr8 { int v[8]; };
struct UnkStruct_00390D70_rec {
    short field_0;
    short field_2;
    int field_4;
    int field_8;
    float field_C;
    float field_10;
    int field_14;
    int field_18;
    UnkStruct_Arr8 field_1C;
    float field_3C;
    int field_40;
    int field_44;
    float field_48;
    int field_4C;
    float field_50;
    float field_54;
    float field_58;
    float field_5C;
    float field_60;
    float field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    unsigned char field_94;
    unsigned char field_95;
    int field_98;
    int field_9C;
    unsigned char field_A0;
    unsigned char field_A1;
    unsigned char field_A2;
    int field_A4;
    int field_A8;
    float field_AC;
    float field_B0;
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    float field_C4;
};
extern UnkStruct_D_int D_01E32B08;
extern UnkStruct_00390D70_rec D_0064EA70;
extern UnkStruct_00390D70_rec D_01EA07D4;
struct UnkStruct_D_sc { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_uc { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_00516E40 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_004F50C0 { unsigned char pad_0[0x10]; };
struct UnkStruct_0038F830 {
    unsigned char pad_0[0x60];
    int field_60;
};
struct UnkStruct_car_1A88 { unsigned char pad_0[0x4EFC]; unsigned char field_4EFC; };
struct UnkStruct_car {
    unsigned char pad_0[0x10C0];
    unsigned char score[0xC];
    float field_10CC;
    unsigned char pad_10D0[0x1160 - 0x10D0];
    unsigned char field_1160;
    unsigned char pad_1161;
    unsigned char field_1162;
    unsigned char pad_1163[0x1344 - 0x1163];
    float field_1344;
    unsigned char pad_1348[0x1390 - 0x1348];
    float field_1390;
    unsigned char pad_1394[0x16C8 - 0x1394];
    int field_16C8;
    unsigned char pad_16CC[0x1760 - 0x16CC];
    unsigned char field_1760;
    unsigned char pad_1761[0x1914 - 0x1761];
    int field_1914;
    unsigned char pad_1918[0x1A88 - 0x1918];
    UnkStruct_car_1A88 * field_1A88;
};
struct UnkStruct_D_Int16 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00 D_01E32AE0, D_01E7A888, D_0066A3D0;
extern UnkStruct_D_uc D_0064FB79;
extern UnkStruct_D_sc D_004F6061;
extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_D_Int16 D_0064D37C;
extern UnkStruct_car D_0064D3B0;
extern UnkStruct_D_00 D_00522660;
extern "C" void func_0026FAA0(void *, int);
extern "C" void func_003FA600(void *, int);
extern "C" int func_00391B80(void *, int, int);
extern "C" int UpdateLaunch__19CB3OnlineStageLogicFv(void *);
extern "C" void func_00391B20(void *);
extern "C" void PrepareScoreList__13CB3HUDManagerFv(void *);
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);
extern "C" int func_00391820(void *);
extern "C" int func_003916D0(void *);
extern "C" int func_00391630(void *);
extern "C" void func_00395A40(void *);
extern "C" int func_003914A0(void *);
extern "C" void func_003906F0(void *);
extern "C" int func_00390380(void *);
extern "C" int func_003910B0(void *, int);
extern "C" int func_00150D00(void *);
extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, int);
extern "C" void AddScore__8CB3ScoreFii(void *, int, int, int);

#define CAR(i) (*(UnkStruct_car **)((char *)&D_00522660 + (i) * 4 + 0x12AD28))

// 0x0038F830
extern "C" void func_0038F830(UnkStruct_0038F830 * self)
{
    func_0026FAA0(&D_01E32AE0, 0);
    switch (self->field_60) {
    case 0:
        self->field_60 = 1;
        break;
    case 1:
        func_003FA600(&D_01E7A888, 4);
        if (func_00391B80(self, 1, 0) != 0) {
            self->field_60 = 2;
        }
        break;
    case 2:
        if (UpdateLaunch__19CB3OnlineStageLogicFv(self) != 0) {
            func_00391B20(self);
            PrepareScoreList__13CB3HUDManagerFv(&D_0066A3D0);
            if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
                self->field_60 = 3;
            } else {
                self->field_60 = 4;
            }
        }
        break;
    case 3:
        if (func_00391820(self) != 0) {
            self->field_60 = 5;
        }
        break;
    case 4:
        if (func_003916D0(self) != 0) {
            self->field_60 = 5;
        }
        break;
    case 5:
        func_00391630(self);
        break;
    case 6: {
        UnkStruct_car * const me = &D_0064D3B0;
        func_003FA600(&D_01E7A888, 5);
        func_00395A40(self);
        if (func_003914A0(self) != 0) {
            ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(18, 0);
            D_0064FB79.field_0 = 1;
            func_003906F0(self);
            self->field_60 = 7;
        }
        int i;
        bool any = false;
        for (i = 0; i < D_0064D37C.field_0; i++) {
            if (CAR(i)->field_1162 != 0) any = true;
        }
        if (any) {
            if (me->field_1160 != 0) {
                if (me->field_16C8 == 0) {
                    SetFinished__10CB3RaceCarF19EB3ScoreFinishState(me, 4);
                }
            } else if (me->field_16C8 == 0) {
                AddScore__8CB3ScoreFii(me->score, 0x5DC, -1, 3);
                SetFinished__10CB3RaceCarF19EB3ScoreFinishState(me, 5);
            }
        }
        bool s1 = true;
        for (i = 0; i < D_0064D37C.field_0; i++) {
            UnkStruct_car * c = CAR(i);
            if (c->field_1160 == 0) {
                bool ok = true;
                if (c->field_1914 == 2 && c->field_10CC > 10.0f) {
                    ok = !(c->field_1A88->field_4EFC != 0);
                }
                bool done = (c->field_16C8 == 2);
                if (ok) {
                    if (func_00150D00(c) == 0) {
                        if (!done) s1 = false;
                    }
                }
            }
        }
        if (s1) {
            if (me->field_1160 != 0) {
                if (me->field_16C8 == 0) {
                    bool t0 = true;
                    for (i = 0; i < D_0064D37C.field_0; i++) {
                        UnkStruct_car * c = CAR(i);
                        if (c->field_1760 == 0 && c->field_16C8 == 4) t0 = false;
                    }
                    if (!t0) AddScore__8CB3ScoreFii(me->score, 0x3E8, -1, 1);
                    SetFinished__10CB3RaceCarF19EB3ScoreFinishState(me, 5);
                }
            } else if (me->field_16C8 == 0) {
                SetFinished__10CB3RaceCarF19EB3ScoreFinishState(me, 4);
            }
        }
        if (me->field_1160 == 0 && me->field_10CC > 2.0f) {
            me->field_1344 = me->field_1390 - me->field_10CC;
        }
        func_00390380(self);
        break;
    }
    case 7: {
        int k = D_004F6061.field_0 * 15;
        *(short *)((char *)&D_004F50C0 + (k + k * 4) * 4 + 0xD8E) = 0;
        if (func_003910B0(self, k) != 0) {
            const UnkStruct_00390D70_rec * const p = &D_0064EA70;
            D_01EA07D4 = *p;
            self->field_60 = 8;
        }
        break;
    }
    case 8:
    default:
        break;
    }
    return;
}
