// func_003941A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OfflineStageLogic.h"
#include "b3/classes/UnkStruct_D_00516E40.h"
#include "b3/classes/UnkStruct_D_005179F0.h"
#include "b3/classes/UnkStruct_D_00665E52.h"
#include "b3/classes/UnkStruct_D_00665EA0.h"
#include "b3/classes/UnkStruct_D_00665EA1.h"
#include "b3/classes/UnkStruct_D_00665F2B.h"

struct UnkStruct_003941A0;

struct UnkStruct_003941A0 {
    unsigned char pad_0[0x40];
    int field_40;
    float field_44;
    float field_48;
    short field_4C;
    short field_4E;
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
    unsigned char field_53;
};

extern UnkStruct_D_00665E52 D_00665E52;
extern UnkStruct_D_00665EA0 D_00665EA0;
extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_005179F0 D_005179F0;
extern UnkStruct_D_00665EA1 D_00665EA1;
extern UnkStruct_D_00665F2B D_00665F2B;
extern "C" int Prepare__20CB3OfflineStageLogicFv(void *);  // CB3OfflineStageLogic::Prepare()

// 0x003941A0
extern "C" int func_003941A0(UnkStruct_003941A0 * self)
{
    int r0 = Prepare__20CB3OfflineStageLogicFv(self);
    if (r0 == 0) {
        return 0;
    }
    self->field_51 = 0;
    if (D_00665E52.field_0 == 0) {
        D_00665EA0.field_0 = 1;
        ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(15, 0);
        ((UnkStruct_D_005179F0 *)&D_005179F0)->vfunc_14(15, 0);
        self->field_40 = 1;
        self->field_50 = 0;
    }
    D_00665EA1.field_0 = 0;
    self->field_4C = 0;
    self->field_4E = 0;
    self->field_44 = -1.0f;
    self->field_48 = -1.0f;
    self->field_52 = 0;
    D_00665F2B.field_0 = 0;
    self->field_53 = 0;
    return 1;
}
