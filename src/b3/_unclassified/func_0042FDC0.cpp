// func_0042FDC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051AEC0.h"
#include "b3/classes/UnkStruct_D_0064EA70.h"
#include "b3/classes/UnkStruct_D_00651240.h"

struct UnkStruct_0042FDC0;

struct UnkStruct_0042FDC0 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x4];
    int field_1C;
    int field_20;
    unsigned char pad_24[0xBB];
    unsigned char field_DF;
    unsigned char pad_E0[0x1];
    unsigned char field_E1;
    unsigned char field_E2;
};

extern UnkStruct_D_00651240 D_00651240;
extern UnkStruct_D_0064EA70 D_0064EA70;
extern UnkStruct_D_0051AEC0 D_0051AEC0;
extern "C" void func_0013C910(void *, int, unsigned char);

// 0x0042FDC0
extern "C" void func_0042FDC0(UnkStruct_0042FDC0 * self)
{
    self->field_1C = 13;
    self->field_20 = 14;
    self->field_14 = 2501;
    short t0 = D_00651240.field_0;
    short t1 = D_0064EA70.field_0;
    if (t1 >= t0) {
        if (t0 < t1) {
            self->field_E2 = 1;
            self->field_DF = 12;
        } else {
            self->field_E1 = 1;
            self->field_E2 = 1;
            self->field_DF = 10;
        }
    } else {
        self->field_E1 = 1;
        self->field_DF = 11;
    }
    func_0013C910(&D_0051AEC0, 0, self->field_E1);
    func_0013C910(&D_0051AEC0, 1, self->field_E2);
}
