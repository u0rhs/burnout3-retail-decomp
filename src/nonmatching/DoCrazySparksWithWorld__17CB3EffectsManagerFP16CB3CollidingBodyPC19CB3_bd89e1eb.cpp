// NONMATCHING: DoCrazySparksWithWorld__17CB3EffectsManagerFP16CB3CollidingBodyPC19CB3SparkSpawnParams -- retail 489 / ours 559 instructions, 798 in changed runs
// fix3 (2026-11-01): rewritten from the retail asm (TRACK clean): speed = sqrt, contact velocity D0 x d (was d x D0), body pad_216 0xAAA (field_CC0 was at 0x2C0), y offset = c160.y - CC0+0x30.y + CC4+0x490.w, edge corners per face from jtbl_004BC920 (draft guessed), both corners lerped 0.2 (D_004E0E00, not D_004E1000), weight = (Rc170 . -plane)^4 (was bd^4), far corner + reversed edge when facing away, player 0x20 flag at-row offset; abs.s via GtMath::Abs | Before: son8: first archive, scalar-float approximation of a VU-heavy body. Right: _gaSurfaceEffects[body+0x190].field_D gate, speed-ramp (params 0..3 x this+0x1F84C), state 1..3 y offset, 6-face pick (planes at this+0x1F7A0, |min/max| table, 1000.0 init), final func_0025D930(rate,y,this,&pos,&normal,&vel,body+0x210). Unsolved: retail uses explicit VU (vopmula cross, ACC dots), the lerp constant at gp 0x8790 and the box-corner switch bodies only approximated; frame 0xB90 (big VU temp buffers) vs ours 0x140
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: clean
// EQUIV: [L] fix3: rewritten from the retail asm, every VU op, branch and the jump table mapped



#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_00255EE0_v { float x, y, z, w; };
struct UnkStruct_00255EE0_m { UnkStruct_00255EE0_v r0, r1, r2, pos; };
struct UnkStruct_00255EE0_se { unsigned char pad_0[0xD]; unsigned char field_D; unsigned char pad_E[2]; };
struct UnkStruct_00255EE0_sp { float field_0; float field_4; float field_8; float field_C; };
struct UnkStruct_00255EE0_ob { unsigned char pad_0[0xC]; };
struct UnkStruct_00255EE0_cc0 { unsigned char pad_0[0x30]; UnkStruct_00255EE0_v field_30; };     // [C] lqc2 0x30(field_CC0), y lane (0x25665C)
struct UnkStruct_00255EE0_cc4 { unsigned char pad_0[0x490]; UnkStruct_00255EE0_v field_490; };   // [C] lqc2 0x490(field_CC4), w lane (0x256660)
struct UnkStruct_00255EE0_pl { unsigned char pad_0[0x27C0]; int field_27C0; };                   // [C] lw 0x27C0(field_1580): player index
struct UnkStruct_00255EE0_e3 { unsigned long field_0; unsigned char pad_8[0xBA8]; };              // [C] D_005179C0[], stride 0xBB0, 64-bit flags
struct UnkStruct_00255EE0_b {
    unsigned char pad_0[0x70];
    UnkStruct_00255EE0_m field_70;
    UnkStruct_00255EE0_v field_B0;
    unsigned char pad_C0[0x10];
    UnkStruct_00255EE0_v field_D0;
    unsigned char pad_E0[0x80];
    UnkStruct_00255EE0_v field_160;
    UnkStruct_00255EE0_v field_170;
    unsigned char pad_180[0x10];
    unsigned char field_190;
    unsigned char pad_191[0x3F];
    UnkStruct_00255EE0_v field_1D0;
    UnkStruct_00255EE0_v field_1E0;
    unsigned char pad_1F0[0x14];
    UnkStruct_00255EE0_m *field_204;
    unsigned char pad_208[8];
    unsigned char field_210;
    unsigned char pad_211[4];
    signed char field_215;
    unsigned char pad_216[0xAAA];              // fix3: was [0xAA] (field_CC0 landed at 0x2C0)
    UnkStruct_00255EE0_cc0 *field_CC0;
    UnkStruct_00255EE0_cc4 *field_CC4;
    unsigned char pad_CC8[0x1580 - 0xCC8];
    UnkStruct_00255EE0_pl *field_1580;
};
struct UnkStruct_00255EE0_em {
    unsigned char pad_0[0x1F7A0];
    UnkStruct_00255EE0_v field_1F7A0[6];
    unsigned char pad_1F800[0x4C - 0x40];
};
struct UnkStruct_00255EE0_f { unsigned char pad_0[0x1F84C]; float field_1F84C; };

extern UnkStruct_00255EE0_se _gaSurfaceEffects[];
extern UnkStruct_00255EE0_e3 D_005179C0[];
extern "C" void func_0025D930(float, float, void *, UnkStruct_00255EE0_v *, UnkStruct_00255EE0_v *, UnkStruct_00255EE0_v *, unsigned char);
extern "C" float sqrtf(float);
extern float D_004E0E00;   // [C] 0.2 (0x3E4CCCCD), lwc1 gp at 0x2564B8

static inline float func_00255EE0_inl1(const UnkStruct_00255EE0_v &a, const UnkStruct_00255EE0_v &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
// point transform (rows + pos)
static inline UnkStruct_00255EE0_v func_00255EE0_inl2(const UnkStruct_00255EE0_m &m, const UnkStruct_00255EE0_v &v)
{
    UnkStruct_00255EE0_v r;
    r.x = m.r0.x * v.x + m.r1.x * v.y + m.r2.x * v.z + m.pos.x;
    r.y = m.r0.y * v.x + m.r1.y * v.y + m.r2.y * v.z + m.pos.y;
    r.z = m.r0.z * v.x + m.r1.z * v.y + m.r2.z * v.z + m.pos.z;
    r.w = 0.0f;
    return r;
}
// direction transform (rows only) [C] 0x256270: vmulax/vmadday/vmaddz, no w term
static inline UnkStruct_00255EE0_v func_00255EE0_inl3(const UnkStruct_00255EE0_m &m, const UnkStruct_00255EE0_v &v)
{
    UnkStruct_00255EE0_v r;
    r.x = m.r0.x * v.x + m.r1.x * v.y + m.r2.x * v.z;
    r.y = m.r0.y * v.x + m.r1.y * v.y + m.r2.y * v.z;
    r.z = m.r0.z * v.x + m.r1.z * v.y + m.r2.z * v.z;
    r.w = 0.0f;
    return r;
}
static inline UnkStruct_00255EE0_v func_00255EE0_inl4(float x, float y, float z)
{
    UnkStruct_00255EE0_v r;
    r.x = x; r.y = y; r.z = z; r.w = 0.0f;
    return r;
}

// fix3 (2026-11-01): rewritten from the retail asm (0x255EE0..0x256680) in scalar floats; every VU op mapped. [L] reading: a
// spark spawn at the body's contact point (field_160) against the world box face nearest the contact: the contact
// velocity (B0 + D0 x lever arm), a speed ramp, the box face (6 planes at this+0x1F7A0) that the local contact point is
// closest to, the face's edge segment (two box corners) pulled 20% toward the body centre, then func_0025D930.
extern "C" void DoCrazySparksWithWorld__17CB3EffectsManagerFP16CB3CollidingBodyPC19CB3SparkSpawnParams(UnkStruct_00255EE0_f *self, UnkStruct_00255EE0_b *body, const UnkStruct_00255EE0_sp *p)
{
    UnkStruct_00255EE0_m *m = body->field_204;
    UnkStruct_00255EE0_v c160 = body->field_160;
    UnkStruct_00255EE0_v c170 = body->field_170;
    UnkStruct_00255EE0_v mpos = m->pos;
    UnkStruct_00255EE0_v d = func_00255EE0_inl4(c160.x - mpos.x, c160.y - mpos.y, c160.z - mpos.z);
    const UnkStruct_00255EE0_v &w = body->field_D0;
    // [C] 0x255F34 vopmula.xyz ACC, D0, d; vopmsub.xyz: D0 x d (the draft had d x D0)
    UnkStruct_00255EE0_v vel;
    vel.x = (w.y * d.z - w.z * d.y) + body->field_B0.x;
    vel.y = (w.z * d.x - w.x * d.z) + body->field_B0.y;
    vel.z = (w.x * d.y - w.y * d.x) + body->field_B0.z;
    vel.w = mpos.w;                            // [C] the lane retail keeps (vsub.xyz into the register holding m->pos)
    float speed = sqrtf(vel.x * vel.x + vel.y * vel.y + vel.z * vel.z);   // [C] 0x255F70 vsqrt
    unsigned char kind = body->field_210;
    if (_gaSurfaceEffects[body->field_190].field_D == 0) return;
    float k = self->field_1F84C;
    float rate;
    if (speed <= p->field_0) {
        rate = 0.0f;
    } else if (!(speed < p->field_4)) {
        rate = p->field_C * k;
    } else {
        float t = (speed - p->field_0) / (p->field_4 - p->field_0);
        rate = k * (0.0f + p->field_8 + (p->field_C - p->field_8) * t);
    }
    float y = 0.0f;
    if (rate <= 0.0f) return;
    int st = body->field_215;
    if (st == 3 || st == 2 || st == 1) {
        // [C] 0x25664C: vsuby.y + vaddw.y (the draft read field_CC0->field_204->pos.y at the wrong offset)
        y = (c160.y - body->field_CC0->field_30.y) + body->field_CC4->field_490.w;
    }
    UnkStruct_00255EE0_v mn = body->field_1D0;
    UnkStruct_00255EE0_v mx = body->field_1E0;
    UnkStruct_00255EE0_v lp = func_00255EE0_inl2(body->field_70, c160);
    UnkStruct_00255EE0_em *em = (UnkStruct_00255EE0_em *)self;
    float e[6];
    float a[6];
    for (int i = 0; i < 6; i++) e[i] = func_00255EE0_inl1(lp, em->field_1F7A0[i]);
    a[0] = GtMath::Abs(mx.x);
    a[1] = GtMath::Abs(mn.x);
    a[2] = GtMath::Abs(mn.y);
    a[3] = GtMath::Abs(mx.y);
    a[4] = GtMath::Abs(mn.z);
    a[5] = GtMath::Abs(mx.z);
    int best = 0;
    float bd = 1000.0f;
    for (int i = 0; i < 6; i++) {
        if (!(e[i] <= 0.0f)) {
            float t = e[i] - a[i];
            t = GtMath::Abs(t);
            if (t < bd) { bd = t; best = i; }
        }
    }
    // [C] 0x256260..0x2562C0: the contact normal (rotated, no translation) against the chosen face's reversed plane
    UnkStruct_00255EE0_v rd = func_00255EE0_inl3(body->field_70, c170);
    const UnkStruct_00255EE0_v &pl = em->field_1F7A0[best];
    float f = rd.x * -pl.x + rd.y * -pl.y + rd.z * -pl.z;
    // [C] jtbl_004BC920: the face's edge, two corners in the body box (lp = the local contact point)
    UnkStruct_00255EE0_v ca;
    UnkStruct_00255EE0_v cb;
    switch (best) {
    case 0: ca = func_00255EE0_inl4(mx.x, lp.y, mx.z); cb = func_00255EE0_inl4(mx.x, lp.y, mn.z); break;
    case 1: ca = func_00255EE0_inl4(mn.x, lp.y, mx.z); cb = func_00255EE0_inl4(mn.x, lp.y, mn.z); break;
    case 2: ca = func_00255EE0_inl4(lp.x, mn.y, mx.z); cb = func_00255EE0_inl4(lp.x, mn.y, mn.z); break;
    case 3: ca = func_00255EE0_inl4(lp.x, mx.y, mx.z); cb = func_00255EE0_inl4(lp.x, mx.y, mn.z); break;
    case 4: ca = func_00255EE0_inl4(mx.x, lp.y, mn.z); cb = func_00255EE0_inl4(mn.x, lp.y, mn.z); break;
    default: ca = func_00255EE0_inl4(mx.x, lp.y, mx.z); cb = func_00255EE0_inl4(mn.x, lp.y, mx.z); break;
    }
    m = body->field_204;
    UnkStruct_00255EE0_v wa = func_00255EE0_inl2(*m, ca);
    UnkStruct_00255EE0_v wb = func_00255EE0_inl2(*m, cb);
    float h = f * f;
    h = h * h;
    float r = D_004E0E00;
    // [C] 0x2564D4..0x2564F0: both corners pulled toward the body centre
    wa = func_00255EE0_inl4(wa.x + (mpos.x - wa.x) * r, wa.y + (mpos.y - wa.y) * r, wa.z + (mpos.z - wa.z) * r);
    wb = func_00255EE0_inl4(wb.x + (mpos.x - wb.x) * r, wb.y + (mpos.y - wb.y) * r, wb.z + (mpos.z - wb.z) * r);
    UnkStruct_00255EE0_v nrm = func_00255EE0_inl4((wb.x - wa.x) * h, (wb.y - wa.y) * h, (wb.z - wa.z) * h);
    UnkStruct_00255EE0_v out;
    if (!(func_00255EE0_inl1(nrm, c170) <= 0.0f)) {
        out = wa;
    } else {
        out = wb;                              // [C] 0x256550: the far corner, the edge reversed
        nrm = func_00255EE0_inl4(-nrm.x, -nrm.y, -nrm.z);
    }
    if (body->field_215 == 1) {
        // [C] 0x25656C: player flag 0x20 and the point in front (local z > 0): one at-row back
        if (D_005179C0[body->field_1580->field_27C0].field_0 & 0x20) {
            UnkStruct_00255EE0_v l = func_00255EE0_inl2(body->field_70, out);
            if (!(l.z <= 0.0f)) {
                const UnkStruct_00255EE0_v &at = body->field_204->r2;
                out = func_00255EE0_inl4(out.x + at.x * -1.0f, out.y + at.y * -1.0f, out.z + at.z * -1.0f);
            }
        }
    }
    func_0025D930(rate, y, self, &out, &nrm, &vel, kind);
}
