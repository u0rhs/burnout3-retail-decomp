// GetTimeSinceLastPacketArrived__16CB3NetworkPlayerCFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004F50A0.h"

struct UnkStruct_0023AFE0;

struct UnkStruct_0023AFE0 {
    unsigned char pad_0[0x4EEC];
    float field_4EEC;
};

extern UnkStruct_D_004F50A0 D_004F50A0;

// 0x0023AFE0
extern "C" float GetTimeSinceLastPacketArrived__16CB3NetworkPlayerCFv(UnkStruct_0023AFE0 * self)
{
    return (D_004F50A0.field_0 - self->field_4EEC);
}
