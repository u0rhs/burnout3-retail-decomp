// NONMATCHING: func_0025D930 -- retail 383 / ours 360 instructions, 259 in changed runs (gapO: CV3dRandomiser reroute, was 348 / 231)
// draftAM C-first: [L] CB3EffectsManager spark/popcorn burst along a segment (DoCrazySparksWithWorld's tail call): speed scale min(|vel|/50, 1), VU0 R seeded from the manager's CGtRandom (+0x1F828), spawn count from a fractional carry D_004E19DC (rate x 7 for the first pass when the flag is set, then a second pass with rate and the flag cleared); per spawn: velocity = lerp(vel/2, vel/4 range, Rx) + lerp(spark box (+-3, 0.5..13, +-3) x scale), position jitter +-0.25, SpawnBouncySpark; on Random() & 1 also SpawnBouncyPopcorn (box +-8, 0.25..8.25) at the same position; position steps dir / n, the height argument by the step's y; 348/383, calls identical, non-stack stores identical (D_01D9D190 x2, D_004E19DC x2), every VU op count equal but 2 vmove (3 vrnext groups + vrinit, 5 vmr32)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; signature from the caller (0x256624: f12 rate, f13 height, a0 this, a1..a3 stack vectors, t0 body+0x210 passed straight into SpawnBouncySpark's bool), the scale test (c.le 2500 (an int converted at run time), sqrt.s x 0.02 else 1.0), each R draw's lanes and state rotation, each lerp's base/range pair (0x410/0x420, 0x430/0x440, 0x450/0x460, 0x3F0/0x400), the two-pass flag loop and the shared spark position for the popcorn traced; the only audit finding is the scale test's arm placement (c.le+bc1f vs bc1t, same condition; all source forms compile the same)

// func_0025D930 -- draftAM (C-first draft). 0x25D930, 0x5FC. Unnamed in every table: placeholder with C linkage; parameter list
// as the caller's archive (DoCrazySparksWithWorld__17CB3EffectsManager) declares it, with the last one bool.
// The random vectors keep retail's exact VU0 sequence (hard1's func_0039A360 pattern): R draws x a rotating state (retail
// D_01D9D190, mixed through ACC with D_004BBFB0 = this file's gEffectsRandomiserScales / kEffectsRandomiser2E23). gapO: the
// draws and lerps are CV3dRandomiser::RandomInterpolate (one draw, vmaddx.xyz) and RandomiseXYZ (three draws, vmadd.xyz) from
// b3/_unclassified/CV3dRandomiser.h ([L] Revenge STABS names, N288); each randomiser's (maximum, maximum - minimum) pair is one
// 0x20 object (retail's 0x410/0x420, 0x430/0x440, 0x450/0x460, 0x3F0/0x400 pairs). The seed (vrinit) stays a local helper.
// Meanings of the vectors [G] (the "min/max" boxes are the constants retail builds on the stack and scales by the speed).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/_unclassified/GtRandom.h"
#include "b3/_unclassified/CV3dRandomiser.h"
using namespace GtMathPs2;

struct UnkStruct_0025D930_mgr {                // [L] CB3EffectsManager (the caller DoCrazySparksWithWorld passes its this)
    unsigned char pad_0[0x20F0];
    unsigned char field_20F0[0x100];           // [L] a CB3PopcornArray (SpawnBouncyPopcorn's this)
    unsigned char field_21F0[0x1D638];         // [L] a CB3SparkArray (SpawnBouncySpark's this)
    CGtRandom field_1F828;
    unsigned char pad_1F830[0x18];
    float field_1F848;                         // [G] spark/popcorn lifetime or size, passed as both spawns' first float
};
extern float D_004E19DC;                       // [G] fractional spawn-count carry (initial 0.999)
extern "C" float sqrtf(float);
extern "C" void SpawnBouncySpark__13CB3SparkArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dffb(void *, const CGtV3d *, const CGtV3d *, float, float, bool);
extern "C" void SpawnBouncyPopcorn__15CB3PopcornArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dff(void *, const CGtV3d *, const CGtV3d *, float, float);

// the VU0 random generator seeded (vrinit), as func_0039A360_inl1
static inline void func_0025D930_inl1(float seed)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(seed));
    asm volatile("vrinit $R, %0x" : : "j"(s));
}

// 0x0025D930
extern "C" void func_0025D930(float rate, float h, UnkStruct_0025D930_mgr *self, const CGtV3d *pos, const CGtV3d *dir,
                              const CGtV3d *vel, bool b)
{
    CGtV3d lvel = *vel;
    CGtV3d ldir = *dir;
    CGtV3d lpos = *pos;
    float lenSq = lvel.GetSquaredLength();
    float scale;
    if (lenSq <= (float)2500)
        scale = 0.02f * sqrtf(lenSq);
    else
        scale = 1.0f;
    func_0025D930_inl1(self->field_1F828.RandomReal());
    CGtV3d lSparkMin = CGtV3d(-3.0f, 0.5f, -3.0f) * scale;
    CGtV3d lSparkMax = CGtV3d(3.0f, 13.0f, 3.0f) * scale;
    CGtV3d lPopMin = CGtV3d(-8.0f, 0.25f, -8.0f) * scale;
    CGtV3d lPopMax = CGtV3d(8.0f, 8.25f, 8.0f) * scale;
    CGtV3d lJitter(0.25f, 0.25f, 0.25f);
    CV3dRandomiser lSpark;
    lSpark.mVecA = lSparkMax;
    lSpark.mVecB = lSparkMax - lSparkMin;
    CV3dRandomiser lPop;
    lPop.mVecA = lPopMax;
    lPop.mVecB = lPopMax - lPopMin;
    CV3dRandomiser lVel;
    lVel.mVecA = lvel * 0.5f;
    lVel.mVecB = lVel.mVecA - lvel * 0.25f;
    CV3dRandomiser lJit;
    lJit.mVecA = lJitter;
    lJit.mVecB = lJitter - (-lJitter);
    for (;;) {
        int n;
        if (b) {
            float f = D_004E19DC + rate * 7.0f;
            n = (int)f;
            D_004E19DC = f - (float)n;
        } else {
            float f = D_004E19DC + rate;
            n = (int)f;
            D_004E19DC = f - (float)n;
        }
        if (n > 0) {
            float lh = h;
            CGtV3d lcur = lpos;
            CGtV3d lstep = ldir * (1.0f / (float)n);
            do {
                CGtV3d a = lVel.RandomInterpolate();
                CGtV3d v = a + lSpark.RandomiseXYZ();
                CGtV3d o = lJit.RandomiseXYZ();
                CGtV3d p = lcur + o;
                SpawnBouncySpark__13CB3SparkArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dffb(self->field_21F0, &p, &v,
                                                                                         self->field_1F848, lh, b);
                if (self->field_1F828.Random() & 1) {
                    CGtV3d a2 = lVel.RandomInterpolate();
                    CGtV3d b2 = lPop.RandomiseXYZ();
                    v = a2 + b2;
                    SpawnBouncyPopcorn__15CB3PopcornArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dff(self->field_20F0, &p, &v,
                                                                                                 self->field_1F848, lh);
                }
                lcur += lstep;
                lh += (float)lstep.Y();
            } while (--n != 0);
        }
        if (!b)
            break;
        b = false;
    }
}
