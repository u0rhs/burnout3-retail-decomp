// CB3SoundESMManager::RequestESM(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESMManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a76: two slot-array find loops).

// [G] two slot arrays (1 x 0xC0 at +8, 5 x 0x90 at +0xC8), busy byte at +0x55; first loop gated by the bool. No DNAT row.
struct UnkStruct_002FAE90_0 {
    unsigned char pad_0[0x55];
    unsigned char field_55;
    unsigned char pad_56[0x6A];
};

struct UnkStruct_002FAE90_1 {
    unsigned char pad_0[0x55];
    unsigned char field_55;
    unsigned char pad_56[0x3A];
};

class CB3SoundESMManager {
public:
    unsigned char pad_0[8];
    UnkStruct_002FAE90_0 field_8[1];
    UnkStruct_002FAE90_1 field_C8[5];
    void * RequestESM(bool);
};

// 0x002FAE90
void * CB3SoundESMManager::RequestESM(bool b)
{
    if (b) {
        for (unsigned int i = 0; i < 1; i++) {
            if (field_8[i].field_55 == 0) {
                field_8[i].field_55 = 1;
                return &field_8[i];
            }
        }
    }
    for (unsigned int i = 0; i < 5; i++) {
        if (field_C8[i].field_55 == 0) {
            field_C8[i].field_55 = 1;
            return &field_C8[i];
        }
    }
    return 0;
}
