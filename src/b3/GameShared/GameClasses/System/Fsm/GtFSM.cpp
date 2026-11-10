// GtFSM.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 6 function(s) named in research/retail_names.csv -> GtFSM.cpp.
// Area: src/b3/GameShared/GameClasses/System/Fsm, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Fsm/GtFSM.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtFSM.h"
#include "b3/classes/CGtState.h"

struct UnkStruct_00217690;
struct UnkStruct_00217690_1;
struct UnkStruct_00217690_e0;

struct UnkStruct_00217690_1 {
    unsigned long field_0;
    int field_8;
};
struct UnkStruct_00217690_e0 {
    unsigned char pad_0[0x1];
};
struct UnkStruct_00217690 {
    UnkStruct_00217690_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_1[0xB];
    int field_C;
};
struct UnkStruct_002177C0_s {
    unsigned long field_0;
    float field_8;
    // vptr at +0xC [G]
    virtual void vfunc_8(int, int, int, int);
};
struct UnkStruct_002177C0_e {
    unsigned long field_0;
    int field_8;
    int pad_C;
};
struct UnkStruct_002177C0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    UnkStruct_002177C0_e *field_C;
    void *field_10;
    float field_14;
};
struct UnkStruct_00217750_s {
    unsigned long field_0;
    float field_8;
    virtual void vfunc_8(int, int, int, int);
};
struct UnkStruct_00217750_e {
    unsigned long field_0;
    int field_8;
    int pad_C;
};
struct UnkStruct_00217750 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    UnkStruct_00217750_e *field_C;
};

// CGtFSM::StateEnter(CGtState*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFSM.cpp.
// 0x00217610
void CGtFSM::StateEnter(CGtState* p0, void* p1)
{
    UnkStruct_00217610_1 * t0 = field_4;
    if (t0 == 0) return;
    t0->vfunc_8(3, field_8, p0, p1);
}

// CGtFSM::StateLeave(CGtState*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFSM.cpp.
// 0x00217650
void CGtFSM::StateLeave(CGtState* p0, void* p1)
{
    UnkStruct_00217610_1 * t0 = field_4;
    if (t0 == 0) return;
    t0->vfunc_8(2, field_8, p0, p1);
}

// GetStateFromID__6CGtFSMFUl -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00217690
extern "C" void * GetStateFromID__6CGtFSMFUl(UnkStruct_00217690 * self, unsigned long p0)
{
    UnkStruct_00217690_1 * m0 = (UnkStruct_00217690_1 *)self->field_C;
    while (m0->field_0 != 0) {
        if (m0->field_0 == p0) {
            return &self->field_0[m0->field_8];
        }
        m0 = (UnkStruct_00217690_1 *)((char *)m0 + 0x10);
    }
    return 0;
}

// CGtFSM::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFSM.cpp.
// 0x00217710
void CGtFSM::Update()
{
    UnkStruct_00217610_1 * t0 = field_4;
    if (t0 == 0) return;
    t0->vfunc_8(4, field_8, 0, 0);
}

// CGtFSM::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFSM.cpp.
// 0x00217750
extern "C" void Destruct__6CGtFSMFv(UnkStruct_00217750 *self)
{
    UnkStruct_00217750_e *e = self->field_C;
    while (e->field_0 != 0) {
        UnkStruct_00217750_s *s = (UnkStruct_00217750_s *)((char *)self + e->field_8);
        s->vfunc_8(1, self->field_8, 0, 0);
        e = (UnkStruct_00217750_e *)((char *)e + 0x10);
    }
}

// CGtFSM::Construct(void*,const CGtStateOffset*,CGtTimer*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFSM.cpp.
// 0x002177C0
extern "C" void Construct__6CGtFSMFPvPC14CGtStateOffsetP8CGtTimer(UnkStruct_002177C0 *self, void *p0_, UnkStruct_002177C0_e *p1, void *p2)
{
    int p0 = (int)p0_;
    self->field_8 = p0;
    self->field_C = (UnkStruct_002177C0_e *)p1;
    self->field_4 = 0;
    self->field_10 = p2;
    self->field_14 = -1.0f;
    UnkStruct_002177C0_e *e = self->field_C;
    while (e->field_0 != 0) {
        UnkStruct_002177C0_s *s = (UnkStruct_002177C0_s *)((char *)self + e->field_8);
        s->field_0 = e->field_0;
        s->field_8 = -1.0f;
        s->vfunc_8(0, self->field_8, 0, 0);
        e = (UnkStruct_002177C0_e *)((char *)e + 0x10);
    }
}
