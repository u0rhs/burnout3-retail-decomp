// func_00466180 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_D_004E2FC4;

struct UnkStruct_D_004E2FC4 {
    int field_0;
};

extern UnkStruct_D_004E2FC4 D_004E2FC4;

extern "C" int func_004641C0(void *);
extern "C" int func_00465320(int);

// 0x00466180
extern "C" void func_00466180()
{
    int r0 = func_004641C0((void *)((D_004E2FC4.field_0 + 72)));
    func_00465320(r0);
}
