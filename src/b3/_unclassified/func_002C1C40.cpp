// func_002C1C40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" void func_0022FC60(void *, int);

// 0x002C1C40
extern "C" void func_002C1C40(int n0, void *p0_)
{
    int p0 = (int)p0_;
    func_0022FC60((void *)(p0), 3);
    func_0022FC60((void *)(p0), 2);
}
