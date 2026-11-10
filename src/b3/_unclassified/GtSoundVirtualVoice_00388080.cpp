// CGtSoundVirtualVoice::Update(float,float,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (RealVoice twin on 003884D0 shapes: inl1 reuse, VV_SETR macros, flag reload via const pun in the 4-arm else (FAKEMATCH-ish [G] pun)).

// CGtSoundVirtualVoice::Update(const CGtSoundVoiceParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (Written on Start's shape: IsPlaying body as a static inline, setter macros, CGtSoundUtils::Clamp, *(const RwV3d *) copies against CSE; volume scale read before pitch scale (FPR order)).

// CGtSoundVirtualVoice::Update(const CGtSoundVoiceParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundVoiceParams;

class CGtSoundVirtualVoice;
class CGtSoundVoice;
class CGtSoundWave;
struct CGtSoundVoiceParams;
struct UnkStruct_00387A90_6;
struct UnkStruct_00387A90_e0;
struct UnkStruct_D_01EA4B00;

class CGtSoundWave {
public:
    float CalcFrequency() const;
    int GetLength() const;

    unsigned char pad_0[0x8];
    int field_8;
};

struct RwV3d {
    float x;
    float y;
    float z;
};

struct CGtSoundVoiceParams {
    RwV3d field_0;
    RwV3d field_C;
    CGtSoundWave * field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0xC];
    float field_34;
    float field_38;
    float field_3C;
    int field_40;
    unsigned char field_44;
    unsigned char field_45;
};

struct UnkStruct_00387A90_e0 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_01EA4B00 {
    UnkStruct_00387A90_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00387A90_6 {
    unsigned char pad_0[0x30];
    RwV3d field_30;
    RwV3d field_3C;
    unsigned char pad_48[0x18];
    void * field_60;
    unsigned char pad_64[0x8];
    int field_6C;
    unsigned char pad_70[0x8];
    float field_78;
    float field_7C;
    float field_80;
    unsigned char pad_84[0x1];
    unsigned char field_85;
    unsigned char pad_86[0x4];
    unsigned char field_8A;
};

class CGtSoundVoice {
public:
    static unsigned char _muMaxActiveCount;
    static float _mrMasterPitch;
    static float _mrMasterVolume;
};

class CGtSoundVirtualVoice {
public:
    void Update(float, float, float, float);
    void UpdatePause();

    unsigned char field_0;
    unsigned char pad_1[0x3];
    UnkStruct_00387A90_6 * field_4;
    CGtSoundWave * field_8;
    int field_C;
    unsigned char pad_10[0x4];
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char field_2E;
    unsigned char field_2F;
    unsigned char field_30;
    unsigned char field_31;
};

extern UnkStruct_D_01EA4B00 D_01EA4B00;

extern "C" void RwaObjHandleSetParamReal(void *, int, int, float);
extern "C" void _rwaVirtualVoiceSetWave(UnkStruct_00387A90_6 *, int);
extern "C" void _rwaVirtualVoiceSetTrigger(UnkStruct_00387A90_6 *, int);
extern "C" void RwaObjHandleSetParamData(void *, int, int, const void *);
extern "C" void RwaObjHandleSetParamUInt32(void *, int, int, int);

// Inlined voice-parameter setters (placeholder names [G]): store the value, then forward it to the RWA object
// handle if there is one. Macros, as retail re-reads the argument expression for the call.
#define VV_SETR(v, f, k, x) { (v)->f = (x); if ((v)->field_60 != 0) RwaObjHandleSetParamReal((v)->field_60, k, 1, (x)); }
#define VV_SETV(v, f, k, x) { (v)->f = *(const RwV3d *)(x); if ((v)->field_60 != 0) RwaObjHandleSetParamData((v)->field_60, k, 1, (x)); }

// [C] name: CGtSoundUtils::Clamp(float,float,float) (research/E_B3O0PCH_symbols.csv, 0x78 bytes out of line there);
// inlined in retail; body [G] from this function's code.
class CGtSoundUtils {
public:
    static float Clamp(float v, float lo, float hi)
    {
        return (v < lo) ? lo : ((v > hi) ? hi : v);
    }
};

// The body of CGtSoundVirtualVoice::IsPlaying() (0x00387980), inlined here [L]; placeholder name [G].
static inline bool func_003884D0_inl1(CGtSoundVirtualVoice * v)
{
    unsigned char t0 = v->field_2C;
    switch (t0) {
    case 0:
    case 1:
    case 3:
        if ((v->field_2F & 64) == 0) {
            return (((v->field_4->field_8A & 2) != 0) != false);
        }
        if ((v->field_2F & 128) != 0) {
            if (((v->field_4->field_8A & 2) != 0) == false) {
                if (t0 == 0) {
                    v->field_0 = 1;
                }
            }
        }
        return (0 < (v->field_2F & 128));
    case 2:
        return (0 < (v->field_2F & 8));
    default:
        return 0;
    }
}

// 0x00388080
void CGtSoundVirtualVoice::Update(float, float, float, float p3)
{
    field_2F = field_2F & 0xDF;
    float dt = p3;
    if (field_2C == 0) {
        UnkStruct_00387A90_e0 * e = &D_01EA4B00.field_0[field_2E];
        float volScale = e->field_4;
        float pitchScale = e->field_0;
        if ((field_2F & 0x10) != 0) {
            VV_SETR(field_4, field_78, 6, field_18 * pitchScale);
        } else {
            VV_SETR(field_4, field_78, 6, pitchScale * (field_18 * CGtSoundVoice::_mrMasterPitch));
        }
        float vol;
        if (field_31 != 0) {
            vol = field_14 * volScale;
        } else {
            vol = volScale * (field_14 * CGtSoundVoice::_mrMasterVolume);
        }
        vol = CGtSoundUtils::Clamp(vol, 0.0f, 1.0f);
        field_4->field_85 = (unsigned char)(255.0f * vol);
        if (field_4->field_60 != 0) {
            RwaObjHandleSetParamReal(field_4->field_60, 7, 1, vol);
        }
        unsigned char fl = field_2F;
        if ((fl & 2) != 0) {
            field_28 = field_28 - dt;
            if (field_28 < 0.0f) {
                _rwaVirtualVoiceSetTrigger(field_4, 1);
                field_2F = field_2F & 0xFD;
                field_2F = field_2F & 0xFE;
            }
        } else if ((field_2F & 4) != 0) {
            float rem = field_1C;
            if (rem > 0.0f) {
                if (((field_4->field_8A & 2) != 0) != false) {
                    unsigned char * pv = &field_4->field_85;
                    float r = ((float)*pv / 255.0f) * (rem / field_20);
                    *pv = (unsigned char)(255.0f * r);
                    if (field_4->field_60 != 0) {
                        RwaObjHandleSetParamReal(field_4->field_60, 7, 1, r);
                    }
                    field_1C = field_1C - dt;
                } else {
                    field_2F = *(const unsigned char *)&field_2F & 0xFB;
                }
            } else {
                _rwaVirtualVoiceSetTrigger(field_4, 0);
                _rwaVirtualVoiceSetWave(field_4, 0);
                field_2C = 0;
                field_28 = 0;
                field_2F = field_2F & 1;
                field_2F = field_2F & 0xFB;
            }
        }
    }
    if (!func_003884D0_inl1(this) && (field_2F & 0x80) != 0) {
        field_2F = field_2F & 0x7F;
    }
    UpdatePause();
}
