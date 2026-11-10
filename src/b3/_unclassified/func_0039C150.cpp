// func_0039C150 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" int func_0039BCD0(void *, void *, void *, int, int, float);

// Returns the tail call's value (retail `j func_0039BCD0`: v0 passes through to the caller).
// 0x0039C150
extern "C" int func_0039C150(void *n0_, void *p0_, void *p1_)
{
    int n0 = (int)n0_;
    int p0 = (int)p0_;
    int p1 = (int)p1_;
    return func_0039BCD0((void *)(n0), (void *)(p0), (void *)(p1), 0, 0, 516.0f);
}
