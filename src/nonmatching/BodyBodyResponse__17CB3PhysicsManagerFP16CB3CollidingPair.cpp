// NONMATCHING: BodyBodyResponse__17CB3PhysicsManagerFP16CB3CollidingPair -- retail 717 / ours 714 instructions, 375 in changed runs
// draftH: CB3PhysicsManager::BodyBodyResponse written from the asm (box-box SAT or CollideBodyHulls, mass-split separation incl. linked type-4 bodies, restitution impulse along the velocity-blended normal, kaabCanFatal crash start, type-6 vfunc_10 callback); calls identical; residue = VU scheduling + N254/N255 frame (0x6C0 vs 0x3D0)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every call, branch, store and VU op accounted for; differs in scheduling and stack-slot layout only

// draftH: BodyBodyResponse__17CB3PhysicsManagerFP16CB3CollidingPair (0x1B4BF0, 0xB34) -- CB3PhysicsManager::BodyBodyResponse
// [C] name: retail symbol table. Written from the retail asm (Ghidra draft as a reading aid); the Revenge counterpart
// (0x304 bytes) is too different to use. Struct layouts shared with the archived sibling BodyTrafficResponse (0x1B5730).
// What it does [L]: interaction types both ways -> early outs; box-box SAT test (func_002F0440) when D_004EB903 and both
// bodies' field_20C == 1, else CollideBodyHulls; position separation split by mass (field_1F0) with a linked body at
// +0x2424 (type 4); impulse along the (velocity-blended, renormalised) normal with restitution krRacecarRacecarRestitution;
// fatal-crash start through kaabCanFatal[7][7] and CB3CrashActionDirector::StartRaceCarCrashing; a vfunc_10 hit callback
// for type-6 bodies.
// Residue [C asm, draftH]: calls identical, branch senses and block order as retail except the slam-time test layout; retail
// keeps the contact point twice (sp+0x410 / 0x400) and the normal (0x3F0) in memory and has a 0x6C0 frame (ours 0x3D0: the
// N254/N255 dead-slot family); the rest is VU scheduling (qmfc2/qmtc2 round trips, lq vs lqc2 of the inertia rows).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

extern "C" float fabsf(float);

// [G] the 32-byte box at body+0x1D0 (min/max, as func_002F0640's CGtAxisAlignedBox)
struct UnkStruct_001B4BF0_box { CGtV3d field_0; CGtV3d field_10; };
// [G] per-body block of the hull-collide parameters (0xF0 bytes) -- as BodyTrafficResponse's archive
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
    int field_1E4;          // set when the separation in field_0/field_F0 .field_30.mPos is valid
    unsigned char pad_1E8[8];
    CGtV3d field_1F0;       // contact normal
    CGtV3d field_200;       // contact point
};
// [G] race-car object at body+0x13F4 (fields used by the slam-invulnerability test)
struct UnkStruct_001B4BF0_car {
    unsigned char pad_0[0x10CC];
    float field_10CC;       // time [G]
    unsigned char pad_10D0[0x1598 - 0x10D0];
    float field_1598[4];    // per-opponent time [G], indexed by the other car's field_19AC
    unsigned char pad_15A8[0x15C6 - 0x15A8];
    unsigned char field_15C6;
    unsigned char pad_15C7[5];
    UnkStruct_001B4BF0_car * field_15CC;
};
struct UnkStruct_001B4BF0_body {
    void * field_0;         // vtable (type-6 bodies: vfunc_10 at +0x10)
    unsigned char pad_4[0x3C];
    CGtV3d field_40[3];     // inverse inertia rows [G]
    CGtMatrix3x4 field_70;
    CGtV3d field_B0;        // velocity [G]
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;        // angular velocity [G]
    unsigned char pad_E0[0x30];
    CGtV3d field_110;       // impulse accumulator [G]
    CGtV3d field_120;       // angular impulse accumulator [G]
    CGtV3d field_130;       // position correction [G]
    unsigned char pad_140[0x174 - 0x140];
    unsigned char field_174;
    unsigned char pad_175[0x1D0 - 0x175];
    UnkStruct_001B4BF0_box field_1D0;
    float field_1F0;        // mass [G]
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[4];
    unsigned char field_20C;
    unsigned char pad_20D[3];
    unsigned char field_210;
    unsigned char field_211;
    unsigned char pad_212[6];
    signed char field_218;
    unsigned char pad_219[0x1353 - 0x219];
    unsigned char field_1353;
    unsigned char pad_1354[0x13F4 - 0x1354];
    UnkStruct_001B4BF0_car * field_13F4;
    unsigned char pad_13F8[0x2424 - 0x13F8];
    UnkStruct_001B4BF0_body * field_2424;   // linked body (type 4) [G]
};
class CB3ActiveBody {
public:
    signed char field_0;
    unsigned char pad_1[0xB];
    UnkStruct_001B4BF0_body * field_C;
    int GetInteractionTypeAgainst(CB3ActiveBody * p0) const;
    int GetNetworkCollBodyType() const;
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
// [G] 16 bytes at sp+0x3C0: two bytes cleared, +8 cleared, +0xC = the other car
class CB3CrashStartInfo {
public:
    unsigned char field_0;
    unsigned char field_1;
    unsigned char pad_2[6];
    int field_8;
    UnkStruct_001B4BF0_car * field_C;
};
class CB3PhysicsManager {
public:
    void BodyBodyResponse(CB3CollidingPair * p0);
    void WorldSafeBodyTranslations(CB3CollidingPair * p0, CGtV3d * p1, CGtV3d * p2);
};
extern unsigned char D_004EB903;
extern unsigned char kaabCanFatal[7][7];
extern float krRacecarRacecarRestitution;
extern float krSlamRaceCarInvulTime;
extern float D_004E1640;          // 5000.0f, read through $gp [C]; [G] a named tuning constant (an integer-valued literal compiles to li+cvt.s.w)
extern float D_004E1644;          // 2500.0f, same
extern unsigned char D_0055E948[];
extern "C" bool func_002F0440(void * p0, const CGtMatrix3x4 * a, void * p2, const CGtMatrix3x4 * m, const CGtMatrix3x4 * b,
    void * p5, CGtV3d * o1, CGtV3d * o2);
extern "C" unsigned char CollideBodyHulls__20CB3ConvexHullCollideFP20CB3HullCollideParamsP16CB3CollidingBodyP16CB3CollidingBodyb(
    CB3HullCollideParams *, UnkStruct_001B4BF0_body *, UnkStruct_001B4BF0_body *, bool);
extern "C" void StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(
    void *, UnkStruct_001B4BF0_body *, int, CB3CollidingPair *, CB3CrashStartInfo *);

// [G] local stand-ins (header gaps): in-place Normalise (N238 H1Q0N2V1R- body; retail `vmulq.xyz $vf4,$vf4,$Q`)
static inline void func_001B4BF0_inl1(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" "\n\t" ".set reorder" : "+j"(v.mData));
}
// [G] apply an impulse at a world point (as BodyTrafficResponse's func_001B5730_inl2)
static inline void func_001B4BF0_inl3(UnkStruct_001B4BF0_body *o, CGtV3d p, CGtV3d i)
{
    o->field_110 += i;
    o->field_120 += CrossProduct(p - o->field_204->mPos, i);
}
// [G] effective-mass term of one body: (I^-1 (r x n)) x r
static inline CGtV3d func_001B4BF0_inl4(const UnkStruct_001B4BF0_body *o, CGtV3d p, const CGtV3d &n)
{
    CGtV3d r = p - o->field_204->mPos;
    return CrossProduct(TransformVector(*(const CGtMatrix3x3*)o->field_40, CrossProduct(r, n)), r);
}

// 0x001B4BF0
void CB3PhysicsManager::BodyBodyResponse(CB3CollidingPair * p0)
{
    CB3HullCollideParams prm;
    UnkStruct_001B4BF0_body * b = p0->field_28->field_C;
    UnkStruct_001B4BF0_body * a = p0->field_24->field_C;
    int ta = p0->field_24->GetInteractionTypeAgainst(p0->field_28);
    int tb = p0->field_28->GetInteractionTypeAgainst(p0->field_24);
    p0->field_2C = 0;
    if (ta == 2 && tb == 2)
        return;
    if (p0->field_24->field_0 == 4 && p0->field_28->field_0 == 4 && a->field_2424 == b)
        return;
    if (D_004EB903 != 0 && a->field_20C == 1 && b->field_20C == 1) {
        UnkStruct_001B4BF0_box boxA = a->field_1D0;
        UnkStruct_001B4BF0_box boxB = b->field_1D0;
        float depth;
        CGtV3d point;
        CGtV3d normal;
        p0->field_2C = func_002F0440(&boxA, a->field_204, &boxB, b->field_204, &b->field_70, &depth, &point, &normal);
        if (p0->field_2C) {
            prm.field_1E4 = 1;
            prm.field_0.field_30.mPos = a->field_204->mPos + normal * depth * 0.5f;
            prm.field_F0.field_30.mPos = b->field_204->mPos - normal * depth * 0.5f;
            prm.field_1F0 = -normal;
            prm.field_200 = point;
        }
    } else {
        p0->field_2C = CollideBodyHulls__20CB3ConvexHullCollideFP20CB3HullCollideParamsP16CB3CollidingBodyP16CB3CollidingBodyb(&prm, a, b, true);
    }
    if (p0->field_2C == 0)
        return;
    if ((unsigned int)p0->field_24->field_0 < 3 && p0->field_24->field_C->field_210 == 0)
        ta = 2;
    a->field_211 = 1;
    b->field_211 = 1;
    if (prm.field_1E4 != 0) {
        CGtV3d da = prm.field_0.field_30.mPos - a->field_204->mPos;
        CGtV3d db = prm.field_F0.field_30.mPos - b->field_204->mPos;
        if (ta == 2) {
            b->field_130 += db - da;
        } else if (tb == 2) {
            a->field_130 += da - db;
        } else {
            WorldSafeBodyTranslations(p0, &da, &db);
            if (p0->field_24->field_0 == 4 && a->field_2424 != 0) {
                float m = a->field_1F0 + a->field_2424->field_1F0;
                float f = m / (m + b->field_1F0);
                da -= db;
                a->field_130 += da * (1.0f - f);
                a->field_2424->field_130 += da * (1.0f - f);
                b->field_130 += da * -f;
            } else if (p0->field_28->field_0 == 4 && b->field_2424 != 0) {
                float f = a->field_1F0 / (a->field_1F0 + (b->field_1F0 + b->field_2424->field_1F0));
                da -= db;
                a->field_130 += da * (1.0f - f);
                b->field_130 += da * -f;
                b->field_2424->field_130 += da * -f;
            } else {
                float f = a->field_1F0 / (a->field_1F0 + b->field_1F0);
                da -= db;
                a->field_130 += da * (1.0f - f);
                b->field_130 += da * -f;
            }
        }
    }
    CGtV3d point = prm.field_200;
    CGtV3d normal = prm.field_1F0;
    CGtV3d rel = (CrossProduct(b->field_D0, point - b->field_204->mPos) + b->field_B0)
               - (CrossProduct(a->field_D0, point - a->field_204->mPos) + a->field_B0);
    if (rel.GetSquaredLength() >= 2.3283064e-10f) {
        CGtV3d dir = rel;
        func_001B4BF0_inl1(dir);
        normal += dir * -0.9f;
        func_001B4BF0_inl1(normal);
    }
    float num = DotProduct(normal, rel) * -(1.0f + krRacecarRacecarRestitution);
    CGtV3d ka = func_001B4BF0_inl4(a, point, normal);
    CGtV3d kb = func_001B4BF0_inl4(b, point, normal);
    float j = num / (DotProduct(ka + kb, normal) + (1.0f / a->field_1F0 + 1.0f / b->field_1F0));
    CGtV3d imp = normal * -fabsf(j);
    p0->field_0 = point;
    p0->field_10 = normal;
    if (j > 0.0f) {
        if (ta == 2) {
            func_001B4BF0_inl3(b, point, imp * -1.0f);
        } else if (tb == 2) {
            func_001B4BF0_inl3(a, point, imp);
        } else {
            func_001B4BF0_inl3(a, point, imp);
            func_001B4BF0_inl3(b, point, -imp);
        }
        p0->field_20 = j;
    } else {
        p0->field_20 = 0.0f;
    }
    float limit = D_004E1640;
    if ((unsigned int)p0->field_24->field_0 < 3 && p0->field_24->field_C->field_210 == 0 && p0->field_24->field_0 != 2
        && (unsigned int)p0->field_28->field_0 < 3 && p0->field_28->field_C->field_210 != 0 && p0->field_28->field_0 == 2)
        limit = D_004E1644;
    if ((unsigned int)p0->field_24->field_0 < 3 && p0->field_24->field_C->field_210 == 0 && p0->field_20 > limit) {
        if (kaabCanFatal[p0->field_24->GetNetworkCollBodyType()][p0->field_28->GetNetworkCollBodyType()]) {
            CB3CrashStartInfo info;
            info.field_1 = 0;
            info.field_0 = 0;
            bool start = true;
            info.field_8 = 0;
            info.field_C = 0;
            CB3CrashStartInfo * pinfo = 0;
            if ((unsigned int)p0->field_28->field_0 < 3) {
                UnkStruct_001B4BF0_car * ca = a->field_13F4;
                UnkStruct_001B4BF0_car * cb = b->field_13F4;
                float dt = 1000.0f;
                pinfo = &info;
                info.field_C = cb;
                if (p0->field_24->field_0 == 2 || p0->field_28->field_0 != 2) {
                    if (cb->field_15C6 != 0 && cb->field_15CC == ca) {
                        dt = ca->field_10CC - *(float *)((char *)cb + 0x13FC);
                    } else {
                        float t = ca->field_1598[*((signed char *)cb + 0x19AC)];
                        if (t > 0.0f)
                            dt = ca->field_10CC - t;
                    }
                    if (dt < krSlamRaceCarInvulTime)
                        start = false;
                }
            }
            if (p0->field_28->field_0 == 3 && (p0->field_28->field_C->field_174 & 8))
                start = false;
            if (p0->field_28->field_0 == 4 && (p0->field_24->field_C->field_1353 & 0x10) == 0x10)
                start = false;
            if (start == true)
                StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(
                    D_0055E948, p0->field_24->field_C, p0->field_28->field_C->field_218, p0, pinfo);
        }
    }
    if (p0->field_24->field_0 == 6) {
        UnkStruct_001B4BF0_body * o = p0->field_24->field_C;
        if (o->field_210 == 0 && p0->field_28->field_C->field_210 != 0)
            ((void (*)(void *, int, int))((void **)o->field_0)[4])(o, p0->field_28->field_C->field_218, 0);
    }
    if (p0->field_28->field_0 == 6) {
        UnkStruct_001B4BF0_body * o = p0->field_28->field_C;
        if (o->field_210 == 0 && p0->field_24->field_C->field_210 != 0)
            ((void (*)(void *, int, int))((void **)o->field_0)[4])(o, p0->field_24->field_C->field_218, 0);
    }
}
