// func_003CC4D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003CC4D0;
struct UnkStruct_003CC4D0_a1;

struct UnkStruct_003CC4D0_a1 {
    unsigned char pad_0[0x4];
    float field_4;
};

struct UnkStruct_003CC4D0 {
    unsigned char pad_0[0x4];
    float field_4;
};

// 0x003CC4D0
extern "C" int func_003CC4D0(UnkStruct_003CC4D0 * self, UnkStruct_003CC4D0_a1 * p0)
{
    float t0 = p0->field_4;
    float t1 = self->field_4;
    if (!(t1 < t0)) {
        int v0 = 1;
        if (t1 <= t0) {
            v0 = 0;
        }
        return (v0 & 255);
    }
    return -1;
}
