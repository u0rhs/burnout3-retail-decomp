// func_00432A50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_00432A50;

struct UnkStruct_00432A50 {
    unsigned char pad_0[0x6C4];
    int field_6C4;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern "C" void func_004328C0(UnkStruct_00432A50 *);
extern "C" void func_00432560(UnkStruct_00432A50 *);

// 0x00432A50
extern "C" void func_00432A50(UnkStruct_00432A50 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    int t0 = self->field_6C4;
    switch (t0) {
    case 0:
        func_004328C0(self);
        break;
    case 1:
        func_00432560(self);
        break;
    }
}
