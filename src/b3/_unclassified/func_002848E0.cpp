// func_002848E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"

struct UnkStruct_002848E0;

struct UnkStruct_002848E0 {
    unsigned char pad_0[0x60];
    int field_60;
    unsigned char pad_64[0x14];
    int field_78;
};

extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x002848E0
extern "C" void func_002848E0(UnkStruct_002848E0 * self, int p0, float f0)
{
    if (p0 <= 0) {
        return;
    }
    if (p0 < self->field_60) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xBD69B91E81C00000, (const CGtSoundBank*)self->field_78, f0, 1.0f, 0, 0.0f);
        self->field_60 = p0;
    }
}
