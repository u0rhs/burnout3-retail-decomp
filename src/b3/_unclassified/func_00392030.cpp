// func_00392030 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00392030_a1;

struct UnkStruct_00392030_a1 {
    unsigned char pad_0[0x13F4];
    int field_13F4;
};

extern "C" void HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo(void *, void *);

// 0x00392030
extern "C" void func_00392030(void *n0_, UnkStruct_00392030_a1 * p0, void *p1_)
{
    int n0 = (int)n0_;
    int p1 = (int)p1_;
    HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo((void *)((p0->field_13F4 + 4288)), (void *)(p1));
}
