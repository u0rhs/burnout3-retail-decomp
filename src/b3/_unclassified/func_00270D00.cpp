// Hand-written; the lifter refused it (do{ r=func_00236C00(); SleepThreadTillVBlank__12CGtThreadMgrFv(); }while(!r): s1 from the first call's v0 (andi in jal delay slot)).

struct UnkStruct_00270D00_o {     virtual void vfunc_8();
    virtual void vfunc_C();
};
struct UnkStruct_00270D00_o2 {     virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
};
struct UnkStruct_00270D00_o3 {     virtual void vfunc_8();
};
struct UnkStruct_00270D00 {
    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[0x9B40 - 0x2C];
    UnkStruct_00270D00_o3 field_9B40;
    unsigned char pad_9B44[0xA264 - 0x9B44];
    UnkStruct_00270D00_o2 field_A264;
    unsigned char pad_A268[0x329E2 - 0xA268];
    unsigned char field_329E2;
    unsigned char field_329E3;
};
extern "C" void func_0041E9E0(void *);
extern "C" UnkStruct_00270D00_o * func_002366D0(void *, int);
extern "C" unsigned char func_00236C00(void *);
extern "C" void SleepThreadTillVBlank__12CGtThreadMgrFv();
extern "C" void func_003608F0(void *);
// 0x00270D00
extern "C" void func_00270D00(UnkStruct_00270D00 *self)
{
    func_0041E9E0((char *)self + 0xFAC);
    for (int i = 0; i < self->field_28; i++) {
        UnkStruct_00270D00_o *o = func_002366D0(self, i);
        if (o != 0) o->vfunc_C();
    }
    unsigned char r;
    do {
        r = func_00236C00(self);
        SleepThreadTillVBlank__12CGtThreadMgrFv();
    } while (!r);
    func_003608F0((char *)self + 0xA8B0);
    self->field_A264.vfunc_1C();
    self->field_9B40.vfunc_8();
    *(int *)((char *)self + 0x329E8) = 0;
    *(int *)((char *)self + 0x329EC) = 0;
    self->field_329E2 = 0;
    self->field_329E3 = 0;
    *(int *)((char *)self + 0x32664) = 1;
}
