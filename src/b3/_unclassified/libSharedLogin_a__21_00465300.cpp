// SLoginStatePreviousGet -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> libSharedLogin.a /21.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C; gp-rel pointer global).

struct UnkStruct_a167_sl { unsigned char pad_0[0x108]; int field_108; };
extern UnkStruct_a167_sl * D_004E2FC4;
// 0x00465300
extern "C" int SLoginStatePreviousGet(int * p0)
{
    *p0 = D_004E2FC4->field_108;
    return 0;
}
