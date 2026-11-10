// B3OnlineSelectLoginPage.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3OnlineSelectLoginPage.cpp, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/CB3OnlineSelectLoginPage.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89522.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"
#include "b3/classes/UnkStruct_D_01E8961C.h"
#include "b3/classes/UnkStruct_D_01E89626.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"
#include "b3/classes/UnkStruct_D_01E899DC.h"
#include "b3/classes/UnkStruct_D_01E8D4F0.h"
#include "b3/classes/UnkStruct_D_01E8D4FA.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"

struct UnkStruct_003485B0;
struct UnkStruct_003496C0;

struct UnkStruct_003485B0 {
    unsigned char pad_0[0x70];
    unsigned char field_70;
    unsigned char field_71;
};

struct UnkStruct_003496C0 {
    unsigned char pad_0[0x6C];
    int field_6C;
    unsigned char field_70;
    unsigned char pad_71[0x1];
    unsigned char field_72;
};

extern UnkStruct_D_01E89626 D_01E89626;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E899DC D_01E899DC;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E8D4FA D_01E8D4FA;
extern UnkStruct_D_01E8D4F0 D_01E8D4F0;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89522 D_01E89522;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::GetLobbyStatus()
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetErrorString(int)
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_00420B60(void *);
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);  // CB3HelpBarComponent::SetString(const unsigned short*,bool,bool,float)
extern "C" int func_00271A00(void *, int);
extern "C" void func_00319C80(void *, int, int);

// CB3OnlineSelectLoginPage::OnKeyboardShow() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// 0x00347890
void CB3OnlineSelectLoginPage::OnKeyboardShow()
{
}

// CB3OnlineSelectLoginPage::OnKeyboardCancel() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// 0x003478A0
void CB3OnlineSelectLoginPage::OnKeyboardCancel()
{
    if (field_72 != 0) {
        if (D_01E89626.field_0 != 0) {
            ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
        }
        func_003BE5A0(&D_01E8961C, ((char *)this + 0xF0), ((char *)this + 0xF8));
        if (field_72 == 2) {
            D_01E899DC.field_0 = 0;
        }
        field_72 = 0;
        D_01E899C0.Show(0, 0);
    }
}

// CB3OnlineSelectLoginPage::UpdateRequestingAccountPassword() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// 0x00348490
void CB3OnlineSelectLoginPage::UpdateRequestingAccountPassword()
{
    int r0 = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
    switch (r0) {
    case 0:
        break;
    case 2:
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 77, 0, 0);
        field_70 = 7;
        break;
    case 1:
        int r3 = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
        if (r3 != 0) {
            field_71 = field_70;
            field_70 = 4;
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            int r5 = GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r3);
            func_0032D080(&D_01E898E8, 2, r5, 0, 0);
            return;
        }
        break;
    default:
        break;
    }
}

// func_003485B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003485B0
extern "C" void func_003485B0(UnkStruct_003485B0 * self)
{
    int r0 = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
    switch (r0) {
    case 0:
        break;
    case 2:
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        self->field_70 = 1;
        break;
    case 1:
        int r2 = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
        if (r2 != 0) {
            self->field_71 = self->field_70;
            self->field_70 = 4;
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            int r4 = GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r2);
            func_0032D080(&D_01E898E8, 2, r4, 0, 0);
            return;
        }
        break;
    default:
        break;
    }
}

// func_003494C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003494C0
extern "C" void func_003494C0()
{
    D_01E899C0.UnRegisterKeyboardCallbacks();
    func_00420B60(&D_01ECD520);
}

// func_003496C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003496C0
extern "C" void func_003496C0(UnkStruct_003496C0 * self)
{
    self->field_70 = 5;
    self->field_72 = 0;
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    if (D_01E89626.field_0 != 0) {
        ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
    }
    if (D_01E8D4FA.field_0 != 0) {
        ((UnkStruct_D_01E8D4F0 *)&D_01E8D4F0)->vfunc_C();
    }
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    }
    if (D_01E89522.field_0 != 0) {
        ((UnkStruct_D_01E89518 *)&D_01E89518)->vfunc_C();
    }
    func_0032D080(&D_01E898E8, 1, 120, 15, 0);
    int r6 = func_00271A00(&D_0051BA44, 192);
    SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short*)r6, 0, 0, 80.0f);
    func_00319C80(&D_01E89518, 102, 14);
    self->field_6C = 0;
}
