// func_003902C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (int return; else-if chain with returns everywhere except the int a<b arm (r = -1; then a final return r), the same shape as func_003C03D0).

// lifter variant 0
// func_003902C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003902C0;
struct UnkStruct_003902C0_a1;

struct UnkStruct_003902C0_a1 {
    unsigned char pad_0[0x4];
    float field_4;
    int field_8;
};

struct UnkStruct_003902C0 {
    unsigned char pad_0[0x4];
    float field_4;
    int field_8;
};

// 0x003902C0
extern "C" int func_003902C0(UnkStruct_003902C0 * self, UnkStruct_003902C0_a1 * p0)
{
    int r;
    if (self->field_4 < p0->field_4) {
        return -1;
    } else if (self->field_4 > p0->field_4) {
        return 1;
    } else if (self->field_8 < p0->field_8) {
        r = -1;
    } else {
        return self->field_8 > p0->field_8;
    }
    return r;
}
