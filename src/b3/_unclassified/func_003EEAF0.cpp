// func_003EEAF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"

extern UnkStruct_D_01ECD520 D_01ECD520;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern "C" void OnMemCardPageExit__24CB3MemCardControllerBaseFv(void *);

// 0x003EEAF0
extern "C" void func_003EEAF0()
{
    OnMemCardPageExit__24CB3MemCardControllerBaseFv(&D_01ECD520);
    D_01E899C0.UnRegisterKeyboardCallbacks();
}
