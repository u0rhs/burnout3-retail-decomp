// func_004656D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (n0 is a pointer (int flipped the null-test layout); inner result in its own zero-initialised local).

// func_004656D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004656D0_1;
struct UnkStruct_D_004E2FC4;

struct UnkStruct_D_004E2FC4 {
    UnkStruct_004656D0_1 * field_0;
};

struct UnkStruct_004656D0_1 {
    unsigned char pad_0[0xD0];
    void * field_D0;
    int field_D4;
};

extern UnkStruct_D_004E2FC4 D_004E2FC4;

extern "C" int func_00465EB0(int);

// 0x004656D0
extern "C" int func_004656D0(void * n0)
{
    int r = 0;
    if (n0 != 0) {
        D_004E2FC4.field_0->field_D0 = n0;
    } else {
        r = 7;
    }
    if (r == 0) {
        int r2 = 0;
        if (D_004E2FC4.field_0->field_D4 == 4) {
            func_00465EB0(2);
        } else {
            r2 = 22;
        }
        r = r2;
    }
    return r;
}
