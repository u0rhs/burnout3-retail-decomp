// NONMATCHING: func_00257230 -- retail 395 / ours 406 instructions, 703 in changed runs
// fix2 (2026-11-01): taskB: no write-back to this+0x1F820 (retail seeds a local CGtRandom {~n, n}, 0x25729C); the three R draws made once before the item loop and used through the 2^23 interpolate with the D_01D9D190 state (vmr32 rotate) as retail 0x2574C0/0x257670; the three pushes straight-line | Before: son5: first-pass archive, logic approximated. Structure [L]: func_0030AAE0 query, VU0 rand seed (vrinit), loop over 0x30-byte items interpolating a 3x4 from two ctx vertices (barycentric u,v + identity), transform by ctx matrix, 3 particle pushes (w 800/400/200, life x1/.5/.25) into emitter table stride 0x34 (cur +0x2C, end +0x30). NOT modelled: exact vrnext/D_01D9D190 LCG draw (vmr32 rotate), VU register pressure (vf12..vf31 hoisted), 0x640 frame
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: seed, the three pre-loop R draws, each push's interpolate (A, B, state rotate), S/W/L constants and the emitter cur/end test traced; behaviour_audit quiet


#include "b3/GtMathPs2.h"
#include "b3/_unclassified/GtRandom.h"
#include "b3/_unclassified/CV3dRandomiser.h"   // taskB: this file's state = retail D_01D9D190 / D_004BBFB0 (as func_00257860)
using namespace GtMathPs2;

extern float D_004E0C6C;
extern float D_004E0F44;
extern float D_004E0F48;
extern float D_004E0F4C;
extern float D_004E0F50;
extern float D_004E0F54;

struct UnkStruct_00257230_out { CGtV3d field_0; float field_10; int field_14; };
extern "C" void func_0030AAE0(void *, void *, int);

struct UnkStruct_00257230_vtx { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; CGtV3d field_30; };
struct UnkStruct_00257230_item {   // [G] stride 0x30
    CGtV3d field_0;
    CGtV3d field_10;
    unsigned char pad_20[4];
    float field_24;
    float field_28;
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char pad_2E[2];
};
// N303 [C asm 0x257334/0x257338]: +0x1684 is a POINTER to the 0x30-byte items, +0x16B4 the count (lbu)
struct UnkStruct_00257230_src { unsigned char pad_0[0x1684]; UnkStruct_00257230_item *field_1684; unsigned char pad_1688[0x16B4 - 0x1688]; unsigned char field_16B4; };
struct UnkStruct_00257230_elem { CGtV3d field_0; CGtV3d field_10; };
struct UnkStruct_00257230_em {   // [G] stride 0x34
    unsigned char pad_0[0x2C];
    UnkStruct_00257230_elem *field_2C;
    UnkStruct_00257230_elem *field_30;
    unsigned char pad_34[0];
};
struct UnkStruct_00257230_ctx {
    CGtMatrix3x4 field_0;
    void *field_40;
    unsigned char pad_44[0x580 - 0x44];
    UnkStruct_00257230_vtx field_580[1];
};

// the VU0 random generator seeded (vrinit), as func_00257860_inl1
static inline void func_00257230_inl2(float seed)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(seed));
    asm volatile("vrinit $R, %0x" : : "j"(s));
}
// taskB: one R draw (vrnext.x); retail draws three before the item loop (0x2574C0..D0) and reuses them for every item
static inline u_long128 func_00257230_inl3()
{
    u_long128 r;
    asm volatile("vrnext.x %0, $R" : "=j"(r));
    return r;
}
// taskB: CV3dRandomiser::RandomInterpolate with an R value drawn earlier: d = floor(state.x * r.x) - state.x * r.x through
// the 2^23 trick, the state rotated one lane (vmr32) and stored back, A + B * d (0x257670..0x2576A8, x3)
static inline CGtV3d func_00257230_inl1(const CGtV3d &a, const CGtV3d &b, u_long128 r)
{
    u_long128 t, d, st, o;
    st = gEffectsRandomiserScales.mData;
    asm("vmulx.x %0, %1, %2x" : "=j"(t) : "j"(st), "j"(r));
    asm("vaddax.x $ACC, %1, %2x" "\n\t" "vmsubaw.x $ACC, %1, $vf0w" "\n\t" "vmsubw.x %0, %2, $vf0w"
        : "=j"(d) : "j"(kEffectsRandomiser2E23.mData), "j"(t));
    asm("vmr32.xyzw %0, %1" : "=j"(st) : "j"(st));
    gEffectsRandomiserScales.mData = st;
    asm("vaddax.xyz $ACC, %1, $vf0x" "\n\t" "vmaddx.xyz %0, %2, %3x" : "=j"(o) : "j"(a.mData), "j"(b.mData), "j"(d));
    return CGtV3d(o);
}

class CB3TrafficEffects {   // [G] placeholder owner of the emitter table
public:
    void func_00257230(UnkStruct_00257230_ctx *p);
};

// 0x00257230
extern "C" void func_00257230(CB3TrafficEffects *self, UnkStruct_00257230_ctx *p)
{
    UnkStruct_00257230_out out;
    func_0030AAE0((char *)p + 0x118C, &out, *((unsigned char *)p + 0x18F1));
    if (!(out.field_10 > D_004E0C6C)) return;
    CGtV3d e0, e1, e2, e3;
    e0.Set(1.0f, 0.0f, 0.0f);
    e1.Set(0.0f, 1.0f, 0.0f);
    e2.Set(0.0f, 0.0f, 1.0f);
    e3.Zero();
    // taskB: retail seeds from a local CGtRandom {~n, n} with n = this+0x1F820 (read only; 0x25729C..0x257340 writes the
    // stepped pair to the stack, never back) [C]; the archive used to store the stepped value into +0x1F820
    CGtRandom lRandom;
    unsigned int n0 = *(unsigned int *)((char *)self + 0x1F820);
    lRandom.mnHigh = ~n0;
    lRandom.mnLow = n0;
    func_00257230_inl2(lRandom.RandomReal());
    UnkStruct_00257230_src *src = *(UnkStruct_00257230_src **)((char *)p + 0x40);
    UnkStruct_00257230_item *it = src->field_1684;
    unsigned char n = src->field_16B4;
    CGtV3d base = out.field_0;
    CGtV3d base2 = base - base * 0.5f;
    CGtV3d r1 = base * D_004E0F44;
    CGtV3d b1 = r1 - base * D_004E0F48;
    CGtV3d r2 = base * D_004E0F48;
    CGtV3d b2 = r2 - base * D_004E0F4C;
    UnkStruct_00257230_em *em = (UnkStruct_00257230_em *)self + out.field_14;
    u_long128 rnd0 = func_00257230_inl3();
    u_long128 rnd1 = func_00257230_inl3();
    u_long128 rnd2 = func_00257230_inl3();
    while (n != 0) {
        float u = it->field_24;
        float v = it->field_28;
        float w = 1.0f - (u + v);
        UnkStruct_00257230_vtx *va = &p->field_580[it->field_2C];
        UnkStruct_00257230_vtx *vb = &p->field_580[it->field_2D];
        CGtMatrix3x4 M;
        M.mRight = va->field_0 * u + vb->field_0 * v + e0 * w;
        M.mUp = va->field_10 * u + vb->field_10 * v + e1 * w;
        ((float *)&M.mUp)[3] = ((const float *)&vb->field_10)[3]; // [C] 0x257590 lqc2 vf7, 0x590(t3) (vb's row 1); 0x257598 vmulx.xyz
        // vf7, vf7; 0x25759C vadd.xyz vf7, vf9, vf7 / 0x2575A0 vadd.xyz vf7, vf7, vf11 keep its w; 0x2575C8 sqc2 vf7, 0x4E0(sp) -- the port's
        // `... + e1 * w` took e1's w. (M.mPos at 0x2575F8 keeps the 0xA0(sp) copy of e3, = e3.w, which the port's form also gives.)
        M.mAt = va->field_20 * u + vb->field_20 * v + e2 * w;
        M.mPos = va->field_30 * u + vb->field_30 * v + e3 * w;
        CGtV3d pos = TransformPoint(p->field_0, TransformPoint(M, it->field_0));
        CGtV3d dir = TransformVector(p->field_0, TransformVector(M, it->field_10));
        // taskB: the three pushes straight-line as retail (0x257670 / 0x2576FC / 0x257788): position + dir * S (w = W),
        // velocity = randomised range * 64 (w = out.field_10 * L)
        UnkStruct_00257230_elem *e;
        CGtV3d vel = func_00257230_inl1(base, base2, rnd0);
        e = em->field_2C;
        if (e != em->field_30) {
            e->field_0 = pos + dir * D_004E0F50;
            ((float *)&e->field_0)[3] = 800.0f;
            e->field_10 = vel * 64.0f;
            ((float *)&e->field_10)[3] = out.field_10;
            em->field_2C = e + 1;
        }
        vel = func_00257230_inl1(r1, b1, rnd1);
        e = em->field_2C;
        if (e != em->field_30) {
            e->field_0 = pos + dir * D_004E0F4C;
            ((float *)&e->field_0)[3] = 400.0f;
            e->field_10 = vel * 64.0f;
            ((float *)&e->field_10)[3] = 0.5f * out.field_10;
            em->field_2C = e + 1;
        }
        vel = func_00257230_inl1(r2, b2, rnd2);
        e = em->field_2C;
        if (e != em->field_30) {
            e->field_0 = pos + dir * D_004E0F54;
            ((float *)&e->field_0)[3] = 200.0f;
            e->field_10 = vel * 64.0f;
            ((float *)&e->field_10)[3] = 0.25f * out.field_10;
            em->field_2C = e + 1;
        }
        it++;
        n--;
    }
}
