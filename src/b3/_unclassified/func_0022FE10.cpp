// func_0022FE10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two arrays of 0x18-byte records, element-pointer locals for the first two groups, pointer-typed args (null test p3)).

struct UnkStruct_0022FE10;
struct UnkStruct_0022FE10_e0;

// [G] a 0x18-byte record (stride from the index * 24); two arrays of 24 of them
struct UnkStruct_0022FE10_e0 {
    int field_0;
    void * field_4;
    void * field_8;
    int field_C;
    int field_10;
    int field_14;
};

struct UnkStruct_0022FE10 {
    unsigned char pad_0[0x2C];
    UnkStruct_0022FE10_e0 field_2C[24];
    UnkStruct_0022FE10_e0 field_26C[24];
    int field_4AC;
};

extern "C" void func_0022D9F0(void *);
extern "C" void func_0022DA20(void *);

// 0x0022FE10
extern "C" void func_0022FE10(UnkStruct_0022FE10 * self, int p0, int p1_, void * p2, void * p3, void *p4_, void *p5_, void *p6_)
{
    void * p1 = (void *)p1_;
    int p4 = (int)p4_;
    int p5 = (int)p5_;
    int p6 = (int)p6_;
    UnkStruct_0022FE10_e0 * e = &self->field_2C[self->field_4AC];
    e->field_0 = p0;
    e->field_4 = p1;
    e->field_8 = p2;
    UnkStruct_0022FE10_e0 * f = &self->field_26C[self->field_4AC];
    f->field_0 = p0;
    f->field_4 = p1;
    f->field_8 = p3;
    self->field_26C[self->field_4AC].field_C = p4;
    self->field_26C[self->field_4AC].field_10 = p5;
    self->field_26C[self->field_4AC].field_14 = p6;
    func_0022D9F0(p2);
    if (p3 != 0) {
        func_0022DA20(p3);
    }
    self->field_4AC++;
}
