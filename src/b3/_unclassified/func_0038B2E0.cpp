// func_0038B2E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038B2E0_a1;

struct UnkStruct_0038B2E0_a1 {
    unsigned char pad_0[0x13F4];
    int field_13F4;
};

extern "C" void HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo(void *, void *);

// 0x0038B2E0
extern "C" void func_0038B2E0(int n0, UnkStruct_0038B2E0_a1 * p0, int p1)
{
    HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo((void *)((p0->field_13F4 + 4288)), (void *)(p1));
}
