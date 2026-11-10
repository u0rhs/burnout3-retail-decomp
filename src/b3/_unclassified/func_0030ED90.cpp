// Hand-written; the lifter refused it (fresh3: online lobby car-class select; clone of func_00311EA0's types, host-id static inline called twice, else-if AmIHost re-test).

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
struct UnkStruct_0030ED90_player { unsigned char pad_0[0x4D8]; unsigned long field_4D8; };
struct UnkStruct_0030ED90_loc { unsigned char pad_0[0x14]; int field_14; unsigned int field_18; unsigned int field_1C; unsigned char pad_20[0x20]; };
struct UnkStruct_0030ED90_b { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_0030ED90_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0030ED90_ul { unsigned long field_0; unsigned long pad_8; };
struct UnkStruct_0030ED90_blk { unsigned char pad_0[0x20]; };
struct UnkStruct_0030ED90 { unsigned char pad_0[0x10]; unsigned char field_10; };
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_0030ED90_b D_01E3D58A;
extern UnkStruct_0030ED90_b D_01E65499;
extern UnkStruct_0030ED90_blk D_01E32AE0;
extern UnkStruct_0030ED90_blk D_01E94EF0;
extern UnkStruct_0030ED90_blk D_005186A0;
extern UnkStruct_0030ED90_ul D_01E3D578;
extern UnkStruct_0030ED90_ul D_01E90130;
extern UnkStruct_0030ED90_i D_01E900E0;
extern UnkStruct_0030ED90_i D_01E94F08;
extern int D_01E900EC[];
struct UnkStruct_0030ED90_p { void *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_0030ED90_p D_0051BF9C;
extern char maOffsetTable__14CB3MenuFlowFSM[];
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);
extern "C" int GetHostPlayerID__23CGtNetworkPlayerManagerFv(void *);
extern "C" UnkStruct_0030ED90_player * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" int GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(int);
extern "C" int func_003EB060(unsigned long);
extern "C" int func_0013A6D0(void *, int);
extern "C" unsigned long GetCarID__14CB3VehicleListF17EB3MenuCarClassesi(void *, int, int);
extern "C" bool func_00318F50(void *self, int p0, unsigned long p1, int p2, int p3, bool p4, unsigned long p5, int p6);
static inline int func_0030ED90_inl1()
{
    if (D_01E65499.field_0 != 0) return GetHostPlayerID__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
    return ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_80();
}
// 0x0030ED90
extern "C" void func_0030ED90(UnkStruct_0030ED90 *self)
{
    int cls = 7;
    UnkStruct_0030ED90_loc loc;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC(&loc);
    int &mode = loc.field_14;
    int k;
    if (mode == 1 && D_01E3D58A.field_0 != 0) k = (loc.field_18 >> 8) & 0xFF;
    else k = (loc.field_1C >> 8) & 0xFF;
    if (k == 0) {
        cls = 7;
    } else if (k == 1) {
        if (!AmIHost__17CB3NetworkManagerFv(&D_01E32AE0)) {
            if (func_0030ED90_inl1() < 0) {
                if (D_01E3D578.field_0 != 0) cls = GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(func_003EB060(D_01E3D578.field_0));
            } else {
                UnkStruct_0030ED90_player *p = GetPlayerByID__23CGtNetworkPlayerManagerCFi(&D_01E32AE0, func_0030ED90_inl1());
                if (p->field_4D8 != 0) cls = GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(func_003EB060(p->field_4D8));
            }
        } else if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0)) {
            self->field_10 = 0;
            cls = 7;
        }
    } else {
        cls = k - 2;
    }
    self->field_10 = 0;
    int v = ((int *)(maOffsetTable__14CB3MenuFlowFSM + 0x3E0))[cls];
    D_01E900EC[D_01E900E0.field_0] = v;
    unsigned long car;
    if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) || func_0013A6D0(D_0051BF9C.field_0, cls)) car = 0;
    else car = GetCarID__14CB3VehicleListF17EB3MenuCarClassesi(&D_005186A0, v, 0);
    D_01E94F08.field_0 = 0;
    func_00318F50(&D_01E94EF0, v, car, (unsigned int)(mode - 2) <= 2, 1, D_01E90130.field_0 != 0, 0, 0);
}
