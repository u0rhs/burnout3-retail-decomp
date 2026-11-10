// B3SoundManager.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3SoundManager.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Sound, [L] Revenge (SLUS_212.42) GameSource/Sound/B4SoundManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundManager.h"
#include "b3/classes/CGtSoundManager.h"
#include "b3/classes/EB3SpeakerConfig.h"
#include "b3/classes/UnkStruct_D_004E1B9C.h"
#include "b3/classes/UnkStruct__grMasterPitchScalar.h"

struct UnkStruct_0028B220;
struct UnkStruct_0028B220_3;
struct UnkStruct_0028B220_a1;

struct UnkStruct_0028B220_a1 {
    unsigned char field_0[0x33];
    signed char field_33;
    signed char field_34;
    signed char field_35;
    unsigned char pad_36[0x3];
    signed char field_39;
};

struct UnkStruct_0028B220_3 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x58];
};

struct UnkStruct_0028B220 {
    unsigned char pad_0[0x2ED0];
    char field_2ED0[1];  // [G] length unknown
    unsigned char pad_2ED1[0x2377];
    char field_5248[1];  // [G] length unknown
    unsigned char pad_5249[0x1FCB];
    unsigned char field_7214;
};

extern UnkStruct__grMasterPitchScalar _grMasterPitchScalar;
extern UnkStruct_D_004E1B9C D_004E1B9C;
extern "C" void SetSpeakerConfig__15CB3SoundManagerF16EB3SpeakerConfig(void *, EB3SpeakerConfig);  // CB3SoundManager::SetSpeakerConfig(EB3SpeakerConfig)
extern "C" void func_0027A900(void *, float);
extern "C" float func_003F8890(void *, float);
extern "C" void func_003F8870(void *, int);
extern "C" void func_003FBB50(void *, int, UnkStruct_0028B220_3 *);
extern "C" void func_003FBAA0(void *, int, UnkStruct_0028B220_3 *, unsigned char);

// CB3SoundManager::GetSpeakerConfig() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundManager.cpp.
// 0x0028ADC0
int CB3SoundManager::GetSpeakerConfig()
{
    return field_720C;
}

// CB3SoundManager::SetMasterPitchScalar(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundManager.cpp.
// 0x0028AE30
void CB3SoundManager::SetMasterPitchScalar(float p0)
{
    _grMasterPitchScalar.field_0 = p0;
}

// func_0028AEB0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0028AEB0
extern "C" void func_0028AEB0(CGtSoundManager *self)
{
    self->StopAll();
}

// func_0028B220 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0028B220
extern "C" void func_0028B220(UnkStruct_0028B220 * self, UnkStruct_0028B220_a1 * p0)
{
    UnkStruct_0028B220_3 local;  // [G] the frame's one local (size: up to the frame top)
    float t1 = (float)p0->field_34 * D_004E1B9C.field_0;
    func_0027A900(self->field_2ED0, t1);
    self->field_7214 = (unsigned char)(255.0f * t1);
    func_003F8890(self->field_5248, (float)p0->field_35 * D_004E1B9C.field_0);
    SetSpeakerConfig__15CB3SoundManagerF16EB3SpeakerConfig(self, (EB3SpeakerConfig)p0->field_33);
    if (p0->field_39 != 0) {
        func_003F8870(self->field_5248, 1);
    } else {
        func_003F8870(self->field_5248, 0);
    }
    char * q = self->field_5248;
    func_003FBB50(q, 0, &local);
    for (int i = 0; i < local.field_4; i++) {
        func_003FBAA0(q, i, &local, p0->field_0[i]);
    }
}
