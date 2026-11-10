// func_004546B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_004E2648.h"
#include "b3/classes/UnkStruct_D_004E264C.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E89810.h"
#include "b3/classes/UnkStruct_D_01E8EB4C.h"
#include "b3/classes/UnkStruct_D_01E8F2D8.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_004546B0;

struct UnkStruct_004546B0 {
    unsigned char pad_0[0x4];
    void *field_4;
    void *field_8;
};

extern UnkStruct_D_01E8EB4C D_01E8EB4C;
extern UnkStruct_D_004E264C D_004E264C;
extern UnkStruct_D_004E2648 D_004E2648;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E89810 D_01E89810;
extern UnkStruct_D_01E8F2D8 D_01E8F2D8;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);  // CB3PromptsComponent::SetCurrentPrompts(unsigned int,unsigned int); first argument declared 64-bit here [G]: retail passes the ld value un-truncated
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" void Play__14CGtSoundStreamFb(void *, int);
extern "C" void SetVolume__14CGtSoundStreamFfi(void *, int, float);
extern "C" int func_00455B00(void *);

// 0x004546B0
extern "C" void func_004546B0(UnkStruct_004546B0 * self)
{
    if (D_01E8EB4C.field_0 == 0) {
        if (self->field_8 != 0) {
            Play__14CGtSoundStreamFb(self->field_8, 0);
            SetVolume__14CGtSoundStreamFfi(self->field_8, 0, D_004E2648.field_0);
        }
    } else {
        if (self->field_8 != 0) {
            Stop__14CGtSoundStreamFv(self->field_8);
        }
        if (self->field_4 != 0) {
            Play__14CGtSoundStreamFb(self->field_4, 0);
            SetVolume__14CGtSoundStreamFfi(self->field_4, 0, D_004E264C.field_0);
        }
    }
    if (D_01E90424.field_0 != 5) {
        return;
    }
    if (func_00455B00(&D_01E8F2D8) != 0) {
        unsigned long t3 = D_01E89810.field_0;
        if ((t3 & 16) != 16) {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, (t3 | 16), 3);
        }
        if (D_004F50C0.GetMenuConfirm(0) != 0) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
        }
    }
}
