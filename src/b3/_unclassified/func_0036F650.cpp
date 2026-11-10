// func_0036F650 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch 7/6/9; static inline helpers for the field_CC=2 restore sequence and the inlined func_0036F3E0 body [G]; strcasecmp()==0 arm first; char buffers).

// lifter variant 0
// func_0036F650 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3BuddyDisplayComponent;
class CB3OnScreenKeyboardComponent;
struct UnkStruct_0036F650;
struct UnkStruct_0036F650_11;
struct UnkStruct_0036F650_2;
struct UnkStruct_0036F650_5;
struct UnkStruct_0036F650_e0;
struct UnkStruct_D_004C8158;
struct UnkStruct_D_004C8160;
struct UnkStruct_D_01E3D390;
struct UnkStruct_D_01E3D460;
struct UnkStruct_D_01E8970C;
struct UnkStruct_D_01E89716;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E8CA94;
struct UnkStruct_D_01E8D67A;
struct UnkStruct_D_01E8EAF8;
struct UnkStruct_D_01E8EB02;
struct UnkStruct_D_01E94C40;
struct UnkStruct_D_01EA2874;
struct UnkStruct_func_0036C760;
struct UnkStruct_func_0036C770;

class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3BuddyDisplayComponent {
public:
    void GetSelectedBuddyName(char*);
    void SetFocus(bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8CA94 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036F650_2 {
    unsigned char pad_0[0xD0];
};

struct UnkStruct_D_01E898F2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036F650_5 {
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

struct UnkStruct_0036F650_11 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01EA2874 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D390 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_0036C770 {
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

struct UnkStruct_0036F650_e0 {
    unsigned char pad_0[0x20];
};

struct UnkStruct_D_01E94C40 {
    UnkStruct_0036F650_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_func_0036C760 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036F650 {
    unsigned char pad_0[0x4];
    char field_4[0x30];
    char field_34[0x28];
    unsigned char field_5C[0x70];
    int field_CC;
    unsigned char pad_D0[0x38];
    char field_108[0x14];
    unsigned char field_11C;
    unsigned char pad_11D[0x1];
    unsigned char field_11E;
    unsigned char pad_11F[0x5];
    int field_124;
    int field_128;
};

extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8D67A D_01E8D67A;
extern UnkStruct_D_01E89716 D_01E89716;
extern UnkStruct_D_01E8970C D_01E8970C;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E3D460 D_01E3D460;
extern UnkStruct_D_01EA2874 D_01EA2874;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern UnkStruct_func_0036C770 func_0036C770;
extern CB3BuddyDisplayComponent D_01E8D670;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_004C8158 D_004C8158;
extern UnkStruct_D_004C8160 D_004C8160;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E94C40 D_01E94C40;
extern UnkStruct_func_0036C760 func_0036C760;

extern "C" void Prepare__24CB3BuddyDisplayComponentFv(void *, int, int);  // CB3BuddyDisplayComponent::Prepare(), passed 2 more argument(s) [G]
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);  // CB3PromptsComponent::SetCurrentPrompts(unsigned int,unsigned int)
extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, void *, int);
extern "C" int func_00360240(void *, void *, char *, void *, UnkStruct_0036F650 *);
extern "C" void func_00366560(void *, char *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);
extern "C" int strcasecmp(const char *, const char *);
extern "C" int FindBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, void *, void *, UnkStruct_0036F650 *);


// [G] inlined: the field_CC=2 restore sequence (as func_0036C370's n0 != 0 arm); name unknown
static inline void func_0036F650_inl1(UnkStruct_0036F650 * self)
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

// [G] inlined func_0036F3E0 (its body)
static inline void func_0036F650_inl2(UnkStruct_0036F650 * self)
{
    switch (self->field_CC) {
    case 7:
        D_01E899C0.Show(0, 0);
        func_0036F650_inl1(self);
        break;
    case 9:
        D_01E899C0.Show(0, 0);
        func_0036F650_inl1(self);
        break;
    }
}

// 0x0036F650
extern "C" void func_0036F650(UnkStruct_0036F650 * self)
{
    char buf[200];
    switch (self->field_CC) {
    case 7:
        D_01E899C0.Show(0, 0);
        if (Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0) > 0) {
            self->field_CC = 8;
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, buf, 200);
            if (func_00360240(&D_01E3D390, self->field_108, buf, &func_0036C770, self) == 0) {
                D_01E8D670.GetSelectedBuddyName(buf);
                func_00366560(&D_01E8D670, buf);
                if (D_01E898F2.field_0 != 0) {
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                }
                func_0032D080(&D_01E898E8, 0, 27, 15, 0);
            } else {
                if (D_01E898F2.field_0 != 0) {
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                }
                func_0032D080(&D_01E898E8, 2, 207, 0, 0);
            }
        } else {
            func_0036F650_inl2(self);
        }
        break;
    case 6:
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, self->field_34, 200);
        self->field_CC = 5;
        break;
    case 9:
        if (Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0) > 0) {
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, self->field_4, 16);
            if (strcasecmp(self->field_4, ((char *)&D_01E94C40.field_0[D_01EA2874.field_0] + 0xDC3C)) == 0) {
                self->field_CC = 10;
                D_01E8D670.SetFocus(0);
                D_01E899C0.Show(0, 0);
                if (D_01E898F2.field_0 != 0) {
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                }
                func_0032D080(&D_01E898E8, 2, 67, 0, 0);
            } else {
                self->field_CC = 10;
                D_01E8D670.SetFocus(0);
                D_01E899C0.Show(0, 0);
                self->field_11C = 0;
                self->field_11E = 0;
                if (FindBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_4, &func_0036C760, self) != 0) {
                    func_0036F650_inl1(self);
                } else {
                    if (D_01E898F2.field_0 != 0) {
                        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                    }
                    func_0032D080(&D_01E898E8, 0, 58, 15, 0);
                }
            }
        } else {
            func_0036F650_inl2(self);
        }
        break;
    }
}
