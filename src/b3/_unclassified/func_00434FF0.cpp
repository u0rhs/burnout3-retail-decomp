// func_00434FF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/GtMath.h"

#include "b3/classes/UnkStruct_D_004E0924.h"
#include "b3/classes/UnkStruct_D_01E8EB50.h"
#include "b3/classes/UnkStruct_D_01E8EB54.h"
#include "b3/classes/UnkStruct_D_01E8EBD4.h"
#include "b3/classes/UnkStruct_D_01E8EBDE.h"
#include "b3/classes/UnkStruct_D_01E8EC30.h"

struct UnkStruct_00434FF0;

struct UnkStruct_00434FF0 {
    unsigned char pad_0[0x2C];
    float field_2C;
    float field_30;
    unsigned char pad_34[0x8];
    unsigned char field_3C;
};

extern UnkStruct_D_01E8EBDE D_01E8EBDE;
extern UnkStruct_D_004E0924 D_004E0924;
extern UnkStruct_D_01E8EBD4 D_01E8EBD4;
extern UnkStruct_D_01E8EB54 D_01E8EB54;
extern UnkStruct_D_01E8EB50 D_01E8EB50;
extern UnkStruct_D_01E8EC30 D_01E8EC30;
extern "C" int func_0042BC70(void *);
extern "C" int func_0042B6A0(void *, int);

// 0x00434FF0
extern "C" void func_00434FF0(UnkStruct_00434FF0 * self, float f12 /* passed by every caller, not read here */)
{
    int t0 = D_01E8EBDE.field_0;
    int r0 = func_0042BC70(&D_01E8EC30);
    int r1 = func_0042B6A0(&D_01E8EC30, r0);
    self->field_3C = ((r1 != 0) ^ 1);
    if ((t0 <= -1) || (D_01E8EBD4.field_0 == 1)) {
        float t1 = D_004E0924.field_0;
        self->field_2C = t1;
        self->field_30 = t1;
        return;
    }
    float t2 = D_004E0924.field_0;
    float mm0 = ((D_01E8EB54.field_0[t0].field_0 - 140.0f) / 65.0f);
    self->field_2C = GtMath::Min(GtMath::Max(mm0, t2), 1.0f);
    float mm1 = ((D_01E8EB50.field_0[t0].field_0 - 500.0f) / 2000.0f);
    self->field_30 = GtMath::Min(GtMath::Max(mm1, t2), 1.0f);
}
