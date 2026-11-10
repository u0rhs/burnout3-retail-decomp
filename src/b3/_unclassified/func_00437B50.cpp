// func_00437B50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (case 5's p2 test is a one-case switch (beq body; b exit); swap block in sibling form; float guard GetDeadInputTime() > 30.0f).

// func_00437B50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3InputManager;
struct UnkStruct_00437B50;
struct UnkStruct_00437B50_10;
struct UnkStruct_00437B50_11;
struct UnkStruct_00437B50_7;
struct UnkStruct_00437B50_9;
struct UnkStruct_D_004F50A0;
struct UnkStruct_D_01E7A888;
struct UnkStruct_D_01E90230;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90430;
struct UnkStruct_D_01E97E34;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

class CB3InputManager {
public:
    void ResetDeadInputTime(signed char);
    float GetDeadInputTime(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F50A0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90430 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    UnkStruct_00437B50_7 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00437B50_7 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00437B50_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00437B50_10 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_00437B50_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E7A888 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E97E34 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00437B50 {
    unsigned char pad_0[0x10];
    float field_10;
};

extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_01E90230 D_01E90230;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E7A888 D_01E7A888;
extern UnkStruct_D_01E97E34 D_01E97E34;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);  // CB3MenuPageManager::ReleaseCurrentMenu()
extern "C" void func_003FA600(void *, int);
extern "C" int func_004372B0(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x00437B50
extern "C" void func_00437B50(UnkStruct_00437B50 * self, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        self->field_10 = D_004F50A0.field_0;
        func_003FA600(&D_01E7A888, 0);
        func_004372B0(&D_01E97E34);
        D_004F50C0.ResetDeadInputTime(-1);
        break;
    case 4:
        if (D_004F50C0.GetDeadInputTime(-1) > 30.0f) {
            if (D_01E90430.field_0 != 0) {
                ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
            }
            D_01E90230.field_0 = 0x94413E2EC6D1AFF5;
            UnkStruct_00437B50_9 * r5 = (UnkStruct_00437B50_9 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x944140D320FEDE85);
            if (D_01EA2974.field_0 != r5) {
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r5, 0);
                void * t0 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r5;
                UnkStruct_00437B50_7 * t1 = D_01EA2980.field_0;
                if (t1 != 0) {
                    D_01EA2984.field_0 = t1->field_20;
                    if (r5 != 0) {
                        r5->field_8 = t1->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            }
        }
        break;
    case 5:
        switch (p2) {
        case 1:
            if (D_01E90430.field_0 != 0) {
                ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
            }
            UnkStruct_00437B50_9 * r5 = (UnkStruct_00437B50_9 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E2ECD875AF7);
            if (D_01EA2974.field_0 != r5) {
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r5, 0);
                void * t0 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r5;
                UnkStruct_00437B50_7 * t1 = D_01EA2980.field_0;
                if (t1 != 0) {
                    D_01EA2984.field_0 = t1->field_20;
                    if (r5 != 0) {
                        r5->field_8 = t1->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            }
            break;
        }
        break;
    default:
        break;
    }
}
