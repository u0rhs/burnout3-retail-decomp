// func_003ED9F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E90240.h"

extern CB3HUDSoundManager D_01E7A800;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]

// 0x003ED9F0
extern "C" void func_003ED9F0(void *a0, float f12, float f13, float f14 /* passed by every caller, not read here */)
{
    D_01E7A800.FEBack();
    D_01E899C0.Show(0, 0);
    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
}
