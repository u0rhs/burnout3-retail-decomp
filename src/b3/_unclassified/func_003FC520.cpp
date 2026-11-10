// func_003FC520 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (flag-set branch first (BC != 0) with the inlined func_003FC5D0 body: early return on D8, then if (C8 == 6 || C8 == 4) C8 = 0 before the +8 call).

// lifter variant 0
// func_003FC520 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FC520;

struct UnkStruct_003FC520 {
    unsigned char pad_0[0xBC];
    unsigned char field_BC;
    unsigned char pad_BD[0xB];
    int field_C8;
    unsigned char pad_CC[0xC];
    int field_D8;
    unsigned char pad_DC[0xC];
    unsigned char field_E8;
    unsigned char pad_E9[0x1];
    unsigned char field_EA;
};

extern "C" void func_0042B590(void *);
extern "C" void func_0042B5A0(void *);

// 0x003FC520
extern "C" void func_003FC520(UnkStruct_003FC520 * self)
{
    if (self->field_D8 == -1) {
        return;
    }
    self->field_E8 = (self->field_E8 | 1);
    self->field_EA = 1;
    if (self->field_BC != 0) {
        if (self->field_C8 == 6) {
        if (self->field_D8 == -1) return;
        if (self->field_BC != 0) {
            if (self->field_C8 == 6 || self->field_C8 == 4) self->field_C8 = 0;
        } else {
            func_0042B5A0(((char *)self + 0x8));
        }
        }
    } else {
        func_0042B590(((char *)self + 0x8));
    }
}
