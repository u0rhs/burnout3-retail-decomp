// func_004376F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (state handler: swap block as static inline (store before D_01EA2980 read), per-player input pointer locals, hash test as if (t0 != A && t0 != B) {...} else, case 5 as one-case switch(p2)).

// lifter variant 0
// func_004376F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3InputManager;
struct UnkStruct_004376F0;
struct UnkStruct_004376F0_10;
struct UnkStruct_004376F0_11;
struct UnkStruct_004376F0_12;
struct UnkStruct_004376F0_13;
struct UnkStruct_004376F0_14;
struct UnkStruct_004376F0_17;
struct UnkStruct_004376F0_18;
struct UnkStruct_004376F0_8;
struct UnkStruct_004376F0_a3;
struct UnkStruct_004376F0_e0;
struct UnkStruct_D_004F50A0;
struct UnkStruct_D_004F6061;
struct UnkStruct_D_004F6062;
struct UnkStruct_D_01E90230;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90430;
struct UnkStruct_D_01E98468;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_004376F0_e0 {
    unsigned char pad_0[0x12C];
};

class CB3InputManager {
public:
    float GetDeadInputTime(signed char);

    UnkStruct_004376F0_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_D_004F50A0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004376F0_a3 {
    unsigned long field_0;
};

struct UnkStruct_D_004F6061 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F6062 {
    signed char field_0;
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
    UnkStruct_004376F0_8 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004376F0_8 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004376F0_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_004376F0_11 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_004376F0_12 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_004376F0_13 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_004376F0_14 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E90430 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90230 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004376F0_17 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_004376F0_18 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E98468 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004376F0 {
    unsigned char pad_0[0x10];
    float field_10;
};

extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_004F6062 D_004F6062;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_01E90230 D_01E90230;
extern UnkStruct_D_01E98468 D_01E98468;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);  // CB3MenuPageManager::ReleaseCurrentMenu()
extern "C" int func_00436F70(void *);
extern "C" float func_0012FC30(void *, int, int);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// [G] inlined helper (name unknown): switches the current state object, carrying the time over
static inline void func_004376F0_swap(unsigned long id)
{
    UnkStruct_004376F0_10 * r = (UnkStruct_004376F0_10 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, id);
    if (D_01EA2974.field_0 == r) return;
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * t3 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_004376F0_8 * t4 = D_01EA2980.field_0;
    if (t4 != 0) {
        D_01EA2984.field_0 = t4->field_20;
        if (r != 0) {
            r->field_8 = t4->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t3, 0);
}

// 0x004376F0
extern "C" void func_004376F0(UnkStruct_004376F0 * self, int p0, int p1, UnkStruct_004376F0_a3 * p2)
{
    switch (p0) {
    case 3: {
        self->field_10 = D_004F50A0.field_0;
        unsigned long t0 = p2->field_0;
        if (t0 != 0x60D6B07214065F27 && t0 != 0x944140D320FEDE85) {
            void * a = (char *)&D_004F50C0.field_0[D_004F6061.field_0] + 0xD48;
            float r2 = func_0012FC30(a, 2, 0);
            float r3 = func_0012FC30(a, 0, 0);
            void * b = (char *)&D_004F50C0.field_0[D_004F6062.field_0] + 0xD48;
            float r4 = func_0012FC30(b, 2, 0);
            float r5 = func_0012FC30(b, 0, 0);
            if ((r2 <= 0.0f || r3 <= 0.0f) && (r4 <= 0.0f || r5 <= 0.0f)) {
                func_004376F0_swap(0x94413E2ECD875AF7);
            } else {
                func_00436F70(&D_01E98468);
            }
        } else {
            func_00436F70(&D_01E98468);
        }
        break;
    }
    case 4:
        if (D_004F50C0.GetDeadInputTime(-1) <= 30.0f) return;
        if (D_01E90430.field_0 != 0) {
            ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
        }
        D_01E90230.field_0 = 0x94413E2EEC056247;
        func_004376F0_swap(0x944140D320FEDE85);
        break;
    case 5:
        switch ((int)p2) {
        case 1:
            if (D_01E90430.field_0 != 0) {
                ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
            }
            func_004376F0_swap(0x94413E2ECD875AF7);
            break;
        }
        break;
    }
}
