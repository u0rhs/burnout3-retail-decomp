// CB3EnvironmentManager::BuildEnvmapSunCoronaData() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (RenderSunBlob clone + [L] N185 operator+(YAxisType,float) stand-in; c declared before v, 8 N140 pads).

// CB3EnvironmentManager::BuildEnvmapSunCoronaData() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written from the proven sibling CB3EnvironmentManager::RenderSunBlob (B3EnvironmentManager_002BC2B0.cpp,
// simfind 0.63): same body, PrepareEnvmapSunCoronaData instead of RenderBlob, and the camera position's Y raised by D_004E1C80.

// Frame (0xB0): CGtV3d c at 0xA0 above v at 0x90, then 8 N140 pads (0x10..0x80) standing in for retail's dead slots;
// SetupCamera taken as const void* (&c, &v).

struct UnkStruct_002BC190_pad { int x[4]; UnkStruct_002BC190_pad() {} ~UnkStruct_002BC190_pad() {} };
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV4d;
using GtMathPs2::YAxisType;
extern float D_004E1C80;
// [L] N185: stands in for a missing GtMathPs2 inline, operator+(YAxisType, float) (as the header's operator-(YAxisType, float)).
static inline YAxisType operator+(YAxisType a, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return YAxisType(r);
}
struct UnkStruct_002BC190_e { CGtV4d field_0; unsigned char pad_10[0x20]; float field_30; unsigned char pad_34[0xC]; };
extern "C" void SetupCamera__14CB3SunRendererFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV4dff(const void *, const void *, float, float);
extern "C" void PrepareEnvmapSunCoronaData__14CB3SunRendererFv();

class CB3EnvironmentManager {
public:
    void BuildEnvmapSunCoronaData();
    unsigned char pad_0[0x70];
    CGtV3d field_70;
    unsigned char pad_80[0x10];
    float field_90;
    unsigned char pad_94[0x1C];
    UnkStruct_002BC190_e field_B0[2];
    int field_130;
    unsigned char pad_134[0x8];
    unsigned char field_13C;
    unsigned char pad_13D[0xF];
    unsigned char field_14C;
};

// 0x002BC190
void CB3EnvironmentManager::BuildEnvmapSunCoronaData()
{
    if (field_14C == 0) return;
    if (field_13C != 0) {
    CGtV3d c;
    CGtV4d v;
    UnkStruct_002BC190_pad p1, p2, p3, p4, p5, p6, p7, p8;
    v.SetX(field_70.X());
    v.SetY(field_70.Y());
    v.SetZ(field_70.Z());
    float w = (*(UnkStruct_002BC190_e *)((char *)this + 0xB0 + field_130 * 0x40)).field_30;
    // [L] CGtV4d::SetA(w), retail's second shape (v277): the scalar by its own qmtc2.ni statement onto a compiler-chosen
    // register, as the header's CGtSphere::SetRadius (hdrrd); the one-statement header SetA hoists v's lqc2 above the lw.
    { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(w)); asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
    c = CGtV3d((*(UnkStruct_002BC190_e *)((char *)this + 0xB0 + field_130 * 0x40)).field_0.mData);
    c.SetY(c.Y() + D_004E1C80);
    SetupCamera__14CB3SunRendererFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV4dff(&c, &v, 12.0f, field_90);
    PrepareEnvmapSunCoronaData__14CB3SunRendererFv();
    }
}
