// OnKeyboardCancel__22CB3OnlineOpenLobbyPageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3ChatDisplayComponent.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EB3ChatDisplayOrientation.h"
#include "b3/classes/EGlobalStrings.h"

struct UnkStruct_003971C0;

struct UnkStruct_003971C0 {
    unsigned char pad_0[0x45C];
    unsigned char field_45C;
    unsigned char field_45D;
};

extern CB3OnScreenKeyboardComponent D_01E899C0;
extern CB3ChatDisplayComponent D_01E8CBE0;
extern "C" void func_00396D30(UnkStruct_003971C0 *);
extern "C" void func_00396E50(UnkStruct_003971C0 *);
extern "C" void func_00396A90(UnkStruct_003971C0 *);

// 0x003971C0
extern "C" void OnKeyboardCancel__22CB3OnlineOpenLobbyPageFv(UnkStruct_003971C0 * self)
{
    unsigned char t0 = self->field_45D;
    if (t0 != 1 && t0 != 5) {
        return;
    }
    self->field_45D = self->field_45C;
    D_01E899C0.Show(0, 0);
    D_01E8CBE0.SetOrientation((EB3ChatDisplayOrientation)1);
    unsigned char t1 = self->field_45D;
    if (t1 == 0) {
        func_00396E50(self);
    } else if (t1 == 2) {
        func_00396D30(self);
    } else if (t1 == 3) {
        func_00396A90(self);
    }
}
