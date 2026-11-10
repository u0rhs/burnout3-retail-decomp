// func_00459550 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3BuddyDisplayComponent.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"

extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern CB3BuddyDisplayComponent D_01E8D670;
extern "C" void func_0032D080(void *, int, int, int, int);

// 0x00459550
extern "C" void func_00459550(int n0, int p0, int p1)
{
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    if (n0 == 0) {
        if (p1 == 6) {
            func_0032D080(&D_01E898E8, 2, 208, 0, 0);
        } else {
            func_0032D080(&D_01E898E8, 2, 207, 0, 0);
        }
    } else {
        func_0032D080(&D_01E898E8, 2, 28, 0, 0);
    }
    D_01E8D670.MailSent(p0);
}
