// CB3VehicleDeform::Prepare(CB3VehicleEssentialParams*,CB3VehicleParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3VehicleDeform has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (near7: func_003E7640 returns CGtMatrix3x4 by value; field_50/60 = func_003E7640(this,k).mPos with CGtV3d fields (v272 call-temp member read)).

#include "b3/GtMathPs2.h"

class CB3VehicleEssentialParams;
class CB3VehicleParams;
class CB3ConvexHull;

class CB3VehicleDeform;
struct CB3VehicleEssentialParams;
struct UnkStruct_00461150_2;
struct UnkStruct_00461150_4;
struct UnkStruct_00461150_e0;

struct UnkStruct_00461150_e0 {
    GtMathPs2::CGtV4d field_0;
    unsigned char pad_10[0x20];
};

struct UnkStruct_00461150_2 {
    unsigned char pad_0[0x40];
    int field_40;
};

struct CB3VehicleEssentialParams {
    unsigned char pad_0[0x40];
    int field_40;
};

struct UnkStruct_00461150_4 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
    unsigned char pad_40[0x30];
    u_long128 field_70;
};

class CB3VehicleDeform {
public:
    int Prepare(CB3VehicleEssentialParams* p0, CB3VehicleParams* p1);

    int field_0;
    int field_4;
    unsigned char pad_8[0x8];
    UnkStruct_00461150_2 * field_10;
    int field_14;
    int field_18;
    unsigned char pad_1C[0x28];
    unsigned char field_44;
    unsigned char pad_45[0x2];
    unsigned char field_47;
    unsigned char pad_48[0x8];
    GtMathPs2::CGtV3d field_50;
    GtMathPs2::CGtV3d field_60;
    unsigned char pad_70[0x20];
    UnkStruct_00461150_e0 field_90[1];  // [G] element count unknown
};

extern "C" void GetDefaultCornerHeights__16CB3VehicleDeformFP13CB3ConvexHullPf(void *, void *, float*);  // CB3VehicleDeform::GetDefaultCornerHeights(CB3ConvexHull*,float*)
extern "C" void Reset__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams(void *, void *, void *);  // CB3VehicleDeform::Reset(CB3VehicleEssentialParams*,CB3VehicleParams*)
extern "C" GtMathPs2::CGtMatrix3x4 func_003E7640(CB3VehicleDeform *, int);  // [G] matrix returned by value (hidden a0)

// 0x00461150
int CB3VehicleDeform::Prepare(CB3VehicleEssentialParams* p0, CB3VehicleParams* p1)
{
    field_44 = 0;
    field_14 = 0;
    field_18 = 0;
    for (int i = 0; (i < 4); i++) {
        field_90[i].field_0.SetW(0.0f);
    }
    field_4 = 0x2B9D6F8;
    field_0 = 0xFD462907;
    field_10 = (UnkStruct_00461150_2 *)p0;
    field_18 = field_10->field_40;
    GetDefaultCornerHeights__16CB3VehicleDeformFP13CB3ConvexHullPf(this, (CB3ConvexHull*)(p0->field_40 + 4192), (float*)((char *)this + 0x28));
    field_50 = func_003E7640(this, 2).mPos;
    field_60 = func_003E7640(this, 3).mPos;
    field_10 = 0;
    field_18 = 0;
    field_47 = 0;
    Reset__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams(this, (CB3VehicleEssentialParams*)p0, p1);
    return 1;
}
