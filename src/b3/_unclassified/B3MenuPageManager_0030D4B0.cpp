// CB3MenuPageManager::ImmediateLeadOut(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuPageManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a165 tiny).

struct UnkStruct_a165_mp { unsigned char pad_0[0x1DC]; int field_1DC; int field_1E0; int field_1E4; int field_1E8; int field_1EC; unsigned char pad_1F0[0x180F]; unsigned char field_19FF; };
struct UnkStruct_a165_D { signed char v; unsigned char pad[0x100]; };
extern UnkStruct_a165_D D_004F6060;
extern "C" void ImmediateLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(UnkStruct_a165_mp *self, int ev) {
 self->field_1E8 = ev; self->field_1DC = 0; self->field_1E0 = 0; self->field_19FF = 0; self->field_1E4 = 3;
 if (self->field_1E8 < 3) self->field_1EC = D_004F6060.v; }
