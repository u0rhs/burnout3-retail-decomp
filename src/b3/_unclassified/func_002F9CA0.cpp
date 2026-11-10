// Malloc__15CGtLinearMallocFUi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (fields C/10 unsigned; mask m=field_14-1 and aligned value a computed once as locals; early return).

struct UnkStruct_002F9CA0 {
    unsigned char pad_0[0xC];
    unsigned int field_C;
    unsigned int field_10;
    int field_14;
    int field_18;
};
extern "C" int Malloc__15CGtLinearMallocFUi(UnkStruct_002F9CA0 * self, int p0)
{
    int m = self->field_14 - 1;
    int a = (self->field_10 + m) & ~m;
    self->field_10 = a + p0;
    if (self->field_10 > self->field_C) {
        self->field_18 = 0;
        return 0;
    }
    self->field_18 = a;
    return self->field_18;
}
