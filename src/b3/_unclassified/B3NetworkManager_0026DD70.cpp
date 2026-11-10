// CB3NetworkManager::GetEmptyPlayerRecord() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C).

struct UnkStruct_026D_a164_R { unsigned char b[0x50]; };
struct UnkStruct_026D_a164 {
    unsigned char pad_0[0x323E0];
    UnkStruct_026D_a164_R rec[1];
    unsigned char pad_1[0x32660 - 0x323E0 - 0x50];
    int count;
};
extern "C" UnkStruct_026D_a164_R *GetEmptyPlayerRecord__17CB3NetworkManagerFv(UnkStruct_026D_a164 *s)
{
    s->count = s->count + 1;
    return &s->rec[s->count - 1];
}
