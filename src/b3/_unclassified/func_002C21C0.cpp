// DoEncode__18CGtLogitechHeadsetFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (phantom args dropped (lgAudRead takes 4); two int stack locals (len=2048, out); merged || guard; field_184 as array member).

// DoEncode__18CGtLogitechHeadsetFv -- tiny-function batch (tools/tiny_batch.py, lifted, then hand-shaped).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to. lgAudRead/lgCodecEncode: [G] prototypes from register use.

struct UnkStruct_002C21C0 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x174];
    int field_17C;
    int field_180;
    unsigned char field_184[4];  // [G] buffer (address passed twice, not CSE'd: an array member)
};

extern "C" int lgAudRead(int, int, void *, int *);
extern "C" void lgCodecEncode(int, void *, int, int, int *);

// 0x002C21C0
extern "C" int DoEncode__18CGtLogitechHeadsetFv(UnkStruct_002C21C0 * self)
{
    int len = 2048;
    int out;
    if (self->field_17C == -1 || self->field_180 == 0) {
        return 0;
    }
    if (lgAudRead(self->field_17C, 1, self->field_184, &len) == 0) {
        if (len == 0) {
            return 0;
        }
        out = self->field_4;
        lgCodecEncode(self->field_180, self->field_184, len, self->field_0, &out);
    }
    return out;
}
