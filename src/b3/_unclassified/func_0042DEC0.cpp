// func_0042DEC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042DEC0;

struct UnkStruct_0042DEC0 {
    unsigned char pad_0[0x20C];
    int field_20C;
    int field_210;
    unsigned char pad_214[0x4];
    int field_218;
    int field_21C;
    int field_220[1];  // [G] element count unknown
    unsigned char pad_224[0x1C];
    int field_240;
    int field_244;
    unsigned char pad_248[0x8];
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x0042DEC0
extern "C" void func_0042DEC0(UnkStruct_0042DEC0 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 4);
    self->field_20C = 0;
    self->field_25C = 9;
    self->field_260 = -1;
    self->field_258 = 0;
    self->field_254 = self->field_258;
    self->field_244 = 0;
    self->field_240 = 0;
    self->field_250 = 0;
    self->field_210 = 0;
    self->field_218 = 0;
    self->field_21C = 0;
    for (int i = 0; (i < 4); i++) {
        self->field_220[i] = 0;
    }
}
