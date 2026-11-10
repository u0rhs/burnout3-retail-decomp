// B3OnlineJoinGamePage.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3OnlineJoinGamePage.cpp, 1 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/CB3OnlineJoinGamePage.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"
#include "b3/classes/UnkStruct_D_01E8CA94.h"
#include "b3/classes/UnkStruct_D_01E8D450.h"
#include "b3/classes/UnkStruct_D_01E8D45A.h"
#include "b3/classes/UnkStruct_D_01E8D490.h"
#include "b3/classes/UnkStruct_D_01E8D49A.h"
#include "b3/classes/UnkStruct_D_01E8D4B0.h"
#include "b3/classes/UnkStruct_D_01E8D4BA.h"
#include "b3/classes/UnkStruct_D_01E8EAF8.h"
#include "b3/classes/UnkStruct_D_01E8EB02.h"
#include "b3/classes/UnkStruct_krTextBackgroundHandle.h"
#include "b3/classes/UnkStruct_krTextBackgroundPosition.h"
#include "b3/classes/UnkStruct_krTextBackgroundSize.h"
#include "b3/classes/UnkStruct_krTextHandle.h"
#include "b3/classes/UnkStruct_krTextPosition.h"

struct UnkStruct_0032A930;
struct UnkStruct_003275A0_10;

struct UnkStruct_0032A930 {
    unsigned char pad_0[0x1B15];
    unsigned char field_1B15;
};

struct UnkStruct_003275A0_10 {
    unsigned char pad_0[0x4C];
    void * field_4C;
};

extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E8D4BA D_01E8D4BA;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_krTextPosition krTextPosition;
extern UnkStruct_krTextHandle krTextHandle;
extern UnkStruct_krTextBackgroundPosition krTextBackgroundPosition;
extern UnkStruct_krTextBackgroundHandle krTextBackgroundHandle;
extern UnkStruct_krTextBackgroundSize krTextBackgroundSize;
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetErrorString(int)
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);  // CB3HelpBarComponent::SetString(const unsigned short*,bool,bool,float)
extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, void *, int);
extern "C" int func_00329210(CB3OnlineJoinGamePage *, unsigned short);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, UnkStruct_003275A0_10 *, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003180A0(void *, void *, void *);
extern "C" bool func_00351E40(void *, void *, void *, void *, void *, void *, void *, int, int, int, int, float, float);

// CB3OnlineJoinGamePage::OnKeyboardShow() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineJoinGamePage.cpp.
// 0x00327540
void CB3OnlineJoinGamePage::OnKeyboardShow()
{
}

// CB3OnlineJoinGamePage::OnKeyboardCancel() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineJoinGamePage.cpp.
// 0x00327550
void CB3OnlineJoinGamePage::OnKeyboardCancel()
{
    if (field_1B15 == 5) {
        D_01E899C0.Show(0, 0);
    }
}

// CB3OnlineJoinGamePage::OnKeyboardDone() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineJoinGamePage.cpp.
// 0x003275A0
void CB3OnlineJoinGamePage::OnKeyboardDone()
{
    UnkStruct_003275A0_10 local;  // [G] the frame's one local (size: up to the frame top)
    if (field_1B15 == 5) {
        int r0 = Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0);
        if (r0 <= 0) {
        } else {
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, ((char *)this + 0x15A4), 32);
            int r2 = func_00329210(this, field_1AF8);
            if (r2 != 0) {
                D_01E899C0.Show(0, 0);
                field_1B15 = 1;
                if (D_01E8D45A.field_0 != 0) {
                    ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
                }
                if (D_01E8D49A.field_0 != 0) {
                    ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
                }
                if (D_01E8D4BA.field_0 != 0) {
                    ((UnkStruct_D_01E8D4B0 *)&D_01E8D4B0)->vfunc_C();
                }
                if (D_01E8EB02.field_0 != 0) {
                    ((UnkStruct_D_01E8EAF8 *)&D_01E8EAF8)->vfunc_C();
                }
                ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(((char *)this + 0x10), &local, 32);
                local.field_4C = (void *)&local;
                int r9 = func_00271A00(&D_0051BA44, 98);
                func_003180A0((void *)(field_1274), (void *)(r9), ((char *)&local + 0x4C));
                SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short*)field_1274, 0, 0, 80.0f);
                func_00351E40(&D_01E8D4B0, &krTextPosition, &krTextHandle, &krTextBackgroundPosition, &krTextBackgroundHandle, &krTextBackgroundSize, (void *)(field_1274), 3, 1, 103, 0, 32.0f, 496.0f);
            } else {
                if (field_1B15 != 5) {
                } else {
                    D_01E899C0.Show(0, 0);
                }
            }
        }
    } else {
    }
}

// CB3OnlineJoinGamePage::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineJoinGamePage.cpp.
// 0x00327F00
void CB3OnlineJoinGamePage::Release()
{
    D_01E899C0.UnRegisterKeyboardCallbacks();
}

// func_0032A930 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0032A930
extern "C" void func_0032A930(UnkStruct_0032A930 * self, int p0)
{
    self->field_1B15 = 4;
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
    }
    if (D_01E8D49A.field_0 != 0) {
        ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
    }
    if (D_01E8D4BA.field_0 != 0) {
        ((UnkStruct_D_01E8D4B0 *)&D_01E8D4B0)->vfunc_C();
    }
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    if (D_01E8EB02.field_0 != 0) {
        ((UnkStruct_D_01E8EAF8 *)&D_01E8EAF8)->vfunc_C();
    } else {
    }
    if (p0 == -38) {
        func_0032D080(&D_01E898E8, 2, 3250, 0, 0);
    } else {
        int r6 = GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, p0);
        func_0032D080(&D_01E898E8, 2, r6, 0, 0);
    }
}
