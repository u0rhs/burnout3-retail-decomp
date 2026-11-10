// CB3AITarget::ResetTarget() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a163 tiny).

extern "C" void ResetCornerStatus__11CB3AITargetFv(void *);
extern "C" void ClearState__24CB3AIAggressionBehaviourFv(void *);
class CB3AITarget { public: void ResetTarget(); unsigned char pad_0[0x170]; int field_170; unsigned char pad_174[0x64]; unsigned short field_1D8; unsigned char pad_1DA[0xBC]; unsigned char field_296; };
// 0x00149140
void CB3AITarget::ResetTarget() { field_1D8 = 0xFFFF; field_296 = 1; ResetCornerStatus__11CB3AITargetFv(this); ClearState__24CB3AIAggressionBehaviourFv(&field_170); }
