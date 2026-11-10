// viBufCreate -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> vibuf.c.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (6-int sema struct, field_8 before field_4).

struct UnkStruct_c0 {
    unsigned int field_0;
    unsigned int field_4;
    int field_8;
    unsigned char pad_C[0xC];
    int field_18;
    unsigned char pad_1C[0x24];
    int field_40;
    unsigned char pad_44[0x4];
    long field_48;
    int field_50;
    int field_54;
};
struct UnkStruct_viBufCreate_sema { int field_0; int field_4; int field_8; int field_C; int field_10; int field_14; };
extern "C" int CreateSema(UnkStruct_viBufCreate_sema *);
extern "C" int viBufReset(UnkStruct_c0 *);
// 0x003268E0
extern "C" int viBufCreate(UnkStruct_c0 *b, void *p1_, void *p2_, int p3, int p4, int p5)
{
    unsigned int p1 = (unsigned int)p1_;
    unsigned int p2 = (unsigned int)p2_;
    UnkStruct_viBufCreate_sema sema;
    b->field_0 = p1;
    b->field_4 = (p2 & 0x0FFFFFFF) | 0x20000000;
    b->field_8 = p3;
    b->field_18 = p3 << 16;
    b->field_50 = p4;
    b->field_54 = p5;
    sema.field_8 = 1;
    sema.field_4 = 1;
    b->field_40 = CreateSema(&sema);
    viBufReset(b);
    b->field_48 = 0;
    return 1;
}
