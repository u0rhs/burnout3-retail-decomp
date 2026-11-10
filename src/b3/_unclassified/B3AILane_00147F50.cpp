// CB3AILane::GetLeftwardsVector(unsigned short,GtMathPs2::CGtV3d*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (vsub (header) + CrossProduct stand-in (GPR operands, .i result) [L] N185; .set noreorder around the store [L] N188).

// CB3AILane::GetLeftwardsVector(unsigned short,GtMathPs2::CGtV3d*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3AILane;
struct UnkStruct_00147F50_2;
struct UnkStruct_00147F50_e1;
struct UnkStruct_00147F50_e2;
struct UnkStruct_D_0064D354;
struct UnkStruct_kYAxis;

struct UnkStruct_D_0064D354 {
    UnkStruct_00147F50_e2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00147F50_2 {
    UnkStruct_00147F50_e1 * field_0;
};

struct UnkStruct_kYAxis {
    GtMathPs2::CGtV3d field_0;
};

struct UnkStruct_00147F50_e1 {
    unsigned short field_0;
    unsigned short field_2;
};

struct UnkStruct_00147F50_e2 {
    GtMathPs2::CGtV3d field_0;
};

class CB3AILane {
public:
    int GetLeftwardsVector(unsigned short p0, GtMathPs2::CGtV3d* p1) const;

    unsigned char pad_0[0x4];
    UnkStruct_00147F50_2 * field_4;
};

extern UnkStruct_D_0064D354 D_0064D354;
extern UnkStruct_kYAxis kYAxis;

// [L] N185: stands in for GtMathPs2::CrossProduct(CGtV3d, CGtV3d) (= a x b): both operands moved in from GPRs and the
// result moved out .i (vopmsub is an ACC-result op, N190; tools/vu0_ni_fixup.py restores .ni), as retail 0x147F9C-0x147FAC.
static inline GtMathPs2::CGtV3d func_00147F50_inl1(GtMathPs2::CGtV3d a, GtMathPs2::CGtV3d b)
{
    u_long128 t;
    asm("qmtc2.i %1, $vf2" "\n\t" "qmtc2.i %2, $vf1" "\n\t" "vopmula.xyz $ACC, $vf2, $vf1" "\n\t" "vopmsub.xyz $vf1, $vf1, $vf2" "\n\t"
        "qmfc2.i %0, $vf1" : "=r"(t) : "r"(a.mData), "r"(b.mData));
    return GtMathPs2::CGtV3d(t);
}

// 0x00147F50
int CB3AILane::GetLeftwardsVector(unsigned short p0, GtMathPs2::CGtV3d* p1) const
{
    GtMathPs2::CGtV3d r = func_00147F50_inl1(D_0064D354.field_0[field_4->field_0[p0].field_0].field_0 - D_0064D354.field_0[field_4->field_0[p0 + 1].field_0].field_0, kYAxis.field_0);
    // [L] N188: a .set noreorder region around the store keeps the result in v0 with the return value in the jr delay slot
    // (scheduled freely, the li v0,1 rises above the qmfc2 and the result moves to v1).
    asm(".set noreorder");
    *p1 = r;
    asm(".set reorder");
    return 1;
}
