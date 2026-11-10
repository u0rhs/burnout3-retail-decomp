// CB3EnvironmentManager::SunOcclusionTest() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (s313: clone of RenderSunBlob (simfind 1.00), callee OcclusionTest).

// CB3EnvironmentManager::SunOcclusionTest() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

// near4 (from a235 archive): frame = v, 3 pads, CGtV3d c, 3 pads (N140); SetupCamera taken as const void* (&c, &v).

struct UnkStruct_002BBFA0_pad { int x[4]; UnkStruct_002BBFA0_pad() {} ~UnkStruct_002BBFA0_pad() {} };
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV4d;
struct UnkStruct_002BBFA0_e { CGtV4d field_0; unsigned char pad_10[0x20]; float field_30; unsigned char pad_34[0xC]; };
extern "C" void SetupCamera__14CB3SunRendererFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV4dff(const void *, const void *, float, float);
extern "C" void OcclusionTest__14CB3SunRendererFv();

class CB3EnvironmentManager {
public:
    void SunOcclusionTest();
    unsigned char pad_0[0x70];
    CGtV3d field_70;
    unsigned char pad_80[0x10];
    float field_90;
    unsigned char pad_94[0x1C];
    UnkStruct_002BBFA0_e field_B0[2];
    int field_130;
    unsigned char pad_134[0x8];
    unsigned char field_13C;
    unsigned char pad_13D[0xF];
    unsigned char field_14C;
};

// 0x002BBFA0
void CB3EnvironmentManager::SunOcclusionTest()
{
    if (field_14C == 0) return;
    if (field_13C != 0) {
    CGtV4d v;
    UnkStruct_002BBFA0_pad p1, p2, p3;
    CGtV3d c;
    UnkStruct_002BBFA0_pad p4, p5, p6;
    v.SetX(field_70.X());
    v.SetY(field_70.Y());
    v.SetZ(field_70.Z());
    float w = (*(UnkStruct_002BBFA0_e *)((char *)this + 0xB0 + field_130 * 0x40)).field_30;
    // [L] CGtV4d::SetA(w), retail's second shape (v277): the scalar by its own qmtc2.ni statement onto a compiler-chosen
    // register, as the header's CGtSphere::SetRadius (hdrrd); the one-statement header SetA hoists v's lqc2 above the lw.
    { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(w)); asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
    c = CGtV3d((*(UnkStruct_002BBFA0_e *)((char *)this + 0xB0 + field_130 * 0x40)).field_0.mData);
    SetupCamera__14CB3SunRendererFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV4dff(&c, &v, 12.0f, field_90);
    OcclusionTest__14CB3SunRendererFv();
    }
}
