// func_003C28A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C28A0;

struct UnkStruct_003C28A0 {
    unsigned char pad_0[0xA0];
    signed char field_A0[1];  // [G] element count unknown
    unsigned char pad_A1[0x12];
    unsigned char field_B3;
};

// 0x003C28A0
extern "C" int func_003C28A0(UnkStruct_003C28A0 * self, int p0)
{
    unsigned char t0 = self->field_B3;
    for (int i = 0; (i < t0); i++) {
        if (self->field_A0[i] == p0) {
            return i;
        }
    }
    return 0;
}
