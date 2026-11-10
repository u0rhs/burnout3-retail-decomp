// func_0013AD30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013AD30;

struct UnkStruct_0013AD30 {
    unsigned char pad_0[0x386];
    signed char field_386[1];  // [G] element count unknown
    unsigned char pad_387[0x48];
    signed char field_3CF[1];  // [G] element count unknown
};

// 0x0013AD30
extern "C" signed char func_0013AD30(UnkStruct_0013AD30 * self, int p0, int p1)
{
    signed char v1;
    if (p0 != -1) {
        signed char v0;
        if (p1 != 0) {
            v0 = self->field_386[p0];
        } else {
            v0 = self->field_3CF[p0];
        }
        v1 = v0;
    } else {
        v1 = 3;
    }
    return v1;
}
