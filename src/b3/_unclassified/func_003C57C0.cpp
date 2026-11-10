// func_003C57C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E8F090.h"
#include "b3/classes/UnkStruct_D_01ECDA00.h"
#include "b3/classes/UnkStruct_D_01ECDAC1.h"
#include "b3/classes/UnkStruct_D_01ECDAC2.h"
#include "b3/classes/UnkStruct_D_01ECDAC5.h"
#include "b3/classes/UnkStruct_D_01ECDAC6.h"
#include "b3/classes/UnkStruct_D_01ECDAC7.h"
#include "b3/classes/UnkStruct_D_01ECDAC9.h"

struct UnkStruct_003C57C0;

struct UnkStruct_003C57C0 {
    unsigned char pad_0[0x4D];
    unsigned char field_4D;
};

extern UnkStruct_D_01ECDA00 D_01ECDA00;
extern UnkStruct_D_01ECDAC1 D_01ECDAC1;
extern UnkStruct_D_01ECDAC2 D_01ECDAC2;
extern UnkStruct_D_01ECDAC7 D_01ECDAC7;
extern UnkStruct_D_01ECDAC5 D_01ECDAC5;
extern UnkStruct_D_01ECDAC6 D_01ECDAC6;
extern UnkStruct_D_01ECDAC9 D_01ECDAC9;
extern UnkStruct_D_01E8F090 D_01E8F090;
extern "C" void func_003C58A0(UnkStruct_003C57C0 *, int, int, void *);
extern "C" int func_00451F70(void *);
extern "C" int func_004516B0(void *);

// 0x003C57C0
extern "C" int func_003C57C0(UnkStruct_003C57C0 * self, int p0, void *p1_)
{
    int p1 = (int)p1_;
    func_003C58A0(self, D_01ECDA00.field_0, p0, (void *)(p1));
    if (D_01ECDAC1.field_0 != 0) {
        func_00451F70(&D_01E8F090);
        if (D_01ECDAC2.field_0 == 0) {
            self->field_4D = 1;
        }
    } else {
        if (D_01ECDAC7.field_0 != 0) {
            func_004516B0(&D_01E8F090);
        } else {
            if (D_01ECDAC5.field_0 != 0) {
                if (D_01ECDAC6.field_0 != 0) {
                    if (D_01ECDAC9.field_0 == 0) {
                        func_004516B0(&D_01E8F090);
                    }
                }
            }
        }
    }
    return 1;
}
