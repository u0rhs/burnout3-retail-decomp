// CGtSoundRealVoice::Start(const CGtSoundVoiceParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (SetLoop 2nd param int (arg order); [0,1] clamp as nested ternary with x>1; FLT_MIN vec copy as 12-byte struct copy; pitch product in temp).

// lifter variant 0
// CGtSoundRealVoice::Start(const CGtSoundVoiceParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

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
    unsigned char pad_28[0x10];
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
    void Start(const CGtSoundVoiceParams* p0);

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
static inline void a54_copy(float * d, const float * s)
{
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

// 0x003856D0
void CGtSoundRealVoice::Start(const CGtSoundVoiceParams* p0)
{
    int id = CGtSoundVoice::_munUniquePlayIdCounter;
    CGtSoundVoice::_munUniquePlayIdCounter = id + 1;
    field_4 = id;
    field_1A = p0->field_44;
    field_1B = (field_1B & 1);
    CGtSoundWave * w = p0->field_18;
    field_0 = w;
    _rwaSPU2VoiceSetWave(field_14, w->field_8);
    UnkStruct_003856D0_e0 * e = &D_01EA4B00.field_0[field_1A];
    float t4 = e->field_0;
    float t5 = e->field_4;
    _rwaSPU2VoiceSetLoop(field_14, p0->field_45);
    if (p0->field_24 < 0.0f) {
        field_10 = field_0->CalcFrequency();
    } else {
        field_10 = p0->field_24;
    }
    float f = t4 * (field_10 * CGtSoundVoice::_mrMasterPitch);
    field_14->field_5C = (field_14->field_5C | 1);
    field_14->field_98 = f;
    if (p0->field_1C < 0.0f) {
        field_C = 0.0f;
    } else {
        field_C = p0->field_1C;
    }
    field_1D = p0->field_46;
    float v10;
    if (field_1D != 0) {
        float x = field_C * t5;
        v10 = (x < 0.0f) ? 0.0f : ((x > 1.0f) ? 1.0f : x);  // [G] clamp to [0,1] (inline helper in the original?)
    } else {
        float x = t5 * (field_C * CGtSoundVoice::_mrMasterVolume);
        v10 = (x < 0.0f) ? 0.0f : ((x > 1.0f) ? 1.0f : x);  // [G] clamp to [0,1] (inline helper in the original?)
    }
    field_14->field_5C = (field_14->field_5C | 2);
    field_14->field_A0 = v10;
    if (1.1754944e-38f == p0->field_3C) {
        field_14->field_B4 = 10.0f;
    } else {
        field_14->field_B4 = p0->field_3C;
    }
    if (1.1754944e-38f == p0->field_38) {
        field_14->field_B8 = 50.0f;
    } else {
        field_14->field_B8 = p0->field_38;
    }
    if (1.1754944e-38f == p0->field_C && 1.1754944e-38f == p0->field_10 && 1.1754944e-38f == p0->field_14) {
        UnkStruct_003856D0_7 * t = field_14;
        t->field_74 = 0.0f;
        t->field_78 = 0.0f;
        t->field_7C = 0.0f;
    } else {
        UnkStruct_003856D0_7 * t = field_14;
        *(UnkStruct_003856D0_v3 *)&t->field_74 = *(const UnkStruct_003856D0_v3 *)&p0->field_C;
    }
    if (p0->field_40 != -1 && (unsigned int)p0->field_40 < (unsigned int)p0->field_18->GetLength()) {
        field_14->field_5C = (field_14->field_5C | 128);
        field_14->field_30->field_18 = p0->field_40;
    }
    UnkStruct_003856D0_7 * t = field_14;
    t->field_68 = p0->field_0;
    t->field_6C = p0->field_4;
    t->field_70 = p0->field_8;
    field_18 = 0;
    _rwaSPU2VoiceSetPan(field_14, 0.0f);
    ((UnkStruct_003856D0_11 *)field_14->field_30)->field_0 = 2;
}
