// CB3ProfileManager::UnlockAll() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Profile.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

struct UnkStruct_D_0051BF9C;

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3ProfileManager {
public:
    void UnlockAll();
};

extern UnkStruct_D_0051BF9C D_0051BF9C;

extern "C" void func_00139790(void *);

// 0x00136490
void CB3ProfileManager::UnlockAll()
{
    func_00139790((void *)(D_0051BF9C.field_0));
}
