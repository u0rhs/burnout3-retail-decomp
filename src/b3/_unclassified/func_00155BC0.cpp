// Hand-written; the lifter refused it (hand-written: score-record update, 3x inlined result-code switch helper, UnkEnum_ index diamond).

// func_00155BC0 -- hand-written (L259); the lifter refused it.
// Unnamed in every table: placeholder with C linkage; file and Area unknown, so _unclassified/.
// Structs carry only the touched fields; every type is [G] (instruction widths). self is the per-car
// score record reached as D_0064D388[i] + 0x16C0 for the opponent [G].

enum UnkEnum_00155BC0 { UnkEnum_00155BC0_0, UnkEnum_00155BC0_1 };
struct UnkStruct_00155BC0_car;

struct UnkStruct_00155BC0_vt {
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
};
struct UnkStruct_00155BC0_g { unsigned char pad_0[0x1B4]; UnkStruct_00155BC0_vt *field_1B4; };
struct UnkStruct_D_0051BA88 { UnkStruct_00155BC0_g *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00155BC0_UB { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00155BC0_Pad16 { unsigned char pad_0[0x10]; };

struct UnkStruct_00155BC0_c {
    unsigned char pad_0[0x1914];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
};

struct UnkStruct_00155BC0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x78];
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    unsigned char field_94;
    unsigned char field_95;
    unsigned char pad_96[2];
    int field_98;
    unsigned char pad_9C[0x2C];
    UnkStruct_00155BC0_c *field_C8;
};

struct UnkStruct_00155BC0_car {
    unsigned char pad_0[0x16C0];
    UnkStruct_00155BC0 field_16C0;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_00155BC0_UB D_01E65499;
extern UnkStruct_00155BC0_UB D_0064D33B;
extern UnkStruct_00155BC0_Pad16 D_0064CE40;
extern UnkStruct_00155BC0_car *D_0064D388[];

extern "C" int func_003CCFB0(void *, unsigned char, unsigned char);
extern "C" int func_003CCEE0(void *, int, int, int);
extern "C" int func_003CD140(void *, int);
extern "C" int GetTotalPickupScore__13CB3CrashScoreFi(void *, int);
extern "C" unsigned char func_003CCE00(void *, int);
extern "C" int func_003CCBE0(void *, int);
extern "C" int func_00155F00(UnkStruct_00155BC0 *, int, UnkStruct_00155BC0_c *);

// [G] inlined three times: result code -> field_8C, then field_98 (no name for this helper)
static inline void func_00155BC0_inl1(UnkStruct_00155BC0 *o, unsigned char a, unsigned char b)
{
    switch (func_003CCFB0(&D_0064CE40, a, b)) {
    case 4:
        o->field_8C = -2;
        break;
    case 5:
        o->field_8C = 2;
        break;
    case 6:
        o->field_8C = 4;
        break;
    default:
        o->field_8C = 1;
        break;
    }
    o->field_98 = func_003CCEE0(&D_0064CE40, o->field_84, o->field_90, o->field_8C);
}
// 0x00155BC0
extern "C" void func_00155BC0(UnkStruct_00155BC0 *self)
{
    int id = self->field_C8->field_19AC;
    if (self->field_C8->field_1914 != 2) {
        self->field_95 = D_0064D33B.field_0;
        self->field_84 = func_003CD140(&D_0064CE40, id);
        self->field_90 = GetTotalPickupScore__13CB3CrashScoreFi(&D_0064CE40, id);
        self->field_94 = func_003CCE00(&D_0064CE40, id);
    }
    if (D_0051BA88.field_0 != 0 && D_0051BA88.field_0->field_1B4 != 0 && D_0051BA88.field_0->field_1B4->vfunc_A4() != 0) {
        // [G] UnkEnum_ local (N148): an int/bool/ternary gives sltiu/movn, retail keeps the branch diamond
        UnkEnum_00155BC0 idx; if (id == 0) idx = UnkEnum_00155BC0_1; else idx = UnkEnum_00155BC0_0;
        UnkStruct_00155BC0 *o = &D_0064D388[idx]->field_16C0;
        if (o->field_8 == 0) {
            self->field_8C = 0;
            self->field_98 = 0;
        } else {
            func_00155BC0_inl1(self, self->field_94, o->field_94);
            func_00155BC0_inl1(o, o->field_94, self->field_94);
            if (D_01E65499.field_0 == 0) {
                func_00155F00(self, 0, self->field_C8);
            }
        }
    } else {
        func_00155BC0_inl1(self, self->field_94, 0);
        if (D_01E65499.field_0 == 0) {
            if (D_0051BA88.field_0->field_1B4->vfunc_A4() != 0 || D_0051BA88.field_0->field_1B4->vfunc_A8() != 0) {
                func_00155F00(self, 0, self->field_C8);
            }
        }
    }
    self->field_88 = (unsigned char)func_003CCBE0(&D_0064CE40, self->field_C8->field_19AC);
}
