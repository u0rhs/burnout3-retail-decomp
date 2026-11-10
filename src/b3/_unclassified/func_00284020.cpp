// func_00284020 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/UnkStruct_D_004E0784.h"

struct UnkStruct_00284020;

struct UnkStruct_00284020 {
    unsigned char pad_0[0x13];
    unsigned char field_13;
    unsigned char pad_14[0x68];
    int field_7C;
};

extern UnkStruct_D_004E0784 D_004E0784;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00284020
extern "C" void func_00284020(UnkStruct_00284020 * self)
{
    if (self->field_13 != 0) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xA8C5D19D149A0000, (const CGtSoundBank*)self->field_7C, 1.0f, 1.0f, 1, D_004E0784.field_0);
    } else {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xA8C5D19D1AB48000, (const CGtSoundBank*)self->field_7C, 1.0f, 1.0f, 1, D_004E0784.field_0);
    }
    self->field_13 = ((self->field_13 != 0) ^ 1);
}
