// CB3SoundCrashManager::PlayCarAlarm(CB3VehiclePhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (nested ifs for the fall-off tail (b epilogue; ld ra) ; p.pos CGtV3d-like member copy; CGtRandom at 0x520).

#include "b3/GtMathPs2.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;
class CB3VehiclePhysics;
struct UnkStruct_27A920_v3 { float x; float y; float z; };
struct UnkStruct_27A920_params {
    UnkStruct_27A920_v3 field_0; unsigned char pad_C[0xC];
    int field_18; float field_1C; unsigned char pad_20[0x24];
    unsigned char field_44; unsigned char field_45; unsigned char pad_46[0xA];
};
struct UnkStruct_27A920_car { unsigned char pad_0[0x204]; char *field_204; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004BED00 { unsigned long field_0; unsigned long pad; };
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E7569C D_01E7569C;
extern UnkStruct_D_004BED00 D_004BED00;
extern float D_004E0AAC;
extern "C" int func_00131E40(void *);
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" int TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);
class CB3SoundCrashManager {
public:
    void PlayCarAlarm(CB3VehiclePhysics *p0);
    unsigned char pad_0[0x520];
    CGtRandom field_520;
    unsigned char pad_528[0x84C - 0x528];
    int field_84C;
    unsigned char pad_850[0x880 - 0x850];
    void *field_880;
    unsigned char pad_884[0x8EC - 0x884];
    UnkStruct_27A920_v3 field_8EC[4];
    int field_91C[4];
    UnkStruct_27A920_car *field_92C[4];
    unsigned char field_93C;
    unsigned char field_93D;
};
// 0x0027A920
void CB3SoundCrashManager::PlayCarAlarm(CB3VehiclePhysics *p0v)
{
    UnkStruct_27A920_car *p0 = (UnkStruct_27A920_car *)p0v;
    if (func_00131E40(&D_004EE040) == 0) return;
    if (field_93D >= 4) return;
    for (int i = 0; i < 4; i++) {
        if (p0 == field_92C[i]) return;
    }
    UnkStruct_27A920_params p;
    Construct__19CGtSoundVoiceParamsFv(&p);
    p.field_1C = D_004E0AAC;
    p.field_45 = 1;
    CGtV4d t;
    t = *(CGtV4d *)(p0->field_204 + 0x30);
    p.field_0 = *(UnkStruct_27A920_v3 *)&t;
    field_93C = field_93C + 1;
    if ((field_93C % 8) == 0) {
        if (field_93D < 4) {
            if ((field_520.Random() & 1) != 0) {
                p.field_18 = field_84C;
            } else {
                p.field_18 = FindWave__12CGtSoundBankCFRCUlb(field_880, &D_004BED00, true);
            }
            p.field_44 = 3;
            int v = TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p);
            field_91C[field_93D] = v;
            field_8EC[field_93D] = p.field_0;
            field_92C[field_93D] = p0;
            field_93D = field_93D + 1;
        }
    }
}
