// CB3SoundTurboModel::Update(const CB3RaceCar*,const CB3SoundRaceCarAttribs*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTurboModel.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near33: lit4 9.549296379f; Interpolate inline + float& ref + mfc1 bit test (func_00288480 form); smoothstep static inline (args loaded before body); clamp ternary 'x < lo ? lo : (x > hi ? hi : x)'; (int)((1.0f - f21) * n) before the pos copy).

typedef unsigned int u_long128 __attribute__((mode(TI)));
class CGtSoundVoiceParams;
class CGtSoundVirtualVoice {
public:
    void ForgetMe(float);
    bool IsPlaying();
    void Update(const CGtSoundVoiceParams *);
    unsigned char pad_0[0xC];
    int field_C;
};
class CGtSoundVoiceManager {
public:
    CGtSoundVirtualVoice *TriggerVoice(const CGtSoundVoiceParams *);
    unsigned char pad_0[0x10];
};
struct UnkStruct_0028FB00_P { unsigned char pad_0[0x1400]; float field_1400; unsigned char pad_1404[0x98]; float field_149C; unsigned char pad_14A0[4]; int field_14A4; };
struct UnkStruct_0028FB00_E { UnkStruct_0028FB00_P *field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_D_0055EFEC { UnkStruct_0028FB00_E field_0[1]; };
struct CB3RaceCar { unsigned char pad_0[0x30]; u_long128 field_30; unsigned char pad_40[0x196C]; signed char field_19AC; };
struct CB3SoundRaceCarAttribs {
    int field_0; float field_4; float field_8; float field_C; float field_10; float field_14; float field_18; float field_1C; float field_20;
};
struct UnkStruct_0028FB00_vp {
    float field_0; float field_4; float field_8;
    unsigned char pad_C[0xC];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x20];
    int field_40;
    unsigned char pad_44[0xC];
};
struct UnkStruct_D_004E0790 { float field_0; };
extern UnkStruct_D_0055EFEC D_0055EFEC;
extern CGtSoundVoiceManager D_01E7569C;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
class CB3SoundTurboModel {
public:
    int field_0;
    int field_4;
    float field_8;
    float field_C;
    CGtSoundVirtualVoice *field_10;
    CGtSoundVirtualVoice *field_14;
    void Update(const CB3RaceCar *, const CB3SoundRaceCarAttribs *);
};
// [L] GtMath::Interpolate(float,float,float) (E map 0x14CCF0), the body as func_001D1130_inl7.
static inline float func_0028FB20_inl1(float a, float b, float t) { float d = b - a; return a + t * d; }
// [G] inlined helper (name unknown): smoothstep of x between lo and hi.
static inline float func_0028FB20_inl2(float x, float lo, float hi)
{
    float r;
    if (x < lo) {
        r = 0.0f;
    } else if (!(x < hi)) {
        r = 1.0f;
    } else {
        float t = (x - lo) / (hi - lo);
        r = (3.0f - 2.0f * t) * (t * t);
    }
    return r;
}
// 0x0028FB20
void CB3SoundTurboModel::Update(const CB3RaceCar *car, const CB3SoundRaceCarAttribs *at)
{
    UnkStruct_0028FB00_vp paramsA;
    UnkStruct_0028FB00_vp paramsB;
    u_long128 posA;
    u_long128 posB;
    float f20;
    float f21;
    UnkStruct_0028FB00_P *p = D_0055EFEC.field_0[car->field_19AC].field_0;
    if (p->field_1400 <= 0.0f || p->field_14A4 != 0) {
        f20 = 0.0f;
    } else {
        f20 = 9.549296379f * p->field_149C;
        if (field_14 != 0 && (int)field_10 == field_14->field_C) {
            field_14->ForgetMe(0.125f);
            field_14 = 0;
            field_10 = 0;
        }
    }
    f20 = f20 - field_8;
    if (f20 < at->field_C) {
        float hi = at->field_C;
        float b = at->field_10;
        float f0 = f20 < b ? b : (f20 > hi ? hi : f20);
        f21 = field_C * (f0 / b);
        f20 = f0;
        if (field_4 != 0) {
            if (field_14 == 0 || (int)field_10 != field_14->field_C || !field_14->IsPlaying()) {
                Construct__19CGtSoundVoiceParamsFv(&paramsA);
                float & v = paramsA.field_1C;
                v = func_0028FB20_inl1(at->field_1C, at->field_20, f21);
                unsigned int bits;
                // float bits moved straight from the FPR (retail mfc1), as in func_00288480 (proven)
                asm("mfc1 %0, %1" : "=r"(bits) : "f"(v));
                if ((bits & 0x7F800000) > 0x37800000) {
                    paramsA.field_40 = (int)((1.0f - f21) * (float)at->field_0);
                    posA = car->field_30;
                    paramsA.field_18 = field_4;
                    paramsA.field_0 = ((float *)&posA)[0];
                    paramsA.field_4 = ((float *)&posA)[1];
                    paramsA.field_8 = ((float *)&posA)[2];
                    field_14 = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams *)&paramsA);
                    if (field_14 != 0) field_10 = (CGtSoundVirtualVoice *)field_14->field_C;
                }
            }
        }
    } else {
        if (f20 < at->field_4) f20 = at->field_4;
        else if (!(f20 < at->field_8)) f20 = at->field_8;
    }
    field_8 = field_8 + f20;
    field_C = func_0028FB20_inl2(field_8, at->field_14, at->field_18);
    if (field_14 != 0 && (int)field_10 == field_14->field_C && field_14->IsPlaying()) {
        Construct__19CGtSoundVoiceParamsFv(&paramsB);
        posB = car->field_30;
        paramsB.field_0 = ((float *)&posB)[0];
        paramsB.field_4 = ((float *)&posB)[1];
        paramsB.field_8 = ((float *)&posB)[2];
        field_14->Update((const CGtSoundVoiceParams *)&paramsB);
    } else {
        field_14 = 0;
        field_10 = 0;
    }
}
