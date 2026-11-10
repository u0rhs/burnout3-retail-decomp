// func_0013AD70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern unsigned char D_0051BFF7[];  // [G] element count unknown
extern unsigned char D_0051C040[];  // [G] element count unknown

// 0x0013AD70
extern "C" int func_0013AD70(void *n0_, int p0, int p1)
{
    int n0 = (int)n0_;
    int v1;
    if (p0 != -1) {
        int v0;
        if (p1 != 0) {
            v0 = ((D_0051BFF7[p0] != 0) ^ 1);
        } else {
            v0 = ((D_0051C040[p0] != 0) ^ 1);
        }
        v1 = v0;
    } else {
        v1 = 0;
    }
    return v1;
}
