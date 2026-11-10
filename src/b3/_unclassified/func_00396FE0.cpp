// OnKeyboardShow__22CB3OnlineOpenLobbyPageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3ChatDisplayComponent.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EB3ChatDisplayOrientation.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8D450.h"
#include "b3/classes/UnkStruct_D_01E8D45A.h"
#include "b3/classes/UnkStruct_D_01E8D490.h"
#include "b3/classes/UnkStruct_D_01E8D49A.h"
#include "b3/classes/UnkStruct_D_01E8EAF8.h"
#include "b3/classes/UnkStruct_D_01E8EB02.h"

struct UnkStruct_00396FE0;
struct UnkStruct_00396FE0_9;

struct UnkStruct_00396FE0_9 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_00396FE0 {
    unsigned char pad_0[0x45C];
    unsigned char field_45C;
    unsigned char field_45D;
};

extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern CB3ChatDisplayComponent D_01E8CBE0;
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x00396FE0
extern "C" void OnKeyboardShow__22CB3OnlineOpenLobbyPageFv(UnkStruct_00396FE0 * self)
{
    unsigned char t0 = self->field_45D;
    if (t0 == 1) {
        return;
    }
    if (t0 == 0) {
        if (D_01E8954E.field_0 == 0) {
        } else {
            ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
        }
    } else {
        if (t0 == 2) {
            if (D_01E8D45A.field_0 != 0) {
                ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
            }
            if (D_01E8D49A.field_0 != 0) {
                ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
            }
            if (D_01E8EB02.field_0 != 0) {
                ((UnkStruct_D_01E8EAF8 *)&D_01E8EAF8)->vfunc_C();
            }
        } else {
            if (t0 == 3) {
                if (D_01E8954E.field_0 != 0) {
                    ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
                }
            }
        }
    }
    self->field_45C = self->field_45D;
    self->field_45D = 1;
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    }
    D_01E899C0.Show(1, 0);
    D_01E899C0.SetAllowableCharacters((EGlobalStrings)659);
    ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    func_0031ECD0(&D_01E89800, 0x40000144, 15);
    D_01E8CBE0.SetOrientation((EB3ChatDisplayOrientation)0);
}
