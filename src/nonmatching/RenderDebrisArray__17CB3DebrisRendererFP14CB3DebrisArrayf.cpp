// NONMATCHING: RenderDebrisArray__17CB3DebrisRendererFP14CB3DebrisArrayf -- retail 182 / ours 182 instructions, 46 in changed runs (gapO: CGtV4d::operator+ reroute, was 47)
// near35: float dt declared at function top (fixes the f21/f22 tmin/dt swap); IntersectSphere called with an explicit CGtSphere(s) copy (retail's second sqc2 to 0xF0, 182/182); three N140 UnkStruct_002F4320_pad (one inside the scalar-multiply inline, one inside the vadd inline, one between s and c) -> frame 0x1B0 exact. Left 47: pos VU numbering (retail kHalf vf3 / vel vf2 / p0 vf1, results in place on vf1; ours rotated; asm operand-order and dt2 local tried) and the rot/c/s slot offsets (retail 0xC0-0xE0 / 0x180 / 0x1A0)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: RenderDebrisArray__17CB3DebrisRendererFP14CB3DebrisArrayf -- retail 182 / ours 181 instructions, 67 in changed runs
// v287: logic right; static member; inlined AddParticleToBuffer exact once the batch buffer + count are ONE object (D_01E866D0, count at +0x644: retail reloads it after every buffer store). Left: pos = p0 + vel*dt + kHalf*dt^2 VU numbering (retail kHalf vf3/vel vf2/p0 vf1, ours rotated), rot reloads field_20 by lqc2 (retail reuses the lq via qmtc2), f21/f22 swap (tmin/dt), 360 mul operand order, frame 0x150 vs 0x1B0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3DebrisRenderer::RenderDebrisArray(CB3DebrisArray*,float) -- hand-written (the lifter refused it).
// [C] name: research/retail_names.csv -> B3DebrisRendererPS2.cpp. Static member [C asm: a0 is the array, no this].
// Fields are placeholders, types [G]. AddParticleToBuffer [C name: B3O0PCH map, (CGtV3d, CGtV3dPlus, unsigned int,
// EGtIntersectionResult)] is inlined in retail.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
enum EGtIntersectionResult { UnkEnum_002F4320_0, UnkEnum_002F4320_1 };
class CGtFrustum;
struct UnkStruct_002F4320_e {      // one debris particle, 0x40 bytes [G]
    CGtV4d field_0;
    CGtV4d field_10;
    CGtV4d field_20;
    float field_30;
    unsigned int field_34;
    float field_38;
    unsigned char pad_3C[4];
};
class CB3DebrisArray {
public:
    unsigned char pad_0[0x14];
    UnkStruct_002F4320_e *field_14;
    unsigned int field_18;
    int field_1C;
    float field_20;
};
struct UnkStruct_D_01E866D0 {      // [L] one object: retail reloads the count (+0x644) after every buffer store
    CGtV3dPlus field_0[16];
    CGtV3dPlus field_100[16];
    unsigned char pad_200[0x400];
    unsigned int field_600[16];
    int field_640;                  // D_01E86D10
    int field_644;                  // D_01E86D14: particles in the batch
    CB3DebrisArray *field_648;      // D_01E86D18
    unsigned char field_64C;        // D_01E86D1C
    unsigned char pad_64D[3];
};
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E866D0 D_01E866D0;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern const CGtV4d kHalfDebrisAcceleration;
extern "C" EGtIntersectionResult IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustum(CGtSphere, const CGtFrustum &);
class CB3DebrisRenderer {
public:
    static void RenderDebrisArray(CB3DebrisArray *, float);
    static void DispatchBuffer();
    static void AddParticleToBuffer(CGtV3d pos, CGtV3dPlus rot, unsigned int col, EGtIntersectionResult res)
    {
        if (D_01E866D0.field_644 == 16)
            DispatchBuffer();
        D_01E866D0.field_0[D_01E866D0.field_644].SetGtV3d(pos);
        D_01E866D0.field_0[D_01E866D0.field_644].SetPlus((float)res);
        D_01E866D0.field_100[D_01E866D0.field_644] = rot;
        D_01E866D0.field_600[D_01E866D0.field_644] = col;
        D_01E866D0.field_644++;
    }
};
// [L] N185 stand-ins: CGtV4d operator*(float) with the scalar on a compiler-chosen register, CGtV4d operator+
struct UnkStruct_002F4320_pad { int x[4]; UnkStruct_002F4320_pad() {} ~UnkStruct_002F4320_pad() {} };
static inline CGtV4d func_002F4320_inl1(const CGtV4d &a, float s)
{
    UnkStruct_002F4320_pad pa;
    u_long128 t, sv;
    asm("qmtc2.ni %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(sv));
    return CGtV4d(t);
}
static inline void func_002F4320_inl3(CGtV4d &a, const CGtV4d &b) { asm("vadd.xyzw %0, %0, %1" : "+j"(a.mData) : "j"(b.mData)); }
// 0x002F4320
void CB3DebrisRenderer::RenderDebrisArray(CB3DebrisArray *arr, float t)
{
    D_01E866D0.field_648 = arr;
    UnkStruct_002F4320_e *p = arr->field_14;
    float dt;
    float tmin = t - 4.0f;
    unsigned int i = 0;
    const CGtFrustum &fr = *(const CGtFrustum *)((char *)&D_00665EC0 + D_00667050.field_0 * 0x230 + 0x470);
    for (; i < arr->field_18; p++, i++) {
        if (p->field_30 <= tmin)
            continue;
        if (!(p->field_30 < t))
            continue;
        dt = t - p->field_30;
        CGtV4d pos = ((p->field_0 + func_002F4320_inl1(p->field_10, dt)) + func_002F4320_inl1(kHalfDebrisAcceleration, dt * dt));
        CGtSphere s;
        UnkStruct_002F4320_pad pc;
        CGtV3d c;
        c.SetX(pos.X());
        c.SetY(GtMath::Max(pos.Y(), pos.W()));
        c.SetZ(pos.Z());
        float rad = p->field_38 * arr->field_20;
        s.SetPosition(c);
        s.SetRadius(rad);
        EGtIntersectionResult r = IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustum(CGtSphere(s), fr);
        if (r == 0)
            continue;
        CGtV3dPlus rot;
        rot.mData = p->field_20.mData;
        float w = p->field_20.W();
        float a = w + w * dt;
        rot.SetPlus(360.0f * (a - (float)(int)a));
        AddParticleToBuffer(c, rot, p->field_34, r);
    }
    if (D_01E866D0.field_644 > 0)
        DispatchBuffer();
}
