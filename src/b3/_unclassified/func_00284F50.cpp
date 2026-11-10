// func_00284F50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"

struct UnkStruct_00284F50;

struct UnkStruct_00284F50 {
    unsigned char pad_0[0x6C];
    unsigned char field_6C;
    unsigned char pad_6D[0xF];
    int field_7C;
};

extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00284F50
extern "C" void func_00284F50(UnkStruct_00284F50 * self)
{
    if (self->field_6C != 0) return;
    self->field_6C = 60;
    PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x8ED9B9DFCF600000, (const CGtSoundBank*)self->field_7C, 0.0f, 1.0f, 0, 0.0f);
}
