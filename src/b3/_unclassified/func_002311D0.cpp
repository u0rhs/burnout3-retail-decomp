// Hand-written; the lifter refused it (a146: NAT/peer negotiation FSM (jump table, fall-through cases); FindEntry inline twice (stride 0x90); '== 3 || == 4' gives the sltiu at form).

struct UnkStruct_11D0_vt {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual int vfunc_1C();
};
struct UnkStruct_11D0_peer { int field_0; int field_4; };
struct UnkStruct_11D0_ent {
    int field_0;
    int field_4;
    unsigned char pad_8[0xC];
    int field_14;
    int field_18;
    unsigned char pad_1C[4];
    int field_20;
    int field_24;
    int field_28;
    unsigned char pad_2C[0x28];
    float field_54;
    unsigned char pad_58[1];
    unsigned char field_59;
    unsigned char field_5A;
    unsigned char field_5B;
    unsigned char pad_5C;
    unsigned char field_5D;
    unsigned char pad_5E[2];
    unsigned char field_60;
    unsigned char pad_61;
    unsigned char field_62;
    unsigned char field_63;
    unsigned char pad_64[8];
    short field_6C;
    unsigned char pad_6E[2];
    unsigned char field_70;
    unsigned char pad_71;
    unsigned char field_72;
    unsigned char field_73;
    unsigned char pad_74[8];
    short field_7C;
    unsigned char pad_7E[2];
    unsigned char field_80;
    unsigned char pad_81;
    unsigned char field_82;
    unsigned char field_83;
    unsigned char pad_84[8];
    short field_8C;
    unsigned char pad_8E[2];
};
struct UnkStruct_11D0 {
    UnkStruct_11D0_ent field_0[8];
    unsigned char pad_480[0xA4];
    UnkStruct_11D0_vt *field_524;
    int field_528;
};
extern "C" {
UnkStruct_11D0_peer *func_002348A0(UnkStruct_11D0 *, int);
int func_00230600(UnkStruct_11D0 *, UnkStruct_11D0_vt *, int, float);
int func_00230C50(UnkStruct_11D0 *, UnkStruct_11D0_ent *, int, float);
void func_0022D850(void *);
}
static inline UnkStruct_11D0_ent *func_002311D0_inl1(UnkStruct_11D0 *self, int id)
{
    for (int i = 0; i < 8; i++) {
        UnkStruct_11D0_ent *e = &self->field_0[i];
        if (id == e->field_14) return e;
    }
    return 0;
}
// 0x002311D0
extern "C" int func_002311D0(UnkStruct_11D0 *self, int a1, int id, short a3, int *out2, int *out1, float dt, float step)
{
    UnkStruct_11D0_ent *s1 = func_002311D0_inl1(self, id);
    *out1 = -1;
    *out2 = -1;
    UnkStruct_11D0_peer *s6 = func_002348A0(self, a1);
    UnkStruct_11D0_ent *s0 = func_002311D0_inl1(self, id);
    switch (s1->field_20) {
    case 0:
        s1->field_20 = 1;
    default:
        return 0;
    case 1:
        if (func_00230600(self, self->field_524, self->field_528, dt) == 0) return 0;
        s1->field_20 = 2;
    case 2:
        if (s0->field_0 == 3 || s0->field_0 == 4) return 0;
        s1->field_20 = 3;
    case 3:
        if (s6->field_0 == 2 && s0->field_4 != s6->field_4 && s1->field_5D == 0) {
            if ((s1->field_60 & 2) == 2) func_0022D850(&s1->field_60);
            s1->field_63 = 5;
            s1->field_6C = a3;
            s1->field_62 = 1;
            s1->field_60 |= 1;
            s1->field_5D = 1;
        }
        s1->field_54 = dt;
        s1->field_20 = 4;
    case 4:
        if (s0->field_0 == 2 && s0->field_4 != s6->field_4) {
            if (self->field_524->vfunc_1C() != 0) s1->field_54 += step;
            if (!(dt - s1->field_54 < 15.0f)) {
                s1->field_20 = 9;
                return 2;
            }
            {
                UnkStruct_11D0_ent *a0 = func_002311D0_inl1(self, id);
                int v = a0->field_18;
                if (v == -1) return 0;
                *out1 = v;
            }
        }
        if ((s1->field_70 & 2) == 2) func_0022D850(&s1->field_70);
        s1->field_73 = 6;
        s1->field_7C = a3;
        s1->field_72 = 1;
        s1->field_70 |= 1;
        s1->field_54 = dt;
        s1->field_20 = 5;
    case 5:
        if (self->field_524->vfunc_1C() != 0) s1->field_54 += step;
        if (!(dt - s1->field_54 < 15.0f)) {
            s1->field_20 = 9;
            return 2;
        }
        if (s1->field_5B != 0) {
            s1->field_20 = 8;
            return 1;
        }
        return 0;
    case 6:
        if (func_00230C50(self, s1, a1, dt) == 0) return 0;
        *out1 = s1->field_28;
        *out2 = s1->field_24;
        if ((s1->field_80 & 2) == 2) func_0022D850(&s1->field_80);
        s1->field_83 = 4;
        s1->field_8C = a3;
        s1->field_82 = 1;
        s1->field_80 |= 1;
        s1->field_54 = dt;
        s1->field_20 = 7;
    case 7:
        {
            UnkStruct_11D0_ent *a0 = func_002311D0_inl1(self, id);
            int v = a0->field_18;
            if (v == -1) {
            } else {
                *out1 = v;
            }
        }
        if (self->field_524->vfunc_1C() != 0) s1->field_54 += step;
        if (!(dt - s1->field_54 < 15.0f)) {
            s1->field_5A = 1;
            s1->field_20 = 9;
            return 0;
        }
        if (s1->field_59 != 0) {
            s1->field_20 = 8;
            return 1;
        }
        return 0;
    case 8:
        return 1;
    case 9:
        return 2;
    }
}
