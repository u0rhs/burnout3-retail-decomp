// CB3OnlineRankingsState::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineRankingsState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (re-queued after the jtbl_retarget 2-table fix (from build/vt/hand/Action__22CB3OnlineRankingsState_5de1ccb_l255r2.cpp)).

// CB3OnlineRankingsState::Action(EGtStateAction,void*,void*,void*)
// [C] name: the mangled symbol in retail's tables. Hand-written (L255) after the matched sibling
// B3OnlineNewsState_003694C0.cpp (same menu FSM D_01EA2970; SetScene inline as B3OnlineMenuState_00323E30.cpp).
// field_10 = page index (jump tables on it), field_11 = record kind [G]. Case-5 default exits via `goto out` (L243 pattern):
// `return;` there leaves a dead `b; ld ra` block.

enum EGtStateAction {};
enum EGlobalStrings {};
enum EB3MessageBoxType {};

struct UnkStruct_D_01EA2970 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_r { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_s { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2980 { UnkStruct_s * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_L { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_H { unsigned short field_0; unsigned char pad_2[0xE]; };

class CB3ErrorPage {
public:
    void Prepare(EGlobalStrings, EGlobalStrings, EB3MessageBoxType);
    unsigned char pad_0[0x10];
};
class CGtLobbyPS2DirtySock {
public:
    int PrepareRanking(char *);
    unsigned char pad_0[0x10];
};

class CB3OnlineRankingsState {
public:
    void Action(EGtStateAction p0, void * p1, void * p2, void * p3);

    unsigned char pad_0[0x10];
    signed char field_10;
    signed char field_11;
};

extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern CGtLobbyPS2DirtySock D_01E3CD44;
extern CB3ErrorPage D_01E95B4C;
extern char D_004C80D0[];
extern UnkStruct_P D_01E9B8C0;
extern UnkStruct_P D_01EA14C0;
extern UnkStruct_P D_01E9B924;
extern UnkStruct_P D_01E9E000;
extern UnkStruct_P D_01E9B940;
extern UnkStruct_P D_01EA08A0;
extern UnkStruct_P D_01E9B944;
extern UnkStruct_L D_01EA14C8;
extern UnkStruct_L D_01EA14D0;
extern UnkStruct_H D_01E9B8C4;
extern UnkStruct_H D_01E9B928;
extern UnkStruct_H D_01E9E004;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_00371270(void *);
extern "C" int func_004556D0(void *);
extern "C" int func_00376470(void *, unsigned long);
extern "C" int func_00379140(void *, unsigned long);
extern "C" int func_00378C00(void *, int, unsigned long);
extern "C" int func_0043B4A0(void *, void *);
extern "C" int func_00336DF0(void *);
extern "C" int func_0036A680(void *, void *);
extern "C" int func_0036A510(void *, void *);
extern "C" int func_0036A3A0(void *, void *);
extern "C" int func_0036A230(void *, void *);
extern "C" int func_00369F80(void *, void *);

static inline void SetScene(unsigned long h, int k)
{
    UnkStruct_r * r = (UnkStruct_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, k);
    void * t = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_s * s = D_01EA2980.field_0;
    if (s != 0) {
        D_01EA2984.field_0 = s->field_20;
        if (r != 0) {
            r->field_8 = s->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t, k);
}

// 0x00369690
void CB3OnlineRankingsState::Action(EGtStateAction p0, void * p1, void * p2, void * p3)
{
    switch (p0) {
    case 0:
        field_10 = 0;
        break;
    case 3:
        if (*(unsigned long *)p2 == 0x94413E2F8A91F137UL) {
            if (D_01E3CD44.PrepareRanking(D_004C80D0) != 0) {
            switch (field_10) {
            case 0:
            default:
                func_00371270(&D_01E9B8C0);
                break;
            case 1:
                func_004556D0(&D_01EA14C0);
                break;
            case 2:
                func_00376470(&D_01E9B924, D_01EA14C8.field_0);
                break;
            case 3:
                func_00379140(&D_01E9E000, D_01EA14D0.field_0);
                break;
            case 4:
                switch (D_01E9B8C4.field_0) {
                case 0:
                default:
                    func_00378C00(&D_01E9B940, 0, 0);
                    break;
                case 1:
                    func_00378C00(&D_01E9B940, 1, 0);
                    break;
                case 2:
                    func_00378C00(&D_01E9B940, 2, 0);
                    break;
                case 3:
                    func_00378C00(&D_01E9B940, 3, 0);
                    break;
                case 4:
                    func_00378C00(&D_01E9B940, 4, 0);
                    break;
                }
                break;
            case 5:
                {
                    unsigned long id = D_01EA14C8.field_0;
                    if (D_01E9B928.field_0 != 1) {
                        func_00378C00(&D_01E9B940, 5, id);
                    } else {
                        func_00378C00(&D_01E9B940, 6, id);
                    }
                }
                break;
            case 6:
                {
                    unsigned long id = D_01EA14D0.field_0;
                    if (D_01E9E004.field_0 != 1) {
                        func_00378C00(&D_01E9B940, 7, id);
                    } else {
                        func_00378C00(&D_01E9B940, 8, id);
                    }
                }
                break;
            case 7:
                break;
            case 8:
                func_0043B4A0(&D_01EA08A0, &D_01E9B944);
                break;
            }
            } else {
                field_10 = 7;
                D_01E95B4C.Prepare((EGlobalStrings)0x72, (EGlobalStrings)0x464, (EB3MessageBoxType)2);
            }
        } else {
            if (D_01E3CD44.PrepareRanking(D_004C80D0) == 0) {
                field_10 = 7;
                D_01E95B4C.Prepare((EGlobalStrings)0x72, (EGlobalStrings)0x464, (EB3MessageBoxType)2);
            } else {
                field_10 = 0;
                func_00371270(&D_01E9B8C0);
            }
        }
        break;
    case 2:
        func_00336DF0(&D_01E3CD44);
        break;
    case 5:
        switch (field_10) {
        case 0:
            func_0036A680(this, p2);
            break;
        case 1:
            func_0036A510(this, p2);
            break;
        case 2:
            func_0036A3A0(this, p2);
            break;
        case 3:
            func_0036A230(this, p2);
            break;
        case 4:
            switch ((int)p2) {
            case 1:
            case 2:
            case 0:
                return;
            case 3:
                field_10 = 0;
                func_00371270(&D_01E9B8C0);
                break;
            case 0x2C:
                field_11 = 4;
                func_0043B4A0(&D_01EA08A0, &D_01E9B944);
                field_10 = 8;
                break;
            case 0x24:
                SetScene(0x94413E2F8A91F137UL, 1);
                break;
            }
            break;
        case 5:
            switch ((int)p2) {
            case 1:
            case 2:
            case 0:
                return;
            case 3:
                field_10 = 2;
                func_00376470(&D_01E9B924, D_01EA14C8.field_0);
                break;
            case 0x2C:
                field_11 = 5;
                func_0043B4A0(&D_01EA08A0, &D_01E9B944);
                field_10 = 8;
                break;
            case 0x24:
                SetScene(0x94413E2F8A91F137UL, 1);
                break;
            }
            break;
        case 6:
            switch ((int)p2) {
            case 1:
            case 2:
            case 0:
                return;
            case 3:
                field_10 = 3;
                func_00379140(&D_01E9E000, D_01EA14D0.field_0);
                break;
            case 0x2C:
                field_11 = 6;
                func_0043B4A0(&D_01EA08A0, &D_01E9B944);
                field_10 = 8;
                break;
            case 0x24:
                SetScene(0x94413E2F8A91F137UL, 1);
                break;
            }
            break;
        case 7:
            switch ((int)p2) {
            default:
            case 1:
            case 2:
            case 0:
                SetScene(0x94414018F8512871UL, 0);
                break;
            case 0x24:
                SetScene(0x94413E2F8A91F137UL, 1);
                break;
            }
            break;
        case 8:
            func_00369F80(this, p2);
            break;
        default:
            goto out;
        }
        break;
    }
out:;
}
