// func_00469AB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (default: return; first in the outer switch; D_01EA2974 store moved above the D_01EA2980 load).

// func_00469AB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00469AB0_5;
struct UnkStruct_00469AB0_7;
struct UnkStruct_00469AB0_8;
struct UnkStruct_D_0051BA90;
struct UnkStruct_D_0051BAD7;
struct UnkStruct_D_01E95C30;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_0051BAD7 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA90 {
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
    virtual void vfunc_18(UnkStruct_00469AB0_7 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_00469AB0_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00469AB0_5 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00469AB0_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00469AB0_8 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01E95C30 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051BAD7 D_0051BAD7;
extern UnkStruct_D_0051BA90 D_0051BA90;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E95C30 D_01E95C30;

extern "C" int func_00469CC0(void *);
extern "C" UnkStruct_00469AB0_7 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x00469AB0
// [L] `default: return;` first in the outer switch; the D_01EA2974 store precedes the D_01EA2980 load (as in
// Save__24CB3MemCardControllerBaseFUiPUsi, the same inlined sequence).
extern "C" void func_00469AB0(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    default:
        return;
    case 3:
        func_00469CC0(&D_01E95C30);
        break;
    case 5:
        switch (p2) {
        case 2:
        case 0:
            D_0051BAD7.field_0 = 1;
            D_0051BA90.field_0 = 1;
            return;
        case 3:
            UnkStruct_00469AB0_7 * r1 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC112F8BDA7);
            if (D_01EA2974.field_0 == r1) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r1, 0);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r1;
            UnkStruct_00469AB0_5 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r1 != 0) {
                    r1->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            return;
        }
        break;
    }
}
