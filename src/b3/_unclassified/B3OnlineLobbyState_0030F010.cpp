// CB3OnlineLobbyState::HandleInLobbyEvents(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rebuilt player loop (bool found declared before vfunc_BC, r==0 arm first, found=true before the store), D_01EA2974 store before D_01EA2980 read).

// lifter variant 0
// CB3OnlineLobbyState::HandleInLobbyEvents(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EB3MenuFlowFSMEvents {};

class CB3MenuChoices;
class CB3OnlineLobbyPage;
class CB3OnlineLobbyState;
struct UnkStruct_0030F010_16;
struct UnkStruct_0030F010_20;
struct UnkStruct_0030F010_23;
struct UnkStruct_0030F010_4;
struct UnkStruct_0030F010_6;
struct UnkStruct_0030F010_7;
struct UnkStruct_0030F010_8;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E32B08;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E3D390;
struct UnkStruct_D_01E3D578;
struct UnkStruct_D_01E3D580;
struct UnkStruct_D_01E3D58A;
struct UnkStruct_D_01E900CC;
struct UnkStruct_D_01E90130;
struct UnkStruct_D_01E90170;
struct UnkStruct_D_01E90227;
struct UnkStruct_D_01E984E0;
struct UnkStruct_D_01E99770;
struct UnkStruct_D_01E9B634;
struct UnkStruct_D_01EA0070;
struct UnkStruct_D_01EA08A0;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

class CB3MenuChoices {
public:
    void RequestNewGameMode();

    unsigned char pad_0[0x80];
    unsigned long field_80[1];  // [G] element count unknown
    unsigned char pad_88[0x38];
    int field_C0[1];  // [G] element count unknown
};

class CB3OnlineLobbyPage {
public:
    void OnKeyboardDone();
    void OnKeyboardShow();
    void OnKeyboardCancel();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90130 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    UnkStruct_0030F010_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030F010_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030F010_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0030F010_7 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_0030F010_8 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x28];
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
    virtual void vfunc_BC(UnkStruct_0030F010_8 *);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32B08 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E900CC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D578 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D580 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90170 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D58A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030F010_16 {
    unsigned char pad_0[0x4D8];
    unsigned long field_4D8;
    int field_4E0;
    unsigned char pad_4E4[0x6];
    unsigned char field_4EA;
};

struct UnkStruct_0030F010_20 {
    unsigned char pad_0[0x2C];
    int field_2C;
};

struct UnkStruct_D_01E90227 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030F010_23 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D390 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA0070 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E99770 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B634 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E984E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA08A0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineLobbyState {
public:
    void HandleInLobbyEvents(EB3MenuFlowFSMEvents p0);

    unsigned char pad_0[0x10];
    unsigned char field_10;
};

extern UnkStruct_D_01E90130 D_01E90130;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_01E900CC D_01E900CC;
extern UnkStruct_D_01E3D578 D_01E3D578;
extern UnkStruct_D_01E3D580 D_01E3D580;
extern UnkStruct_D_01E90170 D_01E90170;
extern UnkStruct_D_01E3D58A D_01E3D58A;
extern CB3MenuChoices D_01E900B0;
extern UnkStruct_D_01E90227 D_01E90227;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern CB3OnlineLobbyPage D_01E98490;
extern UnkStruct_D_01EA0070 D_01EA0070;
extern UnkStruct_D_01E99770 D_01E99770;
extern UnkStruct_D_01E9B634 D_01E9B634;
extern UnkStruct_D_01E984E0 D_01E984E0;
extern UnkStruct_D_01EA08A0 D_01EA08A0;

extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *, EB3MenuFlowFSMEvents);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" UnkStruct_0030F010_16 * func_002366D0(void *, int);
extern "C" int func_003607C0(void *);
extern "C" void func_0026DE80(void *, int);
extern "C" void func_0030ED90(CB3OnlineLobbyState *);
extern "C" int func_003A03B0(void *, int, void *);
extern "C" int func_00438520(void *, void *, int);
extern "C" int func_0043B4A0(void *, void *);

// 0x0030F010
void CB3OnlineLobbyState::HandleInLobbyEvents(EB3MenuFlowFSMEvents p0)
{
    UnkStruct_0030F010_8 local;  // [G] the frame's one local (size: up to the frame top)
    switch (p0) {
    case 29:
        D_01E90130.field_0 = 0;
        ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0, p0);
        UnkStruct_0030F010_6 * r1 = (UnkStruct_0030F010_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8535FC2);
        if (D_01EA2974.field_0 == r1) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r1, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r1;
        UnkStruct_0030F010_4 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r1 != 0) {
                r1->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
        break;
    case 1:
    case 2:
    case 0:
        bool found = false;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC(&local);
        D_01E900CC.field_0 = D_01E32B08.field_0;
        for (int i = 0; i < D_01E900CC.field_0; i++) {
            UnkStruct_0030F010_16 * r = func_002366D0(&D_01E32AE0, i);
            if (r == 0) {
                found = true;
                D_01E90130.field_0 = D_01E3D578.field_0;
                if (local.field_14 == 1) {
                    if (D_01E3D58A.field_0 != 0) {
                        D_01E90170.field_0 = 6;
                    } else {
                        D_01E90170.field_0 = 7;
                    }
                } else {
                    D_01E90170.field_0 = D_01E3D580.field_0;
                }
            } else {
                int idx;
                if (found) {
                    idx = i;
                } else {
                    idx = i + 1;
                }
                D_01E900B0.field_80[idx] = r->field_4D8;
                if (local.field_14 == 1) {
                    if (r->field_4EA != 0) {
                        D_01E900B0.field_C0[idx] = 6;
                    } else {
                        D_01E900B0.field_C0[idx] = 7;
                    }
                } else {
                    D_01E900B0.field_C0[idx] = r->field_4E0;
                }
            }
        }
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_2C();
        func_003607C0(&D_01E3D390);
        D_01E90227.field_0 = 1;
        func_0026DE80(&D_01E32AE0, 1);
        D_01E900B0.RequestNewGameMode();
        break;
    case 30:
        field_10 = 0;
        func_0030ED90(this);
        break;
    case 27:
        D_01E98490.OnKeyboardDone();
        break;
    case 25:
        D_01E98490.OnKeyboardShow();
        break;
    case 26:
        D_01E98490.OnKeyboardCancel();
        break;
    case 35:
        field_10 = 2;
        func_003A03B0(&D_01EA0070, 0, &D_01E99770);
        break;
    case 36:
        UnkStruct_0030F010_23 * r15 = (UnkStruct_0030F010_23 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E2F8A91F137);
        if (D_01EA2974.field_0 == r15) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r15, 0);
        void * t4 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r15;
        UnkStruct_0030F010_4 * t5 = D_01EA2980.field_0;
        if (t5 != 0) {
            D_01EA2984.field_0 = t5->field_20;
            if (r15 != 0) {
                r15->field_8 = t5->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t4, 0);
        break;
    case 42:
        field_10 = 4;
        func_00438520(&D_01E9B634, &D_01E984E0, 0);
        break;
    case 44:
        field_10 = 4;
        func_0043B4A0(&D_01EA08A0, &D_01E984E0);
        break;
    default:
        break;
    }
}
