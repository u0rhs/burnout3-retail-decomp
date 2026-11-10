// NONMATCHING: SpawnDebris__14CB3DebrisArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dffff -- retail 143 / ours 142 instructions, 70 in changed runs
// near35: (old archive re-measured 82 changed under today's header) a 0x50-byte N140 UnkStruct_002F46F0_pad declared after e stands in for retail's 5 dead 16-byte slots -> frame 0x1B0 exact. 142/143, 70 changed: Y-lane temp/vel-read slots (retail 0x40/0xA0, ours 0x00/0x30), e in v1 (retail t0), colour-pack sqc2/lane-read scheduling (retail Z copy before Y); pack-expression forms tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: SpawnDebris__14CB3DebrisArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dffff -- retail 143 / ours 142 instructions, 67 in changed runs
// v257: logic complete (ballistic bounce: disc = vy^2 + 19.6h, t = (vy + sqrt)/9.8, CGtSphere SetPosition/SetRadius, CGtV3dPlus SetGtV3d/SetPlus, colour pack); param copies at retail's slots; 142/143, 67 changed: entry pointer e in v1 (retail t0), colour-pack scheduling, frame 0x160 vs 0x1B0 (dead slots from unknown inline signatures); stand-ins for YAxisType - float (compiler-chosen scalar), w = vf0.w * y (vmuly.w), CGtV3d lane product
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_002F46F0_e {
    CGtSphere field_0;
    CGtSphere field_10;
    CGtV3dPlus field_20;
    float field_30;
    unsigned int field_34;
    float field_38;
    unsigned char pad_3C[4];
};
class CB3DebrisArray {
public:
    void SpawnDebris(CGtV3d, CGtV3d, CGtV3d, CGtV3d, float, float, float, float);
    unsigned char pad_0[0x14];
    UnkStruct_002F46F0_e * field_14;
    int field_18;
    int field_1C;
};
extern CGtV3d kColourScale;
extern "C" float sqrtf(float);
// [L] N185 stand-ins (compiler-chosen VU registers)
static inline YAxisType func_002F46F0_inl1(YAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return YAxisType(r); }
static inline void func_002F46F0_inl2(CGtSphere &d, YAxisType a) { asm("vmuly.w %0, $vf0, %1y" : "+j"(d.mData) : "j"(a.lVector)); }
static inline CGtV3d func_002F46F0_inl3(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vmul.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }

struct UnkStruct_002F46F0_pad { int x[20]; UnkStruct_002F46F0_pad() {} ~UnkStruct_002F46F0_pad() {} };
// 0x002F46F0
void CB3DebrisArray::SpawnDebris(CGtV3d pos, CGtV3d vel, CGtV3d p3, CGtV3d col, float a, float b, float c, float d)
{
    CGtV3d lp = pos;
    CGtV3d lv = vel;
    CGtV3d l3 = p3;
    CGtV3d lc = col;
    UnkStruct_002F46F0_e * e = &field_14[field_1C];
    UnkStruct_002F46F0_pad pad0;
    float vy = lv.Y();
    if (vy < 0.0f && c <= 0.0f) vy = -vy;
    e->field_0.SetPosition(lp);
    e->field_10.SetPosition(lv);
    float disc = vy * vy - -19.6f * c;
    if (disc <= 0.0f) goto flat;
    {
        float q = -39.2f + vy;
        if (!(disc < q * q)) goto flat;
    }
    {
        float t = 0.10204081f * (sqrtf(disc) + vy);
        float g = -9.8f * t;
        float v = -0.6f * (vy + g) - g;
        float s = v * t;
        float h = -4.9f * t * t;
        e->field_0.SetRadius(func_002F46F0_inl1(func_002F46F0_inl1(func_002F46F0_inl1(lp.Y(), c), s), h));
        e->field_10.SetRadius(v);
    }
    goto common;
flat:
    func_002F46F0_inl2(e->field_0, lp.Y());
    func_002F46F0_inl2(e->field_10, lv.Y());
common:
    e->field_20.SetGtV3d(l3);
    e->field_20.SetPlus(a);
    e->field_30 = d;
    CGtV3d k = func_002F46F0_inl3(lc, kColourScale);
    e->field_34 = (int)(float)k.X() | ((int)(float)k.Y() << 8) | ((int)(float)k.Z() << 16) | 0x80000000;
    e->field_38 = b;
    field_1C++;
    if (field_1C == field_18) field_1C = 0;
}
