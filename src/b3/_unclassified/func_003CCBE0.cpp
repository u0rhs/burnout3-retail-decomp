// func_003CCBE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003CCBE0;
struct UnkStruct_003CCBE0_e0;

struct UnkStruct_003CCBE0_e0 {
    unsigned char pad_0[0x18];
    float field_18[1];  // [G] element count unknown
    unsigned char pad_1C[0xEC];
};

struct UnkStruct_003CCBE0 {
    unsigned char pad_0[0x210];
    UnkStruct_003CCBE0_e0 field_210[1];  // [G] element count unknown
    unsigned char pad_318[0x197];
    unsigned char field_4AF;
};

// 0x003CCBE0
extern "C" int func_003CCBE0(UnkStruct_003CCBE0 * self, int p0)
{
    unsigned char t0 = self->field_4AF;
    int m0 = 0;
    for (int i = 0; (i < t0); i++) {
        if (!(self->field_210[p0].field_18[i] <= 0.0f)) {
            m0 = ((m0 + 1) & 255);
        }
    }
    int v1 = m0;
    if ((m0 & 255) > 0) {
        v1 = ((m0 + -1) & 255);
    }
    return v1;
}
