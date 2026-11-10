// CB3Burn::StartBurn(CB3RaceCarPhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a67: bool StartBurn, single && block condition (shared return 0), float guard !(x>=0 && lim<x+min), vfunc_14 on D_004EE040 row).

class CB3RaceCarPhysics;
struct UnkStruct_StartBurn_1;
struct UnkStruct_StartBurn_row;

struct UnkStruct_StartBurn_row {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_StartBurn_1 {
    unsigned char pad_0[0x10CC];
    float field_10CC;
    unsigned char pad_10D0[0x16F0];
    int field_27C0;
};

class CB3RaceCarPhysics {
public:
    unsigned char pad_0[0x215];
    signed char field_215;
    unsigned char pad_216[0x11DE];
    UnkStruct_StartBurn_1 * field_13F4;
};

class CB3Burn {
public:
    bool StartBurn(CB3RaceCarPhysics * p0);

    unsigned char pad_0[0x24];
    float field_24;
    float field_28;
    unsigned char pad_2C[0xC];
    float field_38;
    unsigned char pad_3C[0x8];
    float field_44;
    unsigned char pad_48[0x8];
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
    unsigned char field_53;

    static float gmrMinimumBoostRecoveryTime;
};

extern UnkStruct_D_004EE040 D_004EE040;
extern "C" void func_0030B130(void *, int);

// [L] retail CB3Burn::StartBurn(CB3RaceCarPhysics*) (mangled symbol in retail's tables)
// 0x0014DEF0
bool CB3Burn::StartBurn(CB3RaceCarPhysics * p0)
{
    float limit = p0->field_13F4->field_10CC;
    if (field_52 == 0 && !(field_38 < field_44) && !(field_28 >= 0.0f && limit < field_28 + gmrMinimumBoostRecoveryTime)) {
        field_52 = 1;
        field_53 = 0;
        func_0030B130(this, 0);
        if (p0->field_215 == 1) {
            ((UnkStruct_StartBurn_row *)((char *)&D_004EE040 + p0->field_13F4->field_27C0 * 0xBB0 + 0x28E00))->vfunc_14(0, 0);
        }
        field_24 = limit;
        return 1;
        return 1;
    }
    return 0;
}
