// Prepare__24CB3NetworkNewHostMessageFiPi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002F98E0;

struct UnkStruct_002F98E0 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14[1];  // [G] element count unknown
};

extern "C" void Prepare__17CB3NetworkMessageFib(void *, int, bool);  // CB3NetworkMessage::Prepare(int,bool)

// 0x002F98E0
extern "C" void Prepare__24CB3NetworkNewHostMessageFiPi(UnkStruct_002F98E0 * self, int p0, int * p1)
{
    self->field_10 = p0;
    for (int i = 0; (i < 8); i++) {
        self->field_14[i] = p1[i];
    }
    Prepare__17CB3NetworkMessageFib(self, 16, 0);
}
