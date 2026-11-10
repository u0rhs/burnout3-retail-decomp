// func_00284400 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/UnkStruct_D_004E0784.h"

struct UnkStruct_00284400;

struct UnkStruct_00284400 {
    unsigned char pad_0[0x50];
    int field_50;
    unsigned char pad_54[0x24];
    int field_78;
};

extern UnkStruct_D_004E0784 D_004E0784;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00284400
extern "C" void func_00284400(UnkStruct_00284400 * self, float f0, float f1)
{
    if (self->field_50 != 0) return;
    if (f1 < 2.0f) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xB9A33E7654300000, (const CGtSoundBank*)self->field_78, f0, f1, 1, D_004E0784.field_0);
    } else {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xB9A33E7654300000, (const CGtSoundBank*)self->field_78, f0, f1, 1, 0.0f);
    }
    self->field_50 = 5;
}
