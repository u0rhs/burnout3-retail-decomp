// NONMATCHING: func_00354460 -- retail 192 / ours 185 instructions, 224 in changed runs
// a193: first hand source, logic decoded from asm (scratchpad 0x70002000 records {pos,vel,r^2,t,..}; swept-sphere pair test: dv=b.vel-a.vel, normalise, t=dot/len, perp^2=|dp|^2-dot^2, score=1-perp^2/(ra+rb)). All five 1.0s hoisted by b119p as retail (vf3,9,2,8,7). Left: 185 vs 192 instrs, 224 changed: rec base 0x70002000 rematerialised per use (retail keeps it in v1), VU reg numbering, retail Normalise/GetLength scheduling with c1 sqrt, gpr round trips; 'perp' path A (|dv|^2<2^-32) may be dead-code-ish in retail
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00354460_q { unsigned char pad_0[0xB0]; u_long128 field_B0; unsigned char pad_C0[0x144]; unsigned char* field_204; unsigned char pad_208[0xD]; signed char field_215; };
struct UnkStruct_00354460_e {
    u_long128 field_0;   // [G] sphere: xyz position, w radius
    unsigned char pad_10[0x30];
    float pad_40f[1];
};
struct UnkStruct_00354460_r {
    u_long128 field_0; u_long128 field_10; float field_20; float field_24; float field_28; int field_2C; UnkStruct_00354460_e* field_30;
    unsigned char pad_34[0xC];
};
struct UnkStruct_00354460_c { u_long128 field_0; unsigned char pad_10[0x34]; int field_44; unsigned char pad_48[8]; float field_50; float field_54; unsigned char pad_58[8]; UnkStruct_00354460_q* field_40x; };
struct UnkStruct_00354460_s { unsigned char pad_0[0x2E0]; unsigned char field_2E0[0xD0 * 0 + 0x1030 - 0x2E0]; int field_1030; };

static inline XAxisType func_00354460_dot(CGtV3d a, CGtV3d b)
{
    u_long128 d, m, one;
    asm("vmul.xyz $vf1, %1, %2" "\n\t" "vadday.x $ACC, $vf1, $vf1y" : "=j"(m) : "j"(a.mData), "j"(b.mData));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm("vmaddz.x $vf1, %2, $vf1z" "\n\t" "qmfc2.ni %0, $vf1" : "=r"(d) : "j"(m), "j"(one));
    return XAxisType(d);
}
static inline float func_00354460_sqrt(float x) { float r; asm("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

// 0x00354460
extern "C" void func_00354460(UnkStruct_00354460_s* self)
{
    UnkStruct_00354460_r* rec = (UnkStruct_00354460_r*)0x70002000;
    int k = 0;
    for (int i = 0; i < self->field_1030; i++) {
        unsigned char* e = (unsigned char*)self + i * 0x70 + 0x2E0;
        UnkStruct_00354460_q* q = *(UnkStruct_00354460_q**)(e + 0x40);
        int t = q->field_215;
        if (t == 1 || t == 2 || t == 3 || t == 4) {
            UnkStruct_00354460_r* r = &rec[k++];
            r->field_0 = q->field_B0;
            r->field_10 = *(u_long128*)(*(unsigned char**)(*(unsigned char**)(e + 0x40) + 0x204) + 0x30);
            CGtV4d s;
            s.mData = *(u_long128*)e;
            r->field_20 = s.f[3] * s.f[3];
            r->field_24 = 0.0f;
            r->field_28 = 0.0f;
            r->field_2C = 0;
            r->field_30 = (UnkStruct_00354460_e*)e;
        } else {
            *(float*)(e + 0x50) = 0.0f;
            *(float*)(e + 0x54) = 0.0f;
            *(int*)(e + 0x44) = 0;
        }
    }
    for (int i = 0; i < k; i++) {
        UnkStruct_00354460_r* a = &rec[i];
        for (int j = i + 1; j < self->field_1030; j++) {
            UnkStruct_00354460_r* b = &rec[j];
            CGtV3d dp = CGtV3d(a->field_10) - CGtV3d(b->field_10);
            CGtV3d dv = CGtV3d(b->field_0) - CGtV3d(a->field_0);
            float t;
            float perp;
            if (func_00354460_dot(dv, dv) < 2.3283064e-10f) {
                perp = func_00354460_dot(dp, dp);
                t = -1.0f;
            } else {
                float len = func_00354460_sqrt(dv.GetSquaredLength());
                dv.Normalise();
                float c = func_00354460_dot(dv, dp);
                float dd = func_00354460_dot(dp, dp);
                t = c / len;
                perp = dd - c * c;
            }
            if (t <= 0.0f) continue;
            float rs = a->field_20 + b->field_20;
            if (!(perp < rs)) continue;
            float f = 1.0f - perp / rs;
            if (!(f <= a->field_24)) {
                a->field_24 = f; a->field_28 = t; a->field_2C = (int)b->field_30;
            }
            if (!(f <= b->field_24)) {
                b->field_24 = f; b->field_28 = t; b->field_2C = (int)a->field_30;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        UnkStruct_00354460_r* r = &rec[i];
        unsigned char* q = (unsigned char*)r->field_30;
        *(float*)(q + 0x50) = r->field_24;
        *(float*)(q + 0x54) = r->field_28;
        *(int*)(q + 0x44) = r->field_2C;
    }
}
