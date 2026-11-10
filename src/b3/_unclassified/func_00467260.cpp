// func_00467260 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool temp (sltu) for the D_004E2FCC test; const self; callback takes (self->field_0, p0, p1)).

// from build/vt\try_func_00467260_best.cpp
// func_00467260 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00467260;
struct UnkStruct_00467260_2;
struct UnkStruct_00467260_4;
struct UnkStruct_D_004E2FC8;
struct UnkStruct_D_004E2FCC;

struct UnkStruct_D_004E2FCC {
    UnkStruct_00467260_4 * field_0;
};

struct UnkStruct_D_004E2FC8 {
    UnkStruct_00467260_2 * field_0;
};

struct UnkStruct_00467260_2 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x64];
    int field_70;
};

struct UnkStruct_00467260_4 {
    unsigned char pad_0[0x30];
    int field_30;
};

struct UnkStruct_00467260 {
    int field_0;
};

extern UnkStruct_D_004E2FCC D_004E2FCC;
extern UnkStruct_D_004E2FC8 D_004E2FC8;

extern "C" void * memcpy(void *, const void *, unsigned int);

// 0x00467260
extern "C" int func_00467260(const UnkStruct_00467260 * self, int p0, int p1)
{
    bool v = D_004E2FCC.field_0 != 0;
    if (v == false) {
        return 2;
    }
    if (self == 0) {
        return 12;
    }
    if (D_004E2FC8.field_0->field_0 != 0) {
        return 13;
    }
    D_004E2FC8.field_0->field_0 = 9;
    D_004E2FC8.field_0->field_4 = 28;
    UnkStruct_00467260_2 * t0 = D_004E2FC8.field_0;
    int t1 = t0->field_0;
    if (t1 != 11) {
        if (t1 != 12) {
            if (t1 != 13) {
                t0->field_8 = 0;
            }
        }
    }
    memcpy(((char *)D_004E2FC8.field_0 + 0xC), self, 96);
    D_004E2FC8.field_0->field_70 = p1;
    ((void (*)(int, int, int))D_004E2FCC.field_0->field_30)(self->field_0, p0, p1);
    return 0;
}
