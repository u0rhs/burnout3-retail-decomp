// NONMATCHING: UnHighlightKeys__28CB3OnScreenKeyboardComponentFv -- retail 209 / ours 209 instructions, 6 in changed runs
// a149: logic+layout exact (209/209); 6 instrs of prologue scheduling differ (li 1/sw 0x78 placement vs lui a0/v1 for the la/bs preloads)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

class CB3OnScreenKeyboardCell { public: int field_0; int field_4;
    bool operator!=(CB3OnScreenKeyboardCell o) const { bool r = field_0 != o.field_0; if (!r) r = field_4 != o.field_4; return r; } };
struct UnkStruct_kKey { CB3OnScreenKeyboardCell c; int pad[2]; };
extern UnkStruct_kKey kB3OnScreenKeyboardBackspaceKey;
extern UnkStruct_kKey kB3OnScreenKeyboardLeftArrowKey;
extern UnkStruct_kKey kB3OnScreenKeyboardSpaceKey;
extern UnkStruct_kKey kB3OnScreenKeyboardDoneKey;
class CB3OnScreenKeyboardComponent {
public:
    void UnHighlightKeys();
    void HighlightKey(CB3OnScreenKeyboardCell, bool);
    unsigned char pad_0[0x10];
    CB3OnScreenKeyboardCell field_10;
};
void CB3OnScreenKeyboardComponent::UnHighlightKeys()
{
    CB3OnScreenKeyboardCell k;
    int la = kB3OnScreenKeyboardLeftArrowKey.c.field_4;
    int bs = kB3OnScreenKeyboardBackspaceKey.c.field_4;
    for (k.field_0 = 1; k.field_0 < 4; k.field_0++) {
        int lim = k.field_0 < 3 ? la : bs;
        for (k.field_4 = 2; k.field_4 < lim; k.field_4++) {
            if (k != field_10) HighlightKey(k, false);
        }
    }
    for (k.field_0 = 1; k.field_0 < 4; k.field_0++) {
        for (k.field_4 = 12; k.field_4 < 15; k.field_4++) {
            if (k != field_10) HighlightKey(k, false);
        }
    }
    k.field_0 = 4;
    k.field_4 = 13;
    if (k != field_10) HighlightKey(k, false);
    if (field_10.field_0 != kB3OnScreenKeyboardBackspaceKey.c.field_0 || field_10.field_4 < kB3OnScreenKeyboardBackspaceKey.c.field_4 || field_10.field_4 >= kB3OnScreenKeyboardLeftArrowKey.c.field_4)
        HighlightKey(kB3OnScreenKeyboardBackspaceKey.c, false);
    if (field_10.field_0 != kB3OnScreenKeyboardSpaceKey.c.field_0 || field_10.field_4 < kB3OnScreenKeyboardSpaceKey.c.field_4 || field_10.field_4 >= kB3OnScreenKeyboardDoneKey.c.field_4)
        HighlightKey(kB3OnScreenKeyboardSpaceKey.c, false);
    if (field_10.field_0 != kB3OnScreenKeyboardDoneKey.c.field_0 || field_10.field_4 < kB3OnScreenKeyboardDoneKey.c.field_4 || field_10.field_4 >= kB3OnScreenKeyboardLeftArrowKey.c.field_4)
        HighlightKey(kB3OnScreenKeyboardDoneKey.c, false);
}
