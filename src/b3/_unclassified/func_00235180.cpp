// func_00235180 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00235180;
struct UnkStruct_00235180_e0;

struct UnkStruct_00235180_e0 {
    int field_0;
    int field_4;
    int field_8;
};

struct UnkStruct_00235180 {
    unsigned char pad_0[0x324];
    UnkStruct_00235180_e0 field_324[1];  // [G] element count unknown
    unsigned char pad_330[0x6C];
    int field_39C;
};

// 0x00235180
extern "C" void func_00235180(UnkStruct_00235180 * self)
{
    for (int i = 0; (i < 10); i++) {
        self->field_324[i].field_0 = -1;
        self->field_324[i].field_4 = -1;
        self->field_324[i].field_8 = -1;
    }
    self->field_39C = 0;
}
