// CB3SoundRaceCar::UpdateHorn(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (voice params local declared before a separate 16-byte vector local (lq/sq copy); int* p = &local.field_18 for the wave store/test (as func_00285A60)).

// CB3SoundRaceCar::UpdateHorn(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3RaceCar;
class CGtSoundVoiceParams;

class CB3SoundRaceCar;
class CGtSoundVirtualVoice;
class CGtSoundVoiceManager;
struct CB3RaceCar;
struct UnkStruct_0028CD60_1;
struct UnkStruct_D_004E06C0;

class CGtSoundVirtualVoice {
public:
    void ForgetMe(float);
    void Update(const CGtSoundVoiceParams*);
};

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct CB3RaceCar {
    unsigned char pad_0[0x30];
    u_long128 field_30;
    unsigned char pad_40[0x18AD];
    unsigned char field_18ED;
};

struct UnkStruct_0028CD60_1 {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    int field_18;
    int field_1C;
    unsigned char pad_20[0x24];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};

struct UnkStruct_0028CD60_2 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_D_004E06C0 {
    float field_0;
};

class CB3SoundRaceCar {
public:
    void UpdateHorn(CB3RaceCar* p0);

    unsigned char pad_0[0x7C];
    CGtSoundVirtualVoice * field_7C;
    unsigned char pad_80[0x18];
    int field_98;
};

extern UnkStruct_D_004E06C0 D_004E06C0;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()

// 0x0028CD60
void CB3SoundRaceCar::UpdateHorn(CB3RaceCar* p0)
{
    if (p0->field_18ED == 0) {
        if (field_7C != 0) {
            field_7C->ForgetMe(D_004E06C0.field_0);
            field_7C = 0;
        }
    } else {
        UnkStruct_0028CD60_1 local;
        Construct__19CGtSoundVoiceParamsFv(&local);
        UnkStruct_0028CD60_2 v;
        *(u_long128 *)&v = p0->field_30;
        local.field_0 = v.field_0;
        local.field_4 = v.field_4;
        local.field_8 = v.field_8;
        if (field_7C != 0) {
            field_7C->Update((const CGtSoundVoiceParams*)&local);
        } else {
            local.field_1C = 0;
            local.field_44 = 1;
            local.field_45 = 1;
            int * p = &local.field_18;
            *p = field_98;
            if (*p != 0) {
                field_7C = (CGtSoundVirtualVoice *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&local);
            }
        }
    }
}
