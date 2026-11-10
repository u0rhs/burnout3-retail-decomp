// func_003BA8B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0064D37C.h"

struct UnkStruct_003BA8B0;

struct UnkStruct_003BA8B0 {
    unsigned char pad_0[0x44];
    signed char field_44[1];  // [G] element count unknown
};

extern UnkStruct_D_0064D37C D_0064D37C;

// 0x003BA8B0
extern "C" int func_003BA8B0(UnkStruct_003BA8B0 * self, int p0)
{
    int t0 = D_0064D37C.field_0;
    for (int i = 0; (i < t0); i++) {
        if (self->field_44[i] == p0) {
            return i;
        }
    }
    return 0;
}
