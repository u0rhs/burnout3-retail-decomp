// Hand-written; the lifter refused it (a71: [L] DNAT CGtNATDataManager::ResetFinaliseNATDataVariables; do-while over 8 slots, same slot struct as func_002310B0).

struct UnkStruct_00231850_e0 {
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

struct UnkStruct_00231850 {
    UnkStruct_00231850_e0 field_0[8];
};

extern "C" void func_0022D9F0(void *);

// [L] DNAT: CGtNATDataManager::ResetFinaliseNATDataVariables() (research/proto/new_names.csv, high)
// 0x00231850
extern "C" void ResetFinaliseNATDataVariables__17CGtNATDataManagerFv(UnkStruct_00231850 * self)
{
    int i = 0;
    do {
        UnkStruct_00231850_e0 * e = &self->field_0[i];
        e->field_0 = 4;
        e->field_4 = -1;
        e->field_8 = -1;
        e->field_C = -1;
        e->field_10 = -1;
        e->field_14 = -1;
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
        i++;
    } while (i < 8);
}
