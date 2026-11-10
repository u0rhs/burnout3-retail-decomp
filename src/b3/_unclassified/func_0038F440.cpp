// OnPreCrashReset__26CB3OnlineRoadRageRaceLogicFP17CB3RaceCarPhysics -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (merged && conditions with one else arm (vfunc_108(...,0,8)); && chain for the vfunc_7C guard).

// lifter variant 0
// OnPreCrashReset__26CB3OnlineRoadRageRaceLogicFP17CB3RaceCarPhysics -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038F440;
struct UnkStruct_0038F440_1;
struct UnkStruct_0038F440_3;
struct UnkStruct_0038F440_4;
struct UnkStruct_0038F440_a1;

struct UnkStruct_0038F440_a1 {
    unsigned char pad_0[0x13F4];
    UnkStruct_0038F440_1 * field_13F4;
};

struct UnkStruct_0038F440_1 {
    unsigned char pad_0[0x15C6];
    unsigned char field_15C6;
    unsigned char pad_15C7[0x5];
    int field_15CC;
};

struct UnkStruct_0038F440_3 {
    unsigned char pad_0[0x7C];
    int field_7C;
    unsigned char pad_80[0x88];
    int field_108;
};

struct UnkStruct_0038F440_4 {
    unsigned char pad_0[0x1160];
    unsigned char field_1160;
    unsigned char pad_1161[0x553];
    float field_16B4;
    unsigned char pad_16B8[0x25C];
    int field_1914;
};

struct UnkStruct_0038F440 {
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
    virtual void vfunc_7C(UnkStruct_0038F440_4 *);
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
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual void vfunc_F0();
    virtual void vfunc_F4();
    virtual void vfunc_F8();
    virtual void vfunc_FC();
    virtual void vfunc_100();
    virtual void vfunc_104();
    virtual void vfunc_108(UnkStruct_0038F440_1 *, int, int);
};

extern "C" void func_00392000(UnkStruct_0038F440 *, UnkStruct_0038F440_a1 *);

// 0x0038F440
extern "C" void OnPreCrashReset__26CB3OnlineRoadRageRaceLogicFP17CB3RaceCarPhysics(UnkStruct_0038F440 * self, UnkStruct_0038F440_a1 * p0)
{
    if (p0->field_13F4->field_15C6 != 0 && p0->field_13F4->field_15CC != 0) {
        self->vfunc_108(p0->field_13F4, p0->field_13F4->field_15CC, 7);
    } else {
        self->vfunc_108(p0->field_13F4, 0, 8);
    }
    UnkStruct_0038F440_4 * t2 = (UnkStruct_0038F440_4 *)p0->field_13F4;
    if (t2->field_1914 == 0 && t2->field_1160 == 0 && 0.0f == t2->field_16B4) {
        self->vfunc_7C(t2);
    }
    func_00392000(self, p0);
}
