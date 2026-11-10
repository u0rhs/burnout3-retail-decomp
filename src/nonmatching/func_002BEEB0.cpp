// NONMATCHING: func_002BEEB0 -- retail 143 / ours 142 instructions, 9 in changed runs
// v257: logic complete (ClipPolyBy2AxisPlanes, DNAT high); 142/143, 9 changed: retail hoists (in + axis*4) as the axis-lane base and adds i*16, ours adds axis*4 to &in[i]; every form that gets the hoist (float-indexed in[i*4+axis], (float*)in+axis) rotates t1/t2/t3 (ax / &in[i] / cur) and the VU-block temps (29 changed)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (v257); the lifter refused it.
// [L] DNAT: ClipPolyBy2AxisPlanes(GtMathPs2::CGtV3d*, const float*, int, float, float, int) (research/proto/new_names.csv,
// high; B3BoundingBox.cpp, file static: no symbol form). Clips a polygon against lo <= p[axis] <= hi.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// [L] N185 stand-ins: lane-scaled product with the scalar on its own statement, and a sum on compiler-chosen registers
static inline CGtV3d func_002BEEB0_inl1(const CGtV3d &a, float s) { u_long128 sv, t; asm("qmtc2.ni %1, %0" : "=j"(sv) : "r"(s)); asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(sv)); return CGtV3d(t); }
static inline CGtV3d func_002BEEB0_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
static inline int func_002BEEB0_inl0(float v, float lo, float hi) { return v < lo ? 1 : (v > hi ? 2 : 0); }


static inline void func_002BEEB0_inl3(CGtV3d &o, const CGtV3d &a, const CGtV3d &b, float t) { o = func_002BEEB0_inl2(func_002BEEB0_inl1(a, t), func_002BEEB0_inl1(b, 1.0f - t)); }
// 0x002BEEB0
extern "C" int func_002BEEB0(CGtV3d * out, const CGtV3d * in, int n, float lo, float hi, int axis)
{
    int cnt = 0;
    int prev = func_002BEEB0_inl0(((const float *)&in[n])[axis - 4], lo, hi);
    for (int i = 0; i < n; i++) {
        const CGtV3d * pc = &in[i];
        float v = ((const float *)&in[i])[axis];
        int cur = func_002BEEB0_inl0(v, lo, hi);
        if (prev != cur) {
            int j;
            if (i == 0) j = n - 1; else j = i - 1;
            float pv = ((const float *)&in[j])[axis];
            const CGtV3d * pp = &in[j];
            float inv = 1.0f / (v - pv);
            if (prev == 1) {
                float t = inv * (lo - pv);
                out[cnt++] = func_002BEEB0_inl2(func_002BEEB0_inl1(*pc, t), func_002BEEB0_inl1(*pp, 1.0f - t));
            } else if (prev == 2) {
                float t = inv * (hi - pv);
                out[cnt++] = func_002BEEB0_inl2(func_002BEEB0_inl1(*pc, t), func_002BEEB0_inl1(*pp, 1.0f - t));
            }
            if (cur == 1) {
                float t = inv * (lo - pv);
                out[cnt++] = func_002BEEB0_inl2(func_002BEEB0_inl1(*pc, t), func_002BEEB0_inl1(*pp, 1.0f - t));
            } else if (cur == 2) {
                float t = inv * (hi - pv);
                out[cnt++] = func_002BEEB0_inl2(func_002BEEB0_inl1(*pc, t), func_002BEEB0_inl1(*pp, 1.0f - t));
            }
        }
        if (cur == 0) out[cnt++] = *pc;
        prev = cur;
    }
    return cnt;
}
