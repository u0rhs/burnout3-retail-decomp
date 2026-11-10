// func_00455670 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_00455670;

struct UnkStruct_00455670 {
    unsigned char pad_0[0x650];
    int field_650;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern "C" void func_004553E0(UnkStruct_00455670 *);
extern "C" void func_00455170(UnkStruct_00455670 *);

// 0x00455670
extern "C" void func_00455670(UnkStruct_00455670 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    int t0 = self->field_650;
    switch (t0) {
    case 0:
        func_004553E0(self);
        break;
    case 1:
        func_00455170(self);
        break;
    }
}
