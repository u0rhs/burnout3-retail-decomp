// UpdateCameras__24CB3OnlineSingleRaceLogicFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004F50C0.h"
#include "b3/classes/UnkStruct_D_004F6061.h"
#include "b3/classes/UnkStruct_D_00516E40.h"
#include "b3/classes/UnkStruct_D_01E91C3E.h"

struct UnkStruct_0038A5D0;
struct UnkStruct_0038A5D0_4;

struct UnkStruct_0038A5D0_4 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_0038A5D0 {
    unsigned char pad_0[0x60];
    int field_60;
};

extern UnkStruct_D_01E91C3E D_01E91C3E;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern "C" float func_0012F240(void *);
extern "C" float func_0012F330(void *);

// 0x0038A5D0
extern "C" void UpdateCameras__24CB3OnlineSingleRaceLogicFv(UnkStruct_0038A5D0 * self)
{
    if (D_01E91C3E.field_0 != 0) {
        return;
    }
    if (self->field_60 == 6) {
        char * p = (char *)&D_004F50C0.field_0[D_004F6061.field_0] + 0xD48;
        if (!func_0012F240(p)) {
            if (!func_0012F330(p)) {
                return;
            }
            ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(7, 0);
        } else {
            ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(8, 0);
        }
    }
}
