// GetChallengeUnlockedCount__10CB3ProfileFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_gCalculatedData.h"

extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013AD10
extern "C" int GetChallengeUnlockedCount__10CB3ProfileFv()
{
    return (gCalculatedData.field_30 + gCalculatedData.field_34);
}
