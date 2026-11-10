// func_00396A90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool out-params as locals; 8-byte entry array with a static inline setter [G] (args evaluated right to left); disable flags written !a || !(b != 0)).

// lifter variant 0
// func_00396A90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3MenuComponentSelectionData;
class CB3VSelectComponentEntryData;

class CGtBuddiesPS2DirtySock;
struct UnkStruct_00396A90;
struct UnkStruct_00396A90_0;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E3D4B0;
struct UnkStruct_D_01E89544;
struct UnkStruct_D_01E8954E;
struct UnkStruct_D_01E89800;

class CGtBuddiesPS2DirtySock {
public:
    void IsPermanentBuddy(char*, bool*);
    void IsBuddyIgnored(char*, bool*);
    void IsWannaBeMyBuddy(char*, bool*);
    void IsWannaBeHisBuddy(char*, bool*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00396A90_0 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
};

struct UnkStruct_D_01E3D4B0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8954E {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89544 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

// [G] one 8-byte entry of the list at +0x30 (passed as CB3VSelectComponentEntryData*)
struct UnkStruct_00396A90_e {
    int field_0;
    bool field_4;
    bool field_5;
    unsigned char pad_6[0x2];
};

struct UnkStruct_00396A90 {
    unsigned char pad_0[0x4];
    char field_4[0x24];
    unsigned short field_28;
    unsigned char pad_2A[0x2];
    short field_2C;
    short field_2E;
    UnkStruct_00396A90_e field_30[5];
    unsigned char pad_58[0x405];
    unsigned char field_45D;
    unsigned char pad_45E[0x6];
    int field_464;
};

// [G] inlined entry setter (name unknown)
static inline void func_00396A90_set(UnkStruct_00396A90_e * e, int text, bool a, bool b)
{
    e->field_0 = text;
    e->field_4 = a;
    e->field_5 = b;
}

extern UnkStruct_D_01E3D4B0 D_01E3D4B0;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89800 D_01E89800;
extern CGtBuddiesPS2DirtySock D_01E3D390;
extern UnkStruct_D_0051BA44 D_0051BA44;

extern "C" void Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, bool, float, float, float, float, const void *, void *, int, float);  // CB3VSelectComponent::Prepare(bool,float,float,float,float,const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 2 more argument(s) [G]
extern "C" int func_00271A00(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x00396A90
extern "C" void func_00396A90(UnkStruct_00396A90 * self)
{
    bool perm = false;
    bool ignored = false;
    bool wannaMy = false;
    bool wannaHis = false;
    D_01E3D390.IsPermanentBuddy(self->field_4, &perm);
    D_01E3D390.IsBuddyIgnored(self->field_4, &ignored);
    D_01E3D390.IsWannaBeMyBuddy(self->field_4, &wannaMy);
    D_01E3D390.IsWannaBeHisBuddy(self->field_4, &wannaHis);
    bool v = !(perm || wannaMy || wannaHis);
    if (self->field_464 == self->field_28) {
        func_00396A90_set(&self->field_30[0], func_00271A00(&D_0051BA44, 62), false, false);
        self->field_2C = 0;
        self->field_2E = 1;
    } else {
        func_00396A90_set(&self->field_30[0], func_00271A00(&D_0051BA44, 61), !v || !(D_01E3D4B0.field_0 != 0), false);
        func_00396A90_set(&self->field_30[1], func_00271A00(&D_0051BA44, 11), !perm || !(D_01E3D4B0.field_0 != 0), false);
        func_00396A90_set(&self->field_30[2], func_00271A00(&D_0051BA44, 62), false, false);
        func_00396A90_set(&self->field_30[3], func_00271A00(&D_0051BA44, 14), ignored || !(D_01E3D4B0.field_0 != 0), false);
        func_00396A90_set(&self->field_30[4], func_00271A00(&D_0051BA44, 1088), false, false);
        self->field_2C = 0;
        self->field_2E = 5;
    }
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    }
    Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, 0, 84.0f, 240.0f, 30.0f, 40.0f, (const CB3MenuComponentSelectionData*)&self->field_2C, (CB3VSelectComponentEntryData*)self->field_30, 0, 192.0f);
    self->field_45D = 3;
    ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    func_0031ECD0(&D_01E89800, 325, 3);
}
