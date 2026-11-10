// func_003C8A30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (near8: plain case-3 stores + 'case 0: default:' first in the field_10 switch).

// near8: case 3 stores in plain order, then switch (field_10) with "case 0: default:" first (fills the default jal delay slot).

// lifter variant 0
// func_003C8A30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3MenuChoices;
class CB3Profile;
struct UnkStruct_003C8A30;
struct UnkStruct_003C8A30_17;
struct UnkStruct_003C8A30_4;
struct UnkStruct_003C8A30_6;
struct UnkStruct_003C8A30_7;
struct UnkStruct_D_004E2EDC;
struct UnkStruct_D_0051A9BF;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01EA3170;
struct UnkStruct_D_01ECDA10;
struct UnkStruct_D_01ECDA5D;
struct UnkStruct_D_01ECDA60;
struct UnkStruct_D_01ECDA61;
struct UnkStruct_D_01ECDAC3;
struct UnkStruct_D_01ECDAC8;
struct UnkStruct_D_01ECDD8D;

class CB3Profile {
public:
    void Evaluate();
};

class CB3MenuChoices {
public:
    void RequestNewGameMode();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDD8D {
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
    UnkStruct_003C8A30_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C8A30_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C8A30_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003C8A30_7 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_D_01ECDA5D {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDAC8 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDA61 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDA10 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDA60 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BF9C {
    CB3Profile * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E2EDC {
    unsigned char field_0;
};

struct UnkStruct_D_01ECDAC3 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C8A30_17 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_0051A9BF {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA3170 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C8A30 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    unsigned char field_24;
    unsigned char field_25;
    unsigned char field_26;
};

extern UnkStruct_D_01ECDD8D D_01ECDD8D;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01ECDA5D D_01ECDA5D;
extern UnkStruct_D_01ECDAC8 D_01ECDAC8;
extern UnkStruct_D_01ECDA61 D_01ECDA61;
extern UnkStruct_D_01ECDA10 D_01ECDA10;
extern UnkStruct_D_01ECDA60 D_01ECDA60;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_004E2EDC D_004E2EDC;
extern UnkStruct_D_01ECDAC3 D_01ECDAC3;
extern UnkStruct_D_0051A9BF D_0051A9BF;
extern UnkStruct_D_01EA3170 D_01EA3170;
extern CB3MenuChoices D_01E900B0;

extern "C" UnkStruct_003C8A30_6 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_003C8E20(UnkStruct_003C8A30 *);
extern "C" void func_003C7E80(UnkStruct_003C8A30 *);
extern "C" void func_003C7B60(UnkStruct_003C8A30 *);
extern "C" void func_003C82E0(UnkStruct_003C8A30 *);
extern "C" void func_00139F20(CB3Profile *);

// [G] placeholder for an unnamed inline: switch the active state to the one keyed by `key` (the D_01EA2970 swap
// block func_0030E930 has written out)
static inline void func_003C8A30_inl1(unsigned long key)
{
    UnkStruct_003C8A30_6 * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, key);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * old = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_003C8A30_4 * t = D_01EA2980.field_0;
    if (t != 0) {
        D_01EA2984.field_0 = t->field_20;
        if (r != 0) {
            r->field_8 = t->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(old, 0);
}

// 0x003C8A30
extern "C" void func_003C8A30(UnkStruct_003C8A30 * self, int p0, int p1, void * p2)
{
    switch (p0) {
    case 0:
        return;
    case 3:
        if (p2 == &D_01EA3170) {
            if (D_01ECDD8D.field_0 != 0) {
                func_003C8A30_inl1(0x94413FC035B0F871);
                return;
            }
            self->field_25 = 1;
        } else {
            self->field_25 = 0;
        }
        D_01ECDD8D.field_0 = 1;
        if (D_01ECDA5D.field_0 == 0) {
            func_003C8E20(self);
            break;
        }
        if (D_01ECDAC8.field_0 != 0 || D_01ECDA61.field_0 != 0) {
            self->field_10 = 2;
        } else if ((D_01ECDA10.field_0 & 8) != 0 || D_01ECDA60.field_0 != 0) {
            self->field_10 = 0;
        } else {
            self->field_10 = 1;
        }
        self->field_14 = 0;
        self->field_18 = 0;
        self->field_1C = 0;
        self->field_20 = -1;
        self->field_24 = 0;
        self->field_26 = 0;
        switch (self->field_10) {
        case 0:
        default:
            func_003C82E0(self);
            break;
        case 1:
            func_003C7E80(self);
            break;
        case 2:
            func_003C7B60(self);
            break;
        }
        break;
    case 5:
        switch ((int)p2) {
        case 2:
        case 0:
            switch (self->field_10) {
            case 1:
                func_003C7E80(self);
                break;
            case 2:
                func_003C7B60(self);
                if (self->field_26 != 0 && D_01ECDA60.field_0 != 0) {
                    self->field_20 = -1;
                    self->field_24 = 0;
                    self->field_26 = 0;
                    self->field_10 = 0;
                    func_003C82E0(self);
                }
                break;
            case 0:
            default:
                func_003C82E0(self);
                break;
            }
            if (self->field_26 != 0) {
                {
                    CB3Profile * prof = D_0051BF9C.field_0;
                    prof->Evaluate();
                    func_00139F20(prof);
                }
                D_01ECDAC3.field_0 = 0;
                if (D_004E2EDC.field_0 != 0) {
                    D_004E2EDC.field_0 = 0;
                    func_003C8A30_inl1(0x94413FC109F9B21B);
                    break;
                }
                D_0051BF9C.field_0->Evaluate();
                if (D_0051A9BF.field_0 <= 0) {
                    func_003C8E20(self);
                } else {
                    D_01E900B0.RequestNewGameMode();
                }
            }
            break;
        }
        break;
    }
}
