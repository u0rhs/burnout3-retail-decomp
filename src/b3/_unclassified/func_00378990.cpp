// func_00378990 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (inner store under one 'i != 0 || i1 != 2' test; buddies branch as '&& GetNumBuddies() > 0' with one shared else).

// lifter variant 0
// func_00378990 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3MenuComponentSelectionData;
class CB3VSelectComponentEntryData;

class CGtBuddiesPS2DirtySock;
struct UnkStruct_00378990;
struct UnkStruct_00378990_13;
struct UnkStruct_00378990_e0;
struct UnkStruct_00378990_e2;
struct UnkStruct_00378990_e3;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E3D4B0;
struct UnkStruct_D_01E89544;
struct UnkStruct_D_01E8954E;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E8D450;
struct UnkStruct_D_01E8D45A;
struct UnkStruct_D_01E8D490;
struct UnkStruct_D_01E8D49A;
struct UnkStruct_D_01E8EAF8;
struct UnkStruct_D_01E8EB02;

class CGtBuddiesPS2DirtySock {
public:
    int GetNumBuddies();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D45A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D450 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8EB02 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8EAF8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898F2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D49A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D490 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
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

struct UnkStruct_00378990_e0 {
    unsigned char pad_0[0xC];
    UnkStruct_00378990_13 * field_C[1];  // [G] element count unknown
    unsigned char pad_10[0x4];
};

struct UnkStruct_00378990_13 {
    short field_0;
};

struct UnkStruct_00378990_e3 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x4];
};

struct UnkStruct_00378990_e2 {
    unsigned char pad_0[0x18];
    UnkStruct_00378990_e3 field_18[1];  // [G] element count unknown
    unsigned char pad_24[0x18];
};

struct UnkStruct_D_01E3D4B0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00378990 {
    unsigned char pad_0[0xB04];
    UnkStruct_00378990_e0 field_B04[1];  // [G] element count unknown
    unsigned char pad_B18[0x208];
    UnkStruct_00378990_e2 field_D20[1];  // [G] element count unknown
    unsigned char pad_D5C[0x1A4];
    int field_F00;
    unsigned char pad_F04[0x1];
    unsigned char field_F05;
    short field_F06;
    short field_F08;
    unsigned char pad_F0A[0x2];
    int field_F0C;
    unsigned char field_F10;
    unsigned char field_F11;
    unsigned char pad_F12[0x2];
    int field_F14;
    unsigned char field_F18;
    unsigned char field_F19;
    unsigned char pad_F1A[0x2];
    int field_F1C;
    unsigned char field_F20;
    unsigned char field_F21;
};

extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E3D4B0 D_01E3D4B0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern CGtBuddiesPS2DirtySock D_01E3D390;

extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);  // CB3VSelectComponent::Prepare(const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" int func_00271A00(void *, int);

// 0x00378990
extern "C" void func_00378990(UnkStruct_00378990 * self)
{
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
    }
    if (D_01E8EB02.field_0 != 0) {
        ((UnkStruct_D_01E8EAF8 *)&D_01E8EAF8)->vfunc_C();
    }
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    if (D_01E8D49A.field_0 != 0) {
        ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
    }
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    } else {
    }
    self->field_F00 = 1;
    for (int i = 0; (i < 7); i++) {
        for (int i1 = 0; (i1 < 5); i1++) {
            if (i != 0 || i1 != 2) {
                self->field_B04[i].field_C[i1]->field_0 = 0;
            }
            if (i1 == 4) {
                self->field_D20[i].field_18[i1].field_0 = 0;
                self->field_D20[i].field_18[i1].field_4 = 0;
            }
        }
    }
    int r5 = func_00271A00(&D_0051BA44, 2533);
    self->field_F0C = r5;
    self->field_F10 = 0;
    self->field_F11 = 0;
    int r6 = func_00271A00(&D_0051BA44, 2534);
    self->field_F14 = r6;
    self->field_F18 = 0;
    self->field_F19 = 0;
    if (D_01E3D4B0.field_0 != 0 && D_01E3D390.GetNumBuddies() > 0) {
        self->field_F1C = func_00271A00(&D_0051BA44, 185);
        self->field_F20 = 0;
        self->field_F21 = 0;
        self->field_F06 = 0;
        self->field_F08 = 3;
    } else {
        self->field_F06 = 0;
        self->field_F08 = 2;
    }
    self->field_F05 = 0;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)((char *)self + 0xF06), (CB3VSelectComponentEntryData*)((char *)self + 0xF0C), 640.0f);
}
