// func_00436F70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_004F50A0.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"

struct UnkStruct_00436F70;

struct UnkStruct_00436F70 {
    unsigned char pad_0[0x4];
    int field_4;
    float field_8;
    unsigned char field_C;
};

extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E89800 D_01E89800;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" int func_00271A00(void *, int);
extern "C" int func_0032CC00(void *, int, int, int, int, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x00436F70
extern "C" int func_00436F70(UnkStruct_00436F70 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_4 = 0;
    int r1 = func_00271A00(&D_0051BA44, 157);
    int r2 = func_00271A00(&D_0051BA44, 158);
    int r3 = func_00271A00(&D_0051BA44, 154);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)3);
    func_0032CC00(&D_01E898E8, 9, r3, r1, r2, 15, 0);
    func_0031ECD0(&D_01E89800, 4, 15);
    self->field_8 = D_004F50A0.field_0;
    self->field_C = 1;
    return 1;
}
