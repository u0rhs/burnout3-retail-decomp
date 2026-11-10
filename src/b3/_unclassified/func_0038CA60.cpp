// OnPreCrashReset__23CB3OfflineRoadRageLogicFP17CB3RaceCarPhysics -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (merged && vcall guard; D_0064D3A4 is D_00522660+0x12AD44 (same object, so count reloads in loop)).

// OnPreCrashReset__23CB3OfflineRoadRageLogicFP17CB3RaceCarPhysics -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3RaceCar;

struct UnkStruct_0038CA60;
struct UnkStruct_0038CA60_1;
struct UnkStruct_0038CA60_3;
struct UnkStruct_0038CA60_a1;
struct UnkStruct_0038CA60_e1;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D3A4;

struct UnkStruct_0038CA60_a1 {
    unsigned char pad_0[0x13F4];
    UnkStruct_0038CA60_1 * field_13F4;
};

struct UnkStruct_0038CA60_1 {
    unsigned char pad_0[0x15C6];
    unsigned char field_15C6;
    unsigned char pad_15C7[0x5];
    int field_15CC;
    unsigned char pad_15D0[0xE4];
    float field_16B4;
    int field_16B8;
    unsigned char pad_16BC[0x258];
    int field_1914;
    unsigned char pad_1918[0xEA8];
    int field_27C0;
};

struct UnkStruct_0038CA60_3 {
    unsigned char pad_0[0x108];
    int field_108;
};

struct UnkStruct_D_0064D3A4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0038CA60_e1 {
    unsigned char pad_0[0x1698];
    int field_1698;
    unsigned char pad_169C[0xDC4];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD44];
    int field_12AD44;  // [L] = D_0064D3A4 (car count)
    unsigned char pad_12AD48[0x5CF8];
    UnkStruct_0038CA60_e1 field_130A40[1];  // [G] element count unknown
};

struct UnkStruct_0038CA60 {
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
    virtual void vfunc_108(UnkStruct_0038CA60_1 *, int, int);
    unsigned char pad_4[0x64];
    unsigned char field_68[1];  // [G] element count unknown
};

extern UnkStruct_D_0064D3A4 D_0064D3A4;
extern UnkStruct_D_00522660 D_00522660;

extern "C" void RaceCarKilled__23CB3OfflineRoadRageLogicFP10CB3RaceCarP10CB3RaceCar(void *, void *, void *);  // CB3OfflineRoadRageLogic::RaceCarKilled(CB3RaceCar*,CB3RaceCar*)
extern "C" void func_00389A80(UnkStruct_0038CA60 *, UnkStruct_0038CA60_a1 *);

// 0x0038CA60
extern "C" void OnPreCrashReset__23CB3OfflineRoadRageLogicFP17CB3RaceCarPhysics(UnkStruct_0038CA60 * self, UnkStruct_0038CA60_a1 * p0)
{
    UnkStruct_0038CA60_1 * t0 = p0->field_13F4;
    int t1;
    if (t0->field_15C6 != 0 && (t1 = t0->field_15CC) != 0) {
        self->vfunc_108(t0, t1, 7);
    } else {
        self->vfunc_108(t0, 0, 8);
    }
    if (t0->field_16B8 != 0) {
        if (0.0f == t0->field_16B4) {
            if (t0->field_1914 == 0) {
                RaceCarKilled__23CB3OfflineRoadRageLogicFP10CB3RaceCarP10CB3RaceCar(self, (CB3RaceCar*)t0, 0);
            }
        }
    }
    func_00389A80(self, p0);
    if (t0->field_1914 != 0) {
        return;
    }
    if (self->field_68[t0->field_27C0] == 0) {
        return;
    }
    self->field_68[t0->field_27C0] = 0;
    for (int i = 0; (i < D_00522660.field_12AD44); i++) {
        D_00522660.field_130A40[i].field_1698 = 2;
    }
}
