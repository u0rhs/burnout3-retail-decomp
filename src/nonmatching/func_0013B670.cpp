// NONMATCHING: func_0013B670 -- retail 12 / ours 19 instructions, 19 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x13B670..0x13B69C). Unnamed (no retail_names.csv row). Adds a1 to +0x40 and clamps it to
// [0, 0x773593FF] (retail: pmaxw / pminw, signed; the sum is stored, re-read, clamped and stored again).
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_0013B670 { unsigned char pad_0[0x40]; int field_40; };

// 0x0013B670
extern "C" void func_0013B670(UnkStruct_0013B670 * self, int d)
{
    self->field_40 = self->field_40 + d;
    int v = self->field_40;
    if (v < 0) {
        v = 0;
    }
    if (v > 0x773593FF) {
        v = 0x773593FF;
    }
    self->field_40 = v;
}
