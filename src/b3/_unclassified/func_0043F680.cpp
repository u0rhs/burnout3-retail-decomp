// func_0043F680 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuComponentSelectionData.h"
#include "b3/classes/CB3VSelectComponentEntryData.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89522.h"
#include "b3/classes/UnkStruct_D_01E8953C.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"

struct UnkStruct_0043F680;

struct UnkStruct_0043F680 {
    unsigned char pad_0[0xC];
    short field_C;
    short field_E;
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char pad_16[0x2];
    int field_18;
    unsigned char field_1C;
    unsigned char field_1D;
    unsigned char pad_1E[0x2];
    int field_20;
    unsigned char field_24;
    unsigned char field_25;
    unsigned char pad_26[0x3E];
    int field_64;
    int field_68;
    int field_6C;
};

extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89522 D_01E89522;
extern UnkStruct_D_01E8953C D_01E8953C;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89518 D_01E89518;
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);  // CB3VSelectComponent::Prepare(const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" int func_00271A00(void *, int);
extern "C" void func_00319C80(void *, int, int);

// 0x0043F680
extern "C" void func_0043F680(UnkStruct_0043F680 * self)
{
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    }
    self->field_C = self->field_68;
    self->field_E = 3;
    switch (self->field_64) {
    case 0:
        self->field_10 = func_00271A00(&D_0051BA44, 224);
        self->field_14 = 0;
        self->field_15 = 0;
        self->field_18 = func_00271A00(&D_0051BA44, 357);
        self->field_1C = 0;
        self->field_1D = 0;
        self->field_20 = func_00271A00(&D_0051BA44, 354);
        self->field_24 = 0;
        self->field_25 = 0;
        break;
    case 1:
        self->field_10 = func_00271A00(&D_0051BA44, 400);
        self->field_14 = 0;
        self->field_15 = 0;
        self->field_18 = func_00271A00(&D_0051BA44, 401);
        self->field_1C = 0;
        self->field_1D = 0;
        self->field_20 = func_00271A00(&D_0051BA44, 3180);
        self->field_24 = 0;
        self->field_25 = 0;
        break;
    }
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)((char *)self + 0xC), (CB3VSelectComponentEntryData*)((char *)self + 0x10), 640.0f);
    int v3 = 664;
    if (self->field_64 == 1) {
        switch (self->field_6C) {
        case 0:
            v3 = 3251;
            break;
        case 1:
            v3 = 677;
            break;
        case 2:
            v3 = 690;
            break;
        }
    }
    if (D_01E89522.field_0 == 0) {
        func_00319C80(&D_01E89518, v3, 14);
    } else {
        D_01E8953C.field_0 = v3;
    }
}
