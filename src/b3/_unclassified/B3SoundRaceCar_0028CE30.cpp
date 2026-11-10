// CB3SoundRaceCar::UpdateBoostIn(const CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (null early return, then if/else join (only the mismatch arm returns); params + vector temp as two locals).

// from build/vt\try_UpdateBoostIn__15CB3SoundRaceCarFPC10CB3_best.cpp
// CB3SoundRaceCar::UpdateBoostIn(const CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3RaceCar;
class CGtSoundVoiceParams;

class CB3SoundRaceCar;
class CGtSoundVirtualVoice;
struct CB3RaceCar;
struct UnkStruct_0028CE30_2;

class CGtSoundVirtualVoice {
public:
    int IsPlaying();
    void Stop();
    void Update(const CGtSoundVoiceParams*);

    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_0028CE30_p {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0x44];
};
struct UnkStruct_0028CE30_v {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};
struct UnkStruct_0028CE30_2 {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0x4];
    float field_10;
    float field_14;
    float field_18;
    unsigned char pad_1C[0x44];
};

struct CB3RaceCar {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

class CB3SoundRaceCar {
public:
    void UpdateBoostIn(const CB3RaceCar* p0);

    unsigned char pad_0[0x78];
    CGtSoundVirtualVoice * field_78;
    unsigned char pad_7C[0x8];
    int field_84;
};

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()

// 0x0028CE30
void CB3SoundRaceCar::UpdateBoostIn(const CB3RaceCar* p0)
{
    UnkStruct_0028CE30_p params;
    UnkStruct_0028CE30_v v;
    if (field_78 == 0) {
        return;
    }
    {
        if (field_78->IsPlaying() == 0) {
            if (field_84 == field_78->field_C) {
                field_78->Stop();
            }
            field_78 = 0;
        } else {
            if (field_84 != field_78->field_C) {
                field_78 = 0;
                return;
            }
            Construct__19CGtSoundVoiceParamsFv(&params);
            *(u_long128 *)&v = p0->field_30;
            params.field_0 = v.field_0;
            params.field_4 = v.field_4;
            params.field_8 = v.field_8;
            field_78->Update((const CGtSoundVoiceParams*)&params);
        }
    }
}
