// OnCrashStart__24CB3OfflineTeamCrashLogicFP17CB3RaceCarPhysicsP17CB3CrashStartInfo -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0064D388.h"
#include "b3/classes/UnkStruct_D_0064D38C.h"

struct UnkStruct_003C3050_a1;

struct UnkStruct_003C3050_a1 {
    unsigned char pad_0[0x13F4];
    int field_13F4;
};

extern UnkStruct_D_0064D388 D_0064D388;
extern UnkStruct_D_0064D38C D_0064D38C;
extern "C" void HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo(void *, void *);

// 0x003C3050
extern "C" void OnCrashStart__24CB3OfflineTeamCrashLogicFP17CB3RaceCarPhysicsP17CB3CrashStartInfo(int n0, UnkStruct_003C3050_a1 * p0, int p1)
{
    HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo((void *)((p0->field_13F4 + 4288)), (void *)(p1));
    int t0 = D_0064D388.field_0;
    if (t0 == p0->field_13F4) {
        HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo((void *)((D_0064D38C.field_0 + 4288)), (void *)(0));
    } else {
        HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo((void *)((t0 + 4288)), (void *)(0));
    }
}
