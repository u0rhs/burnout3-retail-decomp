// func_003EDD60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3BackgroundType {};
enum EGlobalStrings {};

class CB3OnScreenKeyboardComponent;
class CB3PromptBarComponent;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8980A;
struct UnkStruct_D_01E8CBCC;

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

struct UnkStruct_D_0051BF9C {
    int field_0;
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

extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01E8CBCC D_01E8CBCC;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89518 D_01E89518;
extern CB3OnScreenKeyboardComponent D_01E899C0;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00319C80(void *, int, int);
extern "C" int func_003517F0(void *);
extern "C" int func_0013B730(void *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x003EDD60
extern "C" int func_003EDD60(void *n0_)
{
    int n0 = (int)n0_;
    Prepare__15CB3MenuPageBaseFb((void *)n0, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)1);
    D_01E894FC.Prepare();
    func_00319C80(&D_01E89518, 425, 14);
    func_003517F0(&D_01E899C0);
    D_01E899C0.RegisterKeyboardCallbacks();
    D_01E899C0.Show(1, 0);
    D_01E899C0.SetAllowableCharacters((EGlobalStrings)659);
    int r8 = func_0013B730((void *)(D_0051BF9C.field_0));
    D_01E899C0.SetDisplayText((unsigned short*)r8, 1);
    D_01E8CBCC.field_0 = 9;
    if (D_01E8980A.field_0 != 0) {
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    }
    func_0031ECD0(&D_01E89800, 261, 15);
    return 1;
}
