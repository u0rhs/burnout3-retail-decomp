// CB3NetworkManager::SetPlayerRecordsNotAdded() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C).

struct UnkStruct_026D_a164_R { unsigned char pad_0[0x4D]; unsigned char f4D; unsigned char pad_1[2]; };
struct UnkStruct_026D_a164 {
    unsigned char pad_0[0x323E0];
    UnkStruct_026D_a164_R rec[1];
    unsigned char pad_1[0x32660 - 0x323E0 - 0x50];
    int count;
};
extern "C" void SetPlayerRecordsNotAdded__17CB3NetworkManagerFv(UnkStruct_026D_a164 *s)
{
    for (int i = 0; i < s->count; i++) {
        s->rec[i].f4D = 0;
    }
}
