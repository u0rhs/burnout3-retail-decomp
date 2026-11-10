// CB3PhysicsManagerDebug::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManagerDebug.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (lit4 literals 0.3f/0.8333333f; SetA as two statements (qmtc2 own =j, then vmulx.w) [L] N185 stand-in).

// CB3PhysicsManagerDebug::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManagerDebug.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3PhysicsManagerDebug;
struct UnkStruct_D_01E86250;

struct UnkStruct_D_01E86250 {
    GtMathPs2::CGtV4d field_0;
};

class CB3PhysicsManagerDebug {
public:
    void Construct();

    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char field_7;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char field_A;
    unsigned char field_B;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    unsigned char field_F;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char field_13;
    int field_14;
    float field_18;
    float field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    unsigned char pad_30[0x1B10];
    int field_1B40;
    unsigned char pad_1B44[0x38C];
    int field_1ED0;
};

extern UnkStruct_D_01E86250 D_01E86250;


// [L] N185: stands in for CGtV4d::SetA(float) with the scalar moved by its own statement (as CGtV4d::SetW / CGtSphere::SetRadius).
static inline void func_002BED00_inl1(GtMathPs2::CGtV4d &v, float a)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(a));
    asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(s));
}

// 0x002BED00
void CB3PhysicsManagerDebug::Construct()
{
    field_0 = 0;
    field_7 = 0;
    field_8 = 0;
    field_9 = 0;
    field_B = 0;
    field_6 = 0;
    field_A = 0;
    field_C = 0;
    field_D = 0;
    field_E = 0;
    field_F = 0;
    field_10 = 0;
    field_11 = 0;
    field_12 = 1;
    field_13 = 1;
    field_14 = 0;
    field_1B40 = 0;
    field_1ED0 = 0;
    field_1 = 0;
    field_2 = 0;
    field_20 = 0;
    field_24 = 0;
    field_28 = 0;
    field_2C = 150;
    field_18 = 1.5f;
    field_1C = 0.3f;
    field_3 = 0;
    field_4 = 0;
    field_5 = 0;
    func_002BED00_inl1(D_01E86250.field_0, 0.8333333f);
}
