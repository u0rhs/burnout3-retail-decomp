// func_00454630 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E774E0.h"
#include "b3/classes/UnkStruct_D_01E7A888.h"

struct UnkStruct_00454630;

struct UnkStruct_00454630 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
};

extern UnkStruct_D_01E774E0 D_01E774E0;
extern UnkStruct_D_01E7A888 D_01E7A888;
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" void func_003FA600(void *, int);

// 0x00454630
extern "C" void func_00454630(UnkStruct_00454630 * self)
{
    Stop__14CGtSoundStreamFv((void *)(self->field_4));
    Release__14CGtSoundStreamFv((void *)(self->field_4));
    FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, (void *)(self->field_4));
    self->field_4 = 0;
    Stop__14CGtSoundStreamFv((void *)(self->field_8));
    Release__14CGtSoundStreamFv((void *)(self->field_8));
    FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, (void *)(self->field_8));
    self->field_8 = 0;
    func_003FA600(&D_01E7A888, 1);
}
