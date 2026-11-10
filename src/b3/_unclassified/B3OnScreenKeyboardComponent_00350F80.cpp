// CB3OnScreenKeyboardComponent::Show(bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a149: PressHL inline, named c1/c2 for ctrl, goto fin from tail arms, unsigned field_3218).

class CB3OnScreenKeyboardCell { public: int field_0; int field_4;
    bool operator!=(const CB3OnScreenKeyboardCell &o) const { int b = o.field_4; bool r = field_0 != o.field_0; if (!r) r = field_4 != b; return r; } };
struct UnkStruct_kKey { CB3OnScreenKeyboardCell c; int pad[2]; };
extern const UnkStruct_kKey kB3OnScreenKeyboardCapsLockKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardShiftKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardDoneKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardAlphabetHelpKey;
struct UnkStruct_D_01E7AA38_a149 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_01E7AA38_a149 D_01E7AA38;
struct UnkStruct_D_01E90430_a149 { void *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90430_a149 D_01E90430;
struct UnkStruct_D_01E98490_a149 { unsigned char pad[0x10]; };
extern UnkStruct_D_01E98490_a149 D_01E98490;
struct UnkStruct_D_01E90424_a149 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90424_a149 D_01E90424;
struct UnkStruct_D_01E8980A_a149 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_01E8980A_a149 D_01E8980A;
struct UnkStruct_D_01E89810_a149 { unsigned long field_0; int field_8; int pad_C; };
extern UnkStruct_D_01E89810_a149 D_01E89810;
struct UnkStruct_D_01E89800_a149 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_01E89800_a149 D_01E89800;
struct UnkStruct_D_004F5518_a149 { void *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004F5518_a149 D_004F5518;
extern "C" {
unsigned char GetLEDState__25CGtInputDevicePS2KeyboardFv(void *);
bool IsControlPressed__25CGtInputDevicePS2KeyboardF18EGtVirtualKeyCodes(void *, int);
void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
bool func_0031ECD0(void *, unsigned long, int);
void RecalculateSize__16CGt2dObjectTableFv(void *);
void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short *, const void *, const void *);
}
struct UnkStruct_a149_cellA { void *field_0; int pad_4; int pad_8; };
struct UnkStruct_a149_cellB { unsigned char pad_0; unsigned char field_1; unsigned char pad_2[0x8E]; };
class CB3OnScreenKeyboardComponent {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    void Show(bool, bool);
    bool PrepareObjects(bool);
    void PressKey(CB3OnScreenKeyboardCell);
    void HighlightKey(CB3OnScreenKeyboardCell, bool);
    unsigned char pad_4[6];
    unsigned char field_A;
    unsigned char pad_B;
    unsigned char pad_C[4];
    CB3OnScreenKeyboardCell field_10;
    unsigned char pad_18;
    unsigned char field_19;
    unsigned char pad_1A[0x2E];
    void *field_48;
    void *field_4C;
    unsigned char pad_50[0xF0];
    UnkStruct_a149_cellA field_140[5][15];
    unsigned char pad_4C4[0x18C];
    UnkStruct_a149_cellB field_650[5][15];
    unsigned char pad_3080[0x190];
    unsigned long field_3210;
    unsigned int field_3218;
};
static inline void PressHL(CB3OnScreenKeyboardComponent *self, const UnkStruct_kKey &k)
{
    unsigned long kk = *(const unsigned long *)&k;
    self->PressKey(k.c);
    if (self->field_10 != k.c) self->HighlightKey(*(CB3OnScreenKeyboardCell *)&kk, false);
}
// 0x00350F80
void CB3OnScreenKeyboardComponent::Show(bool show, bool top)
{
    D_01E7AA38.field_0 = !show;
    if (show) {
        if (field_A != 0) vfunc_C();
        PrepareObjects(top);
        if (D_01E90430.field_0 == &D_01E98490) {
            field_140[kB3OnScreenKeyboardAlphabetHelpKey.c.field_0][kB3OnScreenKeyboardAlphabetHelpKey.c.field_4].field_0 = 0;
            field_650[kB3OnScreenKeyboardAlphabetHelpKey.c.field_0][kB3OnScreenKeyboardAlphabetHelpKey.c.field_4].field_1 = 0;
        } else {
            field_140[kB3OnScreenKeyboardAlphabetHelpKey.c.field_0][kB3OnScreenKeyboardAlphabetHelpKey.c.field_4].field_0 = (void *)&RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            field_650[kB3OnScreenKeyboardAlphabetHelpKey.c.field_0][kB3OnScreenKeyboardAlphabetHelpKey.c.field_4].field_1 = 1;
        }
        bool caps = (GetLEDState__25CGtInputDevicePS2KeyboardFv(&D_004F5518) & 4) == 4;
        bool ctrl = true;
        bool c1 = IsControlPressed__25CGtInputDevicePS2KeyboardF18EGtVirtualKeyCodes(&D_004F5518, 0x65);
        if (!c1) {
            bool c2 = IsControlPressed__25CGtInputDevicePS2KeyboardF18EGtVirtualKeyCodes(&D_004F5518, 0x69);
            if (!c2) ctrl = false;
        }
        if (ctrl) PressHL(this, kB3OnScreenKeyboardShiftKey);
        if (caps && field_19 == 0) PressHL(this, kB3OnScreenKeyboardCapsLockKey);
        RecalculateSize__16CGt2dObjectTableFv(field_4C);
        field_10.field_0 = kB3OnScreenKeyboardDoneKey.c.field_0;
        field_10.field_4 = kB3OnScreenKeyboardDoneKey.c.field_4;
        HighlightKey(field_10, true);
        if (D_01E8980A.field_0 != 0) {
            field_3210 = D_01E89810.field_0;
            field_3218 = D_01E89810.field_8;
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x40000104, 0xF);
        } else {
            field_3210 = 0;
            field_3218 = 0;
            func_0031ECD0(&D_01E89800, 0x40000104, 0xF);
        }
        goto fin;
    }
    HighlightKey(field_10, false);
    if (field_A != 0) vfunc_C();
    if (D_01E90424.field_0 == 5) {
        if (*(const unsigned long *)&field_3210 == 0 && field_3218 == 0) {
            if (D_01E8980A.field_0 != 0) { ((UnkStruct_D_01E89800_a149 *)&D_01E89800)->vfunc_C(); goto fin; }
        } else {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, field_3210, field_3218);
            goto fin;
        }
    }
fin:
    return;
}
