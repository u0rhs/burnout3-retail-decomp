// func_0013C940 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_00665E52.h"

struct UnkStruct_0013C940;
struct UnkStruct_0013C940_1;

struct UnkStruct_0013C940_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual int vfunc_2C();
};

struct UnkStruct_0013C940 {
    unsigned char pad_0[0x1B4];
    UnkStruct_0013C940_1 * field_1B4;
};

extern UnkStruct_D_00665E52 D_00665E52;

// 0x0013C940
extern "C" int func_0013C940(UnkStruct_0013C940 * self)
{
    int r0 = self->field_1B4->vfunc_2C();
    if (r0 == 0) {
        return 0;
    }
    D_00665E52.field_0 = 1;
    return 1;
}
