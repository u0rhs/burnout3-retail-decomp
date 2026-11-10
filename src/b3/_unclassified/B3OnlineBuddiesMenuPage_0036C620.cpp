// CB3OnlineBuddiesMenuPage::_BanBuddyCallback(bool,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineBuddiesMenuPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a103: static callback, vfunc_C + func_0032D080 by bool).

#include "b3/classes/UnkStruct_D_01E898E8.h"
extern UnkStruct_D_01E898E8 D_01E898E8;
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void _BanBuddyCallback__24CB3OnlineBuddiesMenuPageFbPv(bool p0, void *p1)
{
    if (p0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 56, 0, 0);
    } else {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 57, 0, 0);
    }
}
