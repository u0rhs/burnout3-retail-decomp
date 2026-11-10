// func_00467EC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two consecutive same-value early returns merged into one if (a == 0 || b == 0) return 2;).

// func_00467EC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00467EC0_2;
struct UnkStruct_00467EC0_3;
struct UnkStruct_D_004E2FC8;
struct UnkStruct_D_004E2FCC;

struct UnkStruct_D_004E2FCC {
    UnkStruct_00467EC0_2 * field_0;
};

struct UnkStruct_D_004E2FC8 {
    UnkStruct_00467EC0_3 * field_0;
};

struct UnkStruct_00467EC0_2 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    unsigned char pad_48[0x3E4];
    int field_42C;
};

struct UnkStruct_00467EC0_3 {
    int field_0;
    int field_4;
};

extern UnkStruct_D_004E2FCC D_004E2FCC;
extern UnkStruct_D_004E2FC8 D_004E2FC8;

extern "C" void func_00360AC0(int, void *, int, int);

// 0x00467EC0
extern "C" int func_00467EC0()
{
    if ((D_004E2FCC.field_0 != 0) == false) {
        return 2;
    }
    if (D_004E2FCC.field_0 == 0 || D_004E2FC8.field_0 == 0) {
        return 2;
    }
    D_004E2FCC.field_0->field_4 = 0;
    D_004E2FCC.field_0->field_8 = 0;
    D_004E2FCC.field_0->field_C = 0;
    D_004E2FCC.field_0->field_10 = 0;
    D_004E2FCC.field_0->field_14 = 0;
    D_004E2FCC.field_0->field_18 = 0;
    D_004E2FCC.field_0->field_1C = 0;
    D_004E2FCC.field_0->field_20 = 0;
    D_004E2FCC.field_0->field_24 = 0;
    D_004E2FCC.field_0->field_28 = 0;
    D_004E2FCC.field_0->field_2C = 0;
    D_004E2FCC.field_0->field_30 = 0;
    D_004E2FCC.field_0->field_34 = 0;
    D_004E2FCC.field_0->field_38 = 0;
    D_004E2FCC.field_0->field_3C = 0;
    D_004E2FCC.field_0->field_40 = 0;
    D_004E2FCC.field_0->field_44 = 0;
    D_004E2FC8.field_0->field_0 = 0;
    D_004E2FC8.field_0->field_4 = 0;
    func_00360AC0(D_004E2FCC.field_0->field_42C, D_004E2FC8.field_0, 116, 4);
    UnkStruct_00467EC0_2 * t0 = D_004E2FCC.field_0;
    D_004E2FC8.field_0 = 0;
    func_00360AC0(t0->field_42C, t0, 1072, 4);
    D_004E2FCC.field_0 = 0;
    return 0;
}
