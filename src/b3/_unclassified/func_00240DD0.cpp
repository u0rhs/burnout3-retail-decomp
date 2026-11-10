// func_00240DD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" int func_0022FC10(void *, int);
extern "C" void func_0022FC60(void *, int);

// 0x00240DD0
extern "C" void func_00240DD0(void *n0_, void *p0_)
{
    int n0 = (int)n0_;
    int p0 = (int)p0_;
    if (p0 == 0) return;
    int r0 = func_0022FC10((void *)(p0), 1);
    if (r0 == 0) return;
    func_0022FC60((void *)(p0), 1);
}
