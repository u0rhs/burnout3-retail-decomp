// Hand-written; the lifter refused it (a85: GetResultsPageString; switch(9,10,default), bool field read, if/else with early 0x43F, me/name locals declared in order).

// [L] DNAT: CB3OnlineTurnBasedCrashLogic::GetResultsPageString() (research/proto/new_names.csv, medium)
struct UnkStruct_Player {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual unsigned short * vfunc_10();
    unsigned char pad_4[0x4F1];
    unsigned char field_4F5;
    unsigned char pad_4F6[0x2];
    bool field_4F8;
};
struct UnkStruct_2750 {
    unsigned char pad_0[0x20];
    int field_20;
    unsigned char pad_24[0x44];
    int field_68;
    unsigned char pad_6C[0x8];
    unsigned short field_74[32];
    unsigned char pad_B4[0x6C];
    unsigned char field_120;
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E32AE0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E32B08 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BAA4 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E3D558 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_0051BAA4 D_0051BAA4;
extern UnkStruct_D_01E3D558 D_01E3D558;
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" UnkStruct_Player * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);
extern "C" UnkStruct_Player * func_002366D0(void *, int);
extern "C" void func_00310180(unsigned short *dst, const unsigned short *fmt, unsigned short *const &arg);

// 0x00392750
extern "C" const unsigned short * func_00392750(UnkStruct_2750 * self)
{
    switch (self->field_68) {
    case 9:
        return func_00271A00(&D_0051BA44, 0x43D);
    case 10: {
        bool done;
        UnkStruct_Player * p = GetPlayerByID__23CGtNetworkPlayerManagerCFi(&D_01E32AE0, self->field_20);
        if (p != 0) {
            done = p->field_4F8;
        } else {
            done = true;
            for (int i = 0; i < D_01E32B08.field_0; i++) {
                UnkStruct_Player * q = func_002366D0(&D_01E32AE0, i);
                if (q != 0 && q->field_4F5 == 0) {
                    done = false;
                }
            }
        }
        if (done) {
            return func_00271A00(&D_0051BA44, 0x43E);
        }
        return func_00271A00(&D_0051BA44, 0x55B);
    }
    default:
        if (D_0051BAA4.field_0 == 0) {
            return func_00271A00(&D_0051BA44, 0x43F);
        } else {
            if (self->field_120 != 0) {
                unsigned short * me;
                unsigned short * name;
                int id = self->field_20;
                if (id == GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0)) {
                    me = (unsigned short *)&D_01E3D558;
                    func_00310180(self->field_74, func_00271A00(&D_0051BA44, 0x303), me);
                } else {
                    UnkStruct_Player * pl = GetPlayerByID__23CGtNetworkPlayerManagerCFi(&D_01E32AE0, id);
                    if (pl != 0) {
                        name = pl->vfunc_10();
                        func_00310180(self->field_74, func_00271A00(&D_0051BA44, 0x303), name);
                    } else {
                        self->field_74[0] = 0;
                    }
                }
                return self->field_74;
            }
            return func_00271A00(&D_0051BA44, 0x269);
        }
    }
}
