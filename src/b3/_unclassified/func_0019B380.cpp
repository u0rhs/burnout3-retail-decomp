// Hand-written; the lifter refused it (diff_vs_retail lui-mask symmetry fix (a83)).

// Hand-written; the lifter refused it (a83: CB3World::Construct [L] DNAT; N24 goto entry-jump loops).

// Construct__8CB3WorldFv -- CB3World::Construct() [L] DNAT (research/proto/new_names.csv, medium)
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_0019B380_ent { int field_0; int field_4; };
struct UnkStruct_0019B380_a { unsigned char pad_0[0x27D0]; };
struct UnkStruct_0019B380_b { unsigned char pad_0[0x2460]; };
struct UnkStruct_0019B380_c { unsigned char pad_0[0x1AA0]; };
struct UnkStruct_0019B380_vt {
    virtual void vfunc_8();
};
struct UnkStruct_0019B380 {
    unsigned char pad_0[0x28];
    UnkStruct_0019B380_ent field_28[0x40];
    unsigned char pad_228[0x12AD10 - 0x228];
    unsigned long field_12AD10;
    unsigned char field_12AD18;
    unsigned char field_12AD19;
    unsigned char pad_12AD1A[2];
    int field_12AD1C;
    int field_12AD20;
    int field_12AD24;
    void * field_12AD28[6];
    int field_12AD40;
    int field_12AD44;
    int field_12AD48;
    unsigned char pad_12AD4C[4];
    UnkStruct_0019B380_a field_12AD50[2];
    UnkStruct_0019B380_b field_12FCF0[5];
    UnkStruct_0019B380_c field_13B2D0[5];
    unsigned char pad_1437F2_[0x1437F2 - 0x13B2D0 - 5 * 0x1AA0];
    unsigned char field_1437F2;
    unsigned char field_1437F3;
    int field_1437F4;
    int field_1437F8;
    int field_1437FC;
    int field_143800;
    int field_143804;
    unsigned char pad_143808[0x143840 - 0x143808];
    unsigned char field_143840;
    unsigned char field_143841;
    unsigned char pad_143842[2];
    int field_143844;
};
struct UnkStruct_0019B380_g { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_P D_01D9D200, D_01E85900, D_0066A3D0;
extern "C" void Construct__14CB3StaticTrackFv(void *);
extern "C" void Construct__16CB3StreamedTrackFv(void *);
extern "C" void Construct__16CB3StreamManagerFv(void *);
extern "C" void Construct__16CB3TrafficSystemFv(void *);
extern "C" void Construct__28CB3CrashPresentationDirectorFv(void *);
extern "C" void Construct__22CB3CrashActionDirectorFv(void *);
extern "C" void Construct__15CB3ReplaySystemFv(void *);
extern "C" void Construct__17CB3PhysicsManagerFv(void *);
extern "C" void Construct__11CB3GameDataFv(void *);
extern "C" void Construct__15CB3RacePositionFv(void *);
extern "C" void Construct__14CB3PropManagerFv(void *);
extern "C" void Construct__16CB3CrashAnalyserFv(void *);
extern "C" void Construct__12CB3PlayerCarFi(void *, int);
extern "C" void Construct__8CB3AICarFi(void *, int);
extern "C" void Construct__13CB3NetworkCarFi(void *, int);
extern "C" void Construct__17CB3EffectsManagerFv(void *);
extern "C" void Construct__21CB3EnvironmentManagerFv(void *);
extern "C" void Construct__8CGtTimerFv(void *);
extern "C" void Construct__13CB3HUDManagerFv(void *);


// [L] DNAT: CB3World::Construct() (research/proto/new_names.csv, medium)
// 0x0019B380
extern "C" void Construct__8CB3WorldFv(UnkStruct_0019B380 * self)
{
    int i;
    self->field_12AD10 = 0;
    self->field_12AD18 = 0;
    self->field_12AD19 = 0;
    self->field_12AD1C = 0;
    self->field_12AD24 = 0;
    Construct__14CB3StaticTrackFv((char *)self + 0x12A330);
    Construct__16CB3StreamedTrackFv((char *)self + 0x12A348);
    Construct__16CB3StreamedTrackFv((char *)self + 0x12A514);
    Construct__16CB3StreamManagerFv((char *)self + 0x12A6E0);
    *(int *)((char *)self + 0x12A7D8) = 0;
    *(int *)((char *)self + 0x12A7DC) = 0;
    Construct__16CB3TrafficSystemFv((char *)self + 0x4DE0);
    Construct__28CB3CrashPresentationDirectorFv((char *)self + 0x3C2E0);
    Construct__22CB3CrashActionDirectorFv((char *)self + 0x3C2E8);
    Construct__15CB3ReplaySystemFv((char *)self + 0x3C888);
    Construct__17CB3PhysicsManagerFv((char *)self + 0x3C910);
    Construct__11CB3GameDataFv((char *)self + 0x125B40);
    Construct__15CB3RacePositionFv((char *)self + 0x1260D0);
    Construct__14CB3PropManagerFv((char *)self + 0x1281F4);
    ((UnkStruct_0019B380_vt *)((char *)self + 0x12A7E0))->vfunc_8();
    Construct__16CB3CrashAnalyserFv((char *)self + 0x128290);
    Construct__16CB3CrashAnalyserFv((char *)self + 0x1292E0);
    for (i = 0; i < 6; i++) {
        self->field_12AD28[i] = 0;
    }
    for (i = 0; i < 0x40; i++) {
        self->field_28[i].field_4 = i;
    }
    self->field_12AD40 = 1;
    self->field_12AD44 = 0;
    self->field_12AD48 = 0;
    self->field_1437F3 = 0;
    self->field_1437F2 = 0;
    self->field_143840 = 0;
    self->field_143841 = 0;
    // [G] goto: N24 entry-jump loop (approved 2026-10-23)
    i = 0;
    goto pl_test;
pl_body:
    Construct__12CB3PlayerCarFi(&self->field_12AD50[i], i);
    i++;
pl_test:
    if (i < 2) goto pl_body;
    // [G] goto: N24 entry-jump loop (approved 2026-10-23)
    i = 0;
    goto ai_test;
ai_body:
    Construct__8CB3AICarFi(&self->field_12FCF0[i], i);
    i++;
ai_test:
    if (i < 5) goto ai_body;
    // [G] goto: N24 entry-jump loop (approved 2026-10-23)
    i = 0;
    goto ot_test;
ot_body:
    Construct__13CB3NetworkCarFi(&self->field_13B2D0[i], i);
    i++;
ot_test:
    if (i < 5) goto ot_body;
    self->field_1437F4 = -1;
    self->field_1437F8 = -1;
    self->field_1437FC = -1;
    self->field_143800 = -1;
    self->field_143804 = -1;
    Construct__17CB3EffectsManagerFv(&D_01D9D200);
    Construct__21CB3EnvironmentManagerFv(&D_01E85900);
    Construct__8CGtTimerFv(self);
    Construct__13CB3HUDManagerFv(&D_0066A3D0);
    self->field_143844 = 1;
}
