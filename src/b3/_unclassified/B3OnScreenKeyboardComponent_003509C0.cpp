// CB3OnScreenKeyboardComponent::SelectNextRight() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (SelectNextRight).

class CB3OnScreenKeyboardCell { public: int field_0; int field_4;
    bool operator==(const CB3OnScreenKeyboardCell &o) const { int b = o.field_4; bool r = field_0 == o.field_0; if (r) r = field_4 == b; return r; } };
struct UnkStruct_kKey { CB3OnScreenKeyboardCell c; int pad[2]; };
extern const UnkStruct_kKey kB3OnScreenKeyboardBlankKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardBackspaceKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardDoneKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardSpaceKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardLeftArrowKey;
class CB3OnScreenKeyboardComponent {
public:
    void SelectNextRight();
    void SelectNextLeft();
    void HighlightKey(CB3OnScreenKeyboardCell, bool);
    unsigned char pad_0[0x10];
    CB3OnScreenKeyboardCell field_10;
};
// 0x003509C0
void CB3OnScreenKeyboardComponent::SelectNextRight()
{
    HighlightKey(field_10, false);
    if (field_10.field_0 == kB3OnScreenKeyboardBackspaceKey.c.field_0 && field_10.field_4 >= kB3OnScreenKeyboardBackspaceKey.c.field_4 && field_10.field_4 < kB3OnScreenKeyboardLeftArrowKey.c.field_4) {
        field_10.field_4 = kB3OnScreenKeyboardLeftArrowKey.c.field_4;
    } else if (field_10.field_0 == kB3OnScreenKeyboardDoneKey.c.field_0 && field_10.field_4 >= kB3OnScreenKeyboardDoneKey.c.field_4 && field_10.field_4 < kB3OnScreenKeyboardLeftArrowKey.c.field_4) {
        field_10.field_4 = kB3OnScreenKeyboardLeftArrowKey.c.field_4;
    } else if (field_10.field_0 == kB3OnScreenKeyboardSpaceKey.c.field_0 && field_10.field_4 >= kB3OnScreenKeyboardSpaceKey.c.field_4 && field_10.field_4 < kB3OnScreenKeyboardDoneKey.c.field_4) {
        field_10.field_4 = kB3OnScreenKeyboardDoneKey.c.field_4;
    } else {
        field_10.field_4 = (field_10.field_4 + 1) % 15;
        if (field_10 == kB3OnScreenKeyboardBlankKey.c) {
            field_10.field_4 = (field_10.field_4 + 1) % 15;
        }
        if (field_10.field_4 == 0) {
            field_10.field_4 = 1;
        }
    }
    HighlightKey(field_10, true);
}
