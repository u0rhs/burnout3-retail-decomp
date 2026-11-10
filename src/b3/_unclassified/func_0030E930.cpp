// func_0030E930 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (default first; swap block store-then-load and ends in return (case 4 too); inner switch on p2 (case 0 then case 3 return); t0 != 0 arm first).

// func_0030E930 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3InputManager;
struct UnkStruct_0030E930;
struct UnkStruct_0030E930_13;
struct UnkStruct_0030E930_15;
struct UnkStruct_0030E930_16;
struct UnkStruct_D_004F50A0;
struct UnkStruct_D_0051A998;
struct UnkStruct_D_01E3D597;
struct UnkStruct_D_01E6549A;
struct UnkStruct_D_01E94C40;
struct UnkStruct_D_01E94C48;
struct UnkStruct_D_01E94C49;
struct UnkStruct_D_01E94C4A;
struct UnkStruct_D_01E94C4B;
struct UnkStruct_D_01E94C4C;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

class CB3InputManager {
public:
    void ResetDeadInputTime(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F50A0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A998 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E6549A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E94C48 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E94C49 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D597 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E94C4A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E94C4B {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E94C4C {
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
    virtual void vfunc_18(UnkStruct_0030E930_15 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_0030E930_13 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030E930_13 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030E930_15 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0030E930_16 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01E94C40 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030E930 {
    unsigned char pad_0[0x10];
    float field_10;
};

extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_0051A998 D_0051A998;
extern UnkStruct_D_01E6549A D_01E6549A;
extern UnkStruct_D_01E94C48 D_01E94C48;
extern UnkStruct_D_01E94C49 D_01E94C49;
extern UnkStruct_D_01E3D597 D_01E3D597;
extern UnkStruct_D_01E94C4A D_01E94C4A;
extern UnkStruct_D_01E94C4B D_01E94C4B;
extern UnkStruct_D_01E94C4C D_01E94C4C;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E94C40 D_01E94C40;
extern CB3InputManager D_004F50C0;

extern "C" void func_00318520(void *);
extern "C" void func_00214380(void *);
extern "C" int func_00318340(void *);
extern "C" UnkStruct_0030E930_15 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_0030E340(UnkStruct_0030E930 *, int);

// 0x0030E930
extern "C" void func_0030E930(UnkStruct_0030E930 * self, int p0, int p1, int p2, int p3)
{
    switch (p0) {
    default:
        break;
    case 0:
        func_00318520(&D_01E94C40);
        break;
    case 3:
        self->field_10 = D_004F50A0.field_0;
        D_004F50C0.ResetDeadInputTime(-1);
        if (D_0051A998.field_0 == 0) {
            func_00214380(&D_004F50C0);
            D_01E6549A.field_0 = 0;
            D_01E94C48.field_0 = 0;
            D_01E94C49.field_0 = 0;
            unsigned char t0 = D_01E3D597.field_0;
            D_01E94C4A.field_0 = 0;
            if (t0 != 0) {
                D_01E94C4B.field_0 = 0;
            } else {
                D_01E94C4B.field_0 = 1;
            }
            D_01E94C4C.field_0 = 0;
            func_00318340(&D_01E94C40);
        } else {
            UnkStruct_0030E930_15 * r4 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E2ECD875C80);
            if (D_01EA2974.field_0 == r4) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r4, 0);
            void * t1 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r4;
            UnkStruct_0030E930_13 * t2 = D_01EA2980.field_0;
            if (t2 != 0) {
                D_01EA2984.field_0 = t2->field_20;
                if (r4 != 0) {
                    r4->field_8 = t2->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t1, 0);
            return;
        }
        break;
    case 4:
        return;
    case 5:
        switch (p2) {
        case 0:
            func_0030E340(self, p3);
            break;
        case 3:
            return;
        }
        break;
    }
}
