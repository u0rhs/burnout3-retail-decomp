// Hand-written; the lifter refused it (L262: CB3World::Update [L]; paused inline with early returns, char-array PhysicsManager member (no CSE), padded externs, Stop/else-if(!F0) Start; words identical outside relocs (retail-only %lo splat constants D_0012AD1C/D_001437F1..., checked by L262_bytecmp.py)).

// func_0019A550 -- hand-written (L262); the lifter refused it.
// [L] DNAT: CB3World::Update() (research/proto/new_names.csv, low; retail_names has the same name, high) -- the
// symbol keeps its placeholder until the lead applies names. Declarations modelled on Release__8CB3WorldFv
// (func_0019A2E0.cpp): big-offset fields, vptr at 0x1910, sub-objects passed as (char *)self + K.

enum EB3ScoreFinishState {};

struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_0019A550_obj {
    unsigned char pad_0[0x1910];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
};
struct UnkStruct_0019A550_car {
    unsigned char pad_0[0x10C0];
    short field_10C0;
    unsigned char pad_10C2[0x6];
    int field_10C8;
    unsigned char pad_10CC[0x16CC - 0x10CC];
    float field_16CC;
    unsigned char pad_16D0[0x27C0 - 0x16D0];
    int field_27C0;
    unsigned char pad_27C4[0x27D0 - 0x27C4];
};
struct UnkStruct_0019A550_rcp {
    void * field_0;
    unsigned char pad_4[0x2C];
};
struct UnkStruct_0019A550 {
    unsigned char pad_0[0x1C];
    float field_1C;
    float field_20;
    unsigned char pad_24[0x3C910 - 0x24];
    unsigned char field_3C910[0x7C];
    UnkStruct_0019A550_rcp field_3C98C[6];
    unsigned char pad_3CAAC[0x122A10 - 0x3CAAC];
    void * field_122A10[0x43];
    int field_122B1C;
    unsigned char pad_122B20[0x12AD10 - 0x122B20];
    unsigned long field_12AD10;
    unsigned char pad_12AD18[4];
    int field_12AD1C;
    unsigned char pad_12AD20[8];
    UnkStruct_0019A550_obj * field_12AD28[6];
    int field_12AD40;
    unsigned char pad_12AD44[0xC];
    UnkStruct_0019A550_car field_12AD50[8];
    unsigned char pad_end[0x1437F0 - 0x12AD50 - 8 * 0x27D0];
    unsigned char field_1437F0;
    unsigned char field_1437F1;
    unsigned char pad_1437F2;
    unsigned char field_1437F3;

    bool func_0019A550_inl1() { if (field_1437F1 || field_1437F0) return true; return false; }   // [G] placeholder: "paused" test
};

extern UnkStruct_P D_004F50C0, D_01E85900, D_01D9D200;
struct UnkStruct_D_0051BA94 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E65499 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0051BA94 D_0051BA94;
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_01E65499 D_01E65499;

extern "C" void ResetDeadInputTime__15CB3InputManagerFSc(void *, signed char);
extern "C" void func_002BC460(void *, float);
extern "C" void Update__14CB3StaticTrackFv(void *);
extern "C" bool Update__16CB3StreamedTrackFv(void *);
extern "C" void Start__8CGtTimerFv(void *);
extern "C" void Stop__8CGtTimerFv(void *);
extern "C" void Update__15CB3RacePositionFv(void *);
extern "C" void Update__16CB3TrafficSystemFv(void *);
extern "C" void Update__14CB3PropManagerFv(void *);
extern "C" void Update__11CB3GameDataFv(void *);
extern "C" void Update__17CB3PhysicsManagerFf(void *, float);
extern "C" void BeginUpdate__17CB3EffectsManagerFv(void *);
extern "C" void UpdateRaceCarEffects__17CB3EffectsManagerFP17CB3RaceCarPhysics(void *, void *);
extern "C" void UpdateCrashingTrafficEffects__17CB3EffectsManagerFP17CB3VehiclePhysics(void *, void *);
extern "C" void UpdateCollisionEffects__17CB3EffectsManagerFv(void *);
extern "C" void EndUpdate__17CB3EffectsManagerFv(void *);
extern "C" void func_00353A30(void *, float);
extern "C" void UpdateCollidingPairs__13CB3CrashComboFv();
extern "C" void PostEffectsUpdate__17CB3PhysicsManagerFv(void *);
extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, EB3ScoreFinishState);

// 0x0019A550
extern "C" void func_0019A550(UnkStruct_0019A550 * self)
{
    int i;
    if (self->func_0019A550_inl1()) {
        ResetDeadInputTime__15CB3InputManagerFSc(&D_004F50C0, 0);
        ResetDeadInputTime__15CB3InputManagerFSc(&D_004F50C0, 1);
    } else {
        func_002BC460(&D_01E85900, self->field_1C);
        Update__14CB3StaticTrackFv((char *)self + 0x12A330);
    }
    if (self->field_12AD10 == 0) return;
    if (D_0051BA94.field_0 == -1) {
        bool ok = Update__16CB3StreamedTrackFv((char *)self + 0x12A348);
        if (D_0064D3A0.field_0 == 2) {
            if (!Update__16CB3StreamedTrackFv((char *)self + 0x12A514)) ok = false;
        }
        self->field_1437F1 = !ok;
        if (self->field_1437F1) {
            Stop__8CGtTimerFv(self);
        } else if (!self->field_1437F0) {
            Start__8CGtTimerFv(self);
        }
    }
    if (self->func_0019A550_inl1()) return;
    for (i = 0; i < self->field_12AD1C; i++) {
        self->field_12AD28[i]->vfunc_C();
    }
    Update__15CB3RacePositionFv((char *)self + 0x1260D0);
    Update__16CB3TrafficSystemFv((char *)self + 0x4DE0);
    Update__14CB3PropManagerFv((char *)self + 0x1281F4);
    Update__11CB3GameDataFv((char *)self + 0x125B40);
    Update__17CB3PhysicsManagerFf(self->field_3C910, self->field_1C);
    BeginUpdate__17CB3EffectsManagerFv(&D_01D9D200);
    for (i = 0; i < self->field_12AD1C; i++) {
        UpdateRaceCarEffects__17CB3EffectsManagerFP17CB3RaceCarPhysics(&D_01D9D200, self->field_3C98C[i].field_0);
    }
    for (i = 0; i < self->field_122B1C; i++) {
        UpdateCrashingTrafficEffects__17CB3EffectsManagerFP17CB3VehiclePhysics(&D_01D9D200, self->field_122A10[i]);
    }
    UpdateCollisionEffects__17CB3EffectsManagerFv(&D_01D9D200);
    EndUpdate__17CB3EffectsManagerFv(&D_01D9D200);
    func_00353A30((char *)self + 0x128290, self->field_1C);
    func_00353A30((char *)self + 0x1292E0, self->field_1C);
    UpdateCollidingPairs__13CB3CrashComboFv();
    PostEffectsUpdate__17CB3PhysicsManagerFv(self->field_3C910);
    float lim = 1800.0f;
    if (D_01E65499.field_0) lim = 2400.0f;
    if (self->field_1437F3) return;
    if (self->field_20 <= lim) return;
    for (i = 0; i < self->field_12AD40; i++) {
        UnkStruct_0019A550_car * car = &self->field_12AD50[i];
        if (car->field_10C8 == 0) {
            car->field_10C0 = 6 - car->field_27C0;
            SetFinished__10CB3RaceCarF19EB3ScoreFinishState(car, (EB3ScoreFinishState)2);
            car->field_16CC = self->field_20;
        }
    }
}
