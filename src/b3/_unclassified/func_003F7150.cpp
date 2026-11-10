// Hand-written; the lifter refused it (a133: EnterSecondResultsPage; sibling 3F7550 shape + explicit case 5 break for jtbl).

enum EGtStateAction {};
struct UnkStruct_Menu {
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
    virtual int vfunc_9C();
    virtual int vfunc_A0();
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
    virtual int vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    unsigned char pad_E8[0x72 - 0x4];
    unsigned char field_72;
};
struct UnkStruct_003F7150 { unsigned char pad_0[0x10]; int field_10; unsigned char field_14[4]; unsigned char field_18[8]; };
struct UnkStruct_Game { unsigned char pad_0[0x1B4]; UnkStruct_Menu * field_1B4; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051BA88 { UnkStruct_Game * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_P D_01E32AE0;
extern UnkStruct_P D_01E95858;
extern UnkStruct_P D_01E958E0;
extern UnkStruct_P D_01E95968;
extern UnkStruct_P D_0051B7FC;
extern "C" bool AmIHost__17CB3NetworkManagerFv(void *);
extern "C" void func_003C21F0(void *, unsigned long);
extern "C" void func_003C5B80(void *, unsigned long);
extern "C" unsigned long long func_003F65D0(void *, void *);
extern "C" unsigned long long func_003F66F0(void *, void *);
extern "C" void func_003F7AE0(void *, void *, int);
extern "C" void func_003F8040(void *, void *, int);
extern "C" void SetPlayerRecordsNotAdded__17CB3NetworkManagerFv(void *);
extern "C" int func_0043C3C0(void *, unsigned int);
extern "C" int Prepare__22CB3RoadRageResultsPageFv(void *, unsigned int);
extern "C" void AddFakeResults__23CB3OnlineEndOfRaceStateFv(void *);
extern "C" int func_003C57C0(void *, int, void *);
// 0x003F7150
extern "C" void func_003F7150(UnkStruct_003F7150 * self)
{
    UnkStruct_Menu * m = D_0051BA88.field_0->field_1B4;
    for (int i = 0; i < 8; i++) {
        self->field_18[i] = 0;
    }
    SetPlayerRecordsNotAdded__17CB3NetworkManagerFv(&D_01E32AE0);
    switch (m->vfunc_9C()) {
    case 0:
        self->field_10 = 1;
        func_0043C3C0(&D_01E95858, 0x220000);
        func_003F7AE0(self, &D_01E95858, m->vfunc_A0());
        break;
    case 1:
        break;
    case 2:
        self->field_10 = 1;
        AmIHost__17CB3NetworkManagerFv(&D_01E32AE0);
        Prepare__22CB3RoadRageResultsPageFv(&D_01E958E0, 0x220000);
        func_003F7AE0(self, &D_01E958E0, (void *)m == (void *)&D_0051B7FC);
        break;
    case 3:
        {
            AddFakeResults__23CB3OnlineEndOfRaceStateFv(self);
            self->field_10 = 1;
            unsigned long long r = func_003F65D0(self, m);
            func_003C57C0(&D_01E95968, 0, (void *)(0));
            func_003C5B80(&D_01E95968, r);
            func_003F8040(self, &D_01E95968, m->vfunc_A0());
        }
        break;
    case 5:
        break;
    case 4:
        {
            self->field_10 = 1;
            unsigned long long r = func_003F66F0(self, m);
            func_003C57C0(&D_01E95968, 0, (void *)(0));
            func_003C5B80(&D_01E95968, r);
            func_003F8040(self, &D_01E95968, m->vfunc_A0());
        }
        break;
    }
}
