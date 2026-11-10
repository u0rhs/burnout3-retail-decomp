// func_0013B740 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(int, int, int);

// 0x0013B740
extern "C" void func_0013B740(int n0, int p0)
{
    if (p0 == 0) return;
    CopyN__10CGtUnicodeFPUsiPCUs((n0 + 8), 9, p0);
}
