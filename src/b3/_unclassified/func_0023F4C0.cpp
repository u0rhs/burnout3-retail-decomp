// func_0023F4C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0023F4C0;

struct UnkStruct_0023F4C0 {
    unsigned char pad_0[0x4B8];
    unsigned char field_4B8;
    unsigned char pad_4B9[0xF];
    unsigned char field_4C8;
    unsigned char pad_4C9[0xF];
    unsigned long field_4D8;
    int field_4E0;
    int field_4E4;
    unsigned char field_4E8;
    unsigned char field_4E9;
    unsigned char field_4EA;
    unsigned char pad_4EB[0x5];
    int field_4F0;
    unsigned char pad_4F4[0xC];
    int field_500[1];  // [G] element count unknown
    unsigned char pad_504[0x1C];
    int field_520[1];  // [G] element count unknown
    unsigned char pad_524[0x1C];
    int field_540[1];  // [G] element count unknown
    unsigned char pad_544[0x1C];
    int field_560[1];  // [G] element count unknown
    unsigned char pad_564[0x1C];
    int field_580[1];  // [G] element count unknown
    unsigned char pad_584[0x1C];
    int field_5A0[1];  // [G] element count unknown
    unsigned char pad_5A4[0x1C];
    unsigned char field_5C0;
    unsigned char pad_5C1[0x11B];
    int field_6DC;
    int field_6E0;
};

extern "C" void func_0023EB70(UnkStruct_0023F4C0 *);
extern "C" void func_0023F5B0(UnkStruct_0023F4C0 *, int);
extern "C" void func_00230480(UnkStruct_0023F4C0 *, int, int, int, int, int);

// 0x0023F4C0
extern "C" void func_0023F4C0(UnkStruct_0023F4C0 * self, int p0, int p1, int p2, int p3, int p4)
{
    func_0023EB70(self);
    self->field_6DC = p4;
    self->field_6E0 = 0;
    self->field_4F0 = 0;
    self->field_5C0 = 0;
    for (int i = 0; (i < 8); i++) {
        self->field_500[i] = -1;
        self->field_540[i] = -1;
        self->field_580[i] = -1;
        self->field_520[i] = 4;
        self->field_560[i] = 4;
        self->field_5A0[i] = 4;
    }
    self->field_4B8 = 0;
    self->field_4C8 = 0;
    self->field_4D8 = 0;
    self->field_4E0 = 0;
    self->field_4E4 = -1;
    self->field_4E8 = 0;
    self->field_4E9 = 0;
    self->field_4EA = 0;
    func_0023F5B0(self, -1);
    func_00230480(self, p0, p1, p2, p3, self->field_6DC);
}
