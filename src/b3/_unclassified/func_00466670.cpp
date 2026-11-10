// func_00466670 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (nested switches; callee takes 2 args (phantom a2/a3 dropped); case 10 shares default).

// lifter variant 0
// func_00466670 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00466670;
struct UnkStruct_00466670_1;
struct UnkStruct_00466670_a1;
struct UnkStruct_D_004E2FC4;

struct UnkStruct_D_004E2FC4 {
    UnkStruct_00466670_1 * field_0;
};

struct UnkStruct_00466670_1 {
    unsigned char pad_0[0xD4];
    int field_D4;
    unsigned char pad_D8[0x4];
    int field_DC;
};

struct UnkStruct_00466670_a1 {
    int field_0;
};

struct UnkStruct_00466670 {
    int field_0;
};

extern UnkStruct_D_004E2FC4 D_004E2FC4;

extern "C" int func_00465D00(int, int);

// 0x00466670
extern "C" void func_00466670(UnkStruct_00466670 * self, UnkStruct_00466670_a1 * p0)
{
    switch (D_004E2FC4.field_0->field_DC) {
    case 9:
        self->field_0 = 1;
        switch (D_004E2FC4.field_0->field_D4) {
        case 0: func_00465D00(0, 1); break;
        case 1: case 2: func_00465D00(1, 1); break;
        case 3: func_00465D00(8, 1); break;
        default: p0->field_0 = 12; self->field_0 = 0; break;
        }
        break;
    case 10:
    default:
        p0->field_0 = 12;
        self->field_0 = 0;
        break;
    }
}
