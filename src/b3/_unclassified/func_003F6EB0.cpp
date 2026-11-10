// func_003F6EB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (D_01EA2974 store before D_01EA2980 load; case 3 as if/else; no default label, swap-guard exits as break).

// lifter variant 0
// func_003F6EB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3ReplayPage;
struct UnkStruct_003F6EB0;
struct UnkStruct_003F6EB0_11;
struct UnkStruct_003F6EB0_12;
struct UnkStruct_003F6EB0_13;
struct UnkStruct_003F6EB0_1;
struct UnkStruct_003F6EB0_4;
struct UnkStruct_003F6EB0_9;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01EA2F0E;

class CB3ReplayPage {
public:
    void Prepare(bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003F6EB0_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003F6EB0_1 {
    unsigned char pad_0[0x1B4];
    UnkStruct_003F6EB0_4 * field_1B4;
};

struct UnkStruct_003F6EB0_4 {
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
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
};

struct UnkStruct_D_01EA2F0E {
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
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003F6EB0_9 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003F6EB0_9 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003F6EB0_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003F6EB0_12 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_003F6EB0_13 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003F6EB0 {
    unsigned char pad_0[0x10];
    int field_10;
    unsigned char pad_14[0x4];
    unsigned char field_18[1];  // [G] element count unknown
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01EA2F0E D_01EA2F0E;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern CB3ReplayPage D_01E9595C;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_0051A6A8 D_0051A6A8;

extern "C" void SetPlayerRecordsNotAdded__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::SetPlayerRecordsNotAdded()
extern "C" void func_003F7150(UnkStruct_003F6EB0 *);
extern "C" void func_00131F10(void *, void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003F6EB0
extern "C" void func_003F6EB0(UnkStruct_003F6EB0 * self, int p0, void *p1_, int p2)
{
    int p1 = (int)p1_;
    UnkStruct_003F6EB0_1 * t0 = D_0051BA88.field_0;
    UnkStruct_003F6EB0_4 * t1 = t0->field_1B4;
    switch (p2) {
    case 1:
    case 2:
    case 0:
        for (int i = 0; (i < 8); i++) {
            self->field_18[i] = 0;
        }
        SetPlayerRecordsNotAdded__17CB3NetworkManagerFv(&D_01E32AE0);
        t1->vfunc_E0();
        func_003F7150(self);
        break;
    case 3:
        if (self->field_10 == 0) {
            D_01E9595C.Prepare(1);
            self->field_10 = 2;
        } else {
            D_01E9595C.Prepare(1);
            self->field_10 = 3;
        }
        break;
    case 65:
        D_01EA2F0E.field_0 = 1;
        func_00131F10(&D_004EE040, &D_0051A6A8);
        UnkStruct_003F6EB0_11 * r6 = (UnkStruct_003F6EB0_11 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FA737AAA797);
        if (D_01EA2974.field_0 == r6) {
            break;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r6, 0);
        void * t2 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r6;
        UnkStruct_003F6EB0_9 * t3 = D_01EA2980.field_0;
        if (t3 != 0) {
            D_01EA2984.field_0 = t3->field_20;
            if (r6 != 0) {
                r6->field_8 = t3->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
        break;
    case 66:
        D_01EA2F0E.field_0 = 0;
        func_00131F10(&D_004EE040, &D_0051A6A8);
        UnkStruct_003F6EB0_13 * r10 = (UnkStruct_003F6EB0_13 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FA737AAA797);
        if (D_01EA2974.field_0 == r10) {
            break;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r10, 0);
        void * t4 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r10;
        UnkStruct_003F6EB0_9 * t5 = D_01EA2980.field_0;
        if (t5 != 0) {
            D_01EA2984.field_0 = t5->field_20;
            if (r10 != 0) {
                r10->field_8 = t5->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t4, 0);
        break;
    }
}
