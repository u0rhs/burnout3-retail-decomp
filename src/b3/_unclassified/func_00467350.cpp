// func_00467350 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (const self (its field_0 load hoists above the field_70 store); 3-arg callback field_2C(self->field_0, p0, p1); (D!=0)==false guard; && chain for 11/12/13).

// from build/vt\try_func_00467350_best.cpp
// func_00467350 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00467350;
struct UnkStruct_00467350_2;
struct UnkStruct_00467350_4;
struct UnkStruct_D_004E2FC8;
struct UnkStruct_D_004E2FCC;

struct UnkStruct_D_004E2FCC {
    UnkStruct_00467350_4 * field_0;
};

struct UnkStruct_D_004E2FC8 {
    UnkStruct_00467350_2 * field_0;
};

struct UnkStruct_00467350_2 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x64];
    int field_70;
};

struct UnkStruct_00467350_4 {
    unsigned char pad_0[0x2C];
    void (*field_2C)(int, int, int);
};

struct UnkStruct_00467350 {
    int field_0;
};

extern UnkStruct_D_004E2FCC D_004E2FCC;
extern UnkStruct_D_004E2FC8 D_004E2FC8;

extern "C" void * memcpy(void *, const void *, unsigned int);

extern "C" int func_00467350(const UnkStruct_00467350 * self, int p0, int p1)
{
    if ((D_004E2FCC.field_0 != 0) == false) {
        return 2;
    }
    if (self == 0) {
        return 12;
    }
    if (D_004E2FC8.field_0->field_0 != 0) {
        return 13;
    }
    D_004E2FC8.field_0->field_0 = 10;
    D_004E2FC8.field_0->field_4 = 29;
    UnkStruct_00467350_2 * t0 = D_004E2FC8.field_0;
    int t1 = t0->field_0;
    if (t1 != 11 && t1 != 12 && t1 != 13) {
        t0->field_8 = 0;
    }
    memcpy((char *)D_004E2FC8.field_0 + 0xC, self, 96);
    D_004E2FC8.field_0->field_70 = p1;
    D_004E2FCC.field_0->field_2C(self->field_0, p0, p1);
    return 0;
}
