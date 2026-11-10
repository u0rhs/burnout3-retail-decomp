// func_003C2B80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E90198.h"
#include "b3/classes/UnkStruct_D_01E901F0.h"

struct UnkStruct_003C2B80;

struct UnkStruct_003C2B80 {
    unsigned char pad_0[0x8];
    unsigned long field_8[1];  // [G] element count unknown
    unsigned char pad_10[0x20];
    unsigned long field_30[1];  // [G] element count unknown
    unsigned char pad_38[0x20];
    int field_58[1];  // [G] element count unknown
    unsigned char pad_5C[0x1C];
    int field_78[1];  // [G] element count unknown
    unsigned char pad_7C[0x1C];
    unsigned char field_98[1];  // [G] element count unknown
    unsigned char pad_99[0x7];
    unsigned char field_A0[1];  // [G] element count unknown
    unsigned char pad_A1[0x7];
    unsigned char field_A8[1];  // [G] element count unknown
    unsigned char pad_A9[0x7];
    unsigned char field_B0;
    unsigned char field_B1;
};

extern UnkStruct_D_01E901F0 D_01E901F0;
extern UnkStruct_D_01E90198 D_01E90198;
extern "C" void func_003C2960(UnkStruct_003C2B80 *);

// 0x003C2B80
extern "C" void func_003C2B80(UnkStruct_003C2B80 * self)
{
    self->field_B0 = 0;
    self->field_B1 = 0;
    for (int i = 0; (i < 8); i++) {
        self->field_58[i] = 0;
        self->field_78[i] = 0;
        self->field_98[i] = 0;
        self->field_A0[i] = i;
        self->field_A8[i] = i;
    }
    unsigned char t0 = self->field_B0;
    unsigned long t1 = self->field_8[t0];
    D_01E901F0.field_0 = t1;
    D_01E90198.field_0 = self->field_30[self->field_B0];
    func_003C2960(self);
}
