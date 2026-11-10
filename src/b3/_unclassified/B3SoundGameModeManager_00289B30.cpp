// CB3SoundGameModeManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bank fields are CGtSoundBank* (null-tested, passed on)).

// CB3SoundGameModeManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundBank;

class CB3HUDSoundManager;
class CB3SoundCrashManager;
class CB3SoundESMManager;
class CB3SoundGameModeManager;
class CB3SoundRaceCarManager;
class CB3SoundStaticPassManager;
class CB3SoundTrafficManager;
class CGtSoundBankManager;
class CGtSoundListenerManager;
struct UnkStruct_D_01E75640;

class CGtSoundBankManager {
public:
    void UnloadBank(CGtSoundBank*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundRaceCarManager {
public:
    void Release();
};

class CB3SoundESMManager {
public:
    void Release();
};

class CB3SoundCrashManager {
public:
    void Release();
};

class CB3SoundTrafficManager {
public:
    void Release();
};

class CB3HUDSoundManager {
public:
    void Release();
};

class CB3SoundStaticPassManager {
public:
    void Release();
};

class CGtSoundListenerManager {
public:
    void Release();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E75640 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundGameModeManager {
public:
    void Release();

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
    CB3SoundRaceCarManager field_10;
    unsigned char pad_11[0xC1F];
    CB3SoundESMManager field_C30;
    unsigned char pad_C31[0x39F];
    CB3SoundCrashManager field_FD0;
    unsigned char pad_FD1[0x93F];
    CB3SoundTrafficManager field_1910;
    unsigned char pad_1911[0x19AF];
    CB3HUDSoundManager field_32C0;
    unsigned char pad_32C1[0x7F];
    CB3SoundStaticPassManager field_3340;
    unsigned char pad_3341[0x1F77];
    CGtSoundBank * field_52B8;
    CGtSoundBank * field_52BC;
    unsigned char pad_52C0[0xD];
    unsigned char field_52CD;
};

extern UnkStruct_D_01E75640 D_01E75640;
extern CGtSoundBankManager D_01E75648;
extern CGtSoundListenerManager D_01E75688;

extern "C" void func_0028AEB0(void *);
extern "C" int func_003FAA50(void *);

void CB3SoundGameModeManager::Release()
{
    func_0028AEB0(&D_01E75640);
    if (field_52B8 != 0) {
        D_01E75648.UnloadBank(field_52B8);
        field_52B8 = 0;
    }
    if (field_52BC != 0) {
        D_01E75648.UnloadBank(field_52BC);
        field_52BC = 0;
    }
    field_10.Release();
    field_C30.Release();
    field_FD0.Release();
    field_1910.Release();
    field_32C0.Release();
    field_3340.Release();
    func_003FAA50(((char *)this + 0x3348));
    D_01E75688.Release();
    field_4 = 24;
    field_52CD = 0;
}
