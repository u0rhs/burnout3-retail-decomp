// CB3ConnectionAnimationComponent::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConnectionAnimationComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a245: 8 separate 16-byte V4 locals (not one frame struct: avoids per-vector address regs) + 0x70-byte ctor/dtor pad declared first (N140) for the 0x100 frame).

// from build/vt/try_Construct__31CB3ConnectionAnimationCompo_best.cpp
// CB3ConnectionAnimationComponent::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConnectionAnimationComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3ConnectionAnimationComponent;
struct UnkStruct_00352990_2;
struct UnkStruct_D_004E0E94;
struct UnkStruct_D_004E1164;

struct UnkStruct_D_004E0E94 {
    float field_0;
};

struct UnkStruct_D_004E1164 {
    float field_0;
};

struct UnkStruct_00352990_2 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
    float field_50;
    float field_54;
    float field_58;
    float field_5C;
    int field_60;
    int field_64;
    int field_68;
    float field_6C;
    unsigned char pad_70[0x70];
};

class CB3ConnectionAnimationComponent {
public:
    void Construct();

    unsigned char pad_0[0x50];
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    u_long128 field_70;
    u_long128 field_80;
    u_long128 field_90;
    u_long128 field_A0;
    u_long128 field_B0;
    u_long128 field_C0;
    u_long128 field_D0;
    int field_E0;
};

extern UnkStruct_D_004E0E94 D_004E0E94;
extern UnkStruct_D_004E1164 D_004E1164;

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

struct UnkStruct_00352990_pad { unsigned char pad_0[0x70]; UnkStruct_00352990_pad() {} ~UnkStruct_00352990_pad() {} };
struct V4 { float x, y, z, w; };
// 0x00352990
void CB3ConnectionAnimationComponent::Construct()
{
    UnkStruct_00352990_pad pad;
    V4 v7, v6, v5, v4, v3, v2, v1, v0;
    Construct__20CB3MenuComponentBaseFi(this, 2);
    float t0 = D_004E0E94.field_0;
    float t1 = D_004E1164.field_0;
    v6.x = 0;
    v6.y = 0;
    v6.z = 0;
    v6.w = 0.5f;
    u_long128 t2 = *(u_long128 *)&v6;
    v5.x = t0;
    v5.w = 1.0f;
    v5.y = t0;
    v5.z = t0;
    v4.w = 1.0f;
    v4.x = t1;
    u_long128 t3 = *(u_long128 *)&v5;
    v4.y = t1;
    v3.w = 1.0f;
    v4.z = t1;
    v2.w = 1.0f;
    field_70 = t2;
    v3.x = t1;
    v3.y = t1;
    u_long128 t4 = *(u_long128 *)&v4;
    v3.z = t1;
    v1.w = 1.0f;
    field_80 = t3;
    v2.x = t1;
    v2.y = t1;
    u_long128 t5 = *(u_long128 *)&v3;
    v2.z = t1;
    v0.w = 0.5f;
    v1.x = t0;
    u_long128 t6 = *(u_long128 *)&v2;
    field_90 = t4;
    v1.y = t0;
    v1.z = t0;
    u_long128 t7 = *(u_long128 *)&v1;
    v0.x = t0;
    field_A0 = t5;
    v0.y = t0;
    v0.z = t0;
    field_B0 = t6;
    field_C0 = t7;
    field_D0 = *(u_long128 *)&v0;
    field_E0 = 0;
    field_60 = 0;
    field_64 = -1;
    field_68 = -2;
    field_6C = -3;
    field_50 = field_60;
    field_54 = field_64;
    field_58 = field_68;
    field_5C = field_6C;
}
