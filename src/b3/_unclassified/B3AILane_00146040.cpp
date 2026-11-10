// CB3AILane::GetFwdFrac(unsigned short,GtMathPs2::CGtV3d) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near33: archive minus local DotProduct (header now), CGtV3d pos = p1 copy + fwd local, field_4 re-read (no cached t0)).

// CB3AILane::GetFwdFrac(unsigned short,GtMathPs2::CGtV3d) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

class CB3AILane;
struct UnkStruct_00146040_1;
struct UnkStruct_00146040_3;
struct UnkStruct_00146040_e0;
struct UnkStruct_00146040_e1;
struct UnkStruct_00146040_e2;
struct UnkStruct_00146040_e3;
struct UnkStruct_D_0064D354;

struct UnkStruct_00146040_1 {
    GtMathPs2::CGtV3d field_0;
    GtMathPs2::CGtV3d field_10;
};

struct UnkStruct_00146040_3 {
    UnkStruct_00146040_e2 * field_0;
    UnkStruct_00146040_e0 * field_4;
};

struct UnkStruct_00146040_e0 {
    float field_0;
    unsigned char pad_4[0x4];
};

struct UnkStruct_00146040_e1 {
    float field_0;
    unsigned char pad_4[0x4];
};

struct UnkStruct_D_0064D354 {
    UnkStruct_00146040_e3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00146040_e2 {
    unsigned short field_0;
    unsigned char pad_2[0x2];
};

struct UnkStruct_00146040_e3 {
    GtMathPs2::CGtV3d field_0;
};

class CB3AILane {
public:
    float GetFwdFrac(unsigned short p0, GtMathPs2::CGtV3d p1) const;
    void GetAvgForwardsVector(unsigned short, GtMathPs2::CGtV3d*) const;

    unsigned char pad_0[0x4];
    UnkStruct_00146040_3 * field_4;
};

extern UnkStruct_D_0064D354 D_0064D354;

// 0x00146040
float CB3AILane::GetFwdFrac(unsigned short p0, GtMathPs2::CGtV3d p1) const
{
    GtMathPs2::CGtV3d pos = p1;
    float v0;
    if (p0 <= 0) {
        v0 = field_4->field_4[p0].field_0;
    } else {
        v0 = (((UnkStruct_00146040_e1 *)field_4->field_4)[p0].field_0 - ((UnkStruct_00146040_e1 *)field_4->field_4)[(p0 + -1)].field_0);
    }
    GtMathPs2::CGtV3d fwd;
    GetAvgForwardsVector(p0, &fwd);
    fwd.Normalise();
    float mm0 = (GtMathPs2::DotProduct(pos - D_0064D354.field_0[field_4->field_0[p0].field_0].field_0, fwd) / v0);
    return GtMath::Min(mm0, 1.0f);
}
