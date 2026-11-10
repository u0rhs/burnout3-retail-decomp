// func_00284DA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/UnkStruct_D_004E06B8.h"

struct UnkStruct_00284DA0;

struct UnkStruct_00284DA0 {
    unsigned char pad_0[0x69];
    unsigned char field_69;
    unsigned char pad_6A[0x12];
    int field_7C;
};

extern UnkStruct_D_004E06B8 D_004E06B8;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00284DA0
extern "C" void func_00284DA0(UnkStruct_00284DA0 * self)
{
    if (self->field_69 == 0) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x565A446C20BEF600, (const CGtSoundBank*)self->field_7C, D_004E06B8.field_0, 1.0f, 0, 0.0f);
        self->field_69 = 60;
    }
}
