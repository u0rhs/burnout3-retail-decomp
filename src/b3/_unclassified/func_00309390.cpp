// func_00309390 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (pointer local to the e1 element (&p1->field_7E0[p1->field_9B0]) instead of a cached index; ++ increment).

// func_00309390 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_00309390;
struct UnkStruct_00309390_a2;
struct UnkStruct_00309390_e0;
struct UnkStruct_00309390_e1;

struct UnkStruct_00309390_e0 {
    unsigned char pad_0[0x20];
    u_long128 field_20;
};

struct UnkStruct_00309390_e1 {
    u_long128 field_0;
    u_long128 field_10;
    unsigned char pad_20[0x10];
};

struct UnkStruct_00309390_a2 {
    unsigned char pad_0[0x7B0];
    UnkStruct_00309390_e0 field_7B0[1];  // [G] element count unknown
    UnkStruct_00309390_e1 field_7E0[1];  // [G] element count unknown
    unsigned char pad_810[0x170];
    int field_980[1];  // [G] element count unknown
    unsigned char pad_984[0x2C];
    int field_9B0;
};

struct UnkStruct_00309390 {
    unsigned char pad_0[0x60];
    u_long128 field_60;
    u_long128 field_70;
    u_long128 field_80;
};

extern "C" void func_00309390(UnkStruct_00309390 * self, int p0, UnkStruct_00309390_a2 * p1)
{
    UnkStruct_00309390_e1 * e = &p1->field_7E0[p1->field_9B0];
    p1->field_7B0[p1->field_9B0].field_20 = self->field_60;
    e->field_0 = self->field_70;
    e->field_10 = self->field_80;
    p1->field_980[p1->field_9B0] = p0;
    p1->field_9B0++;
}
