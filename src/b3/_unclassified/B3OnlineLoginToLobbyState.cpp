// B3OnlineLoginToLobbyState.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3OnlineLoginToLobbyState.cpp.
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ErrorPage.h"
#include "b3/classes/CB3OnlineLoginToLobbyState.h"
#include "b3/classes/CB3OnlineSelectLoginPage.h"
#include "b3/classes/CB3OnlineSelectPersonaPage.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/EB3MessageBoxType.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E94C40.h"
#include "b3/classes/UnkStruct_D_01E9B4CC.h"
#include "b3/classes/UnkStruct_D_01E9B534.h"
#include "b3/classes/UnkStruct_D_01E9B792.h"
#include "b3/classes/UnkStruct_D_01EA2878.h"

struct UnkStruct_0034B800_e1;

struct UnkStruct_0034B800_e1 {
    unsigned char pad_0[0x10];
};

extern UnkStruct_D_01E9B534 D_01E9B534;
extern UnkStruct_D_01E9B792 D_01E9B792;
extern UnkStruct_D_01EA2878 D_01EA2878;
extern CB3OnlineSelectPersonaPage D_01EA2870;
extern UnkStruct_D_01E94C40 D_01E94C40;
extern UnkStruct_D_01E9B4CC D_01E9B4CC;
extern CB3ErrorPage D_01E95B4C;
extern "C" void Prepare__26CB3OnlineSelectPersonaPageFPc(void *, char*, CB3OnlineLoginToLobbyState *);  // CB3OnlineSelectPersonaPage::Prepare(char*), passed 1 more argument(s) [G]
extern "C" char * strcpy(char *, const char *);
extern "C" void Prepare__24CB3OnlineSelectLoginPageFv(void *, EB3MenuFlowFSMEvents, CB3OnlineLoginToLobbyState *);  // CB3OnlineSelectLoginPage::Prepare(), passed 2 more argument(s) [G]

// CB3OnlineLoginToLobbyState::HandleLoggingIntoServerEvents(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLoginToLobbyState.cpp.
// 0x0034B800
void CB3OnlineLoginToLobbyState::HandleLoggingIntoServerEvents(EB3MenuFlowFSMEvents p0)
{
    switch (p0) {
    case 19:
        field_B4 = 4;
        D_01E9B534.field_0 = 0;
        if (field_AC != 0) {
            Prepare__26CB3OnlineSelectPersonaPageFPc(&D_01EA2870, (char*)((char *)this + 0x74), this);
        } else {
            D_01EA2878.field_0 = D_01E9B792.field_0;
            for (int i = 0; (i < D_01E9B792.field_0); i++) {
                strcpy((char *)((char *)&D_01E94C40.field_0[i] + 0xDC3C), (const char *)((char *)((char *)&D_01E94C40 + (i << 4)) + 0x6B04));
            }
            D_01EA2870.Prepare(0);
        }
        break;
    case 23:
        field_B4 = 1;
        Prepare__24CB3OnlineSelectLoginPageFv(&D_01E9B4CC, p0, this);
        break;
    case 22:
        field_B4 = 3;
        switch (field_B0) {
        case 0:
            break;
        case -5:
            D_01E95B4C.Prepare((EGlobalStrings)82, (EGlobalStrings)111, (EB3MessageBoxType)2);
            break;
        case -6:
            D_01E95B4C.Prepare((EGlobalStrings)82, (EGlobalStrings)112, (EB3MessageBoxType)2);
            break;
        case -12:
            D_01E95B4C.Prepare((EGlobalStrings)82, (EGlobalStrings)111, (EB3MessageBoxType)2);
            break;
        default:
            D_01E95B4C.Prepare((EGlobalStrings)82, (EGlobalStrings)113, (EB3MessageBoxType)2);
            break;
        }
        break;
    default:
        break;
    }
}
