// func_003C6160 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (outer switch 'default: return;' first; case 5's if (p2 == 2) written as an inner switch whose case ends in break; swap block reads D_01EA2980 after the D_01EA2974 store).

class CB3ReplayPage;
struct UnkStruct_003C6160_10;
struct UnkStruct_003C6160_6;
struct UnkStruct_003C6160_8;
struct UnkStruct_003C6160_9;
struct UnkStruct_D_01E900B0;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90430;
struct UnkStruct_D_01E91C3D;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

class CB3ReplayPage {
public:
    void Prepare(bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E91C3D {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90430 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E900B0 {
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
    UnkStruct_003C6160_6 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C6160_6 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C6160_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003C6160_9 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_003C6160_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E91C3D D_01E91C3D;
extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_01E900B0 D_01E900B0;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern CB3ReplayPage D_01E9595C;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);  // CB3MenuPageManager::ReleaseCurrentMenu()
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003C6160
extern "C" void func_003C6160(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    default:
        return;
    case 0:
        break;
    case 3:
        D_01E9595C.Prepare(0);
        break;
    case 4:
        if (D_01E91C3D.field_0 == 0) {
            return;
        }
        if (D_01E90430.field_0 != 0) {
            ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
        }
        D_01E900B0.field_0 = 3;
        UnkStruct_003C6160_8 * r2 = (UnkStruct_003C6160_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FA737AAA797);
        if (D_01EA2974.field_0 == r2) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r2, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r2;
        UnkStruct_003C6160_6 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r2 != 0) {
                r2->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
        break;
    case 5:
        switch (p2) {
        case 2:
            UnkStruct_003C6160_10 * r5 = (UnkStruct_003C6160_10 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x944140403E74F2B0);
            if (D_01EA2974.field_0 == r5) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r5, 0);
            void * t2 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r5;
            UnkStruct_003C6160_6 * t3 = D_01EA2980.field_0;
            if (t3 != 0) {
                D_01EA2984.field_0 = t3->field_20;
                if (r5 != 0) {
                    r5->field_8 = t3->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
            break;
        }
        break;
    }
}
