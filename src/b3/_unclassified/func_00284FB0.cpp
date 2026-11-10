// func_00284FB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/UnkStruct_D_004E0C24.h"

struct UnkStruct_00284FB0;

struct UnkStruct_00284FB0 {
    unsigned char pad_0[0x7C];
    int field_7C;
};

extern UnkStruct_D_004E0C24 D_004E0C24;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00284FB0
extern "C" void func_00284FB0(UnkStruct_00284FB0 * self)
{
    PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x733C0C755C900000, (const CGtSoundBank*)self->field_7C, D_004E0C24.field_0, 1.0f, 0, 0.0f);
}
