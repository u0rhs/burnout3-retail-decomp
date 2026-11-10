// Save__24CB3MemCardControllerBaseFUiPUsi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (moved the D_01EB5D04 store above the D_01EB5D10 load).

// Save__24CB3MemCardControllerBaseFUiPUsi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00421060;
struct UnkStruct_00421060_5;
struct UnkStruct_00421060_7;
struct UnkStruct_00421060_8;
struct UnkStruct_D_01EB5D00;
struct UnkStruct_D_01EB5D04;
struct UnkStruct_D_01EB5D10;
struct UnkStruct_D_01EB5D14;
struct UnkStruct_D_01EB5D38;
struct UnkStruct_D_01EBE3B0;

struct UnkStruct_D_01EB5D38 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D04 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D00 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_00421060_7 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D10 {
    UnkStruct_00421060_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00421060_5 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EB5D14 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00421060_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00421060_8 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01EBE3B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00421060 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x54];
    void * field_5C;
    void * field_60;
};

extern UnkStruct_D_01EB5D38 D_01EB5D38;
extern UnkStruct_D_01EB5D04 D_01EB5D04;
extern UnkStruct_D_01EB5D00 D_01EB5D00;
extern UnkStruct_D_01EB5D10 D_01EB5D10;
extern UnkStruct_D_01EB5D14 D_01EB5D14;
extern UnkStruct_D_01EBE3B0 D_01EBE3B0;

extern "C" void func_00421AF0(void *, int, void *, int, int);
extern "C" UnkStruct_00421060_7 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x00421060
// [L] the D_01EB5D04 store precedes the D_01EB5D10 load in source (retail issues its lui first).
extern "C" void Save__24CB3MemCardControllerBaseFUiPUsi(UnkStruct_00421060 * self, int p0, void *p1_, int p2)
{
    int p1 = (int)p1_;
    int t0 = D_01EB5D38.field_0;
    func_00421AF0(&D_01EBE3B0, p0, (void *)(p1), t0, p2);
    if (t0 != 0) {
        self->field_60 = ((char *)self + 0xC);
        self->field_5C = ((char *)self + 0x4C);
    } else {
        self->field_5C = ((char *)self + 0x5C);
        self->field_60 = ((char *)self + 0x4C);
    }
    self->field_4 = p0;
    UnkStruct_00421060_7 * r1 = GetStateFromID__6CGtFSMFUl(&D_01EB5D00, 0x93CB4D00E7330B63);
    if (D_01EB5D04.field_0 == r1) return;
    ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_18(r1, t0);
    void * t1 = D_01EB5D04.field_0;
    D_01EB5D04.field_0 = (void *)r1;
    UnkStruct_00421060_5 * t2 = D_01EB5D10.field_0;
    if (t2 != 0) {
        D_01EB5D14.field_0 = t2->field_20;
        if (r1 != 0) {
            r1->field_8 = t2->field_20;
        }
    }
    ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_1C(t1, t0);
}
