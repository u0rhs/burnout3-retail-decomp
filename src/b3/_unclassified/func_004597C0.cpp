// func_004597C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E3D390.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"
#include "b3/classes/UnkStruct_D_01E8CA94.h"

struct UnkStruct_004597C0;
struct UnkStruct_004597C0_2;
struct UnkStruct_func_00459550;

struct UnkStruct_004597C0_2 {
    unsigned char pad_0[0xD0];
};

struct UnkStruct_func_00459550 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004597C0 {
    unsigned char pad_0[0xD4D];
    signed char field_D4D;
};

extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern UnkStruct_func_00459550 func_00459550;
extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, UnkStruct_004597C0_2 *, int);
extern "C" int func_00360240(void *, void *, UnkStruct_004597C0_2 *, void *, UnkStruct_004597C0 *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_0045A9F0(UnkStruct_004597C0 *);

// 0x004597C0
extern "C" void func_004597C0(UnkStruct_004597C0 * self)
{
    UnkStruct_004597C0_2 local;  // [G] the frame's one local (size: up to the frame top)
    if (self->field_D4D == 3) {
        D_01E899C0.Show(0, 1);
        int r1 = Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0);
        if (r1 > 0) {
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, &local, 200);
            self->field_D4D = 4;
            int r4 = func_00360240(&D_01E3D390, ((char *)self + 0x4), &local, &func_00459550, self);
            if (r4 == 0) {
                if (D_01E898F2.field_0 != 0) {
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                }
                func_0032D080(&D_01E898E8, 0, 27, 15, 0);
            } else {
                if (D_01E898F2.field_0 != 0) {
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                }
                func_0032D080(&D_01E898E8, 2, 207, 0, 0);
            }
        } else {
            func_0045A9F0(self);
        }
    }
}
