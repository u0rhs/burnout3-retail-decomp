// func_00450E10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (case 0: case 1024: case 1: default: first).

// 0x00450E10
extern "C" int func_00450E10(void *n0_, int p0)
{
    int n0 = (int)n0_;
    switch (p0) {
    case 0: case 1024: case 1: default: return 883;
    case 2: return 2519;
    case 4: return 887;
    case 8: return 882;
    case 16: return 2520;
    case 32: return 2521;
    case 64: return 888;
    case 128: return 2522;
    case 256: return 2523;
    case 512: return 891;
    }
}
