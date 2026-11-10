// CB3SoundCrashManager::PropImpact(bool,EB3PropType,GtMathPs2::CGtV3d,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (lit4 externs as literals (0.1f/0.8f/0.7f), field_520 as CGtRandom + const float k random idiom, entry loads lim/hiT/lo/hi then id, scoped opt_repositioncode off [G] for the shared exit).


#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/_unclassified/GtRandom.h"
using GtMathPs2::CGtV3d;
enum EB3PropType {};
struct UnkStruct_0027F5E0_p {
    float field_0; float field_4; float field_8; unsigned char pad_C[0xC];
    int field_18; float field_1C; float field_20; float field_24;
    unsigned char pad_28[0x10]; float field_38; unsigned char pad_3C[8];
    unsigned char field_44; unsigned char pad_45[0xB];
};
struct UnkStruct_0027F5E0_e { unsigned long field_0; float field_8; float field_C; float field_10; float field_14; };
struct UnkStruct_D_01E75648 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E75648 D_01E75648;
extern UnkStruct_D_01E7569C D_01E7569C;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" int FindWave__19CGtSoundBankManagerCFRCUlb(void *, const unsigned long *, bool);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" void *TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" void func_003872C0(void *, int, float, float, float, float, float, float);
static inline void func_0027F5E0_inl1(UnkStruct_0027F5E0_p *p, CGtV3d v) { p->field_0 = ((float *)&v)[0]; p->field_4 = ((float *)&v)[1]; p->field_8 = ((float *)&v)[2]; }
class CB3SoundCrashManager {
public:
    void PropImpact(bool, EB3PropType, CGtV3d, float);
    unsigned char pad_0[0x190];
    UnkStruct_0027F5E0_e field_190[37];
    unsigned char pad_508[0xC];
    signed char field_514[12];
    CGtRandom field_520;
    unsigned char pad_528[0x288];
    float field_7B0;
};
#pragma push
#pragma opt_repositioncode off  // [G] scoped (N182)
// 0x0027F5E0
void CB3SoundCrashManager::PropImpact(bool b, EB3PropType type, CGtV3d p0, float f)
{
    CGtV3d pos = p0;
    UnkStruct_0027F5E0_p p;
    Construct__19CGtSoundVoiceParamsFv(&p);
    func_0027F5E0_inl1(&p, pos);
    int off = type * 24; UnkStruct_0027F5E0_e *e = (UnkStruct_0027F5E0_e *)(off + (int)this + 0x190);
    float lim = e->field_8;
    float hiT = e->field_C;
    float lo = e->field_10;
    float hi = e->field_14;
    unsigned long id = e->field_0;
    if (f < lim) return;
    signed char *flag = (signed char *)((int)type + (int)this + 0x514);
    if (*flag != 0) return;
    *flag = 4;
    float t = GtMath::Min(GtMath::Max((f - lim) / (hiT - lim), 0.0f), 1.0f);
    float *pv = &p.field_1C;
    *pv = lo + t * (hi - lo);
    const float k = 2.3283064e-10f;
    *pv = 0.0f + *pv - *pv * (field_7B0 * (k * (float)field_520.Random()));
    if (b) goto half;
tail:
    p.field_20 = 1.0f;
    int *pw;
    pw = &p.field_18;
    *pw = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &id, true);
    int w = *pw;
    if (w == 0) return;
    {
        float *pf = &p.field_24;
        *pf = CalcFrequency__12CGtSoundWaveCFv((void *)(w));
        const float k2 = 2.3283064e-10f;
        *pf *= (1.0f + 0.1f * (2.0f * (k2 * (float)field_520.Random()))) - 0.1f;
        p.field_44 = 3;
        p.field_38 = 50.0f;
        void *v = TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p);
        if (v != 0) {
            func_003872C0(v, 0, 0.8f, 0.8f, 1.0f, 0.7f, 1.0f, 1.0f);
        }
    }
    return;
half:
    *pv = *pv / 2.0f;
    goto tail;
}


#pragma pop
