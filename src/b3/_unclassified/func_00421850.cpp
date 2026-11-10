// Hand-written; the lifter refused it (fresh3: save-data restore (neighbour of func_00421700); sub-struct at +0x20 via pointer local, int[0x127] profile copy through element pointer, func_00322EA0 header block + scoped opt_dead_assignments off [G]).

#pragma push
#pragma opt_dead_assignments off

struct UnkStruct_B { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00421850_arr { signed char b[0x2C]; };
struct UnkStruct_D_004F5040 { UnkStruct_00421850_arr field_0; unsigned char pad_2C[0x14]; };
struct UnkStruct_00421850_hdr {
    UnkStruct_00421850_arr field_0;
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char field_2E;
    unsigned char field_2F;
    signed char field_30;
    signed char field_31;
    signed char field_32;
    signed char field_33;
    signed char field_34;
    signed char field_35;
    signed char field_36;
    signed char field_37;
    signed char field_38;
    signed char field_39;
    signed char field_3A;
    signed char field_3B;
    signed char field_3C;
    unsigned char field_3D;
    unsigned char field_3E;
    signed char field_3F;
};
struct UnkStruct_00421850_a { int field_0[0x13B0]; };
struct UnkStruct_00421850_b { int field_0[0x251C]; };
struct UnkStruct_00421850_prof {
    int field_0[0x127];
};
struct UnkStruct_00421850_ab { UnkStruct_00421850_a field_0; UnkStruct_00421850_b field_4EC0; };
struct UnkStruct_00421850 {
    int field_0;
    unsigned int field_4[3];
    signed char field_10[3];
    unsigned char pad_13[0x1];
    float field_14;
    float field_18;
    int field_1C;
    UnkStruct_00421850_ab field_20;
    UnkStruct_00421850_hdr field_E350;
    UnkStruct_00421850_prof field_E390[3];
    int field_F164;
};
struct UnkStruct_00421850_p { UnkStruct_00421850_prof *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004F5040 D_004F5040;
extern UnkStruct_B D_004F506C;
extern UnkStruct_B D_004F506D;
extern UnkStruct_B D_004F506E;
extern UnkStruct_B D_004F506F;
extern UnkStruct_B D_004F5070;
extern UnkStruct_B D_004F5071;
extern UnkStruct_B D_004F5072;
extern UnkStruct_B D_004F5073;
extern UnkStruct_B D_004F5074;
extern UnkStruct_B D_004F5075;
extern UnkStruct_B D_004F5076;
extern UnkStruct_B D_004F5077;
extern UnkStruct_B D_004F5078;
extern UnkStruct_B D_004F5079;
extern UnkStruct_B D_004F507A;
extern UnkStruct_B D_004F507B;
extern UnkStruct_B D_004F507C;
extern UnkStruct_B D_004F507D;
extern UnkStruct_B D_004F507E;
extern UnkStruct_B D_004F507F;
extern UnkStruct_00421850_a D_01EA7810;
extern UnkStruct_00421850_b D_01EAC6D0;
extern UnkStruct_00421850_p D_0051BF9C;
extern "C" int func_0013B820(void *);
extern "C" void Evaluate__10CB3ProfileFv(void *);
extern "C" void func_00139F20(void *);
extern "C" float func_0013A560(unsigned int *, void *);

// 0x00421850
extern "C" void func_00421850(UnkStruct_00421850 *self, int p1)
{
    UnkStruct_00421850_ab *ab = &self->field_20;
    D_01EA7810 = ab->field_0;
    D_01EAC6D0 = ab->field_4EC0;
    UnkStruct_00421850_hdr *h = &self->field_E350;
    D_004F5040.field_0 = h->field_0;
    unsigned char b0 = h->field_2C;
    unsigned char b1 = h->field_2D;
    unsigned char b2 = h->field_2E;
    unsigned char b3 = h->field_2F;
    D_004F506C.field_0 = b0;
    D_004F506D.field_0 = b1;
    D_004F506E.field_0 = b2;
    D_004F506F.field_0 = b3;
    D_004F5070.field_0 = h->field_30;
    D_004F5071.field_0 = h->field_31;
    D_004F5072.field_0 = h->field_32;
    D_004F5073.field_0 = h->field_33;
    D_004F5074.field_0 = h->field_34;
    D_004F5075.field_0 = h->field_35;
    D_004F5076.field_0 = h->field_36;
    D_004F5077.field_0 = h->field_37;
    D_004F5078.field_0 = h->field_38;
    D_004F5079.field_0 = h->field_39;
    D_004F507A.field_0 = h->field_3A;
    D_004F507B.field_0 = h->field_3B;
    D_004F507C.field_0 = h->field_3C;
    unsigned char b4 = h->field_3D;
    unsigned char b5 = h->field_3E;
    D_004F507D.field_0 = b4;
    D_004F507E.field_0 = b5;
    D_004F507F.field_0 = h->field_3F;
    UnkStruct_00421850_prof *prof = D_0051BF9C.field_0;
    func_0013B820(prof);
    UnkStruct_00421850_prof *sp = &self->field_E390[p1];
    *prof = *sp;
    Evaluate__10CB3ProfileFv(prof);
    func_00139F20(prof);
    self->field_14 = self->field_18;
    unsigned int i = 0;
    do {
        UnkStruct_00421850_prof *p = &self->field_E390[i];
        unsigned int t;
        func_0013A560(&t, p);
        self->field_4[i] = t;
        self->field_10[i] = ((signed char *)p)[0x49B] != 0;
        i++;
    } while (i < 3);
    self->field_0 = self->field_F164;
}

#pragma pop
