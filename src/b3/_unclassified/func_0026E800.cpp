// func_0026E800 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (the vfunc_9C()==5 dispatch as int k = vfunc_9C(); if (k == 5) (switch gives beq/b, plain if moves the test inline)).

struct UnkStruct_26E800_ent {
    int field_0;
    char field_4[0x10];
    unsigned char field_14[4];
    int field_18;
    unsigned char pad_1C[0x10];
    int field_2C;
    unsigned char pad_30[4];
    int field_34;
    int field_38;
    unsigned char field_3C;
    unsigned char pad_3D[3];
    int field_40;
    int field_44;
    unsigned char pad_48[4];
    unsigned char field_4C;
    unsigned char pad_4D[3];
};
struct UnkStruct_26E800_mgr {
    unsigned char pad_0[0x323E0];
    UnkStruct_26E800_ent field_323E0[8];
    int field_32660;
};
struct UnkStruct_26E800_car {
    unsigned char pad_0[0x10C0];
    unsigned char field_10C0[4];
    unsigned char pad_10C4[0x5FC];
    unsigned char field_16C0[0x98];
    int field_1758;
};
struct UnkStruct_26E800_pl {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual char * vfunc_10();
    unsigned char pad_4[0x6D8];
    UnkStruct_26E800_car * field_6DC;
};
struct UnkStruct_26E800_msg { unsigned char pad_0[4]; int field_4; };
struct UnkStruct_26E800_v {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual int vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void vfunc_A8(); virtual void vfunc_AC(); virtual void vfunc_B0(); virtual void vfunc_B4();
    virtual void vfunc_B8(); virtual void vfunc_BC(); virtual void vfunc_C0(); virtual void vfunc_C4();
    virtual void vfunc_C8(); virtual void vfunc_CC(); virtual void vfunc_D0(); virtual void vfunc_D4();
    virtual void vfunc_D8(); virtual void vfunc_DC(); virtual void vfunc_E0(); virtual void vfunc_E4();
    virtual void vfunc_E8(); virtual void vfunc_EC(); virtual void vfunc_F0(); virtual void vfunc_F4(int);
    unsigned char pad_4[0x6E];
    unsigned char field_72;
    unsigned char field_73;
};
struct UnkStruct_26E800_g {
    unsigned long field_0;
    unsigned char pad_8[0x1AC];
    UnkStruct_26E800_v * field_1B4;
};
struct UnkStruct_D_0051BA88_26E800 { UnkStruct_26E800_g * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E65499 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0064EA70 {
    unsigned char pad_0[8];
    int field_8;
    unsigned char pad_C[0x78];
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    unsigned char field_94;
    unsigned char pad_95[3];
    int field_98;
};
struct UnkStruct_D_0064CE40 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01ECD9F0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0064EB08 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BA88_26E800 D_0051BA88;
extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_0064EA70 D_0064EA70;
extern UnkStruct_D_0064CE40 D_0064CE40;
extern UnkStruct_D_0064EB08 D_0064EB08;
extern UnkStruct_D_01ECD9F0 D_01ECD9F0;
extern "C" int func_00272BC0(void *, void *);
extern "C" UnkStruct_26E800_pl * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void func_00272D60(void *, void *);
extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, int);
extern "C" unsigned char func_00155F00(void *, int, void *);
extern "C" void func_00272DD0(void *, void *);
extern "C" int func_003CCFB0(void *, unsigned char, unsigned char);
extern "C" int func_003CCEE0(void *, int, int, int);
extern "C" void func_0042F870(void *, int, unsigned long);

static inline UnkStruct_26E800_ent * func_0026E800_find(UnkStruct_26E800_mgr * m, int id)
{
    int n = m->field_32660;
    int i;
    for (i = 0; i < n; i++) {
        if (id == m->field_323E0[i].field_0) return &m->field_323E0[i];
    }
    return 0;
}

// 0x0026E800
extern "C" void func_0026E800(UnkStruct_26E800_msg * msg, int p1, UnkStruct_26E800_mgr * self)
{
    UnkStruct_26E800_pl * pl;
    if (D_01E65499.field_0 == 0) return;
    UnkStruct_26E800_mgr * const m = self;
    int id = msg->field_4;
    if (func_0026E800_find(m, id) != 0) return;
    m->field_32660 = m->field_32660 + 1;
    UnkStruct_26E800_ent * e = &m->field_323E0[m->field_32660 - 1];
    func_00272BC0(msg, e->field_14);
    pl = GetPlayerByID__23CGtNetworkPlayerManagerCFi(m, id);
    strncpy(e->field_4, pl->vfunc_10(), 0x10);
    e->field_0 = id;
    e->field_4C = 1;
    if (pl->field_6DC != 0) {
        func_00272D60(e->field_14, pl->field_6DC->field_10C0);
        SetFinished__10CB3RaceCarF19EB3ScoreFinishState(pl->field_6DC, e->field_18);
        unsigned char rr = func_00155F00(pl->field_6DC->field_16C0, 0, pl->field_6DC);
        if (rr) {
            const UnkStruct_26E800_car * c = pl->field_6DC;
            const UnkStruct_D_0064EA70 * const gg = &D_0064EA70;
            int cc = c->field_1758;
            e->field_44 = e->field_44 - gg->field_98;
            e->field_44 = e->field_44 + cc;
            int s = gg->field_98;
            D_0051BA88.field_0->field_1B4->vfunc_F4(-c->field_1758);
            D_0051BA88.field_0->field_1B4->vfunc_F4(s);
        }
        func_00272DD0(e->field_14, pl->field_6DC->field_16C0);
    }
    int k = D_0051BA88.field_0->field_1B4->vfunc_9C();
    if (k == 5) {
    {
        if (D_0051BA88.field_0->field_1B4->field_72 != 0) {
            UnkStruct_D_0064EA70 * const g = &D_0064EA70;
            if (g->field_8 != 0) {
                int r = func_003CCFB0(&D_0064CE40, g->field_94, e->field_3C);
                switch (r) {
                case 4: g->field_8C = -2; e->field_34 = -2; break;
                case 5: g->field_8C = 2; e->field_34 = 2; break;
                case 6: g->field_8C = 4; e->field_34 = 4; break;
                default: g->field_8C = 1; e->field_34 = 1; break;
                }
                g->field_98 = func_003CCEE0(&D_0064CE40, g->field_84, g->field_90, g->field_8C);
                e->field_40 = func_003CCEE0(&D_0064CE40, e->field_2C, e->field_38, e->field_34);
            }
            D_0051BA88.field_0->field_1B4->vfunc_F4(e->field_40);
            D_0051BA88.field_0->field_1B4->vfunc_F4(g->field_98);
        }
    }
    }
    if (D_0051BA88.field_0->field_1B4->vfunc_9C() == 4 || D_0051BA88.field_0->field_1B4->vfunc_9C() == 5) {
        UnkStruct_26E800_g * G;
        int b;
        if (D_0051BA88.field_0->field_1B4->vfunc_9C() == 4) { G = D_0051BA88.field_0; b = G->field_1B4->field_73; }
        else { G = D_0051BA88.field_0; b = G->field_1B4->field_72; }
        if (b != 0) {
            unsigned long t = G->field_0;
            int a1;
            if (G->field_1B4->vfunc_9C() == 5) a1 = e->field_40 + D_0064EB08.field_0;
            else a1 = D_0064EB08.field_0;
            func_0042F870(&D_01ECD9F0, a1, t);
        }
    }
}
