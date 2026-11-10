// NONMATCHING: BodyTrafficResponse__17CB3PhysicsManagerFP16CB3CollidingPair -- retail 219 / ours 219 instructions, 12 in changed runs
// ghvu19: 12 off. Logic/layout/frame exact (0x1D0 N140 pad). Left: (1) first cross round trip: retail qmfc2/qmtc2 on v0 before lw b->field_C, ours schedules the lw first; (2) after the impulse call retail loads imp twice + p0->field_0 above the field_110 store (vf2/vf4/vf3/vf1); ours reloads imp after the store.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (ghvu19, Ghidra draft + retail asm); the lifter refused it.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [G] per-body block of the hull-collide parameters (0xF0 bytes): hull, world matrix, inverse matrix
struct UnkStruct_001B5730_hb {
    void * field_0;
    unsigned char pad_4[0x2C];
    CGtMatrix3x4 field_30;
    CGtMatrix3x4 field_70;
    unsigned char pad_B0[0x40];
};
struct CB3HullCollideParams {
    UnkStruct_001B5730_hb field_0;
    UnkStruct_001B5730_hb field_F0;
    int field_1E0;
    int field_1E4;
    unsigned char pad_1E8[8];
    CGtV3d field_1F0;
    CGtV3d field_200;
};
struct UnkStruct_001B5730_obj {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;
    CGtV3d field_B0;
    float field_C0;
    float field_C4;
    unsigned char pad_C8[8];
    CGtV3d field_D0;
    unsigned char pad_E0[0x30];
    CGtV3d field_110;
    CGtV3d field_120;
    CGtV3d field_130;
    unsigned char pad_140[0xC4];
    CGtMatrix3x4 * field_204;
    void * field_208;
    unsigned char pad_20C[4];
    unsigned char field_210;
    unsigned char field_211;
    unsigned char pad_212[6];
    signed char field_218;
};
struct UnkStruct_001B5730_tv {
    unsigned char pad_0[0xB0];
    unsigned char * field_B0;
};
class CB3ActiveBody {
public:
    signed char field_0;
    unsigned char pad_1[3];
    CGtMatrix3x4 * field_4;
    void * field_8;
    UnkStruct_001B5730_obj * field_C;
};
class CB3CollidingPair {
public:
    CGtV3d field_0;
    CGtV3d field_10;
    float field_20;
    CB3ActiveBody * field_24;
    CB3ActiveBody * field_28;
    unsigned char field_2C;
};
class CB3PhysicsManager {
public:
    void BodyTrafficResponse(CB3CollidingPair * p0);
    void BodyBodyResponse(CB3CollidingPair * p0);
    void CrashTrafficBody(CB3ActiveBody * p0, int p1, int p2, bool p3, bool p4, bool p5);
};
struct UnkStruct_D_0064ED5C { signed char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0064ED5C D_0064ED5C;
extern float krRacecarTrafficRestitution;
extern "C" int CollideHulls__20CB3ConvexHullCollideFP20CB3HullCollideParams(CB3HullCollideParams *);
extern "C" float CalculateCollisionImpulseWithTraffic__16CB3CollidingBodyFP17CB3TrafficVehicleQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dfPQ29GtMathPs26CGtV3d(
    void *, void *, const void *, const void *, const void *, float, CGtV3d *);

// [L] N185 stand-ins (compiler-chosen VU registers): per-row lane copies of an in-place 3x3 transpose, lane-scaled
// products, vsub, a cross product with the result on the first operand (retail vopmula a,b; vopmsub a,b,a).
static inline void func_001B5730_r0(CGtV3d &d, const CGtV3d &b, const CGtV3d &c) { asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(d.mData) : "j"(b.mData), "j"(c.mData)); }
static inline void func_001B5730_r1(CGtV3d &d, const CGtV3d &a, const CGtV3d &c) { asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(d.mData) : "j"(a.mData), "j"(c.mData)); }
static inline void func_001B5730_r2(CGtV3d &d, const CGtV3d &a, const CGtV3d &b) { asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(d.mData) : "j"(a.mData), "j"(b.mData)); }
static inline CGtV3d func_001B5730_mx(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_001B5730_my(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_001B5730_mz(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_001B5730_sub(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
static inline CGtV3d func_001B5730_cr(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 c, t;
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %0, %2, %1" : "=j"(c) : "j"(a.mData), "j"(b.mData));
    u_long128 v;
    asm("qmfc2.i %1, %2" "\n\t" "qmtc2.i %1, %0" : "=j"(v), "=&r"(t) : "j"(c));
    return CGtV3d(v);
}
static inline CGtV3d func_001B5730_ms(const CGtV3d &a, float s)
{
    u_long128 t, sv;
    asm("qmtc2.ni %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(sv));
    return CGtV3d(t);
}
// [G] orthonormal inverse of src into dst (transpose the rotation, pos = -(r0*p.x + r1*p.y + r2*p.z)); API name unknown
static inline void func_001B5730_inv(CGtMatrix3x4 &r, const CGtMatrix3x4 &m)
{
    r = m;
    CGtV3d a = r.mRight, b = r.mUp, c = r.mAt;
    func_001B5730_r0(r.mRight, b, c);
    func_001B5730_r1(r.mUp, a, c);
    func_001B5730_r2(r.mAt, a, b);
    CGtV3d p = r.mPos;
    CGtV3d z = func_001B5730_mz(r.mAt, p);
    CGtV3d x = func_001B5730_mx(r.mRight, p);
    CGtV3d t = x + func_001B5730_my(r.mUp, p);
    t += z;
    r.mPos = -t;
}
// [G] N140 pad: retail's frame keeps 0x1D0 bytes of dead slots below the call temporaries (inlined matrix/vector code)
struct UnkStruct_001B5730_pad { int x[0x70]; UnkStruct_001B5730_pad() {} ~UnkStruct_001B5730_pad() {} };
// [L] same body-state hull fetch as RenderWorld (B3PhysicsManagerDebug_002BEA00)
static inline bool func_001B5730_inl1(const CB3ActiveBody *e)
{
    return (unsigned int)e->field_0 <= 2 || e->field_0 == 4 || e->field_0 == 6 || e->field_0 == 7;
}

static inline void func_001B5730_inl2(UnkStruct_001B5730_obj *o, CGtV3d p, const CGtV3d & i)
{
    o->field_110 += i;
    CGtV3d r2 = func_001B5730_sub(p, o->field_204->mPos);
    o->field_120 += func_001B5730_cr(r2, i);
}
// 0x001B5730
void CB3PhysicsManager::BodyTrafficResponse(CB3CollidingPair * p0)
{
    CB3HullCollideParams prm;
    CGtV3d rel;
    CGtV3d imp;
    UnkStruct_001B5730_pad pad;
    CB3ActiveBody * b = p0->field_28;
    UnkStruct_001B5730_obj * o = p0->field_24->field_C;
    prm.field_0.field_30 = *o->field_204;
    prm.field_0.field_70 = o->field_70;
    prm.field_0.field_0 = o->field_208;
    prm.field_F0.field_30 = *b->field_4;
    func_001B5730_inv(prm.field_F0.field_70, *b->field_4);
    void * h = 0;
    if (b->field_0 == 3) {
        unsigned char * x = ((UnkStruct_001B5730_tv *)b->field_C)->field_B0;
        if (x != 0) h = x + 0x1060;
    } else if (func_001B5730_inl1(b)) {
        h = b->field_C->field_208;
    }
    prm.field_F0.field_0 = h;
    prm.field_1E0 = 1;
    p0->field_2C = CollideHulls__20CB3ConvexHullCollideFP20CB3HullCollideParams(&prm);
    if (p0->field_2C) {
        o->field_211 = 1;
        if (o->field_210 != 0) {
            CrashTrafficBody(b, D_0064ED5C.field_0, o->field_218, true, true, true);
            b->field_C->field_211 = 1;
            BodyBodyResponse(p0);
            return;
        }
        p0->field_0 = prm.field_200;
        p0->field_10 = prm.field_1F0;
        if (prm.field_1E4 != 0) {
            CGtV3d d0 = func_001B5730_sub(prm.field_0.field_30.mPos, o->field_204->mPos);
            CGtV3d d1 = func_001B5730_sub(prm.field_F0.field_30.mPos, b->field_4->mPos);
            CGtV3d dd = func_001B5730_sub(d0, d1);
            o->field_130 += dd;
        }
        CGtV3d r = func_001B5730_sub(p0->field_0, o->field_204->mPos);
        CGtV3d v = func_001B5730_cr(o->field_D0, r);
        v += o->field_B0;
        u_long128 sv, t;
        asm("qmtc2.ni %1, %0" : "=j"(sv) : "r"(b->field_C->field_C4));
        asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(b->field_4->mAt.mData), "j"(sv));
        rel = CGtV3d(t);
        rel -= v;
        float f = CalculateCollisionImpulseWithTraffic__16CB3CollidingBodyFP17CB3TrafficVehicleQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dfPQ29GtMathPs26CGtV3d(
            o, b->field_C, &p0->field_0, &rel, &p0->field_10, krRacecarTrafficRestitution, &imp);
        if (f > 0.0f) {
            func_001B5730_inl2(o, p0->field_0, imp);
            p0->field_20 = f;
        } else {
            p0->field_20 = 0.0f;
        }
    }
}
