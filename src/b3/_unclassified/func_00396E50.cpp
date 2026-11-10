// func_00396E50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuComponentSelectionData.h"
#include "b3/classes/CB3VSelectComponentEntryData.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"
#include "b3/classes/UnkStruct_D_01E89800.h"

struct UnkStruct_00396E50;

struct UnkStruct_00396E50 {
    unsigned char pad_0[0x2C];
    short field_2C;
    short field_2E;
    int field_30;
    unsigned char field_34;
    unsigned char field_35;
    unsigned char pad_36[0x2];
    int field_38;
    unsigned char field_3C;
    unsigned char field_3D;
    unsigned char pad_3E[0x2];
    int field_40;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0x2];
    int field_48;
    unsigned char field_4C;
    unsigned char field_4D;
    unsigned char pad_4E[0x40F];
    unsigned char field_45D;
};

extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" void Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, bool, float, float, float, float, const void *, void *, int, float);  // CB3VSelectComponent::Prepare(bool,float,float,float,float,const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 2 more argument(s) [G]
extern "C" int func_00271A00(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" void func_00336320(void *);

// 0x00396E50
extern "C" void func_00396E50(UnkStruct_00396E50 * self)
{
    self->field_45D = 0;
    int r0 = func_00271A00(&D_0051BA44, 1068);
    self->field_30 = r0;
    self->field_34 = 0;
    self->field_35 = 0;
    int r1 = func_00271A00(&D_0051BA44, 1067);
    self->field_38 = r1;
    self->field_3C = 0;
    self->field_3D = 0;
    int r2 = func_00271A00(&D_0051BA44, 942);
    self->field_40 = r2;
    self->field_44 = 0;
    self->field_45 = 0;
    int r3 = func_00271A00(&D_0051BA44, 1069);
    self->field_48 = r3;
    self->field_4C = 0;
    self->field_4D = 0;
    self->field_2C = 0;
    self->field_2E = 4;
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    }
    Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, 0, 84.0f, 240.0f, 30.0f, 40.0f, (const CB3MenuComponentSelectionData*)((char *)self + 0x2C), (CB3VSelectComponentEntryData*)((char *)self + 0x30), 0, 192.0f);
    ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    func_0031ECD0(&D_01E89800, 325, 3);
    int r8 = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D8();
    if (r8 != 0) {
        self->field_45D = 9;
        ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
        func_00336320(&D_01E3CD44);
    }
}
