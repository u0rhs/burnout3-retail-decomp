// func_00284D30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CGtSoundBank.h"

struct UnkStruct_00284D30;

struct UnkStruct_00284D30 {
    unsigned char pad_0[0x69];
    unsigned char field_69;
    unsigned char pad_6A[0x12];
    int field_7C;
};

extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

// 0x00284D30
extern "C" void func_00284D30(UnkStruct_00284D30 * self)
{
    if (self->field_69 == 0) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x565A446C12F79E00, (const CGtSoundBank*)self->field_7C, 0.5f, 1.0f, 0, 0.0f);
        self->field_69 = 60;
    }
}
