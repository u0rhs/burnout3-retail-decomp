// CB3OnlineBuddiesMenuPage::_RemoveBuddyCallback(bool,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineBuddiesMenuPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a103: static callback, vfunc_C + func_0032D080 by bool).

#include "b3/classes/UnkStruct_D_01E898E8.h"
extern UnkStruct_D_01E898E8 D_01E898E8;
extern "C" void func_0032D080(void *, int, int, int, int);
struct UnkStruct_0036C6B0_pg {
    unsigned char pad_0[0xCC];
    int field_CC;
    unsigned char pad_D0[0x11D - 0xD0];
    unsigned char field_11D;
    unsigned char pad_11E[0x1];
    unsigned char field_11F;
};
extern "C" void _RemoveBuddyCallback__24CB3OnlineBuddiesMenuPageFbPv(bool p0, void *p1)
{
    UnkStruct_0036C6B0_pg *pg = (UnkStruct_0036C6B0_pg *)p1;
    pg->field_11D = p0;
    pg->field_11F = 1;
    if (pg->field_CC == 10) {
        if (p0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 59, 0, 0);
        } else {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 60, 0, 0);
        }
    }
}
