// func_00240C00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (callee returns void* (null-tested ptr), i declared before m0).

// func_00240C00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00240C00;
struct UnkStruct_00240C00_1;
struct UnkStruct_00240C00_e0;

struct UnkStruct_00240C00_1 {
    unsigned char pad_0[0x28];
    int field_28;
};

struct UnkStruct_00240C00_e0 {
    unsigned char pad_0[0x50];
};

struct UnkStruct_00240C00 {
    UnkStruct_00240C00_e0 * field_0;
    UnkStruct_00240C00_1 * field_4;
};

extern "C" void * func_002366D0(UnkStruct_00240C00_1 *, int);
extern "C" void func_00240E20(void *, void *);

extern "C" void func_00240C00(UnkStruct_00240C00 * self)
{
    int i = 0;
    int m0 = 0;
    for (; i < self->field_4->field_28; i++) {
        void * r0 = func_002366D0(self->field_4, i);
        if (r0) {
            func_00240E20(&self->field_0[m0], r0);
            m0++;
        }
    }
}
