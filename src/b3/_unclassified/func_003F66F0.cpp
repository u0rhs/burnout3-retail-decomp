// func_003F66F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (unsigned long (64-bit) return; whole switch in a [G] static inline helper returning directly (all returns join one block, no movz select)).

// lifter variant 0
// func_003F66F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003F66F0;
struct UnkStruct_003F66F0_4;
struct UnkStruct_003F66F0_5;
struct UnkStruct_003F66F0_a1;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_0051BAA4;
struct UnkStruct_D_01E32AE0;

struct UnkStruct_D_0051BAA4 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003F66F0_a1 {
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
    virtual int vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual void vfunc_F0();
    virtual void vfunc_F4();
    virtual void vfunc_F8();
    virtual void vfunc_FC();
    virtual int vfunc_100();
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003F66F0_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003F66F0_4 {
    unsigned char pad_0[0x100];
    int field_100;
};

struct UnkStruct_003F66F0_5 {
    unsigned char pad_0[0x1B0];
    // vptr at +0x1B0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual int vfunc_20();
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003F66F0 {
    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_D_0051BAA4 D_0051BAA4;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E32AE0 D_01E32AE0;

extern "C" int func_0026C8C0(void *);

// 0x003F66F0
static inline unsigned long func_003F66F0_inl1(UnkStruct_003F66F0 * self, UnkStruct_003F66F0_a1 * p0)  // [G] placeholder: code inlined from an unnamed helper
{
    switch (self->field_10) {
    case 0:
        if (D_0051BAA4.field_0 == 0) {
            return 0;
        }
        if (func_0026C8C0(&D_01E32AE0) != 0) {
            return 16;
        }
        return 0;
    case 1:
        if (p0->vfunc_D8() == 0) {
            return 1;
        }
        UnkStruct_003F66F0_5 * t0 = D_0051BA88.field_0;
        if (p0->vfunc_100() >= t0->vfunc_20()) {
            return 0x200001;
        }
        return 0x8000000001UL;
    }
}

extern "C" unsigned long func_003F66F0(UnkStruct_003F66F0 * self, UnkStruct_003F66F0_a1 * p0)
{
    return func_003F66F0_inl1(self, p0);
}
