// func_0026DA60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (D_01EA2980 pointer read after the D_01EA2974 store (both inlined swap blocks)).

// lifter variant 0
// func_0026DA60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0026DA60_11;
struct UnkStruct_0026DA60_12;
struct UnkStruct_0026DA60_13;
struct UnkStruct_0026DA60_1;
struct UnkStruct_0026DA60_4;
struct UnkStruct_0026DA60_9;
struct UnkStruct_0026DA60_a1;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90430;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01EA2F0C;
struct UnkStruct_D_01EA2F0E;

struct UnkStruct_0026DA60_a1 {
    unsigned char pad_0[0x329AC];
    unsigned char field_329AC;
    unsigned char pad_329AD[0xC];
    unsigned char field_329B9;
    unsigned char field_329BA;
};

struct UnkStruct_0026DA60_1 {
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
};

struct UnkStruct_D_01EA2F0C {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2F0E {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0026DA60_4 {
    unsigned char pad_0[0x58];
    int field_58;
};

struct UnkStruct_D_01E90430 {
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
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_0026DA60_9 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0026DA60_9 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0026DA60_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0026DA60_12 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_0026DA60_13 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EA2F0C D_01EA2F0C;
extern UnkStruct_D_01EA2F0E D_01EA2F0E;
extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);  // CB3MenuPageManager::ReleaseCurrentMenu()
extern "C" void func_003608F0(void *);
extern "C" void func_00130C20(void *, unsigned long);
extern "C" void func_0041E9E0(void *);
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(UnkStruct_0026DA60_a1 *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x0026DA60
extern "C" int func_0026DA60(int n0, UnkStruct_0026DA60_a1 * p0)
{
    if (p0->field_329B9 != 0) {
        func_003608F0(((char *)p0 + 0xA8B0));
        ((UnkStruct_0026DA60_1 *)((char *)p0 + 0xA264))->vfunc_58();
        func_00130C20(&D_0051A6A8, 0x94413E70BF8E74AF);
        return 1;
    }
    if (p0->field_329BA == 0) {
        func_003608F0(((char *)p0 + 0xA8B0));
        func_0041E9E0(((char *)p0 + 0xFAC));
        p0->field_329AC = 0;
        D_01EA2F0C.field_0 = 0;
        D_01EA2F0E.field_0 = 0;
        ((UnkStruct_0026DA60_1 *)((char *)p0 + 0xA264))->vfunc_58();
        return 1;
    }
    D_01EA2F0C.field_0 = 0;
    D_01EA2F0E.field_0 = 0;
    func_003608F0(((char *)p0 + 0xA8B0));
    ClearAllPlayers__23CGtNetworkPlayerManagerFv(p0);
    if (D_01E90430.field_0 != 0) {
        ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
    }
    UnkStruct_0026DA60_11 * r9 = (UnkStruct_0026DA60_11 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x6D6123044330FCCF);
    if (D_01EA2974.field_0 != r9) {
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r9, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r9;
        UnkStruct_0026DA60_9 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r9 != 0) {
                r9->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
    }
    UnkStruct_0026DA60_13 * r12 = (UnkStruct_0026DA60_13 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E70BF8E74AF);
    if (D_01EA2974.field_0 != r12) {
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r12, 0);
        void * t2 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r12;
        UnkStruct_0026DA60_9 * t3 = D_01EA2980.field_0;
        if (t3 != 0) {
            D_01EA2984.field_0 = t3->field_20;
            if (r12 != 0) {
                r12->field_8 = t3->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
    }
    ((UnkStruct_0026DA60_1 *)((char *)p0 + 0xA264))->vfunc_58();
    return 1;
}
