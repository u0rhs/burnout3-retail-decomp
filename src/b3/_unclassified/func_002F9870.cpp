// Retrieve__24CB3NetworkNewHostMessageFPiPi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002F9870;
struct UnkStruct_002F9870_a1;

struct UnkStruct_002F9870_a1 {
    int field_0;
};

struct UnkStruct_002F9870 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
    int field_10;
    int field_14[1];  // [G] element count unknown
};

// 0x002F9870
extern "C" int Retrieve__24CB3NetworkNewHostMessageFPiPi(UnkStruct_002F9870 * self, UnkStruct_002F9870_a1 * p0, int * p1)
{
    if ((self->field_0 & 1) == 1) {
        p0->field_0 = self->field_10;
        for (int i = 0; (i < 8); i++) {
            p1[i] = self->field_14[i];
        }
        self->field_0 = (self->field_0 & -2);
        return 1;
    }
    return 0;
}
