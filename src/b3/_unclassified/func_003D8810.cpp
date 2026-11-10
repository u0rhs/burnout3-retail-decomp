// Prepare__20CB3HUDPrimaryMessageFi9EHUDAligniP11CB3HUDScore -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDComponent.h"
#include "b3/classes/EHUDAlign.h"
#include "b3/classes/EHUDMode.h"
#include "b3/classes/UnkStruct_D_00522660.h"

struct UnkStruct_003D8810;
struct UnkStruct_003D8810_e0;

struct UnkStruct_003D8810_e0 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_003D8810 {
    unsigned char pad_0[0x4];
    UnkStruct_003D8810_e0 * field_4;
    unsigned char pad_8[0x8];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    int field_20;
    void * field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
};

extern UnkStruct_D_00522660 D_00522660;
extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);  // CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int)
extern "C" void AdjustScalingForSplitScreen__15CB3HUDComponentFv(void *);  // CB3HUDComponent::AdjustScalingForSplitScreen()
extern "C" int func_003D8910();
extern "C" void func_0019F350(UnkStruct_003D8810 *);
extern "C" void Prepare__27CB3HUDPrimaryMessageHandlerFP10CGt2dSceneii(void *, void *, int, short);

// 0x003D8810
extern "C" int Prepare__20CB3HUDPrimaryMessageFi9EHUDAligniP11CB3HUDScore(UnkStruct_003D8810 * self, int p0, int p1, int p2, void *p3_)
{
    int p3 = (int)p3_;
    int r0 = func_003D8910();
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 2, r0, 0, p0, (EHUDAlign)p1, p2);
    AdjustScalingForSplitScreen__15CB3HUDComponentFv(self);
    func_0019F350(self);
    self->field_20 = p0;
    self->field_28 = p3;
    self->field_24 = ((char *)((char *)&D_00522660 + (p0 * 10192)) + 0x12BE10);
    self->field_2C = 0;
    self->field_30 = -1;
    self->field_34 = 0;
    self->field_38 = 0;
    Prepare__27CB3HUDPrimaryMessageHandlerFP10CGt2dSceneii(((char *)self + 0x40), ((char *)&self->field_4[self->field_1C] + 0x14), (self->field_10 + 1), self->field_10);
    return 1;
}
