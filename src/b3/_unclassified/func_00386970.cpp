// GetStreamsPreparing__21CGtSoundStreamManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00386970;
struct UnkStruct_00386970_1;

struct UnkStruct_00386970_1 {
    int field_0;
};

struct UnkStruct_00386970 {
    unsigned char pad_0[0x18];
    int field_18;
};

extern "C" int func_00385FD0(void *);

// 0x00386970
extern "C" int GetStreamsPreparing__21CGtSoundStreamManagerFv(UnkStruct_00386970 * self)
{
    int m1 = 0;
    UnkStruct_00386970_1 * m0 = (UnkStruct_00386970_1 *)self->field_18;
    while (m0 != 0) {
        int r0 = func_00385FD0(((char *)m0 + 0x8));
        if (r0 != 0) {
            m1 = (m1 + 1);
        }
        m0 = (UnkStruct_00386970_1 *)m0->field_0;
    }
    return m1;
}
