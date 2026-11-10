// func_003CC280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003CC280;

struct UnkStruct_003CC280 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
    unsigned char field_10;
};

extern "C" void Prepare__17CB3NetworkMessageFib(void *, int, bool);  // CB3NetworkMessage::Prepare(int,bool)

// 0x003CC280
extern "C" void func_003CC280(UnkStruct_003CC280 * self, int p0)
{
    if ((self->field_0 & 1) == 1) return;
    self->field_10 = p0;
    Prepare__17CB3NetworkMessageFib(self, 20, 1);
}
