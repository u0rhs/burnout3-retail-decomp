// func_004568B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004568B0;

struct UnkStruct_004568B0 {
    unsigned char pad_0[0xC];
    int field_C[1];  // [G] element count unknown
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x004568B0
extern "C" void func_004568B0(UnkStruct_004568B0 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 1);
    for (int i = 0; (i < 4); i++) {
        self->field_C[i] = 0;
    }
}
