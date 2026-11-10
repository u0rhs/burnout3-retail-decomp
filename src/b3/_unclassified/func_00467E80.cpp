// func_00467E80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (n0 typed void* (null-tested pointer)).

// func_00467E80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_D_004E2FC8;

struct UnkStruct_D_004E2FC8 {
    int field_0;
};

extern UnkStruct_D_004E2FC8 D_004E2FC8;

extern "C" void * memcpy(void *, const void *, unsigned int);

// 0x00467E80
// [L] n0 is a pointer (null-tested, then passed to memcpy): as an int, MWCC inverts the branch.
extern "C" int func_00467E80(void *n0)
{
    if (n0 != 0) {
        memcpy(n0, (const void *)(D_004E2FC8.field_0 + 12), 96);
        return 0;
    }
    return 12;
}
