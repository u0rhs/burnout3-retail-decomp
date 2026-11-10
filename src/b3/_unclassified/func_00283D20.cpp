// func_00283D20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"

struct UnkStruct_00283D20;

struct UnkStruct_00283D20 {
    unsigned char pad_0[0x68];
    unsigned char field_68;
    unsigned char field_69;
    unsigned char pad_6A[0x12];
    int field_7C;
};

extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00283D20
extern "C" void func_00283D20(UnkStruct_00283D20 * self)
{
    if (self->field_69 == 0) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xA4F3B88CE6900000, (const CGtSoundBank*)self->field_7C, 1.0f, 1.0f, 0, 0.0f);
        self->field_69 = 8;
        self->field_68 = 16;
    }
}
