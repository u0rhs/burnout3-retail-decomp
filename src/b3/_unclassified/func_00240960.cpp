// func_00240960 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtNetworkPlayerManager.h"

struct UnkStruct_00240960;

struct UnkStruct_00240960 {
    unsigned char pad_0[0x40];
    CGtNetworkPlayerManager * field_40;
};

extern "C" void func_00240DD0(UnkStruct_00240960 *, void *);

// 0x00240960
extern "C" void func_00240960(UnkStruct_00240960 * self)
{
    CGtNetworkPlayerManager * t0 = self->field_40;
    int r0 = t0->GetHostPlayerID();
    int r1 = t0->GetPlayerByID(r0);
    func_00240DD0(self, (void *)(r1));
}
