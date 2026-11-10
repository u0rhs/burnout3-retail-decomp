// CB3PauseState::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PauseState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (Rewritten: nested switch in source order 6,8,7,11,76,77 (case 8 falls into 7), swap block as static inline with early return, shared tail after the inner switch, case 3 flag as a bool passed to a bool parameter (daddiu)).

// lifter variant 0
// CB3PauseState::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PauseState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EGtStateAction {};

class CB3PauseState;
struct UnkStruct_003428D0_10;
struct UnkStruct_003428D0_13;
struct UnkStruct_003428D0_14;
struct UnkStruct_003428D0_15;
struct UnkStruct_003428D0_17;
struct UnkStruct_003428D0_18;
struct UnkStruct_003428D0_19;
struct UnkStruct_003428D0_20;
struct UnkStruct_003428D0_21;
struct UnkStruct_003428D0_22;
struct UnkStruct_003428D0_23;
struct UnkStruct_003428D0_24;
struct UnkStruct_003428D0_26;
struct UnkStruct_003428D0_27;
struct UnkStruct_003428D0_3;
struct UnkStruct_003428D0_5;
struct UnkStruct_003428D0_6;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_0051B928;
struct UnkStruct_D_0051B930;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_0051BA94;
struct UnkStruct_D_0051BA9C;
struct UnkStruct_D_0051BACC;
struct UnkStruct_D_00665E52;
struct UnkStruct_D_00665F2B;
struct UnkStruct_D_01E94C94;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01EA2A00;
struct UnkStruct_D_01EA2C68;
struct UnkStruct_D_01ECD9F0;

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
    UnkStruct_003428D0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003428D0_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003428D0_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003428D0_6 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_D_0051BA94 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003428D0_10 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003428D0_10 {
    unsigned char pad_0[0x1B8];
    UnkStruct_003428D0_15 * field_1B8;
};

struct UnkStruct_D_0051BACC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665E52 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003428D0_13 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003428D0_14 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003428D0_15 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
};

struct UnkStruct_D_0051B930 {
    UnkStruct_003428D0_17 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003428D0_17 {
    unsigned char pad_0[0x30];
    int field_30;
};

struct UnkStruct_003428D0_18 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003428D0_19 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003428D0_20 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
};

struct UnkStruct_003428D0_21 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003428D0_22 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003428D0_23 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
};

struct UnkStruct_003428D0_24 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_00665F2B {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003428D0_26 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003428D0_27 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01EA2C68 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2A00 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E94C94 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051B928 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD9F0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3PauseState {
public:
    void Action(EGtStateAction p0, void* p1, void* p2, void* p3);
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_0051BA94 D_0051BA94;
extern UnkStruct_D_0051BA9C D_0051BA9C;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051BACC D_0051BACC;
extern UnkStruct_D_00665E52 D_00665E52;
extern UnkStruct_D_0051B930 D_0051B930;
extern UnkStruct_D_00665F2B D_00665F2B;
extern UnkStruct_D_01EA2C68 D_01EA2C68;
extern UnkStruct_D_01EA2A00 D_01EA2A00;
extern UnkStruct_D_01E94C94 D_01E94C94;
extern UnkStruct_D_0051B928 D_0051B928;
extern UnkStruct_D_01ECD9F0 D_01ECD9F0;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" void func_00342410(void *, int, bool, void*, void*);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_003BAE10(void *, int);
extern "C" void func_0042F790(void *);
extern "C" void func_00130C20(void *, unsigned long);
extern "C" void func_00131F10(void *, void *);
extern "C" int func_00131E40(void *);

// [G] the inlined swap block (as in func_003EB0F0 / CB3MyBurnoutRewardsState::Action)
static inline void func_003428D0_inl1(unsigned long id, int mode)
{
    UnkStruct_003428D0_5 * r = (UnkStruct_003428D0_5 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, id);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, mode);
    void * t1 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_003428D0_3 * t2 = D_01EA2980.field_0;
    if (t2 != 0) {
        D_01EA2984.field_0 = t2->field_20;
        if (r != 0) {
            r->field_8 = t2->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t1, mode);
}

// 0x003428D0
void CB3PauseState::Action(EGtStateAction p0, void* p1, void* p2, void* p3)
{
    switch (p0) {
    case 3: {
        bool v = true;
        if (p2 == &D_01EA2C68 || p2 == &D_01EA2A00) {
            v = false;
        }
        func_00342410(&D_01E94C94, 0, v, p2, p3);
        break;
    }
    case 5:
        switch ((int)p2) {
        case 6:
            func_003428D0_inl1(0x94413EDB6B01A028, 0);
            break;
        case 8:
            if ((void *)D_0051BA88.field_0->field_1B8 == (void *)&D_0051B928 && D_0051B930.field_0->field_30 == 2) {
                func_003BAE10(&D_0051B928, 0);
                break;
            }
        case 7:
            if (D_0051BA88.field_0 != 0 && D_0051BA88.field_0->field_1B8 != 0) {
                D_0051BA88.field_0->field_1B8->vfunc_20();
            } else {
                D_0051BACC.field_0 = 7;
                D_00665E52.field_0 = 0;
                func_003428D0_inl1(0x94413FA737AAA797, 0);
            }
            break;
        case 11:
            func_0042F790(&D_01ECD9F0);
            func_003428D0_inl1(0x94413FA737AAA797, 0);
            func_00130C20(&D_0051A6A8, 0x94413E09C8514CA1);
            func_00131F10(&D_004EE040, &D_0051A6A8);
            if (func_00131E40(&D_004EE040) != 0) {
                D_00665F2B.field_0 = 1;
            }
            break;
        case 76:
            func_003428D0_inl1(0x94413FC165857D40, 1);
            return;
        case 77:
            func_003428D0_inl1(0x94413FC165857D40, 3);
            return;
        }
        if (D_0051BA94.field_0 >= 0) {
            D_0051BA9C.field_0 = D_0051BA94.field_0;
        }
        break;
    }
}
