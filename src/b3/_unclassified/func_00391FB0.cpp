// OnPostCrashReset__19CB3OnlineStageLogicFP17CB3RaceCarPhysics -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3Burn.h"
#include "b3/classes/CB3RaceCarPhysics.h"
#include "b3/classes/CB3StageLogic.h"

struct UnkStruct_00391FB0_1;
struct UnkStruct_00391FB0_a1;

struct UnkStruct_00391FB0_a1 {
    unsigned char pad_0[0x13F4];
    UnkStruct_00391FB0_1 * field_13F4;
};

struct UnkStruct_00391FB0_1 {
    unsigned char pad_0[0x118C];
    CB3Burn field_118C;
};

extern "C" void HandleCrashReset__8CB3ScoreFv(void *);

// 0x00391FB0
extern "C" void OnPostCrashReset__19CB3OnlineStageLogicFP17CB3RaceCarPhysics(CB3StageLogic * self, UnkStruct_00391FB0_a1 * p0)
{
    self->OnPostCrashReset((CB3RaceCarPhysics*)p0);
    p0->field_13F4->field_118C.SetInfiniteBoost(0);
    p0->field_13F4->field_118C.RemoveSegment();
    HandleCrashReset__8CB3ScoreFv(((char *)p0->field_13F4 + 0x10C0));
}
