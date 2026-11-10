// CB3SoundESMManager::RelinquishESM(CB3SoundESM*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESMManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundESM;

class CB3SoundESMManager;
struct CB3SoundESM;

struct CB3SoundESM {
    unsigned char pad_0[0x55];
    unsigned char field_55;
};

class CB3SoundESMManager {
public:
    void RelinquishESM(CB3SoundESM* p0);
};

// 0x002FAE70
void CB3SoundESMManager::RelinquishESM(CB3SoundESM* p0)
{
    if (p0 == 0) return;
    p0->field_55 = 0;
}
