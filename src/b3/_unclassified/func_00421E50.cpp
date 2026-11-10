// func_00421E50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtFSM.h"
#include "b3/classes/CGtStateOffset.h"
#include "b3/classes/CGtTimer.h"

struct UnkStruct_00421E50;
struct UnkStruct_00421E50_1;
struct UnkStruct_00421E50_2;
struct UnkStruct_00421E50_3;

struct UnkStruct_00421E50_1 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_00421E50_2 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00421E50_3 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_00421E50 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_00421E50_2 *, int);
    virtual void vfunc_1C(void *, int);
    void * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_00421E50_1 * field_10;
    float field_14;
};

extern "C" void Construct__6CGtFSMFPvPC14CGtStateOffsetP8CGtTimer(void *, void*, const void *, void *);  // CGtFSM::Construct(void*,const CGtStateOffset*,CGtTimer*)
extern "C" UnkStruct_00421E50_2 * GetStateFromID__6CGtFSMFUl(UnkStruct_00421E50 *, unsigned long);

// 0x00421E50
extern "C" void func_00421E50(UnkStruct_00421E50 * self, void *p0_, void *p1_, void *p2_)
{
    int p0 = (int)p0_;
    int p1 = (int)p1_;
    int p2 = (int)p2_;
    Construct__6CGtFSMFPvPC14CGtStateOffsetP8CGtTimer(self, (void*)p0, (const CGtStateOffset*)p1, (CGtTimer*)p2);
    UnkStruct_00421E50_2 * r1 = GetStateFromID__6CGtFSMFUl(self, 0x93D12267889D607F);
    if (self->field_4 == r1) return;
    self->vfunc_18(r1, 0);
    void * t0 = self->field_4;
    self->field_4 = (void *)r1;
    UnkStruct_00421E50_1 * t1 = self->field_10;
    if (t1 != 0) {
        self->field_14 = t1->field_20;
        if (r1 != 0) {
            r1->field_8 = self->field_10->field_20;
        }
    }
    self->vfunc_1C(t0, 0);
}
