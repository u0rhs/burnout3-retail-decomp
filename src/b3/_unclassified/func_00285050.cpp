// func_00285050 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/UnkStruct_D_004E07C8.h"

struct UnkStruct_00285050;

struct UnkStruct_00285050 {
    unsigned char pad_0[0x69];
    unsigned char field_69;
    unsigned char pad_6A[0x12];
    int field_7C;
};

extern UnkStruct_D_004E07C8 D_004E07C8;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00285050
extern "C" void func_00285050(UnkStruct_00285050 * self)
{
    if (self->field_69 != 0) return;
    self->field_69 = 8;
    PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x7C84FFF9FF6B8A00, (const CGtSoundBank*)self->field_7C, D_004E07C8.field_0, 1.0f, 0, 0.0f);
}
