// NONMATCHING: func_001CBC70 -- retail 27 / ours 24 instructions, 7 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1CBC70..0x1CBCD8). Unnamed; file B3VehiclePhysics.cpp per research/retail_names.csv (high).
// [L] the vehicle's register step (a1 forwarded to func_001ABE40 [C]): unless +0x210 is set, func_001ABE40, then registers the vehicle with D_0064A8F0 and
// D_0064B940 (func_00354CF0), clears +0x116B and keeps the body's height (+0x204 -> +0x30, y lane) at +0x116C.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_001CBC70_q { float x, y, z, w; };
struct UnkStruct_001CBC70_body { unsigned char pad_0[0x30]; UnkStruct_001CBC70_q field_30; };
struct UnkStruct_001CBC70 {
    unsigned char pad_0[0x204];
    UnkStruct_001CBC70_body * field_204;
    unsigned char pad_208[0x8];
    unsigned char field_210;
    unsigned char pad_211[0x116B - 0x211];
    unsigned char field_116B;
    float field_116C;
};

extern unsigned char D_0064A8F0[];
extern unsigned char D_0064B940[];

extern "C" void func_001ABE40(void *, int);   // [C] proven: (self, int p0); retail forwards this function's a1
extern "C" void func_00354CF0(void *, void *);

// 0x001CBC70
extern "C" void func_001CBC70(UnkStruct_001CBC70 * self, int p0)
{
    if (self->field_210 != 0) {
        return;
    }
    func_001ABE40(self, p0);
    func_00354CF0(D_0064A8F0, self);
    func_00354CF0(D_0064B940, self);
    self->field_116B = 0;
    self->field_116C = self->field_204->field_30.y;   // retail: a 16-byte copy read at +0x4
}
