// func_003FA4A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/CGtSoundBankManager.h"

struct UnkStruct_003FA4A0;

struct UnkStruct_003FA4A0 {
    unsigned char pad_0[0x164];
    int field_164;
    int field_168;
    unsigned char pad_16C[0x2C];
    int field_198;
};

extern CGtSoundBankManager D_01E75648;

// 0x003FA4A0
extern "C" bool func_003FA4A0(UnkStruct_003FA4A0 * self)
{
    if (self->field_198 & 16) {
        self->field_198 |= 32;
        return false;
    }
    if ((CGtSoundBank*)self->field_164 != 0) {
        D_01E75648.UnloadBank((CGtSoundBank*)self->field_164);
        self->field_164 = 0;
        self->field_168 = 0;
        self->field_198 &= ~32;
    }
    return true;
}
