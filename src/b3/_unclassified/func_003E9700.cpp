// func_003E9700 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern unsigned long D_004CC400[];  // [G] element count unknown

// 0x003E9700
extern "C" int func_003E9700(unsigned long n0)
{
    int m0 = 0;
    while (D_004CC400[m0] != 0) {
        if (n0 == D_004CC400[m0]) {
            return 1;
        }
        m0 = (m0 + 1);
    }
    return 0;
}
