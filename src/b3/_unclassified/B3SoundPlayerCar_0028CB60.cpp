// CB3SoundPlayerCar::Prepare(unsigned long,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundPlayerCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bool returns (base Prepare, vfunc_8, TurboModel::Prepare); && guard; float& clamp ref; i < 4).

// from build/vt\try_Prepare__17CB3SoundPlayerCarFUli_best.cpp
// CB3SoundPlayerCar::Prepare(unsigned long,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundPlayerCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundESMManager;
class CB3SoundPlayerCar;
class CB3SoundTurboModel;
class CGtSoundVirtualVoice;
struct UnkStruct_0028CB60_3;
struct UnkStruct_0028CB60_4;
struct UnkStruct_D_004BFB38;
struct UnkStruct_D_004E06CC;
struct UnkStruct_D_01E75644;
struct UnkStruct_D_01E75648;

class CB3SoundESMManager {
public:
    UnkStruct_0028CB60_4 * RequestESM(bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundTurboModel {
public:
    bool Prepare(const char*);
};

class CGtSoundVirtualVoice {
public:
    void Stop();
};

struct UnkStruct_D_01E75644 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E06CC {
    float field_0;
};

struct UnkStruct_0028CB60_3 {
    unsigned char pad_0[0x28];
    float field_28;
};

struct UnkStruct_0028CB60_4 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual bool vfunc_8(unsigned char, unsigned long, int);
    unsigned char pad_4[0x24];
    int field_28;
};

struct UnkStruct_D_004BFB38 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E75648 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundPlayerCar {
public:
    bool Prepare(unsigned long p0, int p1);

    unsigned char pad_0[0x4];
    UnkStruct_0028CB60_4 * field_4;
    unsigned char pad_8[0x60];
    UnkStruct_0028CB60_3 * field_68;
    unsigned char pad_6C[0x52];
    unsigned char field_BE;
    unsigned char pad_BF[0x81];
    int field_140;
    CB3SoundTurboModel field_144;
    unsigned char pad_145[0x17];
    CGtSoundVirtualVoice * field_15C[1];  // [G] element count unknown
    unsigned char pad_160[0xC];
    int field_16C[1];  // [G] element count unknown
    unsigned char pad_170[0x14];
    int field_184;
    int field_188;
    unsigned char pad_18C[0x4];
    unsigned char field_190;
};

extern UnkStruct_D_01E75644 D_01E75644;
extern UnkStruct_D_004E06CC D_004E06CC;
extern CB3SoundESMManager D_01E78170;
extern UnkStruct_D_004BFB38 D_004BFB38;
extern UnkStruct_D_01E75648 D_01E75648;

extern "C" bool Prepare__15CB3SoundRaceCarFUli(void *, unsigned long, int);  // CB3SoundRaceCar::Prepare(unsigned long,int)
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" int FindWave__19CGtSoundBankManagerCFRCUlb(void *, void *, bool);  // CGtSoundBankManager::FindWave(const unsigned long&,bool) const
extern "C" int func_00383C00(void *);

// 0x0028CB60
bool CB3SoundPlayerCar::Prepare(unsigned long p0, int p1)
{
    bool r = Prepare__15CB3SoundRaceCarFUli(this, p0, p1);
    if (D_01E75644.field_0 != 0 && field_190 == 0) {
        field_68->field_28 = field_68->field_28 * D_004E06CC.field_0;
        float & x = field_68->field_28;
        if (x > 1.0f) {
            x = 1.0f;
        }
        field_190 = 1;
    } else {
        field_190 = 0;
    }
    if (r) {
        if (field_4 == 0) {
            field_4 = D_01E78170.RequestESM(1);
        }
        r = field_4->vfunc_8(field_BE, p0, p1);
        if (r) {
            r = field_144.Prepare((const char *)func_00383C00((void *)(field_4->field_28)));
            field_184 = FindWave__12CGtSoundBankCFRCUlb((void *)field_4->field_28, &D_004BFB38, 0);
            if (field_184 == 0) {
                field_184 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &D_004BFB38, 0);
            }
        }
    }
    field_140 = 0;
    field_188 = 0;
    for (int i = 0; i < 4; i++) {
        field_16C[i] = 0;
        if (field_15C[i] != 0) {
            field_15C[i]->Stop();
            field_15C[i] = 0;
        }
    }
    return r;
}
