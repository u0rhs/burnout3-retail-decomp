// Hand-written; the lifter refused it (64-bit track-id switch (generated, reverse test order), uninit time on default; bool global for SetInfiniteBoost).

// func_0038EEE0 -- placeholder; in B3OnlineRoadRageRaceLogic.cpp's address range (after 0x0038EDF0) [L].
// Hand-written (L243): the track-id switch leaves the time uninitialised on default (retail reads f20 as left).

struct UnkStruct_0038EEE0_i { unsigned char pad_0[0x32]; unsigned char field_32; };
struct UnkStruct_0038EEE0_c {
    unsigned char pad_0[0x1160];
    unsigned char field_1160;
    unsigned char pad_1161[0x2B];
    unsigned char field_118C[0x1F8];
    int field_1384;
    unsigned char pad_1388[0x8];
    float field_1390;
};
struct UnkStruct_0038EEE0_p {
    unsigned char pad_0[0x4B8];
    UnkStruct_0038EEE0_i field_4B8;
    unsigned char pad_4EB[0x1F1];
    UnkStruct_0038EEE0_c * field_6DC;
};
struct UnkStruct_0038EEE0_vo {
    unsigned char pad_0[0x1B0];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual int vfunc_20();
};
struct UnkStruct_0038EEE0_g { UnkStruct_0038EEE0_vo * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0038EEE0_l { unsigned long field_0; unsigned long pad_8; };
struct UnkStruct_0038EEE0_b { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_0038EEE0_bo { bool field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_0038EEE0_n { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0038EEE0_P { unsigned char pad_0[0x10]; };
extern UnkStruct_0038EEE0_l D_0064D370;
extern UnkStruct_0038EEE0_g D_0051BA88;
extern UnkStruct_0038EEE0_n D_01E32B08;
extern UnkStruct_0038EEE0_P D_01E32AE0;
extern UnkStruct_0038EEE0_c D_0064D3B0;
extern UnkStruct_0038EEE0_i D_01E3D558;
extern UnkStruct_0038EEE0_b D_0064D378;
extern UnkStruct_0038EEE0_bo D_01E90225;
extern "C" UnkStruct_0038EEE0_p * func_002366D0(void *, int);
extern "C" void SetInfiniteBoost__7CB3BurnFb(void *, bool);
extern "C" void OnWorldPrepared__13CB3StageLogicFv(void *);

// 0x0038EEE0
extern "C" void func_0038EEE0(void * self)
{
    float t;
    switch (D_0064D370.field_0) {
    default:
        break;
    case 0x67E5FE5A1F1D4000UL:
    case 0x67E5FE5A1F445000UL:
        t = 180.0f;
        break;
    case 0xC4BD587D9F1D4000UL:
    case 0xC4BD587D9F445000UL:
    case 0xC4BD58A3C4BD4000UL:
    case 0xC4BD58A3C4E45000UL:
    case 0xC4BD58C9EA5D4000UL:
    case 0xC4BD58C9EA845000UL:
    case 0x67E5FEA66A5D4000UL:
    case 0x67E5FEA66A845000UL:
    case 0x67E5FECC8FFD4000UL:
    case 0x67E5FECC90245000UL:
    case 0x505305F59F1D4000UL:
    case 0x505305F59F445000UL:
    case 0x5053061BC4BD4000UL:
    case 0x5053061BC4E45000UL:
    case 0x50530641EA5D4000UL:
    case 0x50530641EA845000UL:
        t = 240.0f;
        break;
    case 0x67E5FE8044BD4000UL:
    case 0x67E5FE8044E45000UL:
        t = 300.0f;
        break;
    case 0xC4BDA5FA0C1D4000UL:
    case 0xC4BDA5FA0C445000UL:
    case 0xC4BDA62031BD4000UL:
    case 0xC4BDA62031E45000UL:
        t = 360.0f;
        break;
    case 0xC4BD9418691D4000UL:
    case 0xC4BD941869445000UL:
    case 0x67E639F4E91D4000UL:
    case 0x67E639F4E9445000UL:
    case 0x67E63A1B0EBD4000UL:
    case 0x67E63A1B0EE45000UL:
    case 0x67E64BD68C1D4000UL:
    case 0x67E64BD68C445000UL:
    case 0x67E64BFCB1BD4000UL:
    case 0x67E64BFCB1E45000UL:
    case 0x50534190691D4000UL:
    case 0x5053419069445000UL:
        t = 420.0f;
        break;
    }
    t = t * (float)D_0051BA88.field_0->vfunc_20();
    for (int i = 0; i < D_01E32B08.field_0; i++) {
        UnkStruct_0038EEE0_p * p = func_002366D0(&D_01E32AE0, i);
        UnkStruct_0038EEE0_c * c;
        UnkStruct_0038EEE0_i * in;
        if (p != 0) {
            c = p->field_6DC;
            in = &p->field_4B8;
        } else {
            c = &D_0064D3B0;
            in = &D_01E3D558;
        }
        if (in->field_32 != 0) {
            c->field_1160 = 1;
            if (D_0064D378.field_0 != 0) {
                c->field_1384 = 1;
            } else {
                c->field_1384 = -1;
            }
            SetInfiniteBoost__7CB3BurnFb(c->field_118C, D_01E90225.field_0);
        } else {
            c->field_1160 = 0;
            c->field_1390 = t;
        }
    }
    OnWorldPrepared__13CB3StageLogicFv(self);
}
