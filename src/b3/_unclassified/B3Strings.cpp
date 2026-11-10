// B3Strings.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3Strings.cpp.
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_00271A60;

struct UnkStruct_00271A10 {
    int field_0;
};
struct UnkStruct_00271A50 {
    int field_0;
};
struct UnkStruct_00271A60 {
    unsigned char pad_0[0xC];
    int * field_C;
};

// func_00271A10 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00271A10
extern "C" void func_00271A10(UnkStruct_00271A10 *self)
{
    self->field_0 = 0;
}

// func_00271A50 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00271A50
extern "C" void func_00271A50(UnkStruct_00271A50 *self)
{
    self->field_0 = 0;
}

// func_00271A60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00271A60
extern "C" int func_00271A60(UnkStruct_00271A60 * self, int p0)
{
    return self->field_C[p0];
}
