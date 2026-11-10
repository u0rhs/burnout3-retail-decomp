// Prepare__25CB3OfflineBurningLapLogicFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OfflineStageLogic.h"
#include "b3/classes/UnkStruct_D_00516E40.h"
#include "b3/classes/UnkStruct_D_005179F0.h"

struct UnkStruct_0038BA50;

struct UnkStruct_0038BA50 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char pad_5[0x3B];
    int field_40;
    unsigned char pad_44[0x4];
    float field_48;
};

extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_005179F0 D_005179F0;
extern "C" int Prepare__20CB3OfflineStageLogicFv(void *);  // CB3OfflineStageLogic::Prepare()

// 0x0038BA50
extern "C" int Prepare__25CB3OfflineBurningLapLogicFv(UnkStruct_0038BA50 * self)
{
    int r0 = Prepare__20CB3OfflineStageLogicFv(self);
    if (r0 == 0) {
        return 0;
    }
    self->field_4 = 0;
    self->field_40 = 1;
    ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(15, 0);
    ((UnkStruct_D_005179F0 *)&D_005179F0)->vfunc_14(15, 0);
    self->field_48 = -1.0f;
    return 1;
}
