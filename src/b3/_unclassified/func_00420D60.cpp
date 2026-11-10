// StartFormat__24CB3MemCardControllerBaseFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01ECD950.h"
#include "b3/classes/UnkStruct_D_01ECD954.h"
#include "b3/classes/UnkStruct_D_01ECD960.h"
#include "b3/classes/UnkStruct_D_01ECD964.h"

struct UnkStruct_00420D60_5;
struct UnkStruct_00420D60_6;

struct UnkStruct_00420D60_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00420D60_6 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

extern UnkStruct_D_01ECD954 D_01ECD954;
extern UnkStruct_D_01ECD950 D_01ECD950;
extern UnkStruct_D_01ECD960 D_01ECD960;
extern UnkStruct_D_01ECD964 D_01ECD964;
extern "C" UnkStruct_00420D60_5 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x00420D60
extern "C" void StartFormat__24CB3MemCardControllerBaseFv(void *a0 /* passed by every caller, not read here */)
{
    UnkStruct_00420D60_5 * r0 = GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D1226778721623);
    if (D_01ECD954.field_0 == r0) return;
    ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_18(r0, 0);
    void * t0 = D_01ECD954.field_0;
    D_01ECD954.field_0 = (void *)r0;
    UnkStruct_003FF1D0_3 * t1 = D_01ECD960.field_0;
    if (t1 != 0) {
        D_01ECD964.field_0 = t1->field_20;
        if (r0 != 0) {
            r0->field_8 = t1->field_20;
        }
    }
    ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_1C(t0, 0);
}
