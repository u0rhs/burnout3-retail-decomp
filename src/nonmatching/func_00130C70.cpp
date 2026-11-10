// NONMATCHING: func_00130C70 -- retail 34 / ours 32 instructions, 3 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x130C70..0x130CF4). Unnamed; file B3FrontEnd.cpp per research/retail_names.csv (high).
// Stops the front end's video (+0x1C8) as func_00131100 does, unless +0x2F8 is already 0x18; +0x2F8 = 0x18.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_00130C70 {
    unsigned char pad_0[0x1C8];
    unsigned char field_1C8[0x130];           // [C] the CGtVideoDecoder [G] size
    int field_2F8;
    unsigned char pad_2FC[0x1C];
    unsigned char field_318[0x10];            // [C] a CGtLinearMalloc
};

extern "C" void func_00324ED0(void *);
extern "C" int func_00324EE0(void *);
extern "C" void Update__15CGtVideoDecoderFv(void *);
extern "C" void Release__15CGtVideoDecoderFv(void *);
extern "C" void Destroy__15CGtLinearMallocFv(void *);

// 0x00130C70
extern "C" void func_00130C70(UnkStruct_00130C70 * self)
{
    if (self->field_2F8 != 0x18) {
        func_00324ED0(self->field_1C8);
        while (func_00324EE0(self->field_1C8) == 0) {
            Update__15CGtVideoDecoderFv(self->field_1C8);
        }
        Release__15CGtVideoDecoderFv(self->field_1C8);
        Destroy__15CGtLinearMallocFv(self->field_318);
    }
    self->field_2F8 = 0x18;
}
