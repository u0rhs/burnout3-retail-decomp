// func_00391B80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if/else nest sharing return 0; bool ok else-if chain; static HasIntroFinished(); 0x12C-element array + 0xD8C byte offset (like func_0038E600); swap helper).

// lifter variant 0
// func_00391B80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00391B80;
struct UnkStruct_00391B80_12;
struct UnkStruct_00391B80_14;
struct UnkStruct_00391B80_15;
struct UnkStruct_00391B80_e0;
struct UnkStruct_D_004F50C0;
struct UnkStruct_D_004F6061;
struct UnkStruct_D_0051BAA4;
struct UnkStruct_D_0051BACC;
struct UnkStruct_D_00522660;
struct UnkStruct_D_00665E50;
struct UnkStruct_D_00665E51;
struct UnkStruct_D_00665EA0;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E78E50;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_004F6061 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00391B80_e0 {
    unsigned char pad_0[0x12C];
};

struct UnkStruct_D_004F50C0 {
    UnkStruct_00391B80_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_D_0051BACC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BAA4 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665EA0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665E50 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665E51 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    virtual void vfunc_18(UnkStruct_00391B80_14 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_00391B80_12 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00391B80_12 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00391B80_14 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00391B80_15 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E78E50 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00391B80 {
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
    virtual void vfunc_BC();
    virtual int vfunc_C0();
    unsigned char pad_4[0x4C];
    unsigned char field_50;
    unsigned char pad_51[0xD];
    unsigned char field_5E;
};

extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_D_0051BACC D_0051BACC;
extern UnkStruct_D_0051BAA4 D_0051BAA4;
extern UnkStruct_D_00665EA0 D_00665EA0;
extern UnkStruct_D_00665E50 D_00665E50;
extern UnkStruct_D_00665E51 D_00665E51;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_01E78E50 D_01E78E50;

extern "C" bool HasIntroFinished__22CB3PlayerCameraManagerFv();  // CB3PlayerCameraManager::HasIntroFinished()
extern "C" void func_0026FAA0(void *, int);
extern "C" void Stop__8CGtTimerFv(void *);
extern "C" void Start__8CGtTimerFv(void *);
extern "C" UnkStruct_00391B80_14 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_00276A20(void *);

static inline void a51_set(unsigned long h)
{
    UnkStruct_00391B80_14 * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * t1 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_00391B80_12 * t2 = D_01EA2980.field_0;
    if (t2 != 0) {
        D_01EA2984.field_0 = t2->field_20;
        if (r != 0) {
            r->field_8 = t2->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t1, 0);
}

// 0x00391B80
extern "C" int func_00391B80(UnkStruct_00391B80 * self, int p0, int p1)
{
    func_0026FAA0(&D_01E32AE0, 0);
    self->field_5E = p1;
    if (self->field_50 != 0) {
        if (D_0051BAA4.field_0 != 0) {
            if (p0 != 0) {
                D_00665E50.field_0 = 1;
                if (D_00665E50.field_0 != 0) {
                    Stop__8CGtTimerFv(&D_00522660);
                } else if (D_00665E51.field_0 == 0) {
                    Start__8CGtTimerFv(&D_00522660);
                }
                a51_set(0x94413E497BA7576B);
                if (self->vfunc_C0() == 0) {
                    func_00276A20(&D_01E78E50);
                }
            }
            self->field_50 = 0;
            return 1;
        }
    } else {
        bool ok = false;
        if (p1 == 0) {
            ok = true;
        } else if (*(short *)((char *)&D_004F50C0.field_0[D_004F6061.field_0] + 0xD8C) != 0) {
            ok = true;
        } else if (HasIntroFinished__22CB3PlayerCameraManagerFv()) {
            ok = true;
        }
        if (ok) {
            D_0051BACC.field_0 = 4;
            D_0051BAA4.field_0 = 0;
            D_00665EA0.field_0 = 0;
            self->field_50 = 1;
        }
    }
    return 0;
}
