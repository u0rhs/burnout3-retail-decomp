// func_003C5690 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E8F090.h"
#include "b3/classes/UnkStruct_D_01E8F09A.h"
#include "b3/classes/UnkStruct_D_01E8F1C8.h"
#include "b3/classes/UnkStruct_D_01ECDA04.h"
#include "b3/classes/UnkStruct_D_01ECDAC5.h"
#include "b3/classes/UnkStruct_D_01ECDAC7.h"

extern UnkStruct_D_01ECDAC7 D_01ECDAC7;
extern UnkStruct_D_01ECDAC5 D_01ECDAC5;
extern UnkStruct_D_01ECDA04 D_01ECDA04;
extern UnkStruct_D_01E8F09A D_01E8F09A;
extern UnkStruct_D_01E8F1C8 D_01E8F1C8;
extern UnkStruct_D_01E8F090 D_01E8F090;
extern "C" int func_0044FE00(void *);
extern "C" int func_004502A0(void *);
extern "C" void func_003C58A0(void *, int, int, void *);
extern "C" void func_003C5BF0(void *, bool);

// 0x003C5690
extern "C" int func_003C5690(void *n0, int p0, void *p1)
{
    int v4 = 4005;
    if (D_01ECDAC7.field_0 == 0) {
        int v2;
        if (D_01ECDAC5.field_0 != 0) {
            func_0044FE00(&D_01E8F090);
            v2 = 2863;
        } else {
            func_004502A0(&D_01E8F090);
            v2 = D_01ECDA04.field_0;
        }
        v4 = v2;
    }
    func_003C58A0((void *)(n0), v4, p0, (void *)(p1));
    bool v6;
    if (D_01E8F09A.field_0 != 0) {
        v6 = (0 < D_01E8F1C8.field_0);
    } else {
        v6 = 0;
    }
    func_003C5BF0((void *)(n0), v6);
    return 1;
}
