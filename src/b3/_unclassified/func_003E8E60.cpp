// func_003E8E60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern signed char D_004CB270[];  // [G] element count unknown

// 0x003E8E60
extern "C" int func_003E8E60(int n0)
{
    return (D_004CB270[(n0 % 20)] + ((n0 / 20) * 13));
}
