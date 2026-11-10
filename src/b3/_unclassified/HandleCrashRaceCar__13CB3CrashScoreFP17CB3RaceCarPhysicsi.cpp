// Hand-written; the lifter refused it (near20: field_228 is a 2D float[][66] array (row base car*264 computed first), indexed [car][field_4AF]).

// HandleCrashRaceCar__13CB3CrashScoreFP17CB3RaceCarPhysicsi -- [L] DNAT: CB3CrashScore::HandleCrashRaceCar(CB3RaceCarPhysics*,int) (research/proto/new_names.csv, high)
struct UnkStruct_003CD4D0_p {
    unsigned char pad_0[0x1960];
    unsigned long field_1960;
    unsigned char pad_1968[0x44];
    signed char field_19AC;
};
struct UnkStruct_003CD4D0_c {
    unsigned char pad_0[0x13F4];
    UnkStruct_003CD4D0_p *field_13F4;
};
struct UnkStruct_003CD4D0 {
    unsigned char pad_0[0x18];
    UnkStruct_003CD4D0_c *field_18[1];
    unsigned char pad_1C[0x104];
    int field_120[1];
    unsigned char pad_124[0x104];
    float field_228[1][66];
    unsigned char pad_330[0x17F];
    unsigned char field_4AF;
    unsigned char field_4B0[1];
};
extern unsigned long D_004EE040[];
extern int D_005190A8[];

static inline int func_003CD4D0_inl1(UnkStruct_003CD4D0 * self, UnkStruct_003CD4D0_c * p1, unsigned char n)
{
    for (int i = 0; i < n; i++) {
        if (self->field_18[i] == p1) return i;
    }
    return -1;
}

// 0x003CD4D0
extern "C" void HandleCrashRaceCar__13CB3CrashScoreFP17CB3RaceCarPhysicsi(UnkStruct_003CD4D0 * self, int p1_)
{
    UnkStruct_003CD4D0_c * p1 = (UnkStruct_003CD4D0_c *)p1_;
    unsigned char n = self->field_4AF;
    if (func_003CD4D0_inl1(self, p1, n) == -1) {
        UnkStruct_003CD4D0_p *p = p1->field_13F4;
        int car = p->field_19AC;
        unsigned long id = p->field_1960;
        int j;
        for (j = 0; j < 0x80; j++) {
            if (id == D_004EE040[j + 0x6000 - 0xAB3]) goto found;
        }
    append:
        self->field_18[self->field_4AF] = p1;
        self->field_4AF = self->field_4AF + 1;
        return;
    found:
        self->field_4B0[n] = 1;
        self->field_120[self->field_4AF] = D_005190A8[j];
        self->field_228[car][self->field_4AF] = 100.0f;
        goto append;
    }
}
