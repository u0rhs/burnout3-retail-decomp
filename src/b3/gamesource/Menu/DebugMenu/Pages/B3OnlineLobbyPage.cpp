// B3OnlineLobbyPage.cpp -- translation unit regrouped by tools/tu_merge.py from 8 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 8 function(s) named in research/retail_names.csv -> B3OnlineLobbyPage.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3BuddyDisplayComponent.h"
#include "b3/classes/CB3ChatDisplayComponent.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/CB3OnlineLobbyPage.h"
#include "b3/classes/EB3ChatDisplayOrientation.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"
#include "b3/classes/UnkStruct_D_01E8CBCC.h"
#include "b3/classes/UnkStruct_D_01E8D450.h"
#include "b3/classes/UnkStruct_D_01E8D490.h"
#include "b3/classes/UnkStruct_D_01E8D49A.h"
#include "b3/classes/UnkStruct_D_01E8EAF8.h"
#include "b3/classes/UnkStruct_D_01E8EB02.h"

struct UnkStruct_00316E30_0;

struct UnkStruct_00316E30_0 {
    unsigned char pad_0[0x100];
};

struct UnkStruct_003180A0_a2 {
    int field_0;
};

struct UnkStruct_003180A0_1 {
    unsigned short field_0[0x1E];
    UnkStruct_003180A0_a2 field_3C;
};

extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern CB3BuddyDisplayComponent D_01E8D670;
extern UnkStruct_D_01E8CBCC D_01E8CBCC;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern CB3ChatDisplayComponent D_01E8CBE0;
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_00316640(CB3OnlineLobbyPage *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char*, UnkStruct_00316E30_0 *, int, void*);
extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, UnkStruct_003180A0_1 *, int, int, int);

// CB3OnlineLobbyPage::_BanBuddyCallback(bool,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// 0x00312210
extern "C" void _BanBuddyCallback__18CB3OnlineLobbyPageFbPv(bool p0, void *p1)
{
    if (p0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 56, 0, 0);
    } else {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 57, 0, 0);
    }
}

// CB3OnlineLobbyPage::_AddUserCallback(bool,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// 0x003122A0
extern "C" void _AddUserCallback__18CB3OnlineLobbyPageFbPv(bool p0, void *p1)
{
    if (p0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 65, 0, 0);
    } else {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 66, 0, 0);
    }
}

// func_00312330 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00312330
extern "C" void func_00312330(int n0, int p0, int p1)
{
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    if (n0 == 0) {
        if (p1 == 6) {
            func_0032D080(&D_01E898E8, 2, 208, 0, 0);
        } else {
            func_0032D080(&D_01E898E8, 2, 207, 0, 0);
        }
    } else {
        func_0032D080(&D_01E898E8, 2, 28, 0, 0);
    }
    D_01E8D670.MailSent(p0);
}

// CB3OnlineLobbyPage::OnKeyboardShow() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// 0x00313090
void CB3OnlineLobbyPage::OnKeyboardShow()
{
    if (field_13AC == 1) {
        field_13AC = 2;
        D_01E899C0.Show(1, 1);
        D_01E899C0.SetAllowableCharacters((EGlobalStrings)659);
        D_01E8CBCC.field_0 = 64;
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
        if (D_01E8D49A.field_0 != 0) {
            ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
        }
        if (D_01E8954E.field_0 != 0) {
            ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
        }
        if (D_01E8EB02.field_0 == 0) {
        } else {
            ((UnkStruct_D_01E8EAF8 *)&D_01E8EAF8)->vfunc_C();
        }
    } else {
    }
}

// CB3OnlineLobbyPage::OnKeyboardCancel() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// 0x003131A0
void CB3OnlineLobbyPage::OnKeyboardCancel()
{
    signed char t0 = field_13AC;
    if (t0 != 2) {
        if (t0 == 5) {
            field_13AC = 3;
            D_01E899C0.Show(0, 1);
        } else {
        }
    } else {
        D_01E899C0.Show(0, 1);
        func_00316640(this);
    }
}

// CB3OnlineLobbyPage::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// 0x003146E0
void CB3OnlineLobbyPage::Release()
{
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_CC(0, 0);
    D_01E899C0.UnRegisterKeyboardCallbacks();
}

// CB3OnlineLobbyPage::ChatMessageCallback(char*,char*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// 0x00316E30
int CB3OnlineLobbyPage::ChatMessageCallback(char* p0, char* p1, void* p2)
{
    UnkStruct_00316E30_0 local;  // [G] the frame's one local (size: up to the frame top)
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(p0, &local, 128, p2);
    D_01E8CBE0.AddNewMessage((char*)this, (const unsigned short*)&local);
    return 1;
}

// func_003180A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003180A0
// [L] p1 is a reference: as a pointer, MWCC cannot hoist the load above the buffer store (retail does).
extern "C" void func_003180A0(void *n0_, void *p0_, const UnkStruct_003180A0_a2 &p1)
{
    int n0 = (int)n0_;
    int p0 = (int)p0_;
    UnkStruct_003180A0_1 local;
    local.field_0[0] = 0;
    local.field_3C = p1;
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, local.field_3C.field_0 != 0 ? (UnkStruct_003180A0_1 *)local.field_3C.field_0 : &local, 0, 0, 0);
}
