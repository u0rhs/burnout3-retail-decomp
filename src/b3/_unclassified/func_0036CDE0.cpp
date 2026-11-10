// func_0036CDE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if/else-if chain r==4/5/0 as sibling func_0036C860; bool out-param; field_108 char array, field_5C array; prompt value 0x105|4<<32 |n<<32 passed 64-bit).

// lifter variant 0
// func_0036CDE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3BuddyDisplayComponent;
class CB3HUDSoundManager;
class CGtBuddiesPS2DirtySock;
struct UnkStruct_0036CDE0;
struct UnkStruct_0036CDE0_2;
struct UnkStruct_0036CDE0_3;
struct UnkStruct_D_004C8158;
struct UnkStruct_D_004C8160;
struct UnkStruct_D_01E3D460;
struct UnkStruct_D_01E8970C;
struct UnkStruct_D_01E89716;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E8D67A;
struct UnkStruct_D_01E8EAF8;
struct UnkStruct_D_01E8EB02;

class CB3HUDSoundManager {
public:
    void FEBack();
    void FESelect();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtBuddiesPS2DirtySock {
public:
    void IsWannaBeMyBuddy(char*, bool*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3BuddyDisplayComponent {
public:
    void SetFocus(bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036CDE0_2 {
    unsigned char field_0;
};

struct UnkStruct_0036CDE0_3 {
    unsigned char pad_0[0xC];
    int field_C;
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

struct UnkStruct_0036CDE0 {
    unsigned char pad_0[0x5C];
    unsigned char field_5C[0x70];
    int field_CC;
    unsigned char pad_D0[0x38];
    char field_108[0x1C];
    int field_124;
    int field_128;
};

extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8D67A D_01E8D67A;
extern UnkStruct_D_01E89716 D_01E89716;
extern UnkStruct_D_01E8970C D_01E8970C;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E3D460 D_01E3D460;
extern CB3HUDSoundManager D_01E7A800;
extern CGtBuddiesPS2DirtySock D_01E3D390;
extern CB3BuddyDisplayComponent D_01E8D670;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_004C8158 D_004C8158;
extern UnkStruct_D_004C8160 D_004C8160;
extern UnkStruct_D_01E89800 D_01E89800;

extern "C" void _BuddyRejectCallback__24CB3OnlineBuddiesMenuPageFbPv(bool, void*);  // CB3OnlineBuddiesMenuPage::_BuddyRejectCallback(bool,void*), its address taken
extern "C" void Prepare__24CB3BuddyDisplayComponentFv(void *, int, int);  // CB3BuddyDisplayComponent::Prepare(), passed 2 more argument(s) [G]
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);  // CB3PromptsComponent::SetCurrentPrompts(unsigned int,unsigned int)
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int BuddyInviteAccept__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, void *, void *, UnkStruct_0036CDE0 *);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);

// 0x0036CDE0
extern "C" void func_0036CDE0(UnkStruct_0036CDE0 * self)
{
    bool b;
    int r = func_0032B2C0(&D_01E898E8, 0, 1);
    if (r == 4) {
        D_01E7A800.FESelect();
        D_01E3D390.IsWannaBeMyBuddy(self->field_108, &b);
        if (b) {
            if (BuddyInviteAccept__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_108, (void *)&_BuddyRejectCallback__24CB3OnlineBuddiesMenuPageFbPv, self) == 0) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                func_0032D080(&D_01E898E8, 0, 39, 15, 0);
            } else {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                func_0032D080(&D_01E898E8, 2, 41, 0, 0);
            }
        } else {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 41, 0, 0);
        }
    } else if (r == 5) {
        D_01E7A800.FEBack();
        self->field_CC = 3;
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    } else if (r == 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
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
        {
        unsigned long v = 0x105 | ((unsigned long)4 << 32);
        if (D_01E3D460.field_0 == 6) {
            v |= (unsigned long)2 << 32;
        } else {
            v |= (unsigned long)1 << 32;
        }
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, v, 3);
        }
        D_01E7A800.FESelect();
    }
}
