// Hand-written; the lifter refused it (loc field refs (f1C then f18) for a1/a0; mode 0/1 switch goto chk out of line; k: if-chain into shared other compare (cls != other) return 0).

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
    virtual void vfunc_BC(void *);
    unsigned char pad_0[0x10];
};
struct UnkStruct_Rbm_player { unsigned char pad_0[0x4D8]; unsigned long field_4D8; };
struct UnkStruct_Loc { unsigned char pad_0[0x14]; int field_14; unsigned int field_18; unsigned int field_1C; unsigned char pad_20[0x20]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_B2 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_Lobby { unsigned char pad_0[0x1394]; int field_1394; int field_1398; };
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_B D_01E3D58A;
extern UnkStruct_B2 D_01E65499;
struct UnkStruct_NM { unsigned char pad_0[0x20]; };
extern UnkStruct_NM D_01E32AE0;
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);
extern "C" int GetHostPlayerID__23CGtNetworkPlayerManagerFv(void *);
extern "C" UnkStruct_Rbm_player * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" int GetCarClass__18CB3OnlineLobbyPageFUl(void *, unsigned long);
// 0x00311EA0
extern "C" int func_00311EA0(UnkStruct_Lobby *self, unsigned long car, int flag)
{
    if (car == 0) return 0;
    int cls = GetCarClass__18CB3OnlineLobbyPageFUl(self, car);
    UnkStruct_Loc loc;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC(&loc);
    if (!AmIHost__17CB3NetworkManagerFv(&D_01E32AE0)) {
        int b1 = (loc.field_1C >> 8) & 0xFF;
        if ((b1 == 0 && self->field_1394 != 0)
            || (((loc.field_18 >> 8) & 0xFF) == 0 && self->field_1398 != 0 && loc.field_14 == 1 && D_01E3D58A.field_0 != 0)) {
            self->field_1394 = b1;
            self->field_1398 = (loc.field_18 >> 8) & 0xFF;
            return 0;
        }
    }
    unsigned int &f1C = loc.field_1C;
    unsigned int &f18 = loc.field_18;
    self->field_1394 = (f1C >> 8) & 0xFF;
    self->field_1398 = (f18 >> 8) & 0xFF;
    int mode = loc.field_14;
    switch (mode) {
    case 1:
    case 0:
        goto chk;  // [G] goto: retail lays the class check out of line after the final return
    }
back:
    int k;
    if (mode == 1 && flag != 0) k = (f18 >> 8) & 0xFF;
    else k = (f1C >> 8) & 0xFF;
    int other;
    if (k == 0) return 1;
    if (k == 1) {
        if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0)) return 1;
        int id;
        if (D_01E65499.field_0 != 0) id = GetHostPlayerID__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
        else id = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_80();
        UnkStruct_Rbm_player *p = GetPlayerByID__23CGtNetworkPlayerManagerCFi(&D_01E32AE0, id);
        if (p == 0 || p->field_4D8 == 0) return 1;
        other = GetCarClass__18CB3OnlineLobbyPageFUl(self, p->field_4D8);
    } else {
        other = k - 2;
    }
    if (cls != other) return 0;
    return 1;
chk:
    if (cls > 5) return 0;
    goto back;
}
