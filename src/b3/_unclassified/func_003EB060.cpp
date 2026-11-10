// func_003EB060 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern unsigned long D_004CCF80[];  // [G] element count unknown

// 0x003EB060
extern "C" int func_003EB060(unsigned long n0)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (n0 == D_004CCF80[i]) {
            return i;
        }
    }
    i++;
loop0_test:
    if (i < 67) goto loop0_body;
    return -1;
}
