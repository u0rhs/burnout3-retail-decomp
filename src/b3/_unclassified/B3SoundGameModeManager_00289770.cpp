// CB3SoundGameModeManager::UpdateTakedownPitcher() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (fresh4: from scratch; smoothstep inline x3 (TurboModel shape), >= arms, constant in a float local for madd order).

// CB3SoundGameModeManager::UpdateTakedownPitcher() -- hand-written from scratch (the lifter refused it).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G]
// (instruction widths). [C] _grPitcherAttackTime is the .sdata word at 0x004E1B54 (retail's gp offset -0x6B1C).

class CGtSoundVoiceParams;
class CGtSoundRealVoice {
public:
    bool IsPlaying() const;
    void Update(const CGtSoundVoiceParams *);
    void Stop();
};
class CB3SoundManager {
public:
    void SetMasterPitchScalar(float);
    unsigned char pad_0[0x10];
};
struct UnkStruct_00289770_vp {
    unsigned char pad_0[0x1C];
    float field_1C;
    unsigned char pad_20[8];
    float field_28;
    float field_2C;
    float field_30;
    unsigned char pad_34[0x1C];
};
struct UnkStruct_D_0051BAC4 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BAC4 D_0051BAC4;
extern UnkStruct_D_004F509C D_004F509C;
extern CB3SoundManager D_01E75640;
extern float _grPitcherDecayTime;
extern float _grPitcherAttackTime;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);

class CB3SoundGameModeManager {
public:
    void UpdateTakedownPitcher();
    unsigned char pad_0[0x52C0];
    float field_52C0;
    CGtSoundRealVoice *field_52C4;
};

// [G] inlined helper (name unknown): smoothstep of x between lo and hi (B3SoundTurboModel_0028FB20's shape).
static inline float func_00289770_inl1(float x, float lo, float hi)
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

// 0x00289770
void CB3SoundGameModeManager::UpdateTakedownPitcher()
{
    if (field_52C0 > 0.0f) {
        if (field_52C4 != 0 && field_52C4->IsPlaying()) {
            UnkStruct_00289770_vp params;
            Construct__19CGtSoundVoiceParamsFv(&params);
            float t = field_52C0;
            if (t >= _grPitcherDecayTime) {
                params.field_1C = 1.0f - func_00289770_inl1(t, 2.75f, 3.0f);
            } else {
                params.field_1C = func_00289770_inl1(t, 0.0f, 0.25f);
            }
            params.field_28 = 0.0f;
            params.field_2C = 0.0f;
            params.field_30 = 0.5f;
            field_52C4->Update((const CGtSoundVoiceParams *)&params);
        }
        float x;
        if (field_52C0 >= _grPitcherDecayTime) {
            x = 1.0f - (field_52C0 - _grPitcherDecayTime) / _grPitcherAttackTime;
        } else {
            x = field_52C0 / _grPitcherDecayTime;
        }
        float r = func_00289770_inl1(x, 0.0f, 1.0f);
        float k = -0.99f;
        D_01E75640.SetMasterPitchScalar(1.0f + r * k);
        field_52C0 = field_52C0 - (float)D_0051BAC4.field_0 * D_004F509C.field_0;
    }
    if (field_52C4 != 0 && field_52C4->IsPlaying() && field_52C0 <= 0.0f) {
        field_52C4->Stop();
        field_52C4 = 0;
    }
}
