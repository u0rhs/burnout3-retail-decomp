// func_0012F6B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" float func_0012FC30(void *, int, int);

// 0x0012F6B0
extern "C" float func_0012F6B0(void *n0_)
{
    int n0 = (int)n0_;
    float r0 = func_0012FC30((void *)(n0), 3, 0);
    float r1 = func_0012FC30((void *)(n0), 15, 0);
    float v0 = (r0 + r1);
    if (!((r0 + r1) <= 1.0f)) {
        v0 = 1.0f;
    }
    return v0;
}
