// func_0039C170 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0039C170;

struct UnkStruct_0039C170 {
    unsigned char pad_0[0x14];
    int field_14[1];  // [G] element count unknown
    unsigned char pad_18[0x40];
    signed char field_58;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x0039C170
extern "C" void func_0039C170(UnkStruct_0039C170 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 2);
    for (int i = 0; (i < self->field_58); i++) {
        self->field_14[i] = 0;
    }
}
