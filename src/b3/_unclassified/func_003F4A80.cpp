// func_003F4A80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/CB3Profile.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_0051BF9C.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"

extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern "C" void OnMemCardPageExit__24CB3MemCardControllerBaseFv(void *);
extern "C" void func_00139F20(CB3Profile *);

// 0x003F4A80
extern "C" void func_003F4A80()
{
    OnMemCardPageExit__24CB3MemCardControllerBaseFv(&D_01ECD520);
    D_01E899C0.UnRegisterKeyboardCallbacks();
    D_0051BF9C.field_0->Evaluate();
    func_00139F20(D_0051BF9C.field_0);
}
