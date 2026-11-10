// CB3OnlineSelectLoginPage::UpdateRetrieveLogin() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten: float guard chain, static CB3SFIOCallbacks getters, enum SLoginProcessE local, if/else around update, switch on func_0030A8C0 (nop delay slot), virtual call through cast global).

// lifter variant 0
// CB3OnlineSelectLoginPage::UpdateRetrieveLogin() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum SLoginProcessE {};

class CB3OnlineSelectLoginPage;
class CB3SFIOCallbacks;
struct UnkStruct_003476B0_1;
struct UnkStruct_003476B0_4;
struct UnkStruct_D_004C6EB0;
struct UnkStruct_D_004F509C;
struct UnkStruct_D_005185A0;
struct UnkStruct_D_01E898E8;

class CB3SFIOCallbacks {
public:
    static int SharedNetworkLoginUpdate(SLoginProcessE*);
    static int SharedNetworkLoginLoadPrepare();
    static char * GetSharedNetworkLoginName();
    static char * GetSharedNetworkLoginPassword();
};

struct UnkStruct_003476B0_1 {
    CB3SFIOCallbacks * field_0;
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003476B0_4 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_005185A0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6EB0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineSelectLoginPage {
public:
    void UpdateRetrieveLogin();
    void PrepareSelectLoginControls();

    unsigned char pad_0[0x6C];
    float field_6C;
    unsigned char field_70;
    unsigned char pad_71[0x2];
    char field_73[0x32];
    char field_A5[0x32];
};

extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_005185A0 D_005185A0;
extern UnkStruct_D_004C6EB0 D_004C6EB0;

extern "C" char * strcpy(char *, const char *);
extern "C" int func_0030A8C0(void *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_003615B0();

// 0x003476B0
void CB3OnlineSelectLoginPage::UpdateRetrieveLogin()
{
    float t = field_6C;
    if (t > 2.0f && -1.0f != t) {
        field_6C = -1.0f;
        if (CB3SFIOCallbacks::SharedNetworkLoginLoadPrepare() != 0) {
            strcpy(field_73, (const char *)&D_004C6EB0);
            strcpy(field_A5, (const char *)&D_004C6EB0);
            PrepareSelectLoginControls();
        }
    } else if (-1.0f != t) {
        field_6C += D_004F509C.field_0;
        return;
    }

    SLoginProcessE e;
    if (CB3SFIOCallbacks::SharedNetworkLoginUpdate(&e) == 0) {
        if (e == 2) {
            strcpy(field_73, CB3SFIOCallbacks::GetSharedNetworkLoginName());
            strcpy(field_A5, CB3SFIOCallbacks::GetSharedNetworkLoginPassword());
            func_003615B0();
            PrepareSelectLoginControls();
        }
    } else {
        switch (func_0030A8C0(&D_005185A0)) {
        case 1:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 6, 0x75, 2, 0);
            strcpy(field_73, (const char *)&D_004C6EB0);
            strcpy(field_A5, (const char *)&D_004C6EB0);
            field_70 = 6;
            break;
        default:
            strcpy(field_73, (const char *)&D_004C6EB0);
            strcpy(field_A5, (const char *)&D_004C6EB0);
            PrepareSelectLoginControls();
            break;
        }
        func_003615B0();
    }
}
