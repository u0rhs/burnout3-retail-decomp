// func_001A85C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_001A85C0;

struct UnkStruct_001A85C0 {
    unsigned char pad_0[0x10];
    int field_10;
    float field_14;
    int field_18[1];  // [G] element count unknown
};

extern "C" void Prepare__17CB3NetworkMessageFib(void *, int, bool);  // CB3NetworkMessage::Prepare(int,bool)

// 0x001A85C0
extern "C" int func_001A85C0(UnkStruct_001A85C0 * self, int p0, int * p1, float f0)
{
    self->field_10 = p0;
    self->field_14 = f0;
    for (int i = 0; (i < 8); i++) {
        self->field_18[i] = p1[i];
    }
    Prepare__17CB3NetworkMessageFib(self, 11, 1);
    return 1;
}
