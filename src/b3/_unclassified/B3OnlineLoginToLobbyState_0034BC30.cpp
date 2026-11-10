// CB3OnlineLoginToLobbyState::HandleConnectingEvents(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLoginToLobbyState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (if/else arms instead of early returns (unsigned range test < 4, field_AC != 0); swap block reads D_01EA2980 after the D_01EA2974 store; phantom p0/this args dropped).

// lifter variant 0
// CB3OnlineLoginToLobbyState::HandleConnectingEvents(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLoginToLobbyState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EB3MenuFlowFSMEvents {};
enum EGlobalStrings {};
enum EB3MessageBoxType {};

class CB3ErrorPage;
class CB3OnlineLoginToLobbyPage;
class CB3OnlineLoginToLobbyState;
struct UnkStruct_0034BC30_6;
struct UnkStruct_0034BC30_8;
struct UnkStruct_0034BC30_9;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E3C620;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E9B4C0;
struct UnkStruct_D_01E9B4CC;
struct UnkStruct_D_01E9B6B8;
struct UnkStruct_D_01EA2960;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

class CB3ErrorPage {
public:
    void Prepare(EGlobalStrings, EGlobalStrings, EB3MessageBoxType);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineLoginToLobbyPage {
public:
    void Prepare(char*, char*, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    virtual int vfunc_58();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B6B8 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2974 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2970 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_0034BC30_8 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_0034BC30_6 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0034BC30_6 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0034BC30_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034BC30_9 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01E3C620 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B4CC {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2960 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B4C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineLoginToLobbyState {
public:
    void HandleConnectingEvents(EB3MenuFlowFSMEvents p0);

    unsigned char pad_0[0xAC];
    unsigned char field_AC;
    unsigned char pad_AD[0x7];
    int field_B4;
};

extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E9B6B8 D_01E9B6B8;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E3C620 D_01E3C620;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern CB3ErrorPage D_01E95B4C;
extern UnkStruct_D_01E9B4CC D_01E9B4CC;
extern CB3OnlineLoginToLobbyPage D_01E9B740;
extern UnkStruct_D_01EA2960 D_01EA2960;
extern UnkStruct_D_01E9B4C0 D_01E9B4C0;

extern "C" int GetAdapterErrorString__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetAdapterErrorString(int)
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetErrorString(int)
extern "C" void Prepare__24CB3OnlineSelectLoginPageFv(void *);  // CB3OnlineSelectLoginPage::Prepare()
extern "C" void Prepare__11CB3DNASPageFv(void *);  // CB3DNASPage::Prepare()
extern "C" void Prepare__23CB3OnlineConnectingPageFi(void *, int);  // CB3OnlineConnectingPage::Prepare(int)
extern "C" int func_0022D2D0(void *);
extern "C" void func_00270D00(void *);
extern "C" UnkStruct_0034BC30_8 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x0034BC30
void CB3OnlineLoginToLobbyState::HandleConnectingEvents(EB3MenuFlowFSMEvents p0)
{
    switch (p0) {
    case 20:
        field_B4 = 10;
        int r0 = func_0022D2D0(&D_01E3C620);
        if ((unsigned int)(r0 - 3) < 4) {
            D_01E95B4C.Prepare((EGlobalStrings)85, (EGlobalStrings)GetAdapterErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r0), (EB3MessageBoxType)7);
        } else {
            D_01E95B4C.Prepare((EGlobalStrings)85, (EGlobalStrings)GetAdapterErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r0), (EB3MessageBoxType)2);
        }
        break;
    case 21:
        field_B4 = 11;
        int r5 = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
        int r6 = GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r5);
        D_01E95B4C.Prepare((EGlobalStrings)82, (EGlobalStrings)r6, (EB3MessageBoxType)2);
        break;
    case 1:
        if (field_AC != 0) {
            field_B4 = 2;
            D_01E9B740.Prepare((char*)((char *)this + 0x10), (char*)((char *)this + 0x42), 0);
        } else {
            field_B4 = 1;
            Prepare__24CB3OnlineSelectLoginPageFv(&D_01E9B4CC);
        }
        break;
    case 17:
        Prepare__11CB3DNASPageFv(&D_01EA2960);
        break;
    case 18:
        Prepare__23CB3OnlineConnectingPageFi(&D_01E9B4C0, D_01E9B6B8.field_0);
        break;
    case 3:
        func_00270D00(&D_01E32AE0);
        UnkStruct_0034BC30_8 * r13 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F847A2EA);
        if (D_01EA2974.field_0 == r13) {
            break;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r13, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r13;
        UnkStruct_0034BC30_6 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r13 != 0) {
                r13->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
        break;
    default:
        break;
    }
}
