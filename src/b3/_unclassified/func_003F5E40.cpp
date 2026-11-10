// func_003F5E40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern unsigned long D_004CE500[];  // [G] element count unknown

// 0x003F5E40
extern "C" int func_003F5E40(unsigned long n0)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (n0 == D_004CE500[i]) {
            return 1;
        }
    }
    i++;
loop0_test:
    if (i < 10) goto loop0_body;
    return 0;
}
