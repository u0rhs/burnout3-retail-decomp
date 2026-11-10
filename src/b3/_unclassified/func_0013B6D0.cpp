// func_0013B6D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(int, int);

// 0x0013B6D0
extern "C" void func_0013B6D0(int n0, int p0, void *p1_)
{
    int p1 = (int)p1_;
    if (p1 == 0) {
        return;
    }
    switch (p0) {
    case 0:
        CopyN__10CGtUnicodeFPUsiPCUs((n0 + 26), 9);
        break;
    case 1:
        CopyN__10CGtUnicodeFPUsiPCUs((n0 + 44), 9);
        break;
    }
}
