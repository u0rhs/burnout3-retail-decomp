// CB3OnlineConnectingPage::Prepare(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineConnectingPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (if (p0 >= 0) { if (==9) A else B } else A; shared field_4 = 0 written once after (tail-duplicated)).

// CB3OnlineConnectingPage::Prepare(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineConnectingPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EB3BackgroundType {};

class CB3OnlineConnectingPage;
class CB3PromptBarComponent;
class CGtPS2LibNet;
struct UnkStruct_D_004C6E78;
struct UnkStruct_D_004C6E80;
struct UnkStruct_D_004C6E88;
struct UnkStruct_D_004C6E90;
struct UnkStruct_D_004C6E98;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E654C8;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89788;
struct UnkStruct_D_01E8D4B0;
struct UnkStruct_D_01E90438;

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtPS2LibNet {
public:
    void UpInterface(int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E654C8 {
    int field_0;
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

struct UnkStruct_D_01E8D4B0 {
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

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89788 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineConnectingPage {
public:
    int Prepare(int p0);

    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[0x2];
    int field_8;
};

extern UnkStruct_D_01E654C8 D_01E654C8;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_D_004C6E78 D_004C6E78;
extern UnkStruct_D_004C6E80 D_004C6E80;
extern UnkStruct_D_004C6E88 D_004C6E88;
extern UnkStruct_D_004C6E90 D_004C6E90;
extern UnkStruct_D_004C6E98 D_004C6E98;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;
extern CGtPS2LibNet D_01E3C620;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" int func_00271A00(void *, int);

// 0x00347440
int CB3OnlineConnectingPage::Prepare(int p0)
{
    Prepare__15CB3MenuPageBaseFb(this, 0);
    field_8 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 50);
    func_00319C80(&D_01E89518, 85, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    D_01E894FC.Prepare();
    if (p0 >= 0) {
        if (D_01E654C8.field_0 == 9) {
field_5 = 1;
        func_00351F00(&D_01E8D4B0, &D_004C6E78, &D_004C6E80, &D_004C6E88, &D_004C6E90, &D_004C6E98, 88, 3, 1, 103, 0, 32.0f, 496.0f);
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)func_00271A00(&D_0051BA44, 88), 1, 80.0f);
        } else {
field_5 = 0;
        D_01E3C620.UpInterface(p0);
        func_00351F00(&D_01E8D4B0, &D_004C6E78, &D_004C6E80, &D_004C6E88, &D_004C6E90, &D_004C6E98, 86, 3, 1, 103, 0, 32.0f, 496.0f);
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)func_00271A00(&D_0051BA44, 87), 1, 80.0f);
        }
    } else {
field_5 = 1;
        func_00351F00(&D_01E8D4B0, &D_004C6E78, &D_004C6E80, &D_004C6E88, &D_004C6E90, &D_004C6E98, 88, 3, 1, 103, 0, 32.0f, 496.0f);
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)func_00271A00(&D_0051BA44, 88), 1, 80.0f);
    }
    field_4 = 0;
    return 1;
}
