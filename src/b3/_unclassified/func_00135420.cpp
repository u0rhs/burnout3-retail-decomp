// func_00135420 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00135420;
struct UnkStruct_00135420_e0;
struct UnkStruct_D_00516DF0;
struct UnkStruct_D_00516E10;
struct UnkStruct_D_00516E14;
struct UnkStruct_D_00516E34;
struct UnkStruct_D_0051BAA8;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E65499;
struct UnkStruct_D_01E6549A;
struct UnkStruct_theMemMgr;

struct UnkStruct_D_01E65499 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E6549A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00516E10 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00516E34 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00135420_e0 {
    unsigned char pad_0[0x1240];
    unsigned char field_1240;
    unsigned char pad_1241[0x3CDF];
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x9E40];
    UnkStruct_00135420_e0 field_9E40[1];  // [G] element count unknown
};

struct UnkStruct_D_0051BAA8 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00516DF0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00516E14 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_theMemMgr {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00135420 {
    unsigned char pad_0[0x1C8];
    int field_1C8;
};

extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_01E6549A D_01E6549A;
extern UnkStruct_D_00516E10 D_00516E10;
extern UnkStruct_D_00516E34 D_00516E34;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_0051BAA8 D_0051BAA8;
extern UnkStruct_D_00516DF0 D_00516DF0;
extern UnkStruct_D_00516E14 D_00516E14;
extern UnkStruct_theMemMgr theMemMgr;

extern "C" void func_00134600(UnkStruct_00135420 *);
extern "C" void func_002709D0(void *);
extern "C" void func_00135A90(void *);
extern "C" void func_003E8750(void *, int);

// 0x00135420
extern "C" void func_00135420(UnkStruct_00135420 * self)
{
    func_00134600(self);
    func_002709D0(&D_01E32AE0);
    D_01E65499.field_0 = 0;
    D_01E6549A.field_0 = 1;
    D_00516E10.field_0 = 1;
    func_00135A90(&D_00516DF0);
    D_00516E34.field_0 = 1;
    func_00135A90(&D_00516E14);
    for (int i = 0; (i < 8); i++) {
        D_01E32AE0.field_9E40[i].field_1240 = 0;
    }
    self->field_1C8 = 24;
    D_0051BAA8.field_0 = 1;
    func_003E8750(&theMemMgr, 20256);
}
