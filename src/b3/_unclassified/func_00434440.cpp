// func_00434440 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E8961C.h"
#include "b3/classes/UnkStruct_D_01E8CA94.h"

struct UnkStruct_00434440;

struct UnkStruct_00434440 {
    unsigned char pad_0[0x40];
    int field_40;
    int field_44;
    unsigned short field_48;
    unsigned char pad_4A[0x2];
    unsigned char field_4C;
};

extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_01E8961C D_01E8961C;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(int, int, int);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);

// 0x00434440
extern "C" void func_00434440(UnkStruct_00434440 * self)
{
    if (self->field_4C == 1) {
        switch (self->field_48) {
        case 0:
            int r0 = Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0);
            if (r0 > 0) {
                CopyN__10CGtUnicodeFPUsiPCUs(self->field_40, 9, D_01E8CA94.field_0);
                SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, 0);
                self->field_4C = 0;
                D_01E899C0.Show(0, 0);
            }
            break;
        case 1:
            int r4 = Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0);
            if (r4 > 0) {
                CopyN__10CGtUnicodeFPUsiPCUs(self->field_44, 9, D_01E8CA94.field_0);
                SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, 0);
                self->field_4C = 0;
                D_01E899C0.Show(0, 0);
            }
            break;
        default:
            break;
        }
    } else {
    }
}
