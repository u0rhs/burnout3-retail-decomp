// func_003EA530 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

// 0x003EA530
extern "C" int func_003EA530(int n0)
{
    switch (n0) {
    case 0:
        return 6;
    case 1:
        return 8;
    case 2:
        return 4;
    }
    return 0;
}
