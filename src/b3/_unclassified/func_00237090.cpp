// func_00237090 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" void iWakeupThread(int);

// 0x00237090
extern "C" void func_00237090(int n0, int p0, int p1)
{
    iWakeupThread(p1);
}
