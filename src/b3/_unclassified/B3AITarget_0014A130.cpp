// CB3AITargetSpline::Prepare(CB3AICar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (header Zero() x9; loop zeroes via a compiler-chosen vadd.xyz "=j" stand-in (b119p hoists both) [L] N185).

// CB3AITargetSpline::Prepare(CB3AICar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3AICar;

class CB3AITargetSpline;
struct UnkStruct_0014A130_e0;
struct UnkStruct_0014A130_e1;

struct UnkStruct_0014A130_e0 {
    GtMathPs2::CGtV3d field_0;
};

struct UnkStruct_0014A130_e1 {
    GtMathPs2::CGtV3d field_0;
};

class CB3AITargetSpline {
public:
    int Prepare(CB3AICar* p0);

    UnkStruct_0014A130_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0x50];
    UnkStruct_0014A130_e1 field_60[1];  // [G] element count unknown
    unsigned char pad_70[0x50];
    GtMathPs2::CGtV3d field_C0;
    GtMathPs2::CGtV3d field_D0;
    GtMathPs2::CGtV3d field_E0;
    GtMathPs2::CGtV3d field_F0;
    GtMathPs2::CGtV3d field_100;
    GtMathPs2::CGtV3d field_110;
    GtMathPs2::CGtV3d field_120;
    GtMathPs2::CGtV3d field_130;
    GtMathPs2::CGtV3d field_140;
    unsigned char field_150;
    unsigned char field_151;
    unsigned char pad_152[0x2];
    CB3AICar * field_154;
};

// [L] N185: stands in for CGtV3d::Zero() on a compiler-chosen register (the header's Zero() hard-codes $vf1).
static inline void func_0014A130_inl1(GtMathPs2::CGtV3d &v)
{
    u_long128 z;
    asm("vadd.xyz %0, $vf0, $vf0" : "=j"(z));
    v.mData = z;
}
// 0x0014A130
int CB3AITargetSpline::Prepare(CB3AICar* p0)
{
    field_154 = (CB3AICar *)p0;
    field_E0.Zero();
    field_F0.Zero();
    field_C0.Zero();
    field_D0.Zero();
    field_110.Zero();
    field_130.Zero();
    field_100.Zero();
    field_120.Zero();
    field_140.Zero();
    field_151 = 0;
    field_150 = 0;
    for (int i = 0; (i < 6); i++) {
        func_0014A130_inl1(field_0[i].field_0);
        func_0014A130_inl1(field_60[i].field_0);
    }
    return 1;
}
