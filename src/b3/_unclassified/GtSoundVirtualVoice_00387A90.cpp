// CGtSoundVirtualVoice::Start(const CGtSoundVoiceParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (Rewritten: field_60 as void* (keeps the handle calls inline), CGtSoundUtils::Clamp as a ternary inline, setters as macros (argument re-read), element pointer into D_01EA4B00 with field_4 read first, RwV3d copies, *(const RwV3d *)& copy to stop CSE of the tested x).

// CGtSoundVirtualVoice::Start(const CGtSoundVoiceParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
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
    static int _munUniquePlayIdCounter;
    static float _mrMasterPitch;
    static float _mrMasterVolume;
};

class CGtSoundVirtualVoice {
public:
    void Start(const CGtSoundVoiceParams* p0);

    unsigned char pad_0[0x4];
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
    unsigned char pad_2D[0x1];
    unsigned char field_2E;
    unsigned char field_2F;
    unsigned char field_30;
    unsigned char field_31;
};

extern UnkStruct_D_01EA4B00 D_01EA4B00;

extern "C" void _rwaVirtualVoiceSetWave(UnkStruct_00387A90_6 *, int, int);
extern "C" void RwaObjHandleSetParamInt32(void *, int, int, int);
extern "C" void RwaObjHandleSetParamReal(void *, int, int, float);
extern "C" void RwaObjHandleSetParamData(void *, int, int, const void *);
extern "C" void RwaObjHandleSetParamUInt32(void *, int, int, int);
extern "C" void _rwaVirtualVoiceSetTrigger(UnkStruct_00387A90_6 *, int);

// Inlined voice-parameter setters (placeholder names [G]): store the value, then forward it to the RWA object
// handle if there is one. Macros, as retail re-reads the argument expression for the call.
#define VV_SETR(v, f, k, x) { (v)->f = (x); if ((v)->field_60 != 0) RwaObjHandleSetParamReal((v)->field_60, k, 1, (x)); }
#define VV_SETV(v, f, k, x) { (v)->f = *(x); if ((v)->field_60 != 0) RwaObjHandleSetParamData((v)->field_60, k, 1, (x)); }

// Same setter for the position (placeholder [G]).
static inline void func_00387A90_inl2(CGtSoundVirtualVoice * self, const RwV3d * x)
{
    self->field_4->field_3C = *x;
    if (self->field_4->field_60 != 0) RwaObjHandleSetParamData(self->field_4->field_60, 1, 1, x);
}

// [C] name: CGtSoundUtils::Clamp(float,float,float) (research/E_B3O0PCH_symbols.csv, 0x78 bytes out of line there);
// inlined in retail; body [G] from this function's code.
class CGtSoundUtils {
public:
    static float Clamp(float v, float lo, float hi)
    {
        return (v < lo) ? lo : ((v > hi) ? hi : v);
    }
};

// 0x00387A90
void CGtSoundVirtualVoice::Start(const CGtSoundVoiceParams* p)
{
    field_2F |= 0x80;
    field_2F &= ~0x10;
    field_2F &= ~0x4;
    int id = CGtSoundVoice::_munUniquePlayIdCounter;
    CGtSoundVoice::_munUniquePlayIdCounter = id + 1;
    field_C = id;
    field_2E = p->field_44;
    field_8 = p->field_18;
    _rwaVirtualVoiceSetWave(field_4, p->field_18->field_8, id);
    UnkStruct_00387A90_e0 * e = &D_01EA4B00.field_0[field_2E];
    float volScale = e->field_4;
    float pitchScale = e->field_0;
    int loop = p->field_45;
    if (loop != 0) {
        field_4->field_8A |= 4;
    } else {
        field_4->field_8A &= ~4;
    }
    if (field_4->field_60 != 0) {
        RwaObjHandleSetParamInt32(field_4->field_60, 10, 1, loop);
    }
    if (loop != 0) {
        field_2F |= 0x40;
    } else {
        field_2F &= ~0x40;
    }
    if (p->field_24 < 0.0f) {
        field_18 = field_8->CalcFrequency();
    } else {
        field_18 = p->field_24;
    }
    float pitch = pitchScale * (field_18 * CGtSoundVoice::_mrMasterPitch);
    if (pitch <= 1000.0f) {
        pitch = 1000.0f;
    }
    VV_SETR(field_4, field_78, 6, pitch);
    if (p->field_1C < 0.0f) {
        field_14 = 0.0f;
    } else {
        field_14 = p->field_1C;
        field_14 = CGtSoundUtils::Clamp(field_14, 0.0f, 1.0f);
    }
    float vol;
    if (field_31 != 0) {
        vol = CGtSoundUtils::Clamp(field_14 * volScale, 0.0f, 1.0f);
    } else {
        vol = CGtSoundUtils::Clamp(volScale * (field_14 * CGtSoundVoice::_mrMasterVolume), 0.0f, 1.0f);
    }
    field_4->field_85 = (unsigned char)(255.0f * vol);
    if (field_4->field_60 != 0) {
        RwaObjHandleSetParamReal(field_4->field_60, 7, 1, vol);
    }
    if (p->field_3C == 1.1754944e-38f) {
        VV_SETR(field_4, field_7C, 4, 10.0f);
    } else {
        VV_SETR(field_4, field_7C, 4, p->field_3C);
    }
    if (p->field_38 == 1.1754944e-38f) {
        VV_SETR(field_4, field_80, 5, 50.0f);
        field_24 = 50.0f;
    } else {
        VV_SETR(field_4, field_80, 5, p->field_38);
        field_24 = p->field_38;
    }
    if (p->field_C.x == 1.1754944e-38f && p->field_C.y == 1.1754944e-38f && p->field_C.z == 1.1754944e-38f) {
        RwV3d zero;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        func_00387A90_inl2(this, &zero);
    } else {
        // the const-cast copy stops MWCC reusing the x loaded for the test above (retail reloads it)
        field_4->field_3C = *(const RwV3d *)&p->field_C;
        if (field_4->field_60 != 0) RwaObjHandleSetParamData(field_4->field_60, 1, 1, &p->field_C);
    }
    VV_SETV(field_4, field_30, 0, &p->field_0);
    int pos = p->field_40;
    if (pos != -1) {
        if ((unsigned int)pos < (unsigned int)p->field_18->GetLength()) {
            field_4->field_6C = pos;
            if (field_4->field_60 != 0) {
                RwaObjHandleSetParamUInt32(field_4->field_60, 9, 1, p->field_40);
            }
        }
    }
    if (p->field_34 <= 0.0f) {
        field_28 = 0.0f;
        field_2F &= ~0x2;
    } else {
        field_28 = p->field_34;
        field_2F |= 0x2;
        field_2F |= 0x1;
    }
    field_2C = 0;
    if ((field_2F & 2) == 0) {
        _rwaVirtualVoiceSetTrigger(field_4, 1);
    }
    field_30 = 0;
}
