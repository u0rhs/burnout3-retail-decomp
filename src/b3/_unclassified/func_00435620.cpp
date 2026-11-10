// func_00435620 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E1038.h"
#include "b3/classes/UnkStruct_D_004E1168.h"
#include "b3/classes/UnkStruct_D_004E116C.h"
#include "b3/classes/UnkStruct_D_01ECDD90.h"
#include "b3/classes/UnkStruct_D_01ECDD94.h"
#include "b3/classes/UnkStruct_D_01ECDD98.h"
#include "b3/classes/UnkStruct_D_01ECDD9C.h"

struct UnkStruct_00435620;

struct UnkStruct_00435620 {
    unsigned char pad_0[0xC];
    int field_C[1];  // [G] element count unknown
    unsigned char pad_10[0x4];
    int field_14[1];  // [G] element count unknown
    unsigned char pad_18[0x4];
    int field_1C[1];  // [G] element count unknown
    unsigned char pad_20[0x4];
    float field_24[1];  // [G] element count unknown
    unsigned char pad_28[0x4];
    float field_2C[1];  // [G] element count unknown
};

extern UnkStruct_D_004E1038 D_004E1038;
extern UnkStruct_D_004E1168 D_004E1168;
extern UnkStruct_D_004E116C D_004E116C;
extern UnkStruct_D_01ECDD94 D_01ECDD94;
extern UnkStruct_D_01ECDD9C D_01ECDD9C;
extern UnkStruct_D_01ECDD90 D_01ECDD90;
extern UnkStruct_D_01ECDD98 D_01ECDD98;
extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x00435620
// [C] the three floats are .lit4 literals (0.1f @ 0x4E1038, 0.481f @ 0x4E1168, 0.789f @ 0x4E116C).
extern "C" void func_00435620(UnkStruct_00435620 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 3);
    for (int i = 0; i < 2; i++) {
        self->field_C[i] = 0;
        self->field_14[i] = 0;
        self->field_1C[i] = 0;
        self->field_24[i] = 0.1f;
        self->field_2C[i] = 0.1f;
    }
    D_01ECDD90.field_0 = 0.481f;
    D_01ECDD94.field_0 = 0;
    D_01ECDD98.field_0 = 0.789f;
    D_01ECDD9C.field_0 = 0;
}
