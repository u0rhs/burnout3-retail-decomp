// CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuPageManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (D_004E08B0 is a .lit4 float (0.4f): the literal lets lwc1 schedule above sd ra (same as StartLeadOutFore)).

#include "b3/classes/CB3HUDSoundManager.h"
struct UnkStruct_0030D560 {
    unsigned char pad_0[0x1DC];
    float field_1DC;
    unsigned char pad_1E0[0x4];
    int field_1E4;
    int field_1E8;
    int field_1EC;
    unsigned char pad_1F0[0x180F];
    unsigned char field_19FF;
};
struct UnkStruct_D_004F6060 { signed char field_0; unsigned char pad_1[0xF]; };
extern CB3HUDSoundManager D_01E7A800;
extern UnkStruct_D_004F6060 D_004F6060;

// 0x0030D560
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(UnkStruct_0030D560 *self, int ev, unsigned char b)
{
    self->field_1E8 = ev;
    self->field_19FF = b;
    self->field_1DC = 0.4f;
    self->field_1E4 = 3;
    if (self->field_1E8 < 3) {
        self->field_1EC = D_004F6060.field_0;
    }
    D_01E7A800.FESelect();
}
