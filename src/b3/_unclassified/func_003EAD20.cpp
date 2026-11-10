// FindTrafficVehicle__23CB3HardCodedVehicleListFUl -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern unsigned long D_004CDC00[];  // [G] element count unknown

// 0x003EAD20
extern "C" int FindTrafficVehicle__23CB3HardCodedVehicleListFUl(unsigned long n0)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (n0 == D_004CDC00[i]) {
            return i;
        }
    }
    i++;
loop0_test:
    if (i < 40) goto loop0_body;
    return -1;
}
