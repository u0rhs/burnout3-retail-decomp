// Hand-written; the lifter refused it (a89 + lead: switch cases 1-6, type 0 default (jump table verified)).

// Hand-written; the lifter refused it (a89: switch(0..6) jump table; case 1 returns uninitialised r (s0); type 0 is the default (lead: cases shifted after the jump-table check); float arg passes caller f12 through).

// OnRaceCarCollision__19CB3OnlineStageLogicF21ERaceCarCollisionTypeP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsf -- [L] DNAT: CB3OnlineStageLogic::OnRaceCarCollision(ERaceCarCollisionType,CB3RaceCarPhysics*,CB3RaceCarPhysics*,float) (research/proto/new_names.csv)
struct UnkStruct_00391E00_c {
    unsigned char pad_0[0x10C0];
    unsigned char field_10C0[0x334];
    void *field_13F4;
};
extern "C" void HandleNonFatalCollision__8CB3ScoreFP10CB3RaceCar(void *, void *);
extern "C" bool ConfirmGrinding__8CB3ScoreFP10CB3RaceCarP10CB3RaceCar(void *, void *);
extern "C" bool ConfirmTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(void *, void *, float, bool);
extern "C" bool ConfirmSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(void *, void *, float, bool);

// 0x00391E00
extern "C" bool OnRaceCarCollision__19CB3OnlineStageLogicF21ERaceCarCollisionTypeP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsf(void *self, unsigned int type, UnkStruct_00391E00_c *a, UnkStruct_00391E00_c *b, float f)
{
    bool r;
    switch (type) {
    case 1:
        HandleNonFatalCollision__8CB3ScoreFP10CB3RaceCar((char *)a->field_13F4 + 0x10C0, b->field_13F4);
        HandleNonFatalCollision__8CB3ScoreFP10CB3RaceCar((char *)b->field_13F4 + 0x10C0, a->field_13F4);
        return r;
    case 2:
        r = ConfirmGrinding__8CB3ScoreFP10CB3RaceCarP10CB3RaceCar(a->field_13F4, b->field_13F4);
        break;
    case 3:
        r = ConfirmTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(a, b, f, false);
        break;
    case 4:
        r = ConfirmTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(a, b, f, true);
        break;
    case 5:
        r = ConfirmSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(a, b, f, false);
        break;
    case 6:
        r = ConfirmSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(a, b, f, true);
        break;
    default:
        r = false;
        break;
    }
    return r;
}
