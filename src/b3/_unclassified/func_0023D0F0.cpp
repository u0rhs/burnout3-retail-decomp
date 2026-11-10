// Hand-written; the lifter refused it (a231: inl2 non-early-return (else-return form) stub order; locals declared reversed (g,s4,s3,s2,e); &e->field_3D91 pointer for clear; combined first return || chain; unsigned char id).


struct UnkStruct_0023D0F0_row {
    unsigned char pad_0[0x26];
    unsigned short field_26;
    unsigned char pad_28[3];
    unsigned char field_2B;
};
struct UnkStruct_0023D0F0_cb { unsigned char pad_0[0x2424]; void * field_2424; };
struct UnkStruct_0023D0F0_car { signed char field_0; unsigned char pad_1[0xB]; UnkStruct_0023D0F0_cb * field_C; };
struct UnkStruct_0023D0F0_p { unsigned char pad_0[0x1A14]; unsigned char field_1A14; };
struct UnkStruct_0023D0F0_o { unsigned char pad_0[0x204]; int field_204; unsigned char pad_208[8]; unsigned char field_210; };
struct UnkStruct_0023D0F0_ent {
    unsigned char pad_0[0x3D90];
    unsigned char field_3D90;
    unsigned char field_3D91;
};
struct UnkStruct_0023D0F0 {
    unsigned char pad_0[0x5C8];
    int field_5C8;
    unsigned char pad_5CC[0x10A];
    short field_6D6;
    unsigned char pad_6D8[4];
    UnkStruct_0023D0F0_p * field_6DC;
    UnkStruct_0023D0F0_o * field_6E0;
    unsigned char pad_6E4[0x36AC];
    unsigned char pad_3D90[0x1150];
    int field_4EE0;
    unsigned char pad_4EE4[4];
    unsigned char field_4EE8;
    unsigned char pad_4EE9[0x24];
    unsigned char field_4F0D;
};
struct UnkStruct_D_00527440 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00539D7C { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0055E948 { unsigned char pad_0[0x10]; };
class CB3TrafficSystem { public: bool VehicleIsValid(unsigned char p0); };
extern UnkStruct_D_00527440 D_00527440;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_00539D7C D_00539D7C;
extern UnkStruct_D_0055E948 D_0055E948;
extern "C" bool func_001A87D0(void *);
extern "C" void func_0023E6E0(void *, void *, int, short);
extern "C" void func_0023D410(void *, void *, void *);
extern "C" void func_001ADA00(void *, void *, void *, int, float);

static inline UnkStruct_0023D0F0_car * func_0023D0F0_inl1(unsigned char id)
{
    if (((CB3TrafficSystem *)&D_00527440)->VehicleIsValid(id)) {
        return *(UnkStruct_0023D0F0_car **)((char *)&D_00522660 + (id & 0xFF) * 0x180 + 0x1771C);
    }
    return 0;
}

static inline UnkStruct_0023D0F0_cb * func_0023D0F0_inl2(UnkStruct_D_00539D7C * g, unsigned char id)
{
    UnkStruct_0023D0F0_car * c;
    if (((CB3TrafficSystem *)&D_00527440)->VehicleIsValid(id)) {
        c = *(UnkStruct_0023D0F0_car **)((char *)g + id * 0x180);
    } else {
        c = 0;
    }
    if (c != 0) {
        if (c->field_0 == 4) return c->field_C; else return 0;
    } else return 0;
}

// 0x0023D0F0
extern "C" void func_0023D0F0(UnkStruct_0023D0F0 * self, UnkStruct_0023D0F0_row * row)
{
    if (self->field_6DC->field_1A14 == 0 || !func_001A87D0(row) || self->field_6E0->field_210 == 0) return;
    self->field_5C8 = row->field_26;
    func_0023E6E0(self, row, self->field_6E0->field_204, self->field_6D6);
    self->field_4EE0 = 0;
    self->field_4EE8 = 0;
    unsigned char id;
    int i;
    UnkStruct_D_00539D7C * g;
    int s4;
    UnkStruct_0023D0F0_cb * s3;
    int s2;
    UnkStruct_0023D0F0_ent * e;
    for (i = 0; i < row->field_2B; i++) {
        func_0023D410(self, row, (void *)(i));
    }
    for (s2 = 0; ; s2++) {
        if (!(s2 < self->field_4EE0)) {
            id = self->field_4F0D;
            if (id == 0xFF) return;
            UnkStruct_0023D0F0_car * c = func_0023D0F0_inl1(id);
            if (c != 0) {
                if (c->field_0 == 4) {
                    func_001ADA00(&D_0055E948, c->field_C, (void *)(0), 1, 0.0f);
                }
            }
            return;
        }
        e = (UnkStruct_0023D0F0_ent *)((char *)self + s2 * 0xC0);
        id = e->field_3D90;
        UnkStruct_0023D0F0_car * c2 = func_0023D0F0_inl1(id);
        if (c2 != 0) {
            if (c2->field_0 == 4) s3 = c2->field_C; else s3 = 0;
        } else s3 = 0;
        if (s3->field_2424 == 0) continue;
        g = &D_00539D7C;
        for (s4 = 0; s4 < self->field_4EE0; s4++) {
            if (s3->field_2424 == func_0023D0F0_inl2(g, ((UnkStruct_0023D0F0_ent *)((char *)self + s4 * 0xC0))->field_3D90)) break;
        }
        if (s4 < self->field_4EE0) {
            unsigned char * fp = &e->field_3D91;
            if (e->field_3D91 == 0 || ((UnkStruct_0023D0F0_ent *)((char *)self + s4 * 0xC0))->field_3D91 == 0) {
                *fp = 0;
                ((UnkStruct_0023D0F0_ent *)((char *)self + s4 * 0xC0))->field_3D91 = 0;
            }
        }
    }
}
