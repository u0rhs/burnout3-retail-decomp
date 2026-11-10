// func_00283B30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/UnkStruct_D_004E06A8.h"
#include "b3/classes/UnkStruct_D_004E08B0.h"

struct UnkStruct_00283B30;

struct UnkStruct_00283B30 {
    unsigned char pad_0[0x7C];
    int field_7C;
};

extern UnkStruct_D_004E08B0 D_004E08B0;
extern UnkStruct_D_004E06A8 D_004E06A8;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00283B30
extern "C" void func_00283B30(UnkStruct_00283B30 * self, int p0)
{
    if (p0 == 1) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xBC3DD2765F800000, (const CGtSoundBank*)self->field_7C, D_004E08B0.field_0, 1.0f, 0, 0.0f);
    } else {
    }
    if (p0 == 2) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xBC3DD29C85200000, (const CGtSoundBank*)self->field_7C, 0.5f, 1.0f, 0, 0.0f);
    } else {
    }
    if (p0 == 3) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xBC3DD2C2AAC00000, (const CGtSoundBank*)self->field_7C, D_004E06A8.field_0, 1.0f, 0, 0.0f);
    } else {
    }
    if (p0 == 4) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xBC3DD2E8D0600000, (const CGtSoundBank*)self->field_7C, 0.75f, 1.0f, 0, 0.0f);
    }
}
