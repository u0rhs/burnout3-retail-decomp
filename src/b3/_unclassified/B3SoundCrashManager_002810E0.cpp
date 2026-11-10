// CB3SoundCrashManager::ReleaseStreams() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (stream fields typed as pointers (void*), not int: keeps both if-bodies inline).

// lifter variant 0
// CB3SoundCrashManager::ReleaseStreams() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundCrashManager;
struct UnkStruct_D_01E774E0;

struct UnkStruct_D_01E774E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundCrashManager {
public:
    void ReleaseStreams();

    unsigned char pad_0[0x884];
    void * field_884;  // [L] a CGtSoundStream* (Stop/Release/FreeStream below)
    void * field_888;  // [L] a CGtSoundStream*
};

extern UnkStruct_D_01E774E0 D_01E774E0;

extern "C" void Stop__14CGtSoundStreamFv(void *);          // CGtSoundStream::Stop() (research/retail_names.csv)
extern "C" int Release__14CGtSoundStreamFv(void *);          // CGtSoundStream::Release() (config/symbol_addrs_b3names.txt, E map)
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);  // CGtSoundStreamManager::FreeStream(CGtSoundStream*) (same)

// 0x002810E0
// [C] the fields are pointers: typed int, MWCC moves each if-body out of line.
void CB3SoundCrashManager::ReleaseStreams()
{
    if (field_884 != 0) {
        Stop__14CGtSoundStreamFv(field_884);
        Release__14CGtSoundStreamFv(field_884);
        FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, field_884);
        field_884 = 0;
    }
    if (field_888 != 0) {
        Stop__14CGtSoundStreamFv(field_888);
        Release__14CGtSoundStreamFv(field_888);
        FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, field_888);
        field_888 = 0;
    }
}
