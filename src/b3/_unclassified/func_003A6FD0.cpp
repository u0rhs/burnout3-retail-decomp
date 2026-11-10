// func_003A6FD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003A6FD0;
struct UnkStruct_003A6FD0_e0;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01E88D40;

struct UnkStruct_D_01E88D40 {
    unsigned short field_0;
    unsigned char pad_2[0xE];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003A6FD0_e0 {
    int field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_003A6FD0 {
    unsigned char pad_0[0xB0];
    UnkStruct_003A6FD0_e0 field_B0[1];  // [G] element count unknown
    unsigned char pad_C0[0x826];
    unsigned char field_8E6;
};

extern UnkStruct_D_01E88D40 D_01E88D40;
extern UnkStruct_D_0051BF9C D_0051BF9C;

extern "C" int func_0013AD70(void *, int, int);

// 0x003A6FD0
extern "C" int func_003A6FD0(UnkStruct_003A6FD0 * self)
{
    return func_0013AD70((void *)(D_0051BF9C.field_0), self->field_B0[D_01E88D40.field_0].field_0, ((self->field_8E6 != 0) ^ 1));
}
