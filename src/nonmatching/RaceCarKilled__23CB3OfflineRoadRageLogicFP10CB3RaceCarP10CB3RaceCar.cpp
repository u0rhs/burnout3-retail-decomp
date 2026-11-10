// NONMATCHING: RaceCarKilled__23CB3OfflineRoadRageLogicFP10CB3RaceCarP10CB3RaceCar -- retail 142 / ours 142 instructions, 6 in changed runs
// near34: LOGIC FIX case 0 -> idx=1 (retail reuses compare const a0=1; old archive passed the pointer), default+case 4 first (dead li v0,4), field_11F5 bool, loop car a fresh local c, i declared before pts. Left: v0/v1 swap in the field_6C[i] != field_1134 compare (6)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)





struct UnkStruct_0038C120_p { unsigned char pad_0[8]; int field_8; };
struct UnkStruct_0038C120_car {
    unsigned char pad_0[0x10C0];
    unsigned char field_10C0[8];
    int field_10C8;
    unsigned char pad_10CC[0x5C];
    int field_1128;
    int field_112C;
    unsigned char pad_1130[4];
    int field_1134;
    unsigned char pad_1138[8];
    UnkStruct_0038C120_p * field_1140;
    unsigned char pad_1144[0xA0];
    unsigned char field_11E4[0x11];
    bool field_11F5;
    unsigned char pad_11F6[0x4BE];
    float field_16B4;
    int field_16B8;
    unsigned char pad_16BC[0x258];
    int field_1914;
};
struct UnkStruct_0038C120 {
    unsigned char pad_0[0x4C];
    unsigned char field_4C;
    unsigned char pad_4D[0x1F];
    int field_6C[8];
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0055D7FE { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055D7FE D_0055D7FE;
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern "C" int gmanRoadRageTakedownBP__8CB3Score[8];
extern "C" void SetNumLives__8CB3ScoreFi(void *, int);
extern "C" void DecrementHealth__8CB3ScoreFf(void *, float);
extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, int);
extern "C" void SetSlowMo__8CGtTimerFi(void *, int);
extern "C" void AddScore__8CB3ScoreFii(void *, int, int, int);
extern "C" void OnMedal__13CB3ScoreBonusF17EB3ScoreMedalTypei(void *, int, int);
extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, int, int, int, bool);
static inline int func_0038C120_min(int a, int b)
{
    int r;
    asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int func_0038C120_zx(int a)
{
    unsigned int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}
// 0x0038C120
extern "C" void RaceCarKilled__23CB3OfflineRoadRageLogicFP10CB3RaceCarP10CB3RaceCar(UnkStruct_0038C120 *self, UnkStruct_0038C120_car *car, UnkStruct_0038C120_car *killer)
{
    int i;
    int pts;
    int lives = car->field_16B8;
    if (lives != -1 && lives > 0) {
        SetNumLives__8CB3ScoreFi(car->field_10C0, lives - 1);
    }
    DecrementHealth__8CB3ScoreFf(car->field_10C0, 1.0f);
    if (car->field_16B8 != 0) {
        car->field_16B4 = 1.0f;
        return;
    }
    if (car->field_1914 == 0) {
        if (self->field_4C == 0) {
            return;
        }
        if (car->field_10C8 == 0) {
            if (car->field_1134 == 4) {
                SetFinished__10CB3RaceCarF19EB3ScoreFinishState(car, 4);
            } else {
                SetFinished__10CB3RaceCarF19EB3ScoreFinishState(car, 5);
            }
        }
        SetSlowMo__8CGtTimerFi(&D_00522660, 5);
        D_0055D7FE.field_0 = 1;
    }
    if (killer != 0) {
        killer->field_112C = killer->field_112C + 1;
    }
    for (i = 0; i < D_0064D3A0.field_0; i++) {
        UnkStruct_0038C120_car *c = (UnkStruct_0038C120_car *)((char *)&D_00522660 + i * 0x27D0 + 0x12AD50);
        if (c->field_16B8 != 0 && killer == c) {
            pts = 0;
            int idx = (int)c->field_1140;
            if (idx != 0) {
                switch (c->field_1134) {
                default:
                case 4:
                    idx = 0;
                    break;
                case 0:
                    idx = 1;
                    break;
                case 1:
                    idx = 2;
                    break;
                case 2:
                    idx = func_0038C120_zx(func_0038C120_min(c->field_1128 - ((UnkStruct_0038C120_p *)idx)->field_8 + 3, 7));
                    break;
                }
                pts = gmanRoadRageTakedownBP__8CB3Score[idx];
                AddScore__8CB3ScoreFii(c->field_10C0, pts, 2, 0);
                if (c->field_1134 != self->field_6C[i]) {
                    self->field_6C[i] = c->field_1134;
                    OnMedal__13CB3ScoreBonusF17EB3ScoreMedalTypei(c->field_11E4, c->field_1134, 0);
                }
            }
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(c->field_11E4, 0x85, pts, 2, c->field_11F5);
        }
    }
}




