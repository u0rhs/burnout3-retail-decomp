// func_003CBB60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_003CBB60;

struct UnkStruct_003CBB60 {
    unsigned char pad_0[0xB4];
    int field_B4;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern "C" void func_003CB630(UnkStruct_003CBB60 *);
extern "C" void func_003CB420(UnkStruct_003CBB60 *);

// 0x003CBB60
extern "C" void func_003CBB60(UnkStruct_003CBB60 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    int t0 = self->field_B4;
    switch (t0) {
    case 0:
        func_003CB630(self);
        break;
    case 1:
        func_003CB420(self);
        break;
    }
}
