// CB3CameraUtils::GetPositionAtParam(CB3AILaneStruct*,unsigned short,float,EAISegmentLinkType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraUtils.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near22: compiler-chosen lerp stand-in (vsub on b, t .ni, vmulx/vadd on t), u_long128 copies in a stack struct, N140 0x20 pad, direct p0->field_0 index).

// CB3CameraUtils::GetPositionAtParam(CB3AILaneStruct*,unsigned short,float,EAISegmentLinkType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraUtils.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3AILaneStruct;
enum EAISegmentLinkType {};

class CB3CameraUtils;
struct CB3AILaneStruct;
struct UnkStruct_002F5D40_2;
struct UnkStruct_002F5D40_e0;
struct UnkStruct_002F5D40_e3;
struct UnkStruct_D_0064D354;

struct CB3AILaneStruct {
    UnkStruct_002F5D40_e0 * field_0;
};

struct UnkStruct_D_0064D354 {
    UnkStruct_002F5D40_e3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002F5D40_2 {
    u_long128 field_0;
    u_long128 field_10;
};

struct UnkStruct_002F5D40_e0 {
    unsigned short field_0[1];  // [G] element count unknown
    unsigned char pad_2[0x2];
};

struct UnkStruct_002F5D40_e3 {
    GtMathPs2::CGtV3d field_0;
};

class CB3CameraUtils {
public:
    void GetPositionAtParam(CB3AILaneStruct* p0, unsigned short p1, float p2, EAISegmentLinkType p3);

    GtMathPs2::CGtV3d field_0;
};

extern UnkStruct_D_0064D354 D_0064D354;

// [G] N140 pad: retail's frame has 0x20 more below the two copies, with no stack access (dead slots)
struct UnkStruct_002F5D40_pad { int x[8]; UnkStruct_002F5D40_pad() {} ~UnkStruct_002F5D40_pad() {} };
// [G] N148 stand-in (near22): a + (b - a) * t with compiler-chosen VU registers -- not the header's Interpolate(CGtV3d)
// (retail 0x2F5D40: vsub on b's register, t moved .ni, vmulx/vadd onto t's register; a/b as u_long128 copies in a stack local).
static inline GtMathPs2::CGtV3d func_002F5D40_inl1(u_long128 a, u_long128 b, float t)
{
    u_long128 s;
    asm("vsub.xyz %0, %0, %1" : "+j"(b) : "j"(a));
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(t));
    asm("vmulx.xyz %0, %1, %0x" : "+j"(s) : "j"(b));
    asm("vadd.xyz %0, %1, %0" : "+j"(s) : "j"(a));
    return GtMathPs2::CGtV3d(s);
}

// 0x002F5D40
void CB3CameraUtils::GetPositionAtParam(CB3AILaneStruct* p0, unsigned short p1, float p2, EAISegmentLinkType p3)
{
    UnkStruct_002F5D40_e3 * t1 = D_0064D354.field_0;
    unsigned short t2 = p0->field_0[p1].field_0[p3];
    unsigned short t3 = p0->field_0[(p1 + 1)].field_0[p3];
    UnkStruct_002F5D40_2 local;
    UnkStruct_002F5D40_pad pad;
    local.field_0 = t1[t2].field_0.mData;
    local.field_10 = t1[t3].field_0.mData;
    field_0 = func_002F5D40_inl1(local.field_0, local.field_10, p2);
}
