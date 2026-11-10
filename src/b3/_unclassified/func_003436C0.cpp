// func_003436C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003436C0;
struct UnkStruct_003436C0_e1;

struct UnkStruct_003436C0_e1 {
    int field_0;
    int field_4;
};

struct UnkStruct_003436C0 {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    int field_14;
    int field_18[1];  // [G] element count unknown
    unsigned char pad_1C[0x4];
    UnkStruct_003436C0_e1 field_20[1];  // [G] element count unknown
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x003436C0
extern "C" void func_003436C0(UnkStruct_003436C0 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 2);
    for (int i = 0; (i < 2); i++) {
        self->field_18[i] = 0;
        self->field_20[i].field_0 = 0;
        self->field_20[i].field_4 = 0;
    }
    self->field_C = 0;
    self->field_10 = 0;
    self->field_14 = 0;
}
