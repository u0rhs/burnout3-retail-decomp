// func_003EAEA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern int D_004CD6F0[];  // [G] element count unknown

// 0x003EAEA0
extern "C" int func_003EAEA0(int n0)
{
    int v0;
    if (n0 > -1) {
        v0 = D_004CD6F0[n0];
    } else {
        v0 = 1279;
    }
    return v0;
}
