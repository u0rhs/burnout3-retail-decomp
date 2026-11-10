// CB3SoundManager::SetMasterVolumeScalar(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (byte field converted as (float)(unsigned int) (MWCC's unsigned-to-float sequence) inline in the tail call argument).

// lifter variant 0
// CB3SoundManager::SetMasterVolumeScalar(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundManager;
class CGtSoundVoice;
struct UnkStruct__grMasterVolumeScalar;

struct UnkStruct__grMasterVolumeScalar {
    float field_0;
};

class CGtSoundVoice {
public:
    static float _mrMasterVolume;
};

class CB3SoundManager {
public:
    void SetMasterVolumeScalar(float p0);

    unsigned char pad_0[0x7214];
    unsigned char field_7214;
};

extern UnkStruct__grMasterVolumeScalar _grMasterVolumeScalar;

extern "C" void func_0027A900(void *, float);

// 0x0028ADD0
void CB3SoundManager::SetMasterVolumeScalar(float p0)
{
    _grMasterVolumeScalar.field_0 = p0;
    CGtSoundVoice::_mrMasterVolume = p0;
    func_0027A900(((char *)this + 0x2ED0), p0 * ((float)(unsigned int)field_7214 / 255.0f));
}
