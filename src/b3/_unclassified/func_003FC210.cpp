// func_003FC210 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (flag branch returns a ternary (field_C0 ? call : 0); else returns the +8 sub-object call).

// lifter variant 0
// func_003FC210 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FC210;

struct UnkStruct_003FC210 {
    unsigned char pad_0[0xBC];
    unsigned char field_BC;
    unsigned char pad_BD[0x3];
    int field_C0;
};

extern "C" int func_00386080(void *, int);
extern "C" int func_0042B540(void *);

// 0x003FC210
extern "C" int func_003FC210(UnkStruct_003FC210 * self)
{
    if (self->field_BC != 0) {
        return self->field_C0 != 0 ? func_00386080((void *)(self->field_C0), 1) : 0;
    }
    return func_0042B540(((char *)self + 0x8));
}
