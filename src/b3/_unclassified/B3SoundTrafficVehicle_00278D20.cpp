// CB3SoundTrafficVehicle::StartHorn() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (jtbl switch 4,5 / 1,2,3 first; explicit 0,6-11 cases + default return; CGtV4d t; t = field_B0 (lq/sq)).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00278D20_params {
    float field_0; float field_4; float field_8; unsigned char pad_C[0xC];
    int field_18; int field_1C; unsigned char pad_20[0x18];
    float field_38; unsigned char pad_3C[8];
    unsigned char field_44; unsigned char field_45; unsigned char pad_46[0xA];
};
struct UnkStruct_00278D20 {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x14];
    int field_D4x;
};
struct UnkStruct_00278D20_a {
    unsigned char pad_0[0xD4];
    int field_D4;
    int field_D8;
    unsigned char pad_DC[0xC];
    float field_E8;
    unsigned char pad_EC[0x28];
    unsigned int field_114;
    unsigned char pad_118[8];
    int field_120;
};
struct UnkStruct_D_01E78E50 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E75648 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E78EFC { float field_0; unsigned char pad[0xC]; };
extern UnkStruct_D_01E78E50 D_01E78E50;
extern UnkStruct_D_01E75648 D_01E75648;
extern UnkStruct_D_01E7569C D_01E7569C;
extern UnkStruct_D_01E78EFC D_01E78EFC;
extern "C" bool CanStartHorning__22CB3SoundTrafficManagerFv(void *);
extern "C" unsigned long GetNextHornVariant__22CB3SoundTrafficManagerFb(void *, bool);
extern "C" int FindWave__19CGtSoundBankManagerCFRCUlb(void *, const unsigned long *, bool);
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" int TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" void StartHorn__22CB3SoundTrafficVehicleFv(UnkStruct_00278D20_a *self)
{
    if ((self->field_114 & 8) == 0) return;
    if (self->field_E8 == 0.0f) return;
    if (!CanStartHorning__22CB3SoundTrafficManagerFv(&D_01E78E50)) return;
    unsigned long ida;
    unsigned long idb;
    UnkStruct_00278D20_params p;
    switch (self->field_120) {
    case 4:
    case 5:
        ida = GetNextHornVariant__22CB3SoundTrafficManagerFb(&D_01E78E50, false);
        self->field_D4 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &ida, false);
        break;
    case 1:
    case 2:
    case 3:
        idb = GetNextHornVariant__22CB3SoundTrafficManagerFb(&D_01E78E50, true);
        self->field_D4 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &idb, false);
        break;
    case 0: case 6: case 7: case 8: case 9: case 10: case 11:
    default:
        return;
    }
    Construct__19CGtSoundVoiceParamsFv(&p);
    p.field_18 = self->field_D4;
    p.field_38 = D_01E78EFC.field_0;
    p.field_1C = 0;
    CGtV4d t;
    t = ((UnkStruct_00278D20 *)self)->field_B0;
    p.field_45 = 1;
    p.field_44 = 9;
    p.field_0 = t.f[0];
    p.field_4 = t.f[1];
    p.field_8 = t.f[2];
    self->field_D8 = 0;
    self->field_D4 = self->field_D4;
    int v = TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p);
    *(int *)((char *)self + 0xC8) = v;
}
