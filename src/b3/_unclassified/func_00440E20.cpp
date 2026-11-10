// func_00440E20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (sibling of func_00440A20: per-pad input block pointer local (D_004F50C0+0xD48), (Up&&f360)||(Down&&f330) return, else-if chain over three vfuncs each followed by an inlined reset loop helper).

// lifter variant 0
// func_00440E20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

class CB3InputManager;
struct UnkStruct_00440E20;
struct UnkStruct_00440E20_10;
struct UnkStruct_00440E20_14;
struct UnkStruct_00440E20_18;
struct UnkStruct_00440E20_20;
struct UnkStruct_00440E20_23;
struct UnkStruct_00440E20_27;
struct UnkStruct_00440E20_31;
struct UnkStruct_00440E20_33;
struct UnkStruct_00440E20_36;
struct UnkStruct_00440E20_40;
struct UnkStruct_00440E20_44;
struct UnkStruct_00440E20_46;
struct UnkStruct_00440E20_49;
struct UnkStruct_00440E20_53;
struct UnkStruct_00440E20_57;
struct UnkStruct_00440E20_60;
struct UnkStruct_00440E20_7;
struct UnkStruct_00440E20_e0;
struct UnkStruct_00440E20_e1;
struct UnkStruct_D_004E2F88;
struct UnkStruct_D_004E2F8C;
struct UnkStruct_D_004E2F90;
struct UnkStruct_D_004F6061;
struct UnkStruct_D_0051B340;
struct UnkStruct_D_0051B38C;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90424;

struct UnkStruct_00440E20_e0 {
    unsigned char pad_0[0x78];
    short field_78;
    unsigned char pad_7A[0xA];
    short field_84;
    unsigned char pad_86[0xA];
    short field_90;
    unsigned char pad_92[0xA];
    short field_9C;
    unsigned char pad_9E[0xA];
    short field_A8;
    unsigned char pad_AA[0x82];
};

class CB3InputManager {
public:
    int GetMenuBack(signed char);

    unsigned char pad_0[0xCE4];
    UnkStruct_00440E20_e0 field_CE4[1];  // [G] element count unknown
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F6061 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00440E20_e1 {
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[0x2];
};

struct UnkStruct_00440E20_7 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

// [G] per-pad input block at D_004F50C0 + 0xD48 + pad * 0x12C (cf. func_004376F0)
struct UnkStruct_00440E20_in {
    unsigned char pad_0[0x14];
    short field_14;
    unsigned char pad_16[0xA];
    short field_20;
    unsigned char pad_22[0xA];
    short field_2C;
    unsigned char pad_2E[0xA];
    short field_38;
    unsigned char pad_3A[0xA];
    short field_44;
};

struct UnkStruct_00440E20_10 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_00440E20_14 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_00440E20_18 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_00440E20_20 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
};

struct UnkStruct_00440E20_23 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_00440E20_27 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_00440E20_31 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_00440E20_33 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
};

struct UnkStruct_00440E20_36 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_00440E20_40 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_00440E20_44 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_00440E20_46 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
};

struct UnkStruct_00440E20_49 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_00440E20_53 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_00440E20_57 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_00440E20_60 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00440E20_60 {
    unsigned char pad_0[0x1B4];
    int field_1B4;
};

struct UnkStruct_D_0051B38C {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E2F88 {
    unsigned char field_0;
};

struct UnkStruct_D_004E2F8C {
    unsigned char field_0;
};

struct UnkStruct_D_004E2F90 {
    unsigned char field_0;
};

struct UnkStruct_D_0051B340 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00440E20 {
    unsigned char pad_0[0x94];
    unsigned char field_94;
    unsigned char pad_95[0xB];
    unsigned char field_A0;
    unsigned char pad_A1[0xB];
    unsigned char field_AC;
    unsigned char pad_AD[0xB];
    unsigned char field_B8;
    unsigned char pad_B9[0x3];
    unsigned short field_BC;
    unsigned char pad_BE[0x2];
    UnkStruct_00440E20_e1 field_C0[1];  // [G] element count unknown
    unsigned char pad_C8[0x40];
    UnkStruct_00440E20_7 * field_108[1];  // [G] element count unknown
    unsigned char pad_10C[0x20];
    int field_12C;
    int field_130[1];  // [G] element count unknown
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004F6061 D_004F6061;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051B38C D_0051B38C;
extern UnkStruct_D_004E2F88 D_004E2F88;
extern UnkStruct_D_004E2F8C D_004E2F8C;
extern UnkStruct_D_004E2F90 D_004E2F90;
extern UnkStruct_D_0051B340 D_0051B340;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);

// [G] inlined helper (name unknown): re-applies every entry's stored value and clears its flags
static inline void func_00440E20_reset(UnkStruct_00440E20 * self)
{
    for (int i = 0; i < self->field_12C; i++) {
        self->field_108[i]->vfunc_14(self->field_130[i]);
        self->field_C0[i].field_0 = self->field_130[i];
        self->field_C0[i].field_4 = 0;
        self->field_C0[i].field_5 = 0;
    }
}

// 0x00440E20
extern "C" void func_00440E20(UnkStruct_00440E20 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    UnkStruct_00440E20_in * p = (UnkStruct_00440E20_in *)((char *)&D_004F50C0.field_CE4[D_004F6061.field_0] + 0x64);
    if (D_004F50C0.GetMenuBack(0) != 0) {
        if (D_0051BA88.field_0 != 0 && D_0051BA88.field_0->field_1B4 == (int)&D_0051B340) {
            D_0051B38C.field_0 = ((self->field_94 != 0) ^ 1);
        }
        D_004E2F88.field_0 = self->field_A0;
        D_004E2F8C.field_0 = self->field_AC;
        D_004E2F90.field_0 = self->field_B8;
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    if ((p->field_2C != 0 && func_00319360((char *)self + 0xBC) != 0)
     || (p->field_38 != 0 && func_00319330((char *)self + 0xBC) != 0)) return;
    unsigned short i = self->field_BC;
    if (self->field_C0[i].field_4 != 0) return;
    if (p->field_44 != 0) {
        self->field_108[i]->vfunc_10();
        func_00440E20_reset(self);
    } else if (p->field_14 != 0) {
        self->field_108[i]->vfunc_8();
        func_00440E20_reset(self);
    } else if (p->field_20 != 0) {
        self->field_108[i]->vfunc_C();
        func_00440E20_reset(self);
    }
}
