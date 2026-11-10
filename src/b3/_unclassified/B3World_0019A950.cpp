// CB3World::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3World.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (CB3World::Prepare state machine; splat-constant RELOC (equal bytes, FINISH_FORCE)).

// CB3World::Prepare() [L] DNAT (research/proto/new_names.csv, medium): init state machine on self->field_143844.
// Hand-matched (a159). Retail's %hi/%lo(D_0012AD20...) are splat-named constants (member offsets): bytes equal.
struct UnkStruct_WP_big { unsigned char pad_0[0x10]; };
struct UnkStruct_WP_flag { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_WP_int { int field_0; int pad_4[3]; };
struct UnkStruct_WP_vt { virtual void vfunc_8(); virtual void vfunc_C(); virtual const void * vfunc_10(); virtual void vfunc_14(int, int); unsigned char pad_4[0x8]; };
struct UnkStruct_WP_vcar { unsigned char pad_0[0x1910]; virtual int vfunc_8(); };
struct UnkStruct_WP_car {
    unsigned char pad_0[0x16B8];
    int field_16B8;
    unsigned char pad_16BC[0x254];
    unsigned char field_1910_vptr_pad[4];  // [G] vptr at +0x1910 (see UnkStruct_WP_vcar)
    int field_1914;
    unsigned char pad_1918[0x5C];
    unsigned short field_1974[8];
    unsigned char pad_1984[0x104];
    void * field_1A88;
    unsigned char pad_1A8C[0xD34];
    int field_27C0;
};
struct UnkStruct_WP_ent { unsigned char pad_0[0x5C1]; unsigned char field_5C1; };
extern UnkStruct_WP_flag D_01E91C3C, D_01E65499;
extern UnkStruct_WP_vt D_00516E40, D_005179F0;
extern UnkStruct_WP_big D_00665EC0, D_01E77540, D_01E32AE0, D_01E85900, D_0051A9E0, D_01E3D558, D_004EE040, D_0051BA44, D_004B7218, D_01D9D200, D_0066A3D0;
extern UnkStruct_WP_int D_01E32B08, D_0064D3A0;
struct UnkStruct_D_0051BA88_wp { void * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BA88_wp D_0051BA88;
extern "C" bool Prepare__8CGtTimerFv(void *);
extern "C" int func_00228400(void *);
extern "C" int Prepare__11CB3GameDataFv(void *);
extern "C" int Prepare__23CB3SoundGameModeManagerFv(void *);
extern "C" void * func_002366D0(void *, int);
extern "C" int func_002BCA20(void *);
extern "C" int Prepare__14CB3TrafficLaneFiUc(void *, int, unsigned char);
extern "C" int Prepare__14CB3StaticTrackFv(void *);
extern "C" int Prepare__28CB3CrashPresentationDirectorFv(void *);
extern "C" int Prepare__22CB3CrashActionDirectorFv(void *);
extern "C" int Prepare__16CB3TrafficSystemFv(void *);
extern "C" int PrepareBuffer__22CB3PlayerCameraManagerFv();
extern "C" int Prepare__16CB3StreamManagerFUl(void *, unsigned long);
extern "C" int func_00302D20(void *, int, int);
extern "C" int Prepare__14CB3PropManagerFv(void *);
extern "C" void Prepare__15CB3ReplaySystemFb(void *, unsigned char);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const void *, void *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(void *, int, const void *);
extern "C" const void * func_00271A00(void *, int);
extern "C" int GetNumStartLines__11CB3GameDataFv(void *);
extern "C" void GenerateInitialTraffic__16CB3TrafficSystemFP18CB3StartFinishLinei(void *, void *, int);
extern "C" void Prepare__17CB3EffectsManagerFv(void *);
extern "C" void Prepare__22CB3PlayerCameraManagerFv(void *);
extern "C" void SetUpTrackExtents__8CB3WorldFv(void *);
extern "C" int Prepare__15CB3RacePositionFv(void *);
extern "C" void Prepare__17CB3PhysicsManagerFv(void *);
extern "C" int Prepare__13CB3HUDManagerFv(void *);

struct UnkStruct_WP_self {
    unsigned char pad_0[0x12A6E4];
    unsigned char field_12A6E4;
    unsigned char pad_12A6E5[0x5FB];
    int field_12ACE0;
    unsigned char pad_12ACE4[0x28];
    int field_12AD0C;
    unsigned long field_12AD10;
    unsigned char pad_12AD18[0x4];
    int field_12AD1C;
    int field_12AD20;
    int field_12AD24;
    UnkStruct_WP_car * field_12AD28[2];
    unsigned char pad_12AD30[0x10];
    int field_12AD40;
    unsigned char pad_12AD44[0x27D5];
    unsigned char field_12D519;
    unsigned char pad_12D51A[0x27CF];
    unsigned char field_12FCE9;
    unsigned char pad_12FCEA[0x13B08];
    unsigned char field_1437F2;
    unsigned char field_1437F3;
    int field_1437F4;
    int field_1437F8;
    int field_1437FC;
    int field_143800;
    int field_143804;
    unsigned char pad_143808[0x38];
    unsigned char field_143840;
    unsigned char pad_143841[0x3];
    int field_143844;
};
#define F(T, K) (*(T *)((char *)self + (K)))
#define CAR(i) (self->field_12AD28[i])

// 0x0019A950
extern "C" int func_0019A950(UnkStruct_WP_self * self)
{
    int i;
    if (D_01E91C3C.field_0 != 0) return 0;
    switch (self->field_143844) {
    case 0:
    case 19: case 20: case 21: case 22:
    default:
        goto tail;
    case 1:
    case 23:
    case 24:
        ((UnkStruct_WP_vt *)&D_00516E40)->vfunc_14(0xE, 0);
        ((UnkStruct_WP_vt *)&D_005179F0)->vfunc_14(0xE, 0);
        Prepare__8CGtTimerFv(self);
        self->field_12AD20 = 0;
        self->field_143844 = 2;
    case 2:
        if (func_00228400(&D_00665EC0) == 0) return 0;
        self->field_143844 = 3;
    case 3:
        if (Prepare__11CB3GameDataFv((char *)self + 0x125B40) == 0) return 0;
        self->field_143844 = 4;
    case 4:
        if (Prepare__23CB3SoundGameModeManagerFv(&D_01E77540) == 0) return 0;
        self->field_143844 = 5;
    case 5:
        for (i = 0; i < D_01E32B08.field_0; i++) {
            UnkStruct_WP_ent * e = (UnkStruct_WP_ent *)func_002366D0(&D_01E32AE0, i);
            if (e != 0) e->field_5C1 = 1;
        }
        i = self->field_12AD20;
        if (i < self->field_12AD1C) {
            goto t5;
        l5:
            if (((UnkStruct_WP_vcar *)CAR(self->field_12AD20))->vfunc_8() == 0) return 0;
            self->field_12AD20 = self->field_12AD20 + 1;
            i++;
        t5:
            if (i < self->field_12AD1C) goto l5;
        }
        self->field_143844 = 6;
    case 6:
        if (self->field_12AD10 != 0) goto race;
        if (D_0051BA88.field_0 == &D_0051A9E0) goto tail;
        CAR(0) = (UnkStruct_WP_car *)((char *)self + 0x12FCF0);
        self->field_12AD28[1] = (UnkStruct_WP_car *)((char *)self + 0x132150);
        *((unsigned char *)CAR(0) + 0x19AC) = 0;
        *((unsigned char *)self->field_12AD28[1] + 0x19AC) = 1;
        goto tail;
    race:
        Prepare__15CB3RacePositionFv((char *)self + 0x1260D0);
        if (self->field_143840 != 0) {
            self->field_12D519 = 1;
            self->field_12FCE9 = 1;
        }
        self->field_143844 = 7;
    case 7:
        if (func_002BCA20(&D_01E85900) == 0) return 0;
        self->field_143844 = 8;
    case 8: {
        int r = 0;
        for (i = 0; i < self->field_12ACE0; i++) {
            r = Prepare__14CB3TrafficLaneFiUc((char *)self + i * 0x4C + 0x22C, r, (unsigned char)i);
        }
        self->field_143844 = 9;
    }
    case 9:
        if (Prepare__14CB3StaticTrackFv((char *)self + 0x12A330) == 0) return 0;
        self->field_143844 = 10;
    case 10:
        if (Prepare__28CB3CrashPresentationDirectorFv((char *)self + 0x3C2E0) == 0) return 0;
        self->field_143844 = 11;
    case 11:
        if (Prepare__28CB3CrashPresentationDirectorFv((char *)self + 0x3C2E0) == 0) return 0;
        self->field_143844 = 12;
    case 12:
        if (Prepare__22CB3CrashActionDirectorFv((char *)self + 0x3C2E8) == 0) return 0;
        self->field_143844 = 13;
    case 13:
        if (Prepare__16CB3TrafficSystemFv((char *)self + 0x4DE0) == 0) return 0;
        self->field_143844 = 14;
    case 14:
        if (PrepareBuffer__22CB3PlayerCameraManagerFv() == 0) return 0;
        self->field_143844 = 15;
    case 15:
        if ((unsigned char)Prepare__16CB3StreamManagerFUl((char *)self + 0x12A6E0, self->field_12AD10) == 0) return 0;
        self->field_143844 = 16;
    case 16:
        if (D_0064D3A0.field_0 == 2) {
            if ((unsigned char)func_00302D20((char *)self + 0x12A348, 1, 0) == 0) return 0;
        } else {
            if ((unsigned char)func_00302D20((char *)self + 0x12A348, 0, 0) == 0) return 0;
        }
        self->field_143844 = 17;
    case 17:
        if (D_0064D3A0.field_0 == 2) {
            if ((unsigned char)func_00302D20((char *)self + 0x12A514, 1, 1) == 0) return 0;
        }
        self->field_12A6E4 = 0;
        self->field_143844 = 18;
    case 18:
        if (Prepare__14CB3PropManagerFv((char *)self + 0x1281F4) == 0) return 0;
        self->field_143844 = 19;
    }
tail:
    Prepare__15CB3ReplaySystemFb((char *)self + 0x3C888, self->field_1437F2);
    ((UnkStruct_WP_vt *)((char *)self + 0x12A7E0))->vfunc_C();
    self->field_1437F3 = self->field_1437F2;
    self->field_12AD0C = 0;
    for (i = 0; i < self->field_12AD1C; i++) {
        UnkStruct_WP_car * c = CAR(i);
        switch (c->field_1914) {
        case 0:
            if (D_01E65499.field_0 != 0) ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&D_01E3D558, c->field_1974, 16);
            else CopyN__10CGtUnicodeFPUsiPCUs(c->field_1974, 16, (char *)&D_004EE040 + c->field_27C0 * 0x24 + 0x28DB4);
            break;
        case 1:
            CopyN__10CGtUnicodeFPUsiPCUs(c->field_1974, 16, func_00271A00(&D_0051BA44, i - self->field_12AD40 + 0x311));
            break;
        case 2:
            ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(((UnkStruct_WP_vt *)c->field_1A88)->vfunc_10(), c->field_1974, 16);
            break;
        case 3:
            ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&D_004B7218, c->field_1974, 16);
            break;
        }
    }
    if (self->field_12AD10 != 0) {
        Prepare__17CB3PhysicsManagerFv((char *)self + 0x3C910);
        Prepare__13CB3HUDManagerFv(&D_0066A3D0);
    }
    for (i = 0; i < D_01E32B08.field_0; i++) {
        UnkStruct_WP_ent * e = (UnkStruct_WP_ent *)func_002366D0(&D_01E32AE0, i);
        if (e != 0) e->field_5C1 = 0;
    }
    if (self->field_12AD10 != 0) {
        GenerateInitialTraffic__16CB3TrafficSystemFP18CB3StartFinishLinei((char *)self + 0x4DE0, (char *)self + 0x125EC8, GetNumStartLines__11CB3GameDataFv((char *)self + 0x125B40));
    }
    Prepare__17CB3EffectsManagerFv(&D_01D9D200);
    if (self->field_1437F4 == -1) self->field_1437F4 = 0;
    if (self->field_1437F8 == -1) self->field_1437F8 = 0;
    if (self->field_1437FC == -1) self->field_1437FC = 0;
    if (self->field_143800 == -1) self->field_143800 = 0;
    if (self->field_143804 == -1) self->field_143804 = 0;
    if (self->field_12AD10 != 0) {
        for (i = 0; i < self->field_12AD40; i++) Prepare__22CB3PlayerCameraManagerFv((char *)&D_004EE040 + i * 0xBB0 + 0x28E00);
    }
    self->field_12AD24 = 0;
    for (i = 0; i < self->field_12AD1C; i++) {
        if (CAR(i)->field_16B8 != 0) self->field_12AD24 = self->field_12AD24 + 1;
    }
    SetUpTrackExtents__8CB3WorldFv(self);
    self->field_143844 = 0x17;
    return 1;
}
