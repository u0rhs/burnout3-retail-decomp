// func_003F86F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003F86F0;

struct UnkStruct_003F86F0 {
    unsigned char pad_0[0x174];
    int field_174;
};

// 0x003F86F0
extern "C" bool func_003F86F0(UnkStruct_003F86F0 * self)
{
    return (self->field_174 == 13);
}
