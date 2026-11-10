// Hand-written; the lifter refused it (a130: CB3OfflineSingleRaceLogic::OnRaceCarCollision (DNAT high); table index=type (0=default), bool r declared before bool a, case 1 sets only r, f12 passes f through).

struct UnkStruct_00389830_car {
    unsigned char pad_0[0x10C0];
    unsigned char field_10C0[0x124];
    unsigned char field_11E4[0x730];
    int field_1914;
};
struct UnkStruct_00389830_ph {
    unsigned char pad_0[0x13F4];
    UnkStruct_00389830_car * field_13F4;
};
struct UnkStruct_00389830 {
    unsigned char pad_0[0x45];
    unsigned char field_45;
    signed char field_46;
};
extern "C" void HandleNonFatalCollision__8CB3ScoreFP10CB3RaceCar(void *, void *);
extern "C" bool ConfirmGrinding__8CB3ScoreFP10CB3RaceCarP10CB3RaceCar(void *, void *);
extern "C" bool ConfirmTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(void *, void *, float, bool);
extern "C" bool ConfirmSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(void *, void *, float, bool);
extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, int, int, int, bool);
// 0x00389830
extern "C" bool func_00389830(UnkStruct_00389830 *self, int type, UnkStruct_00389830_ph *p1, UnkStruct_00389830_ph *p2, float f)
{
    bool r;
    bool a = false;
    switch (type) {
    case 1:
        HandleNonFatalCollision__8CB3ScoreFP10CB3RaceCar(p1->field_13F4->field_10C0, p2->field_13F4);
        HandleNonFatalCollision__8CB3ScoreFP10CB3RaceCar(p2->field_13F4->field_10C0, p1->field_13F4);
        r = true;
        break;
    case 2:
        r = ConfirmGrinding__8CB3ScoreFP10CB3RaceCarP10CB3RaceCar(p1->field_13F4, p2->field_13F4);
        break;
    case 3:
        r = ConfirmTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(p1, p2, f, false);
        break;
    case 4:
        r = ConfirmTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(p1, p2, f, true);
        break;
    case 5:
        r = ConfirmSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(p1, p2, f, false);
        if (p2->field_13F4->field_1914 == 0) {
            a = true;
        } else {
            self->field_45 = 0;
        }
        break;
    case 6:
        r = ConfirmSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(p1, p2, f, true);
        if (p2->field_13F4->field_1914 == 0) {
            a = true;
        } else {
            self->field_45 = 0;
        }
        break;
    case 0:
    default:
        r = false;
    }
    if (self->field_45 != 0 && a && r) {
        self->field_46 = self->field_46 + 1;
        if (self->field_46 == 2) {
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(p2->field_13F4->field_11E4, 0x90, 0, -1, false);
            self->field_45 = 0;
        }
    }
    return r;
}
