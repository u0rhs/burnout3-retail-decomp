// func_0028E0A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0028E0A0;

struct UnkStruct_0028E0A0 {
    unsigned char field_0;
};

// 0x0028E0A0
extern "C" int func_0028E0A0(UnkStruct_0028E0A0 * self)
{
    switch (self->field_0) {
    case 1:
    case 2:
    case 3:
    case 6:
    case 8:
    case 12:
    case 13:
    case 17:
        return 1;
    default:
        return 0;
    }
}
