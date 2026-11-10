// CB3OnlineNewsState::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineNewsState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (func_0037A1B0 takes only a0 (phantom args dropped); inner switch on p2 with case 1 break; swap blocks store-then-load; outer default first).

// lifter variant 0
// CB3OnlineNewsState::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineNewsState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EGtStateAction {};

class CB3OnlineNewsState;
struct UnkStruct_003694C0_3;
struct UnkStruct_003694C0_5;
struct UnkStruct_003694C0_6;
struct UnkStruct_003694C0_7;
struct UnkStruct_D_01E9E018;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

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
    UnkStruct_003694C0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003694C0_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003694C0_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003694C0_6 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_003694C0_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E9E018 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineNewsState {
public:
    void Action(EGtStateAction p0, void* p1, void* p2, void* p3);
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E9E018 D_01E9E018;

extern "C" int func_0037A1B0(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003694C0
void CB3OnlineNewsState::Action(EGtStateAction p0, void* p1, void* p2, void* p3)
{
    switch (p0) {
    default:
        break;
    case 3:
        func_0037A1B0(&D_01E9E018);
        break;
    case 5:
        switch ((int)p2) {
        case 1:
            break;
        case 3:
            UnkStruct_003694C0_7 * r4 = (UnkStruct_003694C0_7 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8512871);
            if (D_01EA2974.field_0 == r4) {
                break;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r4, 0);
            void * t2 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r4;
            UnkStruct_003694C0_3 * t3 = D_01EA2980.field_0;
            if (t3 != 0) {
                D_01EA2984.field_0 = t3->field_20;
                if (r4 != 0) {
                    r4->field_8 = t3->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
            break;
        case 36:
            UnkStruct_003694C0_5 * r1 = (UnkStruct_003694C0_5 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E2F8A91F137);
            if (D_01EA2974.field_0 == r1) {
                break;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r1, 1);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r1;
            UnkStruct_003694C0_3 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r1 != 0) {
                    r1->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 1);
            break;
        }
        break;
    }
}
