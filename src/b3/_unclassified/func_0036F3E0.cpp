// func_0036F3E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (64-bit prompt value built as v = 0x105 | 4<<32; v |= n<<32 (sibling func_0036C370 shape), SetCurrentPrompts declared with unsigned long).

// lifter variant 0
// func_0036F3E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3BuddyDisplayComponent;
class CB3OnScreenKeyboardComponent;
struct UnkStruct_0036F3E0;
struct UnkStruct_0036F3E0_6;
struct UnkStruct_D_004C8158;
struct UnkStruct_D_004C8160;
struct UnkStruct_D_01E3D460;
struct UnkStruct_D_01E8970C;
struct UnkStruct_D_01E89716;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8D67A;
struct UnkStruct_D_01E8EAF8;
struct UnkStruct_D_01E8EB02;

class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3BuddyDisplayComponent {
public:
    void SetFocus(bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D67A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89716 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8970C {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8EB02 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D460 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036F3E0_6 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01E8EAF8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C8158 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C8160 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036F3E0 {
    unsigned char pad_0[0xCC];
    int field_CC;
    unsigned char pad_D0[0x54];
    int field_124;
    int field_128;
};

extern UnkStruct_D_01E8D67A D_01E8D67A;
extern UnkStruct_D_01E89716 D_01E89716;
extern UnkStruct_D_01E8970C D_01E8970C;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E3D460 D_01E3D460;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern CB3BuddyDisplayComponent D_01E8D670;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_004C8158 D_004C8158;
extern UnkStruct_D_004C8160 D_004C8160;
extern UnkStruct_D_01E89800 D_01E89800;

extern "C" void Prepare__24CB3BuddyDisplayComponentFv(void *, int, int);  // CB3BuddyDisplayComponent::Prepare(), passed 2 more argument(s) [G]
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);  // CB3PromptsComponent::SetCurrentPrompts(unsigned int,unsigned int)
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);

// 0x0036F3E0
extern "C" void func_0036F3E0(UnkStruct_0036F3E0 * self)
{
    switch (self->field_CC) {
    case 7:
        D_01E899C0.Show(0, 0);
        self->field_CC = 2;
        if (D_01E8D67A.field_0 == 0) {
            Prepare__24CB3BuddyDisplayComponentFv(&D_01E8D670, self->field_124, self->field_128);
        }
        D_01E8D670.SetFocus(1);
        if (D_01E89716.field_0 != 0) {
            ((UnkStruct_D_01E8970C *)&D_01E8970C)->vfunc_C();
        }
        if (D_01E8EB02.field_0 == 0) {
            Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C8158, &D_004C8160, ((char *)self + 0x5C), 272.0f);
        }
        unsigned long v5 = 0x105 | ((unsigned long)4 << 32);
        if (D_01E3D460.field_0 == 6) {
            v5 |= (unsigned long)2 << 32;
        } else {
            v5 |= (unsigned long)1 << 32;
        }
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, v5, 3);
        break;
    case 9:
        D_01E899C0.Show(0, 0);
        self->field_CC = 2;
        if (D_01E8D67A.field_0 == 0) {
            Prepare__24CB3BuddyDisplayComponentFv(&D_01E8D670, self->field_124, self->field_128);
        }
        D_01E8D670.SetFocus(1);
        if (D_01E89716.field_0 != 0) {
            ((UnkStruct_D_01E8970C *)&D_01E8970C)->vfunc_C();
        }
        if (D_01E8EB02.field_0 == 0) {
            Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C8158, &D_004C8160, ((char *)self + 0x5C), 272.0f);
        }
        unsigned long v12 = 0x105 | ((unsigned long)4 << 32);
        if (D_01E3D460.field_0 == 6) {
            v12 |= (unsigned long)2 << 32;
        } else {
            v12 |= (unsigned long)1 << 32;
        }
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, v12, 3);
        break;
    }
}
