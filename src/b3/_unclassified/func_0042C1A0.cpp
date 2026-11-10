// func_0042C1A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (else-if chain on field_265/field_264 with 'if (field_258 < K) return 1;' arms sharing one trailing return 0).

// lifter variant 0
// func_0042C1A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042C1A0;

struct UnkStruct_0042C1A0 {
    unsigned char pad_0[0x238];
    int field_238;
    unsigned char pad_23C[0x1C];
    int field_258;
    int field_25C;
    unsigned char pad_260[0x4];
    unsigned char field_264;
    unsigned char field_265;
};

extern "C" int func_0042C1A0(UnkStruct_0042C1A0 * self)
{
    if (self->field_25C != 9) {
        return 0;
    }
    if (self->field_238 != 0) {
        return 0;
    }
    if (self->field_265 == 0) {
        if (self->field_258 < 4) {
            return 1;
        }
    } else if (self->field_264 == 0) {
        if (self->field_258 < 5) {
            return 1;
        }
    } else {
        if (self->field_258 < 6) {
            return 1;
        }
    }
    return 0;
}
