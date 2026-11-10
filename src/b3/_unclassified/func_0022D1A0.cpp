// GenericPreparePlayerLocks__15CB3InputManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022D1A0;

struct UnkStruct_0022D1A0 {
    unsigned char pad_0[0xFA1];
    unsigned char field_FA1[1];  // [G] element count unknown
    unsigned char pad_FA2[0x1];
    unsigned char field_FA3[1];  // [G] element count unknown
};

// 0x0022D1A0
extern "C" void GenericPreparePlayerLocks__15CB3InputManagerFv(UnkStruct_0022D1A0 * self)
{
    int m0 = 0;
    do {
        self->field_FA3[((signed char)m0)] = 0;
        self->field_FA1[((signed char)m0)] = m0;
        m0 = ((signed char)(m0 + 1));
    } while (m0 < 2);
}
