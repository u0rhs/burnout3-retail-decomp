// NONMATCHING: func_00257080 -- retail 106 / ours 99 instructions, 83 in changed runs
// near38: by-value copies of p3/p4/p5 (CGtV3d c5/c4/c3 = ...), the add-entry block as a static inline taking the (p*d) product as an argument (retail computes p*d before the cursor test), cursor re-read for ++: 106/99 instrs, 83 changed (was 106/89, 89). Left: frame 0x130 vs 0x60 (retail has dead slots 0x00-0xA0, res spilled to 0xF0 and reloaded on the z<0 path, v stored from VU with sqc2), p3/p4 qmtc2.ni'd from the lq GPRs while p5 is lqc2 from its stack copy, VU numbering (rows vf12/10/9/8, p5 vf7, ones vf6/vf5, 64 vf2)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00257080_out { u_long128 field_0; u_long128 field_10; };
class UnkStruct_00257080_a0 {
public:
    unsigned char pad_0[0x2C];
    UnkStruct_00257080_out* field_2C;
    UnkStruct_00257080_out* field_30;
};
struct UnkStruct_00257080_elem { u_long128 field_0; u_long128 field_10; u_long128 field_20; };
struct UnkStruct_00257080_set { unsigned char pad_0[0x1664]; UnkStruct_00257080_elem* field_1664[4]; unsigned char pad_1674[0x38]; unsigned char field_16AC[4]; };
struct UnkStruct_00257080_s { unsigned char pad_0[0x40]; UnkStruct_00257080_set* field_40; };
struct UnkStruct_00257080_m { u_long128 r0, r1, r2, r3; };

static inline XAxisType func_00257080_dot(CGtV3d a, CGtV3d b)
{
    u_long128 d, m, one;
    asm("vmul.xyz $vf1, %1, %2" "\n\t" "vadday.x $ACC, $vf1, $vf1y" : "=j"(m) : "j"(a.mData), "j"(b.mData));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm("vmaddz.x $vf1, %2, $vf1z" "\n\t" "qmfc2.ni %0, $vf1" : "=r"(d) : "j"(m), "j"(one));
    return XAxisType(d);
}
static inline u_long128 func_00257080_xf(const UnkStruct_00257080_m* m, u_long128 v)
{
    u_long128 r;
    asm("vmulax.xyz $ACC, %1, %5x" "\n\t" "vmadday.xyz $ACC, %2, %5y" "\n\t" "vmaddaz.xyz $ACC, %3, %5z" "\n\t" "vmaddw.xyz $vf1, %4, $vf0w" "\n\t" "qmfc2.ni %0, $vf1"
        : "=r"(r) : "j"(m->r0), "j"(m->r1), "j"(m->r2), "j"(m->r3), "j"(v));
    return r;
}
static inline u_long128 func_00257080_mul1(u_long128 p, float d)
{
    u_long128 t;
    asm("qmtc2.ni %2, $vf1" "\n\t" "vmulx.xyz $vf1, %1, $vf1x" "\n\t" "qmfc2.ni %0, $vf1" : "=r"(t) : "j"(p), "r"(d));
    return t;
}
static inline u_long128 func_00257080_mul2(u_long128 t, u_long128 k)
{
    u_long128 u;
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulx.xyz $vf1, $vf1, %2x" "\n\t" "qmfc2.ni %0, $vf1" : "=r"(u) : "r"(t), "j"(k));
    return u;
}
static inline void func_00257080_inl1(UnkStruct_00257080_a0* self, const u_long128 &pos, u_long128 col, float f, u_long128 k)
{
    if (self->field_2C != self->field_30) {
        UnkStruct_00257080_out* o = self->field_2C;
        o->field_0 = pos; ((float*)&o->field_0)[3] = 400.0f;
        o->field_10 = func_00257080_mul2(col, k); ((float*)&o->field_10)[3] = f;
        self->field_2C++;
    }
}
// 0x00257080
extern "C" void func_00257080(UnkStruct_00257080_a0* self, const UnkStruct_00257080_m* mtx, int idx, CGtV3d p3, CGtV3d p4, CGtV3d p5, float f)
{
    CGtV3d c5 = p5;
    CGtV3d c4 = p4;
    CGtV3d c3 = p3;
    UnkStruct_00257080_s* s = (UnkStruct_00257080_s*)mtx;
    UnkStruct_00257080_set* set = s->field_40;
    int n = set->field_16AC[idx];
    UnkStruct_00257080_elem* e = set->field_1664[idx];
    u_long128 k;
    asm("qmtc2.ni %1, %0" : "=j"(k) : "r"(64.0f));
    for (int i = 0; i < n; i++, e++) {
        CGtV3d v = e->field_0;
        u_long128 res = func_00257080_xf(mtx, v.mData);
        if (((float*)&v)[2] < 0.0f) {
            float d = func_00257080_dot(CGtV3d(e->field_10), c5);
            if (!(d <= 0.0f)) {
                func_00257080_inl1(self, res, func_00257080_mul1(c4.mData, d), f, k);
            }
        } else {
            float d = func_00257080_dot(CGtV3d(e->field_10), c5);
            if (!(d <= 0.0f)) {
                func_00257080_inl1(self, res, func_00257080_mul1(c3.mData, d), f, k);
            }
        }
    }
}
