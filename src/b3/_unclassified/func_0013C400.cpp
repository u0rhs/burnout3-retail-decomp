// func_0013C400 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013C400;

struct UnkStruct_0013C400 {
    unsigned char pad_0[0x164];
    int field_164;
    int field_168;
    int field_16C;
    int field_170;
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    int field_1A0;
    int field_1A4[1];  // [G] element count unknown
    unsigned char pad_1A8[0xC];
    int field_1B4;
    int field_1B8[1];  // [G] element count unknown
    unsigned char pad_1BC[0xC];
    int field_1C8;
    int field_1CC[1];  // [G] element count unknown
    unsigned char pad_1D0[0xC];
    int field_1DC;
    int field_1E0[1];  // [G] element count unknown
    unsigned char pad_1E4[0xC];
    int field_1F0;
    int field_1F4;
    int field_1F8;
    unsigned char pad_1FC[0x78];
    int field_274;
};

extern "C" int func_0013C4B0(UnkStruct_0013C400 *);

// 0x0013C400
extern "C" int func_0013C400(UnkStruct_0013C400 * self)
{
    func_0013C4B0(self);
    self->field_164 = -1;
    self->field_168 = -1;
    self->field_16C = 0;
    self->field_170 = -1;
    self->field_174 = 0;
    self->field_178 = 0;
    self->field_17C = 0;
    self->field_1F4 = 0;
    self->field_180 = 0;
    self->field_184 = 0;
    self->field_188 = 0;
    self->field_18C = 0;
    self->field_190 = 0;
    self->field_194 = 0;
    self->field_198 = 0;
    self->field_19C = 0;
    self->field_1A0 = 0;
    for (int i = 0; (i < 4); i++) {
        self->field_1A4[i] = 0;
        self->field_1B8[i] = 0;
        self->field_1CC[i] = 0;
        self->field_1E0[i] = 0;
    }
    self->field_1F8 = 0;
    self->field_1B4 = 0;
    self->field_1C8 = 0;
    self->field_1DC = 0;
    self->field_1F0 = 0;
    self->field_274 = 0;
    return 1;
}
