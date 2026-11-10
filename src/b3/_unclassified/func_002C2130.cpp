// DoDecode__18CGtLogitechHeadsetFii -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (phantom float args dropped; field_184 an array member (address recomputed per call); two int stack locals).

// DoDecode__18CGtLogitechHeadsetFii -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002C2130;
struct UnkStruct_002C2130_1;

struct UnkStruct_002C2130_1 {
    int field_0;
    int field_4;
};

struct UnkStruct_002C2130 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x170];
    int field_17C;
    int field_180;
    unsigned char field_184[4];
};

extern "C" void lgCodecDecode(int, int, int, void *, int *);
extern "C" void lgAudWrite(int, int, void *, void *);

// 0x002C2130
extern "C" int DoDecode__18CGtLogitechHeadsetFii(UnkStruct_002C2130 * self, int p0)
{
    int b;
    int a;
    if (self->field_17C == -1 || self->field_180 == 0) {
        return 0;
    }
    a = 2048;
    lgCodecDecode(self->field_180, self->field_8, p0, self->field_184, &a);
    b = a;
    lgAudWrite(self->field_17C, 1, self->field_184, &b);
    return a;
}
