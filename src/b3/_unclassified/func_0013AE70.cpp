// func_0013AE70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HardCodedVehicleList.h"

struct UnkStruct_0013AE70;

struct UnkStruct_0013AE70 {
    unsigned char pad_0[0x330];
    CB3HardCodedVehicleList * field_330;
};

// 0x0013AE70
extern "C" int func_0013AE70(UnkStruct_0013AE70 * self, int p0)
{
    CB3HardCodedVehicleList * t0 = self->field_330;
    if ((int)t0 == -1) {
        return 0;
    }
    int r0 = t0->GetRaceVehicleGtID(p0);
    return r0;
}
