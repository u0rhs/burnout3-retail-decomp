// NONMATCHING: SunPos2BearingAndAltitude__21CB3EnvironmentManagerFPfPfQ29GtMathPs26CGtV3d -- retail 213 / ours 216 instructions, 136 in changed runs
// ghvu19: logic complete (alt = 1-sqrt(1-y) / sqrt(y+1)-1; 8-way bearing = k*atan2 octants, k=1/2pi). Left: block order (retail puts the z>=0,x<0 arms after the shared store), retail keeps p in vf2 with qmtc2 hoisted into each branch delay slot (ours vf1, per arm), frame 0x3A0. Named float lane reads (float y = p.Y()) fold the lwc1 sp offsets like retail.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (ghvu19, Ghidra draft + retail asm); the lifter refused it.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
extern "C" float func_0011E358(float, float);
extern "C" float sqrtf(float);
class CB3EnvironmentManager {
public:
    void SunPos2BearingAndAltitude(float * p0, float * p1, CGtV3d p2);
};
// [L] N185: stand in for missing GtMathPs2 lane inlines (compiler-chosen VU registers):
// operator+(YAxisType, float) (as the header's operator-(YAxisType, float)), float - YAxisType into the x lane,
// unary - on XAxisType / ZAxisType as `vsub.<lane> d, $vf0, s`.
static inline YAxisType func_002BB830_addy(const CGtV3d &a, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.y %0, %1, %2x" : "=j"(r) : "j"(a.mData), "j"(s));
    return YAxisType(r);
}
static inline XAxisType func_002BB830_inl1(float f, const CGtV3d &a)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vsuby.x %0, %1, %2y" : "=j"(r) : "j"(s), "j"(a.mData));
    return XAxisType(r);
}
static inline XAxisType func_002BB830_negx(XAxisType a) { u_long128 r; asm("vsub.x %0, $vf0, %1" : "=j"(r) : "j"(a.lVector)); return XAxisType(r); }
static inline ZAxisType func_002BB830_negz(ZAxisType a) { u_long128 r; asm("vsub.z %0, $vf0, %1" : "=j"(r) : "j"(a.lVector)); return ZAxisType(r); }

// 0x002BB830
void CB3EnvironmentManager::SunPos2BearingAndAltitude(float * p0, float * p1, CGtV3d p2)
{
    CGtV3d p = p2;
    float a;
    float b;
    float y = p.Y();
    if (y >= 0.0f) {
        a = 1.0f - sqrtf(func_002BB830_inl1(1.0f, p));
    } else {
        a = sqrtf(func_002BB830_addy(p, 1.0f)) - 1.0f;
    }
    float z = p.Z();
    if (z >= 0.0f) {
        float x = p.X();
        if (x >= 0.0f) {
            float x1 = p.X();
            float z1 = p.Z();
            if (x1 > z1) {
                b = 0.1591549367f * func_0011E358(p.Z(), p.X());
            } else {
                b = 0.25f - 0.1591549367f * func_0011E358(p.X(), p.Z());
            }
        } else {
            float nx = func_002BB830_negx(p.X());
            float z1 = p.Z();
            if (nx < z1) {
                b = 0.25f + 0.1591549367f * func_0011E358(func_002BB830_negx(p.X()), p.Z());
            } else {
                b = 0.5f - 0.1591549367f * func_0011E358(p.Z(), func_002BB830_negx(p.X()));
            }
        }
    } else {
        float x = p.X();
        if (x < 0.0f) {
            float x1 = p.X();
            float z1 = p.Z();
            if (x1 < z1) {
                b = 0.5f + 0.1591549367f * func_0011E358(func_002BB830_negz(p.Z()), func_002BB830_negx(p.X()));
            } else {
                b = 0.75f - 0.1591549367f * func_0011E358(func_002BB830_negx(p.X()), func_002BB830_negz(p.Z()));
            }
        } else {
            float x1 = p.X();
            float nz = func_002BB830_negz(p.Z());
            if (x1 < nz) {
                b = 0.75f + 0.1591549367f * func_0011E358(p.X(), func_002BB830_negz(p.Z()));
            } else {
                b = 1.0f - 0.1591549367f * func_0011E358(func_002BB830_negz(p.Z()), p.X());
            }
        }
    }
    *p1 = a;
    *p0 = b;
}
