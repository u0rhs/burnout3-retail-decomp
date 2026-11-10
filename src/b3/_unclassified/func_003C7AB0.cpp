// func_003C7AB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E959B8.h"
#include "b3/classes/UnkStruct_D_01ECDAC1.h"
#include "b3/classes/UnkStruct_D_01ECDAC6.h"

struct UnkStruct_003C7AB0;

struct UnkStruct_003C7AB0 {
    unsigned char pad_0[0x14];
    unsigned char field_14;
};

extern UnkStruct_D_01ECDAC1 D_01ECDAC1;
extern UnkStruct_D_01ECDAC6 D_01ECDAC6;
extern UnkStruct_D_01E959B8 D_01E959B8;
extern "C" int func_0044A380(void *, int, int);

// 0x003C7AB0
extern "C" void func_003C7AB0(UnkStruct_003C7AB0 * self, int p0)
{
    self->field_14 = 1;
    int v4;
    switch (p0) {
    case 8:
    default:
        if (D_01ECDAC1.field_0 != 0) {
            v4 = 2865;
        } else {
            v4 = 2867;
        }
        break;
    case 7:
        v4 = 337;
        break;
    case 11:
        if (D_01ECDAC1.field_0 != 0) {
            v4 = 2866;
        } else if (D_01ECDAC6.field_0 != 0) {
            v4 = 332;
        } else {
            v4 = 333;
        }
        break;
    }
    func_0044A380(&D_01E959B8, p0, v4);
}
