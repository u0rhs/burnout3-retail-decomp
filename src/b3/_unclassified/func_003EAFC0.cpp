// func_003EAFC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern int D_004CD4D0[];  // [G] element count unknown

// 0x003EAFC0
extern "C" int func_003EAFC0(int n0)
{
    if ((n0 == -1) || (n0 >= 67)) {
        return 0;
    }
    return D_004CD4D0[n0];
}
