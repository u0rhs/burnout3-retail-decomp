// CB3ShadowRenderer::BeginShadowPlaneRendering() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ShadowRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (ghvu10: Ghidra draft; N113 find inline with i declared first; header SetW(0.0f) x8; GIF quads *p++ with 128-bit lq | mask; camera sub-object pointer).

// CB3ShadowRenderer::BeginShadowPlaneRendering() -- hand-written (ghvu10, Ghidra draft).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ShadowRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
// Static: a0 is never read.

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV4d;

class CGtTexture;
class B3Im3d {
public:
    static void BeginRendering();
    static void SetTexture(CGtTexture *);
};
class CB3ShadowRenderer {
public:
    static void BeginShadowPlaneRendering();
};
struct UnkStruct_00303C10_e0 { unsigned char pad_0[0x8]; int field_8; unsigned char pad_C[0x4]; };
struct UnkStruct_00303C10_1 { unsigned char pad_0[0x8]; int field_8; UnkStruct_00303C10_e0 *field_C; };
struct UnkStruct_D_00518688 { UnkStruct_00303C10_1 *field_0; unsigned char pad_4[0xC]; };
// [G] the block at +0x90 of each entry's object; a name at +0x18 (N113, B3HUDImpactTime_003D6AB0).
struct UnkStruct_00303C10_blk { unsigned char pad_0[0x18]; char field_18[8]; };
struct UnkStruct_00303C10_v { CGtV4d field_0; float field_10; float field_14; unsigned char pad_18[8]; };
struct UnkStruct__gpCache { UnkStruct_00303C10_v field_0[8]; };
struct UnkStruct_00303C10_cam { unsigned char pad_0[0x1C0]; u_long128 field_1C0; u_long128 field_1D0; unsigned char pad_1E0[0x50]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x470]; UnkStruct_00303C10_cam field_470[1]; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004C4550 { unsigned char pad_0[0x10]; };
struct UnkStruct_farFogPlane { u_long128 *field_0; };

extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_004C4550 D_004C4550;
extern UnkStruct__gpCache *_gpCache;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_farFogPlane farFogPlane;
extern "C" int strcasecmp(const char *, const void *);
extern "C" void _rwDMAOpenVIFPkt(int, int);

static inline int func_00303C10_inl1()  // [G] placeholder: an inlined find-by-name
{
    int i;
    UnkStruct_00303C10_1 *t0 = D_00518688.field_0;
    for (i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_00303C10_blk *)(t2 + 0x90))->field_18, &D_004C4550) == 0) {
            return t2;
        }
    }
    return 0;
}

// 0x00303C10
void CB3ShadowRenderer::BeginShadowPlaneRendering()
{
    CGtTexture *tex = (CGtTexture *)func_00303C10_inl1();
    _gpCache->field_0[0].field_0.SetW(0.0f);
    _gpCache->field_0[1].field_0.SetW(0.0f);
    _gpCache->field_0[2].field_0.SetW(0.0f);
    _gpCache->field_0[3].field_0.SetW(0.0f);
    _gpCache->field_0[4].field_0.SetW(0.0f);
    _gpCache->field_0[5].field_0.SetW(0.0f);
    _gpCache->field_0[6].field_0.SetW(0.0f);
    _gpCache->field_0[7].field_0.SetW(0.0f);
    _gpCache->field_0[0].field_10 = 0.0f;
    _gpCache->field_0[0].field_14 = 0.0f;
    _gpCache->field_0[1].field_10 = 1.0f;
    _gpCache->field_0[1].field_14 = 0.0f;
    _gpCache->field_0[2].field_10 = 0.0f;
    _gpCache->field_0[2].field_14 = 0.1875f;
    _gpCache->field_0[3].field_10 = 1.0f;
    _gpCache->field_0[3].field_14 = 0.1875f;
    _gpCache->field_0[4].field_10 = 0.0f;
    _gpCache->field_0[4].field_14 = 0.8125f;
    _gpCache->field_0[5].field_10 = 1.0f;
    _gpCache->field_0[5].field_14 = 0.8125f;
    _gpCache->field_0[6].field_10 = 0.0f;
    _gpCache->field_0[6].field_14 = 1.0f;
    _gpCache->field_0[7].field_10 = 1.0f;
    _gpCache->field_0[7].field_14 = 1.0f;
    B3Im3d::BeginRendering();
    B3Im3d::SetTexture(tex);
    const u_long128 *cam = &D_00665EC0.field_470[D_00667050.field_0].field_1C0;
    _rwDMAOpenVIFPkt(0, 7);
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000006), "r"(0x5000000600000000));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008005), "r"(0xE));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)cam[0] | 0xFF00000000000000UL), "r"(0x4C));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)cam[1] | 0x100000000UL), "r"(0x4E));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x8000000044), "r"(0x42));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x50003), "r"(0x47));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(5), "r"(8));
    farFogPlane.field_0 = p;
}
