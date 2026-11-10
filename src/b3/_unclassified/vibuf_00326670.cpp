// viBufBeginPut -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> vibuf.c.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_c0.h"

extern "C" void WaitSema(int);
extern "C" void SignalSema(int);

// 0x00326670
extern "C" void viBufBeginPut(UnkStruct_c0 *b, int *p1, int *p2, int *p3, int *p4)
{
    WaitSema(b->field_40);
    int f14 = b->field_14;
    int f10 = b->field_10;
    int fC = b->field_C;
    int f18 = b->field_18;
    int hi = fC + f10 << 16;
    int off = (hi + f14) % f18;
    int space = ((b->field_8 - 2) - f10 << 16) - f14;
    if (f18 - off >= space) {
        *p1 = b->field_0 + off;
        *p2 = space;
        *p3 = 0;
        *p4 = 0;
    } else {
        *p1 = b->field_0 + off;
        *p2 = b->field_18 - off;
        *p3 = b->field_0;
        *p4 = space - (b->field_18 - off);
    }
    SignalSema(b->field_40);
}
