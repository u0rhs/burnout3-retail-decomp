// func_0043FB60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch with 'default: return;' first; phantom args dropped (func_003FA600/func_00217690 third arg, vfunc_C args); swap block reads D_01EA2980 after the D_01EA2974 store).

struct UnkStruct_0043FB60;
struct UnkStruct_0043FB60_10;
struct UnkStruct_0043FB60_6;
struct UnkStruct_0043FB60_8;
struct UnkStruct_0043FB60_9;
struct UnkStruct_0043FB60_a3;
struct UnkStruct_D_01E7A888;
struct UnkStruct_D_01E90230;
struct UnkStruct_D_01E98478;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_0043FB60_a3 {
    unsigned long field_0;
};

struct UnkStruct_D_01E90230 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    UnkStruct_0043FB60_6 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0043FB60_6 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0043FB60_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0043FB60_9 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_0043FB60_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E98478 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E7A888 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0043FB60 {
    unsigned char pad_0[0x10];
    unsigned long field_10;
};

extern UnkStruct_D_01E90230 D_01E90230;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E98478 D_01E98478;
extern UnkStruct_D_01E7A888 D_01E7A888;

extern "C" void func_003FA600(void *, int);
extern "C" int func_00424750(void *, int, int, int, float);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x0043FB60
extern "C" void func_0043FB60(UnkStruct_0043FB60 * self, int p0, int p1, UnkStruct_0043FB60_a3 * p2)
{
    switch (p0) {
    default:
        return;
    case 3:
        self->field_10 = p2->field_0;
        func_003FA600(&D_01E7A888, 0);
        func_00424750(&D_01E98478, 0, 1, 4005, 1000.0f);
        break;
    case 5:
        switch ((int)p2) {
        case 0:
            UnkStruct_0043FB60_8 * r2 = (UnkStruct_0043FB60_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, D_01E90230.field_0);
            if (D_01EA2974.field_0 == r2) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r2, 0);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r2;
            UnkStruct_0043FB60_6 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r2 != 0) {
                    r2->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            return;
        case 2:
            UnkStruct_0043FB60_10 * r5 = (UnkStruct_0043FB60_10 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x60D6B07214065F27);
            if (D_01EA2974.field_0 == r5) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r5, 0);
            void * t2 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r5;
            UnkStruct_0043FB60_6 * t3 = D_01EA2980.field_0;
            if (t3 != 0) {
                D_01EA2984.field_0 = t3->field_20;
                if (r5 != 0) {
                    r5->field_8 = t3->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
            return;
        }
        break;
    case 2:
        ((UnkStruct_D_01E98478 *)&D_01E98478)->vfunc_C();
        break;
    }
}
