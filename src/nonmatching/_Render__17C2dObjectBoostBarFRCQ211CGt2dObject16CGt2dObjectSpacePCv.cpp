// NONMATCHING: _Render__17C2dObjectBoostBarFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 1564 / ours 1675 instructions, 1577 in changed runs
// draftAI: logic complete; retail 1564 / ours 1675; call multiset identical (24; order differs only by retail's out-of-line placement of the fly-out sprite and blue-flame blocks); every VU op count identical except one -Z() (header ZAxisType::operator- is a -1.0 multiply, retail vsub.z: queued); header SinCosFast2, Interpolate x6, CGtV4d*CGtV4d, lane * float, SetW(W()), operator*=(float); left: CGtV2d constructor temporaries (swc1 +71, sw +25, ld/sd +11), frame 0xF90 vs 0xD90
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm block by block (18 loops): multiplier styles 0/1/2 (seeded CGtRandom shatter: 10 or 5 columns x 3 pieces x 2 triangles, random order A,B spin then (y,x) velocity per half), background, two particle sets, blue flame, heat haze, fire core, fire edge, fire over

// C2dObjectBoostBar::_Render(const CGt2dObject::CGt2dObjectSpace&, const void*) -- draftAI (C-first draft).
// [C] name: retail symbol table. Written from the retail asm (0x1A6290, 1564 instructions). Local names after Revenge's own
// _Render (STABS, B4HUDBoostBar.cpp: lpObjectData, lnMultiplier, lbCompact, lrShatterTime, lrTimeStep, lnXCount, lrUStep,
// lrULeft, lrXStep, lrYStep, lrAngularVelA/B, lRandom, lDown, lRight, lVelocityScale, lVelocity, lParticleCentre, lCentrePos,
// laUVs/laXYs[18], lrHalfAcceleration, lrHeatOffset, lnNumVerts, lnCount, lrRatio, lrRatioScale, lrU, laLower/laUpper XYs/UVs/
// RGBAs[20], lrFrequency, lrElementStep, lrRecipElementWidth, lrElementWidth, lOffset, laRGBAs, lrYEndScale, lrYBottom,
// lrYMiddle, lrYTop, lrElementX, lrUpperXScale, lrMidXScale, lrXFade, lrUScale, lrX0, lrX1, lrY1, lnAnimFrame, lTemp) [L]; the
// Revenge body differs (a separate _RenderBackground with more parameters, no blue flame), so the mapping is by role [G].
// What it draws [L]: the multiplier digits (style field_51A: 1 = shatter into falling, spinning triangles after field_514 > 0,
// or a blinking "+1" before; 2 = a sprite flying out), the background (func_001A8180), the two particle sets, the blue
// flame (field_50C), then the boost flames: a two-strip heat haze, the fire-core sprites, the fire edge strips and the
// fire-over strip, all in blend mode 1.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

class CGtTexture;
// gapN: the Gt2dRenderer declarations now come from Gt2dObject.h
class CB3HUDComponent {
public:
    static CGtTexture *mpBoostBitsTexture;              // [C] mangled names; array sizes [G] (the frame modulus)
    static CGtTexture *mpBoostBlueFlameTexture;
    static CGtTexture *mapBoostFireCoreTextures[30];
    static CGtTexture *mapBoostFireEdgeTextures[41];
    static CGtTexture *mapBoostFireOverTextures[20];
};
struct B3HUDParticleParamsTag;                          // [C] name: _RenderParticles' mangled parameter
extern const B3HUDParticleParamsTag D_004B7860;          // [C] the boost particles' parameters (field_0's set)
extern const B3HUDParticleParamsTag D_004B78B0;          // [C] the shatter particles' parameters (field_280's set)
extern const CGtV4d D_004B7800;                         // [C] shatter colour (times the object colour)
extern const CGtV4d D_004B7810;                         // [C] heat-haze colour, one end
extern const CGtV4d D_004B7820;                         // [C] heat-haze colour, other end (unlabelled, 0x10 after D_004B7810)
extern const CGtV4d D_004B7830;                         // [C] blue-flame colour
extern const CGtV4d D_004B7840;                         // [C] fire-core colour
extern const CGtV4d D_004B7850;                         // [C] fire-over colour
struct UnkStruct_D_004B7950 { float field_0[6]; };      // [C] per heat-haze column: three heights (x size.y), three blends
extern const UnkStruct_D_004B7950 D_004B7950[];
extern char D_004EE040[];
extern "C" int func_00131E40(void *);                   // CB3Game::IsCrashMode() [E map, high] (as BarUpdate's archive)
// [L] DNAT Gt2dRenderer::SetBlendMode(Gt2dRenderer::EGt2dRendererBlend) (research/proto/new_names.csv, high)
extern "C" void func_00217E70(int mode);
// [L] the background and multiplier digits (Revenge's _RenderBackground(lObjectSpace, lrWidth, lnMultiplier,
// lrMultiplierFlashIntensity, ...) by role); retail passes only these four (a0, a1, f12, f13)
extern "C" void func_001A8180(const CGt2dObject::CGt2dObjectSpace &space, int lnMultiplier, float lrWidth, float lrFlash);

class CB3HUDBoostBar {
public:
    // [L] name: _RenderParticles' mangled parameter types (CB3HUDBoostBar::CBoostBarObjectData::CParticle). Layout from this
    // function's reads [C] offsets; meanings [L].
    struct CBoostBarObjectData {
        struct CParticle { unsigned char pad_0[0x20]; };
        CParticle field_0[20];          // [C] the boost particles (_RenderParticles with D_004B7860)
        CParticle field_280[20];        // [C] the shatter particles (_RenderParticles with D_004B78B0)
        float field_500;                // [C] the boost particles' clock; also the flame animation clock
        float field_504;                // [C] the background bar width (func_001A8180)
        float field_508;                // [C] the flame width; 0 in crash mode hides everything
        float field_50C;                // [C] the blue flame intensity
        float field_510;                // [C] the fire edge's spread
        float field_514;                // [C] the multiplier animation clock (also the shatter particles' clock)
        unsigned char field_518;        // [C] the multiplier
        unsigned char field_519;        // [C] a random byte for the blue flame flicker
        unsigned char field_51A;        // [C] the multiplier animation (0 none, 1 shatter, 2 fly-out)
        bool field_51B;                 // [C] compact (half-size) bar (lbu, tested and passed on as is: bool)
    };
};
class C2dObjectBoostBar {
public:
    struct C2dObjectBoostBarData { CB3HUDBoostBar::CBoostBarObjectData *field_0; };   // [C] the data block's one word
    static void _RenderParticles(const B3HUDParticleParamsTag *, const CGt2dObject::CGt2dObjectSpace &,
                                 const CB3HUDBoostBar::CBoostBarObjectData::CParticle *, int, float);
    static void _Render(const CGt2dObject::CGt2dObjectSpace &lObjectSpace, const void *lpData);
};
// [C] retail passes lbCompact in t0 after the mangled name's float (Revenge's _RenderParticles has a trailing bool): called
// through its link name with the real list
extern "C" void _RenderParticles__17C2dObjectBoostBarFPC22B3HUDParticleParamsTagRCQ211CGt2dObject16CGt2dObjectSpacePCQ314CB3HUDBoostBar19CBoostBarObjectData9CParticleif(
    const B3HUDParticleParamsTag *, const CGt2dObject::CGt2dObjectSpace &, const CB3HUDBoostBar::CBoostBarObjectData::CParticle *, void *,
    float, bool);


// 0x001A6290
void C2dObjectBoostBar::_Render(const CGt2dObject::CGt2dObjectSpace &lObjectSpace, const void *lpData)
{
    float lrFlash = 0.0f;
    CB3HUDBoostBar::CBoostBarObjectData *lpObjectData = ((const C2dObjectBoostBarData *)lpData)->field_0;
    bool lbCompact = lpObjectData->field_51B;
    float lrSegmentWidth = 0.25f;
    if (func_00131E40(D_004EE040) != 0 && lpObjectData->field_508 == 0.0f)
        return;
    int lnMultiplier = lpObjectData->field_518;
    float lrFlameWidth = lpObjectData->field_508;
    float lrBackgroundWidth = lpObjectData->field_504;
    if (lbCompact) {
        lrBackgroundWidth *= 0.5f;
        lrFlameWidth *= 0.5f;
        lrSegmentWidth *= 0.5f;
    }
    Gt2dRenderer::SetTexture(CB3HUDComponent::mpBoostBitsTexture);
    Gt2dRenderer::SetTextureAddressMode((Gt2dRenderer::EGt2dRendererTexAddress)1);
    switch (lpObjectData->field_51A) {
    case 2: {
        // the last segment flies out to the right, then the multiplier flashes
        float t = lpObjectData->field_514;
        if (t < 0.3f) {
            CGtV2d laUVs[2];
            CGtV2d laXYs[2];
            laUVs[0] = CGtV2d(0.0f, 0.130859375f);
            laUVs[1] = CGtV2d(6.0f * lrSegmentWidth, 0.244140625f);
            lnMultiplier--;
            lrBackgroundWidth -= lrSegmentWidth;
            float x = (lrBackgroundWidth + 4.444444f * (0.3f - t)) * lObjectSpace.mSize.marValues[0];
            laXYs[0] = CGtV2d(x, 0.0f);
            laXYs[1] = CGtV2d(x + lrSegmentWidth * lObjectSpace.mSize.marValues[0], lObjectSpace.mSize.marValues[1]);
            Gt2dRenderer::RenderSpritesTex(lObjectSpace.mColour, lObjectSpace.mTopLeftPos, 1, laXYs, laUVs);
        } else if (t < 0.63f) {
            lrFlash = (0.63f - t) * 3.030303f;
        }
        break;
    }
    case 1: {
        float lrShatterTime = lpObjectData->field_514;
        if (lrShatterTime < 2.2f) {
            float lrX = 0.0f;
            if (lrShatterTime <= 0.0f) {
                // before the shatter: the next segment and multiplier blink
                lnMultiplier++;
                lrBackgroundWidth += lrSegmentWidth;
                if ((int)(-16.0f * lrShatterTime) & 1)
                    lnMultiplier = 0;
            } else {
                // the segments shatter: lnXCount columns of three pieces, each split into two triangles that fly apart
                CGtV4d lZero;
                lZero.Zero();
                CGtRandom lRandom;
                lRandom.mnLow = 0x2B9D6F8;
                lRandom.mnHigh = 0xFD462907;
                float lrTimeStep = 0.02f;
                float lrYStep = 0.33333334f * lObjectSpace.mSize.marValues[1];
                float lrPieceWidth = 0.25f * lObjectSpace.mSize.marValues[0];
                int lnXCount = 10;
                CGtV4d lColour = D_004B7800 * lObjectSpace.mColour;
                float lrXStep = 0.1f * lrPieceWidth;
                float lrUStep = 0.15f;
                float lrVStep = 0.03776042f;
                if (lbCompact) {
                    lnXCount /= 2;
                    lrPieceWidth *= 0.5f;
                    lrUStep += 0.15f;
                    lrTimeStep += 0.02f;
                }
                float lrULeft = 6.0f * lrBackgroundWidth + lrUStep * (float)lnXCount;
                CGtV2d lCentrePos(lrPieceWidth + (lObjectSpace.mTopLeftPos.marValues[0] + lrBackgroundWidth * lObjectSpace.mSize.marValues[0]),
                                  lObjectSpace.mTopLeftPos.marValues[1]);
                float lrHalfAcceleration = 3.2142856f * lObjectSpace.mSize.marValues[1];
                CGtV2d laUVs[18];
                CGtV2d laXYs[18];
                for (int lnX = 0; lnX < lnXCount; lnX++) {
                    float lrU = lrULeft - lrUStep;
                    if (lrShatterTime <= 2.0f) {
                        if (lrShatterTime < 0.0f)
                            lrShatterTime = 0.0f;
                        CGtV2d lCentre(lrX - 0.5f * lrXStep, lrHalfAcceleration * (lrShatterTime * lrShatterTime) + 0.5f * lrYStep);
                        CGtV2d lVelocityScale = lObjectSpace.mSize * lrShatterTime;
                        float lrScale = 1.0f + 0.5f * lrShatterTime;
                        float lrV = 0.130859375f;
                        float w = lrXStep;
                        float h = lrYStep;
                        float ws = lrXStep * lrScale;
                        float hs = lrYStep * lrScale;
                        CGtV2d *xy = laXYs;
                        CGtV2d *uv = laUVs;
                        for (int lnY = 0; lnY < 3; lnY++) {
                            // [C] random order: the two spin rates, then (y, x) of each half's velocity
                            float lrAngularVelA = 75.398224f * (lRandom.RandomReal() - 0.5f) * lrShatterTime;
                            float lrAngularVelB = 75.398224f * (lRandom.RandomReal() - 0.5f) * lrShatterTime;
                            CGtV4d lSinCos = SinCosFast2(lrAngularVelA, lrAngularVelB);
                            float vy = -4.571429f + 4.75f * lRandom.RandomReal();
                            float vx = 0.35555556f * lRandom.RandomReal();
                            CGtV2d lVelocity(vx, vy);
                            // the first half (the top-left corner, spun by A)
                            CGtV2d lRight((float)(lSinCos.Y() * w), (float)(lSinCos.X() * h));
                            CGtV2d lDown((float)(-lSinCos.X() * w), (float)(lSinCos.Y() * h));
                            CGtV2d lParticleCentre = lCentre + lVelocity * lVelocityScale;
                            xy[0] = lParticleCentre - (lRight + lDown) * 0.5f;
                            xy[1] = xy[0] + lRight;
                            xy[2] = xy[1] + lDown;
                            uv[0] = CGtV2d(lrU, lrV);
                            uv[1] = CGtV2d(lrULeft, lrV);
                            lrV += lrVStep;
                            uv[2] = CGtV2d(lrULeft, lrV);
                            uv[3] = uv[2];
                            uv[4] = CGtV2d(lrU, lrV);
                            uv[5] = uv[0];
                            // the second half (the bottom-right corner, spun by B and growing)
                            vy = -4.571429f + 4.75f * lRandom.RandomReal();
                            vx = 0.35555556f * lRandom.RandomReal();
                            lVelocity = CGtV2d(vx, vy);
                            lRight = CGtV2d((float)(lSinCos.W() * ws), (float)(lSinCos.Z() * hs));
                            lDown = CGtV2d((float)(-lSinCos.Z() * ws), (float)(lSinCos.W() * hs));
                            lParticleCentre = lCentre + lVelocity * lVelocityScale;
                            lCentre.marValues[1] += lrYStep;
                            xy[3] = lParticleCentre + (lRight + lDown) * 0.5f;
                            xy[4] = xy[3] - lRight;
                            xy[5] = xy[4] - lDown;
                            xy += 6;
                            uv += 6;
                        }
                        // fade to zero over the first half second, alpha over two seconds
                        CGtV4d lC;
                        if (2.0f * lrShatterTime < 1.0f)
                            lC = Interpolate(lColour, lZero, 2.0f * lrShatterTime);
                        else
                            lC = lZero;
                        lC.SetW(lColour.W() * (1.0f - 0.25f * (lrShatterTime * lrShatterTime)));
                        Gt2dRenderer::RenderTriListFlatTex(lC, lCentrePos, 6, laXYs, laUVs);
                    }
                    lrX -= lrXStep;
                    lrULeft = lrU;
                    lrShatterTime -= lrTimeStep;
                }
                _RenderParticles__17C2dObjectBoostBarFPC22B3HUDParticleParamsTagRCQ211CGt2dObject16CGt2dObjectSpacePCQ314CB3HUDBoostBar19CBoostBarObjectData9CParticleif(
                    &D_004B78B0, lObjectSpace, lpObjectData->field_280, (void *)(20), lpObjectData->field_514, lbCompact);
            }
        }
        break;
    }
    case 0:
        break;
    }
    func_001A8180(lObjectSpace, lnMultiplier, lrBackgroundWidth, lrFlash);
    Gt2dRenderer::SetTextureAddressMode((Gt2dRenderer::EGt2dRendererTexAddress)0);
    func_00217E70(1);
    _RenderParticles__17C2dObjectBoostBarFPC22B3HUDParticleParamsTagRCQ211CGt2dObject16CGt2dObjectSpacePCQ314CB3HUDBoostBar19CBoostBarObjectData9CParticleif(
        &D_004B7860, lObjectSpace, lpObjectData->field_0, (void *)(20), lpObjectData->field_500, lbCompact);
    if (!(lpObjectData->field_50C <= 0.0f)) {
        // the blue flame: flickers with the random byte (and its nibble swap)
        float lrBlueIntensity = lpObjectData->field_50C;
        int lnRandom = lpObjectData->field_519;
        float lrRandomA = 0.94f + 0.06f * ((1.0f / 255.0f) * (float)lnRandom);
        int lnSwapped = (lnRandom >> 4) | (lnRandom << 4);
        float lrRandomB = 0.94f + 0.06f * ((1.0f / 255.0f) * (float)lnSwapped);
        float lrBlueWidth = (0.5f + 0.5f * lrBlueIntensity) * lrRandomA;
        CGtV4d lColour = D_004B7830 * lObjectSpace.mColour;
        CGtV4d lTemp;
        lTemp.SetW(lColour.W());
        lColour *= lrBlueIntensity * lrRandomB;
        lColour.SetW(lTemp.W());
        CGtV2d laXYs[2];
        CGtV2d laUVs[2];
        laUVs[0] = CGtV2d(0.0f, 0.0f);
        laXYs[0] = CGtV2d(-0.011111111f * lObjectSpace.mSize.marValues[0], -0.42857143f * lObjectSpace.mSize.marValues[1]);
        laXYs[1] = CGtV2d((-0.011111111f + 0.23111111f * lrBlueWidth) * lObjectSpace.mSize.marValues[0],
                          1.4285715f * lObjectSpace.mSize.marValues[1]);
        laUVs[1] = CGtV2d(1.0f, 1.0f);
        Gt2dRenderer::SetTexture(CB3HUDComponent::mpBoostBlueFlameTexture);
        Gt2dRenderer::RenderSpritesTex(lColour, lObjectSpace.mTopLeftPos, 1, laXYs, laUVs);
    }
    if (!(lrFlameWidth <= 0.0f)) {
        if (lrFlameWidth < lrSegmentWidth)
            lrFlameWidth = 0.875f * lrFlameWidth + 0.125f * lrSegmentWidth;
        // the heat haze: two gouraud strips (lower, upper), columns from D_004B7950 shimmering with the clock
        {
            CGtV4d laLowerRGBAs[20];
            CGtV2d laLowerUVs[20];
            CGtV2d laLowerXYs[20];
            CGtV4d laUpperRGBAs[20];
            CGtV2d laUpperUVs[20];
            CGtV2d laUpperXYs[20];
            CGtV4d lColourA = D_004B7810 * lObjectSpace.mColour;
            CGtV4d lColourB = D_004B7820 * lObjectSpace.mColour;
            float lrRatioScale = 0.11111111f / lrFlameWidth;
            float lrX = -0.0055555557f * lObjectSpace.mSize.marValues[0];
            float lrXStep = 0.11234567f * lObjectSpace.mSize.marValues[0];
            float lrHeatOffset = 1.8f * lpObjectData->field_500;
            float lrHeight = lObjectSpace.mSize.marValues[1];
            int lnNumVerts = 0;
            int lnCount = 0;
            float lrRatio;
            do {
                float lrCount = (float)lnCount;
                lrRatio = lrRatioScale * lrCount;
                float lrPhase = 0.25f * lrCount + lrHeatOffset;
                float lrTri = lrPhase - (float)(int)lrPhase;
                float lrU = 0.75f + 0.2421875f * lrRatio;
                lrTri = lrTri + lrTri;
                const float *lpCol = D_004B7950[lnCount].field_0;
                float lrY0 = lrHeight * lpCol[0];
                float lrY1 = lrHeight * lpCol[1];
                float lrY2 = lrHeight * lpCol[2];
                if (!(lrTri <= 1.0f))
                    lrTri = 2.0f - lrTri;
                float lrShimmer = lrTri * 0.4f;
                CGtV4d c0 = Interpolate(lColourA, lColourB, lrShimmer + 0.6f * lpCol[3]);
                CGtV4d c1 = Interpolate(lColourA, lColourB, lrShimmer + 0.6f * lpCol[4]);
                CGtV4d c2 = Interpolate(lColourA, lColourB, lrShimmer + 0.6f * lpCol[5]);
                lnCount++;
                laLowerRGBAs[lnNumVerts] = c0;
                laLowerXYs[lnNumVerts] = CGtV2d(lrX, lrY0);
                laUpperRGBAs[lnNumVerts] = c1;
                laLowerUVs[lnNumVerts] = CGtV2d(lrU, 0.001953125f);
                laUpperUVs[lnNumVerts] = CGtV2d(lrU, 0.0625f);
                laUpperXYs[lnNumVerts] = CGtV2d(lrX, lrY1);
                laLowerRGBAs[lnNumVerts + 1] = c1;
                laLowerXYs[lnNumVerts + 1] = CGtV2d(lrX, lrY1);
                laUpperRGBAs[lnNumVerts + 1] = c2;
                laLowerUVs[lnNumVerts + 1] = CGtV2d(lrU, 0.0625f);
                laUpperUVs[lnNumVerts + 1] = CGtV2d(lrU, 0.123046875f);
                laUpperXYs[lnNumVerts + 1] = CGtV2d(lrX, lrY2);
                lnNumVerts += 2;
                lrX += lrXStep;
            } while (lrRatio < 0.999f);
            Gt2dRenderer::SetTexture(CB3HUDComponent::mpBoostBitsTexture);
            Gt2dRenderer::RenderTriStripGouraudTex(lObjectSpace.mTopLeftPos, lnNumVerts, laLowerXYs, laLowerUVs, laLowerRGBAs);
            Gt2dRenderer::RenderTriStripGouraudTex(lObjectSpace.mTopLeftPos, lnNumVerts, laUpperXYs, laUpperUVs, laUpperRGBAs);
        }
        // the fire core: animated sprites stepping left from the flame's end, alternately flipped, each fading in on its left
        {
            float lrElementWidth = 0.17777778f * lObjectSpace.mSize.marValues[0];
            float lrRecipElementWidth = 1.0f / lrElementWidth;
            float lrFrequency = 30.0f;
            float lrCurrentTime = lpObjectData->field_500;
            CGtV4d laRGBAs[4];
            CGtV2d laUVs[4];
            CGtV2d laXYs[4];
            laRGBAs[0] = laRGBAs[1] = D_004B7840 * lObjectSpace.mColour;
            laRGBAs[2] = laRGBAs[3] = laRGBAs[0] * CGtV4d(0.0f, 0.0f, 0.0f, 1.0f);
            float lrXFadeLine = 0.022222223f * lObjectSpace.mSize.marValues[0];
            float lrXRight = (0.022222223f + lrFlameWidth) * lObjectSpace.mSize.marValues[0];
            float lrElementStep = 0.08888889f * lObjectSpace.mSize.marValues[0];
            float lrYBottom = 1.25f * lObjectSpace.mSize.marValues[1];
            float lrYTop = -0.035714287f * lObjectSpace.mSize.marValues[1];
            CGtV2d lOffset(lObjectSpace.mTopLeftPos.marValues[0] - 0.011111111f * lObjectSpace.mSize.marValues[0],
                           lObjectSpace.mTopLeftPos.marValues[1]);
            while (lrXRight > lrXFadeLine) {
                float lrXLeft = lrXRight - lrElementWidth;
                float lrX0;
                float lrULeft;
                if (lrXLeft < lrXFadeLine) {
                    lrX0 = lrXFadeLine;
                    lrULeft = lrRecipElementWidth * (lrXFadeLine - lrXLeft);
                } else {
                    lrX0 = lrXLeft;
                    lrULeft = 0.0f;
                }
                laXYs[0] = CGtV2d(lrX0, lrYTop);
                laXYs[1] = CGtV2d(lrXRight, lrYBottom);
                laUVs[0] = CGtV2d(lrULeft, 0.0f);
                laUVs[1] = CGtV2d(1.0f, 1.0f);
                int lnFrame = (int)(lrCurrentTime * lrFrequency) % 30;
                Gt2dRenderer::SetTexture(CB3HUDComponent::mapBoostFireCoreTextures[lnFrame]);
                Gt2dRenderer::RenderSpritesTex(laRGBAs[0], lOffset, 1, laXYs, laUVs);
                if (!(lrULeft <= 0.015625f)) {
                    // the clipped part, faded out towards the left
                    laXYs[1] = CGtV2d(lrX0, lrYBottom);
                    laUVs[1] = CGtV2d(lrULeft, 1.0f);
                    float lrU2;
                    if (lrXLeft < 0.0f) {
                        lrU2 = -lrXLeft * lrRecipElementWidth;
                        lrXLeft = 0.0f;
                    } else {
                        lrU2 = 0.0f;
                    }
                    laUVs[3] = CGtV2d(lrU2, 1.0f);
                    laUVs[2] = CGtV2d(lrU2, 0.0f);
                    laXYs[2] = CGtV2d(lrXLeft, lrYTop);
                    laXYs[3] = CGtV2d(lrXLeft, lrYBottom);
                    Gt2dRenderer::RenderTriStripGouraudTex(lOffset, 4, laXYs, laUVs, laRGBAs);
                }
                lrXRight -= lrElementStep;
                lrYTop = lObjectSpace.mSize.marValues[1] - lrYTop;
                lrYBottom = lObjectSpace.mSize.marValues[1] - lrYBottom;
                lrFrequency *= 0.95f;
            }
        }
        // the fire edge: a curved upper strip and a lower strip per element, stepping left
        {
            CGtV2d laUVs[10];
            CGtV2d laXYs[10];
            float lrElementX = (0.0013888889f + lrFlameWidth) * lObjectSpace.mSize.marValues[0];
            float lrRatioScale = 1.0f / lrElementX;
            float lrYTop = -0.78571427f * lObjectSpace.mSize.marValues[1];
            float lrYBottom = 0.21428572f * lObjectSpace.mSize.marValues[1];
            float lrYMiddle = 0.5f * (lrYTop + lrYBottom);
            float lrElementWidth = 0.25f * (0.27777779f * lObjectSpace.mSize.marValues[0]);
            float lrBoostIntensity = lrFlameWidth * lObjectSpace.mSize.marValues[1];
            float lrElementStep = 0.23333335f * lObjectSpace.mSize.marValues[0];
            float lrYEndScale = 1.142857f + lpObjectData->field_510 * 1.2857144f;
            float lrUpperXScale = 1.15f + 0.15f * lpObjectData->field_510;
            float lrMidXScale = 1.1f + 0.05f * lpObjectData->field_510;
            float lrCurrentTime = lpObjectData->field_500;
            float lrAmount = lrBoostIntensity * lrYEndScale;
            float lrFrequency = 24.0f;
            CGtV2d lOffset(lObjectSpace.mTopLeftPos.marValues[0] - 0.011111111f * lObjectSpace.mSize.marValues[0],
                           lObjectSpace.mTopLeftPos.marValues[1]);
            do {
                int lnFrame = (int)(lrCurrentTime * lrFrequency) % 41;
                Gt2dRenderer::SetTexture(CB3HUDComponent::mapBoostFireEdgeTextures[lnFrame]);
                float lrU = 1.0f;
                int lnNumPoints = 0;
                float lrX = lrElementX;
                for (int lnPoint = 0; lnPoint < 5; lnPoint++) {
                    float lrRatio = lrX * lrRatioScale;
                    float lrY0 = lrYTop - lrAmount * (lrRatio * lrRatio);
                    float lrY1 = lrYMiddle;
                    if (lrRatio < 0.125f) {
                        float lrInterpolated = 8.0f * lrRatio;
                        lrY0 = lrYBottom + lrInterpolated * (lrY0 - lrYBottom);
                        lrY1 = lrYBottom + lrInterpolated * (lrYMiddle - lrYBottom);
                    }
                    laXYs[lnNumPoints] = CGtV2d(lrX * lrUpperXScale, lrY0);
                    laUVs[lnNumPoints] = CGtV2d(lrU, 0.015625f);
                    laXYs[lnNumPoints + 1] = CGtV2d(lrX * lrMidXScale, lrY1);
                    laUVs[lnNumPoints + 1] = CGtV2d(lrU, 0.65f);
                    lnNumPoints += 2;
                    if (lrX < lrElementWidth) {
                        if (lrX <= 0.0f)
                            break;
                        lrU = lrU - 0.25f * (lrX / lrElementWidth);
                        lrX = 0.0f;
                    } else {
                        lrX -= lrElementWidth;
                        lrU -= 0.25f;
                    }
                }
                Gt2dRenderer::RenderTriStripFlatTex(lObjectSpace.mColour, lOffset, lnNumPoints, laXYs, laUVs);
                // the lower strip: the even vertices move to the bottom edge, the middle ones stay
                lrU = 1.0f;
                lnNumPoints = 0;
                lrX = lrElementX;
                for (int lnPoint = 0; lnPoint < 5; lnPoint++) {
                    float lrRatio = lrX * lrRatioScale;
                    float lrY = lrYBottom;
                    if (!(lrRatio <= 0.125f)) {
                        float lrA = 1.1428572f * (lrRatio - 0.125f);
                        lrA = lrA * lrA;
                        lrA = lrA * lrA;
                        lrA = lrA * lrA;
                        lrY = lrYBottom + lrA * (lObjectSpace.mSize.marValues[1] - lrYBottom);
                    }
                    laXYs[lnNumPoints] = CGtV2d(lrX, lrY);
                    laUVs[lnNumPoints] = CGtV2d(lrU, 0.984375f);
                    lnNumPoints += 2;
                    if (lrX < lrElementWidth) {
                        if (lrX <= 0.0f)
                            break;
                        lrU = lrU - 0.25f * (lrX / lrElementWidth);
                        lrX = 0.0f;
                    } else {
                        lrX -= lrElementWidth;
                        lrU -= 0.25f;
                    }
                }
                Gt2dRenderer::RenderTriStripFlatTex(lObjectSpace.mColour, lOffset, lnNumPoints, laXYs, laUVs);
                lrElementX = lrElementStep * (float)(int)((lrElementX - 0.001f) / lrElementStep);
                lrFrequency *= 0.95f;
            } while (lrElementX > 0.001f);
        }
        // the fire over: one gouraud strip fading in at the left and out at the right
        {
            float lrCurrentTime = lpObjectData->field_500;
            CGtV4d lZero;
            lZero.Zero();
            CGtV4d lColour = D_004B7850 * lObjectSpace.mColour;
            CGtV2d laUVs[8];
            CGtV2d laXYs[8];
            CGtV4d laRGBAs[8];
            float lrY1 = 0.85714287f * lObjectSpace.mSize.marValues[1];
            float lrX1 = (0.016666668f + lrFlameWidth) * lObjectSpace.mSize.marValues[0];
            float lrX0 = -0.008333334f * lObjectSpace.mSize.marValues[0];
            float lrXFade = 0.033333335f * lObjectSpace.mSize.marValues[0];
            laUVs[0] = CGtV2d(0.0f, 0.0f);
            laUVs[1] = CGtV2d(0.0f, 1.0f);
            laXYs[0] = CGtV2d(lrX0, 0.0f);
            laXYs[1] = CGtV2d(lrX0, lrY1);
            laRGBAs[0] = lZero;
            laRGBAs[1] = lZero;
            float lrUScale = 1.025f / lObjectSpace.mSize.marValues[0];
            int lnNumPoints;
            float lrX;
            float lrU;
            if (lrXFade + lrXFade < lrX1 - lrX0) {
                lnNumPoints = 8;
                laRGBAs[2] = lColour;
                laRGBAs[3] = lColour;
                float lrXA = lrX0 + lrXFade;
                laXYs[2] = CGtV2d(lrXA, 0.0f);
                laXYs[3] = CGtV2d(lrXA, lrY1);
                laUVs[2] = CGtV2d(lrUScale * (lrXA - lrX0), 0.0f);
                laUVs[3] = CGtV2d(lrUScale * (lrXA - lrX0), 1.0f);
                lrX = lrX1 - lrXFade;
                lrU = lrUScale * (lrX - lrX0);
            } else {
                lnNumPoints = 6;
                lrX = 0.5f * (lrX0 + lrX1);
                lrU = lrUScale * (lrX - lrX0);
            }
            laXYs[lnNumPoints - 4] = CGtV2d(lrX, 0.0f);
            laUVs[lnNumPoints - 4] = CGtV2d(lrU, 0.0f);
            laRGBAs[lnNumPoints - 4] = lColour;
            laRGBAs[lnNumPoints - 3] = lColour;
            laUVs[lnNumPoints - 3] = CGtV2d(lrU, 1.0f);
            laXYs[lnNumPoints - 3] = CGtV2d(lrX, lrY1);
            float lrURight = lrUScale * (lrX1 - lrX0);
            laXYs[lnNumPoints - 2] = CGtV2d(lrX1, 0.0f);
            laUVs[lnNumPoints - 2] = CGtV2d(lrURight, 0.0f);
            laXYs[lnNumPoints - 1] = CGtV2d(lrX1, lrY1);
            laUVs[lnNumPoints - 1] = CGtV2d(lrURight, 1.0f);
            laRGBAs[lnNumPoints - 2] = lZero;
            laRGBAs[lnNumPoints - 1] = lZero;
            int lnAnimFrame = (int)(25.0f * lrCurrentTime) % 20;
            Gt2dRenderer::SetTexture(CB3HUDComponent::mapBoostFireOverTextures[lnAnimFrame]);
            Gt2dRenderer::RenderTriStripGouraudTex(lObjectSpace.mTopLeftPos, lnNumPoints, laXYs, laUVs, laRGBAs);
        }
    }
    func_00217E70(0);
}
