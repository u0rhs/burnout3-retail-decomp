// func_00396670 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E3D390.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"

struct UnkStruct_00396670;
struct UnkStruct_00396670_2;
struct UnkStruct_00396670_4;
struct UnkStruct_func_003962A0;

struct UnkStruct_00396670_2 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_00396670_4 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_func_003962A0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00396670 {
    unsigned char pad_0[0x4];
    unsigned char field_4[0x459];
    unsigned char field_45D;
};

extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern UnkStruct_func_003962A0 func_003962A0;
extern "C" int func_0032B2C0(void *, int, int);
extern "C" int BanBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, void *, void *, UnkStruct_00396670 *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_0035FBC0(void *, void *);
extern "C" void func_00396E50(UnkStruct_00396670 *);

// 0x00396670
extern "C" void func_00396670(UnkStruct_00396670 * self)
{
    int r = func_0032B2C0(&D_01E898E8, 0, 1);
    if (r == 4) {
        if (BanBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_4, &func_003962A0, self) == 0) {
            func_0035FBC0(&D_01E3D390, self->field_4);
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 0, 55, 15, 0);
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        } else {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 57, 0, 0);
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
            func_0031ECD0(&D_01E89800, 4, 3);
        }
    } else if (r == 5) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        self->field_45D = 3;
    } else if (r == 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        if (D_01E8954E.field_0 != 0) {
            ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
        }
        func_00396E50(self);
    }
}
