// CGtSoundVoiceManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundVoiceManager;
struct UnkStruct_00389080_e0;
struct UnkStruct_00389080_e1;

struct UnkStruct_00389080_e0 {
    unsigned char pad_0[0x20];
};

struct UnkStruct_00389080_e1 {
    unsigned char pad_0[0x34];
};

class CGtSoundVoiceManager {
public:
    void Release();

    UnkStruct_00389080_e0 field_0[1];  // [G] element count unknown
};

extern "C" void Stop__17CGtSoundRealVoiceFv(void *);  // CGtSoundRealVoice::Stop()
extern "C" void Stop__20CGtSoundVirtualVoiceFv(void *);  // CGtSoundVirtualVoice::Stop()

// 0x00389080
void CGtSoundVoiceManager::Release()
{
    int i = 0;
    do {
        Stop__17CGtSoundRealVoiceFv(((char *)&field_0[i] + 0x1A04));
        i++;
    } while ((unsigned int)i < (unsigned int)16);
    int i1 = 0;
    do {
        Stop__20CGtSoundVirtualVoiceFv(((char *)((char *)this + ((i1 * 13) << 2)) + 0x4));
        i1++;
    } while ((unsigned int)i1 < (unsigned int)128);
}
