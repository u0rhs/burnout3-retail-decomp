// HandlePropHit__8CB3ScoreFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (whole body nested in one if (no early returns); 590>594 max; mult before the vcall; 1.0f in a float local; 4C/B8 int +=).

// lifter variant 0
// HandlePropHit__8CB3ScoreFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3Burn;
class CB3Score;
struct UnkStruct_00156EF0;
struct UnkStruct_00156EF0_1;
struct UnkStruct_00156EF0_5;
struct UnkStruct_00156EF0_6;
struct UnkStruct_00156EF0_e0;
struct UnkStruct_00156EF0_e1;
struct UnkStruct_D_0051BA88;

class CB3Burn {
public:
    void AddBurn(float);
};

struct UnkStruct_00156EF0_1 {
    unsigned char pad_0[0x18EA];
    unsigned char field_18EA;
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_00156EF0_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00156EF0_5 {
    unsigned char pad_0[0x1B4];
    UnkStruct_00156EF0_6 * field_1B4;
};

struct UnkStruct_00156EF0_6 {
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
    virtual int vfunc_48();
};

struct UnkStruct_00156EF0_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00156EF0_e1 {
    unsigned char pad_0[0x1];
};

class CB3Score {
public:
    static float gmrPropHitBurnValue;
    static int gmnPropHitBP;
};

struct UnkStruct_00156EF0 {
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x3C];
    int field_4C;
    unsigned char pad_50[0x68];
    int field_B8;
    unsigned char pad_BC[0xC];
    UnkStruct_00156EF0_1 * field_C8;
    CB3Burn field_CC;
    unsigned char pad_CD[0x1AF];
    int field_27C;
    unsigned char pad_280[0x308];
    int field_588;
    float field_58C;
    int field_590;
    int field_594;
};

extern UnkStruct_D_0051BA88 D_0051BA88;

// 0x00156EF0
extern "C" void HandlePropHit__8CB3ScoreFv(UnkStruct_00156EF0 * self)
{
    if (self->field_27C != 3 && self->field_C8->field_18EA == 0) {
        self->field_588++;
        self->field_58C = self->field_C;
        self->field_590++;
        if (self->field_590 > self->field_594) {
            self->field_594 = self->field_590;
        }
        self->field_CC.AddBurn(CB3Score::gmrPropHitBurnValue);
        int t1 = CB3Score::gmnPropHitBP * self->field_590;
        if (D_0051BA88.field_0->field_1B4->vfunc_48() & 1) {
            float one = 1.0f;
            int d = (int)((float)t1 * one);
            self->field_4C += d;
            self->field_B8 += d;
        }
    }
}
