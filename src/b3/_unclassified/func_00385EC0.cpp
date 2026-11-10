// func_00385EC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00385EC0;

struct UnkStruct_00385EC0 {
    unsigned char pad_0[0x1CC];
    int field_1CC;
    unsigned char pad_1D0[0x24];
    unsigned char field_1F4;
};

extern "C" int _rwaStreamGetStatus(int);
extern "C" int func_002A2B10(int);

// 0x00385EC0
extern "C" int func_00385EC0(UnkStruct_00385EC0 * self)
{
    if (((self->field_1F4 == 0) || (self->field_1CC == 0)) || (_rwaStreamGetStatus(self->field_1CC) <= 0)) {
        return -1;
    }
    int r1 = func_002A2B10(self->field_1CC);
    return r1;
}
