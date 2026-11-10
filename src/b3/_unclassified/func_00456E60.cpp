// func_00456E60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (page Prepare: each profile query materialised as bool b = !call() right after its call; the input check clears the last one).

// lifter variant 0
// func_00456E60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3MenuComponentSelectionData;
class CB3VSelectComponentEntryData;
enum EB3BackgroundType {};

class CB3PromptBarComponent;
struct UnkStruct_00456E60;
struct UnkStruct_D_004F50C0;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89544;
struct UnkStruct_D_01E89800;

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F50C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89544 {
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

struct UnkStruct_00456E60 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x4];
    short field_C;
    short field_E;
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
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char pad_2E[0x2];
    int field_30;
    unsigned char field_34;
    unsigned char field_35;
    unsigned char pad_36[0x2];
    int field_38;
    unsigned char field_3C;
    unsigned char field_3D;
    unsigned char pad_3E[0x2];
    int field_40;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0x2];
    int field_48;
    unsigned char field_4C;
    unsigned char field_4D;
    unsigned char pad_4E[0x2];
    int field_50;
    unsigned char field_54;
    unsigned char field_55;
};

extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);  // CB3VSelectComponent::Prepare(const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" int func_0013A6D0(void *, int);
extern "C" int func_0013A600(int, int);
extern "C" int func_0022C780(void *);
extern "C" int func_00271A00(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x00456E60
extern "C" int func_00456E60(UnkStruct_00456E60 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    int t0 = D_0051BF9C.field_0;
    bool b1 = !func_0013A6D0((void *)(t0), 0);
    bool b2 = !func_0013A6D0((void *)(t0), 1);
    bool b3 = !func_0013A6D0((void *)(t0), 2);
    bool b4 = !func_0013A6D0((void *)(t0), 3);
    bool b5 = !func_0013A6D0((void *)(t0), 4);
    bool b6 = !func_0013A600(t0, 0);
    bool b7 = !func_0013A600(t0, 1);
    bool b8 = !func_0013A600(t0, 2);
    if (func_0022C780(&D_004F50C0) != 0) {
        b8 = 0;
    }
    self->field_C = self->field_4;
    self->field_E = 9;
    self->field_10 = func_00271A00(&D_0051BA44, 3065);
    self->field_14 = 0;
    self->field_15 = 0;
    self->field_18 = func_00271A00(&D_0051BA44, 3066);
    self->field_1C = b1;
    self->field_1D = 0;
    self->field_20 = func_00271A00(&D_0051BA44, 3067);
    self->field_24 = b2;
    self->field_25 = 0;
    self->field_28 = func_00271A00(&D_0051BA44, 3068);
    self->field_2C = b3;
    self->field_2D = 0;
    self->field_30 = func_00271A00(&D_0051BA44, 3069);
    self->field_34 = b4;
    self->field_35 = 0;
    self->field_38 = func_00271A00(&D_0051BA44, 3070);
    self->field_3C = b5;
    self->field_3D = 0;
    self->field_40 = func_00271A00(&D_0051BA44, 3072);
    self->field_44 = b6;
    self->field_45 = 0;
    self->field_48 = func_00271A00(&D_0051BA44, 3073);
    self->field_4C = b7;
    self->field_4D = 0;
    self->field_50 = func_00271A00(&D_0051BA44, 3071);
    self->field_54 = b8;
    self->field_55 = 0;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)((char *)self + 0xC), (CB3VSelectComponentEntryData*)((char *)self + 0x10), 640.0f);
    func_00319C80(&D_01E89518, 3064, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    return 1;
}
