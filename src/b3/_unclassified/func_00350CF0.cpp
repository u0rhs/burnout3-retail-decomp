// Hand-written; the lifter refused it (Cell operator!= inline; ld/sd copy via unsigned long pun [G]).

class CB3OnScreenKeyboardCell { public: int field_0; int field_4;
    bool operator!=(const CB3OnScreenKeyboardCell &o) const { int b = o.field_4; bool r = field_0 != o.field_0; if (!r) r = field_4 != b; return r; } };
struct UnkStruct_kAccents { CB3OnScreenKeyboardCell c; int pad[2]; };
extern const UnkStruct_kAccents kB3OnScreenKeyboardAccentsKey;
class CB3OnScreenKeyboardComponent {
public:
    void HighlightKey(CB3OnScreenKeyboardCell, bool);
    void PressKey(CB3OnScreenKeyboardCell);

    unsigned char pad_0[0x10];
    CB3OnScreenKeyboardCell field_10;
};
// 0x00350CF0
extern "C" void func_00350CF0(CB3OnScreenKeyboardComponent *self)
{
    unsigned long kk = *(const unsigned long *)&kB3OnScreenKeyboardAccentsKey;
    self->PressKey(kB3OnScreenKeyboardAccentsKey.c);
    if (self->field_10 != kB3OnScreenKeyboardAccentsKey.c) {
        self->HighlightKey(*(CB3OnScreenKeyboardCell *)&kk, false);
    }
}
