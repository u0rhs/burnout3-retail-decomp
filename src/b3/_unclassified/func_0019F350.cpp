// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// func_0019F350 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (the cached local is a pointer to a sub-object at element+0x14 (UnkStruct_0019F350_e2 field_14, holding field_2C), not the element pointer).

// func_0019F350 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0019F350;
struct UnkStruct_0019F350_e0;
struct UnkStruct_0019F350_e1;
struct UnkStruct_0019F350_e2;

struct UnkStruct_0019F350_e2 {
    unsigned char pad_0[0x2C];
    UnkStruct_0019F350_e1 * field_2C;
};

struct UnkStruct_0019F350_e0 {
    unsigned char pad_0[0x14];
    UnkStruct_0019F350_e2 field_14;
    unsigned char pad_44[0x20];
    int field_64;
    unsigned char pad_68[0x8];
};

struct UnkStruct_0019F350_e1 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_0019F350 {
    unsigned char pad_0[0x4];
    UnkStruct_0019F350_e0 * field_4;
    unsigned char pad_8[0x8];
    short field_10;
    short field_12;
    unsigned char pad_14[0x8];
    signed char field_1C;
};

// 0x0019F350
extern "C" void func_0019F350(UnkStruct_0019F350 * self)
{
    UnkStruct_0019F350_e2* t = &self->field_4[self->field_1C].field_14;
    for (int i = 0; i < self->field_12; i++) {
        t->field_2C[self->field_10 + i].field_C = self->field_4[self->field_1C].field_64;
    }
}
