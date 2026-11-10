// func_003EC540 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (swap block reads D_01EA2980 after the D_01EA2974 store; int index local; case tails break (not return), inner default: break).

// lifter variant 0
// func_003EC540 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003EC540_10;
struct UnkStruct_003EC540_11;
struct UnkStruct_003EC540_4;
struct UnkStruct_003EC540_6;
struct UnkStruct_003EC540_7;
struct UnkStruct_D_01E96474;
struct UnkStruct_D_01E96478;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_01E96478 {
    unsigned short field_0;
    unsigned char pad_2[0xE];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    UnkStruct_003EC540_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EC540_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EC540_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003EC540_7 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_003EC540_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003EC540_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E96474 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E96478 D_01E96478;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern int D_004A5500[];  // [G] element count unknown
extern UnkStruct_D_01E96474 D_01E96474;

extern "C" int func_003F39C0(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003EC540
extern "C" void func_003EC540(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        func_003F39C0(&D_01E96474);
        break;
    case 5:
        int t0 = D_01E96478.field_0;
        switch (p2) {
        case 0:
            if (t0 == 4) {
                UnkStruct_003EC540_6 * r1 = (UnkStruct_003EC540_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC165853C68);
                if (D_01EA2974.field_0 == r1) {
                    return;
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r1, 0);
                void * t1 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r1;
                UnkStruct_003EC540_4 * t2 = D_01EA2980.field_0;
                if (t2 != 0) {
                    D_01EA2984.field_0 = t2->field_20;
                    if (r1 != 0) {
                        r1->field_8 = t2->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t1, 0);
                break;
            }
            int t3 = D_004A5500[t0];
            UnkStruct_003EC540_10 * r4 = (UnkStruct_003EC540_10 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC165857D40);
            if (D_01EA2974.field_0 == r4) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r4, t3);
            void * t4 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r4;
            UnkStruct_003EC540_4 * t5 = D_01EA2980.field_0;
            if (t5 != 0) {
                D_01EA2984.field_0 = t5->field_20;
                if (r4 != 0) {
                    r4->field_8 = t5->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t4, t3);
            break;
        case 3:
            UnkStruct_003EC540_11 * r7 = (UnkStruct_003EC540_11 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FD6EF6E02D9);
            if (D_01EA2974.field_0 == r7) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r7, 0);
            void * t6 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r7;
            UnkStruct_003EC540_4 * t7 = D_01EA2980.field_0;
            if (t7 != 0) {
                D_01EA2984.field_0 = t7->field_20;
                if (r7 != 0) {
                    r7->field_8 = t7->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t6, 0);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
