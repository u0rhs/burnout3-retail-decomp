// Hand-written; the lifter refused it (mwperm: 'if (GetPlayerByID__23CGtNetworkPlayerManagerCFi(D_01E32AE0, ' -> 'int t1; if (!GetPlayerByID__23CGtNetworkPlayerManagerCFi(D_01E32AE0, s2)) return'; +'t1 = src->field_4;').

struct UnkStruct_D_01E3CD44_o {
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
    virtual int vfunc_7C(void *, void *, void *);
};
struct UnkStruct_26EEC0_a264 {
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
};
struct UnkStruct_26EEC0_9b40 {
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
};
struct UnkStruct_26EEC0_msg { unsigned char pad_0[0x10]; int field_10; };
struct UnkStruct_26EEC0_pl { unsigned char pad_0[0x4F0]; int field_4F0; };
struct UnkStruct_26EEC0_t { int field_0; int field_4; int field_8; int field_C; int field_10; };
struct UnkStruct_D_01E3CD44_w { UnkStruct_D_01E3CD44_o o; unsigned char pad[0xC]; };
extern UnkStruct_D_01E3CD44_w D_01E3CD44;
extern unsigned char D_01E32AE0[];
extern unsigned char D_01E32FC0[];
extern "C" UnkStruct_26EEC0_pl *GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" int GetHostPlayerID__23CGtNetworkPlayerManagerFv(void *);
extern "C" int func_0022D3B0();
extern "C" int func_0022FBB0(void *);
extern "C" void func_00235D90(void *);
extern "C" void func_0022D400(void *);
extern "C" int func_00230EE0(void *, int, void *);
extern "C" UnkStruct_26EEC0_t *func_00231190(void *, int);
extern "C" void func_0022F970(void *, void *);
struct UnkStruct_26EEC0 {
    unsigned char pad_0[4];
    unsigned char field_4;
    unsigned char pad_5[0x9B40 - 5];
    UnkStruct_26EEC0_9b40 field_9B40;
    unsigned char pad_9B44[0xA264 - 0x9B44];
    UnkStruct_26EEC0_a264 field_A264;
    unsigned char pad_A268[0x329B9 - 0xA268];
    unsigned char field_329B9;
};
static inline bool func_0026EEC0_inl1(int s2, UnkStruct_26EEC0_msg *s1)
{
    int t1;
    if (!GetPlayerByID__23CGtNetworkPlayerManagerCFi(D_01E32AE0, s2)) return false;
    if (func_00230EE0(D_01E32FC0, s2, s1) != 0) {
        UnkStruct_26EEC0_t *t = func_00231190(D_01E32FC0, s2);
        UnkStruct_26EEC0_t *src = (UnkStruct_26EEC0_t *)s1;
        t->field_0 = src->field_0;
        t1 = src->field_4;
        t->field_4 = src->field_4;
        t->field_8 = src->field_8;
        t->field_C = src->field_C;
        t->field_10 = src->field_10;
        func_0022F970(GetPlayerByID__23CGtNetworkPlayerManagerCFi(D_01E32AE0, s2), s1);
        return true;
    }
    return false;
}
// 0x0026EEC0
extern "C" void func_0026EEC0(UnkStruct_26EEC0 *self)
{
    if (self->field_4 == 0) return;
    for (;;) {
        UnkStruct_26EEC0_msg *msgp;
        int x;
        unsigned char buf[0x18];
        if (!D_01E3CD44.o.vfunc_7C(&msgp, &x, buf)) return;
        UnkStruct_26EEC0_msg *s1 = msgp;
        int s2 = s1->field_10;
        UnkStruct_26EEC0_pl *s0 = GetPlayerByID__23CGtNetworkPlayerManagerCFi(self, s2);
        if (s0 == 0) return;
        int h;
        if (self->field_329B9 != 0) h = GetHostPlayerID__23CGtNetworkPlayerManagerFv(self);
        else h = self->field_A264.vfunc_80();
        if (h >= 0) {
            int h2;
            if (self->field_329B9 != 0) h2 = GetHostPlayerID__23CGtNetworkPlayerManagerFv(self);
            else h2 = self->field_A264.vfunc_80();
            UnkStruct_26EEC0_pl *s4 = GetPlayerByID__23CGtNetworkPlayerManagerCFi(self, h2);
            if (func_0022D3B0() == 0 && s4 != 0 && s2 == func_0022FBB0(s4)) {
                self->field_9B40.vfunc_3C();
                func_00235D90(self);
                func_0022D400((char *)s1 + 0x14);
            }
        }
        if (s0->field_4F0 != 0) continue;
        if (func_0026EEC0_inl1(s2, s1)) s0->field_4F0 = 1;
    }
}
