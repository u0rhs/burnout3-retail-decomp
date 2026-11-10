// func_00155360 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00155360;

struct UnkStruct_00155360 {
    unsigned char pad_0[0x580];
    int field_580;
};

extern int D_0064D388[];  // [G] element count unknown

// 0x00155360
extern "C" int func_00155360(UnkStruct_00155360 * self)
{
    int t0 = self->field_580;
    int v1;
    if (t0 != -1) {
        v1 = D_0064D388[t0];
    } else {
        v1 = 0;
    }
    return v1;
}
