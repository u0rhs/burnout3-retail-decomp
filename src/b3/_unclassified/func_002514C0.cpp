// FixUp__10CGtTextureFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (offset->pointer fixups on void* fields; sub-struct at +0x34 via hoisted pointer; element-pointer loop; record array starts at +0x10 (field_34 per 0x40 element) walked by pointer).

// lifter variant 0
// FixUp__10CGtTextureFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002514C0;
struct UnkStruct_002514C0_2;
struct UnkStruct_002514C0_e1;

struct UnkStruct_002514C0_e1 {
    unsigned char pad_0[0x34];
    int field_34;
    unsigned char pad_38[0x8];
};

struct UnkStruct_002514C0_2 {
    int field_0;
    unsigned char pad_4[0xC];
    UnkStruct_002514C0_e1 field_10[1];  // [G] element count unknown (count in field_0)
};


// [G] sub-struct at +0x34: retail holds self+0x34 in a2 for field_6C / field_70[]
struct UnkStruct_002514C0_34 {
    unsigned char pad_0[0x38];
    void * field_38;
    void * field_3C[7];
};
struct UnkStruct_002514C0 {
    void * field_0;
    void * field_4;
    void * field_8;
    unsigned char pad_C[0x18];
    UnkStruct_002514C0_2 * field_24;
    unsigned char pad_28[0xC];
    UnkStruct_002514C0_34 field_34;
};
// 0x002514C0
extern "C" void FixUp__10CGtTextureFv(UnkStruct_002514C0 * self)
{
    UnkStruct_002514C0_34 * sub = &self->field_34;
    if (self->field_0 != 0) {
        self->field_0 = (void *)((int)self->field_0 + (int)self);
    }
    if (self->field_4 != 0) {
        self->field_4 = (void *)((int)self->field_4 + (int)self);
    }
    if (self->field_8 != 0) {
        self->field_8 = (void *)((int)self->field_8 + (int)self);
    }
    if (self->field_24 != 0) {
        self->field_24 = (UnkStruct_002514C0_2 *)((int)self->field_24 + (int)self);
    }
    if (sub->field_38 != 0) {
        sub->field_38 = (void *)((int)sub->field_38 + (int)self);
    }
    for (unsigned int i = 0; i < 7; i++) {
        void ** pp = &sub->field_3C[i];
        if (*pp != 0) {
            *pp = (void *)((int)*pp + (int)self);
        }
    }
    UnkStruct_002514C0_2 * t6 = self->field_24;
    unsigned int n = t6->field_0;
    UnkStruct_002514C0_e1 * e = t6->field_10;
    for (unsigned int i1 = 0; i1 < n; i1++) {
        e->field_34 += (int)self;
        e++;
    }
}
