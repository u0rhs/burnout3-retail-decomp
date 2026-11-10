// func_00321780 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_0051A6A8.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89980.h"
#include "b3/classes/UnkStruct_D_01E900B0.h"
#include "b3/classes/UnkStruct_D_01E91C3C.h"
#include "b3/classes/UnkStruct_D_01E91C3D.h"

extern UnkStruct_D_01E900B0 D_01E900B0;
extern UnkStruct_D_01E91C3D D_01E91C3D;
extern UnkStruct_D_01E91C3C D_01E91C3C;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89980 D_01E89980;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00130C20(void *, unsigned long);
extern "C" bool func_00441A00(void *, int);

// 0x00321780
extern "C" int func_00321780(void *n0_)
{
    int n0 = (int)n0_;
    Prepare__15CB3MenuPageBaseFb((void *)n0, 0);
    switch (D_01E900B0.field_0) {
    case 0:
        func_00130C20(&D_0051A6A8, 0x94413E2EEC056247);
        break;
    case 3:
    case 1:
        D_01E91C3D.field_0 = 1;
        Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)6);
        func_00441A00(&D_01E89980, 0);
        break;
    case 2:
        D_01E91C3C.field_0 = 1;
        Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)6);
        func_00441A00(&D_01E89980, 1);
        break;
    default:
        break;
    }
    return 1;
}
