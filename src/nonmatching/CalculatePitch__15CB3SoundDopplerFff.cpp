// NONMATCHING: CalculatePitch__15CB3SoundDopplerFff -- retail 134 / ours 125 instructions, 94 in changed runs
// a124: 125/134 instrs, 94 changed; semantics decoded: sign-flip p0 if p1<0; t=p1/f14; w=(1360-p1)/1360; D20[0..3] descending breakpoints, piecewise-linear 3 arms (p0>=D20[0]: D30[0],D40[0]; p0<=D2C: D3C,D4C; else search i=1..3, lo=i-1 hi=i, frac=(x1-p0)/(x1-x0)); arm = 0+D40*w + D30*dot, dot=(f0*f8+t*f4)/2; result clamp max D_004E06EC min 2.0. Left: retail does not CSE dot across arms (3 separate mula/madd/div) and orders products first (mul f11,f10 then dot then adda); ours hoists/merges. Need non-CSE form (inline helper per arm?)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMath.h"
class CB3SoundDoppler {
public:
    float CalculatePitch(float p0, float p1);

    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0x8];
    float field_14;
};

extern float D_01E86D20[];
extern float D_01E86D30[];
extern float D_01E86D40[];
extern float D_01E86D2C;
extern float D_01E86D3C;
extern float D_01E86D4C;
extern float D_004E06EC;

float CB3SoundDoppler::CalculatePitch(float p0, float p1)
{
    // pass1 [C] retail: lo/hi are written only inside the bracket search (0x2F4DA4); the fall-through path into 0x2F4C3C
    // would read a2/t0 as left by Update__15CB3SoundDopplerFffffPfPf (its second pointer / its untouched entry t0).
    // Unreachable: with D[3] < p0 < D[0] the search always stops by i = 3. Not arguments; a port may initialise them.
    int hi;
    int lo;
    int i;
    if (p1 < 0.0f) {
        p0 = -p0;
    }
    float k = 1360.0f;
    float t = p1 / field_14;
    float w;
    w = (k - p1) / k;
    if (p0 < D_01E86D20[0]) {
        if (p0 <= D_01E86D2C) {
            float dot = (field_0 * field_8 + t * field_4) / 2.0f;
            return GtMath::Min(GtMath::Max(D_01E86D3C * dot + D_01E86D4C * w, D_004E06EC), 2.0f);
        } else {
            for (i = 1; i < 4; i++) {
                if (!(p0 < D_01E86D20[i])) {
                    lo = i - 1;
                    hi = i;
                    break;
                }
            }
            float x0 = D_01E86D20[hi];
            float x1 = D_01E86D20[lo];
            float frac = ((x1 - x0) - (p0 - x0)) / (x1 - x0);
            float a = w * D_01E86D40[lo];
            float b = w * D_01E86D40[hi];
            float dot = (field_0 * field_8 + t * field_4) / 2.0f;
            a = a + dot * D_01E86D30[lo];
            b = b + dot * D_01E86D30[hi];
            return GtMath::Min(GtMath::Max(b * frac + a * (1.0f - frac), D_004E06EC), 2.0f);
        }
    } else {
        float dot = (field_0 * field_8 + t * field_4) / 2.0f;
        return GtMath::Min(GtMath::Max(D_01E86D30[0] * dot + D_01E86D40[0] * w, D_004E06EC), 2.0f);
    }
}
