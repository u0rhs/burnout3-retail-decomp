// func_003FC5D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (early return on D8; flag-set branch first with if (C8 == 6 || C8 == 4) C8 = 0, else the +8 call (the body func_003FC520 inlines)).

struct UnkStruct_003FC5D0;

struct UnkStruct_003FC5D0 {
    unsigned char pad_0[0xBC];
    unsigned char field_BC;
    unsigned char pad_BD[0xB];
    int field_C8;
    unsigned char pad_CC[0xC];
    int field_D8;
};

extern "C" void func_0042B5A0(void *);

// 0x003FC5D0
// [L] func_003FC520 inlines this body after its own field_C8 == 6 test.
extern "C" void func_003FC5D0(UnkStruct_003FC5D0 * self)
{
    if (self->field_D8 == -1) {
        return;
    }
    if (self->field_BC != 0) {
        if (self->field_C8 == 6 || self->field_C8 == 4) {
            self->field_C8 = 0;
        }
    } else {
        func_0042B5A0(((char *)self + 0x8));
    }
}
