// func_0037E600 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E8961C.h"
#include "b3/classes/UnkStruct_D_01E899DC.h"

struct UnkStruct_0037E600;

struct UnkStruct_0037E600 {
    unsigned char pad_0[0xC8];
    unsigned char field_C8;
};

extern UnkStruct_D_01E899DC D_01E899DC;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E8961C D_01E8961C;
extern "C" int func_0037E440(UnkStruct_0037E600 *);
extern "C" void func_003BC360(void *, int, int);

// 0x0037E600
extern "C" void func_0037E600(UnkStruct_0037E600 * self)
{
    if (self->field_C8 == 1) {
        self->field_C8 = 0;
        D_01E899C0.Show(0, 0);
        D_01E899DC.field_0 = 0;
        int r1 = func_0037E440(self);
        func_003BC360(&D_01E8961C, 6, r1);
    }
}
