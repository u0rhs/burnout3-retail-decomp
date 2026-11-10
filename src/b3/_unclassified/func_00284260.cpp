// func_00284260 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtSoundVirtualVoice.h"

struct UnkStruct_00284260;

struct UnkStruct_00284260 {
    unsigned char pad_0[0x4];
    CGtSoundVirtualVoice * field_4;
};

// 0x00284260
extern "C" void func_00284260(UnkStruct_00284260 * self)
{
    CGtSoundVirtualVoice * t0 = self->field_4;
    if (t0 == 0) return;
    t0->Stop();
    self->field_4 = 0;
}
