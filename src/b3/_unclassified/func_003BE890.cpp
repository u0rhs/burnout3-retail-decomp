// func_003BE890 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003BE890;

struct UnkStruct_003BE890 {
    unsigned char pad_0[0x4C];
    unsigned char field_4C;
    unsigned char field_4D;
};

extern "C" int func_0038D480(UnkStruct_003BE890 *);

// 0x003BE890
extern "C" int func_003BE890(UnkStruct_003BE890 * self)
{
    int r0 = func_0038D480(self);
    if (r0 == 0) {
        return 0;
    }
    self->field_4C = 1;
    self->field_4D = 0;
    return 1;
}
