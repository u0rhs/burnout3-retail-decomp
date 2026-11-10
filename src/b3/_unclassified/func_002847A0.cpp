// func_002847A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"

struct UnkStruct_002847A0;

struct UnkStruct_002847A0 {
    unsigned char pad_0[0x74];
    int field_74;
    int field_78;
};

extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x002847A0
extern "C" void func_002847A0(UnkStruct_002847A0 * self, int p0)
{
    int t0 = self->field_74;
    if (p0 < t0 || (p0 == 4 && t0 == 0)) {
        self->field_74 = p0;
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x5370D087C0000000, (const CGtSoundBank*)self->field_78, 1.0f, 1.0f, 0, 0.0f);
    }
}
