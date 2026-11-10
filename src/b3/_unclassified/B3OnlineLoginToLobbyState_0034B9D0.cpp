// CB3OnlineLoginToLobbyState::HandleSelectLoginEvents(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLoginToLobbyState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (D_01E9B534.field_0 is a bool (passed straight to Prepare's bool); case 1 as if (== 1) {state change} else {Prepare}; default first; FSM global declared non-polymorphic).

// CB3OnlineLoginToLobbyState::HandleSelectLoginEvents(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLoginToLobbyState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EB3MenuFlowFSMEvents {};

class CB3OnlineLoginToLobbyPage;
class CB3OnlineLoginToLobbyState;
class CB3OnlineSelectLoginPage;
struct UnkStruct_0034B9D0_10;
struct UnkStruct_0034B9D0_6;
struct UnkStruct_0034B9D0_8;
struct UnkStruct_0034B9D0_9;
struct UnkStruct_D_01E9B4D0;
struct UnkStruct_D_01E9B502;
struct UnkStruct_D_01E9B534;
struct UnkStruct_D_01E9B5BC;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

class CB3OnlineLoginToLobbyPage {
public:
    void Prepare(char*, char*, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineSelectLoginPage {
public:
    void OnKeyboardShow();
    void OnKeyboardCancel();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B5BC {
    unsigned short field_0;
    unsigned char pad_2[0xE];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B534 {
    bool field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2974 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2970_g {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    UnkStruct_0034B9D0_6 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0034B9D0_6 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0034B9D0_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034B9D0_9 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_0034B9D0_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E9B4D0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B502 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineLoginToLobbyState {
public:
    void HandleSelectLoginEvents(EB3MenuFlowFSMEvents p0);

    unsigned char pad_0[0xB4];
    int field_B4;
};

extern UnkStruct_D_01E9B5BC D_01E9B5BC;
extern UnkStruct_D_01E9B534 D_01E9B534;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E9B4D0 D_01E9B4D0;
extern UnkStruct_D_01E9B502 D_01E9B502;
extern CB3OnlineLoginToLobbyPage D_01E9B740;
extern CB3OnlineSelectLoginPage D_01E9B4CC;

extern "C" char * strcpy(char *, const char *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_00347940(void *);

// 0x0034B9D0
void CB3OnlineLoginToLobbyState::HandleSelectLoginEvents(EB3MenuFlowFSMEvents p0)
{
    switch (p0) {
    default:
        break;
    case 1:
        if (D_01E9B5BC.field_0 == 1) {
            UnkStruct_0034B9D0_8 * r = (UnkStruct_0034B9D0_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E52D9756028);
            if (D_01EA2974.field_0 == r) {
                break;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r;
            UnkStruct_0034B9D0_6 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r != 0) {
                    r->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
        } else {
            field_B4 = 2;
            D_01E9B740.Prepare((char*)&D_01E9B4D0, (char*)&D_01E9B502, D_01E9B534.field_0);
            strcpy((char *)this + 0x10, (const char *)&D_01E9B4D0);
            strcpy((char *)this + 0x42, (const char *)&D_01E9B502);
        }
        break;
    case 3: {
        UnkStruct_0034B9D0_8 * r = (UnkStruct_0034B9D0_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC035B0F871);
        if (D_01EA2974.field_0 == r) {
            break;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r;
        UnkStruct_0034B9D0_6 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r != 0) {
                r->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
        break;
    }
    case 27:
        func_00347940(&D_01E9B4CC);
        break;
    case 25:
        D_01E9B4CC.OnKeyboardShow();
        break;
    case 26:
        D_01E9B4CC.OnKeyboardCancel();
        break;
    }
}
