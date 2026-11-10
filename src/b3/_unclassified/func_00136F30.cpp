// func_00136F30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a79: field_1B4 is void*, && chain of pointer compares).

// func_00136F30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00136F30_1;
struct UnkStruct_D_0051AEC0;
struct UnkStruct_D_0051B40C;
struct UnkStruct_D_0051B464;
struct UnkStruct_D_0051B514;
struct UnkStruct_D_0051BA88;

struct UnkStruct_D_0051BA88 {
    UnkStruct_00136F30_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00136F30_1 {
    unsigned char pad_0[0x1B4];
    void * field_1B4;
};

struct UnkStruct_D_0051AEC0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051B40C {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051B464 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051B514 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051AEC0 D_0051AEC0;
extern UnkStruct_D_0051B40C D_0051B40C;
extern UnkStruct_D_0051B464 D_0051B464;
extern UnkStruct_D_0051B514 D_0051B514;

// 0x00136F30
extern "C" bool func_00136F30()
{
    UnkStruct_00136F30_1 * t0 = D_0051BA88.field_0;
    void * t1 = t0->field_1B4;
    return (void *)t0 != (void *)&D_0051AEC0 && t1 != (void *)&D_0051B40C && t1 != (void *)&D_0051B464 && t1 != (void *)&D_0051B514;
}
