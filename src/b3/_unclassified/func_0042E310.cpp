// func_0042E310 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8980A.h"
#include "b3/classes/UnkStruct_D_01E8F360.h"
#include "b3/classes/UnkStruct_D_01E8F36A.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"

struct UnkStruct_0042E310;
struct UnkStruct_0042E310_5;
struct UnkStruct_0042E310_6;

struct UnkStruct_0042E310_5 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_0042E310_6 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_0042E310 {
    unsigned char pad_0[0x8];
    int field_8;
};

extern UnkStruct_D_01E8F36A D_01E8F36A;
extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern "C" void func_00449F10(void *, int, int, int, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void OnMemCardPageExit__24CB3MemCardControllerBaseFv(void *);

// 0x0042E310
extern "C" void func_0042E310(UnkStruct_0042E310 * self, int p0)
{
    switch (self->field_8) {
    case 0:
        switch (p0) {
        case 47:
            self->field_8 = 3;
            if (D_01E8F36A.field_0 != 0) {
                ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
            } else {
            }
            switch (self->field_8) {
            case 0:
            case 1:
                func_00449F10(&D_01E8F360, 0, 2262, 1, 0, 0);
                if (D_01E8980A.field_0 != 0) {
                    ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
                }
                break;
            case 2:
                func_00449F10(&D_01E8F360, 4, 2253, 0, 0, 0);
                if (D_01E8980A.field_0 != 0) {
                    ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
                }
                func_0031ECD0(&D_01E89800, 264, 3);
                break;
            }
            OnMemCardPageExit__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        case 46:
        case 55:
        case 58:
            self->field_8 = 2;
            if (D_01E8F36A.field_0 != 0) {
                ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
            } else {
            }
            switch (self->field_8) {
            case 0:
            case 1:
                func_00449F10(&D_01E8F360, 0, 2262, 1, 0, 0);
                if (D_01E8980A.field_0 != 0) {
                    ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
                }
                break;
            case 2:
                func_00449F10(&D_01E8F360, 4, 2253, 0, 0, 0);
                if (D_01E8980A.field_0 != 0) {
                    ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
                }
                func_0031ECD0(&D_01E89800, 264, 3);
                break;
            }
            OnMemCardPageExit__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        }
    break;
    }
}
