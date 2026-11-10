// Hand-written; the lifter refused it (sibling of func_00389B50, vfunc_14(20,0)).

#include "b3/classes/UnkStruct_D_00516E40.h"
#include "b3/classes/UnkStruct_D_005179F0.h"
struct UnkStruct_0038B2F0 {
    unsigned char pad_0[4];
    unsigned char field_4;
    unsigned char pad_5[0x3B];
    int field_40;
    unsigned char pad_44[0x4];
    float field_48;
};
extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_005179F0 D_005179F0;
extern "C" void StartReplay__20CB3OfflineStageLogicFv(void *);
extern "C" int StartReplay__25CB3OfflineSingleRaceLogicFv(UnkStruct_0038B2F0 *self)
{
    StartReplay__20CB3OfflineStageLogicFv(self);
    self->field_4 = 0;
    self->field_40 = 1;
    ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(20, 0);
    ((UnkStruct_D_005179F0 *)&D_005179F0)->vfunc_14(20, 0);
    self->field_48 = -1.0f;
    return 1;
}
