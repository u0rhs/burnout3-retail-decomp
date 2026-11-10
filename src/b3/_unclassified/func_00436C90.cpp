// Hand-written; the lifter refused it (hand-written (lifter refused): state-1 timer block, then switch(field_4) over the func_0032B2C0 result with if/else-if per case).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_004E2910.h"
#include "b3/classes/UnkStruct_D_004E2914.h"
#include "b3/classes/UnkStruct_D_004EE040.h"
#include "b3/classes/UnkStruct_D_004F50A0.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_00665EC0.h"
#include "b3/classes/UnkStruct_D_01E7A800.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_00436C90;

struct UnkStruct_00436C90 {
    unsigned char pad_0[0x4];
    int field_4;
    float field_8;
    unsigned char field_C;
};

extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004E2910 D_004E2910;
extern UnkStruct_D_004E2914 D_004E2914;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);  // CB3HUDSoundManager::FESelect()
extern "C" int func_00271A00(void *, int);
extern "C" int func_0032CC00(void *, int, int, int, int, int, int);
extern "C" void func_0032CF60(void *, int, void *, int, int);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_00227B80(void *, int);
extern "C" void SetFrontendFrameRate__7CB3GameFb(void *, int);

// 0x00436C90
extern "C" void func_00436C90(UnkStruct_00436C90 * self)
{
    if (D_01E90424.field_0 != 5) return;
    int s3 = func_00271A00(&D_0051BA44, 159);
    int s2 = func_00271A00(&D_0051BA44, 160);
    int s1 = func_00271A00(&D_0051BA44, 156);
    int s0 = func_00271A00(&D_0051BA44, 155);
    if (self->field_4 == 1) {
        if (self->field_C != 0) {
            self->field_8 = D_004F50A0.field_0;
            self->field_C = 0;
        }
        if (D_004F50A0.field_0 - self->field_8 < 5.0f) return;
        self->field_4 = 2;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032CC00(&D_01E898E8, 9, s1, s3, s2, 14, 0);
        }
        func_00227B80(&D_00665EC0, 0);
        SetFrontendFrameRate__7CB3GameFb(&D_004EE040, 1);
    }
    int r = func_0032B2C0(&D_01E898E8, -1, 1);
    switch (self->field_4) {
    case 0:
        if (r == 14) {
            self->field_4 = 1;
            if (D_01E898F2.field_0 != 0) {
                FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                func_0032CF60(&D_01E898E8, 0, (void *)(s0), 15, 0);
            }
            func_00227B80(&D_00665EC0, 1);
            SetFrontendFrameRate__7CB3GameFb(&D_004EE040, 1);
        } else if (r == 13) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
        break;
    case 2:
        if (r == 13) {
            func_00227B80(&D_00665EC0, 1);
            D_004E2914.field_0 = 1;
            D_004E2910.field_0 = 0;
            SetFrontendFrameRate__7CB3GameFb(&D_004EE040, 1);
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        } else if (r == 14) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
        break;
    }
}
