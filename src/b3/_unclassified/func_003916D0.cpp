// Hand-written; the lifter refused it (UpdateWaitInitCountdownClient: vfunc_80 via cast (no devirtualisation), bool flag returned via if(have) return true; return false).

// func_003916D0 -- hand-written from the retail structure (lifter refused: call result used as int and float).
// [L] DNAT: CB3OnlineStageLogic::UpdateWaitInitCountdownClient() (research/proto/new_names.csv, medium)
// Sibling: func_00391820.cpp (UpdateWaitInitCountdownHost).
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E3CD44 {
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
    virtual int vfunc_80();
    unsigned char pad_4[0xC];
};
struct UnkStruct_003916D0 {
    unsigned char pad_0[0x51];
    unsigned char field_51;
    unsigned char pad_52[2];
    float field_54;
    float field_58;
};

extern UnkStruct_P D_01E32AE0;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_B D_01E65499, D_01E654AC;
extern UnkStruct_F D_01E654A4, D_004F50A0;
extern "C" void func_00270880(void *, int);
extern "C" void func_0026FAA0(void *, int);
extern "C" int func_0026D970(void *);
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" int GetHostPlayerID__23CGtNetworkPlayerManagerFv(void *);  // CGtNetworkPlayerManager::GetHostPlayerID()
extern "C" void *GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);  // CGtNetworkPlayerManager::GetPlayerByID(int) const
extern "C" void Prepare__26CB3NetworkRaceReadyMessageFv(void *);  // CB3NetworkRaceReadyMessage::Prepare()

// 0x003916D0
extern "C" bool func_003916D0(UnkStruct_003916D0 * self)
{
    if (self->field_51 == 0) {
        func_00270880(&D_01E32AE0, 1);
    }
    func_0026FAA0(&D_01E32AE0, 1);
    if (func_0026D970(&D_01E32AE0) != 0 && D_004F50A0.field_0 - self->field_54 > 1.0f && self->field_51 == 0
        && AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) == 0) {
        int id;
        if (D_01E65499.field_0 != 0) {
            id = GetHostPlayerID__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
        } else {
            id = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_80();
        }
        void * p = GetPlayerByID__23CGtNetworkPlayerManagerCFi(&D_01E32AE0, id);
        Prepare__26CB3NetworkRaceReadyMessageFv((char *)p + 0xBAC);
        self->field_51 = 1;
    }
    bool have;
    if (D_01E654AC.field_0 != 0) {
        self->field_58 = D_01E654A4.field_0;
        have = true;
    } else {
        self->field_58 = -1.0f;
        have = false;
    }
    if (have) {
        return true;
    }
    return false;
}
