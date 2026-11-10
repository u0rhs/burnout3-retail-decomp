// Hand-written; the lifter refused it (a115: twin of offline OnRaceCarCollision, callee OnRaceCarCollision__19CB3OnlineStageLogicF21ERaceCarCollisionTypeP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsf).

struct UnkStruct_X_car {
    unsigned char pad_0[0x13F4];
    void * field_13F4;
};

struct UnkStruct_X {
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
    virtual void vfunc_C0();
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
    virtual void vfunc_108(void *, void *, int);
};

extern "C" bool OnRaceCarCollision__19CB3OnlineStageLogicF21ERaceCarCollisionTypeP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsf(void *, int, void *, void *, float);
extern "C" void FlapNewBodyPart__13CB3StageLogicFP10CB3RaceCar(void *, void *);

// [L] DNAT: CB3OnlineRoadRageRaceLogic::OnRaceCarCollision (research/proto/new_names.csv, low)
// 0x0038F570
extern "C" bool func_0038F570(UnkStruct_X * self, int type, UnkStruct_X_car * p1, UnkStruct_X_car * p2, float f)
{
    bool r = OnRaceCarCollision__19CB3OnlineStageLogicF21ERaceCarCollisionTypeP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsf(self, type, p1, p2, f);
    if (r != false) {
        switch (type) {
        case 1:
            self->vfunc_108(p2->field_13F4, p1->field_13F4, 5);
            break;
        case 2:
            self->vfunc_108(p2->field_13F4, p1->field_13F4, 4);
            break;
        case 3:
            self->vfunc_108(p2->field_13F4, p1->field_13F4, 2);
            break;
        case 4:
            self->vfunc_108(p2->field_13F4, p1->field_13F4, 3);
            break;
        case 5:
            self->vfunc_108(p2->field_13F4, p1->field_13F4, 0);
            FlapNewBodyPart__13CB3StageLogicFP10CB3RaceCar(self, p2->field_13F4);
            break;
        case 6:
            self->vfunc_108(p2->field_13F4, p1->field_13F4, 1);
            FlapNewBodyPart__13CB3StageLogicFP10CB3RaceCar(self, p2->field_13F4);
            break;
        }
    }
    return r;
}
