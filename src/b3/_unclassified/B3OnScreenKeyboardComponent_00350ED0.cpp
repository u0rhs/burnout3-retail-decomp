// CB3OnScreenKeyboardComponent::SelectShift() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (sibling of SelectSymbols).

class CB3OnScreenKeyboardCell { public: int field_0; int field_4;
    bool operator!=(const CB3OnScreenKeyboardCell &o) const { int b = o.field_4; bool r = field_0 != o.field_0; if (!r) r = field_4 != b; return r; } };
struct UnkStruct_kAlpha { CB3OnScreenKeyboardCell c; int pad[2]; };
extern const UnkStruct_kAlpha kB3OnScreenKeyboardShiftKey;
class CB3OnScreenKeyboardComponent {
public:
    void SelectShift();
    void HighlightKey(CB3OnScreenKeyboardCell, bool);
    void PressKey(CB3OnScreenKeyboardCell);
    unsigned char pad_0[0x10];
    CB3OnScreenKeyboardCell field_10;
};
// 0x00350ED0
void CB3OnScreenKeyboardComponent::SelectShift()
{
    unsigned long kk = *(const unsigned long *)&kB3OnScreenKeyboardShiftKey;
    PressKey(kB3OnScreenKeyboardShiftKey.c);
    if (field_10 != kB3OnScreenKeyboardShiftKey.c) {
        HighlightKey(*(CB3OnScreenKeyboardCell *)&kk, false);
    }
}
