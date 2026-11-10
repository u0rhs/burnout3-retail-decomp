// func_0036BD90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool r tested plainly (!r / else if (r)): daddiu without andi).


// lifter variant 0
// func_0036BD90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};
enum EGlobalStrings {};

class CB3BuddyDisplayComponent;
class CB3OnScreenKeyboardComponent;
struct UnkStruct_0036BD90_3;
struct UnkStruct_0036BD90_5;
struct UnkStruct_0036BD90_t3;
struct UnkStruct_D_004C8158;
struct UnkStruct_D_004C8160;
struct UnkStruct_D_004C8168;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_00665ECE;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E3D460;
struct UnkStruct_D_01E8970C;
struct UnkStruct_D_01E89716;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E8CBCC;
struct UnkStruct_D_01E8D67A;
struct UnkStruct_D_01E8EAF8;
struct UnkStruct_D_01E8EB02;
struct UnkStruct_D_01E90240;

class CB3BuddyDisplayComponent {
public:
    void SetFocus(bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);
    void SetAllowableCharacters(EGlobalStrings);
    void SetDisplayText(unsigned short*, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3CD44 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual int vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual int vfunc_D8();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665ECE {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036BD90_3 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_0036BD90_t3 {
    unsigned char pad_0[0x14];
    char field_14[0x20];
    unsigned char field_34;
    unsigned char pad_35[0x1F];
    int field_54;
    int field_58;
    unsigned char field_5C[0x70];
    int field_CC;
    unsigned char pad_D0[0x54];
    int field_124;
    int field_128;
};

struct UnkStruct_0036BD90_5 {
    unsigned char pad_0[0x3C];
    int field_3C;
    unsigned char pad_40[0x28];
    int field_68;
    unsigned char pad_6C[0x6C];
    int field_D8;
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

struct UnkStruct_D_01E8CBCC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C8168 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
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

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_00665ECE D_00665ECE;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8D67A D_01E8D67A;
extern UnkStruct_D_01E89716 D_01E89716;
extern UnkStruct_D_01E8970C D_01E8970C;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E3D460 D_01E3D460;
extern UnkStruct_D_01E8CBCC D_01E8CBCC;
extern UnkStruct_D_004C8168 D_004C8168;
extern UnkStruct_D_01E90240 D_01E90240;
extern CB3BuddyDisplayComponent D_01E8D670;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_004C8158 D_004C8158;
extern UnkStruct_D_004C8160 D_004C8160;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_0051BA44 D_0051BA44;

extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void Prepare__24CB3BuddyDisplayComponentFv(void *, int, int);  // CB3BuddyDisplayComponent::Prepare(), passed 2 more argument(s) [G]
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);  // CB3PromptsComponent::SetCurrentPrompts(unsigned int,unsigned int)
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" int func_00271A00(void *, int);


// [G] inlined helper (name unknown): the field_CC=2 restore sequence (as func_0036C370's n0 != 0 arm)
static inline void func_0036BD90_inl(UnkStruct_0036BD90_t3 * self)
{
    self->field_CC = 2;
    if (D_01E8D67A.field_0 == 0) {
        Prepare__24CB3BuddyDisplayComponentFv(&D_01E8D670, self->field_124, self->field_128);
    }
    D_01E8D670.SetFocus(1);
    if (D_01E89716.field_0 != 0) {
        ((UnkStruct_D_01E8970C *)&D_01E8970C)->vfunc_C();
    }
    if (D_01E8EB02.field_0 == 0) {
        Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C8158, &D_004C8160, self->field_5C, 272.0f);
    }
    unsigned long v = 0x105 | ((unsigned long)4 << 32);
    if (D_01E3D460.field_0 == 6) {
        v |= (unsigned long)2 << 32;
    } else {
        v |= (unsigned long)1 << 32;
    }
    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, v, 3);
}

// 0x0036BD90
extern "C" int func_0036BD90(int n0, char * p0, int p1, int p2, int p3, int p4, int p5, UnkStruct_0036BD90_t3 * p6)
{
    int b = (p5 & 16) != 0;
    if (n0 == 0) {
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
    }
    bool r;
    if ((unsigned char)n0 == 0 || p3 == 0 || (b && D_00665ECE.field_0 != 0) || !(b || D_00665ECE.field_0 != 0)) {
        r = 1;
    } else {
        r = 0;
    }
    if (!r) {
        n0 = 0;
    }
    if (n0 != 0 && p3 > 0) {
        strncpy(p6->field_14, p0, 32);
        p6->field_54 = p3;
        p6->field_58 = p2;
        if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D8() != 0) {
            if (p3 == ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_68()) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                func_0036BD90_inl(p6);
                return 1;
            }
            ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_3C();
        }
        if (p4 != 0) {
            p6->field_CC = 6;
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            D_01E899C0.Show(1, 0);
            D_01E899C0.SetAllowableCharacters((EGlobalStrings)3160);
            D_01E8CBCC.field_0 = 17;
            D_01E899C0.SetDisplayText((unsigned short *)func_00271A00(&D_0051BA44, 2495), 1);
        } else {
            p6->field_34 = 0;
            p6->field_CC = 5;
        }
    } else if (n0 != 0 && p2 > 0) {
        strncpy(p6->field_14, (const char *)&D_004C8168, 32);
        p6->field_58 = p2;
        p6->field_34 = 0;
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)31, 0);
    } else if (r) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 26, 0, 0);
    } else {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        if (b) {
            func_0032D080(&D_01E898E8, 2, 2877, 0, 0);
        } else {
            func_0032D080(&D_01E898E8, 2, 2876, 0, 0);
        }
    }
    return 1;
}
