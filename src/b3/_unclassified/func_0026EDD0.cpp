// func_0026EDD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004F509C.h"
#include "b3/classes/UnkStruct_D_004F50A0.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E32B08.h"

struct UnkStruct_0026EDD0;
struct UnkStruct_0026EDD0_2;

struct UnkStruct_0026EDD0_2 {
    unsigned char pad_0[0x4F0];
    int field_4F0;
};

struct UnkStruct_0026EDD0 {
    unsigned char pad_0[0xAAB0];
    int field_AAB0;
};

extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" UnkStruct_0026EDD0_2 * func_002366D0(void *, int);
extern "C" int func_0022FBB0(UnkStruct_0026EDD0_2 *);
extern "C" int func_00235BB0(void *, int, float, float);

// 0x0026EDD0
extern "C" void func_0026EDD0(UnkStruct_0026EDD0 * self)
{
    if (self->field_AAB0 == 0) return;
    for (int i = 0; (i < D_01E32B08.field_0); i++) {
        UnkStruct_0026EDD0_2 * r0 = func_002366D0(&D_01E32AE0, i);
        if (r0 != 0) {
            if ((unsigned int)r0->field_4F0 < (unsigned int)2) {
                float t0 = D_004F509C.field_0;
                float t1 = D_004F50A0.field_0;
                int r1 = func_0022FBB0(r0);
                int r2 = func_00235BB0(&D_01E32AE0, r1, t1, t0);
                if (r2 != 0) {
                    if (r2 == 1) {
                        r0->field_4F0 = 2;
                    } else {
                        r0->field_4F0 = 3;
                    }
                }
            }
        }
    }
}
