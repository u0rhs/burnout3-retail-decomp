// func_003A70B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E88D40.h"

struct UnkStruct_003A70B0;
struct UnkStruct_003A70B0_e0;

struct UnkStruct_003A70B0_e0 {
    int field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_003A70B0 {
    unsigned char pad_0[0xB0];
    UnkStruct_003A70B0_e0 field_B0[1];  // [G] element count unknown
};

extern UnkStruct_D_01E88D40 D_01E88D40;

// 0x003A70B0
extern "C" int func_003A70B0(UnkStruct_003A70B0 * self)
{
    return self->field_B0[D_01E88D40.field_0].field_0;
}
