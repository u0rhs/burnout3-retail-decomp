// Prepare__36CB3NetworkAllNATDataFinalisedMessageFPiP15EPlayerNATState -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003350A0;

struct UnkStruct_003350A0 {
    unsigned char pad_0[0x10];
    int field_10[1];  // [G] element count unknown
    unsigned char pad_14[0x1C];
    int field_30[1];  // [G] element count unknown
};

extern "C" void Prepare__17CB3NetworkMessageFib(void *, int, bool);  // CB3NetworkMessage::Prepare(int,bool)

// 0x003350A0
extern "C" void Prepare__36CB3NetworkAllNATDataFinalisedMessageFPiP15EPlayerNATState(UnkStruct_003350A0 * self, int * p0, int * p1)
{
    for (int i = 0; (i < 8); i++) {
        self->field_10[i] = p0[i];
        self->field_30[i] = p1[i];
    }
    Prepare__17CB3NetworkMessageFib(self, 9, 1);
}
