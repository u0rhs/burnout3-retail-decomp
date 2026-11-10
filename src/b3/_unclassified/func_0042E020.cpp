// func_0042E020 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (outer switch 'default: return;' first; phantom args dropped (func_0042E6B0/func_00421580 take only a0, func_0042E310 only a0/a1, GetStateFromID__6CGtFSMFUl third arg); swap block reads D_01EA2980 after the D_01EA2974 store; inner cases end in break).

struct UnkStruct_0042E020_4;
struct UnkStruct_0042E020_6;
struct UnkStruct_0042E020_7;
struct UnkStruct_0042E020_8;
struct UnkStruct_D_01E97DBC;
struct UnkStruct_D_01E97DC0;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECD520;

struct UnkStruct_D_01E97DC0 {
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
    UnkStruct_0042E020_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0042E020_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0042E020_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0042E020_7 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_0042E020_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E97DBC {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD520 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E97DC0 D_01E97DC0;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E97DBC D_01E97DBC;
extern UnkStruct_D_01ECD520 D_01ECD520;

extern "C" int func_0042E6B0(void *);
extern "C" void Update__24CB3MemCardControllerBaseFv(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_0042E310(void *, int);

// 0x0042E020
extern "C" void func_0042E020(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    default:
        return;
    case 3:
        func_0042E6B0(&D_01E97DBC);
        break;
    case 4:
        Update__24CB3MemCardControllerBaseFv(&D_01ECD520);
        break;
    case 5:
        switch (p2) {
        case 0:
            switch (D_01E97DC0.field_0) {
            case 4:
                UnkStruct_0042E020_6 * r2 = (UnkStruct_0042E020_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC155240E48);
                if (D_01EA2974.field_0 == r2) {
                    return;
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r2, 0);
                void * t0 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r2;
                UnkStruct_0042E020_4 * t1 = D_01EA2980.field_0;
                if (t1 != 0) {
                    D_01EA2984.field_0 = t1->field_20;
                    if (r2 != 0) {
                        r2->field_8 = t1->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
                return;
            case 5:
                UnkStruct_0042E020_8 * r5 = (UnkStruct_0042E020_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC15523D68A);
                if (D_01EA2974.field_0 == r5) {
                    return;
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r5, 0);
                void * t2 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r5;
                UnkStruct_0042E020_4 * t3 = D_01EA2980.field_0;
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
        case 49:
            func_0042E310(&D_01E97DBC, 49);
            break;
        case 48:
            func_0042E310(&D_01E97DBC, 48);
            break;
        case 50:
            func_0042E310(&D_01E97DBC, 50);
            break;
        case 46:
            func_0042E310(&D_01E97DBC, 46);
            break;
        case 47:
            func_0042E310(&D_01E97DBC, 47);
            break;
        case 54:
            func_0042E310(&D_01E97DBC, 54);
            break;
        case 55:
            func_0042E310(&D_01E97DBC, 55);
            break;
        case 58:
            func_0042E310(&D_01E97DBC, 58);
            break;
        }
        break;
    }
}
