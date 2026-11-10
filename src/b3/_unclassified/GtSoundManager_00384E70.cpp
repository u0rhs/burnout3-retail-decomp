// CGtSoundManager::StopAll() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundManager;
class CGtSoundStreamManager;
class CGtSoundVoiceManager;

class CGtSoundVoiceManager {
public:
    void Release();
};

class CGtSoundStreamManager {
public:
    void StopAll();
};

class CGtSoundManager {
public:
    void StopAll();

    unsigned char pad_0[0x5C];
    CGtSoundVoiceManager field_5C;
    unsigned char pad_5D[0x1E43];
    CGtSoundStreamManager field_1EA0;
};

extern "C" void RwaCoreUpdateStart(CGtSoundManager *);
extern "C" void RwaCoreUpdateFinish();

struct UnkStruct_00384E70_pad {
    unsigned char field_0[0x4];
    UnkStruct_00384E70_pad() {}
    ~UnkStruct_00384E70_pad() {}
};

// 0x00384E70
void CGtSoundManager::StopAll()
{
    UnkStruct_00384E70_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    RwaCoreUpdateStart(this);
    field_5C.Release();
    field_1EA0.StopAll();
    RwaCoreUpdateFinish();
}
