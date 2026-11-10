// func_0038B280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3RaceCarPhysics.h"
#include "b3/classes/CB3StageLogic.h"

struct UnkStruct_0038B280_a1;

struct UnkStruct_0038B280_a1 {
    unsigned char pad_0[0x13F4];
    int field_13F4;
};

extern "C" void HandleCrashReset__8CB3ScoreFv(void *);

// 0x0038B280
extern "C" void func_0038B280(CB3StageLogic * self, UnkStruct_0038B280_a1 * p0)
{
    self->OnPostCrashReset((CB3RaceCarPhysics*)p0);
    HandleCrashReset__8CB3ScoreFv((void *)((p0->field_13F4 + 4288)));
}
