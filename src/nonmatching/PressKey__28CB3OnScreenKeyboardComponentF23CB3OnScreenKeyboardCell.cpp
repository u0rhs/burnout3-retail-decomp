// NONMATCHING: PressKey__28CB3OnScreenKeyboardComponentF23CB3OnScreenKeyboardCell -- retail 340 / ours 341 instructions, 112 in changed runs
// a149: logic exact, goto form reproduces the compare/range-check shapes; remaining: out-of-line arm ORDER (retail: ctrl2,shift,caps,alpha,accents,left,right,bs,sp,table,setup; ours scrambled), ctrl 'daddiu s3,1' in beqz delay slot, sb zero,0x18 in HighlightKey jal delay slot (needs the real nested if/else shape)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

class CB3OnScreenKeyboardCell { public: int field_0; int field_4;
    bool operator==(const CB3OnScreenKeyboardCell &o) const { int b = o.field_4; bool r = field_0 == o.field_0; if (r) r = field_4 == b; return r; } };
struct UnkStruct_kKey { CB3OnScreenKeyboardCell c; int pad[2]; };
extern UnkStruct_kKey kB3OnScreenKeyboardShiftKey;
extern UnkStruct_kKey kB3OnScreenKeyboardCapsLockKey;
extern UnkStruct_kKey kB3OnScreenKeyboardAlphabetKey;
extern UnkStruct_kKey kB3OnScreenKeyboardAccentsKey;
extern UnkStruct_kKey kB3OnScreenKeyboardLeftArrowKey;
extern UnkStruct_kKey kB3OnScreenKeyboardRightArrowKey;
extern UnkStruct_kKey kB3OnScreenKeyboardBackspaceKey;
extern UnkStruct_kKey kB3OnScreenKeyboardSpaceKey;
extern UnkStruct_kKey kB3OnScreenKeyboardDoneKey;
struct UnkStruct_D_004F5518 { void *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004F5518 D_004F5518;
extern "C" {
bool IsControlPressed__25CGtInputDevicePS2KeyboardF18EGtVirtualKeyCodes(void *, int);
int Length__10CGtUnicodeFPCUs(const unsigned short *);
}
class CB3OnScreenKeyboardComponent {
public:
    void PressKey(CB3OnScreenKeyboardCell);
    void HighlightKey(CB3OnScreenKeyboardCell, bool);
    void AddCharToString(unsigned short);
    void SetupKeys(bool, bool, bool);
    void MoveCursorLeft();
    void MoveCursorRight();
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[8];
    unsigned char field_18;
    unsigned char field_19;
    bool field_1A;
    bool field_1B;
    unsigned char pad_1C[2];
    unsigned char field_1E;
    unsigned char pad_1F;
    int field_20;
    unsigned char pad_24[0x305C];
    unsigned char field_3080[5][15];
    unsigned char pad_30CB[1];
    unsigned char pad_30CC[8];
    unsigned short *field_30D4;
    unsigned char pad_30D8[4];
    unsigned short *field_30DC[5][15];
};
static inline void ClearShift(CB3OnScreenKeyboardComponent *self, bool ctrl)
{
    if (self->field_1A == 0 && self->field_18 != 0 && !ctrl) {
        self->field_18 = 0;
        self->HighlightKey(kB3OnScreenKeyboardShiftKey.c, false);
    }
}
void CB3OnScreenKeyboardComponent::PressKey(CB3OnScreenKeyboardCell key)
{
    unsigned char was = (field_19 ^ field_18) != 0;
    unsigned char s1 = field_1A;
    unsigned char s0 = field_1B;
    bool ctrl = true;
    bool c1 = IsControlPressed__25CGtInputDevicePS2KeyboardF18EGtVirtualKeyCodes(&D_004F5518, 0x65);
    if (!c1) {
        bool c2 = IsControlPressed__25CGtInputDevicePS2KeyboardF18EGtVirtualKeyCodes(&D_004F5518, 0x69);
        if (!c2) ctrl = false;
    }
    if (field_3080[key.field_0][key.field_4] == 0) return;
    if (key == kB3OnScreenKeyboardShiftKey.c) goto shift;
    if (key == kB3OnScreenKeyboardCapsLockKey.c) goto caps;
    if (key == kB3OnScreenKeyboardAlphabetKey.c) goto alpha;
    if (key == kB3OnScreenKeyboardAccentsKey.c) goto accents;
    if (key == kB3OnScreenKeyboardLeftArrowKey.c) goto left;
    if (key == kB3OnScreenKeyboardRightArrowKey.c) goto right;
    if (key.field_0 == kB3OnScreenKeyboardBackspaceKey.c.field_0) goto bs;
spc:
    if (key.field_0 == kB3OnScreenKeyboardSpaceKey.c.field_0) goto sp;
done:
    if (key.field_0 != kB3OnScreenKeyboardDoneKey.c.field_0 || key.field_4 < kB3OnScreenKeyboardDoneKey.c.field_4 || key.field_4 >= kB3OnScreenKeyboardLeftArrowKey.c.field_4) goto table;
    AddCharToString(10);
    ClearShift(this, ctrl);
join:
    if (was != (field_19 ^ field_18) || s1 != field_1A || s0 != field_1B)
        SetupKeys((field_19 ^ field_18) != 0, field_1A, field_1B);
    HighlightKey(key, true);
    return;
shift:
    field_18 = !field_18 || ctrl;
    goto join;
caps:
    field_19 = !field_19;
    goto join;
alpha:
    field_1A = !field_1A;
    field_1B = 0;
    goto join;
accents:
    field_1B = !field_1B;
    field_1A = 0;
    goto join;
left:
    if (field_C > 0) {
        MoveCursorLeft();
        field_1E = 1;
        field_20 = 0;
    }
    goto join;
right:
    {
        int n = field_C;
        if (n < Length__10CGtUnicodeFPCUs(field_30D4)) {
            MoveCursorRight();
            field_1E = 1;
            field_20 = 0;
        }
    }
    goto join;
bs:
    if (key.field_4 < kB3OnScreenKeyboardBackspaceKey.c.field_4 || key.field_4 >= kB3OnScreenKeyboardLeftArrowKey.c.field_4) goto spc;
    AddCharToString(8);
    ClearShift(this, ctrl);
    goto join;
sp:
    if (key.field_4 < kB3OnScreenKeyboardSpaceKey.c.field_4 || key.field_4 >= kB3OnScreenKeyboardDoneKey.c.field_4) goto done;
    AddCharToString(0x20);
    ClearShift(this, ctrl);
    goto join;
table:
    AddCharToString(*field_30DC[key.field_0][key.field_4]);
    ClearShift(this, ctrl);
    goto join;
}
