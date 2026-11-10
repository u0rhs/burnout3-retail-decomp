// func_003F5FB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern int D_004CE750[];  // [G] element count unknown

// 0x003F5FB0
extern "C" int func_003F5FB0(int n0)
{
    return D_004CE750[n0];
}
