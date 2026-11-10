// NONMATCHING: _RenderParticles__17C2dObjectBoostBarFPC22B3HUDParticleParamsTagRCQ211CGt2dObject16CGt2dObjectSpacePCQ314CB3HUDBoostBar19CBoostBarObjectData9CParticleif -- retail 414 / ours 416 instructions, 283 in changed runs
// draftAI: logic complete; retail 414 / ours 416 (2 nops); every op count identical (header Interpolate x2, SetW(W() * f), SinCosFast, CGtV3d * float, X()/Y()); call identical; left: scheduling and frame 0x2B0 vs 0x2E0 (retail keeps lPos/lSize/lRight/lDown in stack slots); defined through the link name with retail's trailing bool (t0)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm op for op: live test (oldest < birth < now), position + velocity*age + gravity, birth->peak->death colour/size lerp, alpha scale, spin quad (pos +- right, pos +- down) with the fixed UV cell

// C2dObjectBoostBar::_RenderParticles(const B3HUDParticleParamsTag*, const CGt2dObject::CGt2dObjectSpace&,
// const CB3HUDBoostBar::CBoostBarObjectData::CParticle*, int, float) -- draftAI (C-first draft).
// [C] name: retail symbol table; written from the retail asm (0x1A7B00). Parameter names: Revenge's _RenderParticles (STABS:
// lpParams, lObjectSpace, lpaParticleArray, lnNumParticles, lrCurrentTime, lbCompact) [L]. Data layouts as the
// C2dObjectBoostBar::_Render archive (same file).
// What it draws [L]: every live particle (born within the last field_30 seconds) as a spinning textured quad, moving with
// its velocity under gravity, colour and size interpolated birth -> peak -> death.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

class CGtTexture;
struct B3HUDParticleParamsTag {           // [C] name: the mangled parameter; layout from this function's reads, meanings [L]
    CGtV4d field_0;                      // [C] colour at birth
    CGtV4d field_10;                     // [C] colour at the peak (field_34 of the life)
    CGtV4d field_20;                     // [C] colour at death
    float field_30;                      // [C] lifetime (seconds)
    float field_34;                      // [C] the peak, as a fraction of the lifetime
    float field_38;                      // [C] size at birth (x / 360 of the width, / 28 of the height)
    float field_3C;                      // [C] size at the peak
    float field_40;                      // [C] size at death
    float field_44;                      // [C] gravity (y acceleration, before the object scale)
};
class CB3HUDBoostBar {
public:
    // [L] name: _RenderParticles' mangled parameter types (CB3HUDBoostBar::CBoostBarObjectData::CParticle). Layout from this
    // function's reads [C] offsets; meanings [L].
    struct CBoostBarObjectData {
        struct CParticle {
            CGtV2d field_0;                 // [C] start position (object units)
            CGtV2d field_8;                 // [C] velocity
            float field_10;                 // [C] birth time (on the caller's clock)
            float field_14;                 // [C] spin rate (radians per second)
            float field_18;                 // [C] size scale
            float field_1C;                 // [C] alpha scale
        };
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
    static void _RenderParticles(const B3HUDParticleParamsTag *lpParams, const CGt2dObject::CGt2dObjectSpace &lObjectSpace,
                                 const CB3HUDBoostBar::CBoostBarObjectData::CParticle *lpaParticleArray, int lnNumParticles,
                                 float lrCurrentTime, bool lbCompact);
};

// 0x001A7B00
// [C] the trailing bool (t0, after the mangled name's float) is Revenge's lbCompact: defined with retail's real list
extern "C" void _RenderParticles__17C2dObjectBoostBarFPC22B3HUDParticleParamsTagRCQ211CGt2dObject16CGt2dObjectSpacePCQ314CB3HUDBoostBar19CBoostBarObjectData9CParticleif(
    const B3HUDParticleParamsTag *lpParams, const CGt2dObject::CGt2dObjectSpace &lObjectSpace,
    const CB3HUDBoostBar::CBoostBarObjectData::CParticle *lpaParticleArray, void *lnNumParticles_, float lrCurrentTime, bool lbCompact)
{
    int lnNumParticles = (int)lnNumParticles_;
    float lrLife = lpParams->field_30;
    float lrPeak = lpParams->field_34 * lrLife;
    float lrHalfGravity = 0.5f * lpParams->field_44;
    float lrRecipFall = 1.0f / (lrLife - lrPeak);
    float lrRecipRise = 1.0f / lrPeak;
    const CGtV2d &lSize = lObjectSpace.mSize;
    CGtV2d lSizeBirth(0.0027777778f * lpParams->field_38 * lSize.marValues[0], 0.035714287f * lpParams->field_38 * lSize.marValues[1]);
    float lrRise = lpParams->field_3C - lpParams->field_38;
    CGtV2d lSizeRise(0.0027777778f * lrRise * lSize.marValues[0], 0.035714287f * lrRise * lSize.marValues[1]);
    float lrFall = lpParams->field_3C - lpParams->field_40;
    CGtV2d lSizeFall(lrFall / 360.0f * lSize.marValues[0], lrFall / 28.0f * lSize.marValues[1]);
    CGtV2d lSizeDeath(lpParams->field_40 / 360.0f * lSize.marValues[0], lpParams->field_40 / 28.0f * lSize.marValues[1]);
    float lrOldest = lrCurrentTime - lrLife;
    CGtV2d lScale = lSize;
    if (lbCompact)
        lScale.marValues[0] = 0.5f * lSize.marValues[0];
    const CB3HUDBoostBar::CBoostBarObjectData::CParticle *p = lpaParticleArray;
    int n = lnNumParticles;
    do {
        float lrBirth = p->field_10;
        if (!(lrBirth <= lrOldest) && lrBirth < lrCurrentTime) {
            float lrAge = lrCurrentTime - lrBirth;
            CGtV2d lPos = p->field_0 + p->field_8 * lrAge;
            float lrAngle = p->field_14 * lrAge;
            lPos.marValues[0] = lPos.marValues[0] * lScale.marValues[0];
            lPos.marValues[1] = (lPos.marValues[1] + lrHalfGravity * (lrAge * lrAge)) * lScale.marValues[1];
            CGtV2d lParticleSize;
            CGtV4d lColour;
            if (lrAge < lrPeak) {
                float t = lrAge * lrRecipRise;
                lParticleSize = lSizeBirth + lSizeRise * t;
                lColour = Interpolate(lpParams->field_0, lpParams->field_10, t);
            } else {
                float t = lrRecipFall * (lrLife - lrAge);
                lParticleSize = lSizeDeath + lSizeFall * t;
                lColour = Interpolate(lpParams->field_20, lpParams->field_10, t);
            }
            lColour.SetW(lColour.W() * p->field_1C);
            CGtV4d lSinCos = SinCosFast(lrAngle);
            CGtV3d lSC = CGtV3d(lSinCos.mData) * p->field_18;
            CGtV2d laUVs[4];
            CGtV2d laXYs[4];
            laUVs[0].Set(0.0078125f, 0.001953125f);
            laUVs[1].Set(0.4921875f, 0.001953125f);
            laUVs[2].Set(0.0078125f, 0.123046875f);
            laUVs[3].Set(0.4921875f, 0.123046875f);
            float c = lSC.Y();
            float s = lSC.X();
            CGtV2d lRight(c * lParticleSize.marValues[0], s * lParticleSize.marValues[1]);
            CGtV2d lDown(-s * lParticleSize.marValues[0], c * lParticleSize.marValues[1]);
            laXYs[0] = lPos + lRight;
            laXYs[3] = lPos - lRight;
            laXYs[1] = lPos + lDown;
            laXYs[2] = lPos - lDown;
            Gt2dRenderer::RenderTriStripFlatTex(lColour, lObjectSpace.mTopLeftPos, 4, laXYs, laUVs);
        }
        p++;
    } while (--n != 0);
}
