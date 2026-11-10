// func_0042E6B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_004E2F58.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8980A.h"
#include "b3/classes/UnkStruct_D_01E8F360.h"
#include "b3/classes/UnkStruct_D_01E8F36A.h"
#include "b3/classes/UnkStruct_D_01E90438.h"

struct UnkStruct_0042E6B0;

struct UnkStruct_0042E6B0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
};

extern UnkStruct_D_004E2F58 D_004E2F58;
extern UnkStruct_D_01E8F36A D_01E8F36A;
extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E90438 D_01E90438;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00319C80(void *, int, int);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00449F10(void *, int, int, int, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x0042E6B0
extern "C" int func_0042E6B0(UnkStruct_0042E6B0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)1);
    D_01E894FC.Prepare();
    func_00319C80(&D_01E89518, 222, 5);
    int r4 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 256);
    D_004E2F58.field_0 = r4;
    self->field_4 = 4;
    self->field_C = 1;
    self->field_8 = 2;
    int v2;
    if (D_01E8F36A.field_0 != 0) {
        ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
        v2 = self->field_8;
    } else {
        v2 = self->field_8;
    }
    switch (v2) {
    case 0:
    case 1:
        func_00449F10(&D_01E8F360, 0, 2262, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        break;
    case 2:
        func_00449F10(&D_01E8F360, 4, 2253, 0, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 264, 3);
        break;
    default:
        break;
    }
    return 1;
}
