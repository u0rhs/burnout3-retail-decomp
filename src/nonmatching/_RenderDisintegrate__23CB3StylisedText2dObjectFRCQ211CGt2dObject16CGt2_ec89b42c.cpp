// NONMATCHING: _RenderDisintegrate__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 366 / ours 349 instructions, 279 in changed runs
// draftAI: logic complete; retail 366 / ours 349; call multiset identical (9; retail places the _RenderNormal fallback block before the loop); every FP and VU op count identical (header Interpolate x3, CGtV4d*CGtV4d, Zero/SetW(W()), operator*(float), SetW(W()*f) x3, GtMath::Min/Max); left: retail reloads the glyph position per strip call (lwc1 +8) and copies the A/B offsets through themselves (ld/sd +2), frame 0x250 vs 0x230
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm op for op: whiteness-lightened gradient ends, the outline/shadow offsets, the seeded CGtRandom per-glyph threshold clamp(1 + R - 2T), the drop (-10/3 a + 16/3 a^2 heights) and alpha fade, 6 strips of 4 per glyph

// CB3StylisedText2dObject::_RenderDisintegrate(const CGt2dObject::CGt2dObjectSpace&, const void*) -- draftAI (C-first draft).
// [C] name: config/symbol_addrs_b3names.txt 0x3CED40 (DNAT high); the E map lists it in B3StylisedText2dObject.cpp.
// Data block layout and callee prototypes as src/nonmatching/_RenderNormal__23CB3StylisedText2dObject*.cpp (same file).
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

class CB3StylisedText2dObject {
public:
    // [C] class name: E map (B3O0PCH CB3StylisedText2dObject::CB3StylisedText2dObjectData::GetWhiteness()); the object's data
    // block at +0x20 (ModifyEffect writes +0x2C / +0x31 through it). Members: placeholders, meanings [L] from the uses.
    struct CB3StylisedText2dObjectData {
        CGt2dFont *field_0;              // [C] the font: its +4 texture goes to SetTexture; _BuildBatchData reads its glyphs
        const unsigned short *field_4;   // [C] the string (_BuildBatchData)
        float field_8;                   // [C] horizontal stretch: scales the outline's x offset and the rotation's aspect
        float field_C;                   // [C] rotation angle in radians (SinCosFast); ModifyEffect zeroes it
        unsigned char field_10;          // [C] style, 0..5 (the jump table jtbl_004CA610)
        unsigned char field_11;          // [C] effect (ModifyEffect stores it at +0x31); 1 = rotated [L]
        unsigned char field_12;          // [C] 0..255, scaled by 1/255 for the metallic / gradient blend [L] whiteness
        unsigned char field_13;          // [C] _BuildBatchData: escape codes off
        float field_14;                  // [C] _BuildBatchData: glyph width scale
        // [C] name: E map (B3O0PCH, 92 bytes). [G] body: the 0..1 blend from the byte (retail: unsigned int to float, * 1/255)
        float GetWhiteness() const { return (1.0f / 255.0f) * (float)(unsigned int)field_12; }
    };
    static void _RenderNormal(const CGt2dObject::CGt2dObjectSpace &space, const void *lpData);
    static void _RenderDisintegrate(const CGt2dObject::CGt2dObjectSpace &space, const void *lpData);
};
typedef CB3StylisedText2dObject::CB3StylisedText2dObjectData UnkStruct_003CED40_data;

struct UnkStruct_D_0066A4C0 {               // the HUD colour set [G] (as the C2dObjectBoostBarMessage::_Render archive)
    unsigned char pad_0[0x50];
    CGtV4d field_50;                         // [C] style 4's first gradient colour (retail label D_0066A510)
    CGtV4d field_60;                         // [C] style 4's second gradient colour (retail label D_0066A520)
};
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern const CGtV4d D_004CA4E0;             // [C] style 5's gradient colours (rodata)
extern const CGtV4d D_004CA4F0;
extern const CGtV4d D_004CA5C0;             // [C] the colour the whiteness blends towards (rodata)

// [L] DNAT _BuildBatchData(const CGtV2d&, const CB3StylisedText2dObjectData&): fills mgu8RenderBatchData, returns the count
extern "C" int func_003CDB80(const CGtV2d &scale, const UnkStruct_003CED40_data &d);
// [L] DNAT _DispatchLRGradient(CGtV4d, CGtV4d, CGtV4d, const CGtV2d&, ...) (src/nonmatching/func_003CE0A0.cpp)
extern "C" void func_003CE0A0(CGtV4d c0, CGtV4d c1, CGtV4d c2, const CGtV2d &pos, const CGtV2d *pts, const CGtV2d *uvs, int n,
                              const CGtV2d &a, const CGtV2d &b, float t);
// [L] DNAT _DispatchMetallic(CGtV4d, const CGtV2d&, const CGtV2d*, const CGtV2d*, ...); the tail from retail's registers [G]
extern "C" void func_003CE290(CGtV4d, const CGtV2d &, const CGtV2d *, const CGtV2d *, int, const CGtV2d &, const CGtV2d &, int, float);

// 0x003CED40
// What it draws [L]: field_C (the disintegrate T) runs 1 -> 0 (>= 1 falls back to _RenderNormal); each glyph gets a fixed
// random threshold (a CGtRandom seeded per call), and once 1 + R - 2T > 0 it falls (a quadratic drop of up to 2 heights) and
// fades out with its own drop shadow / outline ring; the glyph colour is a left-to-right gradient (style 0: plain, 4/5: the
// gradient pairs) lightened by the whiteness.
void CB3StylisedText2dObject::_RenderDisintegrate(const CGt2dObject::CGt2dObjectSpace &space, const void *lpData)
{
    const UnkStruct_003CED40_data *d = (const UnkStruct_003CED40_data *)lpData;
    CGtV2d *xy = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    float lrHalfRecipWidth = 0.5f / space.mSize.marValues[0];
    int n = func_003CDB80(space.mSize, *d);
    if (n == 0)
        return;
    if (d->field_C < 1.0f) {
        // the gradient ends (styles 1..3 leave them unset: unused), lightened by the whiteness, times the object colour
        CGtV4d c1;
        CGtV4d c2;
        switch (d->field_10) {
        case 0:
            c1 = c2 = D_004CA5C0;
            break;
        case 4:
            c1 = D_0066A4C0.field_50;
            c2 = D_0066A4C0.field_60;
            break;
        case 5:
            c1 = D_004CA4E0;
            c2 = D_004CA4F0;
            break;
        }
        float lrWhiteness = d->GetWhiteness();
        c1 = Interpolate(c1, D_004CA5C0, lrWhiteness) * space.mColour;
        c2 = Interpolate(c2, D_004CA5C0, lrWhiteness) * space.mColour;
        // the outline ring and the drop shadow (as _RenderNormal)
        float w = 0.036f * d->field_8 * space.mSize.marValues[0];
        float h = 0.036f * space.mSize.marValues[1];
        CGtV4d lShadow;
        lShadow.Zero();
        lShadow.SetW(space.mColour.W());
        CGtV4d lHalfShadow = lShadow * 0.5f;
        CGtV2d lShadowOffset = CGtV2d(w, h) * 2.7777779f;
        float sh = d->field_8 * (-0.4f * h) * space.mSize.marValues[0] / space.mSize.marValues[1];
        CGtV2d lA(sh - w, h);
        CGtV2d lB(sh + w, h);
        Gt2dRenderer::SetTexture(d->field_0->field_4);
        CGtRandom lRandom;
        lRandom.mnHigh = 0xF8A432EA;
        lRandom.mnLow = 0x75BCD15;
        do {
            // [L] CGtRandom::RandomReal(): (float)(unsigned)Random() * 2^-32 (as the C2dObjectBoostBar::_Render archive)
            float lrRandom = 2.3283064e-10f * (float)(unsigned int)lRandom.Random();
            float lrGone = GtMath::Min(GtMath::Max(1.0f + lrRandom - 2.0f * d->field_C, 0.0f), 1.0f);
            if (lrGone < 1.0f) {
                float lrU = GtMath::Min(GtMath::Max(lrHalfRecipWidth * (xy[0].marValues[0] + xy[3].marValues[0]), 0.0f), 1.0f);
                CGtV4d lColour = Interpolate(c1, c2, lrU);
                CGtV4d lGlyphHalfShadow = lHalfShadow;
                CGtV4d lGlyphShadow = lShadow;
                CGtV2d lPos = space.mTopLeftPos;
                if (!(lrGone <= 0.0f)) {
                    // falling and fading
                    float lrGone2 = lrGone * lrGone;
                    float lrFade = 1.0f - lrGone2;
                    lPos.marValues[1] = lPos.marValues[1] + (-3.3333333f * lrGone + 5.333333f * lrGone2) * space.mSize.marValues[1];
                    lColour.SetW(lColour.W() * lrFade);
                    lGlyphHalfShadow.SetW(lGlyphHalfShadow.W() * lrFade);
                    lGlyphShadow.SetW(lGlyphShadow.W() * lrFade);
                }
                Gt2dRenderer::RenderTriStripFlatTex(lGlyphHalfShadow, lPos + lShadowOffset, 4, xy, uv);
                Gt2dRenderer::RenderTriStripFlatTex(lGlyphShadow, lPos + lA, 4, xy, uv);
                Gt2dRenderer::RenderTriStripFlatTex(lGlyphShadow, lPos + lB, 4, xy, uv);
                Gt2dRenderer::RenderTriStripFlatTex(lGlyphShadow, lPos - lA, 4, xy, uv);
                Gt2dRenderer::RenderTriStripFlatTex(lGlyphShadow, lPos - lB, 4, xy, uv);
                Gt2dRenderer::RenderTriStripFlatTex(lColour, lPos, 4, xy, uv);
            }
            // the next glyph quad: 4 corners + the 2 strip connectors
            n -= 6;
            xy += 6;
            uv += 6;
        } while (n > 0);
    } else {
        _RenderNormal(space, d);
    }
}
