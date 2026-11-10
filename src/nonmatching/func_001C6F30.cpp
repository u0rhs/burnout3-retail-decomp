// NONMATCHING: func_001C6F30 -- retail 23 / ours 23 instructions, 6 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1C6F30..0x1C6F88). Unnamed (no retail_names.csv row; next to
// func_001C6F90, the transmission update). Picks the lowest gear from 1 whose rpm (+0x20 x speed / f12 x ratio) is at
// most the upshift rpm (D_004E0D80 x +0x28), stores that rpm at +0x54 and returns the gear (up to +0x84). Called with
// (transmission, f12, the car's speed lane) by ResetOnTrack and B3AICarPhysics_001D1670.
// TRACK: clean
// EQUIV: [L] written from the asm. [C] retail stores +0x54 from an FPR the loop never set when +0x84 <= 1 (f3 is
// whatever the caller left); the uninitialised local here is the same

struct UnkStruct_001C6F30 {
    unsigned char pad_0[0x4];
    float field_4[7];                         // [C] the gear ratios (as func_001C6F90)
    float field_20;
    unsigned char pad_24[0x4];
    float field_28;
    unsigned char pad_2C[0x28];
    float field_54;
    unsigned char pad_58[0x2C];
    int field_84;
};

extern float D_004E0D80;                      // [C] gp-relative

// 0x001C6F30
extern "C" int func_001C6F30(UnkStruct_001C6F30 * t, float p0, float p1)
{
    float s = p1 / p0;
    float up = D_004E0D80 * t->field_28;
    float r;
    int g;
    for (g = 1; g < t->field_84; g++) {
        r = t->field_20 * (s * t->field_4[g]);
        if (r <= up) {
            break;
        }
    }
    t->field_54 = r;
    return g;
}
