// Hand-written; the lifter refused it (near14: loop limit D_0064D3A0 = D_00522660+0x12AD40 (one object) read through D_00522660 so the stores force retail's per-iteration reload. FINISH_FORCE: rchk reads only the lo addend (0x12AD40 > 0x7FFF, hi/lo resolve to 0x64D3A0 = retail bytes) + ofs_0012C0E0 constant).

#include "b3/classes/UnkStruct_D_00522660.h"
struct UnkStruct_D_int_003933E0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_003933E0_g {
    unsigned char pad_0[0x12AD40];
    int field_12AD40;  // [C] = D_0064D3A0 (0x522660 + 0x12AD40)
};
struct UnkStruct_003933E0_g2 {
    unsigned char pad_0[0x12C0E0];
    float field_12C0E0;
};

extern UnkStruct_D_int_003933E0 D_0064D3A0;
extern "C" void OnWorldPrepared__13CB3StageLogicFv(void *);
extern "C" void OnWorldPrepared__26CB3OfflineSingleCrashLogicFv(void *self)
{
    OnWorldPrepared__13CB3StageLogicFv(self);
    for (int i = 0; i < ((UnkStruct_003933E0_g *)&D_00522660)->field_12AD40; i++) {
        ((UnkStruct_003933E0_g2 *)((char *)&D_00522660 + i * 0x27D0))->field_12C0E0 = 30.0f;
    }
}
