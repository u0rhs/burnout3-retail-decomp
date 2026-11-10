// func_003367B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003367B0;
struct UnkStruct_003367B0_1;

struct UnkStruct_003367B0_1 {
    int field_0;
};

struct UnkStruct_003367B0 {
    unsigned char pad_0[0x61C];
    int field_61C;
};

extern "C" int func_0040D730(int);
extern "C" int func_0040D698(int, int, UnkStruct_003367B0_1 *);

// 0x003367B0
extern "C" int func_003367B0(UnkStruct_003367B0 * self)
{
    UnkStruct_003367B0_1 local;  // [G] the frame's one local (size: up to the frame top)
    for (int i = 0; (i < func_0040D730(self->field_61C)); i++) {
        int r0 = func_0040D698(self->field_61C, i, &local);
        if (r0 != 0) {
            return -1;
        }
        if ((local.field_0 & 1) != 0) {
            return i;
        }
    }
    return -1;
}
