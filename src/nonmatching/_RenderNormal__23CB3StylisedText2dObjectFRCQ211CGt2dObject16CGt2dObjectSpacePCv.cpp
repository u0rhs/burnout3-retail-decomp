// NONMATCHING: _RenderNormal__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 531 / ours 538 instructions, 500 in changed runs
// draftAI: logic complete; retail 531 / ours 538; call sequence identical (10); every VU op count identical (header Zero/SetW(W())/operator*(float)/SinCosFast/X()*k, GtMath::IsEffectivelyZero); _DispatchMetallic (func_003CE290) gets the style in t3 as retail (it reads it: draftAI's func_003CE290 decode; supersedes the 537 archive, which dropped that argument); left: CGtV2d float-copy temporaries (swc1/ld/sd +2), one lq/sq colour copy, an andi on the style byte, frame 0x350 vs 0x320
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm op for op: shadow/outline offsets, the aspect-corrected rotation about the centre, the 5 shadow strips and the 6-way style switch (jtbl_004CA610: 0 flat, 1-3 metallic with the style passed on, 4-5 gradient) all accounted for

// CB3StylisedText2dObject::_RenderNormal(const CGt2dObject::CGt2dObjectSpace&, const void*) -- draftAI (C-first draft).
// [C] name: config/symbol_addrs_b3names.txt 0x3CFE40 (DNAT high); the E map lists it in B3StylisedText2dObject.cpp.
// What it draws [L]: the glyph strip from _BuildBatchData (func_003CDB80), optionally rotated by data->field_C about the
// object's centre (field_11 == 1, the aspect-corrected 2x2 rotation applied to every vertex), a half-alpha drop shadow
// and a black outline ring (offsets +-A, +-B: the slant-sheared outline), then the text itself in one of six styles
// (field_10: 0 flat, 1..3 _DispatchMetallic, 4..5 _DispatchLRGradient with style 4's HUD colours or the two constant ones).
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
};
typedef CB3StylisedText2dObject::CB3StylisedText2dObjectData UnkStruct_003CFE40_data;

struct UnkStruct_D_0066A4C0 {               // the HUD colour set [G] (as the C2dObjectBoostBarMessage::_Render archive)
    unsigned char pad_0[0x50];
    CGtV4d field_50;                         // [C] style 4's first gradient colour (retail label D_0066A510)
    CGtV4d field_60;                         // [C] style 4's second gradient colour (retail label D_0066A520)
};
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern const CGtV4d D_004CA4E0;             // [C] style 5's gradient colours (rodata)
extern const CGtV4d D_004CA4F0;

// [L] DNAT _BuildBatchData(const CGtV2d&, const CB3StylisedText2dObjectData&): fills mgu8RenderBatchData, returns the count
extern "C" int func_003CDB80(const CGtV2d &scale, const UnkStruct_003CFE40_data &d);
// [L] DNAT _DispatchLRGradient(CGtV4d, CGtV4d, CGtV4d, const CGtV2d&, ...) (src/nonmatching/func_003CE0A0.cpp)
extern "C" void func_003CE0A0(CGtV4d c0, CGtV4d c1, CGtV4d c2, const CGtV2d &pos, const CGtV2d *pts, const CGtV2d *uvs, int n,
                              const CGtV2d &a, const CGtV2d &b, float t);
// [L] DNAT _DispatchMetallic(CGtV4d, const CGtV2d&, const CGtV2d*, const CGtV2d*, ...) (the map's signature is truncated); the
// tail from retail's registers: the style (1..3, picks the metal) arrives in t3, still holding field_10 from the switch [C]
extern "C" void func_003CE290(CGtV4d c, const CGtV2d &pos, const CGtV2d *pts, const CGtV2d *uvs, int n,
                              const CGtV2d &a, const CGtV2d &b, int style, float t);

// 0x003CFE40
void CB3StylisedText2dObject::_RenderNormal(const CGt2dObject::CGt2dObjectSpace &space, const void *lpData)
{
    const UnkStruct_003CFE40_data *d = (const UnkStruct_003CFE40_data *)lpData;
    CGtV2d *xy = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    int n = func_003CDB80(space.mSize, *d);
    if (n == 0)
        return;
    // the outline ring and the drop shadow: offsets from the object's height, x sheared by the slant
    float h = 0.036f * space.mSize.marValues[1];
    float w = 0.036f * d->field_8 * space.mSize.marValues[0];
    CGtV4d lShadow;
    lShadow.Zero();
    lShadow.SetW(space.mColour.W());
    CGtV4d lHalfShadow = lShadow * 0.5f;
    float sh = d->field_8 * (-0.4f * h) * space.mSize.marValues[0] / space.mSize.marValues[1];
    CGtV2d lB(sh + w, h);
    CGtV2d lA(sh - w, h);
    CGtV2d lShadowOffset = CGtV2d(w, h) * 2.7777779f;
    CGtV2d lPos;
    CGtV2d lXAxis;
    CGtV2d lYAxis;
    if (d->field_11 == 1 && !GtMath::IsEffectivelyZero(d->field_C)) {
        // rotated by field_C about the centre; x is stretched by field_8, so the rotation is aspect-corrected
        CGtV4d lSinCos = SinCosFast(d->field_C);
        float k = d->field_8 * space.mSize.marValues[0] / space.mSize.marValues[1];
        CGtV2d lRight(lSinCos.Y(), (float)lSinCos.X() / -k);
        CGtV2d lDown((float)(lSinCos.X() * k), lSinCos.Y());
        CGtV2d *p = xy;
        for (int i = 0; i < n; i++) {
            *p = lRight * p->marValues[0] + lDown * p->marValues[1];
            p++;
        }
        CGtV2d lHalf = space.mSize * 0.5f;
        lXAxis = lRight * space.mSize.marValues[0];
        lYAxis = lDown * space.mSize.marValues[1];
        CGtV2d lCentre = space.mTopLeftPos + lHalf;
        lPos = lCentre - (lRight * lHalf.marValues[0] + lDown * lHalf.marValues[1]);
        lA = lRight * lA.marValues[0] + lDown * lA.marValues[1];
        lB = lRight * lB.marValues[0] + lDown * lB.marValues[1];
    } else {
        lPos = space.mTopLeftPos;
        lXAxis = CGtV2d(space.mSize.marValues[0], 0.0f);
        lYAxis = CGtV2d(0.0f, space.mSize.marValues[1]);
    }
    Gt2dRenderer::SetTexture(d->field_0->field_4);
    Gt2dRenderer::RenderTriStripFlatTex(lHalfShadow, lPos + lShadowOffset, n, xy, uv);
    Gt2dRenderer::RenderTriStripFlatTex(lShadow, lPos + lB, n, xy, uv);
    Gt2dRenderer::RenderTriStripFlatTex(lShadow, lPos + lA, n, xy, uv);
    Gt2dRenderer::RenderTriStripFlatTex(lShadow, lPos - lB, n, xy, uv);
    Gt2dRenderer::RenderTriStripFlatTex(lShadow, lPos - lA, n, xy, uv);
    switch (d->field_10) {
    case 0:
        Gt2dRenderer::RenderTriStripFlatTex(space.mColour, lPos, n, xy, uv);
        break;
    case 1:
    case 2:
    case 3:
        func_003CE290(space.mColour, lPos, xy, uv, n, lXAxis, lYAxis, d->field_10, d->GetWhiteness());
        break;
    case 4:
    case 5: {
        CGtV4d c1;
        CGtV4d c2;
        if (d->field_10 == 4) {
            c1 = D_0066A4C0.field_50;
            c2 = D_0066A4C0.field_60;
        } else {
            c1 = D_004CA4E0;
            c2 = D_004CA4F0;
        }
        func_003CE0A0(space.mColour, c1, c2, lPos, xy, uv, n, lXAxis, lYAxis, d->GetWhiteness());
        break;
    }
    }
}
