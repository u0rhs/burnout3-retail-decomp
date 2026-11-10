// func_00285560 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3SoundGameModeManager.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/EB3RaceCarType.h"

struct UnkStruct_00285560;

struct UnkStruct_00285560 {
    unsigned char pad_0[0x78];
    int field_78;
};

extern CB3SoundGameModeManager D_01E77540;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00285560
extern "C" void func_00285560(UnkStruct_00285560 * self, int p0, int p1)
{
    if (p1 != 0) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x6048D35D03000000, (const CGtSoundBank*)self->field_78, 1.0f, 1.0f, 0, 0.0f);
    } else {
        D_01E77540.TriggerSpotDucker(0.25f);
        if (p0 == 2) {
            PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x940D6B9284900000, (const CGtSoundBank*)self->field_78, 1.0f, 0.94387f, 0, 0.0f);
            PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xB9A33E7654300000, (const CGtSoundBank*)self->field_78, 0.7f, 1.0f, 1, 0.0f);
            return;
        }
        if (p0 == 1) {
            PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x940D6B9284900000, (const CGtSoundBank*)self->field_78, 1.0f, 1.0f, 0, 0.0f);
            PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xB9A33E7654300000, (const CGtSoundBank*)self->field_78, 0.7f, 1.0f, 1, 0.0f);
            return;
        }
        if (p0 == 0) {
            PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x940D6B9378B40000, (const CGtSoundBank*)self->field_78, 1.0f, 1.0f, 0, 0.0f);
            PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xB9A33E7654300000, (const CGtSoundBank*)self->field_78, 0.7f, 1.0f, 1, 0.0f);
            return;
        }
    }
}
