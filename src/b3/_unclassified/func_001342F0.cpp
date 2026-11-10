// func_001342F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool return of an || value: return f == 1 || f == 4 (field re-read, not cached)).

// func_001342F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_001342F0;

struct UnkStruct_001342F0 {
    unsigned char pad_0[0x40];
    int field_40;
};

extern "C" bool func_001342F0(UnkStruct_001342F0 * self)
{
    return self->field_40 == 1 || self->field_40 == 4;
}
