// CGtSoundListenerManager::Prepare(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListenerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundListenerManager;
struct UnkStruct_00384D40_2;

struct UnkStruct_00384D40_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C(int);
};

class CGtSoundListenerManager {
public:
    int Prepare(unsigned int p0);

    UnkStruct_00384D40_2 * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
    int field_8;
};

extern "C" void RwaListenerManagerSetMode(int);

// 0x00384D40
int CGtSoundListenerManager::Prepare(unsigned int p0)
{
    field_8 = p0;
    for (int i = 0; ((unsigned int)i < (unsigned int)p0); i++) {
        field_0[i]->vfunc_C(i);
    }
    if (field_8 == 1) {
        RwaListenerManagerSetMode(2);
    } else {
        RwaListenerManagerSetMode(3);
    }
    return 1;
}
