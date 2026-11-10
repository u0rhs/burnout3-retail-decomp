// func_003F57A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern signed char D_004CE440[];  // [G] element count unknown

// 0x003F57A0
extern "C" signed char func_003F57A0(int n0, int p0)
{
    int v1;
    switch (n0) {
    case 0:
        v1 = 0;
        break;
    case 1:
        v1 = 9;
        break;
    case 2:
        v1 = 21;
        break;
    default:
        v1 = 0;
        break;
    }
    return D_004CE440[(p0 + v1)];
}
