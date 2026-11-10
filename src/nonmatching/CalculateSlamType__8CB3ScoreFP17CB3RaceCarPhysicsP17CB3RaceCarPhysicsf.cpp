// NONMATCHING: CalculateSlamType__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsf -- retail 241 / ours 241 instructions, 21 in changed runs
// happly1 (N232): v296_cosang stand-in -> header CosAngleBetweenNormalisedVectors (identical code, 21 = 21; stand-in dropped; N140 pad still needed: without it 24, frame 0xC0). Left as v296: (1) qmfc2 of the normalised vector scheduled before the parked 1.0's qmtc2 at the 4 Normalise+1/length sites (no header API for that family); (2) GtMath::Sign stack-slot order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum ERaceCarCollisionType {};
class CB3RaceCarPhysics;
class CB3HUDSoundManager {
public:
    void OnRaceCarCollision(ERaceCarCollisionType, CB3RaceCarPhysics *, CB3RaceCarPhysics *, float);
    unsigned char pad_0[0x10];
};
extern CB3HUDSoundManager D_01E7A800;
class CB3RaceCarPhysics {
public:
    unsigned char pad_0[0x204];
    CGtMatrix3x4 *field_204;
};
class CB3Score {
public:
    static int CalculateSlamType(CB3RaceCarPhysics *, CB3RaceCarPhysics *, float);
};
extern "C" float func_0011E328(float);   // [L] acosf (LIBM wf_acos.o wrapper next to __ieee754_acosf 0x119C20)
extern float D_004E1564;                 // [L] lrSideAngle$36829 (config/symbol_addrs_b3names.txt, medium): 25.0f

// [L] N185: stands in for the unnamed retail Normalise family that also computes 1/length (`vmulq.x $vf1,$vf1,$Q`, ~80
// sites; N217 dropped it from NormaliseGetLength): in place on a compiler-chosen register, the 1.0 parked in a GPR.
static inline XAxisType v296_normil(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 one, r;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %0, $vf1" : "=r"(one));
    asm("vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" "\n\t" "qmtc2.i %1, $vf1" : "+j"(v.mData) : "r"(one));
    asm("vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r));
    asm(".set reorder");
    return XAxisType(r);
}
// [L] N185: CGtV3d::Normalise's in-place tail shape (N217: ~40 retail sites), compiler-chosen register
static inline void v296_norm(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData));
    asm(".set reorder");
}
// [L] N185: stands in for GtMathPs2::CosAngleBetweenNormalisedVectors(CGtV3d, CGtV3d) (B3O0PCH map): the dot product
// clamped to [-1, 1] (`vsubw.x m,$vf0,$vf0w; vmax.x; vminiw.x ..,$vf0w`)
static inline float v296_cosang(CGtV3d a, CGtV3d b)
{
    XAxisType d = DotProduct(a, b);
    u_long128 m, r;
    asm("vsubw.x %0, $vf0, $vf0w" : "=j"(m));
    asm("qmtc2 %1, $vf1" "\n\t" "vmax.x $vf1, $vf1, %2" "\n\t" "vminiw.x $vf1, $vf1, $vf0w" "\n\t" "qmfc2 %0, $vf1"
        : "=r"(r) : "r"(d.lVector), "j"(m));
    return XAxisType(r);
}
// [L] GtMath::Sign(float) (B3O0PCH map, 48 bytes): +/-1.0 with x's sign bit
static inline float v296_sign(float x)
{
    unsigned int i = (*(unsigned int *)&x & 0x80000000) | 0x3F800000;
    return *(float *)&i;
}
// N140 frame-slot pad: an unused local with an empty ctor/dtor reserves one 16-byte slot and emits no code
struct UnkStruct_00156320_pad { int x[4]; UnkStruct_00156320_pad() {} ~UnkStruct_00156320_pad() {} };

// 0x00156320
int CB3Score::CalculateSlamType(CB3RaceCarPhysics *a, CB3RaceCarPhysics *b, float f)
{
    // [G] N140: one unused 16-byte slot (retail frame 0xD0)
    UnkStruct_00156320_pad pad;
    CGtV3d va = a->field_204->mAt;
    CGtV3d vb = b->field_204->mAt;
    v296_normil(va);
    v296_normil(vb);
    float ang = 57.29578f * func_0011E328(CosAngleBetweenNormalisedVectors(va, vb));
    if (ang < 45.0f) {
        CGtV3d d = b->field_204->mPos - a->field_204->mPos;
        CGtV3d at = a->field_204->mAt;
        v296_normil(d);
        v296_normil(at);
        float ang2 = 57.29578f * func_0011E328(CosAngleBetweenNormalisedVectors(d, at));
        if (ang2 < 30.0f) {
            D_01E7A800.OnRaceCarCollision((ERaceCarCollisionType)6, a, b, f);
            return 1;
        }
        return 0;
    } else if (ang < 135.0f) {
        CGtV3d d = a->field_204->mPos - b->field_204->mPos;
        v296_norm(d);
        float c1 = DotProduct(a->field_204->mRight, b->field_204->mAt);
        float c2 = DotProduct(d, b->field_204->mRight);
        float ang3 = 57.29578f * func_0011E328(c1);
        if (ang3 < D_004E1564 || ang3 > 180.0f - D_004E1564) {
            float s1 = v296_sign(c1);
            float s2 = v296_sign(c2);
            if (s2 == s1) {
                return 3;
            }
            return 2;
        }
        return 0;
    }
    return 0;
}

