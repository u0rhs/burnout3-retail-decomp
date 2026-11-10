// func_003734F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (one-byte local as plain unsigned char; VSelect Prepare passes the extra t0=0 its asm reads).

// func_003734F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3BackgroundType {};
class CB3MenuComponentSelectionData;
class CB3VSelectComponentEntryData;

class CB3BuddyReadMailComponent;
class CB3OnScreenKeyboardComponent;
class CB3PromptBarComponent;
struct UnkStruct_003734F0;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E3D390;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89544;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01EA2F5E;
struct UnkStruct_D_01EA2F6E;
struct UnkStruct_D_01EA3036;

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3BuddyReadMailComponent {
public:
    void Prepare(char*, char*, char*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnScreenKeyboardComponent {
public:
    void RegisterKeyboardCallbacks();

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

struct UnkStruct_D_01E3D390 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2F5E {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89544 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA3036 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2F6E {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003734F0 {
    unsigned char pad_0[0x4];
    short field_4;
    short field_6;
    int field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char pad_E[0x2];
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char pad_16[0x2];
    int field_18;
    unsigned char field_1C;
    unsigned char field_1D;
    unsigned char pad_1E[0x2];
    int field_20;
    unsigned char field_24;
    unsigned char field_25;
    unsigned char pad_26[0x2];
    int field_28;
};

extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern UnkStruct_D_01EA2F5E D_01EA2F5E;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01EA3036 D_01EA3036;
extern UnkStruct_D_01EA2F6E D_01EA2F6E;
extern CB3BuddyReadMailComponent D_01E8E500;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, bool, float, float, float, float, const void *, void *, int, float);  // CB3VSelectComponent::Prepare(bool,float,float,float,float,const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 2 more argument(s) [G] (the callee reads t0 and f16; as func_00396E50)
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_003517F0(void *);
extern "C" int func_0035F9E0(void *, void *, unsigned char *);
extern "C" int func_00271A00(void *, int);

// 0x003734F0
extern "C" int func_003734F0(UnkStruct_003734F0 * self)
{
    unsigned char local;  // [G] one byte at sp+0x2F
    Prepare__15CB3MenuPageBaseFb(self, 0);
    func_00319C80(&D_01E89518, 9, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    func_003517F0(&D_01E899C0);
    func_0035F9E0(&D_01E3D390, &D_01EA2F5E, &local);
    if (local != 0) {
        self->field_4 = 0;
        self->field_6 = 1;
        int r7 = func_00271A00(&D_0051BA44, 30);
        self->field_8 = r7;
        self->field_C = 0;
        self->field_D = 0;
    } else {
        self->field_4 = 1;
        self->field_6 = 4;
        int r8 = func_00271A00(&D_0051BA44, 29);
        self->field_10 = r8;
        self->field_14 = 0;
        self->field_15 = 0;
        int r9 = func_00271A00(&D_0051BA44, 30);
        self->field_8 = r9;
        self->field_C = 0;
        self->field_D = 0;
        int r10 = func_00271A00(&D_0051BA44, 14);
        self->field_18 = r10;
        self->field_1C = 0;
        self->field_1D = 0;
        int r11 = func_00271A00(&D_0051BA44, 1088);
        self->field_20 = r11;
        self->field_24 = 0;
        self->field_25 = 0;
    }
    Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, 0, 84.0f, 240.0f, 30.0f, 40.0f, (const CB3MenuComponentSelectionData*)((char *)self + 0x4), (CB3VSelectComponentEntryData*)((char *)self + 0x8), 0, 172.0f);
    D_01E8E500.Prepare((char*)&D_01EA2F5E, (char*)&D_01EA3036, (char*)&D_01EA2F6E);
    self->field_28 = 0;
    D_01E899C0.RegisterKeyboardCallbacks();
    return 1;
}
