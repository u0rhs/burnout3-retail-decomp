// func_003B6210 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003B6210;

struct UnkStruct_003B6210 {
    unsigned char pad_0[0x54];
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
};

// 0x003B6210
extern "C" void func_003B6210(UnkStruct_003B6210 * self, int p0)
{
    self->field_60 = 0;
    int t0 = self->field_58;
    if (t0 < p0) {
        if ((p0 - t0) == 1) {
            self->field_54 = 3;
        } else {
            self->field_54 = 4;
        }
    } else {
        if ((t0 - p0) == 1) {
            self->field_54 = 4;
        } else {
            self->field_54 = 3;
        }
    }
    self->field_5C = p0;
}
