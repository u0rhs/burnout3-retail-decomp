// func_0030E340 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (swap blocks: D_01EA2974 store before the D_01EA2980 read (x5); func_0013B730 one arg).

// func_0030E340 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3InputManager;
class CB3MenuFlowFSM;
struct UnkStruct_0030E340_10;
struct UnkStruct_0030E340_11;
struct UnkStruct_0030E340_13;
struct UnkStruct_0030E340_14;
struct UnkStruct_0030E340_6;
struct UnkStruct_0030E340_8;
struct UnkStruct_0030E340_9;
struct UnkStruct_D_00516DF4;
struct UnkStruct_D_00516E18;
struct UnkStruct_D_0051AEC0;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01E6549A;
struct UnkStruct_D_01E900B4;
struct UnkStruct_D_01E94C44;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

class CB3InputManager {
public:
    void LockPlayerToPort(signed char, signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3MenuFlowFSM {
public:
    void GetMenuFlowType();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E94C44 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E900B4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2974 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_0030E340_6 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030E340_6 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030E340_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0030E340_9 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_0030E340_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0030E340_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E6549A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030E340_13 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0030E340_14 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00516DF4 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00516E18 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051AEC0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E94C44 D_01E94C44;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01E900B4 D_01E900B4;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern CB3MenuFlowFSM D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E6549A D_01E6549A;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_00516DF4 D_00516DF4;
extern UnkStruct_D_00516E18 D_00516E18;
extern UnkStruct_D_0051AEC0 D_0051AEC0;

extern "C" int func_00271A00(void *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(void *, int, int);
extern "C" int func_0013B730(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_0013B6A0(int, int);
extern "C" void func_0013C8E0(void *);

// 0x0030E340
extern "C" void func_0030E340(void *n0_, int p0)
{
    int n0 = (int)n0_;
    D_004F50C0.LockPlayerToPort(0, ((signed char)p0));
    int t0 = D_01E94C44.field_0;
    switch (t0) {
    case 0:
        int t1 = D_0051BF9C.field_0;
        if (t1 == 0) {
            int r1 = func_00271A00(&D_0051BA44, 441);
            CopyN__10CGtUnicodeFPUsiPCUs(&D_00516DF4, 9, r1);
        } else {
            int r3 = func_0013B730((void *)(t1));
            CopyN__10CGtUnicodeFPUsiPCUs(&D_00516DF4, 9, r3);
        }
        D_01E900B4.field_0 = 0;
        D_01EA2970.GetMenuFlowType();
        UnkStruct_0030E340_8 * r6 = (UnkStruct_0030E340_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E52C3BF9CAA);
        if (D_01EA2974.field_0 == r6) {
            return;
        }
        ((CB3MenuFlowFSM *)&D_01EA2970)->vfunc_18(r6, 0);
        void * t2 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r6;
        UnkStruct_0030E340_6 * t3 = D_01EA2980.field_0;
        if (t3 != 0) {
            D_01EA2984.field_0 = t3->field_20;
            if (r6 != 0) {
                r6->field_8 = t3->field_20;
            }
        }
        ((CB3MenuFlowFSM *)&D_01EA2970)->vfunc_1C(t2, 0);
        break;
    case 1:
        int t4 = D_0051BF9C.field_0;
        if (t4 == 0) {
            int r9 = func_00271A00(&D_0051BA44, 441);
            CopyN__10CGtUnicodeFPUsiPCUs(&D_00516DF4, 9, r9);
        } else {
            int r11 = func_0013B730((void *)(t4));
            CopyN__10CGtUnicodeFPUsiPCUs(&D_00516DF4, 9, r11);
        }
        D_01E900B4.field_0 = 1;
        UnkStruct_0030E340_10 * r13 = (UnkStruct_0030E340_10 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413CAD86353F29);
        if (D_01EA2974.field_0 == r13) {
            return;
        }
        ((CB3MenuFlowFSM *)&D_01EA2970)->vfunc_18(r13, 0);
        void * t5 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r13;
        UnkStruct_0030E340_6 * t6 = D_01EA2980.field_0;
        if (t6 != 0) {
            D_01EA2984.field_0 = t6->field_20;
            if (r13 != 0) {
                r13->field_8 = t6->field_20;
            }
        }
        ((CB3MenuFlowFSM *)&D_01EA2970)->vfunc_1C(t5, 0);
        break;
    case 2:
        int t7 = D_0051BF9C.field_0;
        if (t7 == 0) {
            int r16 = func_00271A00(&D_0051BA44, 441);
            CopyN__10CGtUnicodeFPUsiPCUs(&D_00516DF4, 9, r16);
            int r18 = func_00271A00(&D_0051BA44, 442);
            CopyN__10CGtUnicodeFPUsiPCUs(&D_00516E18, 9, r18);
        } else {
            int r20 = func_0013B6A0(t7, 0);
            CopyN__10CGtUnicodeFPUsiPCUs(&D_00516DF4, 9, r20);
            int r22 = func_0013B6A0(t7, 1);
            CopyN__10CGtUnicodeFPUsiPCUs(&D_00516E18, 9, r22);
        }
        func_0013C8E0(&D_0051AEC0);
        D_01E900B4.field_0 = 2;
        UnkStruct_0030E340_11 * r25 = (UnkStruct_0030E340_11 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413CD3ABD53F29);
        if (D_01EA2974.field_0 == r25) {
            return;
        }
        ((CB3MenuFlowFSM *)&D_01EA2970)->vfunc_18(r25, 0);
        void * t8 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r25;
        UnkStruct_0030E340_6 * t9 = D_01EA2980.field_0;
        if (t9 != 0) {
            D_01EA2984.field_0 = t9->field_20;
            if (r25 != 0) {
                r25->field_8 = t9->field_20;
            }
        }
        ((CB3MenuFlowFSM *)&D_01EA2970)->vfunc_1C(t8, 0);
        break;
    case 3:
        int t10 = D_0051BF9C.field_0;
        if (t10 == 0) {
            int r28 = func_00271A00(&D_0051BA44, 441);
            CopyN__10CGtUnicodeFPUsiPCUs(&D_00516DF4, 9, r28);
        } else {
            int r30 = func_0013B730((void *)(t10));
            CopyN__10CGtUnicodeFPUsiPCUs(&D_00516DF4, 9, r30);
        }
        D_01E6549A.field_0 = 1;
        D_01E900B4.field_0 = 3;
        UnkStruct_0030E340_13 * r32 = (UnkStruct_0030E340_13 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F847A2EA);
        if (D_01EA2974.field_0 == r32) {
            return;
        }
        ((CB3MenuFlowFSM *)&D_01EA2970)->vfunc_18(r32, 0);
        void * t11 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r32;
        UnkStruct_0030E340_6 * t12 = D_01EA2980.field_0;
        if (t12 != 0) {
            D_01EA2984.field_0 = t12->field_20;
            if (r32 != 0) {
                r32->field_8 = t12->field_20;
            }
        }
        ((CB3MenuFlowFSM *)&D_01EA2970)->vfunc_1C(t11, 0);
        break;
    case 4:
        UnkStruct_0030E340_14 * r35 = (UnkStruct_0030E340_14 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FD6EF6E02D9);
        if (D_01EA2974.field_0 == r35) {
            return;
        }
        ((CB3MenuFlowFSM *)&D_01EA2970)->vfunc_18(r35, 2);
        void * t13 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r35;
        UnkStruct_0030E340_6 * t14 = D_01EA2980.field_0;
        if (t14 != 0) {
            D_01EA2984.field_0 = t14->field_20;
            if (r35 != 0) {
                r35->field_8 = t14->field_20;
            }
        }
        ((CB3MenuFlowFSM *)&D_01EA2970)->vfunc_1C(t13, 2);
        break;
    default:
        break;
    }
}
