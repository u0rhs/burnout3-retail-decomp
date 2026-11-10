// func_003C5750 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E8F090.h"
#include "b3/classes/UnkStruct_D_01E8F09A.h"
#include "b3/classes/UnkStruct_D_01E8F1C8.h"
#include "b3/classes/UnkStruct_D_01ECDA04.h"

extern UnkStruct_D_01ECDA04 D_01ECDA04;
extern UnkStruct_D_01E8F09A D_01E8F09A;
extern UnkStruct_D_01E8F1C8 D_01E8F1C8;
extern UnkStruct_D_01E8F090 D_01E8F090;
extern "C" void func_003C58A0(void *, int, int, void *);
extern "C" int func_004502A0(void *);
extern "C" void func_003C5BF0(void *, bool);

// 0x003C5750
extern "C" int func_003C5750(void *n0_, int p0, void *p1_)
{
    int n0 = (int)n0_;
    int p1 = (int)p1_;
    func_003C58A0((void *)(n0), D_01ECDA04.field_0, p0, (void *)(p1));
    func_004502A0(&D_01E8F090);
    bool v1;
    if (D_01E8F09A.field_0 != 0) {
        v1 = (0 < D_01E8F1C8.field_0);
    } else {
        v1 = 0;
    }
    func_003C5BF0((void *)(n0), v1);
    return 1;
}
