// CGtSoundManager::Update(float,float,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundBankManager;
class CGtSoundListenerManager;
class CGtSoundManager;
class CGtSoundStreamManager;
class CGtSoundVoiceManager;

class CGtSoundListenerManager {
public:
    void Update();
};

class CGtSoundBankManager {
public:
    void Update();
};

class CGtSoundStreamManager {
public:
    void Update();
};

class CGtSoundVoiceManager {
public:
    void Update(float, float, float, float);
};

class CGtSoundManager {
public:
    void Update(float p0, float p1, float p2, float p3);

    unsigned char pad_0[0x8];
    CGtSoundBankManager field_8;
    unsigned char pad_9[0x3F];
    CGtSoundListenerManager field_48;
    unsigned char pad_49[0x13];
    CGtSoundVoiceManager field_5C;
    unsigned char pad_5D[0x1E43];
    CGtSoundStreamManager field_1EA0;
};

struct UnkStruct_00385010_pad {
    unsigned char field_0[0x4];
    UnkStruct_00385010_pad() {}
    ~UnkStruct_00385010_pad() {}
};

// 0x00385010
void CGtSoundManager::Update(float p0, float p1, float p2, float p3)
{
    UnkStruct_00385010_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    field_48.Update();
    field_8.Update();
    field_1EA0.Update();
    field_5C.Update(p0, p1, p2, p3);
}
