// func_003FBBE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (callee func_0042B550 returns bool; its result returned directly).

// func_003FBBE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FBBE0;

struct UnkStruct_003FBBE0 {
    unsigned char pad_0[0xBC];
    unsigned char field_BC;
    unsigned char pad_BD[0x2B];
    unsigned char field_E8;
};

extern "C" bool func_0042B550(void *);

// 0x003FBBE0
extern "C" bool func_003FBBE0(UnkStruct_003FBBE0 * self)
{
    if (self->field_BC != 0) {
        return ((self->field_E8 & 1) != 0);
    }
    return func_0042B550(((char *)self + 0x8));
}
