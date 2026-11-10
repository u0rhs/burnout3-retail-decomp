// NONMATCHING: _RenderDistort__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 717 / ours 734 instructions, 513 in changed runs
// draftAI: logic complete; retail 717 / ours 734; call sequence identical (14); every VU op count identical (header Interpolate x2, Zero/SetW(W()), SetX/Y/Z(float)+SetA, CosFast4, lane X/Y/Z/W * float, X+Y; one Z+W stand-in); both switches are jump tables as retail; left: two retail adda-zero/madd fusions (wave w lane, lens 1+1.5u^2) only reproduced by a 0-initialised accumulator, CGtV2d float-copy temporaries (swc1 +6), frame 0x500 vs 0x3F0. Note: retail's two connector re-copy loops start at the quad loop's final index - 4 = 0 and never run (kept)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm op for op: fade-in of the gradient ends, glyph count from T, lens bulge (r^2 < 2.56), CosFast4 wobble, shadow ring, style switch (0 flat, 4-5 gradient, 1-3 nothing), the 1+T ghost in blend mode 1

// CB3StylisedText2dObject::_RenderDistort(const CGt2dObject::CGt2dObjectSpace&, const void*) -- draftAI (C-first draft).
// [C] name: config/symbol_addrs_b3names.txt 0x3CF300 (DNAT high); the E map lists it in B3StylisedText2dObject.cpp.
// Data block layout and callee prototypes as src/nonmatching/_RenderNormal__23CB3StylisedText2dObject*.cpp (same file).
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
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
    static void _RenderDistort(const CGt2dObject::CGt2dObjectSpace &space, const void *lpData);
};
typedef CB3StylisedText2dObject::CB3StylisedText2dObjectData UnkStruct_003CF300_data;

struct UnkStruct_D_0066A4C0 {               // the HUD colour set [G] (as the C2dObjectBoostBarMessage::_Render archive)
    unsigned char pad_0[0x50];
    CGtV4d field_50;                         // [C] style 4's first gradient colour (retail label D_0066A510)
    CGtV4d field_60;                         // [C] style 4's second gradient colour (retail label D_0066A520)
};
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern const CGtV4d D_004CA4E0;             // [C] style 5's gradient colours (rodata)
extern const CGtV4d D_004CA4F0;
extern const CGtV4d D_004CA5C0;             // [C] the colour the gradient ends fade from as field_C goes 0 -> 1 (rodata)

// [L] DNAT _BuildBatchData(const CGtV2d&, const CB3StylisedText2dObjectData&): fills mgu8RenderBatchData, returns the count
extern "C" int func_003CDB80(const CGtV2d &scale, const UnkStruct_003CF300_data &d);
// [L] DNAT _DispatchLRGradient(CGtV4d, CGtV4d, CGtV4d, const CGtV2d&, ...) (src/nonmatching/func_003CE0A0.cpp)
extern "C" void func_003CE0A0(CGtV4d c0, CGtV4d c1, CGtV4d c2, const CGtV2d &pos, const CGtV2d *pts, const CGtV2d *uvs, int n,
                              const CGtV2d &a, const CGtV2d &b, float t);
// [L] DNAT Gt2dRenderer::SetBlendMode(Gt2dRenderer::EGt2dRendererBlend) (research/proto/new_names.csv, high); 1 here = the
// blend for the expanding ghost copy [G], 0 = back to normal
extern "C" void func_00217E70(int mode);
// [L] DNAT _DispatchMetallic(CGtV4d, const CGtV2d&, const CGtV2d*, const CGtV2d*, ...); the tail from retail's registers [G]
extern "C" void func_003CE290(CGtV4d, const CGtV2d &, const CGtV2d *, const CGtV2d *, int, const CGtV2d &, const CGtV2d &, int, float);

// 0x003CF300
// What it draws [L]: field_C (the distort T, 0..1; >= 1 falls back to _RenderNormal) drives a wave over the first m glyphs
// (m grows with T): each vertex is pushed out of a lens around a centre that sweeps right with T, then wobbled by a CosFast4 of
// its scaled position, with the amplitude fading as T -> 0.8. The shadow ring and the text are drawn as in _RenderNormal (no
// metallic style here), then the same strip scaled up about its centre by 1 + T and redrawn with alpha 1 - T in blend mode 1.
void CB3StylisedText2dObject::_RenderDistort(const CGt2dObject::CGt2dObjectSpace &space, const void *lpData)
{
    const UnkStruct_003CF300_data *d = (const UnkStruct_003CF300_data *)lpData;
    CGtV2d *xy = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    int n = func_003CDB80(space.mSize, *d);
    if (n == 0)
        return;
    if (d->field_C < 1.0f) {
        // the gradient colours fade in from D_004CA5C0 (styles 1..3 leave them unset: unused)
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
        float t = d->field_C;
        c1 = Interpolate(D_004CA5C0, c1, t);
        c2 = Interpolate(D_004CA5C0, c2, t);
        // the outline ring and the drop shadow (as _RenderNormal)
        float h = 0.036f * space.mSize.marValues[1];
        float w = 0.036f * d->field_8 * space.mSize.marValues[0];
        CGtV4d lShadow;
        lShadow.Zero();
        lShadow.SetW(space.mColour.W());
        CGtV4d lHalfShadow = lShadow * 0.5f;
        CGtV2d lShadowOffset = CGtV2d(w, h) * 2.7777779f;
        float sh = d->field_8 * (-0.4f * h) * space.mSize.marValues[0] / space.mSize.marValues[1];
        CGtV2d lB(sh + w, h);
        CGtV2d lA(sh - w, h);
        // how many glyphs the wave has reached: n = 6 * glyphs - 2 vertices
        float s = GtMath::Min(1.0f, 1.5f * t);
        int m = (int)(s * (float)((n + 2) / 6) + 0.9f);
        if (m <= 0)
            return;
        int nn = m * 6 - 2;
        CGtV2d lCentre(1.5f * t * space.mSize.marValues[0], 0.5f * space.mSize.marValues[1]);
        float amp = GtMath::Max(0.8f - t, 0.0f);
        CGtV2d lRecip(1.0f / space.mSize.marValues[0], 1.0f / space.mSize.marValues[1]);
        CGtV2d lInv(lRecip.marValues[0] / d->field_8, lRecip.marValues[1]);
        CGtV2d lScale(d->field_8 * space.mSize.marValues[0], space.mSize.marValues[1]);
        float tt = t * t;
        float q = t + t - tt;
        CGtV2d lAmp = lScale * amp;
        CGtV4d lWave;
        CGtV2d *p = xy;
        int j;
        for (int k = nn; k > 0; k -= 6) {
            // the four corners of one glyph quad (the two connector vertices after it are skipped)
            for (j = 0; j < 4; j++) {
                CGtV2d lD = *p - lCentre;
                lD.marValues[1] *= lInv.marValues[1];
                lD.marValues[0] *= lInv.marValues[0];
                float r2 = lD.marValues[0] * lD.marValues[0] + lD.marValues[1] * lD.marValues[1];
                if (r2 < 2.56f) {
                    // inside the lens: pushed out by up to 1.5x
                    float u = 1.0f - (1.0f / 2.56f) * r2;
                    u = u * u;
                    CGtV2d lE = lScale * (1.0f + 1.5f * u);
                    lD.marValues[0] *= lE.marValues[0];
                    lD.marValues[1] *= lE.marValues[1];
                    *p = lCentre + lD;
                }
                CGtV2d lP = *p * lInv;
                lWave.SetX(1.5f * lP.marValues[0] + 23.0f * q);
                lWave.SetY(4.0f * lP.marValues[1] + 9.0f * t);
                lWave.SetZ(2.5f * lP.marValues[0] + 7.0f * t);
                lWave.SetA(lP.marValues[1] + 19.0f * q);
                lWave = CosFast4(lWave);
                float dy = (lWave.Z() * 0.5f + lWave.W() * 0.5f);
                float dx = lWave.X() * 0.5f + lWave.Y() * 0.5f;
                CGtV2d lOff(dx * lAmp.marValues[0], dy * lAmp.marValues[1]);
                *p += lOff;
                p++;
            }
            p += 2;
        }
        // [C] re-copy the connector vertices from their moved neighbours; retail starts this loop at the quad loop's last
        // corner index minus 4 (= 0), so it never runs: kept as retail has it
        for (int i = j - 4; i > 0; i -= 6) {
            xy[i - 1] = xy[i];
            xy[i - 2] = xy[i - 3];
        }
        Gt2dRenderer::SetTexture(d->field_0->field_4);
        Gt2dRenderer::RenderTriStripFlatTex(lHalfShadow, space.mTopLeftPos + lShadowOffset, nn, xy, uv);
        Gt2dRenderer::RenderTriStripFlatTex(lShadow, space.mTopLeftPos + lB, nn, xy, uv);
        Gt2dRenderer::RenderTriStripFlatTex(lShadow, space.mTopLeftPos + lA, nn, xy, uv);
        Gt2dRenderer::RenderTriStripFlatTex(lShadow, space.mTopLeftPos - lB, nn, xy, uv);
        Gt2dRenderer::RenderTriStripFlatTex(lShadow, space.mTopLeftPos - lA, nn, xy, uv);
        switch (d->field_10) {
        case 0:
            Gt2dRenderer::RenderTriStripFlatTex(space.mColour, space.mTopLeftPos, nn, xy, uv);
            break;
        case 1:
        case 2:
        case 3:
            break;
        case 4:
        case 5:
            func_003CE0A0(space.mColour, c1, c2, space.mTopLeftPos, xy, uv, nn, CGtV2d(space.mSize.marValues[0], 0.0f),
                          CGtV2d(0.0f, space.mSize.marValues[1]), d->GetWhiteness());
            break;
        }
        // the ghost: the strip scaled by 1 + T about the reached text's centre
        CGtV2d lSize = space.mSize * s;
        float g = 1.0f + d->field_C;
        CGtV2d lHalfSize = lSize * 0.5f;
        CGtV2d lGrow = lHalfSize * (1.0f - g);
        p = xy;
        for (int k = nn; k > 0; k -= 6) {
            for (j = 0; j < 4; j++) {
                *p = lGrow + *p * g;
                p++;
            }
            p += 2;
        }
        for (int i = j - 4; i > 0; i -= 6) {
            xy[i - 1] = xy[i];
            xy[i - 2] = xy[i - 3];
        }
        CGtV4d lFade = space.mColour;
        lFade.SetA(1.0f - d->field_C);
        func_00217E70(1);
        switch (d->field_10) {
        case 0:
            Gt2dRenderer::RenderTriStripFlatTex(lFade, space.mTopLeftPos, nn, xy, uv);
            break;
        case 1:
        case 2:
        case 3:
            break;
        case 4:
        case 5:
            func_003CE0A0(lFade, c1, c2, space.mTopLeftPos, xy, uv, nn, CGtV2d(space.mSize.marValues[0], 0.0f),
                          CGtV2d(0.0f, space.mSize.marValues[1]), d->GetWhiteness());
            break;
        }
        func_00217E70(0);
    } else {
        _RenderNormal(space, d);
    }
}
