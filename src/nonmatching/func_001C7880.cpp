// NONMATCHING: func_001C7880 -- retail 58 / ours 52 instructions, 11 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1C7880..0x1C7964). Unnamed (no retail_names.csv row; next to
// func_001C6F90). [L] the transmission's reset by its stores: shift state cleared, rev limit +0x40 = +0x38, the random
// stir seeded (+0x68 = 0xFD462907, +0x6C = 0x02B9D6F8), gear 0, +0x84 = the number of positive ratios after the first
// (at most 6), the car pointer at +0x90 (a1; Prepare__17CB3RaceCarPhysicsFP10CB3RaceCar passes this). Returns 1.
// TRACK: clean
// EQUIV: [L] written from the asm: both store blocks (retail clears the state before and after the ratio count),
// the NaN-exact `!(ratio <= 0)` loop test

struct UnkStruct_001C7880 {
    unsigned char pad_0[0x4];
    float field_4[8];                         // [C] the gear ratios; the count loop reads field_4[+0x84 + 1]
    unsigned char pad_24[0x14];
    float field_38;
    unsigned char pad_3C[0x4];
    float field_40;
    unsigned char pad_44[0x10];
    float field_54;
    float field_58;
    int field_5C;
    int field_60;
    unsigned char pad_64[0x4];
    int field_68;
    int field_6C;
    unsigned char pad_70[0x4];
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    float field_88;
    float field_8C;
    void * field_90;
};

// 0x001C7880
extern "C" int func_001C7880(UnkStruct_001C7880 * t, void * car)
{
    *(int *)&t->field_54 = 0;
    *(int *)&t->field_58 = 0;
    t->field_5C = 0;
    t->field_60 = 0;
    t->field_40 = t->field_38;
    t->field_6C = 0x02B9D6F8;
    t->field_68 = (int)0xFD462907;
    t->field_74 = 0;
    t->field_78 = 0;
    t->field_7C = 0;
    t->field_80 = 0;
    t->field_84 = 0;
    while (!(t->field_4[t->field_84 + 1] <= 0.0f) && t->field_84 < 6) {
        t->field_84 = t->field_84 + 1;
    }
    *(int *)&t->field_54 = 0;
    *(int *)&t->field_58 = 0;
    t->field_5C = 0;
    t->field_60 = 0;
    t->field_40 = t->field_38;
    t->field_6C = 0x02B9D6F8;
    t->field_68 = (int)0xFD462907;
    t->field_74 = 0;
    t->field_78 = 0;
    t->field_7C = 0;
    t->field_80 = 0;
    *(int *)&t->field_8C = 0;
    *(int *)&t->field_88 = 0;
    t->field_90 = car;
    return 1;
}
