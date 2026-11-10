// CB3EffectsManager::EndCoronaSubmit() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3EffectsManager;
struct UnkStruct_00262240_e0;

struct UnkStruct_00262240_e0 {
    unsigned char pad_0[0x34];
};

class CB3EffectsManager {
public:
    void EndCoronaSubmit();

    UnkStruct_00262240_e0 field_0[1];  // [G] element count unknown
};

extern "C" void EndUpdate__21CB3CoronaDynamicArrayFv(void *);  // CB3CoronaDynamicArray::EndUpdate()

struct UnkStruct_00262240_pad {
    unsigned char field_0[0x4];
    UnkStruct_00262240_pad() {}
    ~UnkStruct_00262240_pad() {}
};

// 0x00262240
void CB3EffectsManager::EndCoronaSubmit()
{
    UnkStruct_00262240_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    for (int i = 0; (i < 3); i++) {
        EndUpdate__21CB3CoronaDynamicArrayFv(((char *)&field_0[i] + 0xC));
    }
}
