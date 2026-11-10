// NONMATCHING: func_001CBD80 -- retail 49 / ours 47 instructions, 5 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1CBD80..0x1CBE40). Unnamed; file B3VehiclePhysics.cpp per
// research/retail_names.csv (high). Detaches body part a1 when its state byte (+0xCC4 -> +0x4B2[a1]) is 2: state 3,
// then func_001B86A0 (D_0055EF70: [L] the physics manager, as func_001CBCE0) makes the loose piece; with one, it is
// prepared (func_00333990) and func_0027D240 spawns at the piece's position with 100.0; without, the state goes back to 2.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_001CBD80_parts { unsigned char pad_0[0x4B2]; signed char field_4B2[8]; };   // [G] count
struct UnkStruct_001CBD80_body { unsigned char pad_0[0x30]; unsigned char field_30[0x10]; };
struct UnkStruct_001CBD80_piece { unsigned char pad_0[0x204]; UnkStruct_001CBD80_body * field_204; };
struct UnkStruct_001CBD80 { unsigned char pad_0[0xCC4]; UnkStruct_001CBD80_parts * field_CC4; };

extern unsigned char D_0055EF70[];
extern unsigned char D_01E78510[];

extern "C" UnkStruct_001CBD80_piece * func_001B86A0(void *, UnkStruct_001CBD80 *, int, int);
extern "C" void func_00333990(UnkStruct_001CBD80_piece *);
extern "C" void func_0027D240(void *, void *, float, int);

// 0x001CBD80
extern "C" void func_001CBD80(UnkStruct_001CBD80 * self, int part)
{
    signed char * st = &self->field_CC4->field_4B2[part];
    if (*st != 2) {
        return;
    }
    *st = 3;
    UnkStruct_001CBD80_piece * p = func_001B86A0(D_0055EF70, self, part, 1);
    if (p != 0) {
        func_00333990(p);
        func_0027D240(D_01E78510, p->field_204->field_30, 100.0f, part);
        return;
    }
    self->field_CC4->field_4B2[part] = 2;
}
