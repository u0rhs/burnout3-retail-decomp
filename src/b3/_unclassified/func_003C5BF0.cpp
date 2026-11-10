// func_003C5BF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuComponentSelectionData.h"
#include "b3/classes/CB3VSelectComponentEntryData.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01ECDA14.h"
#include "b3/classes/UnkStruct_D_01ECDAC1.h"
#include "b3/classes/UnkStruct_D_01ECDAC2.h"
#include "b3/classes/UnkStruct_D_01ECDAC6.h"

struct UnkStruct_003C5BF0;
struct UnkStruct_003C5BF0_e0;

struct UnkStruct_003C5BF0_e0 {
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[0x2];
};

struct UnkStruct_003C5BF0 {
    unsigned char pad_0[0x4];
    short field_4;
    short field_6;
    UnkStruct_003C5BF0_e0 field_8[1];  // [G] element count unknown
    unsigned char pad_10[0x1C];
    unsigned char field_2C[1];  // [G] element count unknown
    unsigned char pad_2D[0x1E];
    unsigned char field_4B;
};

extern UnkStruct_D_01ECDA14 D_01ECDA14;
extern UnkStruct_D_01ECDAC1 D_01ECDAC1;
extern UnkStruct_D_01ECDAC2 D_01ECDAC2;
extern UnkStruct_D_01ECDAC6 D_01ECDAC6;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89544 D_01E89544;
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);  // CB3VSelectComponent::Prepare(const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" void Prepare__19CB3VSelectComponentFfPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, float, const void *, void *, float);  // CB3VSelectComponent::Prepare(float,const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" int func_00271A00(void *, int);
extern "C" void func_003C5A80(UnkStruct_003C5BF0 *);

// 0x003C5BF0
extern "C" void func_003C5BF0(UnkStruct_003C5BF0 * self, int p0)
{
    if (self->field_4B == 0) {
        return;
    }
    int m1 = 0;
    for (unsigned int m0 = 1; m0 < 16; m0 <<= 1) {
        switch ((D_01ECDA14.field_0 & m0)) {
        case 0:
            continue;
        case 1:
            if (D_01ECDAC1.field_0 == 0 || D_01ECDAC2.field_0 == 0) {
                int r = func_00271A00(&D_0051BA44, 894);
                self->field_8[m1].field_0 = r;
                self->field_8[m1].field_4 = 0;
                self->field_8[m1].field_5 = 0;
            } else {
                int r = func_00271A00(&D_0051BA44, 2864);
                self->field_8[m1].field_0 = r;
                self->field_8[m1].field_4 = 0;
                self->field_8[m1].field_5 = 0;
            }
            self->field_2C[m1] = 2;
            break;
        case 2:
            if (D_01ECDAC1.field_0 != 0) {
                int r = func_00271A00(&D_0051BA44, 2524);
                self->field_8[m1].field_0 = r;
                self->field_8[m1].field_4 = 0;
                self->field_8[m1].field_5 = 0;
            } else {
                int r = func_00271A00(&D_0051BA44, 895);
                self->field_8[m1].field_0 = r;
                self->field_8[m1].field_4 = 0;
                self->field_8[m1].field_5 = 0;
            }
            self->field_2C[m1] = 8;
            break;
        case 4:
            if (D_01ECDAC1.field_0 != 0) {
                int r = func_00271A00(&D_0051BA44, 2525);
                self->field_8[m1].field_0 = r;
                self->field_8[m1].field_4 = 0;
                self->field_8[m1].field_5 = 0;
            } else {
                int r = func_00271A00(&D_0051BA44, 896);
                self->field_8[m1].field_0 = r;
                self->field_8[m1].field_4 = 0;
                self->field_8[m1].field_5 = 0;
            }
            self->field_2C[m1] = 7;
            break;
        case 8:
            if (D_01ECDAC6.field_0 != 0) {
                int r = func_00271A00(&D_0051BA44, 955);
                self->field_8[m1].field_0 = r;
                self->field_8[m1].field_4 = 0;
                self->field_8[m1].field_5 = 0;
            } else {
                int r = func_00271A00(&D_0051BA44, 897);
                self->field_8[m1].field_0 = r;
                self->field_8[m1].field_4 = 0;
                self->field_8[m1].field_5 = 0;
            }
            self->field_2C[m1] = 11;
            break;
        }
        m1++;
    }
    if (m1 == 0) {
        return;
    }
    self->field_4 = 0;
    self->field_6 = m1;
    if (p0 != 0) {
        Prepare__19CB3VSelectComponentFfPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, 340.0f, (const CB3MenuComponentSelectionData*)((char *)self + 0x4), (CB3VSelectComponentEntryData*)((char *)self + 0x8), 150.0f);
    } else {
        Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)((char *)self + 0x4), (CB3VSelectComponentEntryData*)((char *)self + 0x8), 400.0f);
    }
    func_003C5A80(self);
}
