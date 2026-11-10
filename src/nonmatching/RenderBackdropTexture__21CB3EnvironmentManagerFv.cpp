// NONMATCHING: RenderBackdropTexture__21CB3EnvironmentManagerFv -- retail 237 / ours 236 instructions, 94 in changed runs
// a231: int i = 0 before func_00217E70(7) puts i in s4 (94 vs 99); retail sets i=0 even earlier (before the sqrt of h=Bd_h(alt,0)) but int i=0 at top gave 240 instrs; loop constant regs f2-f8 differ
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: RenderBackdropTexture__21CB3EnvironmentManagerFv -- retail 237 / ours 236 instructions, 99 in changed runs
// retail 237/ours 236 instrs, 99 in changed runs. Head (~40 instrs) exact: GtMathPs2 CGtV4d/CGtV2d locals, 'T* const g=&D_0064E470' base, single-expression 0.0f+texel+0.46875f*ratio (adda/madd). Left: the 12-iteration P/U fill loop: retail keeps constants in f2-f8 and a saved-reg induction var s4 (i=0 set before func_00217E70(7), +=2 mid-body), ours int i lands in a-reg when set after the call; Bd_h = 24*(0.5-((1-sqrtf(D*k))-alt)) clamp 'if(t>24)'
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_Bd_elem { u_long128 field_0; unsigned char pad_10[0x30]; };
struct UnkStruct_Bd_env {
    unsigned char pad_0[0xB0];
    UnkStruct_Bd_elem field_B0[2];
    int field_130;
    unsigned char pad_134[0x18];
    unsigned char field_14C;
};
struct UnkStruct_Bd_t { unsigned char pad_0[8]; int field_8; };
struct UnkStruct_D_0064D344 { UnkStruct_Bd_t * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064E470 { unsigned char pad_0[0x348]; float field_348; int field_34C; };
struct UnkStruct_D_004E0F08 { float field_0; };
extern UnkStruct_D_0064D344 D_0064D344;
extern UnkStruct_D_0064E470 D_0064E470;
extern UnkStruct_D_004E0F08 D_004E0F08;
extern "C" void SetBackdropAsRenderTarget__18CB3SkyDomeRendererFv();
extern "C" void SetGradientTextureAsSource__18CB3SkyDomeRendererFv();
extern "C" void Begin__12Gt2dRendererFv();
extern "C" void SetTextureAddressMode__12Gt2dRendererFQ212Gt2dRenderer23EGt2dRendererTexAddress(int);
extern "C" void func_00217E70(int);
extern "C" void RenderSpritesTex__12Gt2dRendererFQ29GtMathPs26CGtV4dRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2d(const void *, const CGtV2d &, int, const CGtV2d *, const CGtV2d *);
extern "C" void SunPos2BearingAndAltitude__21CB3EnvironmentManagerFPfPfQ29GtMathPs26CGtV3d(void *, float *, float *, const void *);
extern "C" void End__12Gt2dRendererFv();
extern "C" void RestoreRenderTarget__18CB3SkyDomeRendererFv();

extern "C" float sqrtf(float);
static inline float Bd_h(float alt, int k)
{
    float t = 24.0f * (0.5f - ((1.0f - sqrtf(D_004E0F08.field_0 * (float)k)) - alt));
    if (t > 24.0f) t = 24.0f;
    return t;
}

// 0x002BBB90
extern "C" void RenderBackdropTexture__21CB3EnvironmentManagerFv(UnkStruct_Bd_env * self)
{
    float texel;
    float u0;
    float h;
    float fa;
    float fb;
    CGtV4d c(0.5f, 0.5f, 0.5f, 1.0f);
    CGtV2d sz(0.0f, 0.0f);
    if (self->field_14C == 0) return;
    u_long128 sun = *(u_long128 *)((char *)self + (self->field_130 << 6) + 0xB0);
    SetBackdropAsRenderTarget__18CB3SkyDomeRendererFv();
    SetGradientTextureAsSource__18CB3SkyDomeRendererFv();
    Begin__12Gt2dRendererFv();
    SetTextureAddressMode__12Gt2dRendererFQ212Gt2dRenderer23EGt2dRendererTexAddress(3);
    func_00217E70(3);
    texel = 0.015625f;
    if (D_0064D344.field_0 != 0) {
        UnkStruct_D_0064E470 * const g = &D_0064E470;
        float ratio = (g->field_348 + (float)g->field_34C) / (float)D_0064D344.field_0->field_8;
        u0 = 0.0f + texel + 0.46875f * ratio;
    } else {
        u0 = texel;
    }
    CGtV2d P[26];
    CGtV2d U[26];
    P[0].Set(0.0f, 0.0f);
    P[1].Set(64.0f, 32.0f);
    U[0].Set(u0, texel);
    U[1].Set(u0, 1.015625f);
    RenderSpritesTex__12Gt2dRendererFQ29GtMathPs26CGtV4dRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2d(&c, sz, 1, P, U);
    float bearing;
    float alt;
    SunPos2BearingAndAltitude__21CB3EnvironmentManagerFPfPfQ29GtMathPs26CGtV3d(self, &bearing, &alt, &sun);
    fa = 15.5f - bearing;
    fb = 1.0f + fa;
    h = Bd_h(alt, 0);
    int i = 0;
    func_00217E70(7);
    for (; i < 24;) {
        P[i].Set(0.0f, (float)i);
        U[i].Set(fa, 0.03125f * h);
        i += 2;
        P[i - 1].Set(64.0f, (float)i);
        h = Bd_h(alt, i);
        U[i - 1].Set(fb, 0.03125f * h);
    }
    P[i].Set(0.0f, 24.0f);
    U[i].Set(fa, 0.765625f);   // 0x3F440000 [C retail 0x2BBE3C lui a0,0x3F44] (was 0.7675f = 0x3F447AE1, port8)
    P[i + 1].Set(64.0f, 32.0f);
    U[i + 1].Set(fb, 1.015625f);
    RenderSpritesTex__12Gt2dRendererFQ29GtMathPs26CGtV4dRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2d(&c, sz, 13, P, U);
    func_00217E70(4);
    P[0].Set(0.0f, 0.0f);
    U[0].Set(0.5f + u0, texel);
    P[1].Set(64.0f, 32.0f);
    U[1].Set(0.5f + u0, 1.015625f);
    RenderSpritesTex__12Gt2dRendererFQ29GtMathPs26CGtV4dRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2d(&c, sz, 1, P, U);
    End__12Gt2dRendererFv();
    RestoreRenderTarget__18CB3SkyDomeRendererFv();
}


