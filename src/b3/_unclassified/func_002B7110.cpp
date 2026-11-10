// FixUp__18CB3EnvironmentDataFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (offset fields typed void* (pointer fixup: field = field + self); no early return).

// lifter variant 0
// FixUp__18CB3EnvironmentDataFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002B7110;

struct UnkStruct_002B7110 {
    unsigned char pad_0[0x98];
    void * field_98;
    void * field_9C;
    void * field_A0;
    void * field_A4;
};

extern "C" void FixUp__10CGtTextureFv(void *);

// 0x002B7110
extern "C" void FixUp__18CB3EnvironmentDataFv(UnkStruct_002B7110 * self)
{
    if (self->field_98 != 0) {
        self->field_98 = (void *)((int)self->field_98 + (int)self);
        FixUp__10CGtTextureFv(self->field_98);
    }
    if (self->field_9C != 0) {
        self->field_9C = (void *)((int)self->field_9C + (int)self);
        FixUp__10CGtTextureFv(self->field_9C);
    }
    if (self->field_A0 != 0) {
        self->field_A0 = (void *)((int)self->field_A0 + (int)self);
        FixUp__10CGtTextureFv(self->field_A0);
    }
    if (self->field_A4 != 0) {
        self->field_A4 = (void *)((int)self->field_A4 + (int)self);
        FixUp__10CGtTextureFv(self->field_A4);
    }
}
