// func_003BE5C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003BE5C0;

struct UnkStruct_003BE5C0 {
    unsigned char pad_0[0x14];
    int field_14[1];  // [G] element count unknown
    unsigned char pad_18[0x20];
    int field_38[1];  // [G] element count unknown
    unsigned char pad_3C[0x20];
    int field_5C[1];  // [G] element count unknown
    unsigned char pad_60[0x20];
    int field_80[1];  // [G] element count unknown
    unsigned char pad_84[0x20];
    int field_A4;
    int field_A8;
    int field_AC[1];  // [G] element count unknown
    unsigned char pad_B0[0x20];
    int field_D0;
    int field_D4;
    int field_D8;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x003BE5C0
extern "C" void func_003BE5C0(UnkStruct_003BE5C0 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 5);
    for (int i = 0; (i < 9); i++) {
        self->field_14[i] = 0;
        self->field_38[i] = 0;
        self->field_5C[i] = 0;
        self->field_80[i] = 0;
        self->field_AC[i] = 0;
    }
    self->field_A4 = 0;
    self->field_A8 = 0;
    self->field_D0 = 0;
    self->field_D4 = 0;
    self->field_D8 = 0;
}
