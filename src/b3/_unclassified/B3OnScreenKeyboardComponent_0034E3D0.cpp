// CB3OnScreenKeyboardComponent::KeyboardEventCallback(int,int,int,int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a149: static callback; PressHL inline (kk pun), caps test as (m==0&&f19!=0)||(m!=0&&f19==0)).

#include "b3/classes/CB3MenuFlowFSM.h"
class CB3OnScreenKeyboardCell { public: int field_0; int field_4;
    bool operator!=(const CB3OnScreenKeyboardCell &o) const { int b = o.field_4; bool r = field_0 != o.field_0; if (!r) r = field_4 != b; return r; } };
struct UnkStruct_kKey { CB3OnScreenKeyboardCell c; int pad[2]; };
extern const UnkStruct_kKey kB3OnScreenKeyboardCapsLockKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardShiftKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardLeftArrowKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardRightArrowKey;
struct UnkStruct_D_01E8E8AA { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_01E8E8AA D_01E8E8AA;
extern CB3MenuFlowFSM D_01EA2970;
struct UnkStruct_D_01E7A800 { unsigned char pad[0x100]; };
extern UnkStruct_D_01E7A800 D_01E7A800;
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
class CB3OnScreenKeyboardComponent {
public:
    static void KeyboardEventCallback(int, int, int, int, void *);
    void HighlightKey(CB3OnScreenKeyboardCell, bool);
    void PressKey(CB3OnScreenKeyboardCell);
    void UnHighlightKeys();
    unsigned char pad_0[0x10];
    CB3OnScreenKeyboardCell field_10;
    unsigned char pad_18;
    unsigned char field_19;
    unsigned char pad_1A[0x2E];
    void *field_48;
};
static inline void PressHL(CB3OnScreenKeyboardComponent *self, const UnkStruct_kKey &k)
{
    unsigned long kk = *(const unsigned long *)&k;
    self->PressKey(k.c);
    if (self->field_10 != k.c) self->HighlightKey(*(CB3OnScreenKeyboardCell *)&kk, false);
}
// 0x0034E3D0
void CB3OnScreenKeyboardComponent::KeyboardEventCallback(int type, int key, int mods, int p3, void *p)
{
    CB3OnScreenKeyboardComponent *self = (CB3OnScreenKeyboardComponent *)p;
    if (D_01E8E8AA.field_0 != 0) return;
    if (key != 0x35) {
        int m = mods & 4;
        if ((m != 0 && self->field_19 == 0) || (m == 0 && self->field_19 != 0)) PressHL(self, kB3OnScreenKeyboardCapsLockKey);
    }
    if (type == 0 && self->field_48 == 0 && key != 0x25 && key != 0x24 && key != 0x54)
        D_01EA2970.ApplyEvent(0x19, 0);
    if (self->field_48 == 0) return;
    if (type == 0 && (key == 0x65 || key == 0x69)) PressHL(self, kB3OnScreenKeyboardShiftKey);
    if (type == 1 && (key == 0x65 || key == 0x69)) PressHL(self, kB3OnScreenKeyboardShiftKey);
    if (type == 0 && key == 0x35 && (mods & 4) != 0 && self->field_19 == 0) PressHL(self, kB3OnScreenKeyboardCapsLockKey);
    if (type == 1 && key == 0x35 && (mods & 4) == 0 && self->field_19 != 0) PressHL(self, kB3OnScreenKeyboardCapsLockKey);
    if (type == 0 || type == 2) {
        if (key == 0x4C) self->PressKey(kB3OnScreenKeyboardLeftArrowKey.c);
    }
    if (type == 1 && key == 0x4C && self->field_10 != kB3OnScreenKeyboardLeftArrowKey.c)
        self->HighlightKey(kB3OnScreenKeyboardLeftArrowKey.c, false);
    if (type == 0 || type == 2) {
        if (key == 0x4B) self->PressKey(kB3OnScreenKeyboardRightArrowKey.c);
    }
    if (type == 1 && key == 0x4B && self->field_10 != kB3OnScreenKeyboardRightArrowKey.c)
        self->HighlightKey(kB3OnScreenKeyboardRightArrowKey.c, false);
    if (type == 1 && key == 0x25) D_01EA2970.ApplyEvent(0x1A, 0);
    if (type == 1) self->UnHighlightKeys();
    if (type == 0) {
        if (key == 0x26) FEKeyboardDel__18CB3HUDSoundManagerFv(&D_01E7A800);
        else FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    }
}
