// CB3NetworkManager::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a145: modular-time ahead32/ahead16 static inlines (upper bound written x > K), else-arm layout by 'bool s1; if (f != 0xFFFF){...goto done;} s1 = false;').

struct UnkStruct_Upd_net {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10();
};
struct UnkStruct_Upd_pl {
    unsigned char pad_0[0x58];
    unsigned char field_58;
    unsigned char pad_59[3];
    unsigned char field_5C;
};
struct UnkStruct_Upd_mgr {
    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[0xFAC - 0x2C];
    unsigned char field_FAC[4];
    unsigned char pad_FB0[0x9B40 - 0xFB0];
    unsigned char field_9B40[0x10];
    unsigned char pad_9B50[0xA264 - 0x9B50];
    UnkStruct_Upd_net field_A264[1];
    unsigned char pad_A268[0xA8B0 - 0xA268];
    unsigned char field_A8B0[4];
    unsigned char pad_A8B4[0xAAB0 - 0xA8B4];
    int field_AAB0;
    unsigned char pad_AAB4[4];
    unsigned short field_AAB8;
    unsigned char pad_AABA[0x32664 - 0xAABA];
    int field_32664;
    unsigned char pad_32668[0x32978 - 0x32668];
    float field_32978;
    unsigned char pad_3297C[0x329B0 - 0x3297C];
    int field_329B0;
    int field_329B4;
    unsigned char field_329B8;
    unsigned char field_329B9;
};
struct UnkStruct_Upd_ent { unsigned char pad_0[0x76]; short field_76; };
struct UnkStruct_Upd_lobby {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(void *, int);
};
struct UnkStruct_D_01E32AE0_upd { int pad_0[2]; void * field_8[1]; };
struct UnkStruct_D_01E32B08 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004E2A14_upd { unsigned int field_0; };
struct UnkStruct_D_004E2A18_upd { float field_0; };
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BAA4 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_004F6061 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E33A8C { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_Upd_dev { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E32AE0_upd D_01E32AE0;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_004E2A14_upd D_004E2A14;
extern UnkStruct_D_004E2A18_upd D_004E2A18;
extern UnkStruct_D_004E2A18_upd D_004E2A1C;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_0051BAA4 D_0051BAA4;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_01E33A8C D_01E33A8C;
extern unsigned char D_004F50C0[];
extern UnkStruct_Upd_dev D_00665EC0;
extern UnkStruct_Upd_dev D_01E32FC0;
extern UnkStruct_Upd_dev D_01E3CD44;
extern "C" int func_0041E930(void *);
extern "C" void func_0041E9C0(void *);
extern "C" void func_0041E9A0(void *);
extern "C" void func_0041E9F0(void *);
extern "C" unsigned int func_00222C90(void *);
extern "C" void func_00236BC0(void *, int);
extern "C" int Update__12CGtPS2LibNetFi(void *, int);
extern "C" void * func_002366D0(void *, int);
extern "C" void func_0023C100(void *);
extern "C" void func_00360950(void *);
extern "C" int func_0022FBB0(void *);
extern "C" UnkStruct_Upd_pl * func_00231190(void *, int);
extern "C" void func_0026EEC0(void *);
extern "C" void func_0026EDD0(void *);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);
extern "C" void * func_002348A0(void *, int);
extern "C" void * func_0022D3C0();
extern "C" void * memcpy(void *, const void *, unsigned int);

static inline bool Upd_ahead32(unsigned int a, unsigned int b)
{
    if (a < 0x55555555 && b > 0xAAAAAAAA) return true;
    if (b < 0x55555555 && a > 0xAAAAAAAA) return false;
    if (b < a) return true;
    return false;
}
static inline unsigned int Upd_dist32(unsigned int a, unsigned int b)
{
    if (a < 0x55555555 && b > 0xAAAAAAAA) return a + (0xFFFFFFFF - b);
    return a - b;
}
static inline bool Upd_ahead16(int a, int b)
{
    if (a < 0x5555 && b > 0xAAAA) return true;
    if (b < 0x5555 && a > 0xAAAA) return false;
    if (b < a) return true;
    return false;
}

// 0x00270ED0
extern "C" void Update__17CB3NetworkManagerFv(UnkStruct_Upd_mgr * self)
{
    if (self->field_32664 != 0x17) return;
    if (self->field_329B9 != 0 && D_0051BAA4.field_0 != 0 && (D_004E2A14.field_0 & 1) != 0) {
        UnkStruct_Upd_ent * e = (UnkStruct_Upd_ent *)(D_004F50C0 + D_004F6061.field_0 * 300 + 0xD48);
        if (D_01E33A8C.field_0 != 0) {
            if (e->field_76 != 0) e->field_76 = 0;
        }
        int i;
        int n = 0;
        for (i = 0; i < D_01E32B08.field_0; i++) {
            if (D_01E32AE0.field_8[i] != 0) n++;
        }
        if (n > 0 && func_0041E930(&D_01E33A8C) < 0 && e->field_76 != 0) {
            func_0041E9C0(&D_01E33A8C);
        } else {
            int a = func_0041E930(&D_01E33A8C);
            if (a == GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0) && e->field_76 == 0) {
                func_0041E9A0(&D_01E33A8C);
            }
        }
    }
    *(int *)&D_004E2A18 = 0x42480000;
    *(int *)&D_004E2A1C = 0x42480000;
    self->field_32978 = self->field_32978 + D_004F509C.field_0;
    if (self->field_329B8 != 0) {
        unsigned int a = D_004E2A14.field_0;
        unsigned int b = func_00222C90(&D_00665EC0);
        int d;
        if (Upd_ahead32(a, b)) d = Upd_dist32(a, b);
        else d = -Upd_dist32(b, a);
        self->field_329B4 = self->field_329B0 - d;
    } else {
        self->field_329B4 = 0;
    }
    {
        unsigned short h = D_004E2A14.field_0;
        if (h == 0xFFFF) h = 0;
        func_00236BC0(self, h);
    }
    {
        unsigned short h = D_004E2A14.field_0;
        if (h == 0xFFFF) h = 0;
        Update__12CGtPS2LibNetFi(self->field_9B40, h);
    }
    int j;
    for (j = 0; j < self->field_28; j++) {
        void * p = func_002366D0(self, j);
        if (p != 0) func_0023C100(p);
    }
    ((UnkStruct_Upd_net *)self->field_A264)->vfunc_10();
    func_00360950(self->field_A8B0);
    func_0041E9F0(self->field_FAC);
    bool s1;
    int f = self->field_AAB8;
    if (f != 0xFFFF) {
        unsigned short h = D_004E2A14.field_0;
        if (h == 0xFFFF) h = 0;
        if (!Upd_ahead16(h, f)) goto done;
    }
    s1 = false;
    {
        int k;
        for (k = 0; k < D_01E32B08.field_0; k++) {
            void * p = func_002366D0(&D_01E32AE0, k);
            if (p != 0) {
                UnkStruct_Upd_pl * q = func_00231190(&D_01E32FC0, func_0022FBB0(p));
                bool v = q->field_5C != 0;
                if (!v) v = q->field_58 != 0;
                if (!v) s1 = true;
            }
        }
        if (s1) {
            if (GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0) >= 0 && self->field_AAB0 == 1) {
                int id = GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0);
                void * x = func_002348A0(&D_01E32FC0, id);
                unsigned char buf[0x34];
                memcpy(buf, x, 0x14);
                void * y = func_0022D3C0();
                if (y != 0) memcpy(buf + 0x14, y, 0x20);
                ((UnkStruct_Upd_lobby *)&D_01E3CD44)->vfunc_78(buf, 0x34);
            }
        }
    }
    if (self->field_AAB8 == 0xFFFF) {
        unsigned short h = D_004E2A14.field_0;
        if (h == 0xFFFF) h = 0;
        self->field_AAB8 = h;
    }
    self->field_AAB8 = self->field_AAB8 + 0xF;
    if (self->field_AAB8 == 0xFFFF) self->field_AAB8 = 0;
done:
    func_0026EEC0(self);
    func_0026EDD0(self);
}
