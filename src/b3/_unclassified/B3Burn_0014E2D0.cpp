// CB3Burn::AddBurn(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a74: fields 38/3C float (as SetInfiniteBoost), vfunc_B4 returns float, p0*(48+4C) first).

// from build/vt\try_AddBurn__7CB3BurnFf_best.cpp
// CB3Burn::AddBurn(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3Burn;
struct UnkStruct_0014E2D0_2;
struct UnkStruct_0014E2D0_3;
struct UnkStruct_0014E2D0_e0;
struct UnkStruct_0014E2D0_e1;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051BA88;

struct UnkStruct_D_0051BA88 {
    UnkStruct_0014E2D0_2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0014E2D0_2 {
    unsigned char pad_0[0x1B4];
    UnkStruct_0014E2D0_3 * field_1B4;
};

struct UnkStruct_0014E2D0_3 {
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
    virtual float vfunc_B4();
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0014E2D0_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_0014E2D0_e1 {
    unsigned char pad_0[0x1];
};

class CB3Burn {
public:
    void AddBurn(float p0);

    unsigned char pad_0[0x34];
    float field_34;
    float field_38;
    float field_3C;
    unsigned char pad_40[0x8];
    float field_48;
    float field_4C;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" int func_00131E40(void *, float);

// 0x0014E2D0
void CB3Burn::AddBurn(float p0)
{
    if (func_00131E40(&D_004EE040, p0) != 0) {
        return;
    }
    float t0 = p0 * (field_48 + field_4C);
    if (D_0051BA88.field_0 != 0) {
        UnkStruct_0014E2D0_3 * t3 = D_0051BA88.field_0->field_1B4;
        if (t3 != 0) {
            t0 = t0 * t3->vfunc_B4();
        }
    }
    field_3C = field_3C + t0;
    field_38 = field_38 + t0;
    if (field_38 > field_34) {
        field_38 = field_34;
    }
}
