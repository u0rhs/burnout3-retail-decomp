// func_002B70C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002B70C0;

struct UnkStruct_002B70C0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
    float field_10;
};

extern "C" void Prepare__17CB3NetworkMessageFib(void *, int, bool);  // CB3NetworkMessage::Prepare(int,bool)

// 0x002B70C0
extern "C" void func_002B70C0(UnkStruct_002B70C0 * self, float f0)
{
    if ((self->field_0 & 1) == 1) return;
    self->field_10 = f0;
    Prepare__17CB3NetworkMessageFib(self, 13, 0);
}
