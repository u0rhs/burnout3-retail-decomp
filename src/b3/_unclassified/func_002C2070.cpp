// func_002C2070 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" void * memset(void *, int, unsigned int);
extern "C" void func_0022DA20(void *);

// 0x002C2070
extern "C" void func_002C2070(void *n0_)
{
    int n0 = (int)n0_;
    func_0022DA20((void *)(n0));
    memset((void *)(n0 + 16), 0, 4);
    memset((void *)(n0 + 32), 0, 264);
}
