// GtVideoDecoderPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> GtVideoDecoderPS2.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/Graphical/VideoDecoder/Ps2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/VideoDecoder/Ps2/GtVideoDecoderPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_00324EF0;
struct UnkStruct_00325990;
struct UnkStruct_00325990_e0;

struct UnkStruct_00324ED0 {
    unsigned char pad_0[0x4A];
    unsigned char field_4A;
};
struct UnkStruct_00324EE0 {
    unsigned char pad_0[0x49];
    unsigned char field_49;
};
struct UnkStruct_00324EF0 {
    unsigned char pad_0[0x38];
    int field_38;
    unsigned char pad_3C[0x4];
    float field_40;
};
struct UnkStruct_00325990_e0 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0xC];
};
struct UnkStruct_00325990 {
    UnkStruct_00325990_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_18[0x48];
    int field_60;
    int field_64;
    int field_68;
    unsigned char pad_6C[0xB4];
    int field_120;
    int field_124;
};

extern "C" void sceMpegInit(UnkStruct_00325990 *);

// func_00324ED0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00324ED0
extern "C" void func_00324ED0(UnkStruct_00324ED0 *self)
{
    self->field_4A = 1;
}

// func_00324EE0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00324EE0
extern "C" unsigned char func_00324EE0(UnkStruct_00324EE0 *self)
{
    return self->field_49;
}

// func_00324EF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00324EF0
extern "C" float func_00324EF0(UnkStruct_00324EF0 * self)
{
    return (self->field_40 * ((float)self->field_38));
}

// Construct__15CGtVideoDecoderFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00325990
extern "C" void Construct__15CGtVideoDecoderFv(UnkStruct_00325990 * self)
{
    for (int i = 0; (i < 2); i++) {
        self->field_0[i].field_0 = 0;
        self->field_0[i].field_4 = -1;
        self->field_0[i].field_8 = -1;
    }
    self->field_60 = 0;
    self->field_64 = 0;
    self->field_68 = 0;
    self->field_120 = 0;
    self->field_124 = 1;
    sceMpegInit(self);
}
