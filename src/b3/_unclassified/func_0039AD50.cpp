// func_0039AD50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0039AD50;

struct UnkStruct_0039AD50 {
    unsigned char pad_0[0xF0];
    int field_F0;
    int field_F4;
};

// 0x0039AD50
extern "C" int func_0039AD50(UnkStruct_0039AD50 * self)
{
    self->field_F4 = 0x2B9D6F8;
    self->field_F0 = 0xFD462907;
    return 1;
}
