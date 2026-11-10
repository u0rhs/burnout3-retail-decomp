// func_0043BC30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0043BC30;
struct UnkStruct_0043BC30_a1;

struct UnkStruct_0043BC30_a1 {
    unsigned char field_0;
    unsigned char pad_1[0x7];
    float field_8;
};

struct UnkStruct_0043BC30 {
    unsigned char field_0;
    unsigned char pad_1[0x7];
    float field_8;
};

// 0x0043BC30
extern "C" int func_0043BC30(UnkStruct_0043BC30 * self, UnkStruct_0043BC30_a1 * p0)
{
    if (p0->field_0 == 0) {
        return -1;
    }
    if (self->field_0 == 0) {
        return 1;
    }
    float t0 = p0->field_8;
    float t1 = self->field_8;
    if (t1 < t0) {
        return -1;
    }
    int v0 = 1;
    if (t1 <= t0) {
        v0 = 0;
    }
    return (v0 & 255);
}
