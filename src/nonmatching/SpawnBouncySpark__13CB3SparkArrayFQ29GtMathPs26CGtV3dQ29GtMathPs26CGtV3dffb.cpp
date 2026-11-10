// NONMATCHING: SpawnBouncySpark__13CB3SparkArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dffb -- retail 143 / ours 143 instructions, 4 in changed runs
// 4 off: VU registers of the first two y-lane subtracts (retail s1 vf1/r1 vf2/s2 vf1; ours r1 coalesced on vf1, s2 vf2). All-local operator-(Y,float) stand-ins give retail's VU numbering but move nv*tm ahead of 0.5g*tm (20 off). Frame exact via two 0x50 N140 pads + by-value particle Set; SetGtV3d stand-in loads the source first
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [C] fix1 (2026-11-01): 24/24 port6 live captures pass the Burn3 checker at tolerance 0 once the port maps the decomp's sqrtf prototype to sqrt.s (the transformed prototype broke the Windows ABI: port-side bug, reported to port7); 6 replay identical on the host -- on those inputs

// CB3SparkArray::SpawnBouncySpark -- hand-matched (ghvu8). Shape from the archived siblings func_00263E80 /
// SpawnBouncyPopcorn (0x90 blocks: float t[4] + 4 x {CGtV3dPlus pos, vel}; ring of 4 slots at this or this+0x4C).
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;
extern "C" float sqrtf(float);

// [G] N140: dead 16-byte frame slots (five above the vy lane copy, five below it inside the setter)
struct UnkStruct_00263C40_pad { int x[20]; UnkStruct_00263C40_pad() {} ~UnkStruct_00263C40_pad() {} };
struct UnkStruct_00263C40_p {
    CGtV3dPlus field_0;
    CGtV3dPlus field_10;
    // [G] by-value setter: its parameter copies are retail's two bottom frame slots
    void Set(CGtV3dPlus p, CGtV3dPlus v) { UnkStruct_00263C40_pad pad; field_0 = p; field_10 = v; }
};
struct UnkStruct_00263C40_b { float field_0[4]; UnkStruct_00263C40_p field_10[4]; };
struct UnkStruct_00263C40_slot { unsigned char *field_0; int field_4; int field_8; float field_C; };
struct UnkStruct_00263C40_ring {
    UnkStruct_00263C40_slot field_0[4];
    int field_40;
    float field_44;
};
struct UnkStruct_00263C40_98 {
    unsigned char pad_0[0x50];
    float field_50;
    float field_54;
};

class CB3SparkArray {
public:
    void SpawnBouncySpark(CGtV3d pos, CGtV3d vel, float t, float h, bool b);
    UnkStruct_00263C40_ring field_0;
    unsigned char pad_48[0x50];
    UnkStruct_00263C40_98 *field_98;
};

// [L] N185: operator-(YAxisType, float) with the scalar's move one inline level deeper (retail's VU numbering)
static inline u_long128 SpawnBouncySpark_inl1(float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); return s; }
static inline YAxisType SpawnBouncySpark_inl2(YAxisType a, float f) {
    u_long128 r;
    asm("vsubx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(SpawnBouncySpark_inl1(f)));
    return YAxisType(r);
}

// [L] N185: CGtV3dPlus::SetGtV3d with the source vector loaded first (retail's lqc2 order)
static inline void SpawnBouncySpark_inl3(CGtV3dPlus &p, CGtV3d v) { u_long128 a = v.mData; u_long128 m = p.mData; asm("vadd.xyz %0, $vf0, %1" : "+j"(m) : "j"(a)); p.mData = m; }

// 0x00263C40
void CB3SparkArray::SpawnBouncySpark(CGtV3d pos, CGtV3d vel, float t, float h, bool b)
{
    CGtV3d pc = pos;
    CGtV3d vc = vel;
    UnkStruct_00263C40_ring *o;
    if (b) o = (UnkStruct_00263C40_ring *)((char *)this + 0x4C);
    else o = &field_0;
    UnkStruct_00263C40_slot *s = &o->field_0[o->field_40];
    int c = s->field_8;
    UnkStruct_00263C40_b *u = (UnkStruct_00263C40_b *)((unsigned int)(s->field_0 + (c / 4) * 0x90) | 0x20000000);
    int r = c & 3;
    UnkStruct_00263C40_p *d = &u->field_10[r];
    s->field_8++;
    if (s->field_8 == s->field_4) s->field_8 = 0;
    o->field_40++;
    o->field_40 &= 3;
    float vy = vc.Y();
    if (vy < 0.0f && h <= 0.0f) vy = -vy;
    float g = field_98->field_50;
    float dd = vy * vy - 2.0f * g * h;
    CGtV3dPlus P;
    SpawnBouncySpark_inl3(P, pc);
    CGtV3dPlus V;
    SpawnBouncySpark_inl3(V, vc);
    UnkStruct_00263C40_pad pad; // [G] N140
    float tt;
    if (dd > 0.0f && (tt = vy + s->field_C * g, dd < tt * tt)) {
        float sq = sqrtf(dd);
        float tm = (-1.0f / g) * (sq + vy);
        float gt = g * tm;
        float nv = -field_98->field_54 * (vy + gt) - gt;
        P.SetPlus(SpawnBouncySpark_inl2(((pc.Y() - h) - nv * tm), 0.5f * g * tm * tm));
        V.SetPlus(nv);
    } else {
        P.SetPlus(pc.Y());
        V.SetPlus(vc.Y());
    }
    d->Set(P, V);
    u->field_0[r] = t;
    o->field_44 = t;
}
