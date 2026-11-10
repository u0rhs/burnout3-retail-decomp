// func_0042AFC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (element pointer local e=&D_00522660.field_12E5E0[t0]; only diff left is the diff tool not masking %lo(D_0012FD49)=-695, bytes identical).

// from build/vt\try_func_0042AFC0_best.cpp
// func_0042AFC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042AFC0;
struct UnkStruct_0042AFC0_e0;
struct UnkStruct_D_00522660;

struct UnkStruct_0042AFC0_e0 {
    unsigned char pad_0[0x1769];
    unsigned char field_1769;
    unsigned char pad_176A[0xCF6];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12E5E0];
    UnkStruct_0042AFC0_e0 field_12E5E0[1];  // [G] element count unknown
};

struct UnkStruct_0042AFC0 {
    unsigned char pad_0[0x9E];
    signed char field_9E;
};

extern UnkStruct_D_00522660 D_00522660;

// 0x0042AFC0
extern "C" void func_0042AFC0(UnkStruct_0042AFC0 * self, int p0)
{
    signed char t0 = self->field_9E;
    if (t0 > -1) {
        UnkStruct_0042AFC0_e0 *e = &D_00522660.field_12E5E0[t0];
        e->field_1769 = p0;
    }
}
