// NONMATCHING: Prepare__17CB3PhysicsManagerFv -- retail 650 / ours 650 instructions, 23 in changed runs
// a159: 650/650 instrs, 23 changed; logic+layout complete (PCID init, goto entry loops, spills). Left: s-register naming in the traffic-body init loops (retail ptr=s5,outer=s2,mid=s3,cnt=s6,idx=s4; ours ptr=s6,outer=s5,mid=s2,cnt=s3; all 720 declaration permutations of ptr/s7/s4/s2/s3/s1 tried) and body-address mult order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// a159: CB3PhysicsManager::Prepare()
struct UnkStruct_PP_vt {
    virtual int vfunc_8();
    virtual int vfunc_C();
    virtual int vfunc_10();
    virtual int vfunc_14();
    virtual int vfunc_18();
    virtual int vfunc_1C();
    virtual int vfunc_20();
    virtual int vfunc_24();
    virtual int vfunc_28();
    virtual int vfunc_2C();
    virtual int vfunc_30();
    virtual int vfunc_34();
    virtual int vfunc_38();
    virtual int vfunc_3C();
    virtual int vfunc_40();
    virtual int vfunc_44();
    virtual int vfunc_48();
    virtual int vfunc_4C();
    virtual int vfunc_50();
    virtual int vfunc_54();
    virtual int vfunc_58();
    virtual int vfunc_5C();
    virtual int vfunc_60();
    virtual int vfunc_64();
    virtual int vfunc_68();
    virtual int vfunc_6C();
    virtual int vfunc_70();
    virtual int vfunc_74();
    virtual int vfunc_78();
    virtual int vfunc_7C();
    virtual int vfunc_80();
    virtual int vfunc_84();
    virtual int vfunc_88();
    virtual int vfunc_8C();
    virtual int vfunc_90();
    virtual int vfunc_94();
    virtual int vfunc_98();
    virtual int vfunc_9C();
    virtual int vfunc_A0();
    virtual int vfunc_A4();
    virtual int vfunc_A8();
    virtual int vfunc_AC();
    virtual int vfunc_B0();
    virtual int vfunc_B4();
    virtual int vfunc_B8();
    virtual int vfunc_BC();
};
struct UnkStruct_PP_pc { unsigned char pad_0[0xCC8]; int field_CC8[6]; unsigned char pad_CE0[0x4590 - 0xCE0]; };
struct UnkStruct_PP_nc { unsigned char pad_0[0xCC8]; int field_CC8[6]; unsigned char pad_CE0[0x1580 - 0xCE0]; };
struct UnkStruct_PP_ai { unsigned char pad_0[0xCC8]; int field_CC8[6]; unsigned char pad_CE0[0x1560 - 0xCE0]; };
struct UnkStruct_PP_tr { unsigned char pad_0[0xCC8]; int field_CC8[6]; unsigned char pad_CE0[0x2430 - 0xCE0]; };
struct UnkStruct_PP_prop { unsigned char pad_0[0x780]; };
struct UnkStruct_PP_part { unsigned char pad_0[0x4E0]; };
struct UnkStruct_PP_row { unsigned char field_0[6]; unsigned char pad_6[10]; };
struct UnkStruct_PP_body { signed char field_0; unsigned char field_1; unsigned char field_2; unsigned char pad_3; void * field_4; void * field_8; void * field_C; unsigned char pad_10[0x20]; };
struct UnkStruct_PP_el { unsigned short field_0; unsigned char field_2; unsigned char pad_3; };
struct UnkStruct_PP_a854 { unsigned char pad_0[0x12]; unsigned char field_12; unsigned char pad_13; unsigned char ** field_14; UnkStruct_PP_el *** field_18; };
struct UnkStruct_PP_a858 { char * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_PP_c994_in { unsigned char pad_0[0x3C]; unsigned char * field_3C; unsigned char pad_40[0x14]; short field_54; };
struct UnkStruct_PP_c994 { UnkStruct_PP_c994_in * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_PP_big { unsigned char pad_0[0x10]; };
struct UnkStruct_PP_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_PP_ent { unsigned char pad_0[0x6E0]; void * field_6E0; };
struct UnkStruct_PP_ba88_in { unsigned char pad_0[0x1B4]; UnkStruct_PP_vt * field_1B4; };
struct UnkStruct_PP_x { unsigned char pad_0[0x216]; signed char field_216; };
struct UnkStruct_D_0051BA88_pp { UnkStruct_PP_ba88_in * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_PP_rc { unsigned char pad_0[0x27D0]; };
extern UnkStruct_PP_a854 D_0064A854;
extern UnkStruct_PP_a858 D_0064A858;
extern UnkStruct_PP_c994 D_0064C994;
extern UnkStruct_PP_i D_00645170;
extern UnkStruct_PP_x D_0057BAF0;
extern UnkStruct_PP_big D_0064C9A8, D_004EE040, D_01E32AE0;
extern UnkStruct_D_0051BA88_pp D_0051BA88;
extern UnkStruct_PP_i D_0064D3A0, D_0064D3A4, D_0064D3A8;
extern UnkStruct_PP_rc D_00522660[];
extern int D_004E15BC;
extern int _gnSortingPCID;
extern int _gnSortAlgPCID;
extern int _gnIntervalPCID;
extern int _gnWorldCollisionPCID;
extern int _gnBodyCollisionPCID;
extern int _gnBodyUpdatePCID;
extern int _gnBodyUpdatePlayerCarPCID;
extern int _gnBodyUpdateNetworkCarPCID;
extern int _gnBodyUpdateAICarPCID;
extern int _gnBodyUpdateTrafficCarPCID;
extern int _gnBodyUpdatePropPCID;
extern int _gnBodyUpdateBodyPartsPCID;
extern int _gnClipPolyWithConvexHullPCID;
extern int _gnBoxWorldCollisionPCID;
extern int _gnBoxBoxCollisionPCID;
extern int _gnHullWorldCollisionPCID;
extern int D_004E15D8;
extern int D_004E15DC;
extern int D_004E15E0;
extern int D_004E1614;
extern int D_004E1608;
extern int D_004E160C;
extern int D_004E1610;
extern int D_004E1618;
extern int D_004E1624;
extern int D_004E161C;
extern int D_004E1620;

extern "C" void * memset(void *, int, unsigned long);
extern "C" void Prepare__17CB3TrafficPhysicsFv(void *);
extern "C" void Construct__14CB3PropPhysicsFv(void *);
extern "C" void Construct__18CB3BodyPartPhysicsFv(void *);
extern "C" void AddRaceCar__17CB3PhysicsManagerFP10CB3RaceCari(void *, void *, int);
extern "C" UnkStruct_PP_ent * func_002366D0(void *, int);
extern "C" int func_00131E40(void *);
extern "C" int GetUnitOriginalID__16CB3StreamedTrackFi(void *, int);
extern "C" void GetIntervals__17CB3PhysicsManagerFP13CB3ActiveBody(void *, void *);
extern "C" void func_001B7E10(void *, int);

class CB3PhysicsManager {
public:
    int Prepare();
    UnkStruct_PP_row field_0[6];
    unsigned char field_60[6];
    unsigned char pad_66[0xA];
    UnkStruct_PP_body field_70[1];
    unsigned char pad_A0[0xE5F0 - 0xA0];
    unsigned char field_E5F0[1];
    unsigned char pad_E5F1[0x1CB70 - 0xE5F1];
    int field_1CB70;
    int field_1CB74;
    unsigned char pad_1CB78[8];
    UnkStruct_PP_pc field_1CB80[2];
    UnkStruct_PP_nc field_256A0[5];
    UnkStruct_PP_ai field_2C220[5];
    UnkStruct_PP_tr field_32D00[0x40];
    UnkStruct_PP_prop field_C3900[0x20];
    UnkStruct_PP_part field_D2900[0x40];
    int field_E6100[0x40];
    int field_E6200;
    int field_E6204;
    int field_E6208;
    int field_E620C;
    unsigned char field_E6210[1];
    unsigned char pad_E6211[0xE9210 - 0xE6211];
    int field_E9210;
    unsigned char pad_E9214[4];
    unsigned long field_E9218;
    unsigned long field_E9220;
    unsigned char field_E9228[4];
};

int CB3PhysicsManager::Prepare()
{
    if (D_004E15BC == -1) D_004E15BC = 0;
    if (_gnSortingPCID == -1) _gnSortingPCID = 0;
    if (_gnSortAlgPCID == -1) _gnSortAlgPCID = 0;
    if (_gnIntervalPCID == -1) _gnIntervalPCID = 0;
    if (_gnWorldCollisionPCID == -1) _gnWorldCollisionPCID = 0;
    if (_gnBodyCollisionPCID == -1) _gnBodyCollisionPCID = 0;
    if (_gnBodyUpdatePCID == -1) _gnBodyUpdatePCID = 0;
    if (_gnBodyUpdatePlayerCarPCID == -1) _gnBodyUpdatePlayerCarPCID = 0;
    if (_gnBodyUpdateNetworkCarPCID == -1) _gnBodyUpdateNetworkCarPCID = 0;
    if (_gnBodyUpdateAICarPCID == -1) _gnBodyUpdateAICarPCID = 0;
    if (_gnBodyUpdateTrafficCarPCID == -1) _gnBodyUpdateTrafficCarPCID = 0;
    if (_gnBodyUpdatePropPCID == -1) _gnBodyUpdatePropPCID = 0;
    if (_gnBodyUpdateBodyPartsPCID == -1) _gnBodyUpdateBodyPartsPCID = 0;
    if (_gnClipPolyWithConvexHullPCID == -1) _gnClipPolyWithConvexHullPCID = 0;
    if (_gnBoxWorldCollisionPCID == -1) _gnBoxWorldCollisionPCID = 0;
    if (_gnBoxBoxCollisionPCID == -1) _gnBoxBoxCollisionPCID = 0;
    if (_gnHullWorldCollisionPCID == -1) _gnHullWorldCollisionPCID = 0;
    if (D_004E15D8 == -1) D_004E15D8 = 0;
    if (D_004E15DC == -1) D_004E15DC = 0;
    if (D_004E15E0 == -1) D_004E15E0 = 0;
    if (D_004E1614 == -1) D_004E1614 = 0;
    if (D_004E1608 == -1) D_004E1608 = 0;
    if (D_004E160C == -1) D_004E160C = 0;
    if (D_004E1610 == -1) D_004E1610 = 0;
    if (D_004E1618 == -1) D_004E1618 = 0;
    if (D_004E1624 == -1) D_004E1624 = 0;
    if (D_004E161C == -1) D_004E161C = 0;
    if (D_004E1620 == -1) D_004E1620 = 0;

    int a;
    int b;
    a = 0;
    goto t1;
    l1: for (b = 0; b < 6; b++) field_1CB80[a].field_CC8[b] = 0;
    a++;
    t1: if (a < 2) goto l1;
    a = 0;
    goto t2;
    l2: for (b = 0; b < 6; b++) field_256A0[a].field_CC8[b] = 0;
    a++;
    t2: if (a < 5) goto l2;
    a = 0;
    goto t3;
    l3: for (b = 0; b < 6; b++) field_2C220[a].field_CC8[b] = 0;
    a++;
    t3: if (a < 5) goto l3;
    for (a = 0; a < 0x40; a++) for (b = 0; b < 6; b++) field_32D00[a].field_CC8[b] = 0;
    for (a = 0; a < 4; a++) field_E9228[a] = 0xFF;
    field_1CB70 = 0;
    field_1CB74 = 0;
    field_E9210 = 0;
    field_E6200 = 0;
    field_E6204 = 0;
    field_E6208 = 0;
    field_E620C = 0;
    memset(&field_70, 0, 0xE580);
    memset(&field_E5F0, 0, 0xE580);
    memset(&field_E6210, 0, 0x3000);
    for (int i = 0; i < 0x40; i++) Prepare__17CB3TrafficPhysicsFv(&field_32D00[i]);
    for (int i = 0; i < 0x40; i++) field_E6100[i] = 0;
    field_E9218 = 0;
    field_E9220 = 0;
    for (int i = 0; i < 0x20; i++) Construct__14CB3PropPhysicsFv(&field_C3900[i]);
    for (int i = 0; i < 0x40; i++) Construct__18CB3BodyPartPhysicsFv(&field_D2900[i]);
    a = 0;
    goto t4;
    l4:
    field_60[a] = 0;
    for (b = 0; b < 6; b++) field_0[a].field_0[b] = 0;
    a++;
    t4: if (a < 6) goto l4;
    field_E6200 = D_0064D3A0.field_0;
    for (int i = 0; i < field_E6200; i++) {
        char * car = (char *)&D_00522660[i] + 0x12AD50;
        AddRaceCar__17CB3PhysicsManagerFP10CB3RaceCari(this, car, i);
        *(void **)(car + 0x2430) = &field_1CB80[i];
        field_1CB70 = field_1CB70 + 1;
    }
    field_E6204 = D_0064D3A4.field_0;
    for (int i = 0; i < field_E6204; i++) {
        char * car = (char *)&D_00522660[0] + i * 0x2460 + 0x12FCF0;
        AddRaceCar__17CB3PhysicsManagerFP10CB3RaceCari(this, car, i);
        *(void **)(car + 0x2430) = &field_256A0[i];
        field_1CB70 = field_1CB70 + 1;
    }
    field_E6208 = D_0064D3A8.field_0;
    for (int i = 0; i < field_E6208; i++) {
        char * car = (char *)&D_00522660[0] + i * 0x1AA0 + 0x13B2D0;
        AddRaceCar__17CB3PhysicsManagerFP10CB3RaceCari(this, car, i);
        UnkStruct_PP_ent * en = func_002366D0(&D_01E32AE0, *(signed char *)(car + 0x19AC));
        en->field_6E0 = (char *)this + i * 0x1560 + 0x2C220;
        field_1CB70 = field_1CB70 + 1;
    }
    if (D_0051BA88.field_0->field_1B4->vfunc_B8() == 0) {
        UnkStruct_PP_a854 * s5 = &D_0064A854;
        int s2;
        int s7;
        int s4;
        if (func_00131E40(&D_004EE040) != 0) {
            s7 = 0x13;
            UnkStruct_PP_x * v = 0 < D_00645170.field_0 ? &D_0057BAF0 : 0;
            int idx = GetUnitOriginalID__16CB3StreamedTrackFi(&D_0064C9A8, v->field_216);
            if (idx <= 0) s4 = D_0064C994.field_0->field_54 - 1;
            else s4 = idx - 1;
        } else {
            s4 = 0;
            s7 = D_0064C994.field_0->field_54;
        }
        s2 = 0;
        goto ts2;
      ls2:
        {
            UnkStruct_PP_a858 * p858 = &D_0064A858;
            int fp = s4 << 2;
            UnkStruct_PP_c994 * p994 = &D_0064C994;
            int * cnt = &field_1CB70;
            for (int s3 = 0; s3 < s5->field_12; s3++) {
                int s3x4 = s3 << 2;
                for (int s1 = 0; s1 < *(unsigned char *)(*(int *)(fp + (int)s5->field_14) + s3); s1++) {
                    UnkStruct_PP_body * bd = &field_70[*cnt];
                    UnkStruct_PP_el * e = (UnkStruct_PP_el *)(*(int *)(s3x4 + *(int *)(fp + (int)s5->field_18)) + (s1 << 2));
                    bd->field_0 = 5;
                    bd->field_C = e;
                    bd->field_4 = p858->field_0 + (e->field_0 << 6);
                    bd->field_8 = p994->field_0->field_3C + e->field_2 * 80;
                    bd->field_1 = 0;
                    bd->field_2 = 0;
                    GetIntervals__17CB3PhysicsManagerFP13CB3ActiveBody(this, bd);
                    *cnt = *cnt + 1;
                }
            }
            s4 = (s4 + 1) % D_0064C994.field_0->field_54;
            s2++;
        }
      ts2:
        if (s2 < s7) goto ls2;
    }
    for (int i = 0; i < field_1CB70; i++) func_001B7E10(this, i);
    return 1;
}
