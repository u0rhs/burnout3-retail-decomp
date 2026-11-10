// func_00370F30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (64-bit arg built as v = 0x400000105; then v |= 0x200000000 / 0x100000000 in the arms).

// lifter variant 0
// func_00370F30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3BackgroundType {};

class CB3BuddyDisplayComponent;
class CB3OnScreenKeyboardComponent;
class CB3PromptBarComponent;
struct UnkStruct_00370F30;
struct UnkStruct_00370F30_3;
struct UnkStruct_D_004C8158;
struct UnkStruct_D_004C8160;
struct UnkStruct_D_004C8168;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E3D390;
struct UnkStruct_D_01E3D460;
struct UnkStruct_D_01E3D4B0;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E8EAF8;
struct UnkStruct_D_01E90438;

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnScreenKeyboardComponent {
public:
    void RegisterKeyboardCallbacks();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3BuddyDisplayComponent {
public:
    void SetFocus(bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D460 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D4B0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00370F30_3 {
    unsigned char pad_0[0x10C];
    int field_10C;
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
    virtual void vfunc_68();
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
    virtual int vfunc_94();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90438 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89518 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E88A80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
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

struct UnkStruct_D_01E898E8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C8168 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D390 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00370F30 {
    unsigned char pad_0[0x5C];
    short field_5C;
    short field_5E;
    unsigned char pad_60[0x6C];
    int field_CC;
    unsigned char pad_D0[0x4C];
    unsigned char field_11C;
    unsigned char field_11D;
    unsigned char field_11E;
    unsigned char field_11F;
    unsigned char pad_120[0x4];
    int field_124;
    int field_128;
};

extern UnkStruct_D_01E3D460 D_01E3D460;
extern UnkStruct_D_01E3D4B0 D_01E3D4B0;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern CB3BuddyDisplayComponent D_01E8D670;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_004C8158 D_004C8158;
extern UnkStruct_D_004C8160 D_004C8160;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_004C8168 D_004C8168;
extern UnkStruct_D_01E3D390 D_01E3D390;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__24CB3BuddyDisplayComponentFv(void *, int, int);  // CB3BuddyDisplayComponent::Prepare(), passed 2 more argument(s) [G]
extern "C" int Connect__22CGtBuddiesPS2DirtySockFPcPc(void *, char*, char*, void *, void *);  // CGtBuddiesPS2DirtySock::Connect(char*,char*), passed 2 more argument(s) [G]
extern "C" int func_003663F0(void *);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);
extern "C" int func_003517F0(void *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_0033A600(void *, UnkStruct_00370F30_3 *, int, void *);

// 0x00370F30
extern "C" int func_00370F30(UnkStruct_00370F30 * self)
{
    UnkStruct_00370F30_3 local;  // [G] the frame's one local (size: up to the frame top)
    Prepare__15CB3MenuPageBaseFb(self, 0);
    int r1 = func_003663F0(&D_01E8D670);
    self->field_128 = r1;
    int r2 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, self->field_128);
    self->field_124 = r2;
    func_00319C80(&D_01E89518, 9, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    unsigned long v0 = 0x400000105;
    if (D_01E3D460.field_0 == 6) {
        v0 |= 0x200000000;
    } else {
        v0 |= 0x100000000;
    }
    func_0031ECD0(&D_01E89800, v0, 3);
    D_01E894FC.Prepare();
    Prepare__24CB3BuddyDisplayComponentFv(&D_01E8D670, self->field_124, self->field_128);
    self->field_5C = 0;
    self->field_5E = 1;
    Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C8158, &D_004C8160, ((char *)self + 0x5C), 272.0f);
    func_003517F0(&D_01E899C0);
    D_01E899C0.RegisterKeyboardCallbacks();
    self->field_CC = 2;
    D_01E8D670.SetFocus(1);
    self->field_11C = 0;
    self->field_11D = 0;
    self->field_11F = 0;
    self->field_11E = 0;
    if (D_01E3D4B0.field_0 == 0) {
        self->field_CC = 0;
        func_0032D080(&D_01E898E8, 3, 80, 1, 0);
        func_0033A600(&D_01E3CD44, &local, 256, ((char *)&local + 0x10C));
        int r14 = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_94();
        Connect__22CGtBuddiesPS2DirtySockFPcPc(&D_01E3D390, (char*)&local, (char*)local.field_10C, (void *)(r14), &D_004C8168);
        D_01E8D670.SetFocus(0);
    }
    return 1;
}
