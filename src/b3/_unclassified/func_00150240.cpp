// Construct__13CB3NetworkCarFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00150240;

struct UnkStruct_00150240 {
    unsigned char pad_0[0x1914];
    int field_1914;
    unsigned char pad_1918[0x170];
    int field_1A88;
    int field_1A8C;
};

extern "C" void Construct__10CB3RaceCarFv(void *);  // CB3RaceCar::Construct()

// 0x00150240
extern "C" void Construct__13CB3NetworkCarFi(UnkStruct_00150240 * self, int p0)
{
    Construct__10CB3RaceCarFv(self);
    self->field_1A8C = p0;
    self->field_1914 = 2;
    self->field_1A88 = 0;
}
