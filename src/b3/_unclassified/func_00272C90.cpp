// func_00272C90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (field-by-field copy in source order from a const pointer parameter (loads hoisted above the stores)).

// lifter variant 0
// func_00272C90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00272C90;
struct UnkStruct_00272C90_a1;

struct UnkStruct_00272C90_a1 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    int field_4;
    float field_8;
    float field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    unsigned char field_28;
    unsigned char field_29;
    unsigned char pad_2A[0x2];
    int field_2C;
    int field_30;
    int field_34;
};

struct UnkStruct_00272C90 {
    unsigned char pad_0[0x10];
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char field_13;
    int field_14;
    float field_18;
    float field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    unsigned char field_38;
    unsigned char field_39;
    unsigned char pad_3A[0x2];
    int field_3C;
    int field_40;
    int field_44;
};

extern "C" void Prepare__17CB3NetworkMessageFib(void *, int, bool);  // CB3NetworkMessage::Prepare(int,bool)

// 0x00272C90
extern "C" int func_00272C90(UnkStruct_00272C90 * self, const UnkStruct_00272C90_a1 * p0)
{
    self->field_10 = p0->field_0;
    self->field_11 = p0->field_1;
    self->field_12 = p0->field_2;
    self->field_13 = p0->field_3;
    self->field_14 = p0->field_4;
    self->field_18 = p0->field_8;
    self->field_1C = p0->field_C;
    self->field_20 = p0->field_10;
    self->field_24 = p0->field_14;
    self->field_28 = p0->field_18;
    self->field_2C = p0->field_1C;
    self->field_30 = p0->field_20;
    self->field_34 = p0->field_24;
    self->field_38 = p0->field_28;
    self->field_39 = p0->field_29;
    self->field_3C = p0->field_2C;
    self->field_40 = p0->field_30;
    self->field_44 = p0->field_34;
    Prepare__17CB3NetworkMessageFib(self, 12, 1);
    return 1;
}
