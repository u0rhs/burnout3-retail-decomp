// CB3OnScreenKeyboardComponent::SelectNextDown() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (sibling of SelectNextUp shape).

class CB3OnScreenKeyboardCell { public: int field_0; int field_4;
    bool operator==(const CB3OnScreenKeyboardCell &o) const { int b = o.field_4; bool r = field_0 == o.field_0; if (r) r = field_4 == b; return r; } };
struct UnkStruct_kBlank { CB3OnScreenKeyboardCell c; int pad[2]; };
extern const UnkStruct_kBlank kB3OnScreenKeyboardBlankKey;
class CB3OnScreenKeyboardComponent {
public:
    void SelectNextDown();
    void SelectNextUp();
    void HighlightKey(CB3OnScreenKeyboardCell, bool);

    unsigned char pad_0[0x10];
    CB3OnScreenKeyboardCell field_10;
};
// 0x00350830
void CB3OnScreenKeyboardComponent::SelectNextDown()
{
    HighlightKey(field_10, false);
    field_10.field_0 = (field_10.field_0 + 1) % 5;
    if (field_10 == kB3OnScreenKeyboardBlankKey.c) {
        field_10.field_0 = (field_10.field_0 + 1) % 5;
    }
    if (field_10.field_0 == 0) {
        field_10.field_0 = 1;
    }
    HighlightKey(field_10, true);
}
