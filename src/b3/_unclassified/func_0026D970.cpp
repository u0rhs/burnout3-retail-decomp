// func_0026D970 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (embedded member object at 0xA264 (recomputed address); bool result var; if/else-if chain; vfunc_AC bool).

struct UnkStruct_0026D970;
struct UnkStruct_0026D970_1;
struct UnkStruct_0026D970_2;

struct UnkStruct_0026D970_1 {
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

struct UnkStruct_0026D970_2 {
    unsigned char pad_0[0xAC];
    int field_AC;
};

struct UnkStruct_0026D970 {
    unsigned char pad_0[0xA264];
    UnkStruct_0026D970_1 field_A264;
    unsigned char pad_A268[0x329B9 - 0xA268];
    unsigned char field_329B9;
    unsigned char field_329BA;
};

extern "C" int GetHostPlayerID__23CGtNetworkPlayerManagerFv(void *);  // CGtNetworkPlayerManager::GetHostPlayerID()
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);  // CGtNetworkPlayerManager::GetMyPlayerID() const
extern "C" int func_00240660(void *, int, float);

// 0x0026D970
extern "C" int func_0026D970(UnkStruct_0026D970 * self)
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
    if (v) return 1;
    return func_00240660((char *)self + 0x328F0, 8, 0.05f);
}
