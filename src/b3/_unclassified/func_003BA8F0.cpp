// func_003BA8F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_BA8F0.h"
#include "b3/classes/UnkStruct_BA8F0_car.h"
#include "b3/classes/UnkStruct_BA8F0_g.h"
#include "b3/classes/UnkStruct_BA8F0_row.h"
#include "b3/classes/UnkStruct_D_0064D37C.h"

extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_BA8F0_g D_00522660;
extern "C" int func_00155340(int n0);

// 0x003BA8F0
extern "C" void func_003BA8F0(UnkStruct_BA8F0 * self)
{
    signed char a;
    int sb;
    UnkStruct_BA8F0_row * e;
    int n = D_0064D37C.field_0;
    signed char b;
    bool t1;
    int i = 0;
    goto loop0_t;
loop0:
    UnkStruct_BA8F0_car * car = D_00522660.field_12AD28[i];
    int * p = &self->field_14[i];
    self->field_2C[i] = self->field_14[i];
    self->field_4A[i] = self->field_44[i];
    if (car->field_16C0 > 0) {
        *p = *p + func_00155340(car->field_16C0);
    }
    i++;
loop0_t:
    if (i < n) goto loop0;
    bool sorted;
    bool sw;
    do {
        sorted = true;
        int j = 1;
        goto loop1_t;
    loop1:
        e = (UnkStruct_BA8F0_row *)((char *)self + j);
        a = e->field_43;
        int sa = self->field_14[a];
        b = e->field_44;
        sb = self->field_14[b];
        sw = false;
        if (sa == sb) {
            if (D_00522660.field_12AD28[b]->field_1914 == 0) {
                sw = true;
            }
        } else if (sa < sb) {
            sw = true;
        }
        if (sw) {
            e->field_44 = a;
            e->field_43 = b;
            sorted = false;
        }
        ++j;
    loop1_t:
        t1 = n > j;
        if (t1 == 0) {
        } else {
            goto loop1;
        }
    } while (!sorted);
}
