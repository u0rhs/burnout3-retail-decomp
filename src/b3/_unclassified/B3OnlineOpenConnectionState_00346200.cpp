// CB3OnlineOpenConnectionState::HandleRetrieveConfigEvents(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineOpenConnectionState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (swap blocks store-then-load; early returns become break; default first; adapter-error range test (r-3)<3 with both arms inline).

// lifter variant 0
// CB3OnlineOpenConnectionState::HandleRetrieveConfigEvents(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineOpenConnectionState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EB3MenuFlowFSMEvents {};
enum EGlobalStrings {};
enum EB3MessageBoxType {};

class CB3ErrorPage;
class CB3OnlineOpenConnectionState;
class CB3OnlineRetrieveConfigsPage;
struct UnkStruct_00346200_12;
struct UnkStruct_00346200_3;
struct UnkStruct_00346200_5;
struct UnkStruct_00346200_6;
struct UnkStruct_00346200_8;
struct UnkStruct_D_0051BA90;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E3C620;
struct UnkStruct_D_01E6548B;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

class CB3ErrorPage {
public:
    void Prepare(EGlobalStrings, EGlobalStrings, EB3MessageBoxType);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineRetrieveConfigsPage {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_00346200_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00346200_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00346200_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00346200_6 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_D_01E3C620 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00346200_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_0051BA90 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E6548B {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00346200_12 {
    unsigned char pad_0[0x8];
    int field_8;
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineOpenConnectionState {
public:
    void HandleRetrieveConfigEvents(EB3MenuFlowFSMEvents p0);

    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E3C620 D_01E3C620;
extern UnkStruct_D_0051BA90 D_0051BA90;
extern UnkStruct_D_01E6548B D_01E6548B;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern CB3ErrorPage D_01E95B4C;
extern CB3OnlineRetrieveConfigsPage D_01E9B690;

extern "C" int GetAdapterErrorString__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetAdapterErrorString(int)
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_0022D2D0(void *);

// 0x00346200
void CB3OnlineOpenConnectionState::HandleRetrieveConfigEvents(EB3MenuFlowFSMEvents p0)
{
    switch (p0) {
    default:
        break;
    case 1:
        UnkStruct_00346200_5 * r0 = (UnkStruct_00346200_5 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8506BD2);
        if (D_01EA2974.field_0 == r0) {
            break;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r0, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r0;
        UnkStruct_00346200_3 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r0 != 0) {
                r0->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
        break;
    case 3:
        ((UnkStruct_D_01E3C620 *)&D_01E3C620)->vfunc_8();
        UnkStruct_00346200_8 * r4 = (UnkStruct_00346200_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC035B0F871);
        if (D_01EA2974.field_0 == r4) {
            break;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r4, 0);
        void * t2 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r4;
        UnkStruct_00346200_3 * t3 = D_01EA2980.field_0;
        if (t3 != 0) {
            D_01EA2984.field_0 = t3->field_20;
            if (r4 != 0) {
                r4->field_8 = t3->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
        break;
    case 20:
        field_10 = 2;
        int r7 = func_0022D2D0(&D_01E3C620);
        if ((unsigned int)(r7 - 3) < 3) {
            D_01E95B4C.Prepare((EGlobalStrings)85, (EGlobalStrings)GetAdapterErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r7), (EB3MessageBoxType)7);
        } else {
            D_01E95B4C.Prepare((EGlobalStrings)85, (EGlobalStrings)GetAdapterErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r7), (EB3MessageBoxType)2);
        }
        break;
    case 28:
        D_0051BA90.field_0 = 1;
        D_01E6548B.field_0 = 1;
        break;
    case 41:
        ((UnkStruct_D_01E3C620 *)&D_01E3C620)->vfunc_8();
        field_10 = 0;
        D_01E9B690.Prepare();
        break;
    }
}
