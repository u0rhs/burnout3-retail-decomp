// CB3OnScreenKeyboardComponent::Select() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (wirefix: PressKey arg type is CB3OnScreenKeyboardCell).

struct CB3OnScreenKeyboardCell { int field_0; int field_4; };
class CB3OnScreenKeyboardComponent { public: void Select(); void PressKey(CB3OnScreenKeyboardCell); unsigned char pad_0[0x10]; CB3OnScreenKeyboardCell field_10; };
// 0x00350F70
void CB3OnScreenKeyboardComponent::Select() { PressKey(field_10); }
