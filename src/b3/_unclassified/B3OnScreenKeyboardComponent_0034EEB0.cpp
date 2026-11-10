// CB3OnScreenKeyboardComponent::HighlightKey(CB3OnScreenKeyboardCell,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (v299: goto-form out-of-line arms + scoped opt_repositioncode off [G], compiler-chosen SetA stand-in [L] N185, mgr const ptr).

// v299: grid keys [5][15] of 0x90 bytes (text colour +0x20, box colour +0x50) [G] layout from the strides; arrow keys separate.
#include "b3/GtMathPs2.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
using namespace GtMathPs2;

class CB3OnScreenKeyboardCell { public: int field_0; int field_4;
    bool operator==(const CB3OnScreenKeyboardCell &o) const { int b = o.field_4; bool r = field_0 == o.field_0; if (r) r = field_4 == b; return r; } };
struct UnkStruct_kKey { CB3OnScreenKeyboardCell c; int pad[2]; };
extern UnkStruct_kKey kB3OnScreenKeyboardShiftKey;
extern UnkStruct_kKey kB3OnScreenKeyboardCapsLockKey;
extern UnkStruct_kKey kB3OnScreenKeyboardLeftArrowKey;
extern UnkStruct_kKey kB3OnScreenKeyboardRightArrowKey;
extern UnkStruct_kKey kB3OnScreenKeyboardBackspaceKey;
extern UnkStruct_kKey kB3OnScreenKeyboardSpaceKey;
extern UnkStruct_kKey kB3OnScreenKeyboardDoneKey;
extern CGtV4d kB3OnScreenKeyboardSelectedBoxColour;
extern CGtV4d kB3OnScreenKeyboardUnSelectedBoxColour;
extern CB3MenuPageManager D_01E90240;
struct UnkStruct_0034EEB0_key {
    unsigned char pad_0[0x20];
    CGtV4d field_20;
    unsigned char pad_30[0x20];
    CGtV4d field_50;
    unsigned char pad_60[0x30];
};
// [L] N185: stands in for CGtV4d::SetA(float) on a compiler-chosen scalar register (retail $vf3/$vf2)
static inline void func_0034EEB0_inl1(CGtV4d &v, float a) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(a)); asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
class CB3OnScreenKeyboardComponent {
public:
    void HighlightKey(CB3OnScreenKeyboardCell, bool);
    unsigned char pad_0[0x18];
    unsigned char field_18;
    unsigned char field_19;
    unsigned char pad_1A[0x5D0 - 0x1A];
    UnkStruct_0034EEB0_key field_5D0[5][15];
    CGtV4d field_3000;
    unsigned char pad_3010[0x10];
    CGtV4d field_3020;
    CGtV4d field_3030;
    CGtV4d field_3040;
    unsigned char pad_3050[0x10];
    CGtV4d field_3060;
    unsigned char pad_3070[0x10];
    unsigned char field_3080[5][15];
};
// N182: [G] scoped to this function -- retail lays the out-of-line arms in source order (onleft, onright, shift, caps, offleft, offright, dim)
#pragma push
#pragma opt_repositioncode off
// 0x0034EEB0
void CB3OnScreenKeyboardComponent::HighlightKey(CB3OnScreenKeyboardCell key, bool on)
{
    CB3MenuPageManager *const mgr = &D_01E90240;
    if (key.field_0 == kB3OnScreenKeyboardBackspaceKey.c.field_0 && key.field_4 >= kB3OnScreenKeyboardBackspaceKey.c.field_4 && key.field_4 < kB3OnScreenKeyboardLeftArrowKey.c.field_4)
        key.field_4 = kB3OnScreenKeyboardBackspaceKey.c.field_4;
    if (key.field_0 == kB3OnScreenKeyboardDoneKey.c.field_0 && key.field_4 >= kB3OnScreenKeyboardDoneKey.c.field_4 && key.field_4 < kB3OnScreenKeyboardLeftArrowKey.c.field_4)
        key.field_4 = kB3OnScreenKeyboardDoneKey.c.field_4;
    if (key.field_0 == kB3OnScreenKeyboardSpaceKey.c.field_0 && key.field_4 >= kB3OnScreenKeyboardSpaceKey.c.field_4 && key.field_4 < kB3OnScreenKeyboardDoneKey.c.field_4)
        key.field_4 = kB3OnScreenKeyboardSpaceKey.c.field_4;
    if (on) {
        if (key == kB3OnScreenKeyboardLeftArrowKey.c) goto onleft;
        if (key == kB3OnScreenKeyboardRightArrowKey.c) goto onright;
        field_5D0[key.field_0][key.field_4].field_50 = kB3OnScreenKeyboardSelectedBoxColour;
        field_5D0[key.field_0][key.field_4].field_20 = mgr->field_0[1];
    } else {
        if (key == kB3OnScreenKeyboardShiftKey.c) goto shift;
caps:
        if (key == kB3OnScreenKeyboardCapsLockKey.c) goto capsl;
left:
        if (key == kB3OnScreenKeyboardLeftArrowKey.c) goto offleft;
        if (key == kB3OnScreenKeyboardRightArrowKey.c) goto offright;
        field_5D0[key.field_0][key.field_4].field_50 = kB3OnScreenKeyboardUnSelectedBoxColour;
        field_5D0[key.field_0][key.field_4].field_20 = mgr->field_0[0];
    }
tail:
    if (field_3080[key.field_0][key.field_4] == 0) goto dim;
ret:
    return;
onleft:
    field_3000 = kB3OnScreenKeyboardSelectedBoxColour;
    field_3020 = mgr->field_0[1];
    goto tail;
onright:
    field_3040 = kB3OnScreenKeyboardSelectedBoxColour;
    field_3060 = mgr->field_0[1];
    goto tail;
shift:
    if (!field_18) goto caps;
            field_5D0[key.field_0][key.field_4].field_50 = kB3OnScreenKeyboardSelectedBoxColour;
            func_0034EEB0_inl1(field_5D0[key.field_0][key.field_4].field_50, 0.25f);
            field_5D0[key.field_0][key.field_4].field_20 = mgr->field_0[1];
            func_0034EEB0_inl1(field_5D0[key.field_0][key.field_4].field_20, 0.5f);
    goto tail;
capsl:
    if (!field_19) goto left;
            field_5D0[key.field_0][key.field_4].field_50 = kB3OnScreenKeyboardSelectedBoxColour;
            func_0034EEB0_inl1(field_5D0[key.field_0][key.field_4].field_50, 0.25f);
            field_5D0[key.field_0][key.field_4].field_20 = mgr->field_0[1];
            func_0034EEB0_inl1(field_5D0[key.field_0][key.field_4].field_20, 0.5f);
    goto tail;
offleft:
    field_3000 = kB3OnScreenKeyboardUnSelectedBoxColour;
    field_3020 = mgr->field_0[0];
    goto tail;
offright:
    field_3040 = kB3OnScreenKeyboardUnSelectedBoxColour;
    field_3060 = mgr->field_0[0];
    goto tail;
dim:
    func_0034EEB0_inl1(field_5D0[key.field_0][key.field_4].field_20, 0.25f);
    goto ret;
}
#pragma pop
