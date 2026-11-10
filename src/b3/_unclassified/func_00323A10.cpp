// func_00323A10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two char[100] locals (buf1 then buf2); CGtBuddiesPS2DirtySock derives CGtBuddies; DNAT low hint CB3OnlineMenuPage::Prepare(bool)).

// lifter variant 0
// func_00323A10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3BackgroundType {};
class CB3MenuComponentSelectionData;
class CB3VSelectComponentEntryData;
enum EGtBuddyPresence {};

class CB3PromptBarComponent;
class CGtBuddies;
class CGtBuddiesPS2DirtySock;
struct UnkStruct_00323A10;
struct UnkStruct_00323A10_1;
struct UnkStruct_D_004E2918;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E3D4B4;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89544;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8E7E0;

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtBuddies {
public:
    void SetPresenceDetail(char*, char*, char*);
};

class CGtBuddiesPS2DirtySock : public CGtBuddies {
public:
    void SetPresence(EGtBuddyPresence, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00323A10_1 {
    unsigned char pad_0[0xE0];
};

struct UnkStruct_D_004E2918 {
    int field_0;
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

struct UnkStruct_D_01E89518 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E88A80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8E7E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D4B4 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89544 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00323A10 {
    unsigned char pad_0[0x4];
    short field_4;
    unsigned short field_6;
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
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char pad_2E[0x2];
    int field_30;
    unsigned char field_34;
    unsigned char field_35;
    unsigned char pad_36[0x2];
    int field_38;
};

extern UnkStruct_D_004E2918 D_004E2918;
extern int D_004D1B70[];  // [G] element count unknown
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E8E7E0 D_01E8E7E0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E3D4B4 D_01E3D4B4;
extern UnkStruct_D_01E89544 D_01E89544;
extern CGtBuddiesPS2DirtySock D_01E3D390;
extern UnkStruct_D_01E32AE0 D_01E32AE0;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);  // CB3VSelectComponent::Prepare(const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int PrepareSpinning__17CB3GlobeComponentFv(void *);
extern "C" int func_00271A00(void *, int);
extern "C" int func_0026C790(void *);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, char *, int);
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" void func_00336320(void *);

// 0x00323A10
extern "C" int func_00323A10(UnkStruct_00323A10 * self)
{
    char buf1[100];
    char buf2[100];
    Prepare__15CB3MenuPageBaseFb(self, 0);
    func_00319C80(&D_01E89518, 183, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 0x1000144, 3);
    D_01E894FC.Prepare();
    PrepareSpinning__17CB3GlobeComponentFv(&D_01E8E7E0);
    self->field_4 = 0;
    self->field_6 = 6;
    self->field_8 = func_00271A00(&D_0051BA44, 90);
    self->field_C = 0;
    self->field_D = 0;
    self->field_10 = func_00271A00(&D_0051BA44, 3163);
    self->field_14 = 0;
    self->field_15 = 0;
    self->field_18 = func_00271A00(&D_0051BA44, 92);
    self->field_1C = 0;
    self->field_1D = 0;
    self->field_20 = func_00271A00(&D_0051BA44, 94);
    self->field_24 = 0;
    self->field_25 = 0;
    self->field_28 = func_00271A00(&D_0051BA44, 93);
    self->field_2C = 0;
    self->field_2D = 0;
    if (func_0026C790(&D_01E3D4B4) > 0) {
        self->field_30 = func_00271A00(&D_0051BA44, 708);
        self->field_34 = 0;
        self->field_35 = 0;
    } else {
        unsigned short t0 = self->field_6;
        self->field_4 = 0;
        self->field_6 = (t0 + -1);
    }
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)((char *)self + 0x4), (CB3VSelectComponentEntryData*)((char *)self + 0x8), 640.0f);
    ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(func_00271A00(&D_0051BA44, 5), buf1, 100);
    ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(func_00271A00(&D_0051BA44, 3080), buf2, 100);
    D_01E3D390.SetPresenceDetail(buf1, buf2, (char*)D_004D1B70[D_004E2918.field_0]);
    D_01E3D390.SetPresence((EGtBuddyPresence)1, 0);
    if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D8() != 0) {
        self->field_38 = 0;
        ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
        func_00336320(&D_01E3CD44);
    } else {
        self->field_38 = 1;
    }
    return 1;
}
