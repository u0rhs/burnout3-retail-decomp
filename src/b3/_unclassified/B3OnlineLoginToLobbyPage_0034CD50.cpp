// CB3OnlineLoginToLobbyPage::Prepare(char*,char*,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLoginToLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EB3BackgroundType {};

class CB3OnlineLoginToLobbyPage;
class CB3PromptBarComponent;
struct UnkStruct_0034CD50_1;
struct UnkStruct_D_004C6F50;
struct UnkStruct_D_004C6F58;
struct UnkStruct_D_004C6F60;
struct UnkStruct_D_004C6F68;
struct UnkStruct_D_004C6F70;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89788;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8D4B0;
struct UnkStruct_D_01E90438;

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0034CD50_1 {
    CB3OnlineLoginToLobbyPage * field_0;
    void * field_4;
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
    virtual void vfunc_30(char*, char*, UnkStruct_0034CD50_1 *);
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

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89788 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D4B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6F50 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6F58 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6F60 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6F68 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6F70 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineLoginToLobbyPage {
public:
    int Prepare(char* p0, char* p1, bool p2);

    unsigned char pad_0[0x44];
    int field_44;
    char * field_48;
    char * field_4C;
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
};

extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_D_004C6F50 D_004C6F50;
extern UnkStruct_D_004C6F58 D_004C6F58;
extern UnkStruct_D_004C6F60 D_004C6F60;
extern UnkStruct_D_004C6F68 D_004C6F68;
extern UnkStruct_D_004C6F70 D_004C6F70;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" int ForAllPersonas__25CB3OnlineLoginToLobbyPageFPcPv(char*, void*);  // CB3OnlineLoginToLobbyPage::ForAllPersonas(char*,void*), its address taken
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);

// 0x0034CD50
int CB3OnlineLoginToLobbyPage::Prepare(char* p0, char* p1, bool p2)
{
    UnkStruct_0034CD50_1 local;  // [G] the frame's one local (size: up to the frame top)
    Prepare__15CB3MenuPageBaseFb(this, 0);
    int r1 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 18);
    field_44 = r1;
    func_00319C80(&D_01E89518, 82, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    int r4 = func_00271A00(&D_0051BA44, 190);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)r4, 1, 80.0f);
    func_0031ECD0(&D_01E89800, 0, 3);
    D_01E894FC.Prepare();
    func_00351F00(&D_01E8D4B0, &D_004C6F50, &D_004C6F58, &D_004C6F60, &D_004C6F68, &D_004C6F70, 189, 3, 1, 103, 0, 32.0f, 496.0f);
    field_50 = p2;
    field_51 = 0;
    field_48 = (char *)p0;
    field_4C = (char *)p1;
    local.field_4 = (void *)&ForAllPersonas__25CB3OnlineLoginToLobbyPageFPcPv;
    local.field_0 = this;
    field_52 = 0;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_30(p0, p1, &local);
    return 1;
}
