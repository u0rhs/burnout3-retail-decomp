// func_00344F80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" void snprintf(int, int, int, int);

// 0x00344F80
extern "C" void func_00344F80(int n0, int p0, int p1, int p2, int p3)
{
    snprintf(n0, p0, p1, (p3 + 12));
}
