// func_00283E70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/UnkStruct_D_004E0E00.h"

struct UnkStruct_00283E70;

struct UnkStruct_00283E70 {
    unsigned char pad_0[0x1];
    unsigned char field_1;
    unsigned char pad_2[0x7A];
    int field_7C;
};

extern UnkStruct_D_004E0E00 D_004E0E00;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00283E70
extern "C" void func_00283E70(UnkStruct_00283E70 * self, int p0)
{
    if ((p0 & 255) != self->field_1) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x5A45A6F028000000, (const CGtSoundBank*)self->field_7C, D_004E0E00.field_0, 1.0f, 0, 0.0f);
        self->field_1 = p0;
    }
}
