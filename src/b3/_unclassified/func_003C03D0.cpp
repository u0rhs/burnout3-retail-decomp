// func_003C03D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (else-if chain: returns everywhere except the a<b arm, which sets r = 1 and falls to a final return r (block order and delay slots; found by trying all 16 return/assign mixes)).

// from build/vt\try_func_003C03D0_best.cpp
// func_003C03D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C03D0;
struct UnkStruct_003C03D0_a1;

struct UnkStruct_003C03D0_a1 {
    unsigned char field_0;
    unsigned char pad_1[0x2F];
    int field_30;
};

struct UnkStruct_003C03D0 {
    unsigned char field_0;
    unsigned char pad_1[0x2F];
    int field_30;
};

// 0x003C03D0
extern "C" int func_003C03D0(UnkStruct_003C03D0 * self, UnkStruct_003C03D0_a1 * p0)
{
    int r;
    if (p0->field_0 == 0) {
        return -1;
    } else if (self->field_0 == 0) {
        return 1;
    } else if (self->field_30 < p0->field_30) {
        r = 1;
    } else {
        return -(p0->field_30 < self->field_30);
    }
    return r;
}
