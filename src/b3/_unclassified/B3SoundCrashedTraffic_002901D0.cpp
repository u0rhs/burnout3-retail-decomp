// CB3SoundCrashedTraffic::StartSkidVoices() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashedTraffic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sibling StartBassVoices params/v structs; inline RNG step via const ptr (x += y separate); range test (unsigned)(x-3) <= 2; if/else-if wave selection).

// from build/vt\try_StartSkidVoices__22CB3SoundCrashedTraffi_best.cpp
// CB3SoundCrashedTraffic::StartSkidVoices() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashedTraffic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtSoundVoiceParams;

class CB3SoundCrashedTraffic;
class CGtSoundVoiceManager;
class CGtSoundWave;
struct UnkStruct_002901D0_0;
struct UnkStruct_002901D0_2;
struct UnkStruct_002901D0_3;
struct UnkStruct_002901D0_5;
struct UnkStruct_D_01E78E58;

class CGtSoundWave {
public:
    float CalcFrequency() const;
};

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002901D0_0 {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0x4];
    float field_10;
    float field_14;
    float field_18;
    unsigned char pad_1C[0xC];
    int field_28;
    int field_2C;
    unsigned char pad_30[0x4];
    float field_34;
    unsigned char pad_38[0x1D];
    unsigned char field_55;
    unsigned char pad_56[0xA];
};

struct UnkStruct_002901D0_2 {
    unsigned char pad_0[0x204];
    UnkStruct_002901D0_3 * field_204;
    unsigned char pad_208[0x2218];
    int field_2420;
};

struct UnkStruct_002901D0_3 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_D_01E78E58 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002901D0_5 {
    unsigned char pad_0[0xC];
    int field_C;
};

class CB3SoundCrashedTraffic {
public:
    void StartSkidVoices();

    UnkStruct_002901D0_2 * field_0;
    unsigned char pad_4[0x8];
    CGtSoundWave * field_C;
    CGtSoundWave * field_10;
    CGtSoundWave * field_14;
    UnkStruct_002901D0_5 * field_18;
    int field_1C;
    unsigned char pad_20[0x4];
    int field_24;
    int field_28;
    int field_2C;
};

extern UnkStruct_D_01E78E58 D_01E78E58;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()

struct UnkStruct_002901D0_p {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    CGtSoundWave * field_18;
    int field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x1D];
    unsigned char field_45;
    unsigned char pad_46[0xA];
};
struct UnkStruct_002901D0_v {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};
// [G] inlined random-number step (no name in any table): D_01E78E58 = { x, y }
static inline unsigned int func_002901D0_inl1()
{
    UnkStruct_D_01E78E58 * const r = &D_01E78E58;
    int x = r->field_0;
    x = (x << 16) + (x >> 16);
    x += r->field_4;
    r->field_0 = x;
    r->field_4 += x;
    return x;
}

// 0x002901D0
void CB3SoundCrashedTraffic::StartSkidVoices()
{
    UnkStruct_002901D0_p params;
    UnkStruct_002901D0_v v;
    Construct__19CGtSoundVoiceParamsFv(&params);
    *(u_long128 *)&v = field_0->field_204->field_30;
    params.field_45 = 1;
    params.field_1C = 0;
    params.field_0 = v.field_0;
    params.field_4 = v.field_4;
    params.field_8 = v.field_8;
    field_24 = 0;
    field_28 = func_002901D0_inl1() % 30 + 30;
    field_2C = 0;
    if ((unsigned int)(field_0->field_2420 - 3) <= 2) {
        params.field_18 = field_14;
        params.field_24 = field_14->CalcFrequency();
    } else if (field_28 % 2 == 0) {
        params.field_18 = field_C;
        params.field_24 = field_C->CalcFrequency();
    } else {
        params.field_18 = field_10;
        params.field_24 = field_10->CalcFrequency();
    }
    field_18 = (UnkStruct_002901D0_5 *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams *)&params);
    if (field_18 != 0) {
        field_1C = field_18->field_C;
    }
}
