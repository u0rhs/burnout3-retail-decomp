// func_003B8450 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDComponent.h"
#include "b3/classes/CGt2dFrame.h"
#include "b3/classes/EHUDAlign.h"
#include "b3/classes/EHUDMode.h"

struct UnkStruct_003B8450;
struct UnkStruct_003B8450_e0;

struct UnkStruct_003B8450_e0 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_003B8450 {
    unsigned char pad_0[0x4];
    UnkStruct_003B8450_e0 * field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    int field_20;
    unsigned char pad_24[0x4];
    int field_28;
    int field_2C;
    unsigned char field_30;
};

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);  // CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int)
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)

// 0x003B8450
extern "C" int func_003B8450(UnkStruct_003B8450 * self, int p0, int p1, int p2, int p3)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 1, 1, 0, p0, (EHUDAlign)p1, p2);
    UnkStruct_003B8450_e0 * e = &self->field_4[self->field_1C];
    short t2 = self->field_10;
    self->field_28 = p0;
    self->field_2C = -1;
    self->field_30 = p3;
    self->field_20 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame((char *)e + 0x14, t2, (CGt2dFrame*)self->field_8);
    return 1;
}
