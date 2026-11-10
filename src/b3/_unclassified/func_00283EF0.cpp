// func_00283EF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/UnkStruct_D_004E0B14.h"

struct UnkStruct_00283EF0;

struct UnkStruct_00283EF0 {
    unsigned char pad_0[0x7C];
    int field_7C;
};

extern UnkStruct_D_004E0B14 D_004E0B14;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00283EF0
extern "C" void func_00283EF0(UnkStruct_00283EF0 * self, int a1 /* passed by every caller, not read here */)
{
    PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xA8C02E2F34AC8000, (const CGtSoundBank*)self->field_7C, 1.0f, 1.0f, 0, D_004E0B14.field_0);
}
