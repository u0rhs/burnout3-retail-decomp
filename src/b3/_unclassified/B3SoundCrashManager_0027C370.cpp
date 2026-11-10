// CB3SoundCrashManager::WheelImpact(bool,GtMathPs2::CGtV3d,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (mwperm: +'static inline float func_0027C370_inl1(float a0) { float t13 = D_004E1358 * (2.0'; 'CGtV3d pos = p0;' -> 'CGtV3d v3 = p0; const float v2 = f; float v1 = v2; float v0 = v1; float t8; v0 ='; 'if (field_8DF != 0) return; if (f < field_680) return; if (f' -> 'if (!((t3 = 0 != field_8DF) || v1 < field_680)) { } else { return; } if (!(1)) {'; 'float vol = field_688 + t * (field_68C - field_688); if (b).

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
struct UnkStruct_0027C3A0_p {
    float field_0; float field_4; float field_8; unsigned char pad_C[0xC];
    int field_18; float field_1C; float field_20; float field_24;
    unsigned char pad_28[0x1C]; unsigned char field_44; unsigned char pad_45[0xB];
};
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
struct UnkStruct_kB3CarPartWheelProp { unsigned long field_0; unsigned char pad_8[8]; };
extern UnkStruct_D_01E7569C D_01E7569C;
extern UnkStruct_kB3CarPartWheelProp kB3CarPartWheelProp;
extern float D_004E1358;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const unsigned long *, bool);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" void *TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
static inline void func_0027C3A0_inl1(UnkStruct_0027C3A0_p *p, CGtV3d v) { p->field_0 = ((float *)&v)[0]; p->field_4 = ((float *)&v)[1]; p->field_8 = ((float *)&v)[2]; }
class CB3SoundCrashManager {
public:
    void WheelImpact(bool, CGtV3d, float);
    unsigned char pad_0[0x520];
    int field_520;
    int field_524;
    unsigned char pad_528[0x158];
    float field_680; float field_684; float field_688; float field_68C; float field_690; float field_694; float field_698; float field_69C;
    unsigned char pad_6A0[0x1E0];
    void *field_880;
    unsigned char pad_884[0x4C];
    signed char field_8D0;
    unsigned char pad_8D1[0xE];
    unsigned char field_8DF;
};
static inline float func_0027C370_inl1(float a0)
{
    float t13 = D_004E1358 * (2.0f * (a0));
    return t13;
}

// N182: `#pragma opt_treetransformation off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_treetransformation off
// 0x0027C370
void CB3SoundCrashManager::WheelImpact(bool b, CGtV3d p0, float f)
{
    CGtV3d v3 = p0;
    const float v2 = f;
    float v1 = v2;
    float v0 = v1;
    float t8;
    v0 = v0;
    CGtV3d pos;
    int t4;
    pos = v3;
    bool t3;
    UnkStruct_0027C3A0_p p;
    if (!((t3 = 0 != field_8DF) || v1 < field_680)) {
    } else {
        return;
    }
    if (!(1)) {
    } else {
        bool t11 = 0 != field_8D0;
        if (t11) {
            return;
        }
    }
    field_8D0 = 5;
    float t = GtMath::Min(GtMath::Max((f - field_680) / (field_684 - field_680), 0.0f), 1.0f);
    float t1 = ((((float)(field_68C + -field_688))) * t);
    float t6 = field_688 + t1;
    t8 = t6;
    v1 = (field_688 + t1);
    if (b) v1 *= field_698; else v1 = field_69C * v1;
    float pitch = (t1 = (field_694 - field_690) * t) - -field_690;
    do {
        float t15 = field_694 + -field_690;
        float t9 = ((t15)) * t;
        if (((field_690 + (t9)) >= (0, D_004E1358))) {
        } else {
            return;
        }
    } while (0);
    Construct__19CGtSoundVoiceParamsFv(&p);
    p.field_20 = 1.0f;
    p.field_1C = v1;
    int *pw = &p.field_18;
    if (1) {
        if (1 == 0) {
        } else {
            if ((&p.field_18) == 0) {
            } else {
            }
            func_0027C3A0_inl1(&p, pos);
        }
    }
    *pw = FindWave__12CGtSoundBankCFRCUlb(field_880, &kB3CarPartWheelProp.field_0, true);
    field_520 = (field_520 << 16) + (field_520 >> 16);
    field_520 += field_524;
    field_524 += field_520;
    const float t10 = (float)(unsigned int)field_520;
    v1 = 2.0f * (t10 * 2.3283064e-10f);
    v1 = v1;
    float t7 = ((((float)D_004E1358) * (v1) + 1.0f)) - D_004E1358;
    pitch *= (t7);
    t = ((float)(1.0f + func_0027C370_inl1(v0)));
    float t12 = CalcFrequency__12CGtSoundWaveCFv((void *)(*(&p.field_18)));
    float t16 = ((float)pitch) * ((float)t12);
    p.field_24 = (t16);
    t4 * field_8DF != 0;
    if (field_8DF == 0) {
        p.field_44 = 3;
        TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p);
    }
}
