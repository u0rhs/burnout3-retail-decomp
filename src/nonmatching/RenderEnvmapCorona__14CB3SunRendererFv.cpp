// NONMATCHING: RenderEnvmapCorona__14CB3SunRendererFv -- retail 191 / ours 192 instructions, 85 in changed runs
// near38: two N140 pads (UnkStruct_0024B6E0_pad) give retail's 0x1C0 frame: 85 changed (was 90, frame 0x1A0). Left: the pads sit above the Y/Z lane copies (retail: copies at 0x70/0x60, dead slots 0x50/0x40; pads in inline wrappers / deeper inlines either land above or vanish), one extra instruction and the inner tristrip loop's load/store schedule
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// v281: logic complete (Im3d ctor x8 SetPlus(0), colour bytes via cvt.w.s, 7-quad VIF/GIF packet via pcpyld, 3x4 tristrip loop); left: frame 0x1A0 vs 0x1C0 (retail has 2 more dead 16-byte slots below the Y/Z lane copies; N140 pads did not add them), and the inner loop's load/store schedule
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/classes/CB3SunRenderer.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [L] CB3Im3dVertex (B3O0PCH map name): position (w = 0 by the constructor, cf. B3VehicleDeform_00460A50.cpp), UV, RGBA bytes
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    float field_10;
    float field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char field_1B;
    unsigned char pad_1C[4];
    CB3Im3dVertex() { field_0.SetPlus(0.0f); }
};
struct UnkStruct_farFogPlane { u_long128 *field_0; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern CGtV4d D_01D9B960;
extern CGtV3d D_01D9B980[16];
extern CGtV2d D_01D9BA80[16];
extern u_long128 D_01D9BB00;
extern "C" void _rwDMAOpenVIFPkt(int, int);
extern "C" void BeginRendering__6B3Im3dFv();
extern "C" void RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi(const CB3Im3dVertex *, int);
extern "C" void EndRendering__6B3Im3dFv();

// [G] the red/green bytes live in memory in retail (sb/lbu at sp+0x1BC/0x1BD, blue in a saved register):
// a two-byte local struct reproduces that (plain unsigned char locals all go to registers)
struct UnkStruct_0024B6E0_col { unsigned char field_0, field_1; };

struct UnkStruct_0024B6E0_pad { int x[4]; UnkStruct_0024B6E0_pad() {} ~UnkStruct_0024B6E0_pad() {} };
void CB3SunRenderer::RenderEnvmapCorona()
{
    CB3Im3dVertex v[8];
    UnkStruct_0024B6E0_col k;
    // [G] N140 pads: retail keeps two more dead 16-byte slots (its lowest, below the Y/Z lane copies); these give the 0x1C0 frame but sit above the copies
    UnkStruct_0024B6E0_pad p0;
    UnkStruct_0024B6E0_pad p1;
    k.field_0 = (int)(float)D_01D9B960.X();
    k.field_1 = (int)(float)D_01D9B960.Y();
    unsigned char b = (int)(float)D_01D9B960.Z();
    BeginRendering__6B3Im3dFv();
    int n = D_00667050.field_0;
    _rwDMAOpenVIFPkt(0x80000000, 7);
    u_long128 *q = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x1000000000008006UL), "r"(0xEUL));
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x31001UL), "r"(0x47UL));
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x44UL), "r"(0x42UL));
    char *tab = (char *)&D_00665EC0 + n * 0x230;
    unsigned long lo = (unsigned long)*(u_long128 *)(tab + 0x630) | 0x00FFFFFF00000000UL;
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(lo), "r"(0x4CUL));
    *q++ = D_01D9BB00;
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x61UL), "r"(0x14UL));
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x5UL), "r"(0x8UL));
    farFogPlane.field_0 = q;
    for (int j = 0; j < 3; j++) {
        int r0 = j * 4;
        int r1 = (j + 1) * 4;
        for (int i = 0; i < 4; i++) {
            int k0 = i + r0;
            int k1 = i + r1;
            CB3Im3dVertex &a = v[i * 2];
            a.field_0.SetGtV3d(D_01D9B980[k0]);
            a.field_10 = D_01D9BA80[k0].marValues[0];
            a.field_14 = D_01D9BA80[k0].marValues[1];
            a.field_18 = k.field_0;
            a.field_19 = k.field_1;
            a.field_1A = b;
            a.field_1B = 0x80;
            CB3Im3dVertex &c = v[i * 2 + 1];
            c.field_0.SetGtV3d(D_01D9B980[k1]);
            c.field_10 = D_01D9BA80[k1].marValues[0];
            c.field_14 = D_01D9BA80[k1].marValues[1];
            c.field_18 = k.field_0;
            c.field_19 = k.field_1;
            c.field_1A = b;
            c.field_1B = 0x80;
        }
        RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi(v, 8);
    }
    EndRendering__6B3Im3dFv();
}

