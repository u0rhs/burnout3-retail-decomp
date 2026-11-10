// CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SoundHUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C form with extra float param f2; p assigned in each find arm).

class CGtSoundVoiceParams;
class CGtSoundBank;
class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);
    int TriggerRealVoice(const CGtSoundVoiceParams*);
    unsigned char pad_0[0x10];
};
struct UnkStruct_PHS_0 {
    unsigned char pad_0[0x18];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0xC];
    float field_34;
    unsigned char pad_38[0xC];
    unsigned char field_44;
    unsigned char pad_45[0xB];
};
extern CGtSoundVoiceManager D_01E7569C;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, void *, bool);
extern "C" int FindWave__19CGtSoundBankManagerCFRCUlb(void *, void *, bool);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" void IgnoreGlobalPitch__20CGtSoundVirtualVoiceFv(void *);
extern "C" void IgnoreGlobalPitch__17CGtSoundRealVoiceFv(void *);
extern char D_01E75648[0x10];
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *self, unsigned long id, const CGtSoundBank *bank, bool b, float f0, float f1, float f2)
{
    UnkStruct_PHS_0 local;
    Construct__19CGtSoundVoiceParamsFv(&local);
    int * p;
    if (bank != 0) {
        p = &local.field_18;
        *p = FindWave__12CGtSoundBankCFRCUlb((void *)bank, &id, 0);
    } else {
        p = &local.field_18;
        *p = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &id, 0);
    }
    if (*p != 0) {
        local.field_1C = f0;
        local.field_24 = f1 * CalcFrequency__12CGtSoundWaveCFv((void *)*p);
        local.field_44 = 1;
        local.field_34 = f2;
        if (b) {
            void *r = (void *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&local);
            if (r != 0) {
                IgnoreGlobalPitch__20CGtSoundVirtualVoiceFv(r);
            }
        } else {
            void *r = (void *)D_01E7569C.TriggerRealVoice((const CGtSoundVoiceParams*)&local);
            if (r != 0) {
                IgnoreGlobalPitch__17CGtSoundRealVoiceFv(r);
            }
        }
    }
}
