// B3OnlineGameCreateState.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3OnlineGameCreateState.cpp.
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_00324E10;
struct UnkStruct_00324E10_0;

struct UnkStruct_00324E10_0 {
    unsigned char pad_0[0x1];
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    unsigned char pad_4[0x1];
    unsigned char field_5;
    unsigned char pad_6[0x2];
};
struct UnkStruct_00324E10 {
    unsigned char field_0[1];  // [G] element count unknown
};

extern "C" void sceCdReadClock(UnkStruct_00324E10_0 *);
extern "C" void sceScfGetGMTfromRTC(UnkStruct_00324E10_0 *);
extern "C" void srand(unsigned int);
extern "C" int rand();

// func_00324E10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00324E10
extern "C" void func_00324E10(UnkStruct_00324E10 * self)
{
    UnkStruct_00324E10_0 local;  // [G] the frame's one local (size: up to the frame top)
    sceCdReadClock(&local);
    sceScfGetGMTfromRTC(&local);
    int seed = 0;
    seed += local.field_1;
    seed <<= 8;
    seed += local.field_2;
    seed <<= 8;
    seed += local.field_3;
    seed <<= 8;
    seed += local.field_5;
    srand(seed);
    rand();
    rand();
    for (int i = 0; (i < 32); i++) {
        int r5 = rand();
        self->field_0[i] = r5;
    }
}
