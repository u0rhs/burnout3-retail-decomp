// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// FixDown__10CGtTextureFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (pointer-typed fields (beqz layout); sub-struct at +0x34 via local pointer; count hoisted; element pointer stepped (elements at +0x10, field_34); counter declared before the element pointer).

struct UnkStruct_002515A0_e0 {
    unsigned char pad_0[0x34];
    int field_34;
    unsigned char pad_38[0x8];
};

struct UnkStruct_002515A0_1 {
    unsigned int field_0;
    unsigned char pad_4[0xC];
    UnkStruct_002515A0_e0 field_10[1];  // [G] element count unknown
};

struct UnkStruct_002515A0_34 {
    unsigned char pad_0[0x38];
    char * field_38;
    char * field_3C[7];
};

struct UnkStruct_002515A0 {
    char * field_0;
    char * field_4;
    char * field_8;
    unsigned char pad_C[0x18];
    UnkStruct_002515A0_1 * field_24;
    unsigned char pad_28[0xC];
    UnkStruct_002515A0_34 field_34;
};

// 0x002515A0
extern "C" void FixDown__10CGtTextureFv(UnkStruct_002515A0 * self)
{
    int d = -(int)self;
    UnkStruct_002515A0_34 * s = &self->field_34;
    UnkStruct_002515A0_1 * t = self->field_24;
    unsigned int n = t->field_0;
    unsigned int i;
    UnkStruct_002515A0_e0 * e = t->field_10;
    for (i = 0; i < n; i++, e++) {
        e->field_34 += d;
    }
    if (s->field_38 != 0) s->field_38 += d;
    for (unsigned int j = 0; j < 7; j++) {
        if (s->field_3C[j] != 0) s->field_3C[j] += d;
    }
    if (self->field_0 != 0) self->field_0 += d;
    if (self->field_4 != 0) self->field_4 += d;
    if (self->field_8 != 0) self->field_8 += d;
    if (self->field_24 != 0) self->field_24 = (UnkStruct_002515A0_1 *)((char *)self->field_24 + d);
}
