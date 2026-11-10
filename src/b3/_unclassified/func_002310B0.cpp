// Hand-written; the lifter refused it (a71: find first free slot (field_14<0, stride 0x90) and init it; callee func_0022D9F0 takes only the member; a2 store via &e->field_14 local).

struct UnkStruct_002310B0_e0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    float field_2C;
    int field_30;
    unsigned char field_34;
    unsigned char pad_35[0x1F];
    float field_54;
    unsigned char field_58;
    unsigned char field_59;
    unsigned char field_5A;
    unsigned char field_5B;
    unsigned char field_5C;
    unsigned char field_5D;
    unsigned char field_5E;
    unsigned char pad_5F[0x1];
    unsigned char field_60[0x10];
    unsigned char field_70[0x10];
    unsigned char field_80[0x10];
};

struct UnkStruct_002310B0 {
    UnkStruct_002310B0_e0 field_0[8];
};

extern "C" void func_0022D9F0(void *);

// 0x002310B0
extern "C" void func_002310B0(UnkStruct_002310B0 * self, int p0)
{
    int i;
    for (i = 0; i < 8; i++) {
        UnkStruct_002310B0_e0 * e = &self->field_0[i];
        int * pp = &e->field_14;
        if (e->field_14 < 0) {
            e->field_0 = 4;
            e->field_4 = -1;
            e->field_8 = -1;
            e->field_C = -1;
            e->field_10 = -1;
            *pp = p0;
            e->field_18 = -1;
            e->field_1C = 0;
            e->field_20 = 0;
            e->field_24 = -1;
            e->field_28 = -1;
            e->field_2C = -1.0f;
            e->field_30 = 0;
            e->field_34 = 0;
            e->field_54 = -1.0f;
            e->field_58 = 0;
            e->field_59 = 0;
            e->field_5A = 0;
            e->field_5B = 0;
            e->field_5C = 0;
            e->field_5D = 0;
            e->field_5E = 0;
            func_0022D9F0(e->field_60);
            func_0022D9F0(e->field_70);
            func_0022D9F0(e->field_80);
            return;
        }
    }
}
