// func_00270880 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (sibling func_002709D0 shape: embedded member at 0xA264, bool v if/else-if chain, vfunc_AC bool; else-if (p0) tail).

// func_00270880 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00270880;
struct UnkStruct_00270880_1;
struct UnkStruct_00270880_2;
struct UnkStruct_D_004E2A14;

struct UnkStruct_00270880_1 {
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
    virtual bool vfunc_AC();
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
};

struct UnkStruct_00270880_2 {
    unsigned char pad_0[0xAC];
    int field_AC;
};

struct UnkStruct_D_004E2A14 {
    unsigned short field_0;
};

struct UnkStruct_00270880_x {
    virtual bool vfunc_AC();
    virtual int vfunc_D8();
};

struct UnkStruct_00270880 {
    unsigned char pad_0[0xA264];
    UnkStruct_00270880_1 field_A264;
    unsigned char pad_A268[0x328F0 - 0xA268];
    unsigned char field_328F0[0x80];
    unsigned char field_32970[0x8];

    float field_32978;
    unsigned char pad_3297C[0x3D];
    unsigned char field_329B9;
    unsigned char field_329BA;
};

extern UnkStruct_D_004E2A14 D_004E2A14;

extern "C" int GetHostPlayerID__23CGtNetworkPlayerManagerFv(void *);  // CGtNetworkPlayerManager::GetHostPlayerID()
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);  // CGtNetworkPlayerManager::GetMyPlayerID() const
extern "C" void func_00240730(void *, unsigned short, void *);
extern "C" void func_00240A70(void *, int, int, float);

// 0x00270880
extern "C" void func_00270880(UnkStruct_00270880 * self, int p0)
{
    bool v;
    if (self->field_A264.vfunc_D8() != 0 || self->field_329B9 != 0) {
        if (self->field_329BA != 0) {
            v = self->field_A264.vfunc_AC();
        } else if (GetHostPlayerID__23CGtNetworkPlayerManagerFv(self) == GetMyPlayerID__23CGtNetworkPlayerManagerCFv(self)) {
            v = true;
        } else {
            v = false;
        }
    } else {
        v = false;
    }
    if (v) {
        unsigned short id = D_004E2A14.field_0;
        if (id == 0xFFFF) {
            id = 0;
        }
        func_00240A70((char *)self + 0x32970, id, p0, self->field_32978);
    } else if (p0 != 0) {
        unsigned short id = D_004E2A14.field_0;
        if (id == 0xFFFF) {
            id = 0;
        }
        func_00240730((char *)self + 0x328F0, id, (char *)self + 0x32978);
    }
}
