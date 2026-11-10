// func_003C70B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (single-case switch (p0) case 4; D_01EA2970..84 one object with virtual calls through a cast pointer; && guard).

// lifter variant 0
// func_003C70B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C70B0_5;
struct UnkStruct_003C70B0_7;
struct UnkStruct_003C70B0_8;
struct UnkStruct_D_0051BA94;
struct UnkStruct_D_0051BA9C;
struct UnkStruct_D_01EA2970;

struct UnkStruct_D_0051BA94 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C70B0_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003C70B0_5 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2970 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_003C70B0_7 *, int);
    virtual void vfunc_1C(UnkStruct_003C70B0_7 *, int);
    UnkStruct_003C70B0_7 * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_003C70B0_5 * field_10;
    float field_14;
};

struct UnkStruct_003C70B0_8 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

extern UnkStruct_D_0051BA94 D_0051BA94;
extern UnkStruct_D_0051BA9C D_0051BA9C;
extern UnkStruct_D_01EA2970 D_01EA2970;

extern "C" UnkStruct_003C70B0_7 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003C70B0
extern "C" void func_003C70B0(int n0, int p0)
{
    switch (p0) {
    case 4:
        if (D_0051BA94.field_0 != -1 && D_0051BA9C.field_0 == -1) {
            UnkStruct_003C70B0_7 * r0 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413EE6EE66CE78);
            if (D_01EA2970.field_4 != r0) {
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r0, 0);
                UnkStruct_003C70B0_7 * old = D_01EA2970.field_4;
                D_01EA2970.field_4 = r0;
                if (D_01EA2970.field_10 != 0) {
                    D_01EA2970.field_14 = D_01EA2970.field_10->field_20;
                    if (r0 != 0) {
                        r0->field_8 = D_01EA2970.field_10->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(old, 0);
            }
        }
        break;
    }
}
