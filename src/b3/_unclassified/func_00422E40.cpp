// func_00422E40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (early return; i/j index if-chain; element+0x1B24 byte offset; field_178 != 0 arm first; func_003CCFB0 takes 3 args (phantom a3/t0)).

// lifter variant 0
// func_00422E40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00422E40;
struct UnkStruct_00422E40_e0;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064CE40;

struct UnkStruct_00422E40_e0 {
    unsigned char pad_0[0x1B24];
    unsigned char field_1B24;
    unsigned char pad_1B25[0xCAB];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12A980];
    UnkStruct_00422E40_e0 field_12A980[1];  // [G] element count unknown
};

struct UnkStruct_D_0064CE40 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00422E40 {
    unsigned char pad_0[0x178];
    unsigned char field_178;
};

extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064CE40 D_0064CE40;

extern "C" int func_003CCFB0(void *, unsigned char, unsigned char);

// 0x00422E40
extern "C" int func_00422E40(UnkStruct_00422E40 * self, int p0, int p1)
{
    if (p0 > 0 && self->field_178 == 0) {
        return 0;
    }
    int i;
    int j;
    if (p1 != 0) {
        if (p0 == 0) {
            i = 1;
            j = 0;
        } else {
            i = 0;
            j = 1;
        }
    } else {
        if (p0 == 0) {
            i = 0;
            j = 1;
        } else {
            i = 1;
            j = 0;
        }
    }
    // [G] element base + byte offset (not ->field_1B24): retail adds base + i*0x27D0, then the 0x12C4A4 offset
    unsigned char a = *((unsigned char *)&D_00522660.field_12A980[i] + 0x1B24);
    unsigned char b;
    if (self->field_178 != 0) {
        b = *((unsigned char *)&D_00522660.field_12A980[j] + 0x1B24);
    } else {
        b = 0;
    }
    switch (func_003CCFB0(&D_0064CE40, a, b)) {
    case 4:
        return 7;
    case 6:
        return 6;
    case 5:
        return 5;
    default:
        return 0;
    }
}
