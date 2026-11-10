// func_00283FA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/UnkStruct_D_004E0B14.h"

struct UnkStruct_00283FA0;

struct UnkStruct_00283FA0 {
    unsigned char pad_0[0x69];
    unsigned char field_69;
};

extern UnkStruct_D_004E0B14 D_004E0B14;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00283FA0
extern "C" void func_00283FA0(UnkStruct_00283FA0 * self)
{
    if (self->field_69 == 0) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xB701A7E2A9E00000, 0, 1.0f, 1.5f, 0, D_004E0B14.field_0);
        self->field_69 = 5;
    }
}
