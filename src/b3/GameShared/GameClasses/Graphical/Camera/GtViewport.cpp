// GtViewport.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> GtViewport.cpp.
// Area: src/b3/GameShared/GameClasses/Graphical/Camera, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/Camera/GtViewport.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtCamera.h"
#include "b3/classes/CGtViewport.h"
#include "b3/classes/UnkStruct_D_004E0C3C.h"

extern UnkStruct_D_004E0C3C D_004E0C3C;
extern "C" int RwCameraCreate(CGtViewport *, int, int, int);
extern "C" int RwFrameCreate();
extern "C" void _rwObjectHasFrameSetFrame(UnkStruct_00211DD0_1 *, int);
extern "C" int RwRasterCreate(int, int, int, int);
extern "C" void RwCameraSetNearClipPlane(UnkStruct_00211DD0_1 *, float);
extern "C" void RwCameraSetFarClipPlane(UnkStruct_00211DD0_1 *, float);

// CGtViewport::SetAspectRatio(float) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtViewport.cpp.
// 0x00211CB0
void CGtViewport::SetAspectRatio(float p0)
{
    field_74 = p0;
}

// CGtViewport::SetCamera(CGtCamera*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtViewport.cpp.
// 0x00211D50
void CGtViewport::SetCamera(CGtCamera* p0)
{
    field_68 = (void *)p0;
    p0->field_30 = (void *)this;
}

// CGtViewport::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtViewport.cpp.
// 0x00211D60
int CGtViewport::Prepare()
{
    field_6C = -1.0f;
    return 1;
}

// CGtViewport::Construct(int,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtViewport.cpp.
// 0x00211DD0
void CGtViewport::Construct(int p0, int p1, int p2)
{
    int r0 = RwCameraCreate(this, p0, p1, p2);
    field_58 = (UnkStruct_00211DD0_1 *)r0;
    int r1 = RwFrameCreate();
    field_5C = r1;
    _rwObjectHasFrameSetFrame(field_58, field_5C);
    field_68 = 0;
    int r3 = RwRasterCreate(p0, p1, p2, 2);
    field_60 = r3;
    int r4 = RwRasterCreate(p0, p1, 0, 1);
    field_64 = r4;
    field_58->field_60 = field_60;
    field_58->field_64 = field_64;
    field_84 = 0x3E800000;
    RwCameraSetNearClipPlane(field_58, *(float *)&field_84);
    field_88 = 0x44FA0000;
    RwCameraSetFarClipPlane(field_58, *(float *)&field_88);
    field_74 = D_004E0C3C.field_0;
    field_70 = 1.0f;
    field_40 = 0;
    field_44 = 0;
    field_78 = p0;
    field_7C = p1;
    field_80 = p2;
}
