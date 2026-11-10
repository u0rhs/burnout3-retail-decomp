// CB3NetworkManager::GetPlayerRecordByID(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a79: find loop, id == slot.field_0 operand order).

struct UnkStruct_0026DD00_slot {
    int field_0;
    unsigned char pad_4[0x4C];
};
class CB3NetworkManager {
public:
    UnkStruct_0026DD00_slot * GetPlayerRecordByID(int);
    unsigned char pad_0[0x323E0];
    UnkStruct_0026DD00_slot field_323E0[8];
    int field_32660;
};
// 0x0026DDC0
UnkStruct_0026DD00_slot * CB3NetworkManager::GetPlayerRecordByID(int id)
{
    for (int i = 0; i < field_32660; i++) {
        if (id == field_323E0[i].field_0) {
            return &field_323E0[i];
        }
    }
    return 0;
}
