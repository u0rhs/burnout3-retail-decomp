// func_004372B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_0051A6A8.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_0051BAB4.h"
#include "b3/classes/UnkStruct_D_0051BAB8.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"

struct UnkStruct_004372B0;

struct UnkStruct_004372B0 {
    unsigned char pad_0[0x4];
    unsigned short field_4[64];  // [G] ustr buffer (Copy__10CGtUnicodeFPUsPCUs target)
    int field_84;
    int field_88;
    unsigned char field_8C;
    unsigned char pad_8D[0x3];
    int field_90;
};

extern UnkStruct_D_0051BAB4 D_0051BAB4;
extern UnkStruct_D_0051BAB8 D_0051BAB8;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E89800 D_01E89800;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);
extern "C" int func_00271A00(void *, int);
extern "C" void Copy__10CGtUnicodeFPUsPCUs(void *, int);
extern "C" void func_0032CF60(void *, int, void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x004372B0
extern "C" int func_004372B0(UnkStruct_004372B0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    func_00130C70(&D_0051A6A8);
    func_00130D00(&D_0051A6A8);
    int r3 = func_00271A00(&D_0051BA44, 2449);
    Copy__10CGtUnicodeFPUsPCUs(self->field_4, r3);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)3);
    func_0032CF60(&D_01E898E8, 8, self->field_4, 15, 0);
    func_0031ECD0(&D_01E89800, 4, 15);
    self->field_8C = 0;
    self->field_90 = 1;
    self->field_84 = D_0051BAB4.field_0;
    self->field_88 = D_0051BAB8.field_0;
    return 1;
}
