// CGt2dFrame::ConstructChild() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dFrameHierarchy.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a80: item at link+8 (cf nonmatching func_001D5CE0), CGtV2d::Set in place + CGtV4d(1,1,1,1)).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
struct UnkStruct_001D5D60_item {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
    unsigned char pad_20[0x28];
    void *field_48;
};
struct UnkStruct_001D5D60 {
    unsigned char pad_0[0x40];
    unsigned char field_40[16];
};
extern "C" void *AddLink__11CGtFreeListFv(void *);
// 0x001D5D60
extern "C" CGtV2d *ConstructChild__10CGt2dFrameFv(UnkStruct_001D5D60 *self)
{
    UnkStruct_001D5D60_item *l = (UnkStruct_001D5D60_item *)((char *)AddLink__11CGtFreeListFv(self->field_40) + 8);
    l->field_48 = self;
    l->field_0.Set(0.0f, 0.0f);
    l->field_8.Set(1.0f, 1.0f);
    l->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
    return &l->field_0;
}
