// func_0038BCE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (constant address hoisted into a local before the null test; three guards merged with || into one return 1).

// lifter variant 0
// func_0038BCE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038BCE0_1;
struct UnkStruct_D_0064D3B0;

struct UnkStruct_D_0064D3B0 {
    unsigned char pad_0[0x10C8];
    int field_10C8;
    unsigned char pad_10CC[0x1364];
    UnkStruct_0038BCE0_1 * field_2430;
};

struct UnkStruct_0038BCE0_1 {
    unsigned char pad_0[0x218];
    signed char field_218;
};

extern UnkStruct_D_0064D3B0 D_0064D3B0;

// 0x0038BCE0
extern "C" int func_0038BCE0(int n0, int p0)
{
    UnkStruct_D_0064D3B0 *p = &D_0064D3B0;
    if (p == 0 || p0 != p->field_2430->field_218 || p->field_10C8 != 2) {
        return 1;
    }
    return 0;
}
