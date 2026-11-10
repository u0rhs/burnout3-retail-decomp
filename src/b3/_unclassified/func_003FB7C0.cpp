// func_003FB7C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (mask (4/2/1) from a static inline helper (daddiu+andi), held in an unsigned char local before the &).

// lifter variant 0
// func_003FB7C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FB7C0;
struct UnkStruct_003FB7C0_e0;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0064D370;

struct UnkStruct_D_0064D370 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003FB7C0_e0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003FB7C0 {
    unsigned char pad_0[0x6C];
    int field_6C;
    unsigned char pad_70[0x44];
    UnkStruct_003FB7C0_e0 * field_B4;
    unsigned char pad_B8[0x4];
    unsigned char field_BC;
    unsigned char pad_BD[0x1B];
    int field_D8;
};

extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" int func_00131E40(void *);

// [G] an inlined helper (real name unknown, placeholder): its merged constant returns give retail's daddiu + andi 0xFF
static inline unsigned char func_003FB7C0_inl0()
{
    if (D_0064D370.field_0 != 0) {
        if (func_00131E40(&D_004EE040) != 0) {
            return 2;
        }
        return 1;
    }
    return 4;
}

// 0x003FB7C0
extern "C" bool func_003FB7C0(UnkStruct_003FB7C0 * self)
{
    if (self->field_D8 == -1) {
        return 0;
    }
    if (self->field_BC == 0) {
        return 1;
    }
    if ((unsigned int)self->field_D8 >= (unsigned int)self->field_6C) {
        return 0;
    }
    unsigned char m = func_003FB7C0_inl0();
    return (m & self->field_B4[self->field_D8].field_14) != 0;
}
