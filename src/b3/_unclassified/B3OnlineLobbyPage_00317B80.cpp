// CB3OnlineLobbyPage::HandleError(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/CB3OnlineLobbyPage.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"
#include "b3/classes/UnkStruct_D_01E8D450.h"
#include "b3/classes/UnkStruct_D_01E8D45A.h"
#include "b3/classes/UnkStruct_D_01E8D490.h"
#include "b3/classes/UnkStruct_D_01E8D49A.h"
#include "b3/classes/UnkStruct_D_01E8D4B0.h"
#include "b3/classes/UnkStruct_D_01E8D4BA.h"
#include "b3/classes/UnkStruct_D_01E8EAF8.h"
#include "b3/classes/UnkStruct_D_01E8EB02.h"

extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E8D4BA D_01E8D4BA;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetErrorString(int)
extern "C" void func_00316640(CB3OnlineLobbyPage *, int);
extern "C" void func_0032D080(void *, int, int, int, int);

// 0x00317B80
void CB3OnlineLobbyPage::HandleError(int p0)
{
    field_13AC = 16;
    if (p0 == -19) {
        func_00316640(this, p0);
    }
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
    }
    if (D_01E8EB02.field_0 != 0) {
        ((UnkStruct_D_01E8EAF8 *)&D_01E8EAF8)->vfunc_C();
    }
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    }
    if (D_01E8D49A.field_0 != 0) {
        ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
    }
    if (D_01E8D4BA.field_0 != 0) {
        ((UnkStruct_D_01E8D4B0 *)&D_01E8D4B0)->vfunc_C();
    }
    D_01E899C0.Show(0, 1);
    int r8 = GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, p0);
    func_0032D080(&D_01E898E8, 2, r8, 0, 0);
}
