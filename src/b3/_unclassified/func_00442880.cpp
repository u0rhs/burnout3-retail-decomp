// func_00442880 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00442880;
struct UnkStruct_00442880_e2;

struct UnkStruct_00442880_e2 {
    unsigned char pad_0[0x18];
};

struct UnkStruct_00442880 {
    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x34];
    int field_38[1];  // [G] element count unknown
    unsigned char pad_3C[0x4];
    int field_40;
    unsigned char field_44;
};

extern "C" void * memset(void *, int, unsigned int);
extern "C" void func_004438E0(UnkStruct_00442880 *);

// 0x00442880
extern "C" void func_00442880(UnkStruct_00442880 * self)
{
    self->field_40 = 0;
    self->field_44 = 0;
    func_004438E0(self);
    for (int i = 0; (i < 2); i++) {
        self->field_38[i] = -1;
        memset(((char *)((char *)self + ((i * 3) << 3)) + 0x8), 0, 24);
        self->field_0[i] = 0;
    }
}
