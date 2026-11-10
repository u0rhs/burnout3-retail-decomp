// OnKeyboardCancel__27CB3MyBurnoutProfileSavePageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"

struct UnkStruct_003EDE70;

struct UnkStruct_003EDE70 {
    unsigned char pad_0[0x8];
    int field_8;
};

extern UnkStruct_D_01ECD520 D_01ECD520;
extern CB3HUDSoundManager D_01E7A800;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern "C" void func_003EE470(UnkStruct_003EDE70 *, int);
extern "C" void StartSaveProfileFlow__24CB3MemCardControllerBaseFv(void *);

// 0x003EDE70
extern "C" void OnKeyboardCancel__27CB3MyBurnoutProfileSavePageFv(UnkStruct_003EDE70 * self)
{
    if (self->field_8 == 14) {
        self->field_8 = 0;
        func_003EE470(self, 0);
        StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
        D_01E7A800.FEBack();
        D_01E899C0.Show(0, 0);
    }
}
