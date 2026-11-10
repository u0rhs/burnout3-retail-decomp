// B3OnlineBuddiesSearchMenuPage.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3OnlineBuddiesSearchMenuPage.cpp, 2 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3BuddyDisplayComponent.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/CB3OnlineBuddiesSearchMenuPage.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E3D390.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"
#include "b3/classes/UnkStruct_D_01E8CA94.h"

struct UnkStruct_00373100;
struct UnkStruct_00373100_5;
struct UnkStruct_func_00372FB0;

struct UnkStruct_00373100_5 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_func_00372FB0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00373100 {
    unsigned char pad_0[0x28];
    int field_28;
};

extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern CB3BuddyDisplayComponent D_01E8D670;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern UnkStruct_func_00372FB0 func_00372FB0;
extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, void *, int);
extern "C" int func_00360240(void *, char *, char *, void *, UnkStruct_00373100 *);
extern "C" void func_00366560(void *, char *);
extern "C" void func_0032D080(void *, int, int, int, int);

// CB3OnlineBuddiesSearchMenuPage::OnKeyboardShow() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineBuddiesSearchMenuPage.cpp.
// 0x003730A0
void CB3OnlineBuddiesSearchMenuPage::OnKeyboardShow()
{
}

// CB3OnlineBuddiesSearchMenuPage::OnKeyboardCancel() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineBuddiesSearchMenuPage.cpp.
// 0x003730B0
void CB3OnlineBuddiesSearchMenuPage::OnKeyboardCancel()
{
    if (field_28 == 1) {
        field_28 = 0;
        D_01E899C0.Show(0, 0);
    }
}

// func_00373100 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00373100
extern "C" void func_00373100(UnkStruct_00373100 * self)
{
    char utf8[200];
    char name[16];
    if (self->field_28 == 1) {
        D_01E899C0.Show(0, 0);
        int r1 = Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0);
        if (r1 > 0) {
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, utf8, 200);
            D_01E8D670.GetSelectedBuddyName(name);
            int r4 = func_00360240(&D_01E3D390, name, utf8, &func_00372FB0, self);
            if (r4 != 0) {
                func_00366560(&D_01E8D670, name);
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
            self->field_28 = 5;
        } else {
            self->field_28 = 0;
        }
    }
}

// CB3OnlineBuddiesSearchMenuPage::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineBuddiesSearchMenuPage.cpp.
// 0x00373260
void CB3OnlineBuddiesSearchMenuPage::Release()
{
    D_01E899C0.UnRegisterKeyboardCallbacks();
}
