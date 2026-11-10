// NONMATCHING: func_003D62A0 -- retail 237 / ours 238 instructions, 115 in changed runs
// psweep: scoped #pragma inline_depth(3) [G] improves 125 -> 119
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003D62A0 -- hand-written (ghvu14, Ghidra draft + retail asm).
// [L] DNAT: CB3PositiveIcon2dObject::_RenderIcon(const CGt2dObject::CGt2dObjectSpace&,const void*) (research/proto/new_names.csv,
// medium): a Gt2d render callback (a0 = object space, a1 = data block). Placeholder with C linkage; _unclassified/.
// ghvu14: rings pulse outwards while the icon's timer is low, the icon then scales in (smoothstep), and once the timer
// passes 0.95 the "HUD_Strikeout" texture (found by name, the N113 record walk) is drawn over it. Types [G].

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(3)
using namespace GtMathPs2;

class CGtTexture;
struct UnkStruct_003D62A0_d { CGtTexture * field_0; float field_4; unsigned char pad_8[4]; unsigned char field_C; };
struct UnkStruct_003D62A0_blk { unsigned char pad_0[0x18]; char field_18[8]; };
struct UnkStruct_003D62A0_e { unsigned char pad_0[8]; int field_8; unsigned char pad_C[4]; };
struct UnkStruct_003D62A0_t { unsigned char pad_0[8]; int field_8; UnkStruct_003D62A0_e * field_C; };
struct UnkStruct_D_00518688 { UnkStruct_003D62A0_t * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00518688 D_00518688;
extern const float D_004CA800;   // 7.0f in the unit's .rodata [C asm]; name not recovered
extern char D_004CA808[];        // "HUD_Strikeout"
extern "C" int strcasecmp(const char *, const void *);

// [L] N185: lane w = 1.0 * the other vector's w (vmulw.w), as SetA from a lane.
static inline void func_003D62A0_inl1(CGtV4d &d, WAxisType w) { asm("vmulw.w %0, $vf0, %1w" : "+j"(d.mData) : "j"(w.lVector)); }

static inline CGtTexture *func_003D62A0_inl2()
{
    int i;
    UnkStruct_003D62A0_t *t = D_00518688.field_0;
    for (i = 0; i < t->field_8; i++) {
        int r = t->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_003D62A0_blk *)(r + 0x90))->field_18, D_004CA808) == 0) return (CGtTexture *)r;
    }
    return 0;
}
extern float D_004E0688;   // [G] .lit4 0.05 read as the pool global: retail reloads it every loop pass (a71)
extern float D_004E06DC;   // [G] .lit4 0.8, as D_004E0688

// 0x003D62A0
extern "C" void func_003D62A0(const CGt2dObject::CGt2dObjectSpace &os, const void *pv)
{
    const UnkStruct_003D62A0_d *d = (const UnkStruct_003D62A0_d *)pv;
    float n = D_004CA800;
    Gt2dRenderer::SetTexture(d->field_0);
    CGtV2d T[2];
    CGtV2d V[2];
    T[0].marValues[0] = 0.0f;
    T[0].marValues[1] = 0.0f;
    T[1] = os.mSize;
    V[0].marValues[0] = 0.0f;
    V[0].marValues[1] = 0.0f;
    V[1].marValues[0] = 1.0f;
    V[1].marValues[1] = 1.0f;
    float t = 2.857142925f * d->field_4;
    if (t < 0.5f + D_004E0688 * (n - 1.0f)) {
        CGtV4d c;
        c = os.mColour;
        float s = 0.5f - t;
        float a = c.W() * 0.6f;
        CGtV2d p;
        p.marValues[1] = os.mTopLeftPos.marValues[1];
        for (int i = 0; (float)i < n; i++) {
            if (s <= 0.5f && s > 0.0f) {
                c.SetA(a);
                p.marValues[0] = os.mTopLeftPos.marValues[0] + (-6.25f * s) * os.mSize.marValues[0];
                Gt2dRenderer::RenderSpritesTex(c, p, 1, T, V);
                p.marValues[0] = os.mTopLeftPos.marValues[0] + (12.5f * s) * os.mSize.marValues[0];
                Gt2dRenderer::RenderSpritesTex(c, p, 1, T, V);
            }
            a *= D_004E06DC;
            s += D_004E0688;
        }
    }
    if (!(t < 0.5f)) {
        CGtV4d c;
        c = os.mColour;
        Gt2dRenderer::RenderSpritesTex(c, os.mTopLeftPos, 1, T, V);
        if (t < 1.0f) {
            float u = 0.8f - 1.6f * (t - 0.5f);
            float w = 3.0f - 2.0f * (u * u);
            float lo = 0.5f * (1.0f - w);
            float hi = 0.5f * (1.0f + w);
            CGtV4d c2 = c;
            func_003D62A0_inl1(c, c2.W() * u);
            T[0] = os.mSize * lo;
            T[1] = os.mSize * hi;
            Gt2dRenderer::RenderSpritesTex(c, os.mTopLeftPos, 1, T, V);
        }
    }
    if (d->field_C != 0 && !(t < 0.95f)) {
        Gt2dRenderer::SetTexture(func_003D62A0_inl2());
        Gt2dRenderer::RenderSpritesTex(os.mColour, os.mTopLeftPos, 1, T, V);
    }
}

#pragma pop
