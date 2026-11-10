// func_0019F200 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0019F200;

class CGtViewport {
public:
    void Destruct();
};

struct UnkStruct_0019F200 {
    unsigned char pad_0[0x90];
    CGtViewport field_90;
    unsigned char pad_91[0x9F];
    CGtViewport field_130;
    unsigned char pad_131[0x1DF];
    CGtViewport field_310;
};

// 0x0019F200
extern "C" void func_0019F200(UnkStruct_0019F200 * self)
{
    self->field_90.Destruct();
    self->field_130.Destruct();
    self->field_310.Destruct();
}
