// NONMATCHING: DispatchArray__19CB3ParticleRendererFPQ219CB3ParticleRenderer24CB3ParticleRendererEntry -- retail 142 / ours 142 instructions, 95 in changed runs
// v257: logic complete (static member, a0 = entry; 21-quad GIF block per particle sub-array + optional tail quad, entry-jump goto loop, 3-row rotate of field_50, FOV-scaled field_80 with z clamped by Max(.., mrMinNearClip)); 142/142, 95 changed: GPR/quad register assignment (arr t7 / p t3 / i t8 / z t9 in retail), loc's GPR round trip (vmove.w then SetGtV3d), scale on compiler-chosen VU regs, frame 0x70 vs 0xE0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (v257); the lifter refused it. CB3ParticleRenderer::DispatchArray(CB3ParticleRendererEntry*): a static
// member (a0 is the entry), defined under its mangled name. Types and fields are placeholders [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
struct UnkStruct_00254340_s { unsigned char pad_0[0x8]; unsigned int field_8; unsigned int field_C; unsigned char pad_10[6]; unsigned char field_16; unsigned char pad_17[1]; unsigned int field_18; unsigned int field_1C; unsigned int field_20; unsigned int field_24; };
struct UnkStruct_00254340_tex {
    unsigned char pad_0[0x34];
    UnkStruct_00254340_s field_34;
};
struct UnkStruct_00254340_arr {
    u_long128 field_0[5];
    CGtV4d field_50;
    u_long128 field_60;
    union { u_long128 field_70; struct { float pad_70; float field_74; } f; };
    CGtV4d field_80;
    u_long128 field_90[4];
    u_long128 field_D0;
    UnkStruct_00254340_tex * field_E0;
};
struct UnkStruct_00254340_p { unsigned int field_0; unsigned int field_4; unsigned char pad_8[0x1C]; float field_24; };
struct UnkStruct_00254340_e { UnkStruct_00254340_arr * field_0; UnkStruct_00254340_p * field_4[2]; unsigned int field_C; };
struct UnkStruct_farFogPlane { u_long128 * field_0; };
extern UnkStruct_farFogPlane farFogPlane;
extern CGtV3d D_01D9CFD0, D_01D9CFE0, D_01D9CFF0;
extern "C" float mrFOVScale__19CB3ParticleRenderer;
extern "C" float mrMinNearClip__19CB3ParticleRenderer;
static inline u_long128 func_00254340_q(unsigned long lo, unsigned long hi) { u_long128 q; asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(lo), "r"(hi)); return q; }
// [L] N185 stand-ins (compiler-chosen VU registers)
static inline CGtV3d func_00254340_inl1(const CGtV3d &r0, const CGtV3d &r1, const CGtV3d &r2, const CGtV4d &v)
{
    u_long128 t;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %2y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddz.xyz $vf1, $vf1, %2z" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(r0.mData), "j"(v.mData), "r"(r1.mData), "r"(r2.mData));
    return CGtV3d(t);
}
static inline CGtV4d func_00254340_inl2(const CGtV4d &v, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s)); return CGtV4d(t); }
static inline void func_00254340_inl3(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00254340_inl4(CGtV3dPlus &d, const CGtV4d &s) { asm("vmove.w %0, %1" : "+j"(d.mData) : "j"(s.mData)); }

// 0x00254340
extern "C" void DispatchArray__19CB3ParticleRendererFPQ219CB3ParticleRenderer24CB3ParticleRendererEntry(UnkStruct_00254340_e * e)
{
    UnkStruct_00254340_arr * arr = e->field_0;
    UnkStruct_00254340_tex * tex = arr->field_E0;
    u_long128 q6 = func_00254340_q(tex->field_34.field_8 | ((unsigned long)tex->field_34.field_C << 32), 6);
    unsigned long a = 0, b = 0;
    UnkStruct_00254340_s * s = &tex->field_34;
    if ((s->field_16 >> 2) > 0) {
        a = s->field_18 | ((unsigned long)s->field_1C << 32);
        b = s->field_20 | ((unsigned long)s->field_24 << 32);
    }
    u_long128 q5 = func_00254340_q(a, 0x34);
    u_long128 q4 = func_00254340_q(b, 0x36);
    CGtV3dPlus loc;
    func_00254340_inl4(loc, arr->field_50);
    loc.SetGtV3d(func_00254340_inl1(D_01D9CFD0, D_01D9CFE0, D_01D9CFF0, arr->field_50));
    CGtV4d sc = func_00254340_inl2(arr->field_80, mrFOVScale__19CB3ParticleRenderer);
    func_00254340_inl3(sc, GtMath::Max(sc.Z(), mrMinNearClip__19CB3ParticleRenderer));
    unsigned long z = 0;
    unsigned int i = 0;
    u_long128 q1 = func_00254340_q(0x10000011, 0x6C1103E801000101UL);
    u_long128 q0 = func_00254340_q(0x10000000, 0x17000000);
    u_long128 q2 = func_00254340_q(0x10000000, 0x10000000);
    u_long128 * p = farFogPlane.field_0;
    goto test;
body:
    {
        UnkStruct_00254340_p * pp = e->field_4[i];
        p[0] = func_00254340_q(((unsigned long)pp->field_0 << 32) | 0x50000000, z);
        p[1] = q2;
        arr->f.field_74 = pp->field_24;
        p[2] = q1;
        p[3] = arr->field_0[0];
        p[4] = arr->field_0[1];
        p[5] = arr->field_0[2];
        p[6] = arr->field_0[3];
        p[7] = arr->field_0[4];
        p[8] = loc.mData;
        p[9] = arr->field_60;
        p[10] = arr->field_70;
        p[11] = sc.mData;
        p[12] = arr->field_90[0];
        p[13] = arr->field_90[1];
        p[14] = arr->field_90[2];
        p[15] = arr->field_90[3];
        p[16] = q6;
        p[17] = arr->field_D0;
        p[18] = q5;
        p[19] = q4;
        p[20] = q0;
        unsigned int n = pp->field_4;
        p += 21;
        if (n) {
            *p = func_00254340_q(((unsigned long)n << 32) | 0x50000000, z);
            p++;
        }
    }
    i++;
test:
    if (i < e->field_C) goto body;
    farFogPlane.field_0 = p;
}
