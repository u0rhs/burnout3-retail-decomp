// func_0045D060 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"

struct UnkStruct_0045D060;

struct UnkStruct_0045D060 {
    unsigned char pad_0[0xD4];
    int field_D4;
};

extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern "C" void func_00335F60(void *);
extern "C" void func_00335DB0(void *, void *);

// 0x0045D060
extern "C" void func_0045D060(UnkStruct_0045D060 * self)
{
    func_00335F60(&D_01E3CD44);
    int t0 = self->field_D4;
    if (t0 != 0) {
        func_00335DB0(&D_01E3CD44, (void *)(t0));
    }
    D_01E899C0.UnRegisterKeyboardCallbacks();
}
