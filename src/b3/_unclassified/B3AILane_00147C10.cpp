// CB3AILane::GetWidth(unsigned short) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near11: GetTotalWidth's compiler-chosen vsub + SetY stand-in (b, a loads then zero)).

// CB3AILane::GetWidth(unsigned short) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3AILane;
struct UnkStruct_00147C10_2;
struct UnkStruct_00147C10_e0;
struct UnkStruct_00147C10_e1;
struct UnkStruct_D_0064D354;

struct UnkStruct_D_0064D354 {
    UnkStruct_00147C10_e1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00147C10_2 {
    UnkStruct_00147C10_e0 * field_0;
};

struct UnkStruct_00147C10_e0 {
    unsigned short field_0;
    unsigned short field_2;
};

struct UnkStruct_00147C10_e1 {
    GtMathPs2::CGtV3d field_0;
};

class CB3AILane {
public:
    float GetWidth(unsigned short p0) const;

    unsigned char pad_0[0x4];
    UnkStruct_00147C10_2 * field_4;
};

extern UnkStruct_D_0064D354 D_0064D354;

// 0x00147C10
// [L] N185: stands in for missing GtMathPs2 inlines -- compiler-chosen vsub (N198) + SetY(0.0f) as in GetTotalWidth (s318).
float CB3AILane::GetWidth(unsigned short p0) const
{
    u_long128 b = D_0064D354.field_0[field_4->field_0[p0].field_2].field_0.mData;
    u_long128 a = D_0064D354.field_0[field_4->field_0[p0].field_0].field_0.mData;
    u_long128 z; asm("qmtc2.ni %1, %0" : "=j"(z) : "r"(0.0f));
    u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a), "j"(b));
    asm("vaddx.y %0, $vf0, %1x" : "+j"(t) : "j"(z));
    GtMathPs2::CGtV3d v(t);
    return v.GetLength();
}
