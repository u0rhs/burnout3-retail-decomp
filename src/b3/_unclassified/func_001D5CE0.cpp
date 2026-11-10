// Hand-written; the lifter refused it (slot: by-value parameter declared const CGtV4d (the entry lq hoist, a104 pattern)).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
struct UnkStruct_001D5CE0_item {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
    unsigned char pad_20[0x28];
    void *field_48;
};
struct UnkStruct_001D5CE0_owner {
    unsigned char pad_0[0x40];
    unsigned char field_40[16];
};
extern "C" void *AddLink__11CGtFreeListFv(void *);
// 0x001D5CE0
extern "C" CGtV2d *func_001D5CE0(UnkStruct_001D5CE0_owner *self, const CGtV2d &p0, const CGtV2d &p1, const CGtV4d p2)   // const by-value CGtV4d: retail hoists its lq to the entry (a104 pattern)
{
    UnkStruct_001D5CE0_item *l = (UnkStruct_001D5CE0_item *)((char *)AddLink__11CGtFreeListFv(self->field_40) + 8);
    l->field_48 = self;
    l->field_0 = p0;
    l->field_8 = p1;
    l->field_10 = p2;
    return &l->field_0;
}
