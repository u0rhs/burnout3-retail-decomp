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
    void Update(const CGtSoundVoiceParams* p0);
    void UpdatePause();

    unsigned char field_0;
    unsigned char pad_1[0x3];
    UnkStruct_00387A90_6 * field_4;
    CGtSoundWave * field_8;
    int field_C;
    unsigned char pad_10[0x4];
    float field_14;
    float field_18;
    unsigned char pad_1C[0x8];
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

// 0x003884D0
void CGtSoundVirtualVoice::Update(const CGtSoundVoiceParams* p)
{
    UnkStruct_00387A90_e0 * e = &D_01EA4B00.field_0[field_2E];
    float volScale = e->field_4;
    float pitchScale = e->field_0;
    if (func_003884D0_inl1(this)) {
        if (field_30 < CGtSoundVoice::_muMaxActiveCount) {
            field_30++;
        }
        float minDist = p->field_3C;
        if (minDist != 1.1754944e-38f) {
            VV_SETR(field_4, field_7C, 4, minDist);
        }
        float maxDist = p->field_38;
        if (maxDist != 1.1754944e-38f) {
            VV_SETR(field_4, field_80, 5, maxDist);
            field_24 = p->field_38;
        }
        if (!(p->field_24 < 0.0f)) {
            field_18 = p->field_24;
        }
        if ((field_2F & 0x10) != 0) {
            VV_SETR(field_4, field_78, 6, field_18 * pitchScale);
        } else {
            VV_SETR(field_4, field_78, 6, pitchScale * (field_18 * CGtSoundVoice::_mrMasterPitch));
        }
        if (!(p->field_1C < 0.0f)) {
            field_14 = p->field_1C;
            field_14 = CGtSoundUtils::Clamp(field_14, 0.0f, 1.0f);
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
        if (!(p->field_C.x == 1.1754944e-38f && p->field_C.y == 1.1754944e-38f && p->field_C.z == 1.1754944e-38f)) {
            VV_SETV(field_4, field_3C, 1, &p->field_C);
        }
        if (!(p->field_0.x == 1.1754944e-38f && p->field_0.y == 1.1754944e-38f && p->field_0.z == 1.1754944e-38f)) {
            VV_SETV(field_4, field_30, 0, &p->field_0);
        }
        int pos = p->field_40;
        if (pos != -1) {
            if ((unsigned int)pos < (unsigned int)p->field_18->GetLength()) {
                field_4->field_6C = pos;
                if (field_4->field_60 != 0) {
                    RwaObjHandleSetParamUInt32(field_4->field_60, 9, 1, p->field_40);
                }
            }
        }
        field_0 = 0;
    } else if ((field_2F & 0x80) != 0) {
        field_0 = 1;
        field_2F &= ~0x80;
    }
    UpdatePause();
    field_2F |= 0x20;
}
