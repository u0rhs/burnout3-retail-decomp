// func_00399600 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (swap block reads D_01EA2980 after the D_01EA2974 store; outer switch has default: return; first).

// lifter variant 0
// func_00399600 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00399600;
struct UnkStruct_00399600_10;
struct UnkStruct_00399600_4;
struct UnkStruct_00399600_6;
struct UnkStruct_00399600_7;
struct UnkStruct_00399600_8;
struct UnkStruct_00399600_9;
struct UnkStruct_D_01E9B634;
struct UnkStruct_D_01E9FC00;
struct UnkStruct_D_01E9FC04;
struct UnkStruct_D_01E9FC2C;
struct UnkStruct_D_01EA08A0;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_01E9FC2C {
    unsigned short field_0;
    unsigned char pad_2[0xE];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    UnkStruct_00399600_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00399600_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00399600_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00399600_7 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_00399600_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00399600_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00399600_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E9FC00 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B634 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9FC04 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA08A0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00399600 {
    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_D_01E9FC2C D_01E9FC2C;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E9FC00 D_01E9FC00;
extern UnkStruct_D_01E9B634 D_01E9B634;
extern UnkStruct_D_01E9FC04 D_01E9FC04;
extern UnkStruct_D_01EA08A0 D_01EA08A0;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_00397280(void *);
extern "C" void OnKeyboardShow__22CB3OnlineOpenLobbyPageFv(void *);
extern "C" void OnKeyboardCancel__22CB3OnlineOpenLobbyPageFv(void *);
extern "C" int func_00438520(void *, void *, int);
extern "C" int func_0043B4A0(void *, void *);

// 0x00399600
extern "C" void func_00399600(UnkStruct_00399600 * self, int p0)
{
    switch (p0) {
    default:
        return;
    case 1:
        switch (D_01E9FC2C.field_0) {
        case 0:
            UnkStruct_00399600_6 * r0 = (UnkStruct_00399600_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F84B7CB7);
            if (D_01EA2974.field_0 == r0) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r0, 0);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r0;
            UnkStruct_00399600_4 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r0 != 0) {
                    r0->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            return;
        case 1:
            UnkStruct_00399600_8 * r3 = (UnkStruct_00399600_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F84E7822);
            if (D_01EA2974.field_0 == r3) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r3, 0);
            void * t2 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r3;
            UnkStruct_00399600_4 * t3 = D_01EA2980.field_0;
            if (t3 != 0) {
                D_01EA2984.field_0 = t3->field_20;
                if (r3 != 0) {
                    r3->field_8 = t3->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
            return;
        }
        break;
    case 3:
        UnkStruct_00399600_9 * r6 = (UnkStruct_00399600_9 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8512871);
        if (D_01EA2974.field_0 == r6) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r6, 0);
        void * t4 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r6;
        UnkStruct_00399600_4 * t5 = D_01EA2980.field_0;
        if (t5 != 0) {
            D_01EA2984.field_0 = t5->field_20;
            if (r6 != 0) {
                r6->field_8 = t5->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t4, 0);
        break;
    case 27:
        func_00397280(&D_01E9FC00);
        break;
    case 25:
        OnKeyboardShow__22CB3OnlineOpenLobbyPageFv(&D_01E9FC00);
        break;
    case 26:
        OnKeyboardCancel__22CB3OnlineOpenLobbyPageFv(&D_01E9FC00);
        break;
    case 36:
        UnkStruct_00399600_10 * r12 = (UnkStruct_00399600_10 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E2F8A91F137);
        if (D_01EA2974.field_0 == r12) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r12, 0);
        void * t6 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r12;
        UnkStruct_00399600_4 * t7 = D_01EA2980.field_0;
        if (t7 != 0) {
            D_01EA2984.field_0 = t7->field_20;
            if (r12 != 0) {
                r12->field_8 = t7->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t6, 0);
        break;
    case 42:
        self->field_10 = 1;
        func_00438520(&D_01E9B634, &D_01E9FC04, 2);
        break;
    case 44:
        self->field_10 = 2;
        func_0043B4A0(&D_01EA08A0, &D_01E9FC04);
        break;
    }
}
