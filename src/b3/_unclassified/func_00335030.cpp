// Retrieve__36CB3NetworkAllNATDataFinalisedMessageFPiP15EPlayerNATState -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00335030;

struct UnkStruct_00335030 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
    int field_10[1];  // [G] element count unknown
    unsigned char pad_14[0x1C];
    int field_30[1];  // [G] element count unknown
};

// 0x00335030
extern "C" int Retrieve__36CB3NetworkAllNATDataFinalisedMessageFPiP15EPlayerNATState(UnkStruct_00335030 * self, int * p0, int * p1)
{
    if ((self->field_0 & 1) == 1) {
        for (int i = 0; (i < 8); i++) {
            p0[i] = self->field_10[i];
            p1[i] = self->field_30[i];
        }
        self->field_0 = (self->field_0 & -2);
        return 1;
    }
    return 0;
}
