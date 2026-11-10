// func_00438DD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (default: return; first in the switch (fills the default jump's delay slot); case 5 as a nested one-case switch on p2; D_01EA2980 read after the D_01EA2974 store).

// lifter variant 0
// func_00438DD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00438DD0_3;
struct UnkStruct_00438DD0_5;
struct UnkStruct_00438DD0_6;
struct UnkStruct_D_01E96F58;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECD520;

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
    virtual void vfunc_18(UnkStruct_00438DD0_5 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_00438DD0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00438DD0_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00438DD0_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00438DD0_6 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01E96F58 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD520 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E96F58 D_01E96F58;
extern UnkStruct_D_01ECD520 D_01ECD520;

extern "C" int func_00438CF0(void *);
extern "C" void Update__24CB3MemCardControllerBaseFv(void *);
extern "C" UnkStruct_00438DD0_5 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x00438DD0
extern "C" void func_00438DD0(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    default:
        return;
    case 0:
        break;
    case 3:
        func_00438CF0(&D_01E96F58);
        break;
    case 4:
        Update__24CB3MemCardControllerBaseFv(&D_01ECD520);
        break;
    case 5:
        switch (p2) {
        case 1:
            UnkStruct_00438DD0_5 * r2 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC1552CB1E0);
            if (D_01EA2974.field_0 == r2) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r2, 0);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r2;
            UnkStruct_00438DD0_3 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r2 != 0) {
                    r2->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            break;
        }
        break;
    }
}
