// CB3OnlineSelectLoginPage::PrepareSelectLoginControls() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (field_73 is a char[] member (not CSE'd); strcmp()!=0 arm first; Prepare gets an extra int 0 in t0).

// lifter variant 0
// CB3OnlineSelectLoginPage::PrepareSelectLoginControls() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3MenuComponentSelectionData;
class CB3VSelectComponentEntryData;

class CB3OnlineSelectLoginPage;
struct UnkStruct_D_004C6EB0;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89522;
struct UnkStruct_D_01E89544;
struct UnkStruct_D_01E8954E;
struct UnkStruct_D_01E8961C;
struct UnkStruct_D_01E89626;
struct UnkStruct_D_01E89788;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E8D4F0;
struct UnkStruct_D_01E8D4FA;

struct UnkStruct_D_01E8D4FA {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D4F0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89522 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89518 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8954E {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89544 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89626 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8961C {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
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

struct UnkStruct_D_004C6EB0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89788 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineSelectLoginPage {
public:
    void PrepareSelectLoginControls();

    unsigned char pad_0[0x70];
    unsigned char field_70;
    unsigned char pad_71[0x1];
    unsigned char field_72;
    char field_73[0x65];
    int field_D8;
    unsigned char field_DC;
    unsigned char field_DD;
    unsigned char pad_DE[0x2];
    int field_E0;
    unsigned char field_E4;
    unsigned char field_E5;
    unsigned char pad_E6[0x2];
    int field_E8;
    unsigned char field_EC;
    unsigned char field_ED;
    unsigned char pad_EE[0x2];
    short field_F0;
    short field_F2;
    int field_F4;
};

extern UnkStruct_D_01E8D4FA D_01E8D4FA;
extern UnkStruct_D_01E8D4F0 D_01E8D4F0;
extern UnkStruct_D_01E89522 D_01E89522;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89626 D_01E89626;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_004C6EB0 D_004C6EB0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;

extern "C" int strcmp(const char *, const char *);
extern "C" void Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, bool, float, float, float, float, const void *, void *, int, float);  // CB3VSelectComponent::Prepare(bool,float,float,float,float,const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 2 more argument(s) (t0 = 0, f16) [G]
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);  // CB3HelpBarComponent::SetString(const unsigned short*,bool,bool,float)
extern "C" void func_00319C80(void *, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, int, int);

// 0x00349280
void CB3OnlineSelectLoginPage::PrepareSelectLoginControls()
{
    field_70 = 0;
    field_72 = 0;
    if (D_01E8D4FA.field_0 != 0) {
        ((UnkStruct_D_01E8D4F0 *)&D_01E8D4F0)->vfunc_C();
    }
    if (D_01E89522.field_0 != 0) {
        ((UnkStruct_D_01E89518 *)&D_01E89518)->vfunc_C();
    }
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    }
    if (D_01E89626.field_0 != 0) {
        ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
    }
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    func_00319C80(&D_01E89518, 102, 14);
    field_F0 = 0;
    field_F2 = 3;
    if (strcmp(field_73, (const char *)&D_004C6EB0) != 0) {
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(field_73, field_F4, 50);
        field_D8 = field_F4;
        field_DC = 0;
        field_DD = 0;
    } else {
        field_D8 = func_00271A00(&D_0051BA44, 127);
        field_DC = 1;
        field_DD = 0;
    }
    int r9 = func_00271A00(&D_0051BA44, 70);
    field_E0 = r9;
    field_E4 = 0;
    field_E5 = 0;
    int r10 = func_00271A00(&D_0051BA44, 69);
    field_E8 = r10;
    field_EC = 0;
    field_ED = 0;
    Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, 0, 84.0f, 240.0f, 30.0f, 40.0f, (const CB3MenuComponentSelectionData*)((char *)this + 0xF0), (CB3VSelectComponentEntryData*)((char *)this + 0xD8), 0, 480.0f);
    int r12 = func_00271A00(&D_0051BA44, 102);
    SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short*)r12, 0, 0, 80.0f);
}
