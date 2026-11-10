// CGtSoundRealVoice::Update(const CGtSoundVoiceParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sibling Start's declarations; volume = if/else then one [0,1] clamp ternary, written twice (second under !set); FLT_MIN tests; t5 declared before t4).

// CGtSoundRealVoice::Update(const CGtSoundVoiceParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished (declarations from the sibling CGtSoundRealVoice::Start, 0x003856D0).

class CGtSoundVoiceParams;

class CGtSoundRealVoice;
class CGtSoundVoice;
class CGtSoundWave;
struct CGtSoundVoiceParams;
struct UnkStruct_003856D0_10;
struct UnkStruct_003856D0_11;
struct UnkStruct_003856D0_7;
struct UnkStruct_003856D0_9;
struct UnkStruct_003856D0_e0;
struct UnkStruct_D_01EA4B00;

class CGtSoundWave {
public:
    float CalcFrequency() const;
    int GetLength() const;

    unsigned char pad_0[0x8];
    int field_8;
};

struct CGtSoundVoiceParams {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    CGtSoundWave * field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    unsigned char pad_34[0x4];
    float field_38;
    float field_3C;
    int field_40;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
};

struct UnkStruct_003856D0_e0 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_01EA4B00 {
    UnkStruct_003856D0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003856D0_7 {
    unsigned char pad_0[0x30];
    UnkStruct_003856D0_10 * field_30;
    unsigned char pad_34[0x28];
    unsigned short field_5C;
    unsigned char pad_5E[0xA];
    float field_68;
    float field_6C;
    float field_70;
    float field_74;
    float field_78;
    float field_7C;
    unsigned char pad_80[0x18];
    float field_98;
    unsigned char pad_9C[0x4];
    float field_A0;
    unsigned char pad_A4[0x10];
    float field_B4;
    float field_B8;
};

struct UnkStruct_003856D0_9 {
    unsigned char pad_0[0x5C];
    unsigned short field_5C;
};

struct UnkStruct_003856D0_10 {
    unsigned char pad_0[0x18];
    int field_18;
};

struct UnkStruct_003856D0_11 {
    int field_0;
};

class CGtSoundVoice {
public:
    static int _munUniquePlayIdCounter;
    static float _mrMasterPitch;
    static float _mrMasterVolume;
};

class CGtSoundRealVoice {
public:
    void Update(const CGtSoundVoiceParams* p0);

    CGtSoundWave * field_0;
    int field_4;
    unsigned char pad_8[0x4];
    float field_C;
    float field_10;
    UnkStruct_003856D0_7 * field_14;
    unsigned char field_18;
    unsigned char pad_19[0x1];
    unsigned char field_1A;
    unsigned char field_1B;
    unsigned char pad_1C[0x1];
    unsigned char field_1D;
};

extern UnkStruct_D_01EA4B00 D_01EA4B00;

extern "C" void _rwaSPU2VoiceSetWave(UnkStruct_003856D0_7 *, int);
extern "C" void _rwaSPU2VoiceSetLoop(UnkStruct_003856D0_7 *, int);  // [G] int param: arg evaluation order (a0 before a1) only matches with int
extern "C" void _rwaSPU2VoiceSetPan(UnkStruct_003856D0_7 *, float);

// [G] 3-float vector: the copy reloads p0->field_C after the FLT_MIN test, so it is a struct copy
struct UnkStruct_003856D0_v3 { float field_0; float field_4; float field_8; };

// 0x00385B10
void CGtSoundRealVoice::Update(const CGtSoundVoiceParams* p0)
{
    UnkStruct_003856D0_e0 * e = &D_01EA4B00.field_0[field_1A];
    float t5 = e->field_4;
    float t4 = e->field_0;
    bool set = false;
    if (!(p0->field_24 < 0.0f)) {
        field_10 = p0->field_24;
    }
    float f;
    if (field_1B & 0x10) {
        f = field_10 * t4;
    } else {
        f = t4 * (field_10 * CGtSoundVoice::_mrMasterPitch);
    }
    field_14->field_5C = (field_14->field_5C | 1);
    field_14->field_98 = f;
    if (1.1754944e-38f == p0->field_C && 1.1754944e-38f == p0->field_10 && 1.1754944e-38f == p0->field_14) {
    } else {
        UnkStruct_003856D0_7 * t = field_14;
        *(UnkStruct_003856D0_v3 *)&t->field_74 = *(const UnkStruct_003856D0_v3 *)&p0->field_C;
    }
    if (p0->field_40 != -1 && (unsigned int)p0->field_40 < (unsigned int)p0->field_18->GetLength()) {
        field_14->field_5C = (field_14->field_5C | 128);
        field_14->field_30->field_18 = p0->field_40;
    }
    if (1.1754944e-38f != p0->field_28) {
        _rwaSPU2VoiceSetPan(field_14, p0->field_28);
    }
    if (1.1754944e-38f != p0->field_2C) {
        _rwaSPU2VoiceSetPan(field_14, p0->field_2C);
    }
    if (!(p0->field_30 < 0.0f)) {
        field_C = p0->field_30;
        set = true;
    }
    float v;
    {
        float x;
        if (field_1D != 0) {
            x = field_C * t5;
        } else {
            x = t5 * (field_C * CGtSoundVoice::_mrMasterVolume);
        }
        v = (x < 0.0f) ? 0.0f : ((x > 1.0f) ? 1.0f : x);
    }
    field_14->field_5C = (field_14->field_5C | 2);
    field_14->field_A0 = v;
    if (!(p0->field_1C < 0.0f) && !set) {
        field_C = p0->field_1C;
    }
    if (!set) {
        {
            float x;
            if (field_1D != 0) {
                x = field_C * t5;
            } else {
                x = t5 * (field_C * CGtSoundVoice::_mrMasterVolume);
            }
            v = (x < 0.0f) ? 0.0f : ((x > 1.0f) ? 1.0f : x);
        }
        field_14->field_5C = (field_14->field_5C | 2);
        field_14->field_A0 = v;
    }
}
