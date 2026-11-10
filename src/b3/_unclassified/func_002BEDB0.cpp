// func_002BEDB0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_00272EA0. Returns its result: the clipped vertex count, which the caller func_002B7F70 reads in v0
// [C] retail 0x2B8108 (beqz v0) (draftAO, 2026-11-01; fix3 gap).

struct UnkStruct_002BEDB0;

extern "C" int func_00272EA0(UnkStruct_002BEDB0 *, int, void *, void *, void *);

// 0x002BEDB0
extern "C" int func_002BEDB0(UnkStruct_002BEDB0 *self, int p0, void *p1_, void *p2_)
{
    int p1 = (int)p1_;
    int p2 = (int)p2_;
    return func_00272EA0(self, p0, (void *)(p1), (void *)(p2), (void *)(0));
}
