// CGtSoundListenerManager::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListenerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundListenerManager;
struct UnkStruct_00384CE0_2;

struct UnkStruct_00384CE0_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
};

class CGtSoundListenerManager {
public:
    void Update();

    UnkStruct_00384CE0_2 * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
    int field_8;
};

// 0x00384CE0
void CGtSoundListenerManager::Update()
{
    for (int i = 0; ((unsigned int)i < (unsigned int)field_8); i++) {
        field_0[i]->vfunc_8();
    }
}
