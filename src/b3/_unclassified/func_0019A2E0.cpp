// Hand-written; the lifter refused it (a84: CB3World::Release [L] DNAT; struct with big-offset fields, vptr@0x1910 virtual call, plain for loops).

// Release__8CB3WorldFv -- CB3World::Release() [L] DNAT (research/proto/new_names.csv, high)
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_0019A2E0_obj {
    unsigned char pad_0[0x1910];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
};
struct UnkStruct_0019A2E0_cam { unsigned char pad_0[0xBB0]; };
struct UnkStruct_0019A2E0 {
    unsigned char pad_0[0x12ACE0];
    int field_12ACE0;
    unsigned char pad_12ACE4[0x12AD10 - 0x12ACE4];
    unsigned long field_12AD10;
    unsigned char field_12AD18;
    unsigned char field_12AD19;
    unsigned char pad_12AD1A[2];
    int field_12AD1C;
    int field_12AD20;
    int field_12AD24;
    UnkStruct_0019A2E0_obj * field_12AD28[6];
    int field_12AD40;
    unsigned char pad_12AD44[0x143844 - 0x12AD44];
    int field_143844;
};
extern UnkStruct_P D_00665EC0, D_01E85900, D_01D9D200, D_0066A3D0, D_01E77540;
extern UnkStruct_0019A2E0_cam D_004EE040;
extern "C" void Stop__8CGtTimerFv(void *);
extern "C" void Release__11CB3GameDataFv(void *);
extern "C" void func_00228380(void *);
extern "C" void Release__22CB3PlayerCameraManagerFv(void *);
extern "C" void ReleaseBuffer__22CB3PlayerCameraManagerFv();
extern "C" void Release__15CB3RacePositionFv(void *);
extern "C" void Release__14CB3PropManagerFv(void *);
extern "C" void Release__14CB3StaticTrackFv(void *);
extern "C" void func_00302C10(void *);
extern "C" void func_003C32E0(void *);
extern "C" void Release__17CB3PhysicsManagerFv(void *);
extern "C" void Release__16CB3TrafficSystemFv(void *);
extern "C" void Release__14CB3TrafficLaneFv(void *);
extern "C" void Release__21CB3EnvironmentManagerFv(void *);
extern "C" void Release__17CB3EffectsManagerFv(void *);
extern "C" void Release__13CB3HUDManagerFv(void *);
extern "C" void Release__23CB3SoundGameModeManagerFv(void *);

// [L] DNAT: CB3World::Release() (research/proto/new_names.csv, high)
// 0x0019A2E0
extern "C" void Release__8CB3WorldFv(UnkStruct_0019A2E0 * self)
{
    int i;
    self->field_143844 = 0x18;
    Stop__8CGtTimerFv(self);
    for (i = 0; i < self->field_12AD1C; i++) {
        self->field_12AD28[i]->vfunc_10();
    }
    for (i = 0; i < 6; i++) {
        self->field_12AD28[i] = 0;
    }
    self->field_12AD1C = 0;
    self->field_12AD24 = 0;
    Release__11CB3GameDataFv((char *)self + 0x125B40);
    func_00228380(&D_00665EC0);
    if (self->field_12AD10 != 0) {
        for (i = 0; i < *(int *)((char *)self + 0x12AD40); i++) {
            Release__22CB3PlayerCameraManagerFv((char *)&D_004EE040 + i * 0xBB0 + 0x28E00);
        }
        ReleaseBuffer__22CB3PlayerCameraManagerFv();
        Release__15CB3RacePositionFv((char *)self + 0x1260D0);
        Release__14CB3PropManagerFv((char *)self + 0x1281F4);
        Release__14CB3StaticTrackFv((char *)self + 0x12A330);
        func_00302C10((char *)self + 0x12A348);
        func_00302C10((char *)self + 0x12A514);
        func_003C32E0((char *)self + 0x12A6E0);
        *(int *)((char *)self + 0x12A7D8) = 0;
        *(int *)((char *)self + 0x12A7DC) = 0;
        self->field_12AD10 = 0;
        self->field_12AD18 = 0;
        self->field_12AD19 = 0;
        Release__17CB3PhysicsManagerFv((char *)self + 0x3C910);
        Release__16CB3TrafficSystemFv((char *)self + 0x4DE0);
        for (i = 0; i < self->field_12ACE0; i++) {
            Release__14CB3TrafficLaneFv((char *)self + i * 76 + 0x22C);
        }
        Release__21CB3EnvironmentManagerFv(&D_01E85900);
        Release__17CB3EffectsManagerFv(&D_01D9D200);
        Release__13CB3HUDManagerFv(&D_0066A3D0);
        Release__23CB3SoundGameModeManagerFv(&D_01E77540);
    }
}
