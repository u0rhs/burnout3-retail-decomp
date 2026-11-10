// CB3SoundCrashManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundBank;

class CB3SoundCrashManager;
class CGtSoundBankManager;
class CGtSoundVirtualVoice;
struct UnkStruct_00280FC0_e2;
struct UnkStruct_D_01E774E0;

class CGtSoundBankManager {
public:
    void UnloadBank(CGtSoundBank*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtSoundVirtualVoice {
public:
    void Stop();
};

struct UnkStruct_00280FC0_e2 {
    unsigned char pad_0[0x40];
};

struct UnkStruct_D_01E774E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundCrashManager {
public:
    void Release();

    int field_0;
    unsigned char pad_4[0x87C];
    void * field_880;
    void * field_884;
    void * field_888;
    unsigned char pad_88C[0x90];
    CGtSoundVirtualVoice * field_91C[1];  // [G] element count unknown
    unsigned char pad_920[0xC];
    int field_92C[1];  // [G] element count unknown
};

extern CGtSoundBankManager D_01E75648;
extern UnkStruct_D_01E774E0 D_01E774E0;

extern "C" void Release__14CB3SoundScrapeFv(void *);  // CB3SoundScrape::Release()
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);

// 0x00280FC0
void CB3SoundCrashManager::Release()
{
    for (int i = 0; (i < 6); i++) {
        Release__14CB3SoundScrapeFv(((char *)((char *)this + (i << 6)) + 0x10));
    }
    void * t0 = field_880;
    if (t0 != 0) {
        D_01E75648.UnloadBank((CGtSoundBank*)t0);
        field_880 = 0;
    }
    for (int i1 = 0; (i1 < 4); i1++) {
        CGtSoundVirtualVoice * t1 = field_91C[i1];
        if (t1 != 0) {
            t1->Stop();
        }
        field_91C[i1] = 0;
        field_92C[i1] = 0;
    }
    void * t2 = field_884;
    if (t2 != 0) {
        Stop__14CGtSoundStreamFv(t2);
        Release__14CGtSoundStreamFv(field_884);
        FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, field_884);
        field_884 = 0;
    }
    void * t3 = field_888;
    if (t3 != 0) {
        Stop__14CGtSoundStreamFv(t3);
        Release__14CGtSoundStreamFv(field_888);
        FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, field_888);
        field_888 = 0;
    }
    field_0 = 24;
}
