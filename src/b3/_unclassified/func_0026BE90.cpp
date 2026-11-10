// func_0026BE90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0026BE90_0;

struct UnkStruct_0026BE90_0 {
    unsigned char pad_0[0x590];
};

extern "C" int func_0041BE30(int);
extern "C" void func_0041BE38(UnkStruct_0026BE90_0 *);
extern "C" void DirtyDnasShutdown();

// 0x0026BE90
extern "C" int func_0026BE90(void *a0 /* passed by every caller, not read here */)
{
    UnkStruct_0026BE90_0 local;  // [G] the frame's one local (size: up to the frame top)
    int r0 = func_0041BE30(1);
    if ((r0 != 0) != false) {
        return 0;
    }
    func_0041BE38(&local);
    DirtyDnasShutdown();
    return 1;
}
