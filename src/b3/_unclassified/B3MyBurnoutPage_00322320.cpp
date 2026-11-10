// CB3MyBurnoutPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MyBurnoutPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (parkfix: tool-bug park fixed (N213)).

// CB3MyBurnoutPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MyBurnoutPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a245: re-queue a112o (0 diff); earlier park was jtbl retarget false alarm?).

#include "b3/gamesource/Menu/DebugMenu/Pages/B3MyBurnoutPage.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
extern CB3MenuPageManager D_01E90240;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(CB3MenuPageManager *, int, int);
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90424 D_01E90424;
struct UnkStruct_D_004F50C0_Pad {
    unsigned char pad0[0x2C];
    short field_2C;
    unsigned char pad2E[0xA];
    short field_38;
    unsigned char pad3A[0xA];
    short field_44;
    unsigned char pad46[0x16];
    short field_5C;
    unsigned char pad5E[300 - 0x5E];
};
struct UnkStruct_D_004F50C0 {
    unsigned char pad0[0xD48];
    UnkStruct_D_004F50C0_Pad pads[4];
};
extern UnkStruct_D_004F50C0 D_004F50C0;
struct UnkStruct_D_004F6061 {
    signed char value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_004F6061 D_004F6061;
// 0x00322320
void CB3MyBurnoutPage::Update()
{
    if (D_01E90424.value == 5) {
        UnkStruct_D_004F50C0_Pad *pad = &D_004F50C0.pads[D_004F6061.value];
        if (pad->field_44 != 0) {
            field_4 = field_80C.field_0;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 1, 0);
            return;
        } else if (pad->field_5C != 0) {
            D_01E90240.StartLeadOutFore((EB3MenuFlowFSMEvents)3, false);
            return;
        } else {
            int v;
            if (pad->field_2C != 0 && func_00319360(&field_80C)) {
                v = field_80C.field_0;
            } else if (pad->field_38 == 0) {
                return;
            } else if (func_00319330(&field_80C)) {
                v = field_80C.field_0;
            } else {
                return;
            }
            field_4 = v;
            func_00321870(this, field_4);
        }
    }
}
