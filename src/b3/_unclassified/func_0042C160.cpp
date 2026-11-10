// func_0042C160 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (nested ifs: inner if (b != 0) {} else { return x>0; } with outer else return 0 and a final return 0).

// func_0042C160 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042C160;

struct UnkStruct_0042C160 {
    unsigned char pad_0[0x238];
    int field_238;
    unsigned char pad_23C[0x1C];
    int field_258;
    int field_25C;
};

extern "C" bool func_0042C160(UnkStruct_0042C160 * self)
{
    if (self->field_25C == 9) {
        if (self->field_238 != 0) {
        } else {
            return self->field_258 > 0;
        }
    } else {
        return 0;
    }
    return 0;
}
