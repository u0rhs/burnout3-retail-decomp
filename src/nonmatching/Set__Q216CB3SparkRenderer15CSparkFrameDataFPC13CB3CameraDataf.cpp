// NONMATCHING: Set__Q216CB3SparkRenderer15CSparkFrameDataFPC13CB3CameraDataf -- retail 137 / ours 140 instructions, 126 in changed runs
// ghvu7 first draft: semantics decoded (projection rows: xy=2*cam rows, w=r3.w+cam.z, xy-=w, xy*=s, z=s.z*w, r3.z+=s.w; s = (c218/(256+c218), c21C/(256+c21C), (n+f)/(n-f), -2nf/(n-f)); field_40 lanes; field_50.x=t). 140/137, 126 changed: FP/VU scheduling and registers, frame 0x40 vs 0x50 (one more 16-byte slot). Lane-op stand-ins [L] N185
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3SparkRenderer::CSparkFrameData::Set(const CB3CameraData*, float) -- hand-written (ghvu7) from the Ghidra draft.
// [C] name: the mangled symbol in retail's tables. Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct CB3CameraData {
    unsigned char pad_0[0xE0];
    u_long128 field_E0[4];
    unsigned char pad_120[0x6C];
    float field_18C;
    unsigned char pad_190[0xC];
    float field_19C;
    unsigned char pad_1A0[0x60];
    float field_200;
    float field_204;
    float field_208;
    float field_20C;
    unsigned char pad_210[8];
    float field_218;
    float field_21C;
};
class CB3SparkRenderer {
public:
    class CSparkFrameData {
    public:
        void Set(const CB3CameraData *, float);
        u_long128 field_0;
        u_long128 field_10;
        u_long128 field_20;
        u_long128 field_30;
        u_long128 field_40;
        CGtV3d field_50;
    };
};

// [L] N185: lane-op stand-ins on compiler-chosen registers (no GtMathPs2 API is evidenced for these shapes).
static inline void func_00263120_inl1(u_long128 &r, const u_long128 &a) { asm("vadd.xy %0, %1, %1" : "+j"(r) : "j"(a)); }
static inline void func_00263120_inl2(u_long128 &r, const u_long128 &b, const u_long128 &a) { asm("vaddz.w %0, %1, %2z" : "+j"(r) : "j"(b), "j"(a)); }
static inline void func_00263120_inl3(u_long128 &r) { asm("vsubw.xy %0, %0, %0w" : "+j"(r)); }
static inline void func_00263120_inl4(u_long128 &r, const u_long128 &s) { asm("vmul.xy %0, %0, %1" : "+j"(r) : "j"(s)); }
static inline void func_00263120_inl5(u_long128 &r, const u_long128 &s) { asm("vmulw.z %0, %1, %0w" : "+j"(r) : "j"(s)); }
static inline void func_00263120_inl6(u_long128 &r, const u_long128 &s) { asm("vaddw.z %0, %0, %1w" : "+j"(r) : "j"(s)); }

// 0x00263120
void CB3SparkRenderer::CSparkFrameData::Set(const CB3CameraData *cam, float t)
{
    float n = cam->field_18C;
    float f = GtMath::Min(cam->field_19C, 0.012f);
    asm("vsubw.w %0, $vf0, $vf0w" : "+j"(field_30));
    float k = 1.0f / (n - f);
    func_00263120_inl1(field_0, cam->field_E0[0]);
    func_00263120_inl1(field_10, cam->field_E0[1]);
    func_00263120_inl1(field_20, cam->field_E0[2]);
    func_00263120_inl1(field_30, cam->field_E0[3]);
    func_00263120_inl2(field_0, field_30, cam->field_E0[0]);
    func_00263120_inl2(field_10, field_30, cam->field_E0[1]);
    func_00263120_inl2(field_20, field_30, cam->field_E0[2]);
    func_00263120_inl2(field_30, field_30, cam->field_E0[3]);
    CGtV4d s;
    s.f[0] = cam->field_218 / (256.0f + cam->field_218);
    s.f[1] = cam->field_21C / (256.0f + cam->field_21C);
    s.f[2] = k * (n + f);
    s.f[3] = k * (-2.0f * n * f);
    func_00263120_inl3(field_0);
    func_00263120_inl3(field_10);
    func_00263120_inl3(field_20);
    func_00263120_inl3(field_30);
    float x = cam->field_200 / (float)s.X();  // [C] retail FPU form, not a VU lane op: 0x263178.. div.s (the cast keeps the port's PS2 float model)
    float y = cam->field_204 / (float)s.Y();  // [C] retail FPU form, not a VU lane op: 0x263178.. div.s (the cast keeps the port's PS2 float model)
    float z = 0.5f * (cam->field_218 * cam->field_208);
    float w = 0.5f * (cam->field_21C * cam->field_20C);
    func_00263120_inl4(field_0, s.mData);
    func_00263120_inl4(field_10, s.mData);
    func_00263120_inl4(field_20, s.mData);
    func_00263120_inl4(field_30, s.mData);
    func_00263120_inl5(field_30, s.mData);
    func_00263120_inl5(field_0, s.mData);
    func_00263120_inl5(field_10, s.mData);
    func_00263120_inl5(field_20, s.mData);
    func_00263120_inl6(field_30, s.mData);
    CGtV4d *o = (CGtV4d *)&field_40;
    o->SetX(x);
    o->SetY(y);
    o->SetZ(z);
    o->SetA(w);
    field_50.SetX(t);
}
