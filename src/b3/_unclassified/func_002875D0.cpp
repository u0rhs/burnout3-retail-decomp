// func_002875D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/CGtSoundVirtualVoice.h"
#include "b3/classes/CGtSoundVoiceParams.h"

struct UnkStruct_002875D0;
struct UnkStruct_002875D0_0;
struct UnkStruct_002875D0_2;
struct UnkStruct_002875D0_e1;

struct UnkStruct_002875D0_0 {
    unsigned char pad_0[0x18];
    int field_18;
    unsigned char pad_1C[0x1C];
    float field_38;
    unsigned char pad_3C[0x8];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};

struct UnkStruct_002875D0_2 {
    unsigned char pad_0[0x3C];
    UnkStruct_002875D0_e1 * field_3C;
    unsigned char field_40;
};

struct UnkStruct_002875D0_e1 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_002875D0 {
    unsigned char pad_0[0x28];
    int field_28;
    UnkStruct_002875D0_2 * field_2C;
    unsigned char pad_30[0x27];
    unsigned char field_57;
    unsigned char pad_58[0x8];
    CGtSoundVirtualVoice * field_60[1];  // [G] element count unknown
};

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const

// 0x002875D0
extern "C" void func_002875D0(UnkStruct_002875D0 * self)
{
    UnkStruct_002875D0_0 local;  // [G] the frame's one local (size: up to the frame top)
    Construct__19CGtSoundVoiceParamsFv(&local);
    local.field_45 = 1;
    local.field_44 = 6;
    local.field_38 = 150.0f;
    for (int i = 0; ((unsigned int)i < (unsigned int)self->field_2C->field_40); i++) {
        int r1 = FindWave__12CGtSoundBankCFRCUlb((void *)self->field_28, &self->field_2C->field_3C[i], 0);
        local.field_18 = r1;
        self->field_60[i]->Start((const CGtSoundVoiceParams*)&local);
    }
    self->field_57 = 1;
}
