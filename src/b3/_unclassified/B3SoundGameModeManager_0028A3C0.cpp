// CB3SoundGameModeManager::Construct(RwaSPU2Output*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class RwaSPU2Output;

class CB3HUDSoundManager;
class CB3SoundCrashManager;
class CB3SoundESMManager;
class CB3SoundGameModeManager;
class CB3SoundRaceCarManager;
class CB3SoundTrafficManager;
struct UnkStruct_D_004E1B74;

class CB3SoundRaceCarManager {
public:
    void Construct();
};

class CB3SoundESMManager {
public:
    void Construct();
};

class CB3SoundCrashManager {
public:
    void Construct();
};

class CB3SoundTrafficManager {
public:
    void Construct();
};

class CB3HUDSoundManager {
public:
    void Construct();
};

struct UnkStruct_D_004E1B74 {
    int field_0;
};

class CB3SoundGameModeManager {
public:
    void Construct(RwaSPU2Output* p0);

    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char pad_C[0x4];
    CB3SoundRaceCarManager field_10;
    unsigned char pad_11[0xC1F];
    CB3SoundESMManager field_C30;
    unsigned char pad_C31[0x39F];
    CB3SoundCrashManager field_FD0;
    unsigned char pad_FD1[0x93F];
    CB3SoundTrafficManager field_1910;
    unsigned char pad_1911[0x19AF];
    CB3HUDSoundManager field_32C0;
    unsigned char pad_32C1[0x1FF7];
    int field_52B8;
    int field_52BC;
    unsigned char pad_52C0[0x4];
    int field_52C4;
};

extern UnkStruct_D_004E1B74 D_004E1B74;

extern "C" void func_003FB710(void *);
extern "C" void func_0041D8E0(void *);

// 0x0028A3C0
void CB3SoundGameModeManager::Construct(RwaSPU2Output* p0)
{
    field_10.Construct();
    field_C30.Construct();
    field_FD0.Construct();
    field_1910.Construct();
    field_32C0.Construct();
    func_003FB710(((char *)this + 0x3348));
    func_0041D8E0(((char *)this + 0x3340));
    field_8 = 1;
    field_52B8 = 0;
    field_52BC = 0;
    field_52C4 = 0;
    field_4 = 1;
    if (D_004E1B74.field_0 == -1) {
        D_004E1B74.field_0 = 0;
    }
}
