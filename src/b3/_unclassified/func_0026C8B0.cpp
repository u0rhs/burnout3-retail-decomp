// func_0026C8B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

// 0x0026C8B0
extern "C" int func_0026C8B0(void *n0_, int p0)
{
    int n0 = (int)n0_;
    return (n0 + ((p0 & 255) << 4));
}
