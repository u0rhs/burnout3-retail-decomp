// CGtFSM -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTFSM_H
#define B3_CLASSES_CGTFSM_H

#include "b3/GtMath.h"

class CGtFSM;
class CGtState;
class CGtStateOffset;
class CGtTimer;
struct UnkStruct_00217610_1;

struct UnkStruct_00217610_1 {
    unsigned char pad_0[0xC];
    // vptr at +0xC: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8(int, int, CGtState*, void*);
};

class CGtFSM {
public:
    void ApplyEvent(unsigned int, void*);
    void Construct(void*, const CGtStateOffset*, CGtTimer*);
    void StateEnter(CGtState* p0, void* p1);
    void StateLeave(CGtState* p0, void* p1);
    void Update();

    unsigned char pad_0[0x4];
    UnkStruct_00217610_1 * field_4;
    int field_8;
    unsigned char pad_C[0x80C];
    int field_818;
};

#endif
