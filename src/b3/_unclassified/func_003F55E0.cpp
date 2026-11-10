// func_003F55E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3BackgroundType {};
enum EGlobalStrings {};

class CB3OnScreenKeyboardComponent;
class CB3PromptBarComponent;
struct UnkStruct_003F55E0;
struct UnkStruct_D_0051A998;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8980A;
struct UnkStruct_D_01E8CBCC;
struct UnkStruct_D_01E8F360;
struct UnkStruct_D_01E8F36A;
struct UnkStruct_D_01E90438;

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnScreenKeyboardComponent {
public:
    void RegisterKeyboardCallbacks();
    void Show(bool, bool);
    void SetAllowableCharacters(EGlobalStrings);
    void SetDisplayText(unsigned short*, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A998 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8F36A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8F360 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8CBCC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8980A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E88A80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89518 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90438 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003F55E0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    int field_10[1];  // [G] element count unknown
    unsigned char pad_14[0xC];
    int field_20;
};

extern UnkStruct_D_0051A998 D_0051A998;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01E8F36A D_01E8F36A;
extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E8CBCC D_01E8CBCC;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89518 D_01E89518;
extern CB3PromptBarComponent D_01E894FC;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E90438 D_01E90438;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00319C80(void *, int, int);
extern "C" int func_003517F0(void *);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_003F4600(UnkStruct_003F55E0 *, int);
extern "C" int func_0013B820(void *);
extern "C" int func_0013B730(void *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x003F55E0
extern "C" int func_003F55E0(UnkStruct_003F55E0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)1);
    func_00319C80(&D_01E89518, 428, 14);
    D_01E894FC.Prepare();
    func_003517F0(&D_01E899C0);
    D_01E899C0.RegisterKeyboardCallbacks();
    int r6 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 256);
    self->field_C = r6;
    for (int i = 0; (i < 3); i++) {
        int r7 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 18);
        self->field_10[i] = r7;
    }
    self->field_8 = -1;
    self->field_20 = 0;
    if (D_0051A998.field_0 == 0) {
        self->field_4 = 1;
        func_003F4600(self, 1);
    } else {
        func_0013B820((void *)(D_0051BF9C.field_0));
        self->field_4 = 17;
        if (D_01E8F36A.field_0 != 0) {
            ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
        }
        D_01E899C0.Show(1, 0);
        D_01E899C0.SetAllowableCharacters((EGlobalStrings)659);
        int r13 = func_0013B730((void *)(D_0051BF9C.field_0));
        D_01E899C0.SetDisplayText((unsigned short*)r13, 1);
        D_01E8CBCC.field_0 = 9;
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 260, 15);
    }
    return 1;
}
