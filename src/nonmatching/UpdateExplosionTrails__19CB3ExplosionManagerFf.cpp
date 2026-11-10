// NONMATCHING: UpdateExplosionTrails__19CB3ExplosionManagerFf -- retail 122 / ours 122 instructions, 20 in changed runs
// ghvu6: 122/122, 20 off. VU sequence exact (hard-coded vf1/vf2 operator*(float) stand-in, compiler-chosen vadd/vsub stand-ins, static init as explicit guard). Left: frame 0xD0 vs 0xE0 -- retail has 2 dead 16-byte slots BELOW the static-init ctor temp (0x60/0x70); pads always land at the top; the gravity lqc2 is scheduled after the sq of t->pos (retail before) even with a const static; lui a0 / sd t3 order in the call setup
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [G] trail record, stride 0x30 (retail addiu s1,s1,0x30; 5 entries at this+0)
struct UnkStruct_00399C30_T {
    CGtV3d field_0;
    CGtV3d field_10;
    float field_20;
    unsigned char pad_24[0xC];
};
class CB3ExplosionManager {
public:
    void UpdateExplosionTrails(float dt);
    UnkStruct_00399C30_T field_0[5];
};
extern char D_004E2E8C;            // [G] guard byte of a function-local static (gp, lb/sb 1)
extern const CGtV3d D_004C9A10;          // [G] the static vector (0, -9.8, 0)
extern unsigned char D_004E2E90[3]; // [G] per-pass byte (gp + i)
extern int D_004A5208[];
extern char D_01D9D200[];          // [L] CB3EffectsManager instance (func_0019A550)
struct UnkStruct_00399C30_V2 { float x, y; };
extern "C" void func_0025F0C0(void *mgr, const void *a, const void *b, const void *c, int k, const void *uv,
                              unsigned char *p, int f8, float len, float s0, float s1, int f9);


// [L] N185: stands in for GtMathPs2 operator+/operator- with compiler-chosen registers (retail vadd.xyz vf2,vf3,vf1 / vsub.xyz vf1,vf2,vf3)
static inline CGtV3d func_00399C30_inl1(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_00399C30_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185: stands in for the hard-coded CGtV3d::operator*(float) body (v288: qmtc2 v,$vf1; qmtc2.ni s,$vf2; vmulx.xyz $vf1,$vf1,$vf2x)
static inline CGtV3d func_00399C30_inl3(const CGtV3d &v, float s) { u_long128 t; asm("qmtc2 %1, $vf1" "\n\t" "qmtc2.ni %2, $vf2" "\n\t" "vmulx.xyz $vf1, $vf1, $vf2x" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(v.mData), "r"(s)); return CGtV3d(t); }
// N140: unused 16-byte frame-slot pads (retail frame 0xE0)
struct UnkStruct_00399C30_pad { int x[4]; UnkStruct_00399C30_pad() {} ~UnkStruct_00399C30_pad() {} };
struct UnkStruct_00399C30_pad8 { int x[3]; UnkStruct_00399C30_pad8() {} ~UnkStruct_00399C30_pad8() {} };
// 0x00399C30
void CB3ExplosionManager::UpdateExplosionTrails(float dt)
{
    if (D_004E2E8C == 0) {
        *(CGtV3d *)&D_004C9A10 = CGtV3d(0.0f, -9.8f, 0.0f);   // [G] const static written by its guarded init
        D_004E2E8C = 1;
    }
    UnkStruct_00399C30_V2 uv;
    uv.x = 0.0f;
    uv.y = 1.0f;
    UnkStruct_00399C30_pad8 p8;
    int n;
    UnkStruct_00399C30_T *t;
    for (n = 0, t = field_0; n < 5; n++, t++) {
        if (t->field_20 > 0.0f) {
            CGtV3d old = t->field_0;
            CGtV3d np = func_00399C30_inl1(old, func_00399C30_inl3(t->field_10, dt));
            UnkStruct_00399C30_pad pc, pd;
            float len = func_00399C30_inl2(np, old).GetLength();
            float s;
            if (t->field_20 > 0.8f) s = 1.0f;
            else s = t->field_20 * 1.25f;
            for (int i = 0; i < 3; i++)
                func_0025F0C0(D_01D9D200, &np, &old, &t->field_10, D_004A5208[i], &uv, &D_004E2E90[i], 1, len, s, s, 1);
            t->field_0 = np;
            t->field_10 += func_00399C30_inl3(D_004C9A10, dt);
            t->field_20 -= dt;
        }
    }
}
