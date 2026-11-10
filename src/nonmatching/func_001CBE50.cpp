// NONMATCHING: func_001CBE50 -- retail 14 / ours 14 instructions, 3 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1CBE50..0x1CBE84). Unnamed; file B3VehiclePhysics.cpp per research/retail_names.csv (high).
// Marks body part a1 loose (state 2) when its state byte (+0xCC4 -> +0x4B2[a1]) is 0 or 1 (unsigned compare, as retail).
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_001CBE50_parts { unsigned char pad_0[0x4B2]; signed char field_4B2[8]; };   // [G] count
struct UnkStruct_001CBE50 { unsigned char pad_0[0xCC4]; UnkStruct_001CBE50_parts * field_CC4; };

// 0x001CBE50
extern "C" void func_001CBE50(UnkStruct_001CBE50 * self, int part)
{
    signed char * st = &self->field_CC4->field_4B2[part];
    if ((unsigned int)(int)*st < 2) {
        *st = 2;
    }
}
