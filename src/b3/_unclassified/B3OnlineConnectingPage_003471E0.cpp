// CB3OnlineConnectingPage::PrepareLobbyConnect() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineConnectingPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (two separate char[100] stack buffers instead of one struct + offset).

// lifter variant 0
// CB3OnlineConnectingPage::PrepareLobbyConnect() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineConnectingPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EB3BackgroundType {};

class CB3OnlineConnectingPage;
class CB3PromptBarComponent;
struct UnkStruct_003471E0_4;
struct UnkStruct_D_004C6E60;
struct UnkStruct_D_004C6E78;
struct UnkStruct_D_004C6E80;
struct UnkStruct_D_004C6E88;
struct UnkStruct_D_004C6E90;
struct UnkStruct_D_004C6E98;
struct UnkStruct_D_004E2918;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E3CE48;
struct UnkStruct_D_01E3D390;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89788;
struct UnkStruct_D_01E89792;
struct UnkStruct_D_01E8D4B0;
struct UnkStruct_D_01E8D4BA;
struct UnkStruct_D_01E90438;

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D4BA {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D4B0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    virtual void vfunc_28(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003471E0_4 {
    unsigned char pad_0[0xE0];
};

struct UnkStruct_D_004E2918 {
    int field_0;
};

struct UnkStruct_D_01E3CE48 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89792 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
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

struct UnkStruct_D_004C6E78 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6E80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6E88 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6E90 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6E98 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6E60 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D390 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89788 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineConnectingPage {
public:
    int PrepareLobbyConnect();

    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char pad_5[0x3];
    int field_8;
};

extern UnkStruct_D_01E8D4BA D_01E8D4BA;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_004E2918 D_004E2918;
extern UnkStruct_D_01E3CE48 D_01E3CE48;
extern int D_004D1B70[];  // [G] element count unknown
extern UnkStruct_D_01E89792 D_01E89792;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_004C6E78 D_004C6E78;
extern UnkStruct_D_004C6E80 D_004C6E80;
extern UnkStruct_D_004C6E88 D_004C6E88;
extern UnkStruct_D_004C6E90 D_004C6E90;
extern UnkStruct_D_004C6E98 D_004C6E98;
extern UnkStruct_D_004C6E60 D_004C6E60;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern UnkStruct_D_01E89788 D_01E89788;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);  // CB3HelpBarComponent::SetString(const unsigned short*,bool,bool,float)
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" int func_00271A00(void *, int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, void *, int);
extern "C" int func_003609A0(void *, void *, void *, void *, int, int);

// 0x003471E0
int CB3OnlineConnectingPage::PrepareLobbyConnect()
{
    char b1[100];
    char b0[100];
    Prepare__15CB3MenuPageBaseFb(this, 0);
    int r1 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 50);
    field_8 = r1;
    func_00319C80(&D_01E89518, 85, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    D_01E894FC.Prepare();
    func_00351F00(&D_01E8D4B0, &D_004C6E78, &D_004C6E80, &D_004C6E88, &D_004C6E90, &D_004C6E98, 86, 3, 1, 103, 0, 32.0f, 496.0f);
    field_4 = 1;
    if (D_01E8D4BA.field_0 != 0) {
        ((UnkStruct_D_01E8D4B0 *)&D_01E8D4B0)->vfunc_C();
    }
    func_00351F00(&D_01E8D4B0, &D_004C6E78, &D_004C6E80, &D_004C6E88, &D_004C6E90, &D_004C6E98, 89, 3, 1, 103, 0, 32.0f, 496.0f);
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_28(&D_004C6E60, 21800);
    int r9 = func_00271A00(&D_0051BA44, 5);
    ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(r9, b1, 100);
    int r11 = func_00271A00(&D_0051BA44, 3080);
    ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(r11, b0, 100);
    func_003609A0(&D_01E3D390, b1, b0, (void *)(D_004D1B70[D_004E2918.field_0]), D_01E3CE48.field_0, D_004E2918.field_0);
    int r14 = func_00271A00(&D_0051BA44, 89);
    field_8 = r14;
    if (D_01E89792.field_0 != 0) {
        SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short*)field_8, 0, 0, 80.0f);
    } else {
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)field_8, 1, 80.0f);
    }
    return 1;
}
